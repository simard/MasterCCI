/* Exo 3 du TD3 */

#include<stdio.h>

//fonction principale dans laquelle sont rassembl�es les instructions
int main(){
    //D�claration d'une variable de type char d'identificateur x
    char x;
    
    //Invite l'utilisateur � rentre un entier
    printf("Rentrez un caract�re f m a ou b\n");
    x=getchar();
    
    /*Branchement multiple : selon la valeur de x, il ex�cute les instructions jusqu'au break*/
    switch(x){
         case 'f':
              printf("CCI\n");
              break;
         case 'm':
              printf("Programmation\n");
              break;
         case 'a':
              printf("2006\n");
              break;
         case 'b':
              printf("308\n");
              break;
         default:
              printf("vous avez un gros probleme\n");
              break;
    }
}
