/* TD 2 de C */

/* question 2.2 */

/* on commence par inclure les fonctions d'affichages de la bibliothèque standard */
#include <stdio.h>

/* fonction principale */
int main(){
	int i1 = 3, i2 = 2, i3;
	float f1 = 3, f2 = 2, f3;
	i3 = i1/i2;
	f3 = f1/f2;
	printf("i3 = %i\nf3 = %f\n", i3,f3);
	i3 = f1/f2;
	f3 = i1/i2;
	printf("i3 = %i\nf3 = %f\n", i3,f3);
}