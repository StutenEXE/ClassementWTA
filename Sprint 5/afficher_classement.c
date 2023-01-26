#pragma warning(disable:4996)
#pragma warning(disable:6031)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"
/* afficher_classement.c
 * Auteurs : Rapha�l Courraze (Groupe 101) , Alexandre Bidaux (Groupe 107)
 * Cr�ation : 13/10/2021
 * Derni�re mise � jour : 03/11/2021
 */

/* Fonction de tri par insertion par ordre decroissant
 * en cas d'un nombre �gal de points, on trie par ordre lexicographique croissant
 * nbJoueuses [in] entier, nombre total de joueuses enregistr�es
 * joueusesWTA [in-out] Joueuse*, liste des joueuses du tournoi � trier
 */
void tri_points(Joueuse* joueusesWTA, const int nbJoueuses) {
	int i, j, stockageIndex = 0;
	Joueuse joueuseAnalyse = joueusesWTA[0];
	//il faut que le premier �l�ment du tableau a trier soit le'�lement le plus petit �l�ment
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
 * en cas d'un nombre �gal de points, on trie par ordre lexicographique croissant
 * nbJoueuses [in] entier, nombre total de joueuses enregistr�es
 * joueusesWTA [in-out] Joueuse*, liste des joueuses du tournoi � trier
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

/* Fonction qui affiche le classement tri� par ordre d�croissant des points les joueuses du tournoi WTA
 * en cas d'un nombre �gal de points, on trie par ordre lexicographique croissant
 * tournoiWTA [in] TournoiWTA*, liste de tous les tournois et joueuses
 * nbJoueuses [in] entier, nombre total de joueuses enregistr�es
 */
void afficher_classement(const TournoiWTA* tournoiWTA, const int nbJoueuses) {
	int i, tailleTab;
	Joueuse joueusesWTA[nbJoueusesTournoi * maxTournois];

	//on transfert les donn�es des joueuses de tournoiWTA dans une liste que l'on pourra modifier (et donc trier)
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