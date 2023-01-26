#pragma warning(disable:4996)
#pragma warning(disable:6031)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"
#include "trouver_index_tournoi.h"
/* affichage_joueuses_tournoi.c
 * Auteurs : Raphaël Courraze (Groupe 101) , Alexandre Bidaux (Groupe 107)
 * Création : 08/10/2021
 * Dernière mise à jour : 03/11/2021
 */

/* Fonction qui attribue des points aux joueuses 
 * idxMatch [in] entier, index du match evalué
 * idxJoueuse [in] entier, index de la joueuse évaluée
 * joueusesTournoi [out] Joueuse*, liste des joueuses du tournoi
 */
void attributionPoints(Joueuse* joueusesTournoi, const int idxMatch, const int idxJoueuse) {
	if (idxMatch < 64) { joueusesTournoi[idxJoueuse].points = 10; } else
	if (idxMatch < 96) { joueusesTournoi[idxJoueuse].points = 45; } else
	if (idxMatch < 112) { joueusesTournoi[idxJoueuse].points = 90; } else
	if (idxMatch < 120) { joueusesTournoi[idxJoueuse].points = 180; } else
	if (idxMatch < 124) { joueusesTournoi[idxJoueuse].points = 360; } else
	if (idxMatch < 126) { joueusesTournoi[idxJoueuse].points = 720; } else
	if (idxMatch == 126) { joueusesTournoi[idxJoueuse].points = 1200; }
}

//definition d'un type qui permet d'identifier les gagnantes et perdantes
typedef enum {PERD, VICT} Vict;

/* Fonction qui cherche une joueuse ou qui l'enregistre puis renvoie son index
 * mot [in] char*, nom lu
 * idxMatch [in] entier, index du match
 * statut [in] Vict, statut du résultat de la joueuse sur un match
 * nbJoueusesEnreg [in-out] entier, index de la joueuse évaluée
 * joueusesTournoi [out] Joueuse*, liste des joueuses du tournoi
 */
void chercherJoueuse_ouEnregistrer(Joueuse* joueusesTournoi, const char* mot, int* nbJoueuseEnregistre, 
	                               const int idxMatch, const Vict statut) {
	int i;
	for (i = 0; i < *nbJoueuseEnregistre; i++) {	// cherche le nom de la joueuse dans la liste des joueuses déjà enregistrées
		if (strcmp(joueusesTournoi[i].nom, mot) == 0) {
			attributionPoints(joueusesTournoi, idxMatch, i);
			if (idxMatch == nbMatchTournoi - 1 && statut == VICT) {
				joueusesTournoi[i].points = 2000;
			}
			break;
		}
	}
	if (i == *nbJoueuseEnregistre) {	// la joueuse n'a pas encore été enregistrée
		strcpy(joueusesTournoi[i].nom, mot);
		attributionPoints(joueusesTournoi, idxMatch, i);
		*nbJoueuseEnregistre = *nbJoueuseEnregistre + 1;
	}
}

/* Fonction de tri par insertion par ordre lexicographique croissant
 * joueusesTournoi [in-out] Joueuse*, liste des joueuses du tournoi à trier
 */
void tri_lexico(Joueuse* joueusesTournoi) {
	int i, j, stockageIndex;
	Joueuse joueuseAnalyse = joueusesTournoi[0];
	//il faut que le premier élément du tableau à trier soit l'élement le plus petit élément
	for (i = 1; i < nbJoueusesTournoi; i++) {
		if (strcmp(joueuseAnalyse.nom, joueusesTournoi[i].nom) > 0) {
			joueuseAnalyse = joueusesTournoi[i];
			stockageIndex = i;
		}
	}
	joueusesTournoi[stockageIndex] = joueusesTournoi[0];
	joueusesTournoi[0] = joueuseAnalyse;

	//le tri par insertion commence
	for (i = 1; i < nbJoueusesTournoi; i++) {
		joueuseAnalyse = joueusesTournoi[i];
		j = i;
		while (j > 1 && strcmp(joueusesTournoi[j - 1].nom, joueuseAnalyse.nom) > 0) {
			joueusesTournoi[j] = joueusesTournoi[j - 1];
			j--;
		}
		joueusesTournoi[j] = joueuseAnalyse;
	}
}

/* Fonction qui affiche toutes les joueuses d'un tournoi et leurs points de ce tournoi trié par 
 * ordre lexicographique 
 * tournoiWTA [in] TournoiWTA*, liste de tous les tournois et joueuses
 * nbTournois [in] entier*, nombre total de tournois enregistrés
 */
void affichage_joueuses_tournoi(const TournoiWTA* tournoiWTA, const int* nbTournois) {
	int idxTournoi = 0, nbJoueusesEnregistres = 0, idxMatch, idxJoueuse, i, idxPerdante, idxGagnante;
	unsigned int dateTournoi;

	char nomTournoi[lgMot + 1] = "";
	scanf("%s", &nomTournoi);	//on lit le nom du tournoi
	scanf("%u", &dateTournoi);	//on recupere l'année du tournoi

	Joueuse joueusesTournoi[nbJoueusesTournoi];

	//on transfert l'information des joueuses du tournoi dans un autre tableau que l'on peut modifier (et donc trier)
	if (trouver_index_tournoi(tournoiWTA, nbTournois, &nomTournoi, &dateTournoi, &idxTournoi)) {
		for (idxMatch = 0; idxMatch < nbMatchTournoi; idxMatch++) {
			idxPerdante = tournoiWTA->dataTournois[idxTournoi].dataMatch[idxMatch].idxPerdante;
			idxGagnante = tournoiWTA->dataTournois[idxTournoi].dataMatch[idxMatch].idxGagnante;
			chercherJoueuse_ouEnregistrer(joueusesTournoi, tournoiWTA->dataJoueuses[idxPerdante].nom, 
				                          &nbJoueusesEnregistres, idxMatch, PERD);
			chercherJoueuse_ouEnregistrer(joueusesTournoi, tournoiWTA->dataJoueuses[idxGagnante].nom, 
				                          &nbJoueusesEnregistres, idxMatch, VICT);
		}

		tri_lexico(joueusesTournoi);

		printf("%s %u\n", nomTournoi, dateTournoi);
		for (i = 0; i < nbJoueusesTournoi; i++) {
			printf("%s %u\n", joueusesTournoi[i].nom, joueusesTournoi[i].points);
		}
	}
}