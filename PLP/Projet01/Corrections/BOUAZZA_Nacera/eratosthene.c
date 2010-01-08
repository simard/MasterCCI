/* Projet01 de BOUAZZA Nacéra*/
/*EXO1*/

# include <stdio.h>
# include <stdlib.h>


int main (int argc , char ** argv)
{
int i;
int NbrMax;/*valeur max entrer par l'utilisateur*/
int j; 

scanf ("%d" , &NbrMax);

int tab[NbrMax]; /*vecteur contenant les nombres*/

  
  for (i=0 ; i< NbrMax ; i++ )  /*initialisation du tableau*/
    tab[i] = 0;
    
   
    for (i= 2 ; i <NbrMax; i++  ) {
    	for (j=2; j<i; j++) {
    		if (i%j == 0) {  /*j diviseur de i*/
    			tab[i] = 1; /* i n'est pas premier afficher i égale à1*/
    			break;  /* sortir de la boucle*/
    		}
    	}
    }
    
    
    
  for (i = 1 ; i <= NbrMax ; i++ )
   { 
    printf ("%d \t %d \n", i, tab[i]) ;   /*afficher le tableau*/     
   }  
      return 0; /* retourner les valeurs*/
      	
      }
      	

 
    
   

      

































