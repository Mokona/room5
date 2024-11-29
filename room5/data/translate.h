// Generated by MSXgl on 2024-11-30 00:13:45
#pragma once
#include "core.h"
#include "data/translate_def.h"

// Localization data table
const c8* const g_TransData[LANG_MAX][TEXT_MAX] =
{
	// EN
	{
		"ENGLISH", // TEXT_LANG_LABEL
		"ROOM 5", // TEXT_TITLE
		"THIS GAME WAS MADE LIVE\n ON TWITCH\n\nTWITCH.TV/MO5ASSORETRO", // TEXT_TITLE_TWITCH
		"HOLD 'ESC' TO RESET\n A LEVEL", // TEXT_PRESS_ESC
		"...YOU NEED... TO REACH...\n ROOM 5.\n\n1.IS THAT WHERE I'LL WAKE UP?\n\n2.IS IT IMPORTANT TO YOU?\n\n3.IT'S A SAVE POINT!", // TEXT_ROOM1
		"...ROOM 5 WILL BRING YOU...\n CLOSER TO... THE TRUTH.\n\n1.FOR ME OR YOU?\n\n2.BONUS STAGE?\n\n3.FOR MY MEMORIES?", // TEXT_ROOM7
		"...REMINDER... ROOM 5...\n IS THE KEY.\n\n1.FOR YOUR WEIRD GAME.\n\n2.I KNOW, I READ THE MANUAL.\n\n3.MY BODY IS A TRAP.", // TEXT_ROOM11
		"...ROOM 5 IS DIFFERENT\n FROM... THE OTHERS.\n\n1.IS IT A SECRET?\n\n2.WHAT HAVE YOU DONE\n   IN THAT ROOM?\n\n3.IS THAT WHERE\n   EVERYTHING WILL BECOM?", // TEXT_ROOM15
		"...ROOM 5... WILL GIVE...\n YOU ANSWERS.\n\n1.ABOUT MY CONDITION?\n\n2.ABOUT THE OBJECTIVE?\n\n3.ABOUT YOUR MISSION?", // TEXT_ROOM19
		"...ROOM 5... IS NEAR...\n DONT LOSE HOPE...\n\n1.I JUST WANT TO UNDERSTAND.\n\n2.WHY IS IT SO\n   IMPORTANT TO YOU?\n\n3.NEXT LEVEL?", // TEXT_ROOM23
		"...ROOM 5... IS...\n YOUR DESTINY...\n\n1.MY DESTINY OR YOURS?\n\n2.MY DESTINY TO WAKE UP?\n\n3.DESTINY FOR A PLAYER?", // TEXT_ROOM25
		"YOU'RE FINALLY AWAKE.\nYOU WHERE IN A COMA,\nBUT YOU MANAGED TO FIGHT\nAND COME BACK TO US.\n\nYOUR MIND CREATED THIS PLACE\nTO HELP YOU WAKE UP.\n\nWELCOME BACK TO REALITY.", // TEXT_END_HOSPITAL
		"CONGRATULATIONS!\nYOU'VE COMPLETED THE GAME.\nEVERYTHING YOU EXPERIENCED\nWAS A SIMULATION,\nA CREATION OF OUR TEAM.\nYOU'VE BEEN AN\nEXCELLENT PLAYER.\n\nSEE YOU SOON IN ANOTHER GAME.", // TEXT_END_MATRIX
		"YOU DID WELL, HUMAN.\nYOU WHERE A VALUABLE\nSUBJECT FOR OUR STUDY.\nWE WANTED TO UNDERSTAND\nTHE HUMAN MIND.\n\nYOU ARE FREE NOW, WITH MEMORIES\nOF UNIQUE EXPERIENCES.", // TEXT_END_ALIEN
		"      THANKS FOR PLAYING!\n\n\n DESIGN, CODE:\n  KAZERLELUTIN, AOINEKO, MOKONA\n\n MUSIC:\n  TOTTA\n\n TRANSLATION:\n  ...", // TEXT_THANKS
	},
	// FR
	{
		"FRANCAIS", // TEXT_LANG_LABEL
		"ROOM 5", // TEXT_TITLE
		"CE JEU EST FAIT EN LIVE\nSUR TWITCH\n\nTWITCH.TV/MO5ASSORETRO", // TEXT_TITLE_TWITCH
		"  MAINTENIR 'ESC'\n   POUR RELANCER", // TEXT_PRESS_ESC
		"...TU DOIS...ATTEINDRE\n...LA CHAMBRE 5.\n\n1.C'EST LA QUE JE\n  ME REVEILLERAI?\n\n2.C'EST IMPORTANT\n  POUR VOUS?\n\n3.C'EST UN POINT\n  DE SAUVEGARDE !", // TEXT_ROOM1
		"...LA CHAMBRE 5...\nTE RAPPROCHERA...\nDE...LA VERITE.\n\n1.POUR MOI OU POUR VOUS?\n\n2.NIVEAU BONUS?\n\n3.POUR MES SOUVENIRS?", // TEXT_ROOM7
		"...RAPPEL...\nLA CHAMBRE 5...\nEST LA CLE.\n\n1.POUR TON JEU BIZARRE\n\n2.JE SAIS,\n  J'AI LU LA NOTICE\n\n3.MON CORPS EST UN PIEGE", // TEXT_ROOM11
		"...LA CHAMBRE 5\nEST DIFFERENTE\nDES...AUTRES.\n\n1.EST-CE UN SECRET?\n\n2.QUE FAITES-VOUS\n  DANS CETTE CHAMBRE?\n\n3.EST-CE LA OU\n  TOUT VA BASCULER?", // TEXT_ROOM15
		"...LA CHAMBRE 5\n...TE DONNERA\nDES REPONSES.\n\n1.SUR MON ETAT?\n\n2.SUR L'OBJECTIF?\n\n3.SUR VOTRE MISSION?", // TEXT_ROOM19
		"...LA CHAMBRE 5\n...EST PROCHE...\nNE PERDS PAS ESPOIR...\n\n1.JE VEUX JUSTE COMPRENDRE.\n\n2.POURQUOI EST-CE SI\n  IMPORTANT POUR VOUS?\n\n3.NIVEAU SUIVANT?", // TEXT_ROOM23
		"...LA CHAMBRE 5\n...EST TON DESTIN...\n\n1.MON DESTIN OU LE VOTRE?\n\n2.MON DESTIN POUR\n  ME REVEILLER?\n\n3.DESTIN POUR UN JOUEUR?", // TEXT_ROOM25
		"VOUS ETES ENFIN REVEILLE.\nVOUS ETIEZ DANS LE COMA,\nMAIS VOUS AVEZ REUSSI\nA VOUS BATTRE\nET A REVENIR VERS NOUS.\nVOTRE ESPRIT A CREE CET ENDROIT\nPOUR VOUS AIDER A\nVOUS REVEILLER.\n\nBIENVENUE DANS LA REALITE.", // TEXT_END_HOSPITAL
		"FELICITATIONS !\nVOUS AVEZ TERMINE LE JEU.\nTOUT CE QUE VOUS AVEZ VECU\nETAIT UNE SIMULATION,\nUNE CREATION DE NOTRE EQUIPE.\nVOUS AVEZ ETE UN\nEXCELLENT JOUEUR.\n\nA BIENTOT DANS UN AUTRE JEU.", // TEXT_END_MATRIX
		"VOUS AVEZ BIEN FAIT, HUMAIN.\nVOUS ETIEZ UN SUJET DE\nVALEUR POUR NOTRE ETUDE.\nNOUS VOULIONS COMPRENDRE\nL'ESPRIT HUMAIN.\nVOUS ETES LIBRE MAINTENANT,\nAVEC DES SOUVENIRS\nD'EXPERIENCES UNIQUES.", // TEXT_END_ALIEN
		" MERCI D'AVOIR JOUE !\n\n\n     KAZERLELUTIN\n\n     AOINEKO\n\n     MOKONA", // TEXT_THANKS
	},
	// JA
	{
		"NIHONGO", // TEXT_LANG_LABEL
		"\x3B\x38\x38\x36\x25", // TEXT_TITLE
		"\x87\x87\x4D\x5C\x4C\x7C\x7B\x64\x5D\x3D\x40\x32\x3D\x2C\x31\n\x87\x87\x87\x87\x87\x87\x87\x87\x5C\x35\x32\x3F\x2E\x56\x7C\x55\x4B\x6A\x6D\x62\x4F\x53\n\n\x87\x3D\x40\x32\x3D\x2C\x31\x7F\x3D\x3F\x86\x36\x38\x25\x2A\x3C\x3C\x38\x3B\x2E\x3D\x3B\x38", // TEXT_TITLE_TWITCH
		"\x67\x6B\x58\x48\x50\x53\x65\x82\x2E\x3C\x2C\x83\x70\x48\x4F\x55\x55\x7C\x4C\x6C", // TEXT_PRESS_ESC
		"\x82\x7F\x7F\x7F\x25\x4D\x7C\x46\x4F\x55\x7F\x7F\x7F\x59\x45\x49\x58\x45\x57\x7F\x7F\x7F\x83\n\n\x21\x7F\x52\x4D\x59\x45\x77\x53\x6A\x7E\n\x87\x87\x68\x65\x49\x6A\x65\x49\x7C\x4E\x65\x6C\x5C\x49\x58\x85\n\n\x22\x7F\x52\x6D\x5D\x44\x58\x53\x59\x57\x77\x56\x53\x7C\x45\x4F\x7C\x56\x7C\x50\x49\x85\n\n\x23\x7F\x52\x6D\x5D\x3C\x2A\x3F\x2E\x87\x39\x38\x32\x37\x3D\x53\x7C\x84", // TEXT_ROOM1
		"\x52\x4F\x4F\x4D\x87\x35\x87\x57\x49\x4C\x4C\x87\x42\x52\x49\x4E\x47\x87\x59\x4F\x55\x5C\x6E\x43\x4C\x4F\x53\x45\x52\x2E\x2E\x2E\x87\x54\x4F\x2E\x2E\x2E\x5C\x6E\x54\x48\x45\x87\x54\x52\x55\x54\x48\x2E\x5C\x6E\x5C\x6E\x31\x2E\x46\x4F\x52\x87\x4D\x45\x87\x4F\x52\x87\x59\x4F\x55\x3F\x5C\x6E\x5C\x6E\x32\x2E\x42\x4F\x4E\x55\x53\x87\x53\x54\x41\x47\x45\x3F\x5C\x6E\x5C\x6E\x33\x2E\x46\x4F\x52\x87\x4D\x59\x87\x4D\x45\x4D\x4F\x52\x49\x45\x53\x3F", // TEXT_ROOM7
		"\x2E\x2E\x2E\x52\x45\x4D\x49\x4E\x44\x45\x52\x2E\x2E\x2E\x52\x4F\x4F\x4D\x87\x35\x5C\x6E\x2E\x2E\x2E\x49\x53\x87\x54\x48\x45\x87\x4B\x45\x59\x2E\x5C\x6E\x5C\x6E\x31\x2E\x46\x4F\x52\x87\x59\x4F\x55\x52\x87\x57\x45\x49\x52\x44\x87\x47\x41\x4D\x45\x5C\x6E\x5C\x6E\x32\x2E\x49\x87\x4B\x4E\x4F\x57\x2C\x5C\x6E\x87\x87\x49\x87\x52\x45\x41\x44\x87\x54\x48\x45\x87\x4D\x41\x4E\x55\x41\x4C\x5C\x6E\x5C\x6E\x33\x2E\x4D\x59\x87\x42\x4F\x44\x59\x87\x49\x53\x87\x41\x87\x54\x52\x41\x50", // TEXT_ROOM11
		"\x2E\x2E\x2E\x52\x4F\x4F\x4D\x87\x35\x87\x49\x53\x87\x44\x49\x46\x46\x45\x52\x45\x4E\x54\x5C\x6E\x46\x52\x4F\x4D\x2E\x2E\x2E\x54\x48\x45\x87\x4F\x54\x48\x45\x52\x53\x2E\x5C\x6E\x5C\x6E\x31\x2E\x49\x53\x87\x49\x54\x87\x41\x87\x53\x45\x43\x52\x45\x54\x3F\x5C\x6E\x5C\x6E\x32\x2E\x57\x48\x41\x54\x87\x48\x41\x56\x45\x87\x59\x4F\x55\x87\x44\x4F\x4E\x45\x5C\x6E\x87\x87\x49\x4E\x87\x54\x48\x41\x54\x87\x52\x4F\x4F\x4D\x3F\x5C\x6E\x5C\x6E\x33\x2E\x49\x53\x87\x54\x48\x41\x54\x87\x57\x48\x45\x52\x45\x5C\x6E\x87\x87\x45\x56\x45\x52\x59\x54\x48\x49\x4E\x47\x87\x57\x49\x4C\x4C\x87\x42\x45\x43\x4F\x4D\x3F", // TEXT_ROOM15
		"\x2E\x2E\x2E\x52\x4F\x4F\x4D\x87\x35\x2E\x2E\x2E\x57\x49\x4C\x4C\x87\x47\x49\x56\x45\x5C\x6E\x59\x4F\x55\x87\x41\x4E\x53\x57\x45\x52\x53\x2E\x5C\x6E\x5C\x6E\x31\x2E\x41\x42\x4F\x55\x54\x87\x4D\x59\x87\x43\x4F\x4E\x44\x49\x54\x49\x4F\x4E\x3F\x5C\x6E\x5C\x6E\x32\x2E\x41\x42\x4F\x55\x54\x87\x54\x48\x45\x87\x4F\x42\x4A\x45\x43\x54\x49\x56\x45\x3F\x5C\x6E\x5C\x6E\x33\x2E\x41\x42\x4F\x55\x54\x87\x59\x4F\x55\x52\x87\x4D\x49\x53\x53\x49\x4F\x4E\x3F", // TEXT_ROOM19
		"\x2E\x2E\x2E\x52\x4F\x4F\x4D\x87\x35\x2E\x2E\x2E\x49\x53\x87\x4E\x45\x41\x52\x5C\x6E\x2E\x2E\x2E\x44\x4F\x4E\x54\x87\x4C\x4F\x53\x45\x87\x48\x4F\x50\x45\x2E\x2E\x2E\x5C\x6E\x5C\x6E\x31\x2E\x49\x87\x4A\x55\x53\x54\x87\x57\x41\x4E\x54\x5C\x6E\x87\x87\x54\x4F\x87\x55\x4E\x44\x45\x52\x53\x54\x41\x4E\x44\x2E\x5C\x6E\x5C\x6E\x32\x2E\x57\x48\x59\x87\x49\x53\x87\x49\x54\x87\x53\x4F\x5C\x6E\x87\x87\x49\x4D\x50\x4F\x52\x54\x41\x4E\x54\x87\x54\x4F\x87\x59\x4F\x55\x3F\x5C\x6E\x5C\x6E\x33\x2E\x4E\x45\x58\x54\x87\x4C\x45\x56\x45\x4C\x3F", // TEXT_ROOM23
		"\x2E\x2E\x2E\x52\x4F\x4F\x4D\x87\x35\x2E\x2E\x2E\x49\x53\x5C\x6E\x59\x4F\x55\x52\x87\x44\x45\x53\x54\x49\x4E\x59\x2E\x2E\x2E\x5C\x6E\x5C\x6E\x31\x2E\x4D\x59\x87\x44\x45\x53\x54\x49\x4E\x59\x87\x4F\x52\x87\x59\x4F\x55\x52\x53\x3F\x5C\x6E\x5C\x6E\x32\x2E\x4D\x59\x87\x44\x45\x53\x54\x49\x4E\x59\x87\x54\x4F\x87\x57\x41\x4B\x45\x87\x55\x50\x3F\x5C\x6E\x5C\x6E\x33\x2E\x44\x45\x53\x54\x49\x4E\x59\x87\x46\x4F\x52\x87\x41\x87\x50\x4C\x41\x59\x45\x52\x3F", // TEXT_ROOM25
		"\x59\x4F\x55\x27\x52\x45\x87\x46\x49\x4E\x41\x4C\x4C\x59\x87\x41\x57\x41\x4B\x45\x2E\x5C\x6E\x59\x4F\x55\x87\x57\x48\x45\x52\x45\x87\x49\x4E\x87\x43\x4F\x4D\x41\x2C\x5C\x6E\x42\x55\x54\x87\x59\x4F\x55\x87\x4D\x41\x4E\x41\x47\x45\x44\x87\x54\x4F\x87\x46\x49\x47\x48\x54\x5C\x6E\x41\x4E\x44\x87\x43\x4F\x4D\x45\x87\x42\x41\x43\x4B\x87\x54\x4F\x87\x55\x53\x2E\x5C\x6E\x5C\x6E\x59\x4F\x55\x52\x87\x4D\x49\x4E\x44\x87\x43\x52\x45\x41\x54\x45\x44\x87\x54\x48\x49\x53\x87\x50\x4C\x41\x43\x45\x5C\x6E\x54\x4F\x87\x48\x45\x4C\x50\x87\x59\x4F\x55\x87\x54\x4F\x87\x57\x41\x4B\x45\x87\x55\x50\x2E\x6E\x5C\x6E\x57\x45\x4C\x43\x4F\x4D\x45\x87\x42\x41\x43\x4B\x87\x54\x4F\x87\x52\x45\x41\x4C\x49\x54\x59\x2E", // TEXT_END_HOSPITAL
		"\x43\x4F\x4E\x47\x52\x41\x54\x55\x4C\x41\x54\x49\x4F\x4E\x53\x21\x5C\x6E\x59\x4F\x55\x27\x56\x45\x87\x43\x4F\x4D\x50\x4C\x45\x54\x45\x44\x87\x54\x48\x45\x87\x47\x41\x4D\x45\x2E\x5C\x6E\x45\x56\x45\x52\x59\x54\x48\x49\x4E\x47\x87\x59\x4F\x55\x87\x45\x58\x50\x45\x52\x49\x45\x4E\x43\x45\x44\x5C\x6E\x57\x41\x53\x87\x41\x87\x53\x49\x4D\x55\x4C\x41\x54\x49\x4F\x4E\x2C\x5C\x6E\x41\x87\x43\x52\x45\x41\x54\x49\x4F\x4E\x87\x4F\x46\x87\x4F\x55\x52\x87\x54\x45\x41\x4D\x2E\x5C\x6E\x59\x4F\x55\x27\x56\x45\x87\x42\x45\x45\x4E\x87\x41\x4E\x5C\x6E\x45\x58\x43\x45\x4C\x4C\x45\x4E\x54\x87\x50\x4C\x41\x59\x45\x52\x2E\x5C\x6E\x5C\x6E\x53\x45\x45\x87\x59\x4F\x55\x87\x53\x4F\x4F\x4E\x87\x49\x4E\x87\x41\x4E\x4F\x54\x48\x45\x52\x87\x47\x41\x4D\x45\x2E", // TEXT_END_MATRIX
		"\x59\x4F\x55\x87\x44\x49\x44\x87\x57\x45\x4C\x4C\x2C\x87\x48\x55\x4D\x41\x4E\x2E\x5C\x6E\x59\x4F\x55\x87\x57\x48\x45\x52\x45\x87\x41\x87\x56\x41\x4C\x55\x41\x42\x4C\x45\x5C\x6E\x53\x55\x42\x4A\x45\x43\x54\x87\x46\x4F\x52\x87\x4F\x55\x52\x87\x53\x54\x55\x44\x59\x2E\x5C\x6E\x57\x45\x87\x57\x41\x4E\x54\x45\x44\x87\x54\x4F\x87\x55\x4E\x44\x45\x52\x53\x54\x41\x4E\x44\x5C\x6E\x54\x48\x45\x87\x48\x55\x4D\x41\x4E\x87\x4D\x49\x4E\x44\x2E\x5C\x6E\x5C\x6E\x59\x4F\x55\x87\x41\x52\x45\x87\x46\x52\x45\x45\x87\x4E\x4F\x57\x2C\x5C\x6E\x57\x49\x54\x48\x87\x4D\x45\x4D\x4F\x52\x49\x45\x53\x87\x4F\x46\x5C\x6E\x55\x4E\x49\x51\x55\x45\x87\x45\x58\x50\x45\x52\x49\x45\x4E\x43\x45\x53\x2E", // TEXT_END_ALIEN
		"\x87\x87\x54\x48\x41\x4E\x4B\x53\x87\x46\x4F\x52\x87\x50\x4C\x41\x59\x49\x4E\x47\x21\x5C\x6E\x5C\x6E\x5C\x6E\x87\x87\x87\x87\x87\x4B\x41\x5A\x45\x52\x4C\x45\x4C\x55\x54\x49\x4E\x5C\x6E\x5C\x6E\x87\x87\x87\x87\x87\x41\x4F\x49\x4E\x45\x4B\x4F\x5C\x6E\x5C\x6E\x87\x87\x87\x87\x87\x4D\x4F\x4B\x4F\x4E\x41", // TEXT_THANKS
	},
};