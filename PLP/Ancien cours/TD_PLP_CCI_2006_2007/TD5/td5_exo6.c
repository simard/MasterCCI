/* TD 6 de C */

/* exercice 6 :  */

/* on commence par inclure les bibliothèque */
#include <stdio.h>
#include <stdlib.h>

void f (int x)
{
	x+=3;
}

int main ()
{
	int y=0;
	
	printf("test 1 : %i\n",y); /* affiche la variable y = 0 ! */
	
	f(y);

	printf("test 2 : %i\n",y); /* affichera 0 aussi, car nous sommes en dehors de la fonction f */
}
