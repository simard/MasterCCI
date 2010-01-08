/* TD 5 de C */

/* exercice 6 : transfo de tableau */

/* on commence par inclure les bibliothèque */
#include <stdio.h>
#include <stdlib.h>

#define DIMX 5
#define DIMY 5

int main()
{
	int tablo[DIMX][DIMY];
	int i,j,k,nd;
	k=0;

// Remplissage du tableau

	for (i=0;i<DIMX;i++)
	{
		for (j=0;j<DIMY;j++)
		{
			tablo[i][j]=k;
			k++;
		}
	}

// Affichage du tableau

	printf("affichage du tableau\n");
	for (i=0;i<DIMX;i++)
	{
		for (j=0;j<DIMY;j++)
		{
			printf("%i\t", tablo[i][j]);
		}
		printf("\n");
	}
	printf("\n");

// Dimension du nouveau tableau

	nd=DIMX*DIMY;	//calcul nouvel dimension
	int newtablo[nd];	// déclaration du nouveau tableau
	
// transfert de cases dans le nouveau tableau !

// Remplissage du tableau

	i=0;j=0;
	while (i<6)
	{
		while (j<6)
		{
			newtablo[(DIMY * i + j)]=tablo[i][j];
			j++;
		}
		i++;
		j=0;
	}


// Affichage du tableau

	printf("affichage du nouveau tableau\n");
	i=0;
	for (i=0;i<DIMX*DIMY;i++)
		printf("%i ", newtablo[i]);

	printf("\n");
}
