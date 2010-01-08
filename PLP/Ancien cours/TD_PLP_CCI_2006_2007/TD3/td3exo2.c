/* Exo 2 du TD3 */

#include<stdio.h>

//fonction principale dans laquelle sont rassemblées les instructions
int main(){
    //Déclaration d'une variable de type char d'identificateur x
    char x;
    
    //Invite l'utilisateur à rentrer un caractère
    printf("Choisir h/H ou f/F\n");
    x=getchar();
    /*Structure conditionnelle
    SI le caractère est h ou H
       ALORS        Affiche question taille
                    Invite l'utilisateur à rentrer un float
                    SI la taille est <0 ou >3
                       ALORS affiche erreur
                    SINON affiche la taille en cm
                    FIN SI
    SINON SI le caractère est f ou F
       ALORS        Affiche question age
                    Invite l'utilisateur à rentrer un int
                    SI l'age est <0 ou >130
                       ALORS affiche erreur
                    SINON 
                          SI age < 20
                             ALORS affiche age
                          SINON affiche message
                          FIN SI
                    FIN SI          
    SINON affiche faux
    FIN SI
    */
    if( (x=='h') || (x=='H') ){
        float taille;
        printf("Quelle est votre taille en m ?\n");
        scanf("%f",&taille);
        if(taille<0 || taille>3){
             printf("vous en etes vraiment sur ?\n");
        }
        else{
             printf("Votre taille en cm est : %.0f\n",taille*100);
        }
    }
    else if ( (x=='f') || (x=='F') ){
         int age;
         printf("Quel est votre age ?\n");
         scanf("%d",&age);
         if(age<0 || age>130){
             printf("vous en etes vraiment sur ?\n");
         }
         else{
             if(age < 20){
                 printf("Votre age est : %d\n",age);
             }
             else{
                 printf("Vous ne les faites vraiment pas\n");
             }
         }
    }
    else{
         printf("vous vous etes trompes\n");
    }
}
