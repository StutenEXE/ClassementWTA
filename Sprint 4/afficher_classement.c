#pragma warning(disable:4996)
#pragma warning(disable:6031)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"

//on applique la méthode de tri par insertion
void tri_points(Joueuse* joueusesWTA, int* nbJoueuses) {
	int i, j, stockageIndex = 0;
	Joueuse joueuseAnalyse = joueusesWTA[0];
	//il faut que le premier élément du tableau a trier soit le'élement le plus petit élément
	for (i = 1; i < *nbJoueuses; i++) {
		if (joueuseAnalyse.points < joueusesWTA[i].points) {
			joueuseAnalyse = joueusesWTA[i];
			stockageIndex = i;
		}
	}
	joueusesWTA[stockageIndex] = joueusesWTA[0];
	joueusesWTA[0] = joueuseAnalyse;

	//le tri par insertion commence
	for (i = 1; i < *nbJoueuses; i++) {
		joueuseAnalyse = joueusesWTA[i];
		j = i;
		while (j > 1 && joueusesWTA[j - 1].points < joueuseAnalyse.points) {
			joueusesWTA[j] = joueusesWTA[j - 1];
			j--;
		}
		joueusesWTA[j] = joueuseAnalyse;
	}
}

//on applique la méthode de tri par insertion
void tri_lexico_classement(Joueuse* joueusesWTA, int* nbJoueuses) {
	int i, j, stockageIndex;
	Joueuse joueuseAnalyse = joueusesWTA[0];
	//le tri par insertion commence
	for (i = 1; i < *nbJoueuses; i++) {
		joueuseAnalyse = joueusesWTA[i];
		j = i;
		while (j > 1 && strcmp(joueusesWTA[j - 1].nom, joueuseAnalyse.nom) > 0 && joueuseAnalyse.points == joueusesWTA[j-1].points) {
			joueusesWTA[j] = joueusesWTA[j - 1];
			j--;
		}
		joueusesWTA[j] = joueuseAnalyse;
	}
}

void afficher_classement(TournoiWTA* tournoiWTA, int* nbJoueuses) {
	int i, tailleTab;
	Joueuse joueusesWTA[nbJoueusesTournoi * 4];

	//on transfert les données des joueuses de tournoiWTA dans une liste que l'on pourra modifier (et donc trier)
	for (i = 0; i < *nbJoueuses; i++) {
		joueusesWTA[i] = tournoiWTA->dataJoueuses[i];
	}

	tri_points(joueusesWTA, nbJoueuses);

	tri_lexico_classement(joueusesWTA, nbJoueuses);

	for (i = 0; i < *nbJoueuses; i++) {
		printf("%s %d\n", joueusesWTA[i].nom, joueusesWTA[i].points);
	}
}