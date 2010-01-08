/* TD 6 de C */

/* exercice 11 : fonction pgcd ppcm, à n'utiliser qu'avec des nbs entiers positifs */

/* on commence par inclure les bibliothèque */
#include <stdio.h>
#include <stdlib.h>

/* fonction calculant le pgcd */
int pgcd(int x, int y)
{
// déclaration des variables
	int r,pgcd;
	
//calcul

	while (r!=0)
	{
		r= x % y;
		x=y;
		y=r;
	}
	pgcd=x;

// Affichage résultats
	return pgcd;
}


/* fonction calculant le ppcm */
int ppcm(int x, int y)
{
// déclaration des variables
	int ppcm;
	
//calcul
		
	ppcm = ((x * y)/ (pgcd(x,y)));

// Affichage résultats
	return ppcm;
}


int main()
{
// déclaration des variables
	int x,y;

//demande d'entrée utilisateur
	printf("Entrer le premier nombre : ");
	scanf("%i",&x);

	printf("Entrer le deuxième nombre : ");
	scanf("%i",&y);
	
	printf("Le PGCD de (%i,%i) est : %i\n",x,y,pgcd(x,y));
	printf("Le PPCM de (%i,%i) est : %i\n",x,y,ppcm(x,y));
}
