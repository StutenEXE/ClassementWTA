#pragma warning(disable:4996)
#pragma warning(disable:6031)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"
#include "affichage_matchs_tournoi.h"

void affichage_matchs_tournoi(TournoiWTA* tournoiWTA, int* nbTournoisEnregistres) {
	int date, indexTournoi, i = 0;
	char nom[lgMot + 1] = "";
	scanf("%s", &nom);	//on lit le nom du tournoi
	scanf("%u", &date);	//on recupere l'année du tournoi
	for (i; i < *nbTournoisEnregistres; i++) {
		if (((*tournoiWTA).dataTournois[i].date == date)) {
			int n = 0;
			for (n; n < lgMot + 1; n++) {
				if ((nom[n] == '\0') && ((*tournoiWTA).dataTournois[i].nom[n] == '\0')) {
					indexTournoi = i;
					break;
				}
				if (nom[n] != (*tournoiWTA).dataTournois[i].nom[n]) {
					printf("\ntournoi inconnu");
					return; // si le tournoi est inconnu on sort de la fonction avec un return
				}
			}
			printf("%s %u", tournoiWTA->dataTournois[i].nom, tournoiWTA->dataTournois[i].date);
			int j = 0;
			int cpt = nbMatchTournoi; // on crée une variable pour pouvoir afficher les différentes phases du tournoi
			for (j; j < nbMatchTournoi; j++) {
				switch (cpt) {
				case 127: printf("\n64emes de finale");
					break;
				case 63: printf("\n32emes de finale");
					break;
				case 31: printf("\n16emes de finale");
					break;
				case 15: printf("\n8emes de finale");
					break;
				case 7: printf("\nquarts de finale");
					break;
				case 3: printf("\ndemi-finales");
					break;
				case 1: printf("\nfinale");
					break;
				}
				printf("\n%s %s", (tournoiWTA->dataJoueuses[tournoiWTA->dataTournois[indexTournoi].dataMatch[j].idxGagnante]).nom, (tournoiWTA->dataJoueuses[tournoiWTA->dataTournois[indexTournoi].dataMatch[j].idxPerdante]).nom);
				cpt--;
			}
		}

	}
}

