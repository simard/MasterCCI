/* définitions des différentes fonctions*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "hSnake.h"





/*pour initialiser le tableau d'environnement*/
void Init_Env(char Env[], t_Cadre Cadre){
  
uint   iL = 0, iH = 0; 

  for (iH = 0;  iH < Cadre.Hauteur+2;  iH++ ){
	for (iL = 0;  iL < Cadre.Largeur+2; iL++){
	  
	  /*pour remplir les bords*/
	  if(iH == 0  || iL == 0 
		      || iH == Cadre.Hauteur+1 
		      || iL == Cadre.Largeur+1)
	    
		  Env[iH*(Cadre.Largeur+2) +iL] = '#';
	  
	  else  /*pour remplir l'intérieur de l'Environnement*/  
		  Env[iH*(Cadre.Largeur+2) +iL] = ' ';
	  } 
        }

     }

/*remplir l'espace Env en présence d'un serpent*/
void Env_Serpent(char Env[], t_Serpent  Serpent, t_Cadre  Cadre){
uint   iL = 0, iH = 0; 

  for (iH = 0;  iH < Cadre.Hauteur+2;  iH++ ){
	for (iL = 0;  iL < Cadre.Largeur+2; iL++){

	   if(iH == 0 || iL == 0 
		      || iH == Cadre.Hauteur+1 
		      || iL == Cadre.Largeur+1)
	      Env[iH*(Cadre.Largeur+2) +iL] = '#'; /*pour remplir les bords*/
          
	   /*et pour se positionner sur la position choisi au hasard:*/
	  else if (iH  == Serpent.HSerpent  &&  iL == Serpent.LSerpent) 
	
	      Env[iH*(Cadre.Largeur+2) +iL]='>'; /*choix de la forme d'un serpent*/
      
	  else    
	      Env[iH*(Cadre.Largeur+2) +iL] = ' ';/*pour remplir le reste du Cadre*/
	  }
      }

    }




/*affichage du tableau d'Environnement*/
void Affiche(char Env[], t_Cadre Cadre){
  uint   k ; /*un nouveau indice pour parcourrir le tableau unidimensionnel*/

  for (k = 0; k < (Cadre.Largeur+2)*(Cadre.Hauteur+2); k++){
	/*le passage à une nouvelle ligne*/
	if( k%(Cadre.Largeur+2) == 0 ) {
	      printf("\n");
	  }

	      printf("%c",Env[k]);

  }
	      printf("\n");

} /*fin fonction Affiche*/

	
/*fonction pour simuler l'animation de sserpents*/
void Attendre (uint   ms) { 
    clock_t pause;
    
    pause =  clock()+CLOCKS_PER_SEC*ms/10; 
 
    while(clock() < pause) {};
    
    return;
}/* fin fonction Attendre*/



/*choix d'une position aléatoire d'un serpent dans le cadre*/
t_Serpent Pos_Hasard(t_Cadre Cadre){
  
  t_Serpent Serpent;
  
  srand(time(NULL));/* pour ne pas donner le même nombre aléatoire à chaque appel*/
  
  /*pour générer une valeur aléatoire entre 1 et Largeur*/
  Serpent.LSerpent=1+(uint)(rand() % Cadre.Largeur);
  
  /*pour générer une valeur aléatoire entre 1 et Hauteur*/
  Serpent.HSerpent=1+(uint)(rand() % Cadre.Hauteur);
  
  return Serpent;
}


/*pour se dépalcer à droite ...mais pas complète*/
void Mouv_Droite(char Env[], t_Serpent  Serpent, t_Cadre  Cadre){
uint   iL = 0, iH = 0; 
  for (iH = 0;  iH < Cadre.Hauteur+2;  iH++ ){
      for (iL = 0;  iL < Cadre.Largeur+2; iL++){

	  if(iH == 0  || iL == 0 
		      || iH == Cadre.Hauteur+1 
		      || iL == Cadre.Largeur+1)
	    Env[iH*(Cadre.Largeur+2) +iL] = '#';
	
	  else if (iH==Serpent.HSerpent && iL==Serpent.LSerpent)
	    Env[iH*(Cadre.Largeur+2) +iL]='>';

	  else    
	    Env[iH*(Cadre.Largeur+2) +iL] = ' ';
	  }
      }

}







