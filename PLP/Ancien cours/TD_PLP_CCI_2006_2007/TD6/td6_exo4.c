/* TD 9 de C */

/* exercice 4 : tableaux et pointeurs */

/* on commence par inclure les bibliothèque */
#include <stdio.h>
#include <stdlib.h>

void tableascii()
{
	int i;
	char *pt;
	pt = malloc(256*sizeof(char));

	//pt=&i;
	for (i=97;i<123;i++)
	{
		*(pt+i)=i;
		/* Affichage des caractères en minuscules */
		printf("\nNuméro : %i représente %c",i,*(pt+i));
	}

	printf("\n");
	printf("\nAffichage des majuscules\n");

	/* Affichage des résultats : caractères majuscules */
	for (i=97;i<123;i++)
	{
		*(pt+i)=i-32;
		/* Affichage des caractères en minuscules */
		printf("\t%c",*(pt+i));
	}
	free(pt);
}




int main()
{
	printf("\nAffichage de l'alphabet");
	tableascii();
	printf("\n");
}
