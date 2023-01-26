#pragma warning(disable:4996)
#pragma warning(disable:6031)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"

void suppression_points(TournoiWTA* tournoiWTA, int idxTournoi) {
	int cpt, idxPerdante;  // on crée une variable pour pouvoir compter les différentes phases du tournoi
	for (cpt = 0; cpt < nbMatchTournoi; cpt++) {
		idxPerdante = tournoiWTA->dataTournois[idxTournoi].dataMatch[cpt].idxPerdante;
		if (0 <= cpt && cpt < 64) { tournoiWTA->dataJoueuses[idxPerdante].points -= 10; } else
		if (64 <= cpt && cpt < 96) { tournoiWTA->dataJoueuses[idxPerdante].points -= 45; } else
		if (96 <= cpt && cpt < 112) { tournoiWTA->dataJoueuses[idxPerdante].points -= 90; } else
		if (112 <= cpt && cpt < 120) { tournoiWTA->dataJoueuses[idxPerdante].points -= 180; } else
		if (120 <= cpt && cpt < 124) { tournoiWTA->dataJoueuses[idxPerdante].points -= 360; } else
		if (124 <= cpt && cpt < 126) { tournoiWTA->dataJoueuses[idxPerdante].points -= 720; } else
		if (126 <= cpt && cpt < 127) {
			int idxGagnante = tournoiWTA->dataTournois[idxTournoi].dataMatch[cpt].idxGagnante;
			tournoiWTA->dataJoueuses[idxPerdante].points -= 1200;
			tournoiWTA->dataJoueuses[idxGagnante].points -= 2000;
		}
	}
}

void addition_points(TournoiWTA* tournoiWTA, int idxTournoi) {
	int cpt, idxPerdante;  // on crée une variable pour pouvoir compter les différentes phases du tournoi
	for (cpt = 0; cpt < nbMatchTournoi; cpt++) {
		idxPerdante = tournoiWTA->dataTournois[idxTournoi].dataMatch[cpt].idxPerdante;
		if (0 <= cpt && cpt < 64) { tournoiWTA->dataJoueuses[idxPerdante].points += 10; } else
		if (64 <= cpt && cpt < 96) { tournoiWTA->dataJoueuses[idxPerdante].points += 45;} else
		if (96 <= cpt && cpt < 112) { tournoiWTA->dataJoueuses[idxPerdante].points += 90;} else
		if (112 <= cpt && cpt < 120) { tournoiWTA->dataJoueuses[idxPerdante].points += 180;} else
		if (120 <= cpt && cpt < 124) { tournoiWTA->dataJoueuses[idxPerdante].points += 360;} else
		if (124 <= cpt && cpt < 126) { tournoiWTA->dataJoueuses[idxPerdante].points += 720;} else
		//cas particulier de la finale où la gagnante prend des points aussi
		if (126 <= cpt && cpt < 127) {
			int idxGagnante = tournoiWTA->dataTournois[idxTournoi].dataMatch[cpt].idxGagnante;
			tournoiWTA->dataJoueuses[idxPerdante].points += 1200;
			tournoiWTA->dataJoueuses[idxGagnante].points += 2000;
		}
	}
}

void attribution_points(TournoiWTA* tournoiWTA, char* nomTournoi, int date, int nbTournois) {
	int i, idxTournoi;
	//on vérifie si le tournoi a déjà été joué une année précédente, auquel cas il faut supprimer les points
	// de l'année dernière pour mettre ceux de cette année
	for (i = 0; i < nbTournois; i++) {
		//on vérifie s'il y a eu le même tournoi l'annèe dernière et on retire les points si oui
		if (strcmp(tournoiWTA->dataTournois[i].nom, nomTournoi) == 0) {
			if (tournoiWTA->dataTournois[i].date == (date - 1)) {
				suppression_points(tournoiWTA, i);
			}
			if (tournoiWTA->dataTournois[i].date == date) {
				idxTournoi = i;
				addition_points(tournoiWTA, idxTournoi);
				return;
			}
		}
	}
}

//Fonction qui cherche une joueuse, la crée si elle n'existe pas et retoure son index dans le tableau des joueuses
int chercher_Joueuse_ouEnregistrer(TournoiWTA* tournoiWTA, char* mot, int* nbJoueuse) {
	int i = 0;
	while (i < *nbJoueuse) {	// cherche le nom de la joueuse dans la liste des joueuses déjà enregistrées
		if (strcmp(tournoiWTA->dataJoueuses[i].nom, mot) == 0) {
			break;
		}
		i++;
	}

	if (i == *nbJoueuse) {	// la joueuse n'a pas encore été enregistrée
		strcpy(tournoiWTA->dataJoueuses[i].nom, mot);
		tournoiWTA->dataJoueuses[i].points = 0;
		*nbJoueuse = *nbJoueuse + 1;
	}

	return i; //retourne l'index de la joueuse
}

void enregistrement_tournoi(TournoiWTA* tournoiWTA, const int indexTournoi, int* nbJoueuse, int nbTournois) {
	int i,
		date,				// Année du tournoi 
		indexMatch = 0;		// index d'un match d'un tournoi

	unsigned int indexGagnante = 0,
				 indexPerdante = 0;

	char mot[lgMot + 1] = "", nomTournoi[lgMot + 1] = "";

	//on lit l'année et la date du tournoi et on les rentre dans tournoiWTA
	scanf("%s", nomTournoi);	
	scanf("%u", &date);	
	tournoiWTA->dataTournois[indexTournoi].date = date;
	strcpy(tournoiWTA->dataTournois[indexTournoi].nom, nomTournoi);

	//on commence la lecture des joueuses pour les stocker dans dataJoueuses et pour connaitre leur index et ensuite le rentrer dans match 
	while (indexMatch < nbMatchTournoi) {

		char mot[lgMot + 1] = "";

		scanf("%s", mot);	// nom de la première joueuse du match = gagnante
		if (strcmp(mot, "") != 0) { //si le mot n'est pas une cha�ne de caract�re vide
			indexGagnante = chercher_Joueuse_ouEnregistrer(tournoiWTA, mot, nbJoueuse);
		}

		scanf("%s", mot);	// nom de la deuxième joueuse du match = perdante
		if (strcmp(mot, "") != 0) {
			indexPerdante = chercher_Joueuse_ouEnregistrer(tournoiWTA, mot, nbJoueuse);
		}

		tournoiWTA->dataTournois[indexTournoi].dataMatch[indexMatch].idxGagnante = indexGagnante;
		tournoiWTA->dataTournois[indexTournoi].dataMatch[indexMatch].idxPerdante = indexPerdante;

		indexMatch++;//on passe au match suivant
	}
	attribution_points(tournoiWTA, nomTournoi, date, nbTournois);
}