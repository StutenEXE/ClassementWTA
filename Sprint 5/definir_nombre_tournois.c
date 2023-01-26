#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
/* definir_nombre_tournois.c
 * Auteurs : Raphaël Courraze (Groupe 101) , Alexandre Bidaux (Groupe 107)
 * Création : 01/10/2021
 * Dernière mise à jour : 03/11/2021
 */

 /* Fonction qui defini combien de tournois seront enregistrés
  * nbTournois [in-out] entier*, nombre total de tournois à enregistrer
  * Préconditions : 0 < valeur rentrée < 11
  */
void definir_nombre_tournois(int* nbTournois) {
	unsigned int valRentree;
	scanf("%u", &valRentree);
	assert(valRentree > 0 && valRentree < 11);
	//on modifie la valeur de nbTournois par la valeur rentrée par l'utilisateur 
	*nbTournois = valRentree;
}