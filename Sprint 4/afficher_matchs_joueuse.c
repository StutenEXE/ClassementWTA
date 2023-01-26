#pragma warning(disable:4996)
#pragma warning(disable:6031)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"
#include "trouver_index_tournoi.h"


/* Fonction qui cherche une joueuse, la crée si elle n'existe pas et retoure son index dans le tableau des joueuses*/
int chercher_joueuse(TournoiWTA* tournoiWTA, char* mot, int* nbJoueuse) {
	int i = 0;
	while (i < *nbJoueuse) {	// cherche le nom de la joueuse dans la liste des joueuses déjà enregistrées
		if (strcmp(tournoiWTA->dataJoueuses[i].nom, mot) == 0) {
			break;
		}
		i++;
	}
	if (i == *nbJoueuse) {	// la joueuse n'a pas été enregistrée
		printf("joueuse inconnue\n");
		exit(0);
	}
	return i; //retourne l'index de la joueuse
}


void afficher_matchs_joueuse(TournoiWTA* tournoiWTA, int* nbJoueuses, int* nbTournois) {
	int indexJoueuse, indexTournoi = 0, indexMatch, i, idxGagnante, idxPerdante;
	unsigned int dateTournoi;
	char nomTournoi[lgMot + 1] = "", nomJoueuse[lgMot + 1] = "", mot[lgMot + 1] = "";

	scanf("%s", &nomTournoi);	//on lit le nom du tournoi
	scanf("%u", &dateTournoi);	//on recupere l'année du tournoi
	if (trouver_index_tournoi(tournoiWTA, nbTournois, &nomTournoi, &dateTournoi, &indexTournoi)) {
		scanf("%s", nomJoueuse);
		indexJoueuse = chercher_joueuse(tournoiWTA, nomJoueuse, nbJoueuses);

		for (indexMatch = 0; indexMatch < nbMatchTournoi; indexMatch++) {
			if ((tournoiWTA->dataTournois[indexTournoi].dataMatch[indexMatch].idxPerdante == indexJoueuse) || (tournoiWTA->dataTournois[indexTournoi].dataMatch[indexMatch].idxGagnante == indexJoueuse)) {
				idxGagnante = tournoiWTA->dataTournois[indexTournoi].dataMatch[indexMatch].idxGagnante;
				idxPerdante = tournoiWTA->dataTournois[indexTournoi].dataMatch[indexMatch].idxPerdante;
				printf("%s %s\n", (tournoiWTA->dataJoueuses[idxGagnante]).nom, (tournoiWTA->dataJoueuses[idxPerdante]).nom);
			}

		}
	}
}