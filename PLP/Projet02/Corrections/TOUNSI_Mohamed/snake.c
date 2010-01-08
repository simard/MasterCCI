#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "hSnake.h"


int main (int argc, char **argv){

uint   Largeur=0; /*Largeur de la fenêtre  du jeu*/ 
uint   Hauteur=0; /*Hauteur de la fenêtre  du jeu*/

uint   nb_Serpents=0;/*nombre de sepents*/

uint   Temps=0; /*temps d'effacement de l'écran*/

t_Serpent Serpent;/*déclaration d'un Serpent*/
t_Cadre Cadre;/*déclaration du Cadre de l'environnement*/



/*récupération des données depuis la ligne de commande */
if (argc < 4){
      printf("\n il manque %d argument(s)...fin du programme\n\n", 4-argc);
      return 0;
              }
else {
      sscanf(argv[1],"%ux%u",&Largeur,&Hauteur);
      sscanf(argv[2],"%u",&nb_Serpents);
      sscanf(argv[3],"%u", &Temps);
    }

    Cadre.Largeur=Largeur;
    Cadre.Hauteur=Hauteur;



   /*déclaration d'un tableau unidimensionnel comme Environnement du jeu */
  /*le +2 c'est pour résever l'espace de dépalcement des serpents entre 1 et largeur (rep. Hauteur)*/ 
char Env[(Largeur+2)*(Hauteur+2)]; 

  /*état initial du tableau d'environnement*/
  Init_Env(Env,Cadre);

  /*choix d'une position au hasard d'un Serpent*/
  Serpent= Pos_Hasard( Cadre);

  /*état du tableau d'Environement Env après le choix d'un serpent*/
  Env_Serpent( Env ,Serpent, Cadre) ;
  
  /*Affichage de tableau d'Environnement*/
  Affiche(Env,Cadre);
  
  /*faire une pause*/
  Attendre(Temps);
  
  /*effacer l'écran*/
  system("clear");

  return 0; /*Fin du la fonction main*/

}





