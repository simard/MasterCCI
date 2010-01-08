
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>

/* Déclaration des systèmes d'exploitation */

# ifdef __linux__
# define CLRSCR " clear "
# else
# define CLRSCR " cls"
# endif




enum Direction {
     HAUT=94,
     BAS=118,
     DROITE=62,
     GAUCHE=60};

/*** Structure pour définir la tete du serpent***/

 typedef struct{
   int xpos,ypos;
   enum Direction sens;
 }serpent;
 

/* Declaration des fonctions du programme */

void init_environnement(unsigned int colonne ,unsigned int ligne, char tab[]); 
void init_tableau( unsigned int colonne , unsigned int ligne, char tab[]);
void attente(int t_attente);

int depl_sens_haut( unsigned int colonne , unsigned int ligne ,serpent *serp, char tab[]);
int depl_sens_bas( unsigned int colonne , unsigned int ligne ,serpent *serp, char tab[]);
int depl_sens_droite( unsigned int colonne , unsigned int ligne,serpent *serp, char tab[]);
int depl_sens_gauche( unsigned int colonne , unsigned int ligne ,serpent *serp, char tab[]);


/* Programme principale */

int main (int argc , char** argv){

   int ilargeur,ihauteur,nbserpents,temps_attente;



 /* recuperation des arguments du jeu */
 sscanf (argv[1], "%d*%d*%d*%d", &ilargeur,&ihauteur,&nbserpents,&temps_attente);
 
serpent stab[nbserpents];

/* création du cadre du jeu */

 char cEchiquier [ihauteur*ilargeur];
 int blocage [nbserpents];
 int t_blocage=0;
 int t;
 for(t=0; t < nbserpents; t++){
          blocage[t]=0;
          }

init_tableau( ihauteur, ilargeur, cEchiquier);

/* Generation et position des testes des serpents */

 int k,dir;
 srand(time(NULL));

 for(k=0;k<nbserpents;k++){

   stab[k].xpos= rand()%ihauteur ;
   stab[k].ypos= rand()%ilargeur;
   dir=rand()%3;

/*** le sens de la direction du déplacement des serpents ****/

    switch(dir)
      {
      case 0 : stab[k].sens=HAUT; 
	break;
      case 1 : stab[k].sens=BAS; 
	break;
      case 2 : stab[k].sens=DROITE; 
	break;
      case 3 : stab[k].sens=GAUCHE; 
	break;
      }

   cEchiquier[stab[k].xpos*ilargeur+stab[k].ypos]=stab[k].sens; /* Placement du serpent dans le tableau d affichage */
 }

 init_environnement( ihauteur, ilargeur,cEchiquier);    /* affichage du tableau*/
 
 while(t_blocage != nbserpents){      /* teste le blocage des serpents */

   for(k=0;k<nbserpents;k++){             /* boucle gerant les deplacements des serpents */
                            switch(stab[k].sens){
                                        case HAUT : blocage[k]=depl_sens_haut(ihauteur,ilargeur,&stab[k],cEchiquier);
                                        break;
                                        case BAS: blocage[k]=depl_sens_bas(ihauteur,ilargeur,&stab[k],cEchiquier) ;
                                        break;
                                        case DROITE : blocage[k]=depl_sens_droite(ihauteur,ilargeur,&stab[k],cEchiquier) ; 
                                        break;
                                        case GAUCHE : blocage[k]=depl_sens_gauche(ihauteur,ilargeur,&stab[k],cEchiquier);
                                        break;
                                        }
                     }
                      int t;
                      t_blocage=0;
                      for(t=0; t < nbserpents; t++){
			t_blocage=t_blocage+blocage[t]; /* calcul de t_blocage */
                               }
		      attente(temps_attente); /* attendre 50ms */
		      system( CLRSCR );        /* effacement de l'ecran */
                      init_environnement( ihauteur, ilargeur,cEchiquier); 

                     }

  /* calcul des statisques du programme */

 int gh;
 int gl;
 int ha=0;
 int ba=0;
 int dr=0;
 int ga=0;
 int occupe=0;
 int vide=0;
 for(gh=0;gh<ihauteur;gh++){
           for(gl=0;gl<ilargeur;gl++){
                                      if(cEchiquier[gh*ilargeur+gl]==HAUT){
                                                                           occupe=occupe+1;
                                                                           ha=ha+1;
                                                                           }
                                          else if(cEchiquier[gh*ilargeur+gl]==BAS){
                                           occupe=occupe+1;
                                           ba=ba+1;
                                           }
                                      else if(cEchiquier[gh*ilargeur+gl]==DROITE){
                                           occupe=occupe+1;
                                           dr=dr+1;
                                           }
                                      else if(cEchiquier[gh*ilargeur+gl]==GAUCHE){
                                           occupe=occupe+1;
                                           ga=ga+1;
                                           }
                                      else if (cEchiquier[gh*ilargeur+gl]==' '){
                                           vide=vide+1;
                                           }
                                      }
           }

 float pourcentage,pourcentage1,pourcentage2,pourcentage3,pourcentage4;
 pourcentage= ((float)(occupe))/((float)(ilargeur*ihauteur))*100;
 printf("Le plateau est rempli a %0.1f (%d/%d) dont :\n",pourcentage,occupe,ilargeur*ihauteur);
 pourcentage1= ((float)(ha))/((float)(occupe))*100;   
 printf("- %0.1f '^' (%d/%d)\n",pourcentage1,ha,occupe);
 pourcentage2= ((float)(ba))/((float)(occupe))*100;
 printf("- %0.1f 'v' (%d/%d)\n",pourcentage2,ba,occupe);
 pourcentage3= ((float)(dr))/((float)(occupe))*100;
 printf("- %0.1f '>' (%d/%d)\n",pourcentage3,dr,occupe);
 pourcentage4= ((float)(ga))/((float)(occupe))*100;
 printf("- %0.1f '<' (%d/%d)\n",pourcentage4,ga,occupe);                                        
                                           
            
                          
 return 0;
   }                    
 /* fin de la fonction main du programme */
   
    
/* Definition de la fonction initialisation de l' environnement */
    
void init_environnement( unsigned int colonne , unsigned int ligne , char tab[]){
     int i,j;

 for(i=0;i<ligne+2;i++){
                        printf("#");
                        }
 printf("\n");
 for(i=0; i< colonne ; i++){
                         printf("#");
	                     for(j=0; j<ligne; j++){
                                                printf("%c",tab[i*ligne+j]);
                                                }
                         printf("#\n");
                         }
 for(i=0; i< ligne+2 ; i++){
                            printf("#");
                            }
 
 printf("\n");
}

/* definition de la fonction initialisation de tableau */

void init_tableau( unsigned int colonne, unsigned int ligne , char tab[]){
     int i;
     for(i=0; i< colonne*ligne ; i++){
                                      tab[i]=' ';
                                      }
}
     


/*  la fonction d'attente */

void attente(int t_attente)
{
      clock_t fin;
      fin = clock() + t_attente*CLOCKS_PER_SEC/1000;
      while(clock()<fin){}
      return ;
}

/* fonctions de deplacement */
/* fonction deplacement sens HAUT*/
int depl_sens_haut( unsigned int colonne , unsigned int ligne ,serpent *serp, char tab[]){
     int etat;
     if(tab[(serp->xpos-1)*ligne+(serp->ypos)]==' '){
                                    tab[(serp->xpos-1)*ligne+(serp->ypos)]=HAUT;
                                    serp->xpos=(serp->xpos)-1;
                                    serp->ypos=(serp->ypos);
                                    serp->sens=(serp->sens);
                                    etat=0;
                                    }
                                    else if(tab[(serp->xpos)*ligne+(serp->ypos)-1]==' '){
                                         tab[(serp->xpos)*ligne+(serp->ypos)-1]=GAUCHE;
                                         serp->xpos=(serp->xpos);
                                         serp->ypos=(serp->ypos)-1;
                                         serp->sens=GAUCHE;
                                         etat=0;
                                         }
                                         else if(tab[(serp->xpos)*ligne+(serp->ypos)+1]==' '){
                                              tab[(serp->xpos)*ligne+(serp->ypos)+1]=DROITE;
                                              serp->xpos=(serp->xpos);
                                              serp->ypos=(serp->ypos)+1;
                                              serp->sens=DROITE;
                                              etat=0;
                                              }
                                              else{
                                                   etat=1;
                                                   }
                                                   return etat;
                                    
     }
     
/* fonction deplacement sens BAS*/
int depl_sens_bas( unsigned int colonne , unsigned int ligne ,serpent *serp, char tab[]){
     int etat;
     if(tab[(serp->xpos+1)*ligne+serp->ypos]==' '){
                                    tab[(serp->xpos+1)*ligne+serp->ypos]=BAS;
                                    serp->xpos=(serp->xpos)+1;
                                    serp->ypos=(serp->ypos);
                                    serp->sens=(serp->sens);
                                    etat=0;
                                    }
                                    else if(tab[(serp->xpos)*ligne+(serp->ypos)+1]==' '){
                                         tab[(serp->xpos)*ligne+(serp->ypos)+1]=DROITE;
                                         serp->xpos=(serp->xpos);
                                         serp->ypos=(serp->ypos)+1;
                                         serp->sens=DROITE;
                                         etat=0;
                                         }
                                         else if(tab[(serp->xpos)*ligne+(serp->ypos)-1]==' '){
                                              tab[(serp->xpos)*ligne+(serp->ypos)-1]=GAUCHE;
                                              serp->xpos=(serp->xpos);
                                              serp->ypos=(serp->ypos)-1;
                                              serp->sens=GAUCHE;
                                              etat=0;
                                              }
                                              else{
                                                   etat=1;
                                                   }
                                                   return etat;
                                    
     }

/* fonction deplacement sens DROITE*/
int depl_sens_droite( unsigned int colonne , unsigned int ligne ,serpent *serp, char tab[]){
     int etat;
     if(tab[(serp->xpos)*ligne+(serp->ypos)+1]==' '){
                                    tab[(serp->xpos)*ligne+(serp->ypos)+1]=DROITE;
                                    serp->xpos=(serp->xpos);
                                    serp->ypos=(serp->ypos)+1;
                                    serp->sens=(serp->sens);
                                    etat=0;
                                    }
                                    else if(tab[((serp->xpos)-1)*ligne+(serp->ypos)]==' '){
                                         tab[((serp->xpos)-1)*ligne+(serp->ypos)]=HAUT;
                                         serp->xpos=(serp->xpos)-1;
                                         serp->ypos=(serp->ypos);
                                         serp->sens=HAUT;
                                         etat=0;
                                         }
                                         else if(tab[((serp->xpos)+1)*ligne+(serp->ypos)]==' '){
                                              tab[((serp->xpos)+1)*ligne+(serp->ypos)]=BAS;
                                              serp->xpos=(serp->xpos)+1;
                                              serp->ypos=(serp->ypos);
                                              serp->sens=BAS;
                                              etat=0;
                                              }
                                              else{
                                                   etat=1;
                                                   }
                                                   return etat;
                                    
     }
     
/* fonction deplacement sens GAUCHE*/
int depl_sens_gauche( unsigned int colonne , unsigned int ligne,serpent *serp, char tab[]){
     int etat;
     if(tab[(serp->xpos)*ligne+(serp->ypos)-1]==' '){
                                    tab[(serp->xpos)*ligne+(serp->ypos)-1]=GAUCHE;
                                    serp->xpos=(serp->xpos);
                                    serp->ypos=(serp->ypos)-1;
                                    serp->sens=(serp->sens);
                                    etat=0;
                                    }
                                    else if(tab[((serp->xpos)+1)*ligne+(serp->ypos)]==' '){
                                         tab[((serp->xpos)+1)*ligne+(serp->ypos)]=BAS;
                                         serp->xpos=(serp->xpos)+1;
                                         serp->ypos=(serp->ypos);
                                         serp->sens=BAS;
                                         etat=0;
                                         }
                                         else if(tab[((serp->xpos)-1)*ligne+(serp->ypos)]==' '){
                                              tab[((serp->xpos)-1)*ligne+(serp->ypos)]=HAUT;
                                              serp->xpos=(serp->xpos)-1;
                                              serp->ypos=(serp->ypos);
                                              serp->sens=HAUT;
                                              etat=0;
                                              }
                                              else{
                                                   etat=1;
                                                   }
                                                   return etat;
                                    
     }


