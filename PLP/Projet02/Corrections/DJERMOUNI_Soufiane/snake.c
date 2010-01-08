/* ---------------------- Mini-Projet N°2: Snake -----------------------------*/  
/*------------------ Nom : DJERMOUNI; Prénom : Soufiane ----------------------*/
/*----------------------------- M2 CCI ---------------------------------------*/                                            
          


/* ------------- Definition des bibliothèques ----------------*/
# include <stdio.h>
# include <stdlib.h> /* pour la fonction system () */
# include <string.h> /* pour utiliser les chaînes de caractères,*/
# include <time.h>    /* pour la fonction clock() */

/* ------------ Definition la fonction system() pour effacer l'écran sous les deux systèmes d'exploitation 'Linux' et 'Windows' ----------*/

# ifdef __linux__
# define CLRSCR " clear "
# else
# define CLRSCR " cls"
# endif

/* ------- Definition des structures ---------------------*/

 /* -------------1.Les directions -------------------------*/
typedef enum directions
 {
   haut=94,
   bas=118,
   droite=62,
   gauche=60
 }direction;

/* -------------2.Le serpent -----------------*/

 typedef struct serpents
 {
   int xposi,yposi; /* coordonnees de serpent*/
   direction sens;
 } serpent;
 
void affichage_cadre(unsigned int colonne ,unsigned int ligne, char tab[]); 
void init_tableau( unsigned int colonne , unsigned int ligne, char tab[]);
void attendre(int temps);

int depl_sens_haut( unsigned int colonne , unsigned int ligne ,serpent *serp, char tab[]);
int depl_sens_bas( unsigned int colonne , unsigned int ligne ,serpent *serp, char tab[]);
int depl_sens_droite( unsigned int colonne , unsigned int ligne,serpent *serp, char tab[]);
int depl_sens_gauche( unsigned int colonne , unsigned int ligne ,serpent *serp, char tab[]);


/* -------- Declaration des constantes ---------------*/

const unsigned int nbre_sens=4;  /* nombre de sens ou de deplacement*/

                              
							  /*___________________________________*/
							  

/*------------ ------------------Programme principale --------------------------------------------------*/

int main (int argc , char** argv)
{
  int largeur,hauteur,nbserpents,attente;

/*----------------- 1.recuperation des arguments de la commande---------------------------*/

  if (argc !=4)  /* test si le nombre d'arguments entres lors de l'exécution est egale a 4  */
    {
      printf("entrer tout vos arguments\n");
    }
  if(argv[0][0]=='.')
    {
      sscanf(argv[1],"%dx%d",&hauteur,&largeur);
      sscanf(argv[2],"%d",&nbserpents);
      sscanf(argv[3],"%d",&attente);
    }
 printf("largeur = %d\n",largeur);
 printf("hauteur = %d\n",hauteur);
 printf("nbserpents = %d\n",nbserpents);
 printf("temps d'attendre = %d\n",attente);
  
 /* ----------- 2. initialisation de l'environnement (tableau) qui permet l'enregistrement des serpents -------*/
 
 char tableau [hauteur*largeur];
 init_tableau( hauteur, largeur, tableau);

 /*------- initialisation de nombre de bloquage des serpents-------*/
  
 int bloque [nbserpents];
 int somme_bloque=0;
 int t;
 for(t=0; t < nbserpents; t++)
   {
    bloque[t]=0;
   }

 /* ----------------- 3.generation des directions aleatoires des serpents ----------*/
 
 serpent tab1[nbserpents]; /*declaration des la structure de tableau des serpents à afficher*/
 int k,sens1;
 srand(time(NULL));

 for(k=0;k<nbserpents;k++)
  {

   tab1[k].xposi= rand()%hauteur ; /* position du serpent suivent x */
   tab1[k].yposi= rand()%largeur;  /* position du serpent suivent y */
   sens1=rand()%3; /* sens de deplacement du serpent */

    /* Trouver le sens de direction */

    switch(sens1)
      {
      case 0 : tab1[k].sens=haut; 
	break;
      case 1 : tab1[k].sens=bas; 
	break;
      case 2 : tab1[k].sens=droite; 
	break;
      case 3 : tab1[k].sens=gauche; 
	break;
      }
   printf("%c\n",tab1[k].sens); 
   printf("%d\n",tab1[k].xposi);
   printf("%d\n",tab1[k].yposi);
   
   tableau[tab1[k].xposi*largeur+tab1[k].yposi]=tab1[k].sens; /* Placement des serpents dans l'environnement */
 }

 /* ------------------ 4. Affichage de cadre du tableau --------------------------------*/
 
 affichage_cadre( hauteur, largeur,tableau);   
 
 /* ------------------ 5. Deplacement des serpents dans l'environnement définie -------------------*/
 
 while(somme_bloque != nbserpents) /* on teste si les serpent sont tous bloqués */
   {      

    for(k=0;k<nbserpents;k++) /* cette branche permet  de gerer tous les deplacements des serpents */
	 {              
        switch(tab1[k].sens)
	   {
        case haut : bloque[k]=depl_sens_haut(hauteur,largeur,&tab1[k],tableau);
        break;
        case bas: bloque[k]=depl_sens_bas(hauteur,largeur,&tab1[k],tableau) ;
        break;
        case droite : bloque[k]=depl_sens_droite(hauteur,largeur,&tab1[k],tableau) ; 
        break;
        case gauche : bloque[k]=depl_sens_gauche(hauteur,largeur,&tab1[k],tableau);
        break;
       }
     }
 int t;
 somme_bloque=0;
 for(t=0; t < nbserpents; t++)
     {
	   somme_bloque=somme_bloque+bloque[t]; /* calcul de la variable somme_bloque */
     }
 attendre(attente); /* delai d'attente */
 system( CLRSCR );    /* effacer à chaque fois l'ecran*/
 affichage_cadre( hauteur, largeur,tableau); /* affichage du tableau a l'etat suivant (initial+1)*/

   } /* fin de while*/

  /* -------------6. statisques : pourcentage pour remplissage + chaque direction ------------------------------- */

 int gh; /* parcours en hauteur*/
 int gl; /* parcours en largeur*/
 int ha=0;  /* nombre de deplacement de la direction 'HAUT' */
 int ba=0;  /* nombre de deplacement de la direction 'BAS' */
 int dr=0;  /* nombre de deplacement de la direction 'DROITE' */
 int ga=0;  /* nombre de deplacement de la direction 'GAUCHE' */
 int occupe=0;  /* nombre de place occupé dans l'environnement(tableau) par tous les directions */
 int vide=0;    /* nombre de place vide*/
 
 for(gh=0;gh<hauteur;gh++){
           for(gl=0;gl<largeur;gl++){
                                      if(tableau[gh*largeur+gl]==haut){
                                                                           occupe=occupe+1;
                                                                           ha=ha+1;
                                                                           }
                                      else if(tableau[gh*largeur+gl]==bas){
                                           occupe=occupe+1;
                                           ba=ba+1;
                                           }
                                      else if(tableau[gh*largeur+gl]==droite){
                                           occupe=occupe+1;
                                           dr=dr+1;
                                           }
                                      else if(tableau[gh*largeur+gl]==gauche){
                                           occupe=occupe+1;
                                           ga=ga+1;
                                           }
                                      else if (tableau[gh*largeur+gl]==' '){
                                           vide=vide+1;
                                           }
                                      }
           }
 printf("%d\n",hauteur*largeur);
 printf("%d\n",occupe);
 printf("%d\n",vide);

 float pourcentage;  /* pourcenatge de remplissage de l'espace */
 float pourcentage1; /* pourcenatge de remplisssage de la direction HAUT*/
 float pourcentage2; /* pourcenatge de remplisssage de la direction BAS*/
 float pourcentage3; /* pourcenatge de remplisssage de la direction DROITE*/
 float pourcentage4; /* pourcenatge de remplisssage de la direction GAUCHE*/
 
 pourcentage= ((float)(occupe))/((float)(largeur*hauteur))*100;
 printf("Le plateau est rempli a %0.1f (%d/%d) dont :\n",pourcentage,occupe,largeur*hauteur);
 pourcentage1= ((float)(ha))/((float)(occupe))*100;   
 printf("- %0.1f '^' (%d/%d)\n",pourcentage1,ha,occupe);
 pourcentage2= ((float)(ba))/((float)(occupe))*100;
 printf("- %0.1f 'v' (%d/%d)\n",pourcentage2,ba,occupe);
 pourcentage3= ((float)(dr))/((float)(occupe))*100;
 printf("- %0.1f '>' (%d/%d)\n",pourcentage3,dr,occupe);
 pourcentage4= ((float)(ga))/((float)(occupe))*100;
 printf("- %0.1f '<' (%d/%d)\n",pourcentage4,ga,occupe);                  
                                           
                           
 return 0;
   }   /*---------------- Fin de programme principale ----------------*/
 
                                    /*___________________________________*/
  
/* --------------------------- Definitions des fonction utilisees ---------------------------------*/

/*------- 1.definition de la fonction affichage des  contours du tableau -------------*/    
void affichage_cadre( unsigned int colonne , unsigned int ligne , char tab[])
{
     int i,j;

 /*limite du cadrant superieur*/
 for(i=0;i<ligne+2;i++)
    {
      printf("#");
    }
 printf("\n");
 
 for(i=0; i< colonne ; i++)
  {
    printf("#");
	for(j=0; j<ligne; j++)
	   {
        printf("%c",tab[i*ligne+j]);
       }
       printf("#\n");
  }
 /* limites  du cadre inferieur*/
 
 for(i=0; i< ligne+2 ; i++)
    {
      printf("#");
    }
 
 printf("\n");
}

/* ------- 1.definition de la fonction d'initialisation du tableau---------- */


void init_tableau( unsigned int colonne, unsigned int ligne , char tab[])
{
     int i;
     for(i=0; i< colonne*ligne ; i++)
	  {
         tab[i]=' ';
      }
}
  
/* -----------3. Définition de la fonction d'attente --------*/

void attendre(int temps)
{
      unsigned int f = clock ();
	 unsigned int temps_clock =0;
	 temps_clock = temps * CLOCKS_PER_SEC/1000;
	 while (clock() < f + temps_clock) {}
	 return;
}

/* ---------- 4. tirage d'une valeur aleatoire --------------*/

/* int fonctrand ( unsigned int valeur)
{
    unsigned int resultat=0; 
    srand ( time( NULL ) );
    resultat= ( unsigned int)( ( double ) rand () / ( (double ) RAND_MAX ) * valeur ) + 1;
    return resultat;
} */


/* -------- 5.Definition des fonctions de deplacement ---------------*/

/* -------- 5.1 Deplacement sens HAUT -------------------*/

int depl_sens_haut( unsigned int colonne , unsigned int ligne ,serpent *serp, char tab[]){
     int etat;
     if(tab[(serp->xposi-1)*ligne+(serp->yposi)]==' '){
                                    tab[(serp->xposi-1)*ligne+(serp->yposi)]=haut;
                                    serp->xposi=(serp->xposi)-1;
                                    serp->yposi=(serp->yposi);
                                    serp->sens=(serp->sens);
                                    etat=0;
                                    }
                                    else if(tab[(serp->xposi)*ligne+(serp->yposi)-1]==' '){
                                         tab[(serp->xposi)*ligne+(serp->yposi)-1]=gauche;
                                         serp->xposi=(serp->xposi);
                                         serp->yposi=(serp->yposi)-1;
                                         serp->sens=gauche;
                                         etat=0;
                                         }
                                         else if(tab[(serp->xposi)*ligne+(serp->yposi)+1]==' '){
                                              tab[(serp->xposi)*ligne+(serp->yposi)+1]=droite;
                                              serp->xposi=(serp->xposi);
                                              serp->yposi=(serp->yposi)+1;
                                              serp->sens=droite;
                                              etat=0;
                                              }
                                              else{
                                                   etat=1;
                                                   }
                                                   return etat;
                                    
     }
     
/* -------- 5.2 Deplacement sens BAS -----------*/

int depl_sens_bas( unsigned int colonne , unsigned int ligne ,serpent *serp, char tab[]){
     int etat;
     if(tab[(serp->xposi+1)*ligne+serp->yposi]==' '){
                                    tab[(serp->xposi+1)*ligne+serp->yposi]=bas;
                                    serp->xposi=(serp->xposi)+1;
                                    serp->yposi=(serp->yposi);
                                    serp->sens=(serp->sens);
                                    etat=0;
                                    }
                                    else if(tab[(serp->xposi)*ligne+(serp->yposi)+1]==' '){
                                         tab[(serp->xposi)*ligne+(serp->yposi)+1]=droite;
                                         serp->xposi=(serp->xposi);
                                         serp->yposi=(serp->yposi)+1;
                                         serp->sens=droite;
                                         etat=0;
                                         }
                                         else if(tab[(serp->xposi)*ligne+(serp->yposi)-1]==' '){
                                              tab[(serp->xposi)*ligne+(serp->yposi)-1]=gauche;
                                              serp->xposi=(serp->xposi);
                                              serp->yposi=(serp->yposi)-1;
                                              serp->sens=gauche;
                                              etat=0;
                                              }
                                              else{
                                                   etat=1;
                                                   }
                                                   return etat;
                                    
     }

/* -------- 5.3 fonction deplacement sens DROITE ---------------*/

int depl_sens_droite( unsigned int colonne , unsigned int ligne ,serpent *serp, char tab[]){
     int etat;
     if(tab[(serp->xposi)*ligne+(serp->yposi)+1]==' '){
                                    tab[(serp->xposi)*ligne+(serp->yposi)+1]=droite;
                                    serp->xposi=(serp->xposi);
                                    serp->yposi=(serp->yposi)+1;
                                    serp->sens=(serp->sens);
                                    etat=0;
                                    }
                                    else if(tab[((serp->xposi)-1)*ligne+(serp->yposi)]==' '){
                                         tab[((serp->xposi)-1)*ligne+(serp->yposi)]=haut;
                                         serp->xposi=(serp->xposi)-1;
                                         serp->yposi=(serp->yposi);
                                         serp->sens=haut;
                                         etat=0;
                                         }
                                         else if(tab[((serp->xposi)+1)*ligne+(serp->yposi)]==' '){
                                              tab[((serp->xposi)+1)*ligne+(serp->yposi)]=bas;
                                              serp->xposi=(serp->xposi)+1;
                                              serp->yposi=(serp->yposi);
                                              serp->sens=bas;
                                              etat=0;
                                              }
                                              else{
                                                   etat=1;
                                                   }
                                                   return etat;
                                    
     }
     
/* -------- 5.4 fonction deplacement sens GAUCHE ------------------*/

int depl_sens_gauche( unsigned int colonne , unsigned int ligne,serpent *serp, char tab[]){
     int etat;
     if(tab[(serp->xposi)*ligne+(serp->yposi)-1]==' '){
                                    tab[(serp->xposi)*ligne+(serp->yposi)-1]=gauche;
                                    serp->xposi=(serp->xposi);
                                    serp->yposi=(serp->yposi)-1;
                                    serp->sens=(serp->sens);
                                    etat=0;
                                    }
                                    else if(tab[((serp->xposi)+1)*ligne+(serp->yposi)]==' '){
                                         tab[((serp->xposi)+1)*ligne+(serp->yposi)]=bas;
                                         serp->xposi=(serp->xposi)+1;
                                         serp->yposi=(serp->yposi);
                                         serp->sens=bas;
                                         etat=0;
                                         }
                                         else if(tab[((serp->xposi)-1)*ligne+(serp->yposi)]==' '){
                                              tab[((serp->xposi)-1)*ligne+(serp->yposi)]=haut;
                                              serp->xposi=(serp->xposi)-1;
                                              serp->yposi=(serp->yposi);
                                              serp->sens=haut;
                                              etat=0;
                                              }
                                              else{
                                                   etat=1;
                                                   }
                                                   return etat;
                                    
     }


