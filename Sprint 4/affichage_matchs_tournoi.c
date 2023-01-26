#pragma warning(disable:4996)
#pragma warning(disable:6031)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"
#include "trouver_index_tournoi.h"

void affichage_matchs_tournoi(TournoiWTA* tournoiWTA, int* nbTournoisEnregistres) {
	int dateTournoi, indexTournoi, i = 0;
	char nomTournoi[lgMot + 1] = "";
	scanf("%s", &nomTournoi);	//on lit le nom du tournoi
	scanf("%u", &dateTournoi);	//on recupere l'année du tournoi
	if (trouver_index_tournoi(tournoiWTA, nbTournoisEnregistres, &nomTournoi, &dateTournoi, &indexTournoi)) {
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
			case 15: printf("8emes de finale\n");
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

