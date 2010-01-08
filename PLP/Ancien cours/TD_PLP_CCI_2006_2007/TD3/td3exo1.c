/* Exo 1 du TD3 */

#include<stdio.h>

//fonction principale dans laquelle sont rassemblées les instructions
int main(){
    //Déclaration d'une variable de type int d'identificateur x
    int x;
    
    //Invite l'utilisateur à rentre un entier
    printf("Rentrez un entier\n");
    
    /*Structure conditionnelle
    SI l'entrée au clavier est un entier
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
