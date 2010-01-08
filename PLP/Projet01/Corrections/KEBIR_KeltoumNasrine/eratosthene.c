/* Projet 01:Exercice d'Erastothene
  KEBIR Keltoum Nasrine
  Date:16/10/2009*/


#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])  

{ //Déclaration de toutes les variables 
	int nombreEntier;
	int i;
	int j;
	int reste;
	printf ("entrez un nombre entier superieur ou egal 2 : ");
	scanf("%d",&nombreEntier);
	printf("vous avez entrez %d\n",nombreEntier);
	int tableau[nombreEntier];

        for (i=0;i<nombreEntier;i++)   // On fait une boucle for pour initialiser tout le tableau à zero.
		tableau[i] = 0;
        i = j = reste = 0; // Initialisation à "0" de 3 variables locales
 
	if(nombreEntier>=2) {   // On effectue un teste sur la condition de depart qui de prendre un entier >=2
		for(i=2;i<nombreEntier;i++) { // Deux boucles successives sont necessaires pour parcourir notre tableau et effectuer les divisions afin de savoir si reste =0 
			for(j=2;j<i;j++ ) {
				reste=i%j;   //cette operation modulo nous permet de savoir si notre chiffre est un nombre premier ou non 
				if(reste==0){   // Si reste=0 ce n'est pas un nombre premier donc on met le chiffre "1" dans la case du tableau correspondant à ce chiffre
					tableau[i]=1;
					break; //on a break car si la premiere operation donne un reste ="0" pas la peine de faire les autres operation
				}
			}
		}
	}
	else
		printf(" vous avez rentrer le nombre entier %d ce chiffre n'est pas superieur ou egal 2, recommancer\n",nombreEntier);// si le chiffre entree n est pas bon , le programme affiche cela. 

	for (i=1;i<nombreEntier;i++)  // on fait une boucle pour afficher notre tableau dans sa globalite, on affiche les indices et les "0"et "1".
		printf("%d %d \n",i,tableau[i]);

	return 0;

}



