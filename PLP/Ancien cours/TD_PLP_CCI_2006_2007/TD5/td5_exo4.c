/* TD 6 de C */

/* exercice 4 : fonction puissance */

/* on commence par inclure les bibliothèque */
#include <stdio.h>
#include <stdlib.h>

float puissance(float n, float p)
{
	float resultat=1;
	float puiss=p;

	while (puiss!=0)
	{
		resultat=n*resultat;
		puiss=puiss-1;
	}

	printf("\n%f à la puissance %f = %f\n",n,p,resultat);
}

int main()
{
	float x,y;

	printf("\nEntrer un nombre : ");
	scanf("%f",&x);

	printf("\nEntrer une puissance positive : ");
	scanf("%f",&y);

	puissance(x,y);
}
