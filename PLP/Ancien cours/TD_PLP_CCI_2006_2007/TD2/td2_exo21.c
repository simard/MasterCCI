/* TD 2 de C */

/* sizeof(type) */

/* on commence par inclure les fonctions d'affichages de la bibliothèque standard */
#include <stdio.h>



/* fonction principale */
main(){
	int x;
	int y;
	printf("Choisissez parmis les choix suivants,\n");
	printf("le type a calculer\n");
	printf("1 : int\n");
	printf("2 : unsigned int\n");
	printf("3 : char\n");
	printf("4 : short int\n");
	printf("5 : long int\n");

	scanf("%d",x);
	printf("Votre type est : %d\n",x);

	/*y = sizeof(x);*/
	printf("La taille en octet de votre type d'entier est %d\n",sizeof(int));
}