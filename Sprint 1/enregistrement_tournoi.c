#pragma warning(disable:4996)
#pragma warning(disable:6031)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"

/* Fonction qui cherche une joueuse, la crée si elle n'existe pas et retoure son index dans le tableau des joueuses*/
int chercherJoueuse(TournoiWTA* tournoiWTA, char* mot, int* nbJoueuse) {
	int i = 0;
	while (i < *nbJoueuse) {	// cherche le nom de la joueuse dans la liste des joueuses déjà enregistrées
		if (strcmp(tournoiWTA->dataJoueuses[i].nom, mot) == 0) {
			break;
		}
		i++;
	}

	if (i == *nbJoueuse) {	// la joueuse n'a pas encore été enregistrée
		strcpy(tournoiWTA->dataJoueuses[i].nom, mot);
		tournoiWTA->dataJoueuses[i].points = 0;
		*nbJoueuse = *nbJoueuse + 1;
	}

	return i; //retourne l'index de la joueuse
}

void enregistrement_tournoi(TournoiWTA* tournoiWTA, const int indexTournoi, int* nbJoueuse) {
	int i,
		date,				// Année du tournoi 
		indexMatch = 0;		// index d'un match d'un tournoi

	unsigned int indexGagnante = 0,
		indexPerdante = 0;

	char mot[lgMot + 1] = "";

	scanf("%s", &mot);	//on lit le nom du tournoi
	scanf("%u", &date);	//on recupere l'année du tournoi

	tournoiWTA->dataTournois[indexTournoi].date = date; //les valeurs lues sont donnees a la variable tounoiWTA dans dataTournoi à l'index 
	strcpy(tournoiWTA->dataTournois[indexTournoi].nom, mot);   //du tournoi actuellement crée. On lui donne ici sa date et son nom

	//on commence la lecture des joueuses pour les stocker dans dataJoueuses et pour connaitre leur index et ensuite le rentrer dans match 
	while (indexMatch < nbMatchTournoi) {

		char mot[lgMot + 1] = "";

		scanf("%s", mot);	// nom de la première joueuse du match = gagnante

		if (strcmp(mot, "") != 0) { //si le mot n'est pas une cha�ne de caract�re vide
			indexGagnante = chercherJoueuse(tournoiWTA, mot, nbJoueuse);
		}

		scanf("%s", mot);	// nom de la deuxième joueuse du match = perdante
		if (strcmp(mot, "") != 0) {
			indexPerdante = chercherJoueuse(tournoiWTA, mot, nbJoueuse);
		}

		tournoiWTA->dataTournois[indexTournoi].dataMatch[indexMatch].idxGagnante = indexGagnante;
		tournoiWTA->dataTournois[indexTournoi].dataMatch[indexMatch].idxPerdante = indexPerdante;

		indexMatch++;//on passe au match suivant
	}
}