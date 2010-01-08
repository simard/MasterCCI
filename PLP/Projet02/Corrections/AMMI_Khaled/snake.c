/* Nom ,Prenom  :AMMI KHALED */
/*Projet N2 */


#include <stdio.h>
/* Utilisation de la librairie stdlib pour la commande clear */
#include <stdlib.h>
/* Utilisation de la librairie time pour la fonction clock */
#include <time.h>

/* Effacement de lEcran */
#ifdef __linux__
#define CLRSCR "clear"
#else
#define CLRSCR "clr"
#endif

/* Enumeration des directions avec leurs codes hexadicimals */
typedef enum eDirection {
	haut = 94,
	bas = 118,
	droite = 62,
	gauche = 60,
} direction;

/* Definition de la structure serpents :la position, la direction et le sens */
typedef struct serpents {
	int position;
	direction sens;
	int taille;
} serpent;

/* Definition des fonctions de deplacement */
/* Fonction deplacement sens Droite */
tournerDroite(char ctab[], int larg, int haut, serpent* S, int *av) {
	switch ((*S).sens) {
		case 60 :
			if (ctab[(*S).position-larg]==' ') { /*Est ce que je peux avancer*/
				ctab[(*S).position-larg]=94;
				(*S).position -=larg;
				(*S).sens = 94;
				(*S).taille++;
				(*av) = 1;
				break;
			}
			else 
			{
				break;
			}
		case 62 :
			if (ctab[(*S).position+larg]==' ') { /*Est ce que je peux avancer*/
				ctab[(*S).position+larg]=118;
				(*S).position +=larg;
				(*S).sens = 118;
				(*S).taille++;
				(*av) = 1;
				break;
			}
			else 
			{
				break;
			}
		case 94 :
			if (ctab[(*S).position+1]==' ') { /*Est ce que je peux avancer*/
				ctab[(*S).position+1]=62;
				(*S).position +=1;
				(*S).sens = 62;
				(*S).taille++;
				(*av) = 1;
				break;
			}
			else 
			{
				break;
			}
		case 118 :
			if (ctab[(*S).position-1]==' ') { /*Est ce que je peux avancer*/
				ctab[(*S).position-1]=60;
				(*S).position -=1;
				(*S).sens = 60;
				(*S).taille++;
				(*av) = 1;
				break;
			}
			else
			{
				break;
			}
	}
}

/* Fonction deplacement sens Gauche, et on teste a chaque fois si je peux avancer comme dans la fonction DEPLACEMENT SENS DROITE */
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
			else 
			{
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
			else 
			{ 
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
			else 
			{
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
			else
			{
				tournerDroite(ctab, larg, haut, S, av);
				break;
			}
	}
}

/* Fonction deplacement sens Avancer */
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
			else 
			{
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
			else
			{ 
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
			else
			{ 
				tournerGauche(ctab, larg, haut, S, av);
				break;
			}
	}
}

/* Definition de la fonction deplacement des Serpent */
deplacementSerpent(char ctab[], int larg, int haut, serpent tableSerpent[], int nbSerpent, int* av) {
	int i;
	for (i=0; i<nbSerpent; i++) {
		avancer(ctab, larg, haut, &tableSerpent[i], av);
	}
}

/* Definition de la fonction d'attente */
void attente(unsigned int tps_att) {
	unsigned int f = clock();
	unsigned int tps_clock = 0;

	tps_clock = tps_att * CLOCKS_PER_SEC/1000;
	while (clock()<f+tps_clock) {
	}
}

/* Definition de la fonction affichage de l'environnement */
affichage(char ctab[], int nbLigne, int nbColonne) {
	int i, j;
	system(CLRSCR);

	for (i=0; i<nbLigne; i++) {
		for (j=i*nbColonne; j<((i+1)*nbColonne); j++) {
			printf("%c ", ctab[j]);
		}
		printf("\n");
	}
}

int main(int argc, char** argv) {

	/* Declaration des variables */
	int larg, haut, nb_Total, nbSerpent;
	int i, j, k, nbCaseVides, nbCaseVidesRestant;
	char c;
	int tete, caseTete, sens, dureeAttente;
	int versDir[4] = {94, 118, 62,60};
	int av = 1;
	int gh; int gl;
	int ha=0;
	int ba=0;
	int dr=0;
	int ga=0;
	int occupe=0;
	int vide=0;
	float pourcentage,pourcentage1,pourcentage2,pourcentage3,pourcentage4;

	/* Initialisation du nombre aleatoire */
	srand(time(NULL)); 

	printf("Nombre dArgument :%d \n", (argc-1));
	if (argc!=4) {
		printf("Entrer: largeurXhauteur, Nombre des serepents, Duree de rafraichissment de lAnimation en ms \n");
		printf("Total dArguements 3 \n");
		return (EXIT_SUCCESS);
	}

	/* Recuperation des arguments de la commande */
	sscanf(argv[1], "%dx%d", &larg, &haut);
	printf("Largeur %d et Hauteur %d \n", larg, haut);
	nb_Total = larg * haut;
	sscanf(argv[2], "%d", &nbSerpent);
	serpent tableSerpent[nbSerpent];
	sscanf(argv[3], "%d", &dureeAttente);

	/* Declaration tableau 1D */   
	char ctab[larg*haut]; 
	nbCaseVides = (larg-2)*(haut-2);
	nbCaseVidesRestant = nbCaseVides;
	int tabCaseVides[nbCaseVides];

	/* Remplissage du tableau par des # */
	for (i=0; i<nb_Total; i++)
		ctab[i] = '#';
	/* Mettre des vide dans le noyau du tableau 2D */
	/* et creation du tableau des cases vides */
	k = 0;
	for (i=1; i<haut-1; i++) {
		for (j=i*larg+1; j<((i+1)*larg-1); j++) {
			ctab[j] = ' ';
			tabCaseVides[k] = j;
			k++;
		}
	}

	/* Test affichage du table 2D */
	affichage(ctab, haut, larg);
	/* Creation les serpents */
	for (i=0; i<nbSerpent; i++) {
		caseTete = (int) ((double) rand() / RAND_MAX * (nbCaseVides-i));
		tete = tabCaseVides[caseTete];
		tabCaseVides[caseTete] = tabCaseVides[nbCaseVides-1-i];
		tabCaseVides[nbCaseVides-1-i] = tete;
		sens = versDir[(int) ((double) rand() / RAND_MAX * (3 + 1))];
		tableSerpent[i].position = tete;
		tableSerpent[i].sens = sens;
		tableSerpent[i].taille = 1;
		ctab[tete] = (char) sens;
	}

	/* Deplacement des serpents */
	/* Test affichage du table 2D */
	affichage(ctab, haut, larg); 
	i=0;
	do {
		av = 0;
		i++;
		/* Test affichage du table 2D */
		affichage(ctab, haut, larg); 
		deplacementSerpent(ctab, larg, haut, tableSerpent, nbSerpent, &av);
		attente(dureeAttente);
	} while (av);

	printf("\n LE JEUX SNAKE EST FINIS MERCI POUR VOTRE ATTENTION \n");

	/* Calcul des cases occupees par chaque caractere */	
	for(gh=0;gh<haut;gh++){
		for(gl=0;gl<larg;gl++){
			if(ctab[gh*larg+gl]==94){
				occupe=occupe+1;
				ha=ha+1;
			}
			else if(ctab[gh*larg+gl]==118){
				occupe=occupe+1;
				ba=ba+1;
			}
			else if(ctab[gh*larg+gl]==62){
				occupe=occupe+1;
				dr=dr+1;
			}
			else if(ctab[gh*larg+gl]==60){
				occupe=occupe+1;
				ga=ga+1;
			}
			else if (ctab[gh*larg+gl]==' '){
				vide=vide+1;
			}
		}
	}

	printf("Le nombre total de cases est : %d\n",haut*larg);
	printf("Le nombre total de cases occupees est : %d\n",occupe);
	printf("Le nombre total de cases vides est : %d\n",vide);

	/* Calcul et afficahge des pourcentages des cases occipees par chaque caractere */
	pourcentage= ((float)(occupe))/((float)(larg*haut))*100;
	printf("Le plateau est rempli a %0.1f (%d/%d) dont :\n",pourcentage,occupe,larg*haut);

	pourcentage1= ((float)(ha))/((float)(occupe))*100;   
	printf("- %0.1f '^' (%d/%d)\n",pourcentage1,ha,occupe);

	pourcentage2= ((float)(ba))/((float)(occupe))*100;
	printf("- %0.1f 'v' (%d/%d)\n",pourcentage2,ba,occupe);

	pourcentage3= ((float)(dr))/((float)(occupe))*100;
	printf("- %0.1f '>' (%d/%d)\n",pourcentage3,dr,occupe);

	pourcentage4= ((float)(ga))/((float)(occupe))*100;
	printf("- %0.1f '<' (%d/%d)\n",pourcentage4,ga,occupe); 

	return 0;
	system("PAUSE");
	return (EXIT_SUCCESS);
}
