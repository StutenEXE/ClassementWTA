#pragma once
#define maxTournois 10 //nb max de tournois
#define lgMot 30 //chaque mot peut contenir jusqu'a 30 caractères
#define nbMatchTournoi 127 //dans chaque tournoi il y a 127 rencontres 
#define nbJoueusesTournoi 128 //il y a 128 joueuses dans chaque tounoi
/* types.h
 * Auteurs : Raphaël Courraze (Groupe 101) , Alexandre Bidaux (Groupe 107)
 * Création : 01/10/2021
 * Dernière mise à jour : 03/11/2021
 * Sert à importer les types dans chaque source (évite de devoir recopier)
 */

typedef struct {
	char nom[lgMot + 1]; //+1 car on ajoute le '\0' à la fin 
	unsigned int points; //les points ne peuvent pas être négatifs ou à virgule, d'où unsigned int 
} Joueuse;

typedef struct {
	unsigned int idxGagnante; //index de la gagnante, ne peut être ni négatif ou à virgule
	unsigned int idxPerdante; //index de la perdante, ne peut être ni négatif ou à virgule
} Match;

typedef struct {
	char nom[lgMot + 1]; //nom du tournoi (30 caractères + '\0')
	unsigned int date; //année du tournoi, ne peut être ni négatif ou à virgule
	Match dataMatch[nbMatchTournoi]; //tableau des 127 matchs du tournoi
} Tournoi;

typedef struct {
	Tournoi dataTournois[maxTournois]; //liste de tous les tournois (max 10)
	Joueuse dataJoueuses[(maxTournois * nbJoueusesTournoi)]; //liste de toutes les joueuses (max 1280)
} TournoiWTA;

typedef enum {FALSE = 0, TRUE = 1} Bool; //type booléen pas inclus par défaut en C