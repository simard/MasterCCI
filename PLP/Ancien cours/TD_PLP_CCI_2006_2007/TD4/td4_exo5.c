/* TD 5 de C */

/* exercice 5 : factorielle */

/* on commence par inclure les bibliothèque */
#include <stdio.h>
#include <stdlib.h>

int main()
{

	int resultat=1;
	int chiffre;

	printf("Entrer votre nombre pour calculer son factorielle : ");
	scanf("%i",&chiffre);

	if(chiffre == 0)
	{
		printf("Resultat : 1\n");
		exit(0);
	}

	if(chiffre == 1)
	{
		printf("Resultat : 1\n");
		exit(0);
	}

	do
	{
		resultat=resultat*chiffre;
		chiffre=chiffre-1;
	}	while (chiffre!=1);
	printf("Resultat : %i\n", resultat);

}
