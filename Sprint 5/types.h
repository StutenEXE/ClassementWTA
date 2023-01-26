#pragma once
#define maxTournois 10 //nb max de tournois
#define lgMot 30 //chaque mot peut contenir jusqu'a 30 caract�res
#define nbMatchTournoi 127 //dans chaque tournoi il y a 127 rencontres 
#define nbJoueusesTournoi 128 //il y a 128 joueuses dans chaque tounoi
/* types.h
 * Auteurs : Rapha�l Courraze (Groupe 101) , Alexandre Bidaux (Groupe 107)
 * Cr�ation : 01/10/2021
 * Derni�re mise � jour : 03/11/2021
 * Sert � importer les types dans chaque source (�vite de devoir recopier)
 */

typedef struct {
	char nom[lgMot + 1]; //+1 car on ajoute le '\0' � la fin 
	unsigned int points; //les points ne peuvent pas �tre n�gatifs ou � virgule, d'o� unsigned int 
} Joueuse;

typedef struct {
	unsigned int idxGagnante; //index de la gagnante, ne peut �tre ni n�gatif ou � virgule
	unsigned int idxPerdante; //index de la perdante, ne peut �tre ni n�gatif ou � virgule
} Match;

typedef struct {
	char nom[lgMot + 1]; //nom du tournoi (30 caract�res + '\0')
	unsigned int date; //ann�e du tournoi, ne peut �tre ni n�gatif ou � virgule
	Match dataMatch[nbMatchTournoi]; //tableau des 127 matchs du tournoi
} Tournoi;

typedef struct {
	Tournoi dataTournois[maxTournois]; //liste de tous les tournois (max 10)
	Joueuse dataJoueuses[(maxTournois * nbJoueusesTournoi)]; //liste de toutes les joueuses (max 1280)
} TournoiWTA;

typedef enum {FALSE = 0, TRUE = 1} Bool; //type bool�en pas inclus par d�faut en C