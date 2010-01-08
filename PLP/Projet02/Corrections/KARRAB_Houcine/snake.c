/*************************************
 ************ Mini-projet 2 **********
 ************** Exercice 1 ***********
 ****************Jeu de Snake*********
 *****réalisé par KARRAB Houcine******
 ******* Master CCI 2009-2010 ********
 ************************************/

//librairie permettant l'utilisation les fonctions printf et scanf
#include <stdio.h>

//Pour le tirage aléatoire
#include <stdlib.h>
#include <time.h>

#include <math.h>
// Pour effacer l'écran
#ifdef    __linux__  
#define CLRSCR "clear"
#else
#define CLRSCR "clr"
#endif

//déclaration de type enuméré : type de direction 
typedef enum eDirection {  
  BAS = 86,
  HAUT = 94,
  DROITE = 62,
  GAUCHE = 60,
}tDirection;

//Déclaration de type structure : caractéristiques du serpent
typedef struct {
  int position;
  tDirection sens;
  int taille;
}tSerpent;

//Déclarations des prototypes des fonctions
void affichageCadre(char terrain[], int , int );
void tournerDroite(char terrain[], int , int , tSerpent*, int *);
void tournerGauche(char terrain[], int , int , tSerpent* , int *);
void avancer(char terrain[], int , int , tSerpent*, int *);
void deplacerSerpent(char terrain[], int , int,tSerpent terrainSerpents[], int, int*);
void attendre (unsigned int);	
int iArrondi(float);


// La fonction principale
int main(int argc, char** argv) {
  
  //Déclaration des variables
  int larg=0, haut=0, nbreSerpents=0;
  int i=0, j=0, k=0, p=0;
  int tete=0, posTete=0, sens=0, tempsAttente=0;
  int tabDir[4] = {94, 86, 62,60};
  int decalage = 1;
  tSerpent terrainSerpents[nbreSerpents];
  unsigned int nbreTotal=0;int nbreHaut=0; int nbreBas=0; int nbreGauche=0; int nbreDroite=0;int nbreVide=0;int nbreT=0;
  int surfacePlateau=0;
  double pourcRempli=0.0, pourcHaut=0.0, pourcBas=0.0, pourcGauche=0.0, pourcDroite=0.0;

  //a-Titre du programme
  printf("\n### Jeu de Snake ###\n");
  
  // pour l'initialisation du nombre aleatoire
  srand(time(NULL)); 
  
  //Vérification du nombre d'arguments.
  printf("nombre d'argument est égale à %d . \n", (argc-1));
  if (argc!=4) {
    printf("il faut entrer trois arguments (largxhaut, nbreSerpents et tempsAttente). \n");
    return 0;
  }
  
  //Lecture des arguments
  sscanf(argv[1], "%dx%d", &larg, &haut);
  sscanf(argv[2], "%d", &nbreSerpents);
  sscanf(argv[3], "%d", &tempsAttente);
  
  char terrain[larg*haut]; // declaration tableu 1D
  surfacePlateau = (larg-2)*(haut-2);
  
  int cases[surfacePlateau];
  
  // Remplissage du tableau cadre 
  for (i=0; i<(larg*haut); i++)
    terrain[i] = '#';
  
  // Remplissage du cadre par du vide
  for (i=1; i<haut-1; i++) {
    for (j=i*larg+1; j<((i+1)*larg-1); j++) {
      terrain[j] = ' ';
      cases[k] = j;
      k++;
    }
    }
  
  
  // Placer aléatoirement les serpents dans le terrain.
  for (i=0; i<nbreSerpents; i++) {
    posTete = (int) ((double) rand() / RAND_MAX * (surfacePlateau-i));
    tete = cases[posTete];
    cases[posTete] = cases[surfacePlateau-1-i];
    cases[surfacePlateau-1-i] = tete;
    sens = tabDir[(int) ((double) rand() / RAND_MAX * 4)];// 4 = 3 + 1
    terrainSerpents[i].position = tete;
    terrainSerpents[i].sens = sens;
    terrainSerpents[i].taille = 1;
    terrain[tete] = (char) sens;
  }
 
  
  // Animation
  i=0;
  do {
    decalage = 0;
    i++;
    affichageCadre(terrain, haut, larg); // test affichage du table 2D
    
    deplacerSerpent(terrain, larg, haut, terrainSerpents, nbreSerpents, &decalage);
    attendre(tempsAttente);
    
    system(CLRSCR);
    affichageCadre(terrain, haut, larg); // test affichage du table 2D
    } while (decalage);
  
  
  
  //Les statistiques.
  for(i=0;i<(haut*larg)-1 ;i++)
    {
      
      switch (terrain[i])
	{
	case HAUT:nbreHaut++;
	case BAS:nbreBas++;  
	case GAUCHE:nbreGauche++;
	case DROITE:nbreDroite++;
	}
    }
  
  surfacePlateau = (haut-2)*(larg-2);
  
 
  nbreTotal = nbreHaut + nbreBas + nbreGauche + nbreDroite;
  pourcRempli = ((double)nbreTotal / (double)surfacePlateau) * 100;
  p=iArrondi( pourcRempli );

  pourcHaut = (double)nbreHaut / (double) nbreTotal; 
  pourcBas = (double)nbreBas / (double) nbreTotal;
  pourcGauche = (double)nbreGauche / (double) nbreTotal;
  pourcDroite = (double)nbreDroite / (double) nbreTotal;
  
  
  printf("Le plateau est rempli à %.1lf (%d/100) dont : \n",pourcRempli,p);  
  printf("- %.2lf '^' (%u/%u)\n",(pourcHaut/pourcRempli)*100, nbreHaut,p );
  printf("- %.1lf 'v' (%u/%u)\n",(pourcBas/pourcRempli)*100, nbreBas,p);
  printf("- %.1lf '^' (%u/%u)\n",(pourcGauche/pourcRempli)*100, nbreGauche,p);
  printf("- %.1lf '^' (%u/%u)\n",(pourcDroite/pourcRempli)*100, nbreDroite,p);
  
  return 0;
}


//Définitions des fonctions
// tous ces fonctions retournent void => elles sont des procédures.
//Fonction pour afficher le cadre externe fomé par des "#".
void affichageCadre(char terrain[], int nbreLigne, int nbreColonne) {
 int i, j;
 int nbrligne;
 int nbrcolone;
 
 //Pour effacer l'écran
 system(CLRSCR);
 
 for (i = 0; i < nbreLigne; i++)
   {
     for (j = 0; j < nbreColonne; j++)
       {
	 printf("%c", terrain[i*nbreColonne+j]);
       }
     printf ("\n");
	  }
}


//Fonction pour tourner à droite
void tournerDroite(char terrain[], int larg, int haut, tSerpent* unSerpent, int *decalage) {
  switch (unSerpent->sens) {
  case GAUCHE :
      if (terrain[unSerpent->position-larg]==' ') {
	terrain[unSerpent->position-larg]=HAUT;
	unSerpent->position -=larg;
	unSerpent->sens = HAUT;
	unSerpent->taille++;
	(*decalage) = 1;
	break;
      }
      else { 
	break;
      }
  case DROITE :
    if (terrain[unSerpent->position+larg]==' ') {
      terrain[unSerpent->position+larg]=BAS;
      unSerpent->position +=larg;
      unSerpent->sens = BAS;
      unSerpent->taille++;
      (*decalage) = 1;
      break;
    }
    else { 
	      break;
    }
  case HAUT :
    if (terrain[unSerpent->position+1]==' ') { 
      terrain[unSerpent->position+1]=DROITE;
      unSerpent->position +=1;
      unSerpent->sens = DROITE;
      unSerpent->taille++;
      (*decalage) = 1;
      break;
    }
    else { 
      break;
    }
  case BAS :
    if (terrain[unSerpent->position-1]==' ') {
      terrain[unSerpent->position-1]=GAUCHE;
      unSerpent->position -=1;
      unSerpent->sens = GAUCHE;
      unSerpent->taille++;
      (*decalage) = 1;
      break;
    }
    else { 
      break;
    }
  }
}

//Fonction pour tourner à gauche
void tournerGauche(char terrain[], int larg, int haut, tSerpent* unSerpent, int *decalage) {
  switch (unSerpent->sens) {
  case GAUCHE :
    if (terrain[unSerpent->position+larg]==' ') { 
      terrain[unSerpent->position+larg]=BAS;
      unSerpent->position +=larg;
      unSerpent->sens = BAS;
      unSerpent->taille++;
      (*decalage) = 1;
      break;
    }
    else { 
      tournerDroite(terrain, larg, haut, unSerpent, decalage);
      break;
    }
  case DROITE :
    if (terrain[unSerpent->position-larg]==' ') { 
      terrain[unSerpent->position-larg]=HAUT;
      unSerpent->position -=larg;
      unSerpent->sens = HAUT;
      unSerpent->taille++;
      (*decalage) = 1;
      break;
    }
    else { 
      tournerDroite(terrain, larg, haut, unSerpent, decalage);
      break;
    }
  case HAUT :
    if (terrain[unSerpent->position-1]==' ') {
      terrain[unSerpent->position-1]=GAUCHE;
      unSerpent->position -=1;
      unSerpent->sens = GAUCHE;
      unSerpent->taille++;
      (*decalage) = 1;
      break;
    }
    else { 
      tournerDroite(terrain, larg, haut, unSerpent, decalage);
      break;
    }
  case BAS :
    if (terrain[unSerpent->position+1]==' ') {
      terrain[unSerpent->position+1]=DROITE;
      unSerpent->position +=1;
      unSerpent->sens = DROITE;
      unSerpent->taille++;
      (*decalage) = 1;
      break;
    }
    else {
      tournerDroite(terrain, larg, haut, unSerpent, decalage);
      break;
    }
  }
  
}

//Fonction pour avancer
void avancer(char terrain[], int larg, int haut, tSerpent* unSerpent, int *decalage) {
  switch ((*unSerpent).sens) {
  case GAUCHE :
    if (terrain[unSerpent->position-1]==' ') { 
      terrain[unSerpent->position-1]=GAUCHE;
      unSerpent->position -=1;
      unSerpent->taille++;
      (*decalage) = 1;
      break;
    }
    else {
      tournerGauche(terrain, larg, haut, unSerpent, decalage);
      break;
    }
  case DROITE :
    if (terrain[unSerpent->position+1]==' ') { 
      terrain[unSerpent->position+1]=DROITE;
      unSerpent->position +=1;
      unSerpent->taille++;
      (*decalage) = 1;
      break;
    }
    else {
      tournerGauche(terrain, larg, haut, unSerpent, decalage);
      break;
    }
  case HAUT :
    if (terrain[unSerpent->position-larg]==' ') { 
      terrain[unSerpent->position-larg]=HAUT;
      unSerpent->position -=larg;
      unSerpent->taille++;
      (*decalage) = 1;
      break;
    }
    else { 
      tournerGauche(terrain, larg, haut, unSerpent, decalage);
      break;
    }
  case BAS :
    if (terrain[unSerpent->position+larg]==' ') {
      terrain[unSerpent->position+larg]=BAS;
      unSerpent->position +=larg;
      unSerpent->taille++;
      (*decalage) = 1;
      break;
    }
    else { 
      tournerGauche(terrain, larg, haut, unSerpent, decalage);
      break;
    }
  }
  
}

//Fonction pour déplacer le serpent
void deplacerSerpent(char terrain[], int larg, int haut,
		     tSerpent terrainSerpents[], int nbreSerpents, int* decalage) {
  
  int i;
  for (i=0; i<nbreSerpents; i++) {
    avancer(terrain, larg, haut, &terrainSerpents[i], decalage);
  }
  
}

//Fonction d'attente pour voir clairement l'animation
void attendre (unsigned int tempsAttente) {
  unsigned int f = clock();
  unsigned int temps_clock = 0;
  temps_clock = tempsAttente*CLOCKS_PER_SEC / 1000;
  while (clock() < f + temps_clock);
  return;
}


// Fonction pour arrondir un nombre
int iArrondi(float fValeur)
{
  float fDecimal;
  int iResultat;
  
  if (fValeur<0)
    
    {
      fDecimal=fValeur-ceil(fValeur);
      if (fDecimal > -0.5)
	iResultat=ceil(fValeur);
      else
	iResultat=floor(fValeur);
    }
  else
    {
      fDecimal=fValeur-floor(fValeur);
      if (fDecimal< 0.5)
	iResultat=floor(fValeur);
      else
	iResultat=ceil(fValeur);
    }
  
  return iResultat;
}
