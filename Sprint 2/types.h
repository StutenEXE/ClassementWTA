#pragma once
#define maxTournois 10 //nb max de tournois
#define lgMot 30 //chaque mot peut contenir jusqu'a 30 caractères
#define nbMatchTournoi 127 //dans chaque tournoi il y a 127 rencontres 
#define nbJoueusesTournoi 128 //il y a 128 joueuses dans chaque tounoi


typedef struct {
	char nom[lgMot + 1]; //+1 car on ajoute le '\0' à la fin 
	unsigned int points; //les points ne peuvent pas être négatifs ou a virgule, d'où unsigned int 
} Joueuse;

typedef struct {
	unsigned int idxGagnante; //index de la gagnante
	unsigned int idxPerdante; //index de la perdante 
} Match;

typedef struct {
	char nom[lgMot + 1];
	unsigned int date;
	Match dataMatch[nbMatchTournoi];
} Tournoi;

typedef struct {
	Tournoi dataTournois[maxTournois];
	Joueuse dataJoueuses[(maxTournois * nbJoueusesTournoi)];
	Match dataMatch[nbMatchTournoi];
} TournoiWTA;
