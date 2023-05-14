// ____________________________
// ██▀▀█▀▀██▀▀▀▀▀▀▀█▀▀█        │   ▄▄▄                ▄▄
// ██  ▀  █▄  ▀██▄ ▀ ▄█ ▄▀▀ █  │  ▀█▄  ▄▀██ ▄█▄█ ██▀▄ ██  ▄███
// █  █ █  ▀▀  ▄█  █  █ ▀▄█ █▄ │  ▄▄█▀ ▀▄██ ██ █ ██▀  ▀█▄ ▀█▄▄
// ▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀────────┘                 ▀▀
//  Program template
// ─────────────────────────────────────────────────────────────────────────────

//=============================================================================
// INCLUDES
//=============================================================================
#include "msxgl.h"
#include "room5.h"

//=============================================================================
// DEFINITIONS
//=============================================================================

// Structure de description d'une pièce
struct RoomDefinition
{
	u8 X;
	u8 Y;
	u8 Width;
	u8 Height;
	const u8 *Layout;
	const c8 *Name;
	u8 NextLvlIdx;
};

// Structure des paramètres du joueur
struct PlayerDefinition
{
	u8 X;
	u8 Y;
	i8 VelocityY;
};

// Structure des paramètres de l'élévateur

struct ElevatorDefinition
{
	u8 X;
	u8 Y;
	i8 VelocityY;
	u8 State;
	u8 Timer;
};

enum PlayerState
{
	PLAYER_STATE_IDLE,
	PLAYER_STATE_MOVE,
	PLAYER_STATE_ACTION,
	PLAYER_STATE_FALL,
};

enum ElevatorState
{
	ELEVATOR_STATE_MOVE,
	ELEVATOR_STATE_STAND,
};

#define SPT_PLAYER_HAIR 0
#define SPT_PLAYER_SKIN 1
#define SPT_PLAYER_CHAIR 2
#define SPT_PLAYER_OUTLINE 16
#define SPT_ELEVATOR 3
#define MAX_ELEVATOR 8
#define RAILS_TILE_NUM 39

//=============================================================================
// VARIABLES GLOBALES (alloué en RAM)
//=============================================================================

// Index de la pièce courante
u8 g_CurrRoomIdx;
// Définie si la lumière est allumée ou non
bool g_CurrentLightOn;
// Paramètres du joueur
struct PlayerDefinition g_Player;

u8 g_PlayerState = PLAYER_STATE_IDLE;

struct ElevatorDefinition g_Elevator[MAX_ELEVATOR];

u8 g_ElevatorCount = 0;

u8 g_FrameCounter = 0;

//=============================================================================
// DONNEES CONSTANTES (stockées dans le ROM)
//=============================================================================

// Données des sprites du joueur
#include "data/sprt_player.h"

// Données des formes et couleurs des tuiles
#include "data/bg_tileset.h"

// Données des pièces
#include "data/level/level001.h"
#include "data/level/level002.h"
#include "data/level/level003.h"
#include "data/level/level004.h"

// Données des sprites de l'elevateur
#include "data/sprt_elevator.h"

// Liste des pièces et de leur caracteristiques
const struct RoomDefinition g_Rooms[] = {
		{(32 - LEVEL001_WIDTH) / 2, (24 - LEVEL001_HEIGHT) / 2, LEVEL001_WIDTH, LEVEL001_HEIGHT, g_Level001, "Room 1", 1},
		{(32 - LEVEL002_WIDTH) / 2, (24 - LEVEL002_HEIGHT) / 2, LEVEL002_WIDTH, LEVEL002_HEIGHT, g_Level002, "Room 42", 2},
		{(32 - LEVEL003_WIDTH) / 2, (24 - LEVEL003_HEIGHT) / 2, LEVEL003_WIDTH, LEVEL003_HEIGHT, g_Level003, "Room 2", 3},
		{(32 - LEVEL004_WIDTH) / 2, (24 - LEVEL004_HEIGHT) / 2, LEVEL004_WIDTH, LEVEL004_HEIGHT, g_Level004, "Room 66", 0},
};

const u8 g_NumPlayerFramesMove[] = {1, 2, 3, 4};
const u8 g_NumPlayerFramesAction[] = {5, 6, 7, 8, 9, 10, 9, 11};
const u8 g_NumPlayerFramesFall[] = {1, 2, 3, 4};

//=============================================================================
// FONCTIONS
//=============================================================================

//-----------------------------------------------------------------------------

// Récupère la tuile à la position indiquée
u8 getTile(u8 x, u8 y)
{
	u8 tile = VDP_Peek_16K(g_ScreenLayoutLow + (y / 8) * 32 + (x / 8));
	return tile;
}

// Point d'entrée du programme principal
bool checkCollision(u8 x, u8 y)
{
	return getTile(x, y) >= 128;
}

bool checkRails(u8 x, u8 y)
{
	return getTile(x, y) == RAILS_TILE_NUM; // N° de la tuile des rails
}

// Allume ou éteint la lumière
void activateLight(bool bActivate)
{
	g_CurrentLightOn = bActivate; // Enregistrement de l’état de la lumière

	// Change la couleur des tuiles du décor
	u8 firstCol = g_CurrentLightOn ? 0xA1 : 0x41;
	u8 secondCol = g_CurrentLightOn ? 0xB1 : 0x51;
	VDP_FillVRAM_16K(firstCol, g_ScreenColorLow, 8);
	VDP_FillVRAM_16K(firstCol, g_ScreenColorLow + (64 / 8), 8);
	VDP_FillVRAM_16K(secondCol, g_ScreenColorLow + (128 / 8), 8);

	// Change la couleur du personnage
	VDP_SetSpriteColorSM1(SPT_PLAYER_HAIR, g_CurrentLightOn ? COLOR_LIGHT_YELLOW : COLOR_LIGHT_BLUE);
	VDP_SetSpriteColorSM1(SPT_PLAYER_SKIN, g_CurrentLightOn ? COLOR_WHITE : COLOR_CYAN);
	VDP_SetSpriteColorSM1(SPT_PLAYER_CHAIR, g_CurrentLightOn ? COLOR_MEDIUM_RED : COLOR_DARK_BLUE);
}

//-----------------------------------------------------------------------------

// initialise le personnage

void initPlayer()
{
	g_Player.X = 100;
	g_Player.Y = 103;
	g_Player.VelocityY = 0;
}

void initElevator(u8 num, u8 x, u8 y)
{
	g_Elevator[num].X = x;
	g_Elevator[num].Y = y;
	g_Elevator[num].VelocityY = 1;
	g_Elevator[num].State = ELEVATOR_STATE_MOVE;
	g_Elevator[num].Timer = 0;

	VDP_SetSpriteSM1(SPT_ELEVATOR + num, x, y, 4 * 4 * 12, COLOR_WHITE);
}

void updateElevator(u8 num)
{
	// si monte
	if (g_Elevator[num].VelocityY < 0)
	{
		if (!checkRails(g_Elevator[num].X, g_Elevator[num].Y - 1))
		{

			g_Elevator[num].VelocityY = 1;
			g_Elevator[num].State = ELEVATOR_STATE_STAND;
		}
	}
	else
	{
		if (!checkRails(g_Elevator[num].X, g_Elevator[num].Y + 1))
		{
			g_Elevator[num].VelocityY = -1;
			g_Elevator[num].State = ELEVATOR_STATE_STAND;
		}
	}

	g_Elevator[num].Y += g_Elevator[num].VelocityY;
	VDP_SetSpritePosition(SPT_ELEVATOR + num, g_Elevator[num].X, g_Elevator[num].Y - 9);
}
// Afficher une pièce
void displayLevel(u8 levelIdx)
{
	g_CurrRoomIdx = levelIdx; // Enregistrement du numéro de la pièce
	g_ElevatorCount = 0;			// Initialisation du nombre d'élévateurs

	// Nettoyage de l'écran (tuile n°0 partout)
	VDP_FillVRAM_16K(0, g_ScreenLayoutLow, 32 * 24);

	// Dessin de la pièce ligne par ligne
	// I = ligne, J = colonne
	for (u8 i = 0; i < g_Rooms[levelIdx].Height; ++i)
	{
		// Copie une ligne de donnée en VRAM
		VDP_WriteVRAM_16K(g_Rooms[levelIdx].Layout + g_Rooms[levelIdx].Width * i,
											g_ScreenLayoutLow + 32 * (i + g_Rooms[levelIdx].Y) + (g_Rooms[levelIdx].X), g_Rooms[levelIdx].Width);

		for (u8 j = 0; j < g_Rooms[levelIdx].Width; ++j)
		{
			u8 tile = g_Rooms[levelIdx].Layout[g_Rooms[levelIdx].Width * i + j];
			if (tile == 63) // Detection de la position initiale du joueur
			{
				// Positionnement du joueur centré sur la tuile trouvée
				g_Player.X = (g_Rooms[levelIdx].X + j) * 8 - 4;
				g_Player.Y = (g_Rooms[levelIdx].Y + i) * 8 - 9;
			}
			if ((tile == RAILS_TILE_NUM) && (g_ElevatorCount < MAX_ELEVATOR)) // Detection des rails pour placer les élévateurs
			{
				if (g_Rooms[levelIdx].Layout[g_Rooms[levelIdx].Width * i + j - 1] != RAILS_TILE_NUM)
				{
					if (g_Rooms[levelIdx].Layout[g_Rooms[levelIdx].Width * (i - 1) + j] != RAILS_TILE_NUM)
					{

						initElevator(g_ElevatorCount, (g_Rooms[levelIdx].X + j) * 8, (g_Rooms[levelIdx].Y + i) * 8);
						g_ElevatorCount++;
					}
				}
			}
		}
	}

	// Initialisation de la couleur des tuiles
	activateLight(FALSE);

	for (u8 i = g_ElevatorCount; i < MAX_ELEVATOR; ++i)
	{
		VDP_HideSprite(SPT_ELEVATOR + i);
	}

	// Affichage du nom de la pièce
	Print_DrawTextAt(g_Rooms[levelIdx].X - 1, 0, g_Rooms[levelIdx].Name);
}

//-----------------------------------------------------------------------------
// Interagit à une position donnée
bool interact(u8 x, u8 y)
{
	u8 tile = getTile(x, y);
	switch (tile)
	{
	// Telephone
	case 73:
		Print_DrawTextAt(g_Rooms[g_CurrRoomIdx].X - 1, g_Rooms[g_CurrRoomIdx].Y + g_Rooms[g_CurrRoomIdx].Height + 2, "DRIIIING !!");
		return TRUE;
	// Light ON/OFF
	case 74:
	case 76:
		activateLight(!g_CurrentLightOn);
		return TRUE;
	// Open door
	case 12:
	case 13:
		displayLevel(g_Rooms[g_CurrRoomIdx].NextLvlIdx);
		// TODO Animer porte qui s'ouvre et personnage qui passe
		return FALSE;
	}
	return FALSE;
}

//=============================================================================
// BOUCLE PRINCIPALE
//=============================================================================

//-----------------------------------------------------------------------------
// Point d'entrée du programme principal
void main()
{
	// Initialisation de l'affichage
	VDP_SetMode(VDP_MODE_SCREEN1); // Mode écran 1 (32x24 tuiles de 8x8 pixels en 2 couleurs)
	VDP_SetSpriteFlag(VDP_SPRITE_SIZE_16);
	VDP_SetColor(COLOR_BLACK); // Couleur de la bordure et de la couleur 0
	VDP_ClearVRAM();

	// Chargement du tileset du décor en VRAM
	VDP_WriteVRAM_16K(g_Tiles_Patterns, g_ScreenPatternLow, sizeof(g_Tiles_Patterns));
	VDP_WriteVRAM_16K(g_Tiles_Colors, g_ScreenColorLow, sizeof(g_Tiles_Colors));

	// Initialisation de la font de caractère
	Print_SetMode(PRINT_MODE_TEXT);
	Print_SetFontEx(8, 8, 1, 1, ' ', '_', g_Tiles_Patterns + 192);
	Print_Initialize();
	g_PrintData.PatternOffset = 192;

	// Chargement des formes des sprites
	VDP_WriteVRAM_16K(g_SprtPlayer, g_SpritePatternLow, sizeof(g_SprtPlayer));
	VDP_WriteVRAM_16K(g_SprtElevator, g_SpritePatternLow + 4 * 4 * 12 * 8, sizeof(g_SprtElevator));

	// Creation des 4 sprites du personnage (leur position et leur pattern seront mis-à-jour à chaque frame dans la boucle principale)
	VDP_SetSpriteSM1(SPT_PLAYER_HAIR, 0, 0, 0, COLOR_DARK_YELLOW);
	VDP_SetSpriteSM1(SPT_PLAYER_SKIN, 0, 0, 4, COLOR_WHITE);
	VDP_SetSpriteSM1(SPT_PLAYER_CHAIR, 0, 0, 8, COLOR_DARK_RED);
	VDP_SetSpriteSM1(SPT_PLAYER_OUTLINE, 0, 0, 12, COLOR_BLACK);
	initPlayer();

	// Affichage de la pièce n°0 (la première)
	displayLevel(0);

	u8 count = 0;
	bool alreadyJumping = FALSE;
	while (1) // Pour un jeu en cartouche (ROM) on a pas besoin de gérer la sortie de la boucle principale
	{
		// Attente de la synchronisation avec le processeur graphique (à 50 ou 60 Hz)
		Halt();

		count++;

		if (g_PlayerState == PLAYER_STATE_ACTION)
		{
			if (count == 2 * 8)
			{
				// Interaction au milieu du personnage
				if (interact(g_Player.X + 12, g_Player.Y + 4))
				{
					g_PlayerState = PLAYER_STATE_IDLE;
				}
				else
				{
					// TODO mettre animation haussement épaule
					g_PlayerState = PLAYER_STATE_IDLE;
				}
			}
		}
		else
		{
			u8 xTemp = g_Player.X; // Sauvegarde de l'ancienne position du joueur
			u8 yTemp = g_Player.Y;

			// Test des boutons de déplacement gauche/droite
			g_PlayerState = PLAYER_STATE_IDLE;
			if (Keyboard_IsKeyPressed(KEY_LEFT))
			{
				xTemp--;
				g_PlayerState = PLAYER_STATE_MOVE;
			}
			if (Keyboard_IsKeyPressed(KEY_RIGHT))
			{
				xTemp++;
				g_PlayerState = PLAYER_STATE_MOVE;
			}

			// Test du bouton d'interaction
			if (Keyboard_IsKeyPressed(KEY_SPACE))
			{
				count = 0;
				g_PlayerState = PLAYER_STATE_ACTION;
			}

			// Test du bouton d'interaction
			if (Keyboard_IsKeyPressed(KEY_UP) && !alreadyJumping)
			{

				alreadyJumping = TRUE;
				g_Player.VelocityY = 0;
				g_Player.Y -= 32;
			}
			else
			{
				alreadyJumping = FALSE;
			}

			// Test des collisions horizontales aux 4 coins du personnage
			bool bCollide = FALSE;
			bool bFalling = TRUE;

			if (checkCollision(xTemp, yTemp))
				bCollide = TRUE;
			if (checkCollision(xTemp + 15, yTemp))
				bCollide = TRUE;
			if (checkCollision(xTemp + 15, yTemp + 15))
				bCollide = TRUE;
			if (checkCollision(xTemp, yTemp + 15))
				bCollide = TRUE;

			if (checkCollision(xTemp + 8, yTemp + 17))
				bFalling = FALSE;

			if (!bCollide) // Application du déplacement si aucune collision n'est détectée
			{
				g_Player.X = xTemp;

				// VDP_SetColor(COLOR_BLACK);
			}
			else
			{
				g_Player.VelocityY = 0;
				// VDP_SetColor(COLOR_DARK_RED);
			}

			if (bFalling)
			{
				if (g_Player.VelocityY < 8)
					g_Player.VelocityY++;

				g_Player.Y = yTemp + g_Player.VelocityY;
				g_PlayerState = PLAYER_STATE_FALL;
			}
			else
			{
				g_Player.VelocityY = 0;
				g_Player.Y &= 0b11111000;
				// g_Player.Y--;
			}
		}

		// Calcul de la frame d'animation à jouer
		u8 baseNumPattern = 0;
		switch (g_PlayerState)
		{
		case PLAYER_STATE_IDLE:
			baseNumPattern = 0;
			break;
		case PLAYER_STATE_MOVE:
			baseNumPattern = g_NumPlayerFramesMove[count / 4 % 4] * 16;
			break;
		case PLAYER_STATE_ACTION:
			baseNumPattern = g_NumPlayerFramesAction[count / 2 % 8] * 16;
			break;
		case PLAYER_STATE_FALL:
			baseNumPattern = g_NumPlayerFramesFall[count / 4 % 4] * 16;
			break;
		}

		// Mise à jour de la position et du pattern des sprites du joueur (1 par couleur)
		VDP_SetSprite(SPT_PLAYER_HAIR, g_Player.X, g_Player.Y - 8 - 1, baseNumPattern);
		VDP_SetSprite(SPT_PLAYER_SKIN, g_Player.X, g_Player.Y - 1, baseNumPattern + 4);
		VDP_SetSprite(SPT_PLAYER_CHAIR, g_Player.X, g_Player.Y + 8 - 1, baseNumPattern + 8);
		VDP_SetSprite(SPT_PLAYER_OUTLINE, g_Player.X, g_Player.Y - 1, baseNumPattern + 12);
		if (g_FrameCounter % 4 == 0)
		{
			for (u8 i = 0; i < g_ElevatorCount; i++)
			{

				updateElevator(i);
			}
		}
		g_FrameCounter++;
	}
}