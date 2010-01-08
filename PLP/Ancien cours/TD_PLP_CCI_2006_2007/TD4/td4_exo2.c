/* TD 5 de C */

/* exercice 2 : définir un tableau de 100, avec valeur de 0 à 99 et une boucle while */

/* on commence par inclure les bibliothèque */
#include <stdio.h>


int main()
{
	int tableau[100];
	int i;

// Remplissage du tableau

	i =0;

	while (i<100)
	{
		tableau[i]=i;
		i++;
	}

// calcul de la somme des entiers du tableau

	int somme = 0;
	i =0;

	while (i<100)
	{
		somme=somme+tableau[i];
		i++;
	}
	printf("\nla somme est %i\n", somme);

// Affichage du tableau

	i =0;

	printf("Affichage du tableau :\n");
	while (i<100)
	{
		tableau[i]=i;
		printf("%i ",tableau[i]);
		i++;
	}
	printf("\n");
}
