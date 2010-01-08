/* TD 2 de C */

/* question 2.2 */

/* on commence par inclure les fonctions d'affichages de la bibliothèque standard */
#include <stdio.h>
struct point {
	float x;
	float y;
};


/* fonction principale */
int main()
{
	struct point p	;
	
	p.x = 0;
	p.y = 0;

printf("%f\n%f\n",p.x,p.y);
}