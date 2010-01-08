/* TD 9 de C */
/* exercice 1 : tableaux et pointeurs */
/* on commence par inclure les bibliothèque */
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int i = 1;
	int *pt;
	pt = malloc(sizeof(int));
	if (pt != NULL)
	{
		*pt = i;
		printf("i = %i\t*pt = %i\n",i,*pt);	// 1er affichage : i=1 et *pt =1
		*pt = 2;
		printf("i = %i\t*pt = %i\n",i,*pt);	// 2eme affichage : i=1 et *pt =2
		// le free(pt) doit se placer ici !!
		pt = &i;
		*pt = 3;
		printf("i = %i\t*pt = %i\n",i,*pt);	// 3eme affichage : i=3 et *pt =3
		//free(pt);
		exit(0);
	}
	else
	{
		printf("Problème d'allocation de la mémoire\n");
		//free(pt);
		exit(-1);
	}
free(pt);
}
/* Explications :
soit x : une valeur.
&x : est l'adresse de x.
soit int *pt : je créé un pointeur nommé 'pt' de type (int).
Ce pointeur 'pt' pointe vers une adresse mémoire 	CONTENANT une valeur.
Cependant la valeur de 'pt' = une adresse mémoire !

On veut accéder à la valeur qui est contenu par l'adresse mémoire !!
*pt = i; //ici on affecte la valeur de i dans la case mémoire pointée par 'pt'.
Cela ne se fait que si i est préalablement déclaré : int i = 1;
*pt = i signifie donc que 'pt' pointe vers une case mémoire de valeur 1.

2ème : *pt = 2; // on affecte la valeur 2 dans la case mémoire pointée par 'pt'.

3eme : pt = &i; // on fait pointer désormais le pointeur vers l'adresse de i !
Le pointeur change d'adresse, on change la valeur de 'pt', on change donc son adresse mémoire.
A ce stade, si on affiche *pt : on aura la valeur de i (1), puisque *pt donnera la valeur de la case pointée par 'pt'.
MAIS : on fait ensuite : *pt = 3
On écrase donc la valeur dans la case pointée par la valeur 3 (on écrase 1 avec la valeur 3).
Et comme l'adresse &i est stocké au niveau ce cette case mémoire, i prend la valeur 3 maintenant !
On aura l'affichage i=3 et *pt=3.


Conclusion :
x : une valeur
&x : son adresse
int *pt = &x; // signifie 1 : on créé un pointeur de type (int)
			  signifie 2 : ce pointeur pointe vers la valeur contenant dans l'adresse &x, donc la valeur de x !


La fonction malloc()
int*pt;
pt = (int*) malloc(100*sizeof(int));
cette fonction renvoit NULL si l'allocation est impossible
en gros, on peut faire : if(pt==NULL){"pb",return()}

et NE PAS OUBLIER de faire un free(pt) en fin de programme pour désallouer la mémoire !!!!!!!!!

*/
