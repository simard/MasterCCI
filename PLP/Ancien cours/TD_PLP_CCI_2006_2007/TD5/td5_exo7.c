/* TD 6 de C */

/* exercice 6 :  */

/* on commence par inclure les bibliothèque */
#include <stdio.h>
#include <stdlib.h>

void f (int *x)
{
	*x += 3;
}

int main ()
{
	int y = 0;
	
	printf("test 1 : %i\n",y); /* affiche la variable y = 0 ! */
	
	f(&y); /* il faut utiliser la syntaxe &f pour appeler la fonction */

	printf("test 2 : %i\n",y); /* affichera 3 par appel de la fonction f */
}
