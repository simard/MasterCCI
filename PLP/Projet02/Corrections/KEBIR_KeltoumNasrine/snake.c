/* 
 * Fichier :   projet.c
 * Auteur  : KEBIR Keltoum Nasrine
 *
 * Le 02 novembre 2009
 */

/* Declaration des bibliothèques  */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/* Definition de l'environnement d'exploitation pour la fonction system() */
#ifdef __linux__
#define CLRSCR "clear"
#else
#define CLRSCR "clear"
#endif


typedef enum eDirection {   //enum eDirection {haut1,bas1,droite1,gauche1}

        haut = 94,
        bas = 118,
        droite = 62,
        gauche = 60,
} direction;

typedef struct serpents {
    int position;
    direction sens;
    int taille;
} serpent;

// serpent tourne � droite
tournerDroite(char table[], int largeur, int hauteur, serpent* monSerpent, int *avancement) {
    switch ((*monSerpent).sens) {
        case 60 :
            if (table[(*monSerpent).position-largeur]==' ') { // avancement possible
                table[(*monSerpent).position-largeur]=94;
                (*monSerpent).position -=largeur;
                (*monSerpent).sens = 94;
                (*monSerpent).taille++;
                (*avancement) = 1;
                break;
            }
            else { // avancement possible {
                break;
            }
        case 62 :
            if (table[(*monSerpent).position+largeur]==' ') { // avancement possible
                table[(*monSerpent).position+largeur]=118;
                (*monSerpent).position +=largeur;
                (*monSerpent).sens = 118;
                (*monSerpent).taille++;
                (*avancement) = 1;
                break;
            }
            else { // avancement possible
                break;
            }
        case 94 :
            if (table[(*monSerpent).position+1]==' ') { // avancement possible
                table[(*monSerpent).position+1]=62;
                (*monSerpent).position +=1;
                (*monSerpent).sens = 62;
                (*monSerpent).taille++;
                (*avancement) = 1;
                break;
            }
            else { // avancement possible
                break;
            }
        case 118 :
            if (table[(*monSerpent).position-1]==' ') { // avancement possible
                table[(*monSerpent).position-1]=60;
                (*monSerpent).position -=1;
                (*monSerpent).sens = 60;
                (*monSerpent).taille++;
                (*avancement) = 1;
                break;
            }
            else { // avancement possible
                break;
            }
    }
}

// serpent tourne � gauche
tournerGauche(char table[], int largeur, int hauteur, serpent* monSerpent, int *avancement) {
    switch ((*monSerpent).sens) {
        case 60 :
            if (table[(*monSerpent).position+largeur]==' ') { // avancement possible
                table[(*monSerpent).position+largeur]=118;
                (*monSerpent).position +=largeur;
                (*monSerpent).sens = 118;
                (*monSerpent).taille++;
                (*avancement) = 1;
                break;
            }
            else { // avancement possible
                tournerDroite(table, largeur, hauteur, monSerpent, avancement);
                break;
            }
        case 62 :
            if (table[(*monSerpent).position-largeur]==' ') { // avancement possible
                table[(*monSerpent).position-largeur]=94;
                (*monSerpent).position -=largeur;
                (*monSerpent).sens = 94;
                (*monSerpent).taille++;
                (*avancement) = 1;
                break;
            }
            else { // avancement possible
                tournerDroite(table, largeur, hauteur, monSerpent, avancement);
                break;
            }
        case 94 :
            if (table[(*monSerpent).position-1]==' ') { // avancement possible
                table[(*monSerpent).position-1]=60;
                (*monSerpent).position -=1;
                (*monSerpent).sens = 60;
                (*monSerpent).taille++;
                (*avancement) = 1;
                break;
            }
            else { // avancement possible
                tournerDroite(table, largeur, hauteur, monSerpent, avancement);
                break;
            }
        case 118 :
            if (table[(*monSerpent).position+1]==' ') { // avancement possible
                table[(*monSerpent).position+1]=62;
                (*monSerpent).position +=1;
                (*monSerpent).sens = 62;
                (*monSerpent).taille++;
                (*avancement) = 1;
                break;
            }
            else { // avancement possible
                tournerDroite(table, largeur, hauteur, monSerpent, avancement);
                break;
            }
    }

}

// Avancement du serpent
avancer(char table[], int largeur, int hauteur, serpent* monSerpent, int *avancement) {
    switch ((*monSerpent).sens) {
        case 60 :
            if (table[(*monSerpent).position-1]==' ') { // avancement possible
                table[(*monSerpent).position-1]=60;
                (*monSerpent).position -=1;
                (*monSerpent).taille++;
                (*avancement) = 1;
                break;
            }
            else {// avancement possible
                tournerGauche(table, largeur, hauteur, monSerpent, avancement);
                break;
            }
        case 62 :
            if (table[(*monSerpent).position+1]==' ') { // avancement possible
                table[(*monSerpent).position+1]=62;
                (*monSerpent).position +=1;
                (*monSerpent).taille++;
                (*avancement) = 1;
                break;
            }
            else {// avancement possible
                tournerGauche(table, largeur, hauteur, monSerpent, avancement);
                break;
            }
        case 94 :
            if (table[(*monSerpent).position-largeur]==' ') { // avancement possible
                table[(*monSerpent).position-largeur]=94;
                (*monSerpent).position -=largeur;
                (*monSerpent).taille++;
                (*avancement) = 1;
                break;
            }
            else { // avancement possible
                tournerGauche(table, largeur, hauteur, monSerpent, avancement);
                break;
            }
        case 118 :
            if (table[(*monSerpent).position+largeur]==' ') { // avancement possible
                table[(*monSerpent).position+largeur]=118;
                (*monSerpent).position +=largeur;
                (*monSerpent).taille++;
                (*avancement) = 1;
                break;
            }
            else { // avancement possible
                tournerGauche(table, largeur, hauteur, monSerpent, avancement);
                break;
            }
    }

}

// D�placement du serpent
deplacementSerpent(char table[], int largeur, int hauteur,
        serpent tableSerpent[], int nbSerpent, int* avancement) {

    int i;
    for (i=0; i<nbSerpent; i++) {
        avancer(table, largeur, hauteur, &tableSerpent[i], avancement);
    }

}
//Attente du serpent
void attente(unsigned int tps_att) {
    unsigned int f = clock();
    unsigned int tps_clock = 0;

    tps_clock = tps_att * CLOCKS_PER_SEC/1000;
    while (clock()<f+tps_clock) {

    }
}
 //Affichage
affichage(char table[], int nbLigne, int nbColonne) {

    int i, j;

    //system("PAUSE");
    system("cls");

    for (i=0; i<nbLigne; i++) {
        for (j=i*nbColonne; j<((i+1)*nbColonne); j++) {
                printf("%c ", table[j]);
                //attente(500);
        }
        printf("\n");
    }
}



int main(int argc, char** argv) {

    int largeur, hauteur, nb_Total, nbSerpent;
    int i, j, k, nbCaseVides, nbCaseVidesRestant;
    char c;
    int tete, caseTete, sens, dureeAttente;
    int versDir[4] = {94, 118, 62,60};
    int avancement = 1;

    srand(time(NULL)); // pour l'initialisation du nombre aleatoire
    
    printf("nombre d'argument %d \n", (argc-1));
    if (argc!=4) {
        printf("Vous devez entre largeurxhauetr, plus nombre de serepents \n");
        printf("plus la durre de rafraichissment de l'animation en ms \n");
        printf("Total d'arguements 3 \n");
        return (EXIT_SUCCESS);
    }
    sscanf(argv[1], "%dx%d", &largeur, &hauteur);
    printf("largeur %d et hauteur %d \n", largeur, hauteur);
    nb_Total = largeur * hauteur;
    sscanf(argv[2], "%d", &nbSerpent);
    serpent tableSerpent[nbSerpent];
    sscanf(argv[3], "%d", &dureeAttente);

    system("clear");

    char table[largeur*hauteur]; // declaration tableu 1D
    nbCaseVides = (largeur-2)*(hauteur-2);
    nbCaseVidesRestant = nbCaseVides;
    int casseVides[nbCaseVides];

    // Remplissage du tableau par des #
    for (i=0; i<nb_Total; i++)
        table[i] = '#';

    // mettre des vide dans le noyau du tableau 2D
    // et creation du tableau des casses vides
    k = 0;
    for (i=1; i<hauteur-1; i++) {
        for (j=i*largeur+1; j<((i+1)*largeur-1); j++) {
                table[j] = ' ';
                casseVides[k] = j;
                k++;
        }
    }

    affichage(table, hauteur, largeur); // test affichage du table 2D

    // creation des serpents
    for (i=0; i<nbSerpent; i++) {
        caseTete = (int) ((double) rand() / RAND_MAX * (nbCaseVides-i));
        tete = casseVides[caseTete];
        casseVides[caseTete] = casseVides[nbCaseVides-1-i];
        casseVides[nbCaseVides-1-i] = tete;
        sens = versDir[(int) ((double) rand() / RAND_MAX * (3 + 1))];
        tableSerpent[i].position = tete;
        tableSerpent[i].sens = sens;
        tableSerpent[i].taille = 1;
        table[tete] = (char) sens;
    }

    // Deplacement des serpents
    affichage(table, hauteur, largeur); // test affichage du table 2D

    i=0;
    do {
        avancement = 0;
        i++;
        affichage(table, hauteur, largeur); // test affichage du table 2D
        deplacementSerpent(table, largeur, hauteur, tableSerpent, nbSerpent, &avancement);
        attente(dureeAttente);

    } while (avancement);

    printf("\n Fin du Jeu...\n");

    system("PAUSE");
    return (EXIT_SUCCESS);
}



