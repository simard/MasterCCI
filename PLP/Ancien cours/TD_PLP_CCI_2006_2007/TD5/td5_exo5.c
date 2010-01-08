/* TD 6 de C */

/* exercice 5 : fonction somme des n premiers entiers */

/* on commence par inclure les bibliothèque */
#include <stdio.h>
#include <stdlib.h>

/* fonction recursive */

int somme(int x)
{
	if (x<0) return 0;
	return (x+somme(x-1));
}

/* fonction itérative */

// int somme(int x)
// {
// 	int nombre=0;
// 	int copiedux=x;
// 
// 	while (x!=0)
// 	{
// 		nombre=nombre+x;
// 		x=x-1;
// 	}
// 	printf("\nLa somme des %i premier entiers est : %i\n",copiedux,nombre);
// }

int main()
{
	int n=0;
	printf("\nVeuillez entrer un nombre entier positif : ");
	scanf("%i",&n);

	int copiedux=n;

	printf("\nLa somme des %i premier entiers est : %i\n",copiedux,somme(n));
}
