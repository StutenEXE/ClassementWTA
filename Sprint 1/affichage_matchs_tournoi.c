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
					printf("Tournoi inconnu\n");
					return; // si le tournoi est inconnu on sort de la fonction avec un return
				}
			}
			printf("%s %u\n", tournoiWTA->dataTournois[i].nom, tournoiWTA->dataTournois[i].date);
			int j = 0;
			int cpt = nbMatchTournoi; // on crée une variable pour pouvoir afficher les différentes phases du tournoi
			for (j; j < nbMatchTournoi; j++) {
				switch (cpt) {
				case 127: printf("64emes de finale\n");
					break;
				case 63: printf("32emes de finale\n");
					break;
				case 31: printf("16emes de finale\n");
					break;
				case 15: printf("n8emes de finale\n");
					break;
				case 7: printf("quarts de finale\n");
					break;
				case 3: printf("demi-finales\n");
					break;
				case 1: printf("finale\n");
					break;
				}
				printf("%s %s\n", (tournoiWTA->dataJoueuses[tournoiWTA->dataTournois[indexTournoi].dataMatch[j].idxGagnante]).nom, (tournoiWTA->dataJoueuses[tournoiWTA->dataTournois[indexTournoi].dataMatch[j].idxPerdante]).nom);
				cpt--;
			}
		}

	}
}
