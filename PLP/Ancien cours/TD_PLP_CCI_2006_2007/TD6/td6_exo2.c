/* TD 9 de C */

/* exercice 2 : tableaux et pointeurs */

/* on commence par inclure les bibliothèque */
#include <stdio.h>
#include <stdlib.h>

void remplirTableau(int n)
{
	int i;
	int *pt;
	pt = malloc(n*sizeof(int));

	if (pt==NULL)
		printf("\nProblème d'allocation !!!\n");
	else
		/* remplissage du tableau */
		*pt=i;
		
		for (i=0;i<n;i++)
		{
			*(pt+i)=i;
		}

	/* affichage du tableau */
		for (i=0;i<n;i++)
		{
			printf("%i\t", *(pt+i));
		}
	free(pt);
}

/* question suivante : affichage de caractères, sachant que 105 = i en char */

void remplirTableauchar(int n)
{
	int i;
	char pair='i';
	char impair='p';
	char *pt;
	pt = malloc(n*sizeof(char));

	if (pt==NULL)
		printf("\nProblème d'allocation !!!\n");
	else
		/* remplissage du tableau */
		*pt=i;
		
		for (i=0;i<n;i=i+2)
		{
			*(pt+i)=pair;
		}

		for (i=1;i<n;i=i+2)
		{
			*(pt+i)=impair;
		}

	/* affichage du tableau */
		for (i=0;i<n;i++)
		{
			printf("%c\t", *(pt+i));
		}
	free(pt);
}

/* Fonction principale */

int main()
{
	int n;
	printf("\nVeuillez entrer un nombre entier positif :");
	scanf("%i",&n);
	remplirTableau(n);
	printf("\nVeuillez entrer un autre nombre entier positif :");
	scanf("%i",&n);
	remplirTableauchar(n);
	printf("\n");
}
