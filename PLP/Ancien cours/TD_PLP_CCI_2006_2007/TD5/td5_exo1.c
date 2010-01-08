/* TD 6 de C */

/* exercice 1 : fonction */

/* on commence par inclure les bibliothèque */
#include <stdio.h>
#include <stdlib.h>

void afficher(char nom[10], char prenom[10])
{
	printf("%s %s\n", nom, prenom);
}

	char nom[10];
	char prenom[10];

int main()
{
	printf("\nVeuillez entrer votre nom  : ");
	scanf("%s",&nom);

	printf("\nVeuillez entrer votre prenom : ");
	scanf("%s",&prenom);

	printf("\nJe m'appele ");
	afficher(nom, prenom);
	printf("\n");
}



// Premier essai

// void afficher(char nom[10], char prenom[10])
// {
// 	printf("%s %s\n", nom, prenom);
// }
// 
// int main()
// {
// 	printf("Je m'appele ");
// 	afficher("fromentin", "sebastien");
// }
