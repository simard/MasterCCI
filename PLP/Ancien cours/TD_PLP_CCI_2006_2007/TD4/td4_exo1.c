/* TD 5 de C */

/* exercice 1 : définir un tableau de 100, avec valeur de 0 à 99 et une boucle for */

/* on commence par inclure les bibliothèque */
#include <stdio.h>


int main()
{
	int tableau[100];
	int i;

// Remplissage du tableau

	for (i = 0; i<100; i++)
	{
		tableau[i]=i;
	}

// calcul de la somme des entiers du tableau

	int somme = 0;

	for (i = 0; i<100; i++)
	{
		somme=somme+tableau[i];

	}
	printf("\nla somme est %i\n", somme);

// Affichage du tableau

	printf("Affichage du tableau :\n");
	for (i = 0; i<100; i++)
	{
		tableau[i]=i;
		printf("%i ",tableau[i]);
	}
	printf("\n");
}
