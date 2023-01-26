#include <stdio.h>
#include <stdlib.h>
#include "types.h"
/* enregistrement_tournoi.c
 * Auteurs : Raphaël Courraze (Groupe 101) , Alexandre Bidaux (Groupe 107)
 * Création : 01/10/2021
 * Dernière mise à jour : 07/10/2021
 * Code obsolète car la méthode de lecture dans le fichier a changé
 */

char lecture_fichier_mot(FILE* fichierIn) {
	int i = 0;
	char mot[lgMot + 1];
	while (1) {  //récupération du mot écrit caractère par caractère
		mot[i] = (char)fgetc(fichierIn);
		if (mot[i] == ' ' || mot[i] == '\n' || mot[i] == EOF) { //si les caractères ' ', '\n' ou EOF(= ÿ) sont inscrit, on veut que la chaîne se termine donc on remplace le 
			mot[i] = '\0';									 //caractère non voulu par un '\0' pour finir la chaîne
			break;
		}
		i++;
	}
	return mot;
}