/* TD 13 de C */

/* exercice 1 : gerer un fichier */

/* Inclusion de bibliothèques */
#include <stdio.h>
#include <stdlib.h>

int main(){
	int buffer2 ;
	/* fonction qui ouvre un fichier */
	FILE* buffer = fopen("/homes/fromenti/CCI/td_algo/td13/exemple.txt", "r");
	/* ferme le fichier ouvert */
	buffer2 = fclose(buffer);
	/* retour d'une valeur test*/
	printf("\ntest, valeur du int retour : %i\n",buffer2);
}
