/* TD 6 de C */

/* exercice 13 : transpo de tableaux */

/* on commence par inclure les bibliothèque */
#include <stdio.h>
#include <stdlib.h>

#define dimX 10
#define dimY 7

int tab1[dimX][dimY];
int tab2[dimY][dimX];

/* fonction avec les pointeurs */
void echange ()
{
	int i,j;
	for (i=0;i<dimX;i++)
	{
		for (j=0;j<dimY;j++)
		{
			tab2[j][i]=tab1[i][j];
		}
	}
}

int main(){

	int i,j,k=1;

// Remplissage du tableau avec des nombres impairs

	for (i=0;i<dimX;i++)
	{
		for (j=0;j<dimY;j++)
		{
			tab1[i][j]=k;
			k=k+2;
		}
	}

// Affichage du tableau

	printf("affichage du tableau\n");
	for (i=0;i<dimX;i++)
	{
		for (j=0;j<dimY;j++)
		{
			printf("%i\t", tab1[i][j]);
		}
		printf("\n");
	}
	printf("\n");

echange();

// Affichage du ouveau tableau

	printf("affichage du nouveau tableau\n");
	for (i=0;i<dimY;i++)
	{
		for (j=0;j<dimX;j++)
		{
			printf("%i\t", tab2[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
