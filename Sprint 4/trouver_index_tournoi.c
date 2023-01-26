#pragma warning(disable:4996)
#pragma warning(disable:6031)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"

int trouver_index_tournoi(TournoiWTA* tournoiWTA, int* nbTournoisEnregistres, char* nomTournoi, unsigned int* dateTournoi, int* indexTournoi) {
	int i = 0;
	for (i; i < *nbTournoisEnregistres; i++) { //on parcourt les tournois de tournoiWTA
		if ((tournoiWTA->dataTournois[i].date == *dateTournoi)) {
			if (strcmp(nomTournoi, ((*tournoiWTA).dataTournois[i].nom)) == 0) {
				*indexTournoi = i;
				return 1;
			}
		}
	}
	printf("tournoi inconnu\n");
	return 0;
}
