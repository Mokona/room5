// Generated by MSXgl on 2024-03-17 23:53:11
#pragma once
#include "core.h"

// Language definition
#define LANG_EN 0
#define LANG_FR 1
#define LANG_JA 2
#define LANG_MAX 3

// Text ID definition
#define TEXT_TITLE 0
#define TEXT_TITLE_TWITCH 1
#define TEXT_PRESS_ESC 2
#define TEXT_ROOM1_QUESTION 3
#define TEXT_ROOM1_1 4
#define TEXT_ROOM1_2 5
#define TEXT_ROOM1_3 6
#define TEXT_ROOM7_QUESTION 7
#define TEXT_ROOM7_1 8
#define TEXT_ROOM7_2 9
#define TEXT_ROOM7_3 10
#define TEXT_ROOM11_QUESTION 11
#define TEXT_ROOM11_1 12
#define TEXT_ROOM11_2 13
#define TEXT_ROOM11_3 14
#define TEXT_ROOM15_QUESTION 15
#define TEXT_ROOM15_1 16
#define TEXT_ROOM15_2 17
#define TEXT_ROOM15_3 18
#define TEXT_ROOM19_QUESTION 19
#define TEXT_ROOM19_1 20
#define TEXT_ROOM19_2 21
#define TEXT_ROOM19_3 22
#define TEXT_ROOM23_QUESTION 23
#define TEXT_ROOM23_1 24
#define TEXT_ROOM23_2 25
#define TEXT_ROOM23_3 26
#define TEXT_ROOM25_QUESTION 27
#define TEXT_ROOM25_1 28
#define TEXT_ROOM25_2 29
#define TEXT_ROOM25_3 30
#define TEXT_END_HOSPITAL 31
#define TEXT_END_MATRIX 32
#define TEXT_END_ALIEN 33
#define TEXT_THANKS 34
#define TEXT_MAX 35

// Localization data table
const c8* const g_TransData[LANG_MAX][TEXT_MAX] =
{
	// EN
	{
		"MSXgl - Localization sample", // TEXT_TITLE
		"THIS GAME IS MADE LIVE ON TWITCH\n\nTWITCH.TV/MO5ASSORETRO", // TEXT_TITLE_TWITCH
		"HOLD 'ESC' TO RESET", // TEXT_PRESS_ESC
		"...YOU NEED...TO REACH...ROOM 5.", // TEXT_ROOM1_QUESTION
		"IS THAT WHERE I'LL WAKE UP ? ", // TEXT_ROOM1_1
		"IT'S IMPORTANT FOR YOU?", // TEXT_ROOM1_2
		"IT'S A SAVE POINT!", // TEXT_ROOM1_3
		"ROOM 5 WILL BRING YOU CLOSER... TO...THE TRUTH.", // TEXT_ROOM7_QUESTION
		"FOR ME OR YOU?", // TEXT_ROOM7_1
		"BONUS STAGE?", // TEXT_ROOM7_2
		"FOR MY MEMORIES?", // TEXT_ROOM7_3
		"...REMINDER...ROOM 5...IS THE KEY.", // TEXT_ROOM11_QUESTION
		"FOUR YOUR WEIRD GAME", // TEXT_ROOM11_1
		"I KNOW, I READ THE MANUAL", // TEXT_ROOM11_2
		"MY BODY IS A TRAP", // TEXT_ROOM11_3
		"...ROOM 5 IS DIFFERENT FROM...THE OTHERS.", // TEXT_ROOM15_QUESTION
		"IS IT A SECRET?", // TEXT_ROOM15_1
		"WHAT HAVE YOU DONE IN THAT ROOM?", // TEXT_ROOM15_2
		"IS THAT WHERE EVERYTHING WILL BECOM?", // TEXT_ROOM15_3
		"...ROOM 5...WILL GIVE YOU ANSWERS.", // TEXT_ROOM19_QUESTION
		"ABOUT MY CONDITION?", // TEXT_ROOM19_1
		"ABOUT THE OBJECTIVE?", // TEXT_ROOM19_2
		"ABOUT YOUR MISSION?", // TEXT_ROOM19_3
		"...ROOM 5...IS NEAR...DONT LOSE HOPE...", // TEXT_ROOM23_QUESTION
		"I JUST WANT TO UNDERSTAND.", // TEXT_ROOM23_1
		"WHY IS IT SO IMPORTANT TO YOU?", // TEXT_ROOM23_2
		"NEXT LEVEL?", // TEXT_ROOM23_3
		"...ROOM 5...IS YOUR DESTINY...", // TEXT_ROOM25_QUESTION
		"MY DESTINY OR YOURS?", // TEXT_ROOM25_1
		"MY DESTINY TO WAKE UP?", // TEXT_ROOM25_2
		"DESTINY FOR A PLAYER?", // TEXT_ROOM25_3
		"YOU'RE FINALLY AWAKE. YOU WHERE IN COMA, BUT YOU MANAGED TO FIGHT AND COME BACK TO US. YOUR MIND CREATED THIS PLACE TO HELP YOU TO WAKE UP. WELCOME BACK TO REALITY.", // TEXT_END_HOSPITAL
		"CONGRATULATIONS! YOU'VE COMPLETED THE GAME. EVERYTHING YOU EXPERIENCED WAS A SIMULATION, A CREATION OF OUR TEAM. YOU'VE BEEN AN EXCELLENT PLAYER. SEE YOU SOON IN ANOTHER GAME.", // TEXT_END_MATRIX
		"YOU DID WELL, HUMAN. YOU WHERE A VALUABLE SUBJECT FOR OUR STUDY. WE WANTED TO UNDERSTAND THE HUMAN MIND. YOU ARE FREE NOW, WITH MEMORIES OF UNIQUE EXPERIENCES.", // TEXT_END_ALIEN
		"THANKS FOR PLAYING!\n\nKAZERLELUTIN\nAOINEKO\nMOKONA", // TEXT_THANKS
	},
	// FR
	{
		"MSXgl - Sample de traduction", // TEXT_TITLE
		"    CE JEU EST FAIT\nEN LIVE SUR TWITCH\n\nTWITCH.TV/MO5ASSORETRO", // TEXT_TITLE_TWITCH
		"MAINTENIR 'ESC'\n POUR RELANCER", // TEXT_PRESS_ESC
		"...TU DOIS...ATTEINDRE...LA CHAMBRE 5.", // TEXT_ROOM1_QUESTION
		"C'EST LA QUE JE ME REVEILLERAI ?", // TEXT_ROOM1_1
		"C'EST IMPORTANT POUR VOUS ?", // TEXT_ROOM1_2
		"C'EST UN POINT DE SAUVEGARDE !", // TEXT_ROOM1_3
		"LA CHAMBRE 5 TE RAPPROCHERA... DE...LA VERITE.", // TEXT_ROOM7_QUESTION
		"POUR MOI OU POUR VOUS ?", // TEXT_ROOM7_1
		"NIVEAU BONUS ?", // TEXT_ROOM7_2
		"POUR MES SOUVENIRS ?", // TEXT_ROOM7_3
		"...RAPPEL...LA CHAMBRE 5...EST LA CLE.", // TEXT_ROOM11_QUESTION
		"POUR TON JEU BIZARRE", // TEXT_ROOM11_1
		"JE SAIS, J'AI LU LA NOTICE", // TEXT_ROOM11_2
		"MON CORPS EST UN PIEGE", // TEXT_ROOM11_3
		"...LA CHAMBRE 5 EST DIFFERENTE DES...AUTRES.", // TEXT_ROOM15_QUESTION
		"EST-CE UN SECRET ?", // TEXT_ROOM15_1
		"QUE FAITES-VOUS DANS CETTE CHAMBRE ?", // TEXT_ROOM15_2
		"EST-CE LA OU TOUT VA BASCULER ?", // TEXT_ROOM15_3
		"...LA CHAMBRE 5...TE DONNERA DES REPONSES.", // TEXT_ROOM19_QUESTION
		"SUR MON ETAT ?", // TEXT_ROOM19_1
		"SUR L'OBJECTIF ?", // TEXT_ROOM19_2
		"SUR TA MISSION ?", // TEXT_ROOM19_3
		"...LA CHAMBRE 5...EST PROCHE...NE PERDS PAS ESPOIR...", // TEXT_ROOM23_QUESTION
		"JE VEUX JUSTE COMPRENDRE.", // TEXT_ROOM23_1
		"POURQUOI EST-CE SI IMPORTANT POUR TOI ?", // TEXT_ROOM23_2
		"NIVEAU SUIVANT ?", // TEXT_ROOM23_3
		"...LA CHAMBRE 5...EST TON DESTIN...", // TEXT_ROOM25_QUESTION
		"MON DESTIN OU LE VOTRE ?", // TEXT_ROOM25_1
		"MON DESTIN DE ME REVEILLER ?", // TEXT_ROOM25_2
		"DESTIN POUR UN JOUEUR ?", // TEXT_ROOM25_3
		"VOUS ETES ENFIN REVEILLE. VOUS ETIEZ DANS LE COMA, MAIS VOUS AVEZ REUSSI A VOUS BATTRE ET A REVENIR VERS NOUS. VOTRE ESPRIT A CREE CET ENDROIT POUR VOUS AIDER A VOUS REVEILLER. BIENVENUE DANS LA REALITE.", // TEXT_END_HOSPITAL
		"FELICITATIONS ! VOUS AVEZ TERMINE LE JEU. TOUT CE QUE VOUS AVEZ VECU ETAIT UNE SIMULATION, UNE CREATION DE NOTRE EQUIPE. VOUS AVEZ ETE UN EXCELLENT JOUEUR. A BIENTOT DANS UN AUTRE JEU.", // TEXT_END_MATRIX
		"VOUS AVEZ BIEN FAIT, HUMAIN. VOUS ETIEZ UN SUJET DE VALEUR POUR NOTRE ETUDE. NOUS VOULIONS COMPRENDRE L'ESPRIT HUMAIN. VOUS ETES LIBRE MAINTENANT, AVEC DES SOUVENIRS D'EXPERIENCES UNIQUES.", // TEXT_END_ALIEN
		"MERCI D'AVOIR JOUE !\n\nKAZERLELUTIN\nAOINEKO\nMOKONA", // TEXT_THANKS
	},
	// JA
	{
		"MSXgl - \xDB\xB0\xB6\xD8\xBE\xDE\xB0\xBC\xAE\xDD\xA5\xBB\xDD\xCC\xDF\xD9", // TEXT_TITLE
		"\x9A\xE9\x99\xDE\xB0\xF1\xEATwitch\xE3\xDE\xF7\x92\xEC\xDE\xEA\x92\x9C\xFD\x9B\xFA\xE3\x92\xEF\x9D", // TEXT_TITLE_TWITCH
		NULL, // TEXT_PRESS_ESC
		NULL, // TEXT_ROOM1_QUESTION
		NULL, // TEXT_ROOM1_1
		NULL, // TEXT_ROOM1_2
		NULL, // TEXT_ROOM1_3
		NULL, // TEXT_ROOM7_QUESTION
		NULL, // TEXT_ROOM7_1
		NULL, // TEXT_ROOM7_2
		NULL, // TEXT_ROOM7_3
		NULL, // TEXT_ROOM11_QUESTION
		NULL, // TEXT_ROOM11_1
		NULL, // TEXT_ROOM11_2
		NULL, // TEXT_ROOM11_3
		NULL, // TEXT_ROOM15_QUESTION
		NULL, // TEXT_ROOM15_1
		NULL, // TEXT_ROOM15_2
		NULL, // TEXT_ROOM15_3
		NULL, // TEXT_ROOM19_QUESTION
		NULL, // TEXT_ROOM19_1
		NULL, // TEXT_ROOM19_2
		NULL, // TEXT_ROOM19_3
		NULL, // TEXT_ROOM23_QUESTION
		NULL, // TEXT_ROOM23_1
		NULL, // TEXT_ROOM23_2
		NULL, // TEXT_ROOM23_3
		NULL, // TEXT_ROOM25_QUESTION
		NULL, // TEXT_ROOM25_1
		NULL, // TEXT_ROOM25_2
		NULL, // TEXT_ROOM25_3
		NULL, // TEXT_END_HOSPITAL
		NULL, // TEXT_END_MATRIX
		NULL, // TEXT_END_ALIEN
		NULL, // TEXT_THANKS
	},
};