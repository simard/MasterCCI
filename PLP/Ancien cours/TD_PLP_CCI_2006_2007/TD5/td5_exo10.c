/* TD 6 de C */

/* exercice 10 : fonction recursive factorielle, ne fonctionn que pour n compris entre 0 et 27 */

/* on commence par inclure les biblioth�ue */
#include <stdio.h>
#include <stdlib.h>

/* fonction recursive */

int factorielle(int n)
{
	if (n<=1) return 1;
	else return (n*factorielle(n-1));
}

/* fonction itérative */

// void factorielle(float n)
// {
// 	float fact = 1;
// 	float i=1;
// 	while(i<=n){
// 		fact = fact*i;
// 		i++;
// 	}
// 		
// 	printf("Factorielle %f = %f\n",n,fact);
// }




int main()
{
	int n;
	
	printf("Entrer votre nombre : ");
	scanf("%i",&n);
	int copien=n;	

	factorielle(n);
	printf("Factorielle %i = %i\n",copien,factorielle(n));
}
