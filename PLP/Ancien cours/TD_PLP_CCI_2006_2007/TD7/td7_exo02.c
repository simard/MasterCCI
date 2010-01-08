/* TD 13 de C */

/* exercice 2 : gerer un fichier */

/* Inclusion de bibliothèques */
#include <stdio.h>
#include <stdlib.h>

int main(){
	int test_fclose ;
	int taille = 200;
	char *str ;
	str = (char*)malloc(taille);

	/* fonction qui ouvre un fichier */
	FILE* buffer = fopen("/homes/fromenti/CCI/td_algo/td13/exemple.txt", "r");

	/* utilisation de la fonction fgets pour lire un fichier par ligne */
/*	fgets(str, taille, buffer);	//pour afficher la première ligne
	printf("\n%s\n", str);
	fgets(str, taille, buffer);	//pour afficher la deuxième ligne
	printf("\n%s\n", str);
*/
	/* utilisation de la fonction fgetc pour lire un fichier par caractère */
	char valeur = fgetc(buffer);
	printf("\n%c\n", valeur);

	/* ferme le fichier ouvert */
	test_fclose = fclose(buffer);
	/* retour d'une valeur test*/
	printf("\ntest, valeur du int retour : %i\n",test_fclose);
}
