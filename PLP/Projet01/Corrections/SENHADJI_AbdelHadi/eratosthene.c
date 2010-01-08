/*************** Projet01:Crible d'Erastothene********/
/***Nom SENHADJI*****/
/***Prenom ABDELHADI****/
/*** Date 16_10_2009****/

#include<stdio.h>
  int main (int argc ,char **argv )
    
  {
    printf(     "\n###      le crible derastosthene         ###\n ");  
    
    int i=0;             /* i: c'est un indice pour parcourir le tableau [2...N]  */
    
    int j=0;             /* J:c'est un indice pour parcourir le tableau [2..N] */
    
    int iTeste =1;     /* c'est une valeur =0 si le nombre entrée superieur ou egale a 2 et valeur = 1 si nombre inferieur       */  
    
    int N=0;      /* N c'est le nombre           */
    
    int iTmp =0;     /* tmp  :Variable contient les valeurs de 2 3 ...N      */
    
    int k =1;    /* k :c'est un indice pour parcourir le tableau */
    
  
    /* Tant que le nombre entrée < 2 demande à l'utilisateur de choisir un nombre superieur ou egale à 2*/
    
    
    while (iTeste) {
      printf ("Entrer un entier superieur ou egale a 2: ");
      scanf("%d",&N);
      
      if ( N>=2 ){
	
	iTeste=0;
      }
      else {
	printf ("il faux choisir un nombre entier superieur ou egale a 2: ");
	printf("\n" );
	iTeste=1;   
      }
      
    }
    
    
    int tab2[N-1];     /* tab2 : c'est un tableau de taille N-1 contient [ 2,3,4.........N] */
    int tab1[N-1];      /*tab1 : c'est un tableau de taille N-1 initialisé par les valeurs [2,.. N] et a la fin du programme  contient que les nombres premiers [2,3,1,5.....] */
    
   /* Cette boucle while c'est le remplissage de deux tableaux tab1 et tab2  [2,3....N] */
    
    while ( i< N ){
      tab1[i] = i+2;
      tab2[i] = i+2;
      i++;
  }
    
    
    
   for ( j=0; j<N-1;j++ ){
     printf("%d\n" ,tab1[j]);
     
   }
   
  i=0;
  
  while ( tab2[i]*tab2[i] <= N  ){       /*  C'est la condition de l'algorithme d'Eratosthene   */
    iTmp = tab2[i] ;                     /* au debut iTmp  contient la premiere valeur du tableau =2 apres 3 ....N  */
    
    
    
    for ( k = i+1; k <N-1; k++ ) {  /*  Dans cette boucle on teste tous les valeurs de notre tableau  si ils sont multiple de la valeur iTmp ou non  */  
      
      if (tab1[k] % iTmp == 0 ) {    /*  Est ce que case k du tableau est multiple de iTmp ou non ? */
	tab1[k]=1;                   /* Si oui on met 1 a la place du valeur de tab1[k],sinon on teste la valeur de tab1[k+1]...       */
      }
    }
    i++;  /* On incrimente i c'est à dire on passe la case suivante du tableau tab2[i+1]  et on fait le meme teste */   
    
  }
  
  
  
  
      printf("Voici le crible d'Eratosthene :" );
      for ( j=0; j<N-1;j++ ){
	printf(" %d\t" ,tab1[j]);
	
      }
      
      
      return 0;
      
  }
