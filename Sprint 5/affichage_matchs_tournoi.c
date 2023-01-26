#pragma warning(disable:4996)
#pragma warning(disable:6031)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"
#include "trouver_index_tournoi.h"
/* affichage_matchs_tournoi.c
 * Auteurs : Raphaël Courraze (Groupe 101) , Alexandre Bidaux (Groupe 107)
 * Création : 01/10/2021
 * Dernière mise à jour : 03/11/2021
 */

/* Fonction qui affiche tous les matchs du tournoi coupés par la phase du tournoi
 * nbTournoisEnreg [in] entier*, nombre total de tournois enregistres
 * tournoiWTA [in] TournoiWTA*, liste de tous les tournois et joueuses
 */
void affichage_matchs_tournoi(const TournoiWTA* tournoiWTA, const int* nbTournoisEnreg) {
	int dateTournoi, idxTournoi;
	char nomTournoi[lgMot + 1] = "";
	scanf("%s", &nomTournoi);	//on lit le nom du tournoi
	scanf("%u", &dateTournoi);	//on recupere l'année du tournoi
	if (trouver_index_tournoi(tournoiWTA, nbTournoisEnreg, &nomTournoi, &dateTournoi, &idxTournoi)) {
		printf("%s %u\n", tournoiWTA->dataTournois[idxTournoi].nom, tournoiWTA->dataTournois[idxTournoi].date);
		int j = 0;
		// on crée une variable pour pouvoir faire un décompte des matchs
		int cpt = nbMatchTournoi; 
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
			printf("%s %s\n", (tournoiWTA->dataJoueuses[tournoiWTA->dataTournois[idxTournoi].dataMatch[j].idxGagnante]).nom,
				(tournoiWTA->dataJoueuses[tournoiWTA->dataTournois[idxTournoi].dataMatch[j].idxPerdante]).nom);
			cpt--;
		}
	}
}

