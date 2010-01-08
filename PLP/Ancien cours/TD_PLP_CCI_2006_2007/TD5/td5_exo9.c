/* TD 6 de C */

/* exercice 9 : pointeurs */

/* on commence par inclure les biblioth�ue */
#include <stdio.h>
#include <stdlib.h>

/* fonction d'origine intuitive, ne fonctionne pas par manque de pointeur */
//void echange (float a, float b)
//{
//	float e;
//	e = a;
//	a = b;
//	b = a;
//		
//		printf("\nles valeurs �hang�s de retour sont %f et %f\n");
//}

/* fonction avec les pointeurs */
void echange (float *x, float *y)
{float tmp = *x;
	*x = *y;
	*y = tmp;
}

int main ()
{
	float a,b;
	
	printf("Entrer votre premier nombre : ");
	scanf("%f",&a);
	
	printf("\nEntrer votre deuxième nombre : ");
	scanf("%f",&b);
	
	echange(&a,&b);

	printf("\nles valeurs échangées de retour sont %f et %f\n", a, b);
}
