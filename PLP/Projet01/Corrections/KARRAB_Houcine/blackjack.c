
/*************************************
 **************Mini projet 1 *********
 ***************Exercice 2 ***********
 *************Jeu de Blackjack *******
 *****réalisé par KARRAB Houcine******
 ******* Master CCI 2009-2010 ********
 ************************************/

//librairie permettant l'utilisation les fonctions printf et scanf
#include <stdio.h>

//Pour le tirage aléatoire
#include <stdlib.h>
#include <time.h>

// La fonction principale
int main(int argc, char *argv[]) {
  
  // Déclaration des variables
  char continuer='\0'; // choix du joueur
  int iScoreJoueur=0, iScoreBanque=0; // score du joueur et de la banque
  int tirageCarteJoueur, tirageCarteBanque; // nature des cartes tirees
  int nbreAs = 0; // nombre d'as tires
  
  enum typeCarteTiree {C1,C2,C3,C4,C5,C6,C7,C8,C9,C10,CVDR,
		       T1,T2,T3,T4,T5,T6,T7,T8,T9,TX,TVDR,
		       P1,P2,P3,P4,P5,P6,P7,P8,P9,PX,PVDR,
		       Ca1,Ca2,Ca3,CAa,Ca5,Ca6,Ca7,Ca8,Ca9,Ca10,CaVDR};//  VDR=Valet Dame Roi
  
  srand(time(NULL)); // pour l'initialisation du nombre aleatoire
  
  do {
    printf("Votre score est : %d\n", iScoreJoueur );
    
    while (continuer != 'y' && continuer != 'n'){
      printf("Voulez-vous tirer une nouvelle carte [y/n] ? ");
      scanf("%c",&continuer);
      getchar();
      printf("\n");
    }
    
    if (continuer=='n')
      break;
    
    if (continuer=='y')
      tirageCarteJoueur = (int) (1 + ((double) rand() / RAND_MAX * 52));//52 - 1 + 1
    
    switch (tirageCarteJoueur) {
    case 1 : printf("Vous tirez un as Coeur \n");
      nbreAs++;
      iScoreJoueur += 11;
      break;
    case 2 : printf("Vous tirez un 2 Coeur \n");
      iScoreJoueur += 2;
      break;
    case 3 : printf("Vous tirez un 3 Coeur \n");
      iScoreJoueur += 3;
      break;
    case 4 : printf("Vous tirez un 4 Coeur \n");
      iScoreJoueur += 4;
      break;
    case 5 : printf("Vous tirez un 5 Coeur \n");
      iScoreJoueur += 5;
      break;
    case 6 : printf("Vous tirez un 6 Coeur \n");
      iScoreJoueur += 6;
      break;
    case 7 : printf("Vous tirez un 7 Coeur \n");
      iScoreJoueur += 7;
      break;
    case 8 : printf("Vous tirez un 8 Coeur \n");
      iScoreJoueur += 8;
      break;
    case 9 : printf("Vous tirez un 9 Coeur \n");
      iScoreJoueur += 9;
      break;
    case 10 : printf("Vous tirez un 10 Coeur \n");
      iScoreJoueur += 10;
      break;
    case 11 : printf("Vous tirez un valet Coeur \n");
      iScoreJoueur += 10;
      break;
    case 12 : printf("Vous tirez un dame Coeur \n");
      iScoreJoueur += 10;
      break;
    case 13 : printf("Vous tirez un roi Coeur \n");
      iScoreJoueur += 10;
      break;
    case 14 : printf("Vous tirez un as trefle \n");
      iScoreJoueur += 11;
      nbreAs++;
      break;
    case 15 : printf("Vous tirez un 2 trefle \n");
      iScoreJoueur += 2;
      break;
    case 16 : printf("Vous tirez un 3 trefle \n");
      iScoreJoueur += 3;
      break;
    case 17 : printf("Vous tirez un 4 trefle \n");
      iScoreJoueur += 4;
      break;
    case 18 : printf("Vous tirez un 5 trefle \n");
      iScoreJoueur += 5;
      break;
    case 19 : printf("Vous tirez un 6 trefle \n");
      iScoreJoueur += 6;
      break;
    case 20 : printf("Vous tirez un 7 trefle \n");
      iScoreJoueur += 7;
      break;
    case 21 : printf("Vous tirez un 8 trefle \n");
      iScoreJoueur += 8;
      break;
    case 22 : printf("Vous tirez un 9 trefle \n");
      iScoreJoueur += 9;
      break;
    case 23 : printf("Vous tirez un 10 trefle \n");
      iScoreJoueur += 10;
      break;
    case 24 : printf("Vous tirez un valet trefle \n");
      iScoreJoueur += 10;
      break;
    case 25 : printf("Vous tirez un dame trefle \n");
      iScoreJoueur += 10;
      break;
    case 26 : printf("Vous tirez un roi trefle \n");
      iScoreJoueur += 10;
      break;
    case 27 : printf("Vous tirez un as pique \n");
      iScoreJoueur += 11;
      nbreAs++;
      break;
    case 28 : printf("Vous tirez un 2 pique \n");
      iScoreJoueur += 2;
      break;
    case 29 : printf("Vous tirez un 3 pique \n");
      iScoreJoueur += 3;
      break;
    case 30 : printf("Vous tirez un 4 pique \n");
      iScoreJoueur += 4;
      break;
    case 31 : printf("Vous tirez un 5 pique \n");
      iScoreJoueur += 5;
      break;
    case 32 : printf("Vous tirez un 6 pique \n");
      iScoreJoueur += 6;
      break;
    case 33 : printf("Vous tirez un 7 pique \n");
      iScoreJoueur += 7;
      break;
    case 34 : printf("Vous tirez un 8 pique \n");
      iScoreJoueur += 8;
      break;
    case 35 : printf("Vous tirez un 9 pique \n");
      iScoreJoueur += 9;
      break;
    case 36 : printf("Vous tirez un 10 pique \n");
      iScoreJoueur += 10;
      break;
    case 37 : printf("Vous tirez un valet pique \n");
      iScoreJoueur += 10;
      break;
    case 38 : printf("Vous tirez un dame pique \n");
      iScoreJoueur += 10;
      break;
    case 39 : printf("Vous tirez un roi pique \n");
      iScoreJoueur += 10;
      break;
    case 40 : printf("Vous tirez un as carreau \n");
      iScoreJoueur += 11;
      nbreAs++;
      break;
    case 41 : printf("Vous tirez un 2 carreau \n");
      iScoreJoueur += 2;
      break;
    case 42 : printf("Vous tirez un 3 carreau \n");
      iScoreJoueur += 3;
      break;
    case 43 : printf("Vous tirez un 4 carreau \n");
      iScoreJoueur += 4;
      break;
    case 44 : printf("Vous tirez un 5 carreau \n");
      iScoreJoueur += 5;
      break;
    case 45 : printf("Vous tirez un 6 carreau \n");
      iScoreJoueur += 6;
      break;
    case 46 : printf("Vous tirez un 7 carreau \n");
      iScoreJoueur += 7;
      break;
    case 47 : printf("Vous tirez un 8 carreau \n");
      iScoreJoueur += 8;
      break;
    case 48 : printf("Vous tirez un 9 carreau \n");
      iScoreJoueur += 9;
      break;
    case 49 : printf("Vous tirez un 10 carreau \n");
      iScoreJoueur += 10;
      break;
    case 50 : printf("Vous tirez un valet carreau \n");
      iScoreJoueur += 10;
      break;
    case 51 : printf("Vous tirez un dame carreau \n");
      iScoreJoueur += 10;
      break;
    case 52 : printf("Vous tirez un roi carreau\n");
      iScoreJoueur += 10;
      
    }
    
    if (iScoreJoueur>21 && nbreAs>0) {
      iScoreJoueur -= 10;
      nbreAs--;
    }
    
    if (iScoreJoueur>21 && nbreAs==0) {
      break;
    }
    
    continuer= '\0';
    
  } while (iScoreJoueur<21);  // Quand le score du joeur sera > 21 , on quitte la boucle voir = 21 ou non 
  
  if (iScoreJoueur >21) {
    tirageCarteBanque = (int) (16 + ((double) rand() / RAND_MAX * 6)); //  = 21 - 16 +1 
    iScoreBanque += tirageCarteBanque;
    printf("Score Banque est   : \t %d \n", iScoreBanque);
    printf(" votre score est : %d \t, PERDU \n", iScoreJoueur );
     
  }
  
  if (iScoreJoueur == 0) {
    printf("jouer  \n");
    
  }
  
  if (iScoreJoueur >= 1 && iScoreJoueur <= 21) {
    iScoreBanque = (int) (16 + ((double) rand() / RAND_MAX * 6));
	  
    if (iScoreBanque <= iScoreJoueur) {
      printf("Score Banque est   : \t %d \n", iScoreBanque);
      printf("votre score est : %d \t, GAGNE  \n", iScoreJoueur );
    }
    
    else {
      printf("Score Banque est   : \t %d \n", iScoreBanque);
      printf(" votre score est : %d \t, PERDU  \n", iScoreJoueur );
     
      
    }
  }
  
  return 0;
}
