/* TD 6 de C */

/* exercice 1 : fonction valeur absolue */

/* on commence par inclure les bibliothèque */
#include <stdio.h>
#include <stdlib.h>

float valeurab(float x)
{
	if (x>=0)
		printf("\nLa valeur absolue de %f est : %f\n",x,x);
	else
		printf("\nLa valeur absolue de %f est : %f\n",x,(-x));
}

int main()
{
	float n;

	printf("\nVeuillez entrer votre nombre reel ou entier : ");
	scanf("%f",&n);

	valeurab(n);
}
