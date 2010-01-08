/* TD 6 de C */

/* exercice 12 : FIBONACCI */

/* on commence par inclure les bibliothèque */
#include <stdio.h>
#include <stdlib.h>

int fibonacci (int n)
{
	if (n==0)
		return 0;
	if (n==1)
		return 1;
	else return ((fibonacci(n-1)) + (fibonacci(n-2)));
}

int main()
{
	int x;
	printf("Entrer votre nombre : ");
	scanf("%i",&x);

	fibonacci(x);
	printf("Fibonacci de %i : %i\n",x,fibonacci(x));
}
