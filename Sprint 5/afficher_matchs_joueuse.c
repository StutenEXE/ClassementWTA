#pragma warning(disable:4996)
#pragma warning(disable:6031)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"
#include "trouver_index_tournoi.h"
/* afficher_matchs_joueuses.c
 * Auteurs : Raphaël Courraze (Groupe 101) , Alexandre Bidaux (Groupe 107)
 * Création : 10/10/2021
 * Dernière mise à jour : 03/11/2021
 */

/* Fonction qui cherche une joueuse et renvoie son index, si elle n'existe pas, renvoie "joueuse inconnue"
 * tournoiWTA [in] TournoiWTA*, liste de tous les tournois et joueuses
 * nbJoueuse [in] entier*, nombre de joueuses enregistrées
 * i [retour] entier, index de la joueuse trouvée
 */
int chercher_joueuse(const TournoiWTA* tournoiWTA, const char* mot, const int nbJoueuse) {
	int i = 0;
	while (i < nbJoueuse) {	// cherche le nom de la joueuse dans la liste des joueuses déjà enregistrées
		if (strcmp(tournoiWTA->dataJoueuses[i].nom, mot) == 0) {
			break;
		}
		i++;
	}
	if (i == nbJoueuse) {	// la joueuse n'a pas été enregistrée
		printf("joueuse inconnue\n");
		exit(0);
	}
	return i; //retourne l'index de la joueuse
}

/* Fonction qui affiche tous les matchs d'une joueuse durant un tournoi 
 * tournoiWTA [in] TournoiWTA*, liste de tous les tournois et joueuses
 * nbJoueuses [in] entier, nombre total de joueuses enregistrées
 * nbTournoisEnreg [in] entier*, nombre total de tournois enregistrés
 */
void afficher_matchs_joueuse(const TournoiWTA* tournoiWTA, const int nbJoueuses, const int* nbTournoisEnreg) {
	int indexJoueuse, indexTournoi = 0, indexMatch, i, idxGagnante, idxPerdante;
	unsigned int dateTournoi;
	char nomTournoi[lgMot + 1] = "", nomJoueuse[lgMot + 1] = "", mot[lgMot + 1] = "";

	scanf("%s", &nomTournoi);	//on lit le nom du tournoi
	scanf("%u", &dateTournoi);	//on recupere l'année du tournoi
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