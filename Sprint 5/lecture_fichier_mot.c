#include <stdio.h>
#include <stdlib.h>
#include "types.h"
/* enregistrement_tournoi.c
 * Auteurs : Rapha�l Courraze (Groupe 101) , Alexandre Bidaux (Groupe 107)
 * Cr�ation : 01/10/2021
 * Derni�re mise � jour : 07/10/2021
 * Code obsol�te car la m�thode de lecture dans le fichier a chang�
 */

char lecture_fichier_mot(FILE* fichierIn) {
	int i = 0;
	char mot[lgMot + 1];
	while (1) {  //r�cup�ration du mot �crit caract�re par caract�re
		mot[i] = (char)fgetc(fichierIn);
		if (mot[i] == ' ' || mot[i] == '\n' || mot[i] == EOF) { //si les caract�res ' ', '\n' ou EOF(= �) sont inscrit, on veut que la cha�ne se termine donc on remplace le 
			mot[i] = '\0';									 //caract�re non voulu par un '\0' pour finir la cha�ne
			break;
		}
		i++;
	}
	return mot;
}