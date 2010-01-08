/*  Houte
    Nicolas
    BlackJack */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(int argc, char ** argv)
{

    typedef enum Valeur Valeur;
        enum Valeur
        {
            AS, DEUX, TROIS, QUATRE, CINQ, SIX, SEPT, HUIT, NEUF, DIX, VALET, DAME, ROI
        };

    typedef enum Couleur Couleur;
        enum Couleur
        {
            COEUR, CARREAU, PIQUE, TREFLE
        };

    Couleur cCarte;
    Valeur vCarte;
    int banque = 0;
    int score = 0;
    char prendreCarte = 0;
    int continuer = 1;


/* on initialise la fonction rand*/
    srand( time( NULL ) );


/* on met une valeur aléatoirement entre 16 et 21 dans le score de la banque */

    banque = (rand() % (21 - 16) + 1) +16;


    printf("Votre score est %d\n", score);


/* on commence la partie */
    while(continuer && score < 21)
    {
        prendreCarte = 0;

        printf("Voulez vous tirer une nouvelle carte [y/n] ?");

        scanf("%c", &prendreCarte);


/*  si oui, on obtient la valeur et la couleur d'une carte */
        if(prendreCarte == 'y')
        {

            cCarte =  (rand() % (4 - 0));
            vCarte =  (rand() % (13 - 0));

/* on affiche la carte correspondant à la valeur et la couleur choisi aléatoirement
Je met deux switch different pour ne pas avoir a faire 1 cas par carte */
            switch(vCarte)
            {
                case  AS :
                printf("Vous tirez un as");
                break;
                case  DEUX :
                printf("Vous tirez un deux");
                break;
                case  TROIS :
                printf("Vous tirez un trois");
                break;
                case  QUATRE :
                printf("Vous tirez un quatre");
                break;
                case  CINQ :
                printf("Vous tirez un cinq");
                break;
                case  SIX :
                printf("Vous tirez un six");
                break;
                case  SEPT :
                printf("Vous tirez un sept");
                break;
                case  HUIT :
                printf("Vous tirez un huit");
                break;
                case  NEUF :
                printf("Vous tirez un neuf");
                break;
                case  DIX :
                printf("Vous tirez un dix");
                break;
                case  VALET :
                printf("Vous tirez un valet");
                break;
                case  DAME :
                printf("Vous tirez un dame");
                break;
                case  ROI :
                printf("Vous tirez un roi");
                break;
                default :
                break;
            }

            switch(cCarte)
            {
                case  COEUR :
                printf(" de coeur\n");
                break;
                case  CARREAU :
                printf(" de carreau\n");
                break;
                case  PIQUE :
                printf(" de pique\n");
                break;
                case  TREFLE :
                printf(" de trefle\n");
                break;
                default :
                break;
            }


            /* on calcule le score selon la valeur de la carte tirée */

            if(vCarte > 9)
            {
                score += 10;
            }
            else if(vCarte == 0)
            {
                score += 11;
            }
            else
            {
                score += (vCarte +1);
            }
            printf("Votre score est %d\n", score);
        }

   /* si non, on sort de la boucle, pour terminer la partie */

        else if(prendreCarte == 'n')
        {
            break;

        }

        /* si une autre touche que 'n' ou 'y' est tapé on redemande une carte */
        else
        {
            continue;
        }

    }


/* on test si le joueur a gagné, perdu, ou est à égalité avec la banque */

    if(score > banque && score <= 21)
        {
            printf("Vous avez gagné\n");

        }
        else if(score == banque)
        {
            printf("Egalité\n");
        }
        else
        {
            printf("Vous avez perdu\n");

        }
        printf(" La banque avait : %d\n", banque);


    return 0;
}
