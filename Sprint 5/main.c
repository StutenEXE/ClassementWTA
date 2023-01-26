#pragma warning(disable:4996)
#pragma warning(disable:6031)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "types.h"
#include "definir_nombre_tournois.h"
#include "enregistrement_tournoi.h"
#include "affichage_matchs_tournoi.h"
#include "afficher_matchs_joueuse.h"
#include "affichage_joueuses_tournoi.h"
#include "afficher_classement.h"

/* main.c
 * Auteurs : Raphaël Courraze (Groupe 101) , Alexandre Bidaux (Groupe 107)
 * Création : 01/10/2021
 * Dernière mise à jour : 03/11/2021
 */

int main() {
	int nbTournois = 0,
		nbTournoisEnreg = 0,
		nbJoueuses = 0,
		date = 0;
	TournoiWTA tournoiWTA;

	while (1) { // ou do {} while(1); 

		char mot[lgMot + 1] = "";	
		scanf("%30s", mot);

		//si la commande est "definir_nombre_tournois"
		if (strcmp(mot, "definir_nombre_tournois") == 0) {
			definir_nombre_tournois(&nbTournois);
		}

		//si la commande est "enregistrement_tournoi"
		if (strcmp(mot, "enregistrement_tournoi") == 0) {
			enregistrement_tournoi(&tournoiWTA, nbTournoisEnreg, &nbJoueuses, nbTournois);
			nbTournoisEnreg++;
		}

		//si la commande est "affichage_matchs_tournoi"
		if (strcmp(mot, "affichage_matchs_tournoi") == 0) {
			affichage_matchs_tournoi(&tournoiWTA, &nbTournoisEnreg);
		}

		//si la commande est "affichage_matchs_joueuse"
		if (strcmp(mot, "afficher_matchs_joueuse") == 0) {
			afficher_matchs_joueuse(&tournoiWTA, nbJoueuses, &nbTournois);
		}

		//si la commande est "affichage_matchs_joueuse"
		if (strcmp(mot, "affichage_joueuses_tournoi") == 0) {
			affichage_joueuses_tournoi(&tournoiWTA, &nbTournoisEnreg);
		}

		//si la commande est "afficher_classement"
		if (strcmp(mot, "afficher_classement") == 0) {
			afficher_classement(&tournoiWTA, nbJoueuses);
		}

		// si la commande est "exit" ou au qu'il n'y a plus rien à lire.
		if (strcmp(mot, "exit") == 0 || strcmp(mot, "") == 0) {
			exit(0); // sortie du programme principal
		}
	}
	system("pause"); return 0;
}