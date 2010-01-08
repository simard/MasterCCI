/* TD 5 de C */

/* exercice 3 : les tableaux */

/* on commence par inclure les bibliothèque */
#include <stdio.h>


int main()
{
	int tablo[5][5];
	int i,j,k;
	k=0;

// Remplissage du tableau

	for (i=0;i<5;i++)
	{
		for (j=0;j<5;j++)
		{
			tablo[i][j]=k;
			k++;
		}
	}

// Affichage du tableau

	printf("affichage du tableau\n");
	for (i=0;i<5;i++)
	{
		for (j=0;j<5;j++)
		{
			printf("%i\t", tablo[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
