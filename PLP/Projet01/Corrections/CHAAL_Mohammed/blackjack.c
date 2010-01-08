//MOHAMMED CHAAL
//MASTER CCI PROJET 1
//EXERCICE 2  LE BLACKJACK                      

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Enumeration des cartes avec leur nombre de points
enum poid_carte {as=11,deux=2,trois=3,quatre=4,cinq=5,six=6,sept=7,huit=8,
              neuf=9,dix=10,valet=10,dame=10,roi=10} point;

int main ()
{

  /* INITIALISATION*/              

  srand(time(NULL));
  int a;
  char jouer;
  int score_joueur=0;
  int score_banque;
  int rand_carte;
  int rand_coul;
  char *carte;
  char *couleur;  

  /* RENTREE DU PROGRAMME*/
  printf("Votre score est 0 \n");

  printf("Voulez-vous tirer une nouvelle carte [y/n] ? ");
  scanf("%s", &jouer);
  
  /*ON REPOSE LA QUESTION TANT QUE ON N'A PAS REPONDU CORRECTEMENT*/
  
  while (jouer!='y' && jouer!= 'n') {
    printf("Voulez-vous tirer une nouvelle carte [y/n] ? ");
    scanf("%s", &jouer);
    
  }
  
  /* Tant que le joueur veut tirer une carte le jeu continue */

  while (jouer=='y') {
   
    /* Tirage aleatoire d'une des 13 cartes du jeu. */                                  
    rand_carte=1+rand()%13;         
    
    /* Tirage aleatoire d'une des 4 couleurs de la carte (coeur, trefle, pique, carreau) */                           
    rand_coul=1+rand()%4;
      
    /* Affecter à la variable C1 le poid de la carte tiree suivant sa valeur d'apres
       l'enumeration poid_carte. */
    
    switch(rand_carte)
      {
      case 1 : carte="as"; 
	point=as;
	break;
      case 2 : carte="deux"; 
	point=deux;
	break;
      case 3 : carte="trois"; 
	point=trois;
	break;
      case 4 : carte="quatre"; 
	point=quatre;
	break;
      case 5 : carte="cinq"; 
	point=cinq;
	break;   
      case 6 : carte="six"; 
	point=six;
	break;
      case 7 : carte="sept"; 
	point=sept;
	break;
      case 8 : carte="huit"; 
	point=huit;
	break;
      case 9 : carte="neuf"; 
	point=neuf;
	break;
      case 10 : carte="dix"; 
	point=dix;
	break;
      case 11 : carte="valet"; 
	point=valet;
	break;
      case 12 : carte="dame"; 
	point=dame;
	break;
      case 13 : carte="roi"; 
	point=roi;
	break;
	
      }
    
    /* Trouver la couleur de la carte. */                  
    switch(rand_coul)
      {
      case 1 : couleur="coeur"; 
	break;
      case 2 : couleur="trefle"; 
	break;
      case 3 : couleur="pique"; 
	break;
      case 4 : couleur="carreau"; 
	break;
      }
    
    printf("Vous tirez la carte %s de %s\n",carte, couleur);

    /* Nouveau score du joueur.*/
    score_joueur +=point;
    
    /* Si le score du joueur est <= 21 le jeu continue sinon 
       le jeu est terminé (partie perdue). */
    
    if (score_joueur <= 21) {
      printf("Votre score est %d \n", score_joueur);
      
      printf("Voulez-vous tirer une nouvelle carte [y/n] ? ");
      scanf("%s", &jouer);
      
      while (jouer!='y' && jouer!= 'n') {
	printf("Voulez-vous tirer une nouvelle carte [y/n] ? ");
	scanf("%s", &jouer);
	
      }
    } else jouer='n';
    
  }
     
  if (jouer == 'n') {
    printf("Votre score est %d \n", score_joueur);
    
    /* Calcul du score de la banque (tirage aleatoire entre 16 et 21).*/
    score_banque=16+rand()%6;
    
    printf("Le score de la banque est %d \n", score_banque);
    
    /* Resultats: GAGNE, PERDU, EGALITE. */
    if (score_joueur < score_banque) {
      
      printf("PERDU\n");
    } else {
      if (score_joueur> score_banque) { 
        if ( score_joueur <= 21){
	  printf("GAGNE\n"); 
        } else printf("PERDU\n");
      } else printf("EGALITE\n"); 
    }
  }
  scanf("%d",&a);      
 
}
