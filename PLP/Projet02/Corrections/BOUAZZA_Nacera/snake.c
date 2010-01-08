
    /*    ##########################################  */

   /*     Projet2 Langage C, de BOUAZZA Nacéra       */

  /*                                                */

 /*                  2009/2010                     */

/*    ########################################    */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* Definition de l'environnement d'exploitation pour la fonction system() */

#ifdef __linux__
#define CLRSCR "clear"
#else
#define CLRSCR "clear"
#endif
/*  ************************** */

typedef enum eDirection {
  HAUT = 95,    /* deplacement vers la gauche   */
  BAS = 118,    /*deplacement vers le bas      */
  DROITE = 62,  /*deplacement vers la droite  */
  GAUCHE = 60,  /*deplacement vers la gauche */
} direction;

typedef struct serpents {
  int position;     /* coordonnees           */
  direction sens;   /* direction de la tete */
  int taille;
} serpent;
/* ********************* Fonctions de deplacement des Serpents ************** */

depl_Droite(char mon_table[], int largeur, int hauteur, serpent* monSerpent, int *avancement) {
    switch ((*monSerpent).sens) {
        case 60 :
            if (mon_table[(*monSerpent).position-largeur]==' ') { 
                mon_table[(*monSerpent).position-largeur]=95;
                (*monSerpent).position -=largeur;
                (*monSerpent).sens = 95;
                (*monSerpent).taille++;
                (*avancement) = 1;
                break;
            }
            else { 
                break;
                 (*m  case 62 :
            if (mon_table[(*monSerpent).position+largeur]==' ') {                
mon_table[(*monSerpent).position+largeur]=118;
                (*monSerpent).position +=largeur;
                (*monSerpent).sens = 118;
                (*monSerpent).taille++;
                (*avancement) = 1;
                break;
            }
            else { 
                break;
            }
        case 95 :
            if (mon_table[(*monSerpent).position+1]==' ') { 
                mon_table[(*monSerpent).position+1]=62;
                (*monSerpent).position +=1;
                (*monSerpent).sens = 62;
                (*monSerpent).taille++;
                (*avancement) = 1;
                break;
            }
            else {
                break;
            }
        case 118 :
            if (mon_table[(*monSerpent).position-1]==' ') { 
                mon_table[(*monSerpent).position-1]=60;
                (*monSerpent).position -=1;
                (*monSerpent).sens = 60;
                (*monSerpent).taille++;
                (*avancement) = 1;
                break;
            }
            else {
                break;
            }
    }
}


depl_Gauche(char mon_table[], int largeur, int hauteur, serpent* monSerpent, int *avancement) {
    switch ((*monSerpent).sens) {
        case 60 :
            if (mon_table[(*monSerpent).position+largeur]==' ') { 
                mon_table[(*monSerpent).position+largeur]=118;
                (*monSerpent).position +=largeur;
                (*monSerpent).sens = 118;
                (*monSerpent).taille++;
                (*avancement) = 1;
                break;
            }
            else { 
                depl_Droite(mon_table, largeur, hauteur, monSerpent, avancement);
                break;
            }
        case 62 :
            if (mon_table[(*monSerpent).position-largeur]==' ') { 
                mon_table[(*monSerpent).position-largeur]=95;
                (*monSerpent).position -=largeur;
                (*monSerpent).sens = 95;
                (*monSerpent).taille++;
                (*avancement) = 1;
                break;
            }
            else { 
                depl_Droite(mon_table, largeur, hauteur, monSerpent, avancement);
                break;
            }
        case 95 :
            if (mon_table[(*monSerpent).position-1]==' ') { 
                mon_table[(*monSerpent).position-1]=60;
                (*monSerpent).position -=1;
                (*monSerpent).sens = 60;
                (*monSerpent).taille++;
                (*avancement) = 1;
                break;
            }
            else { 
                depl_Droite(mon_table, largeur, hauteur, monSerpent, avancement);
                break;
            }
        case 118 :
            if (mon_table[(*monSerpent).position+1]==' ') { 
                mon_table[(*monSerpent).position+1]=62;
                (*monSerpent).position +=1;
                (*monSerpent).sens = 62;
                (*monSerpent).taille++;
                (*avancement) = 1;
                break;
            }
            else { 
                depl_Droite(mon_table, largeur, hauteur, monSerpent, avancement);
                break;
            }
    }

}


avancer(char mon_table[], int largeur, int hauteur, serpent* monSerpent, int *avancement) { 
    switch ((*monSerpent).sens) {
        case 60 :
            if (mon_table[(*monSerpent).position-1]==' ') { 
                mon_table[(*monSerpent).position-1]=60;
                (*monSerpent).position -=1;
                (*monSerpent).taille++;
                (*avancement) = 1;
                break;
            }
            else {
                depl_Gauche(mon_table, largeur, hauteur, monSerpent, avancement);
                break;
            }
        case 62 :
            if (mon_table[(*monSerpent).position+1]==' ') { 
                mon_table[(*monSerpent).position+1]=62;
                (*monSerpent).position +=1;
                (*monSerpent).taille++;
                (*avancement) = 1;
                break;
            }
            else {
                depl_Gauche(mon_table, largeur, hauteur, monSerpent, avancement);
                break;
            }
        case 95 :
            if (mon_table[(*monSerpent).position-largeur]==' ') { 
                mon_table[(*monSerpent).position-largeur]=95;
                (*monSerpent).position -=largeur;
                (*monSerpent).taille++;
                (*avancement) = 1;
                break;
            }
            else { 
                depl_Gauche(mon_table, largeur, hauteur, monSerpent, avancement);
                break;
            }
        case 118 :
            if (mon_table[(*monSerpent).position+largeur]==' ') { 
                mon_table[(*monSerpent).position+largeur]=118;
                (*monSerpent).position +=largeur;
                (*monSerpent).taille++;
                (*avancement) = 1;
                break;
            }
            else { 
                depl_Gauche(mon_table, largeur, hauteur, monSerpent, avancement);
                break;
            }
    }

}
/* ************** fonction principale de deplacement *****************  */

deplacementSerpent(char mon_table[], int largeur, int hauteur,
        serpent tableSerpent[], int nbSerpent, int* avancement) {

    int i;
    for (i=0; i<nbSerpent; i++) {
        avancer(mon_table, largeur, hauteur, &tableSerpent[i], avancement);
    }

}
/* ********* fonction Timer **************** */

void attente(unsigned int tps_att) {
    unsigned int f = clock();
    unsigned int tps_clock = 0;

    tps_clock = tps_att * CLOCKS_PER_SEC/1000;
    while (clock()<f+tps_clock) {

    }
}
/* ******************** Fonction Affichage de montableau **************** */

affichage(char mon_table[ ], int nbLigne, int nbColonne) {

    int i, j;

    
    system("cls");

    for (i=0; i<nbLigne; i++) {
        for (j=i*nbColonne; j<((i+1)*nbColonne); j++) {
                printf("%c ", mon_table[j]);
                
        }
        printf("\n");
    }
}

/* ****************** Fonction Principale main ******************** */

int main(int argc, char** argv) {

    int largeur, hauteur, nb_Total, nbSerpent;
    int i, j, k, nbCaseVides, nbCaseVidesRestant;
    char c;
    int tete, caseTete, sens, dureeAttente;
    int versDir[4] = {94, 118, 62,60};
    int avancement = 1;

    srand(time(NULL)); 
    
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

    char mon_table[largeur*hauteur]; /* Creation du Tableau */
    nbCaseVides = (largeur-2)*(hauteur-2);
    nbCaseVidesRestant = nbCaseVides;
    int casseVides[nbCaseVides];

    for (i=0; i<nb_Total; i++)
        mon_table[i] = '#';

   
    k = 0;
    for (i=1; i<hauteur-1; i++) {
        for (j=i*largeur+1; j<((i+1)*largeur-1); j++) {
                mon_table[j] = ' ';
                casseVides[k] = j;
                k++;
        }
    }

    affichage(mon_table, hauteur, largeur); 
	

   
    for (i=0; i<nbSerpent; i++) {
        caseTete = (int) ((double) rand() / RAND_MAX * (nbCaseVides-i));
        tete = casseVides[caseTete];
        casseVides[caseTete] = casseVides[nbCaseVides-1-i];
        casseVides[nbCaseVides-1-i] = tete;
        sens = versDir[(int) ((double) rand() / RAND_MAX * (3 + 1))];
        tableSerpent[i].position = tete;
        tableSerpent[i].sens = sens;
        tableSerpent[i].taille = 1;
        mon_table[tete] = (char) sens;
    }

   
	
    affichage(mon_table, hauteur, largeur); 

    i=0;
    do {
        avancement = 0;
        i++;
        affichage(mon_table, hauteur, largeur); 
        deplacementSerpent(mon_table, largeur, hauteur, tableSerpent, nbSerpent, &avancement);
        attente(dureeAttente);

    } while (avancement);

    printf("\n Fin du Jeu...\n");

    system("PAUSE");
    return (EXIT_SUCCESS);
}



