#pragma warning(disable:4996)
#pragma warning(disable:6031)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"
/* afficher_classement.c
 * Auteurs : Raphaël Courraze (Groupe 101) , Alexandre Bidaux (Groupe 107)
 * Création : 13/10/2021
 * Dernière mise à jour : 03/11/2021
 */

/* Fonction de tri par insertion par ordre decroissant
 * en cas d'un nombre égal de points, on trie par ordre lexicographique croissant
 * nbJoueuses [in] entier, nombre total de joueuses enregistrées
 * joueusesWTA [in-out] Joueuse*, liste des joueuses du tournoi à trier
 */
void tri_points(Joueuse* joueusesWTA, const int nbJoueuses) {
	int i, j, stockageIndex = 0;
	Joueuse joueuseAnalyse = joueusesWTA[0];
	//il faut que le premier élément du tableau a trier soit le'élement le plus petit élément
	for (i = 1; i < nbJoueuses; i++) {
		if (joueuseAnalyse.points < joueusesWTA[i].points) {
			joueuseAnalyse = joueusesWTA[i];
			stockageIndex = i;
		}
	}
	joueusesWTA[stockageIndex] = joueusesWTA[0];
	joueusesWTA[0] = joueuseAnalyse;

	//le tri par insertion commence
	for (i = 1; i < nbJoueuses; i++) {
		joueuseAnalyse = joueusesWTA[i];
		j = i;
		while (j > 1 && joueusesWTA[j - 1].points < joueuseAnalyse.points) {
			joueusesWTA[j] = joueusesWTA[j - 1];
			j--;
		}
		joueusesWTA[j] = joueuseAnalyse;
	}
}

/* Fonction de tri par insertion par ordre lexicographique croissant 
 * en cas d'un nombre égal de points, on trie par ordre lexicographique croissant
 * nbJoueuses [in] entier, nombre total de joueuses enregistrées
 * joueusesWTA [in-out] Joueuse*, liste des joueuses du tournoi à trier
 */
void tri_lexico_classement(Joueuse* joueusesWTA, const int nbJoueuses) {
	int i, j, stockageIndex;
	Joueuse joueuseAnalyse = joueusesWTA[0];
	//le tri par insertion commence
	for (i = 1; i < nbJoueuses; i++) {
		joueuseAnalyse = joueusesWTA[i];
		j = i;
		while (j > 1 && strcmp(joueusesWTA[j - 1].nom, joueuseAnalyse.nom) > 0 && 
			   joueuseAnalyse.points == joueusesWTA[j-1].points) {
			joueusesWTA[j] = joueusesWTA[j - 1];
			j--;
		}
		joueusesWTA[j] = joueuseAnalyse;
	}
}

/* Fonction qui affiche le classement trié par ordre décroissant des points les joueuses du tournoi WTA
 * en cas d'un nombre égal de points, on trie par ordre lexicographique croissant
 * tournoiWTA [in] TournoiWTA*, liste de tous les tournois et joueuses
 * nbJoueuses [in] entier, nombre total de joueuses enregistrées
 */
void afficher_classement(const TournoiWTA* tournoiWTA, const int nbJoueuses) {
	int i, tailleTab;
	Joueuse joueusesWTA[nbJoueusesTournoi * maxTournois];

	//on transfert les données des joueuses de tournoiWTA dans une liste que l'on pourra modifier (et donc trier)
	for (i = 0; i < nbJoueuses; i++) {
		joueusesWTA[i] = tournoiWTA->dataJoueuses[i];
	}

	tri_points(joueusesWTA, nbJoueuses);
	tri_lexico_classement(joueusesWTA, nbJoueuses);

	//affichage
	for (i = 0; i < nbJoueuses; i++) {
		if (joueusesWTA[i].points != 0) {
			printf("%s %d\n", joueusesWTA[i].nom, joueusesWTA[i].points);
		}
	}
}