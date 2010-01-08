/* TD 6 de C */

/* exercice 3 : fonction factorielle */

/* on commence par inclure les bibliothèque */
#include <stdio.h>
#include <stdlib.h>

int factoriel(int x)
{
	int resultat=1;

	if(x == 0){
		printf("Resultat : 1\n");
		exit(0);
		}

	else if(x == 1){
		printf("Resultat : 1\n");
		exit(0);
		}

	else do
	{
		resultat=resultat*x;
		x=x-1;
	}	while (x!=1);
	printf("Resultat : %i\n", resultat);
}


int main()
{
	int chiffre;

	printf("Entrer votre nombre pour calculer son factorielle : ");
	scanf("%i",&chiffre);

	factoriel(chiffre);
	printf("\n");
	exit(0);
}
