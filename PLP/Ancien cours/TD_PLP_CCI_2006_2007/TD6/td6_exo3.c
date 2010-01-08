/* TD 9 de C */

/* exercice 3 : tableaux et pointeurs */

/* on commence par inclure les bibliothèque */
#include <stdio.h>
#include <stdlib.h>

void tableascii()
{
	int i;
	char *pt;
	pt = malloc(256*sizeof(char));

	//pt=&i;
	for (i=0;i<256;i++)
	{
		*(pt+i)=i;
		printf("\nNuméro : %i représente %c",i,*(pt+i));
	}
	free(pt);
}




int main()
{
	printf("\nAffichage d'un morceau de la table ASCII");
	tableascii();
	printf("\n");
}
