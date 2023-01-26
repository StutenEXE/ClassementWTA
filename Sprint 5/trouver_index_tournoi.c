#pragma warning(disable:4996)
#pragma warning(disable:6031)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"
/* affichage_matchs_tournoi.c
 * Auteurs : Rapha�l Courraze (Groupe 101) , Alexandre Bidaux (Groupe 107)
 * Cr�ation : 08/10/2021
 * Derni�re mise � jour : 03/11/2021
 */

/* Fonction qui v�rifie si le tournoi existe et qui renvoie l'index du tounoi s'il existe
 * nbTournoisEnregistres [in] entier*, nombre total des tournois enregistr�s
 * nomTournoi [in] char*, nom du tournoi
 * dateTournoi [in] entier*, ann�e du tournoi
 * tournoiWTA [in] TournoiWTA*, liste de tous les tournois et joueuses
 * indexTournoi [out] entier*, index du tournoi trouv�
 * [retour] Bool, TRUE si le tournoi existe et FALSE si le tournoi n'existe pas
 */
Bool trouver_index_tournoi(const TournoiWTA* tournoiWTA, const int* nbTournoisEnregistres, const char* nomTournoi, 
						   const unsigned int* dateTournoi, int* indexTournoi) {
	int i;
	for (i = 0; i <= *nbTournoisEnregistres; i++) { //on parcourt les tournois de tournoiWTA
		if ((tournoiWTA->dataTournois[i].date == *dateTournoi)) {
			if (strcmp(nomTournoi, ((*tournoiWTA).dataTournois[i].nom)) == 0) {
				*indexTournoi = i;
				return TRUE;
			}
		}
	}
	printf("tournoi inconnu\n");
	return FALSE;
}
