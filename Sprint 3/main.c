#pragma warning(disable:4996)
#pragma warning(disable:6031)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"
#include "definir_nombre_tournois.h"
#include "enregistrement_tournoi.h"
#include "affichage_matchs_tournoi.h"
#include "afficher_matchs_joueuse.h"
#include "affichage_joueuses_tournoi.h"

//1 = vrai	0 = faux

int main() {
	int nbTournois = 0,
		indexTournoi = 0,
		nbJoueuses = 0,
		date = 0;
	TournoiWTA tournoiWTA;	// Structure contenant la liste des tournois et leurs résultats et la liste des joueuses WTA

	while (1) { // ou do {} while(1); 

		char mot[lgMot + 1] = "";	//création d'une variable mot pouvant contenir un mot de 30 caractères et reinitialisation "" à chaque réitération de la boucle
		scanf("%s", mot); //lecture du mot dans le fichier
		//printf("%s\n", mot);

		//si la commande est "definir_nombre_tournois"
		if (strcmp(mot, "definir_nombre_tournois") == 0) {
			definir_nombre_tournois(&nbTournois);
		}

		//si la commande est "enregistrement_tournoi"
		if (strcmp(mot, "enregistrement_tournoi") == 0) {
			enregistrement_tournoi(&tournoiWTA, indexTournoi, &nbJoueuses, nbTournois);
			indexTournoi++;
		}

		//si la commande est "affichage_matchs_tournoi"
		if (strcmp(mot, "affichage_matchs_tournoi") == 0) {
			affichage_matchs_tournoi(&tournoiWTA, &nbTournois);
		}

		//si la commande est "affichage_matchs_joueuse"
		if (strcmp(mot, "afficher_matchs_joueuse") == 0) {
			afficher_matchs_joueuse(&tournoiWTA, &nbJoueuses, &nbTournois);
		}

		//si la commande est "affichage_matchs_joueuse"
		if (strcmp(mot, "affichage_joueuses_tournoi") == 0) {
			affichage_joueuses_tournoi(&tournoiWTA, &nbJoueuses, &nbTournois);
		}

		// si la commande est "exit" .
		if (strcmp(mot, "exit") == 0 || strcmp(mot, "") == 0) {
			exit(0); // sortie du programme principal
		}
	}
	system("pause"); return 0;
}