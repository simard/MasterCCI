/* Exo 4 du TD3 
   La diff�rence avec l'exo 3 est que j'accepte les majuscules
*/

#include<stdio.h>

//fonction principale dans laquelle sont rassembl�es les instructions
int main(){
    //D�claration d'une variable de type char d'identificateur x
    char x;
    
    //Invite l'utilisateur � rentre un entier
    printf("Rentrez un caract�re f/F m/M a/A ou b/B\n");
    x=getchar();
    
    /*Branchement multiple : selon la valeur de x, il ex�cute les instructions jusqu'au break*/
    switch(x){
         case 'f':
         case 'F':
              printf("CCI\n");
              break;
         case 'm':
         case 'M':
              printf("Programmation\n");
              break;
         case 'a':
         case 'A':
              printf("2006\n");
              break;
         case 'b':
         case 'B':
              printf("308\n");
              break;
         default:
              printf("vous avez un gros probleme\n");
              break;
    }
}
