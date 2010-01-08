/* 
 * projet: snake
 * Author: DAHMANI_Arezki
 *
 * 28/10/ 2009
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifdef __linux__
#define CLRSCR "clear"
#else
#define CLRSCR "clear"
#endif

/*
 * 
 */

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
    int statistique[4];
} serpent;


void tournerDroite(char table[], int* largeur, serpent* monSerpent, int *avancement) {
    switch ((*monSerpent).sens) {
			// Exemple suite, appel de cette fonction pour le serpent
			// qui se deplace horizontalement et à gauche : (case 60 :)
			// et qui ne peut ni avancer ni tourner à gauche
			// au depart on verifie si la case au dessus de sa tete (cad table(tete-nbColonnes))
			// Si (if) elle est vide, on met dans table(tete-nbColonnes) un '^'
			// on met a jour les caracteristiques du tableau, tete taille et statistique
			// et on met la variable de controle de la boucle (avancement) en Vrai
			// Sinon (else), ce serpent est bloque
        case 60 :
            if (table[(*monSerpent).position-(*largeur)]==' ') { // avancement possible
                table[(*monSerpent).position-(*largeur)]=94;
                (*monSerpent).position -=(*largeur);
                (*monSerpent).sens = 94;
                (*monSerpent).taille++;
                (*monSerpent).statistique[0]++;
                (*avancement) = 1;
                break;
            }
            else { // avancement possible {
                break;
            }
        case 62 :
            if (table[(*monSerpent).position+(*largeur)]==' ') { // avancement possible
                table[(*monSerpent).position+(*largeur)]=118;
                (*monSerpent).position +=(*largeur);
                (*monSerpent).sens = 118;
                (*monSerpent).taille++;
                (*monSerpent).statistique[1]++;
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
                (*monSerpent).statistique[2]++;
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
                (*monSerpent).statistique[3]++;
                (*avancement) = 1;
                break;
            }
            else { // avancement possible
                break;
            }
    }
}


void tournerGauche(char table[], int* largeur, serpent* monSerpent, int *avancement) {
    switch ((*monSerpent).sens) {
			// Exemple suite, appel de cette fonction pour le serpent
			// qui se deplace horizontalement et à gauche : (case 60 :)
			// et qui n'arrive pas a avancer
			// au depart on verifie si la case au dessous de sa tete (cad table(tete+nbColonnes))
			// Si (if) elle est vide, on met dans table(tete+nbColonnes) un 'v'
			// on met a jour les caracteristiques du tableau, tete taille et statistique
			// et on met la varible de controle de la boucle (avancement) en Vrai
			// Sinon (else), on appel la fonction tournerDroite pour ce serpent
        case 60 :
            if (table[(*monSerpent).position+(*largeur)]==' ') { // avancement possible
                table[(*monSerpent).position+(*largeur)]=118;
                (*monSerpent).position +=(*largeur);
                (*monSerpent).sens = 118;
                (*monSerpent).taille++;
                (*monSerpent).statistique[1]++;
                (*avancement) = 1;
                break;
            }
            else { // avancement possible
                tournerDroite(table, largeur, monSerpent, avancement);
                break;
            }
        case 62 :
            if (table[(*monSerpent).position-(*largeur)]==' ') { // avancement possible
                table[(*monSerpent).position-(*largeur)]=94;
                (*monSerpent).position -=(*largeur);
                (*monSerpent).sens = 94;
                (*monSerpent).taille++;
                (*monSerpent).statistique[0]++;
                (*avancement) = 1;
                break;
            }
            else { // avancement possible
                tournerDroite(table, largeur, monSerpent, avancement);
                break;
            }
        case 94 :
            if (table[(*monSerpent).position-1]==' ') { // avancement possible
                table[(*monSerpent).position-1]=60;
                (*monSerpent).position -=1;
                (*monSerpent).sens = 60;
                (*monSerpent).taille++;
                (*monSerpent).statistique[3]++;
                (*avancement) = 1;
                break;
            }
            else { // avancement possible
                tournerDroite(table, largeur, monSerpent, avancement);
                break;
            }
        case 118 :
            if (table[(*monSerpent).position+1]==' ') { // avancement possible
                table[(*monSerpent).position+1]=62;
                (*monSerpent).position +=1;
                (*monSerpent).sens = 62;
                (*monSerpent).taille++;
                (*monSerpent).statistique[2]++;
                (*avancement) = 1;
                break;
            }
            else { // avancement possible
                tournerDroite(table, largeur, monSerpent, avancement);
                break;
            }
    }
	
}


void avancer(char table[], int* largeur, serpent* monSerpent, int *avancement) {
    switch ((*monSerpent).sens) {
			// Exemple,
			// si le serpent se deplace horizontalement et à gauche : (case 60 :)
			// si (if) la case precedent dans la table (cad table(teteSerpent-1))
			// on met un '<' dans cette case et on affecte le numero de la case
			// à la tete du serpent, on incremente sa taille, maj du
			// tableau de ses statistiques des deplacments
			// et on met la varible de controle de la boucle (avancement) en Vrai
			// Sinon(else) on appelle la fonction tournerGauche
        case 60 :
            if (table[(*monSerpent).position-1]==' ') { // avancement possible
                table[(*monSerpent).position-1]=60;
                (*monSerpent).position -=1;
                (*monSerpent).taille++;
                (*monSerpent).statistique[3]++;
                (*avancement) = 1;
                break;
            }
            else {// avancement possible
                tournerGauche(table, largeur, monSerpent, avancement);
                break;
            }
        case 62 :
            if (table[(*monSerpent).position+1]==' ') { // avancement possible
                table[(*monSerpent).position+1]=62;
                (*monSerpent).position +=1;
                (*monSerpent).taille++;
                (*monSerpent).statistique[2]++;
                (*avancement) = 1;
                break;
            }
            else {// avancement possible
                tournerGauche(table, largeur, monSerpent, avancement);
                break;
            }
        case 94 :
            if (table[(*monSerpent).position-(*largeur)]==' ') { // avancement possible
                table[(*monSerpent).position-(*largeur)]=94;
                (*monSerpent).position -=(*largeur);
                (*monSerpent).taille++;
                (*monSerpent).statistique[0]++;
                (*avancement) = 1;
                break;
            }
            else { // avancement possible
                tournerGauche(table, largeur, monSerpent, avancement);
                break;
            }
        case 118 :
            if (table[(*monSerpent).position+(*largeur)]==' ') { // avancement possible
                table[(*monSerpent).position+(*largeur)]=118;
                (*monSerpent).position +=(*largeur);
                (*monSerpent).taille++;
                (*monSerpent).statistique[1]++;
                (*avancement) = 1;
                break;
            }
            else { // avancement possible
                tournerGauche(table, largeur, monSerpent, avancement);
                break;
            }
    }
	
}


// Cette fonction prend les adresses de la table des casses, largeur
// table des serpents, nombre de serpents, variable de controle de la fin de la simulation
void deplacementSerpent(char table[], int* largeur, 
						serpent tableSerpent[], int nbSerpent, int* avancement) {
	
    int i;
    // Pour les serpents on appel la fonction pour les avancer
    for (i=0; i<nbSerpent; i++) {
        avancer(table, largeur, &tableSerpent[i], avancement);
    }
	
}

// Fonction d'attente prenant un argument un nombre de milliseconde
void attente(unsigned int tps_att) {
    unsigned int f = clock();
    unsigned int tps_clock = 0;
	
    tps_clock = tps_att * CLOCKS_PER_SEC/1000;
    while (clock()<f+tps_clock) {
    }
}

void affichage(char table[], int* nbLigne, int* nbColonne) {
	
    int i, j;
	
    //system("PAUSE");
    system(CLRSCR);
	
    for (i=0; i<(*nbLigne); i++) {
        // En parcours le tableau 1D pour chaque nbColonne
        // On fait un retour chariot
        for (j=i*(*nbColonne); j<((i+1)*(*nbColonne)); j++) {
			printf("%c ", table[j]);
        }
        printf("\n");
    }
}



int main(int argc, char** argv) {
	
    // Declaration des Variables
    int largeur, hauteur, nb_Total, nbSerpent, partieRemplie;
    int i, j, k, nbCaseVides, nbCaseVidesRestant;
    int tete, caseTete, sens, dureeAttente;
    int versDir[4] = {94, 118, 62,60};
    int avancement = 1;
    int statistiquesDirection[4]={0,0,0,0};
    partieRemplie = 0;
	
    srand(time(NULL)); // pour l'initialisation du nombre aleatoire
	
    // Verification du nombre d'arguments pour continuer
    printf("nombre d'arguments saisis est : %d \n", (argc-1));
    if (argc!=4) {
        printf("Vous devez entre largeurxhauetr, plus nombre de serepents \n");
        printf("plus la durre de rafraichissment de l'animation en ms \n");
        printf("Total d'arguements 3 \n");
        return (EXIT_SUCCESS);
    }
	
    sscanf(argv[1], "%dx%d", &largeur, &hauteur);
    nb_Total = largeur * hauteur;
    sscanf(argv[2], "%d", &nbSerpent);
    serpent tableSerpent[nbSerpent];
    sscanf(argv[3], "%d", &dureeAttente);
	
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
	
    system("CLS");
    affichage(table, &hauteur, &largeur); // test affichage du table 2D
	
    // creation des serpents
    for (i=0; i<nbSerpent; i++) {
        // Pour chaque serpent, tirage aleatoire sans remise de la case de depart
        // En utilidsant un tableau ntermediaire contenant, au depart,
        // les numeros des cases vides
        caseTete = (int) ((double) rand() / RAND_MAX * (nbCaseVides-i));
        tete = casseVides[caseTete];
        casseVides[caseTete] = casseVides[nbCaseVides-1-i];
        casseVides[nbCaseVides-1-i] = tete;
        // Tirage aleatoire du sens du serpent au depart
        sens = versDir[(int) ((double) rand() / RAND_MAX * (3 + 1))];
        tableSerpent[i].position = tete;
        tableSerpent[i].sens = sens;
        tableSerpent[i].taille = 1;
        table[tete] = (char) sens;
        // Initialisation du tableau statistique du tableau
        tableSerpent[i].statistique[0] = tableSerpent[i].statistique[1] = 0;
        tableSerpent[i].statistique[2] = tableSerpent[i].statistique[3] = 0;
        switch (sens) {
            case 0 :
                tableSerpent[i].statistique[0]=1;
                break;
            case 1:
                tableSerpent[i].statistique[1]=1;
                break;
            case 2:
                tableSerpent[i].statistique[2]=1;
                break;
            case 3:
                tableSerpent[i].statistique[3]=1;
                break;
        }
    }
	
    // Deplacement des serpents
    affichage(table, &hauteur, &largeur); // test affichage du table 2D
	
    i=0;
    do {
        // pour garantir l'arret de la boucle
        avancement = 0;
        i++;
        affichage(table, &hauteur, &largeur); // test affichage du table 2D
        deplacementSerpent(table, &largeur, tableSerpent, nbSerpent, &avancement);
        attente(dureeAttente);
		
    } while (avancement);
	
    printf("\n Fin du Jeu...\n");
    printf("\n Partie des Statistiques...\n");
    for (i=0; i<nbSerpent; i++) {
        partieRemplie += tableSerpent[i].taille;
        statistiquesDirection[0] += tableSerpent[i].statistique[0];
        statistiquesDirection[1] += tableSerpent[i].statistique[1];
        statistiquesDirection[2] += tableSerpent[i].statistique[2];
        statistiquesDirection[3] += tableSerpent[i].statistique[3];
    }
    printf("Le plateau est rempli a %d / %d dont : \n", partieRemplie, (largeur-2)*(hauteur-2));
    printf("\t - %d vers '^' \n",statistiquesDirection[0]);
    printf("\t - %d vers 'v' \n",statistiquesDirection[1]);
    printf("\t - %d vers '>' \n",statistiquesDirection[2]);
    printf("\t - %d vers '<' \n",statistiquesDirection[3]);
	
    for (i=0; i<nbSerpent; i++) {
        printf("Le serpent numero %d a rempli %d / %d dont :\n", i+1, tableSerpent[i].taille,partieRemplie);
        printf("\t - %d vers '^' \n",tableSerpent[i].statistique[0]);
        printf("\t - %d vers 'v' \n",tableSerpent[i].statistique[1]);
        printf("\t - %d vers '>' \n",tableSerpent[i].statistique[2]);
        printf("\t - %d vers '<' \n",tableSerpent[i].statistique[3]);
    }
	
    
    return (EXIT_SUCCESS);
}




