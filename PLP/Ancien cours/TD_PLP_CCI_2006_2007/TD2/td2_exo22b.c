/* TD 2 de C */

/* question 2.2 */

/* on commence par inclure les fonctions d'affichages de la bibliothèque standard */
#include <stdio.h>

/* fonction principale */
int main(){
double f;
f = (2.0/3.0);
	printf("precision de 3 chiffres : %.3f\n",f);
	printf("precision de 6 chiffres : %.6f\n",f);
	printf("precision de 12 chiffres : %.12f\n",f);
}