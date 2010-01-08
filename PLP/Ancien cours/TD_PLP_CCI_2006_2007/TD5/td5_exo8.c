/* TD 6 de C */

/* exercice 1 : fonction */

/* on commence par inclure les bibliothèque */
#include <stdio.h>
#include <stdlib.h>

struct personne 
{
	char nom[10];
	char prenom[10];
};


void afficherPresentation(struct personne p)
{
	printf("%s %s\n", p.nom, p.prenom);
}


int main()
{
	struct personne p;

	printf("\nVeuillez entrer votre nom  : ");
	scanf("%s",&p.nom);

	printf("\nVeuillez entrer votre prenom : ");
	scanf("%s",&p.prenom);

	printf("\nJe m'appele ");
	afficherPresentation(p);
	printf("\n");
}
