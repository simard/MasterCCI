
/*************************************
 ************ Mini-projet 1 **********
 ************** Exercice 1 ***********
 *********Crible d'Eratosthène******** 
 *****réalisé par KARRAB Houcine******
 ******* Master CCI 2009-2010 ********
 ************************************/

/*effectuer le crible d'Eratosthène (trouver les nombres premiers) sur tous les nombres
  entiers de l'intervalle [1,N].*/



//librairie permettant l'utilisation les fonctions printf et scanf
#include <stdio.h>

//librairie permettant l'utilisation de la  fonction  sqrt
# include <math.h>

//déclaration de type enuméré
typedef enum { 
  TRUE = 1, // vrai est explicitement un nom symbolique pour l'entier 1 
  FALSE = 0 // vrai est explicitement un nom symbolique pour l'entier 0
} BOOLEAN;


//définitions des constantes
const int     TAILLE_MAX = 1000000;

//déclaration des variables utilisées 
unsigned int iEntierN;
int i=0, j=0;


//fonction principale
int main( int argc , char ** argv )
{
  
  BOOLEAN cribleEratne[TAILLE_MAX];
  
  
  //a-Titre du programme
  printf("\n### Crible d'Eratosthène ###\n");
  
  printf( "Entrer un entier : " );
  scanf( "%u", &iEntierN);
  
  if ((iEntierN<2) || (iEntierN<=0)|| (iEntierN > TAILLE_MAX) )
    { 
      printf( "Il faut choisir un nombre entier superieur a 2.\n" );
      return 0;
    }
  
  
  else
    {
      printf( "Voici le crible d' Eratosthene jusqu'à l' entier %u \t \n", iEntierN);
      
      // 0 et 1 ne sont pas des nombres premiers!
      cribleEratne[0] =  cribleEratne[1] = FALSE;
      
      //initialisation du tableau
      for (i = 2; i<iEntierN; i++)
	cribleEratne[i] = TRUE;
      
      
      
      //Ici on utilise le fait qu'il suffit de tester les nombres jusqu'à sqrt(iEntierN) seulement.
      //i<(unsigned long)sqrt((double)iEntierN) 
      
      for (i = 2; i*i < iEntierN; i++)
	
	{ // rayer tous les multiples de i
	  for (j = 2; i*j < iEntierN; j++) 
	    cribleEratne[i*j] = FALSE;
	}
    }
  
  {
    for (i = 0; i < iEntierN; i++) 
      if ( cribleEratne[i] == TRUE)
	{
	  // On affiche les nombre premiers 
	  printf(" %d",i);
	  printf("\n");
	  if (!(++j % 5)) 
	    j = 0;
	  
	}
  }
  
  return 0;
}
