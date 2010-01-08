#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#ifdef __linux__
#define CLRSCR "clear"
#else
#define CLRSCR "clr"
#endif

typedef enum eDirection {
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


tournerDroite(char ctab[], int larg, int haut, serpent* S, int *av) {
    switch ((*S).sens) {
        case 60 :
            if (ctab[(*S).position-larg]==' ') { 
                ctab[(*S).position-larg]=94;
                (*S).position -=larg;
                (*S).sens = 94;
                (*S).taille++;
                (*av) = 1;
                break;
            }
            else { 
                break;
            }
        case 62 :
            if (ctab[(*S).position+larg]==' ') { 
                ctab[(*S).position+larg]=118;
                (*S).position +=larg;
                (*S).sens = 118;
                (*S).taille++;
                (*av) = 1;
                break;
            }
            else {
                break;
            }
        case 94 :
            if (ctab[(*S).position+1]==' ') { 
                ctab[(*S).position+1]=62;
                (*S).position +=1;
                (*S).sens = 62;
                (*S).taille++;
                (*av) = 1;
                break;
            }
            else {
                break;
            }
        case 118 :
            if (ctab[(*S).position-1]==' ') { 
                ctab[(*S).position-1]=60;
                (*S).position -=1;
                (*S).sens = 60;
                (*S).taille++;
                (*av) = 1;
                break;
            }
            else 
                break;
            }
    }



tournerGauche(char ctab[], int larg, int haut, serpent* S, int *av) {
    switch ((*S).sens) {
        case 60 :
            if (ctab[(*S).position+larg]==' ') { 
                ctab[(*S).position+larg]=118;
                (*S).position +=larg;
                (*S).sens = 118;
                (*S).taille++;
                (*av) = 1;
                break;
            }
            else { 
                tournerDroite(ctab, larg, haut, S, av);
                break;
            }
        case 62 :
            if (ctab[(*S).position-larg]==' ') {
                ctab[(*S).position-larg]=94;
                (*S).position -=larg;
                (*S).sens = 94;
                (*S).taille++;
                (*av) = 1;
                break;
            }
            else { 
                tournerDroite(ctab, larg, haut, S, av);
                break;
            }
        case 94 :
            if (ctab[(*S).position-1]==' ') { 
                ctab[(*S).position-1]=60;
                (*S).position -=1;
                (*S).sens = 60;
                (*S).taille++;
                (*av) = 1;
                break;
            }
            else { 
                tournerDroite(ctab, larg, haut, S, av);
                break;
            }
        case 118 :
            if (ctab[(*S).position+1]==' ') { 
                ctab[(*S).position+1]=62;
                (*S).position +=1;
                (*S).sens = 62;
                (*S).taille++;
                (*av) = 1;
                break;
            }
            else { 
                tournerDroite(ctab, larg, haut, S, av);
                break;
            }
    }

}


avancer(char ctab[], int larg, int haut, serpent* S, int *av) {
    switch ((*S).sens) {
        case 60 :
            if (ctab[(*S).position-1]==' ') { 
                ctab[(*S).position-1]=60;
                (*S).position -=1;
                (*S).taille++;
                (*av) = 1;
                break;
            }
            else {
                tournerGauche(ctab, larg, haut, S, av);
                break;
            }
        case 62 :
            if (ctab[(*S).position+1]==' ') { 
                ctab[(*S).position+1]=62;
                (*S).position +=1;
                (*S).taille++;
                (*av) = 1;
                break;
            }
            else {
                tournerGauche(ctab, larg, haut, S, av);
                break;
            }
        case 94 :
            if (ctab[(*S).position-larg]==' ') {
                ctab[(*S).position-larg]=94;
                (*S).position -=larg;
                (*S).taille++;
                (*av) = 1;
                break;
            }
            else { 
                tournerGauche(ctab, larg, haut, S, av);
                break;
            }
        case 118 :
            if (ctab[(*S).position+larg]==' ') { 
                ctab[(*S).position+larg]=118;
                (*S).position +=larg;
                (*S).taille++;
                (*av) = 1;
                break;
            }
            else { 
                tournerGauche(ctab, larg, haut, S, av);
                break;
            }
    }

}


deplacementSerpent(char ctab[], int larg, int haut,
        serpent tableSerpent[], int nbSerpent, int* av) {

    int i;
    for (i=0; i<nbSerpent; i++) {
        avancer(ctab, larg, haut, &tableSerpent[i], av);
    }

}

void attente(unsigned int tps_att) {
    unsigned int f = clock();
    unsigned int tps_clock = 0;

    tps_clock = tps_att * CLOCKS_PER_SEC/1000;
    while (clock()<f+tps_clock) {

    }
}

affichage(char ctab[], int nbLigne, int nbColonne) {

    int i, j;

    //system("PAUSE");
    system(CLRSCR);

    for (i=0; i<nbLigne; i++) {
        for (j=i*nbColonne; j<((i+1)*nbColonne); j++) {
                printf("%c ", ctab[j]);
                //attente(500);
        }
        printf("\n");
    }
}



int main(int argc, char** argv) {

    int larg, haut, nb_Total, nbSerpent;
    int i, j, k, nbCaseVides, nbCaseVidesRestant;
    char c;
    int tete, caseTete, sens, dureeAttente;
    int versDir[4] = {94, 118, 62,60};
    int av = 1;

    srand(time(NULL)); // pour l'initialisation du nombre aleatoire
    
    printf("nombre d'argument %d \n", (argc-1));
    if (argc!=4) {
        printf("Vous devez entre largeurxhauetr, plus nombre de serepents \n");
        printf("plus la durre de rafraichissment de l'animation en ms \n");
        printf("Total d'arguements 3 \n");
        return (EXIT_SUCCESS);
    }
    sscanf(argv[1], "%dx%d", &larg, &haut);
    printf("largeur %d et hauteur %d \n", larg, haut);
    nb_Total = larg * haut;
    sscanf(argv[2], "%d", &nbSerpent);
    serpent tableSerpent[nbSerpent];
    sscanf(argv[3], "%d", &dureeAttente);

    //system(CLRSCR);

    char ctab[larg*haut]; // declaration tableu 1D
    nbCaseVides = (larg-2)*(haut-2);
    nbCaseVidesRestant = nbCaseVides;
    int casseVides[nbCaseVides];

    // Remplissage du tableau par des #
    for (i=0; i<nb_Total; i++)
        ctab[i] = '#';

    // mettre des vide dans le noyau du tableau 2D
    // et creation du tableau des casses vides
    k = 0;
    for (i=1; i<haut-1; i++) {
        for (j=i*larg+1; j<((i+1)*larg-1); j++) {
                ctab[j] = ' ';
                casseVides[k] = j;
                k++;
        }
    }

    affichage(ctab, haut, larg); // test affichage du table 2D

    // creation les serpents
    for (i=0; i<nbSerpent; i++) {
        caseTete = (int) ((double) rand() / RAND_MAX * (nbCaseVides-i));
        tete = casseVides[caseTete];
        casseVides[caseTete] = casseVides[nbCaseVides-1-i];
        casseVides[nbCaseVides-1-i] = tete;
        sens = versDir[(int) ((double) rand() / RAND_MAX * (3 + 1))];
        tableSerpent[i].position = tete;
        tableSerpent[i].sens = sens;
        tableSerpent[i].taille = 1;
        ctab[tete] = (char) sens;
    }

    // Deplacement des serpents
    affichage(ctab, haut, larg); // test affichage du table 2D

    i=0;
    do {
        av = 0;
        i++;
        affichage(ctab, haut, larg); // test affichage du table 2D
        deplacementSerpent(ctab, larg, haut, tableSerpent, nbSerpent, &av);
        attente(dureeAttente);
	//system(CLRSCR);
    } while (av);

    printf("\n Fin du Jeu...\n");




    // int i,j;

 int chaut=0;
 int cbas=0;
 int cdroite=0;
 int cgauche=0;
 int occupe=0;
 int vide=0;
 for(i=0;i<haut;i++){
           for(j=0;j<larg;j++){
                                      if(ctab[i*larg+j]==94){
                                         occupe++;
                                         chaut++;
                                           }
                                      else if(ctab[i*larg+j]==118){
                                           occupe++;
                                           cbas++;
                                           }
                                      else if(ctab[i*larg+j]==62){
                                           occupe++;
                                           cdroite++;
                                           }
                                      else if(ctab[i*larg+j]==60){
                                           occupe++;
                                           cgauche++;
                                           }
                                      else if (ctab[i*larg+j]==' '){
                                           vide++;
                                           }
                                      }
           }
 printf("le nombre totale de cases est :%d\n",haut*larg);
 printf("le nombres total de cases occupeés est :%d\n",occupe);
 printf("le nombres total de cases vides est :%d\n",vide);

 float pourcentage,pourcentage1,pourcentage2,pourcentage3,pourcentage4;
 pourcentage= ((float)(occupe))/((float)(larg*haut))*100;
 printf("Le plateau est rempli a %0.1f pourcent (%d/%d) dont :\n",pourcentage,occupe,larg*haut);
 pourcentage1= ((float)(chaut))/((float)(occupe))*100;   
 printf("- %0.1f '^' (%d/%d)\n",pourcentage1,chaut,occupe);
 pourcentage2= ((float)(cbas))/((float)(occupe))*100;
 printf("- %0.1f 'v' (%d/%d)\n",pourcentage2,cbas,occupe);
 pourcentage3= ((float)(cdroite))/((float)(occupe))*100;
 printf("- %0.1f '>' (%d/%d)\n",pourcentage3,cdroite,occupe);
 pourcentage4= ((float)(cgauche))/((float)(occupe))*100;
 printf("- %0.1f '<' (%d/%d)\n",pourcentage4,cgauche,occupe);                                        
                                           
            
                          
 return 0;






    system("PAUSE");
    return (EXIT_SUCCESS);
}
