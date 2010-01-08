/* TD 5 de C */

/* exercice 7 : PGCD */

/* on commence par inclure les bibliothèque */
#include <stdio.h>
#include <stdlib.h>

int main()
{
	// déclaration des variables
	int x,y,x1,y1,r,pgcd;

	//demande d'entrée utilisateur
	printf("Entrer le premier nombre : ");
	scanf("%i",&x);

	printf("Entrer le deuxième nombre : ");
	scanf("%i",&y);
	
	//calcul
	x1=x;
	y1=y;

	while (r!=0)
	{
		r= x1 % y1;
		x1=y1;
		y1=r;
	}
	pgcd=x1;

// Affichage résultats

	printf("Le PGCD de (%i,%i) est : %i\n",x,y,pgcd);
}
