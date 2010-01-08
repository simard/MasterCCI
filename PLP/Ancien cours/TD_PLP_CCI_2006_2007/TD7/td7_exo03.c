/* TD 13 de C */

/* exercice 3 : gerer un fichier */

/* Inclusion de bibliothèques */
#include <stdio.h>
#include <stdlib.h>

int main(){
	int test_fclose ;
	int taille = 200;
	char *str ;
	str = (char*)malloc(taille);

	/* fonction qui ouvre un fichier */
	FILE* monfichier = fopen("/homes/fromenti/CCI/td_algo/td13/exemple.txt", "r+");

	/* utilisation de la fonction fgets pour lire un fichier par ligne */
	printf("\n lecture du fichier original\n");
	fgets(str, taille, monfichier);	//pour afficher la première ligne
	printf("\n%s\n", str);
	fgets(str, taille, monfichier);	//pour afficher la deuxième ligne
	printf("\n%s\n", str);

	/* utilisation de la fonction fgetc pour lire un fichier par caractère */
/*	char valeur = fgetc(monfichier);
	printf("\n%c\n", valeur);
*/
	/* Utilisation de la fonction fputs : écriture d'une chaine de caractère dans un fichier */
/*	fputs("salut",monfichier);
*/

	/* Utilisation de la fonction fputc : écriture d'un caractère dans un fichier */
	fputc('Z',monfichier);

	/* ferme le fichier ouvert */
	test_fclose = fclose(monfichier);
	/* fonction qui ouvre un fichier */
	FILE* monfichier2 = fopen("/homes/fromenti/CCI/td_algo/td13/exemple.txt", "r");

	/* utilisation de la fonction fgets pour lire un fichier par ligne */
	printf("\n lecture du fichier modifié\n");
	fgets(str, taille, monfichier2);	//pour afficher la première ligne modifié
	printf("\n%s\n", str);

	/* ferme le fichier ouvert */
	test_fclose = fclose(monfichier2);
	/* retour d'une valeur test*/
	printf("\ntest, valeur du int retour : %i\n",test_fclose);

	free(str); // désallocation du pointeur *str
}


