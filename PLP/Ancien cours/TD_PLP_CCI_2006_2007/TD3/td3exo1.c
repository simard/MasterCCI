/* Exo 1 du TD3 */

#include<stdio.h>

//fonction principale dans laquelle sont rassembl�es les instructions
int main(){
    //D�claration d'une variable de type int d'identificateur x
    int x;
    
    //Invite l'utilisateur � rentre un entier
    printf("Rentrez un entier\n");
    
    /*Structure conditionnelle
    SI l'entr�e au clavier est un entier
       ALORS affiche vraie
    SINON affiche faux
    FIN SI
    */
    if(scanf("%d",&x)){
       printf("vraie\n");
    }
    else{
       printf("faux\n");
    }
}
