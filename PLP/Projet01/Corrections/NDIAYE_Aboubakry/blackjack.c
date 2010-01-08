#include<stdio.h>
#include <time.h>
#include RAND_MAX1 11
#include RAND_MAX2 4

typedef enum CouleurCarte{coeur,carreau, trèfle, pique} ColorCarte;
typedef enum ValeursCarte{deux=2,trois,quatre, cinq, six, sept, huit, neuf, valet=10,roi=10, dame=10,As }ValueCarte;


int main( int arc, char**argv)

{
  int Score, couleur, ScoreBanque=0, ScoreJoueur=0;
  char reponse;

  srand(time(NULL));
  ScoreBanque = ( int)( ( double ) rand () / ( (double )	\ RAND_MAX + 1.0 ) * 100.0 );

  printf("Votre score est 0");
  printf("Voulez vous tirer une nouvelle carte [y/n] ?");
  scanf("%c", &reponse);
  
  if(reponse=='y')
    {
      srand(time(NULL));//tirer une valeur pour la valeur de la carte, valeur inferieur ou egale à 21

      Score = ( int)( ( double ) rand () / ( (double )	\ RAND_MAX1 + 1.0 ) * 100.0 );
      ScoreJoueur +=Score;  // calculer le score
      
      srand(time(NULL));    // tirer une carte pour la couleur, valeur comprise entre 1 et 4
      couleur= ( int)( ( double ) rand () / ( (double )	\ RAND_MAX2 + 1.0 ) * 100.0 );
      
      switch(Score)

      case 2 
	if(couleur==1) {printf("Vous tirez un deux de coeur");}
        if(couleur==2) {printf("Vous tirez un deux de carreau");}
	if(couleur==3) {printf("Vous tirez un deux de tréfle");}
	if(couleur==4) {printf("Vous tirez un deux de pique");}
      
      case 3 
	if(couleur==1) {printf("Vous tirez un trois de coeur");}
        if(couleur==2) {printf("Vous tirez un trois de carreau");}
	if(couleur==3) {printf("Vous tirez un trois de tréfle");}
	if(couleur==4) {printf("Vous tirez un trois de pique");}
 
    case 4 
	if(couleur==1) {printf("Vous tirez un quatre de coeur");}
        if(couleur==2) {printf("Vous tirez un quatre de carreau");}
	if(couleur==3) {printf("Vous tirez un quatre de tréfle");}
	if(couleur==4) {printf("Vous tirez un quatre de pique");}

    case 5 
	if(couleur==1) {printf("Vous tirez un cinq de coeur");}
        if(couleur==2) {printf("Vous tirez un cinq de carreau");}
	if(couleur==3) {printf("Vous tirez un cinq de tréfle");}
	if(couleur==4) {printf("Vous tirez un cinq de pique");}

    case 6 
	if(couleur==1) {printf("Vous tirez un six de coeur");}
        if(couleur==2) {printf("Vous tirez un six de carreau");}
	if(couleur==3) {printf("Vous tirez un six de tréfle");}
	if(couleur==4) {printf("Vous tirez un six de pique");}
    case 7 
	if(couleur==1) {printf("Vous tirez un sept de coeur");}
        if(couleur==2) {printf("Vous tirez un sept de carreau");}
	if(couleur==3) {printf("Vous tirez un sept de tréfle");}
	if(couleur==4) {printf("Vous tirez un sept de pique");}
    case 8 
	if(couleur==1) {printf("Vous tirez un huit de coeur");}
        if(couleur==2) {printf("Vous tirez un huit de carreau");}
	if(couleur==3) {printf("Vous tirez un huit de tréfle");}
	if(couleur==4) {printf("Vous tirez un huit de pique");}
    case 9 
	if(couleur==1) {printf("Vous tirez un neuf de coeur");}
        if(couleur==2) {printf("Vous tirez un neuf de carreau");}
	if(couleur==3) {printf("Vous tirez un neuf de tréfle");}
	if(couleur==4) {printf("Vous tirez un neuf de pique");}
    case 10 
	if(couleur==1) {printf("Vous tirez un deux de coeur");}
        if(couleur==2) {printf("Vous tirez un deux de carreau");}
	if(couleur==3) {printf("Vous tirez un deux de tréfle");}
	if(couleur==4) {printf("Vous tirez un deux de pique");}
    case 11 
	if(couleur==1) {printf("Vous tirez un As de coeur");}
        if(couleur==2) {printf("Vous tirez un As de carreau");}
	if(couleur==3) {printf("Vous tirez un As de tréfle");}
	if(couleur==4) {printf("Vous tirez un As de pique");}
    }
  if(reponse=='n')
    {
      if(ScoreBanque<ScoreJoueur)
	{
	  printf("GAGNE");
	}
      else{printf("PERDU");}
    }


  return 0;
}
