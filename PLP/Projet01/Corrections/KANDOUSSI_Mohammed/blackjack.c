// Mohammed KANDOUSSI MATER 2 CCI: exercice 2


#include <stdlib.h>
#include <time.h>
#include<stdlib.h>

/* d�claration d'une �num�ration valeur de la carte, et d'un ensemble d'�num�rateurs correspond � des valeurs entiers */
typedef  enum valeur { 
        
         
          2;
          3;
          4;
          5;
          6;
          7;
          8;
          9;
         10;
      valet=10;//d�finition d'un valet � 10
       dame=10;//d�finition d'une dame � 10
        roi=10;//d�finition du roi � 10
        as=11;
          }c_val;
          
/* d�claration d'une �num�ration couleur de la carte, et d'un ensemble d'�num�rateurs correspond � des valeurs entiers */

 typedef enum couleur{
           
           tr�fle;
           pique;
           carreau,
           coeur;
           }couleur_carte;
           
 int main (int argc, char ** argv)
 
 {
     enum valeur C1,C2,C3,C4,C5,C6,C7,C8,C9,C10,C11,C12,C13;/*d�finition de 13 variable de type enum couleur*/
     enum couleur Tr,Pi,Co,Ca; /* d�finition de 4 variable de type enum couleur */
     int carte =0;
     int somme=0;
     char c;
     char CARD [4][13]; // tableau bi-dimentionel pour les cartes 4 couleur de la carte et pour les 13 valeur
     
carte =int ((double)rand(time(NULL)) ((RAND_MAX)*11) /*fonction aleatoire qui permet le tirage des cartes*/
        
scanf ("%d\n",&carte);
enum c_val CARD [13]; /*on d�termine la valeur de la carte � partir d'enum */
enum couleur_carte


     
switch (c){

case 'y | n':
{
  while (somme<21){
      
     somme +=carte // on fait la somme des valeur de la carte tant que la somme est inf�rieur � 21
     printf("voulez-vous tirer une nouvelle carte [y/n]?\n ");
     
     if ( somme <=21 || somme >=16)
     {printf("GAGNE!!\n");} 
     
     else{printf ("PERDU");}
}

pritf("vous tirer %d\n", carte);
scanf("votre score est \n",&carte);   
     
     
     
     }
break;


default :
        
printf("voulez-vous tirer une nouvelle carte [y/n]?\n ");
      
break;  
}
printf("le score de la banque est %d\n", somme);

if (somme<=21)

{printf("GAGNE!!\n");} 

else {printif ("PERDU!!")}

     return 0;}  
          
