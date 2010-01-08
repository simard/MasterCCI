/* TD 2 de C */

/* 4.1 : structure */

/* on commence par inclure les bibliothèque */
#include <stdio.h>

/* definition d'une structure comportant les coordonnees x, y, z dans l'espace */
struct point {
	float x;
	float y;
};

int main()
{
	struct point p;
	p.x = 0;
	p.y=0;
	printf("%f\n%f",p.x,p.y);
}
