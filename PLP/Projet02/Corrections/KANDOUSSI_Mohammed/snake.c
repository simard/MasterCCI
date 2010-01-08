/* Mohamemd KANDOUSSI Master 2 CCI, TP test 2*/


# ifdef __linux__
# define CLRSCR "clear "
# else
# define CLRSCR "clr"
# endif

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef enum direction {

  DROITE=62,
  GAUCHE=60,
  HAUT=94,
  BAS=118,

}Edirection;


typedef struct serpent_t {

  int x;
  int y;
  char d;
  char g;
  char h;
  char b;
}serpent_t;

/*les fonctions qui permettent de récuperer les coordonnées et les positions des serpents*/

int getPositionX(struct serpent_t S)
{
	return S.x;
}
int getPositionY(struct serpent_t S)
{
	return S.y;
}
char getDirD(struct serpent_t S)
{
	return S.d;
}
char getDirG(struct serpent_t S)
{
	return S.g;
}
char getDirH(struct serpent_t S)
{
	return S.h;
}
char getDirB(struct serpent_t S)
{
	return S.b;
}

system (CLERSCR);

void initialisation(char tab[],int hauteur,int largeur);

void affichage (char tab[], int largeur, int hauteur);

void attendre(int frequence);

int main ( int argc , char ** argv)

{
  
  int largeur=0;
  int hauteur=0;
  int nb_serpent=0;
  int posx = 0;
  int posy = 0;
  char tab[largeur*hauteur];
  
/*sscanf retourne les valeur des arguments*/

  sscanf(argv[1],"%dx%d",&largeur,&hauteur);
  sscanf(argv[2],"%d",&nb_serpent);

  initialisation(tab,largeur,hauteur);
  
  affichage(tab,largeur,hauteur);
  /*rand place aléatoirement les serpents*/
  
  Edirection rdirection = ( unsigned int)( ( double ) rand\
() / ( ( double ) RAND_MAX + 1.0 ) * 4.0 );

  serpent_t cordonee; 
  
  /* les rands permettent de placer les coordonnees des serpents à l'intérieur du cadre des #*/
  
  cordonee.x = (rand()%(largeur+2)+1);
  cordonee.y = (rand()%(hauteur+2)+1);

  posx = getPositionX(cordonee);      
  posy = getPositionY(cordonee); 
  
  /* le switch permet l'affichage du déplacement des serpents à partir de la postion initiale donnée par le rand   */
  
  int k=1;  
  
  for (k;k<=nb_serpent;k++){
  switch (rdirection ){
  case GAUCHE:
      while(posx<largeur+2){
        tab[posx]=60;                    	
       printf("%c",tab[posx] );
       posx++;
       attendre(5);}
      break;

 case DROITE:
       while (posx>0){
	   tab[posx]=62;                    	
       printf("%c",tab[posx] );
         posx--;
         attendre(5);}
       break;

 case HAUT :
      while (posy<hauteur+2){
         tab[posy]=94;                    	
         printf("%c",tab[posy] );
          posy++;
          attendre(5);}
      break;

 case BAS:
   while (posy>0){
        tab[posx]=118;                    	
        printf("%c",tab[posy] );
        posy--;
	attendre(5);}
   break;
 }
 } 
  system("PAUSE");	
  return 0;
}

/*je voulais créer une fonction qui remplace les espaces avec le nombre des serpents rentrés au clavier*/

void initialisation(char tab[],int hauteur,int largeur)
{
  int i=0;
  for(i=0;i<hauteur*largeur;i++)
    {
      tab[i]=' ';
    }
} 

void affichage (char tab[] , int largeur , int hauteur){

  int i = 0;
  int j = 0;

  /* boucle pour afficher la premiere ligne des # */

  for(i=0;i<largeur+2;i++){

    printf("#");
  }
   printf("\n");



  for (i=0; i<hauteur;i++){

    printf("#");

    for (j=0;j<largeur; j++){


      printf("%c",tab[ (i*largeur) + j ]);
     
  }

     printf("#");

    printf("\n");
  }


  /* boucle pour afficher la derniere ligne des # */

 for(i=0;i<largeur+2;i++){

    printf("#");
   
  }
 printf("\n");

}


void attendre(int frequence)
{
clock_t fin;
fin=clock()+ frequence *(CLOCKS_PER_SEC/1000);
while (clock()<fin) {;}
}

