#pragma warning(disable:4996)
#pragma warning(disable:6031)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"
#include "trouver_index_tournoi.h"
/* afficher_matchs_joueuses.c
 * Auteurs : Rapha�l Courraze (Groupe 101) , Alexandre Bidaux (Groupe 107)
 * Cr�ation : 10/10/2021
 * Derni�re mise � jour : 03/11/2021
 */

/* Fonction qui cherche une joueuse et renvoie son index, si elle n'existe pas, renvoie "joueuse inconnue"
 * tournoiWTA [in] TournoiWTA*, liste de tous les tournois et joueuses
 * nbJoueuse [in] entier*, nombre de joueuses enregistr�es
 * i [retour] entier, index de la joueuse trouv�e
 */
int chercher_joueuse(const TournoiWTA* tournoiWTA, const char* mot, const int nbJoueuse) {
	int i = 0;
	while (i < nbJoueuse) {	// cherche le nom de la joueuse dans la liste des joueuses d�j� enregistr�es
		if (strcmp(tournoiWTA->dataJoueuses[i].nom, mot) == 0) {
			break;
		}
		i++;
	}
	if (i == nbJoueuse) {	// la joueuse n'a pas �t� enregistr�e
		printf("joueuse inconnue\n");
		exit(0);
	}
	return i; //retourne l'index de la joueuse
}

/* Fonction qui affiche tous les matchs d'une joueuse durant un tournoi 
 * tournoiWTA [in] TournoiWTA*, liste de tous les tournois et joueuses
 * nbJoueuses [in] entier, nombre total de joueuses enregistr�es
 * nbTournoisEnreg [in] entier*, nombre total de tournois enregistr�s
 */
void afficher_matchs_joueuse(const TournoiWTA* tournoiWTA, const int nbJoueuses, const int* nbTournoisEnreg) {
	int indexJoueuse, indexTournoi = 0, indexMatch, i, idxGagnante, idxPerdante;
	unsigned int dateTournoi;
	char nomTournoi[lgMot + 1] = "", nomJoueuse[lgMot + 1] = "", mot[lgMot + 1] = "";

	scanf("%s", &nomTournoi);	//on lit le nom du tournoi
	scanf("%u", &dateTournoi);	//on recupere l'ann�e du tournoi
	if (trouver_index_tournoi(tournoiWTA, nbTournoisEnreg, &nomTournoi, &dateTournoi, &indexTournoi)) {
		scanf("%s", nomJoueuse);
		indexJoueuse = chercher_joueuse(tournoiWTA, nomJoueuse, nbJoueuses);

		for (indexMatch = 0; indexMatch < nbMatchTournoi; indexMatch++) {
			if ((tournoiWTA->dataTournois[indexTournoi].dataMatch[indexMatch].idxPerdante == indexJoueuse) ||
				(tournoiWTA->dataTournois[indexTournoi].dataMatch[indexMatch].idxGagnante == indexJoueuse)) {
				idxGagnante = tournoiWTA->dataTournois[indexTournoi].dataMatch[indexMatch].idxGagnante;
				idxPerdante = tournoiWTA->dataTournois[indexTournoi].dataMatch[indexMatch].idxPerdante;
				printf("%s %s\n", (tournoiWTA->dataJoueuses[idxGagnante]).nom, (tournoiWTA->dataJoueuses[idxPerdante]).nom);
			}

		}
	}
	else {
		exit(0);
	}
}