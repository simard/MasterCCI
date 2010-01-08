/* TD 2 de C */

/* exercice 2 (correction) : structure */

/* on commence par inclure les bibliothèque */
#include <stdio.h>
#include <math.h>

/* definition d'une structure comportant les coordonnees x, y, z dans l'espace */
struct point {
	float x;
	float y;
	float z;
};


/* fonction principale */
int main()
{
	struct point p1	;
	struct point p2	;	

	printf("Veuillez entrer les coordonnees de p1\n");
	scanf("%f",&p1.x);
	scanf("%f",&p1.y);
	scanf("%f",&p1.z);

	printf("Veuillez entrer les coordonnees de p2\n");
	scanf("%f",&p2.x);
	scanf("%f",&p2.y);
	scanf("%f",&p2.z);

	printf("coordonnes du point 1 (%f,%f,%f)\n",p1.x,p1.y,p1.z);
	printf("coordonnes du point 2 (%f,%f,%f)\n",p2.x,p2.y,p2.z);









	float a,b,c,d,e,f;
	float V1,V2,V3,D;

	/* entrer des coordonnes du point 1 */
	printf("Veuillez entrer la premiere coordonnee pour le point 1 x1 :\n");
	scanf("%f",&a);
	printf("Veuillez entrer la deuxieme coordonnee pour le point 1 y1 :\n");
	scanf("%f",&b);
	printf("Veuillez entrer la troisieme coordonnee pour le point 1 z1 :\n");
	scanf("%f",&c);

	/* entrer des coordonnes du point 2 */
	printf("Veuillez entrer la premiere coordonnee pour le point 2 x2 :\n");
	scanf("%f",&d);
	printf("Veuillez entrer la deuxieme coordonnee pour le point 2 y2 :\n");
	scanf("%f",&e);
	printf("Veuillez entrer la troisieme coordonnee pour le point 2 z2 :\n");
	scanf("%f",&f);

	/* definitions des structures pour les 2 points */
	struct point p1	;
	p1.x = a;
	p1.y = b;
	p1.z = c;

	struct point p2	;
	p2.x = d;
	p2.y = e;
	p2.z = f;

	/* calculs des resultats */
	V1=p2.x - p1.x;
	V2=p2.y - p1.y;
	V3=p2.z - p1.z;

	D=(sqrt( V1*V1 + V2*V2 + V3*V3));

/* impression des resultats */
/* impression des coordonnes */
printf("coordonnes de 2 points rentres :\n");
printf("coordonnes du point 1 (%f,%f,%f)\n",p1.x,p1.y,p1.z);
printf("coordonnes du point 2 (%f,%f,%f)\n",p2.x,p2.y,p2.z);
/* impression de la distance separant les 2 points dans l'espace */
printf("distance separant 2 points : %f\n",D);
/* impression du vecteur des 2 points rentres */
printf("coordonnes du vecteur de 2 points rentres : \n");
printf("(%f,%f,%f)\n",V1,V2,V3);

}
