/* Projet 01:Exercice Black JACK
  KEBIR Keltoum Nasrine
  Date:16/10/2009*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(int argc, char *argv[]) {

    char decisionJoeur; // choix du joueur
    int scoreJoeur, scoreBanque; // score du joeur et de la banque
    int tirageCarte, tirageCarteBanque; // cartes tirees
    int nbAs = 0; // nombre d'As tirés
    enum carteTiree {C0,C1,C2,C3,C4,C5,C6,C7,C8,C9,CX,CVDR,
        T1,T2,T3,T4,T5,T6,T7,T8,T9,TX,TVDR,
        P1,P2,P3,P4,P5,P6,P7,P8,P9,PX,PVDR,
        CA1,CA2,CA3,CA4,CA5,CA6,CA7,CA8,CA9,CAX,CAVDR};// X=10, VDR=ValetDameRoi

	srand(time(NULL)); // pour l'initialisation du nombre aleatoire

	// scoreBanque = (int) (16 + ((double) rand() / RAND_MAX * (21 - 16 + 1)));
	
	scoreJoeur = 0;
        scoreBanque = 0;
	decisionJoeur = '0';

        // tant que le score du joeur<21 
	do {
		printf("Votre score est : %d\n", scoreJoeur );
		while (decisionJoeur != 'y' && decisionJoeur != 'n'){
			printf("Voulez-vous tirer une nouvelle carte [y/n] ? ");
			scanf("%c",&decisionJoeur);
			getchar();
			printf("\n");
		}
                if (decisionJoeur=='n')
                    break;
                if (decisionJoeur=='y')
                    tirageCarte = (int) (1 + ((double) rand() / RAND_MAX * (52 - 1 + 1)));

                switch (tirageCarte) {
                    case 1 : printf("Vous tirez un as Coeur \n");
                                nbAs++;
                                scoreJoeur += 10;
                                break;
                    case 2 : printf("Vous tirez un 2 Coeur \n");
                                scoreJoeur += 2;
                                break;
                    case 3 : printf("Vous tirez un 3 Coeur \n");
                                scoreJoeur += 3;
                                break;
                    case 4 : printf("Vous tirez un 4 Coeur \n");
                                scoreJoeur += 4;
                                break;
                    case 5 : printf("Vous tirez un 5 Coeur \n");
                                scoreJoeur += 5;
                                break;
                    case 6 : printf("Vous tirez un 6 Coeur \n");
                                scoreJoeur += 6;
                                break;
                    case 7 : printf("Vous tirez un 7 Coeur \n");
                                scoreJoeur += 7;
                                break;
                    case 8 : printf("Vous tirez un 8 Coeur \n");
                                scoreJoeur += 8;
                                break;
                    case 9 : printf("Vous tirez un 9 Coeur \n");
                                scoreJoeur += 9;
                                break;
                    case 10 : printf("Vous tirez un 10 Coeur \n");
                                scoreJoeur += 10;
                                break;
                    case 11 : printf("Vous tirez un valet Coeur \n");
                                scoreJoeur += 10;
                                break;
                    case 12 : printf("Vous tirez un dame Coeur \n");
                                scoreJoeur += 10;
                                break;
                    case 13 : printf("Vous tirez un roi Coeur \n");
                                scoreJoeur += 10;
                                break;
                    case 14 : printf("Vous tirez un as trefle \n");
                                scoreJoeur += 10;
                                nbAs++;
                                break;
                    case 15 : printf("Vous tirez un 2 trefle \n");
                                scoreJoeur += 2;
                                break;
                    case 16 : printf("Vous tirez un 3 trefle \n");
                                scoreJoeur += 3;
                                break;
                    case 17 : printf("Vous tirez un 4 trefle \n");
                                scoreJoeur += 4;
                                break;
                    case 18 : printf("Vous tirez un 5 trefle \n");
                                scoreJoeur += 5;
                                break;
                    case 19 : printf("Vous tirez un 6 trefle \n");
                                scoreJoeur += 6;
                                break;
                    case 20 : printf("Vous tirez un 7 trefle \n");
                                scoreJoeur += 7;
                                break;
                    case 21 : printf("Vous tirez un 8 trefle \n");
                                scoreJoeur += 8;
                                break;
                    case 22 : printf("Vous tirez un 9 trefle \n");
                                scoreJoeur += 9;
                                break;
                    case 23 : printf("Vous tirez un 10 trefle \n");
                                scoreJoeur += 10;
                                break;
                    case 24 : printf("Vous tirez un valet trefle \n");
                                scoreJoeur += 10;
                                break;
                    case 25 : printf("Vous tirez un dame trefle \n");
                                scoreJoeur += 10;
                                break;
                    case 26 : printf("Vous tirez un roi trefle \n");
                                scoreJoeur += 10;
                                break;
                    case 27 : printf("Vous tirez un as pique \n");
                                scoreJoeur += 10;
                                nbAs++;
                                break;
                    case 28 : printf("Vous tirez un 2 pique \n");
                                scoreJoeur += 2;
                                break;
                    case 29 : printf("Vous tirez un 3 pique \n");
                                scoreJoeur += 3;
                                break;
                    case 30 : printf("Vous tirez un 4 pique \n");
                                scoreJoeur += 4;
                                break;
                    case 31 : printf("Vous tirez un 5 pique \n");
                                scoreJoeur += 5;
                                break;
                    case 32 : printf("Vous tirez un 6 pique \n");
                                scoreJoeur += 6;
                                break;
                    case 33 : printf("Vous tirez un 7 pique \n");
                                scoreJoeur += 7;
                                break;
                    case 34 : printf("Vous tirez un 8 pique \n");
                                scoreJoeur += 8;
                                break;
                    case 35 : printf("Vous tirez un 9 pique \n");
                                scoreJoeur += 9;
                                break;
                    case 36 : printf("Vous tirez un 10 pique \n");
                                scoreJoeur += 10;
                                break;
                    case 37 : printf("Vous tirez un valet pique \n");
                                scoreJoeur += 10;
                                break;
                    case 38 : printf("Vous tirez un dame pique \n");
                                scoreJoeur += 10;
                                break;
                    case 39 : printf("Vous tirez un roi pique \n");
                                scoreJoeur += 10;
                                break;
                    case 40 : printf("Vous tirez un as carreau \n");
                                scoreJoeur += 10;
                                nbAs++;
                                break;
                    case 41 : printf("Vous tirez un 2 carreau \n");
                                scoreJoeur += 2;
                                break;
                    case 42 : printf("Vous tirez un 3 carreau \n");
                                scoreJoeur += 3;
                                break;
                    case 43 : printf("Vous tirez un 4 carreau \n");
                                scoreJoeur += 4;
                                break;
                    case 44 : printf("Vous tirez un 5 carreau \n");
                                scoreJoeur += 5;
                                break;
                    case 45 : printf("Vous tirez un 6 carreau \n");
                                scoreJoeur += 6;
                                break;
                    case 46 : printf("Vous tirez un 7 carreau \n");
                                scoreJoeur += 7;
                                break;
                    case 47 : printf("Vous tirez un 8 carreau \n");
                                scoreJoeur += 8;
                                break;
                    case 48 : printf("Vous tirez un 9 carreau \n");
                                scoreJoeur += 9;
                                break;
                    case 49 : printf("Vous tirez un 10 carreau \n");
                                scoreJoeur += 10;
                                break;
                    case 50 : printf("Vous tirez un valet carreau \n");
                                scoreJoeur += 10;
                                break;
                    case 51 : printf("Vous tirez un dame carreau \n");
                                scoreJoeur += 10;
                                break;
                    case 52 : printf("Vous tirez un roi carreau\n");
                                scoreJoeur += 10;

                }
                if (scoreJoeur>21 && nbAs>0) {
                    scoreJoeur -= 9;
                    nbAs--;
                }
                if (scoreJoeur>21 && nbAs==0) {
                    printf("Vous avez perdu \n");
                    break;
                }
                decisionJoeur = '0';

	} while (scoreJoeur<21);

        if (scoreJoeur >21) {
            tirageCarteBanque = (int) (16 + ((double) rand() / RAND_MAX * (21 - 16 + 1)));
            scoreBanque += tirageCarteBanque;
            printf("Score Banque est   : \t %d \n", scoreBanque);
            printf("Fin de la partie, votre score est : %d \t, vous avez perdu !!! \n", scoreJoeur );
        }

        if (scoreJoeur == 0) {
            printf("Trouvez de l'aregent et venez jouez !!! \n");
            printf("Tentez votre chance !!! \n");
        }

        if (scoreJoeur >= 1 && scoreJoeur <= 21) {
            scoreBanque = (int) (16 + ((double) rand() / RAND_MAX * (21 - 16 + 1)));
            if (scoreBanque <= scoreJoeur) {
                printf("Score Banque est   : \t %d \n", scoreBanque);
                printf("Fin de la partie, votre score est : %d \t, vous avez gagne !!! \n", scoreJoeur );
            }
            else {
                printf("Score Banque est   : \t %d \n", scoreBanque);
                printf("Fin de la partie, votre score est : %d \t, vous avez perdu !!! \n", scoreJoeur );
            }
        }

    return EXIT_SUCCESS;
}
