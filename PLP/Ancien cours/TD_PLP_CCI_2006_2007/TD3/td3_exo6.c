/* TD 3 de C */

/* exercice 6 choix  PAS FINI*/

/* on commence par inclure les bibliothèque */
#include <stdio.h>

int main()
{

	int choix, age;

	printf("########################################################\n");
	printf(" ######################################################\n");
	printf("  ####################################################\n");
	printf("   ##################################################\n");

	printf("Menu de choix :\n");
	printf("Pour executer le programme de conversion,\n=====> veuillez tapper 1\n");
	printf("Pour executer le programme du monnayeur,\n=====> veuillez tapper 2\n");
	printf("Pour executer le programme de l'age,\n=====> veuillez tapper 3\n");

	printf("   ##################################################\n");
	printf("  ####################################################\n");
	printf(" ######################################################\n");
	printf("########################################################\n");
	printf("Choix : ");

	scanf("%i",&choix);

	switch (choix)
		{
		case (1) : exec1("conversion");
			break;
		case (2) : printf("monnayeur\n");
			break;
		case (3) :
		{
			printf("Quel est votre age svp ? : ");
			scanf("%i",&age);

			if (age<0)
				printf("\nATTENTION : Vous avez entre un age negatif !\n"); /* gestion erreur */
			else
			{
				if (age<18)
					printf("\nVous etes mineure\n");
				else
					if (age>=18)
						printf("\nVous etes majeure\n");
					else printf("\nATTENTION : Veuillez a bien entrer un entier pour votre age !\n"); /* gestion erreur */
			}
		}
		default : printf("ATTENTION : vous n'avez pas entre un choix valide !\n"); /* gestion erreur */
			break;
		}
}
