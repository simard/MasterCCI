#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

// OUMAROU ABAS

//typedef enum couleur couleur;
enum Couleur_Carte
{
  PIQUE, CARREAU, COEUR, TREFFE
};

enum Numero_Carte 
{
  AS, deux,trois,quatre,cinq,six,sept,huit,neuf,dix, VALET, DAME,ROI
};

struct Carte
{
      enum Numero_Carte numero;
      enum Couleur_Carte couleur;
       }
;
//bool compare(carte t,

int main()

{
    struct Carte tirage;
     int MAX1=13,MIN1=1, MAX2=4; int max=20, min=16 , banque=0;
     int m, n;
     char c='a';
    int som=0;
    
    
    while(som<21)
      {
                      // Lecture du caractère frappé par le joueur
                      
        printf("voulez vous tirer une carte?");
        c=getchar();
        
        while(c!='n') 
               {
               
               if(c!='y') 
                 {
               printf("voulez vous tirer une carte?");
               c=getchar();
               }
               else if(c=='y')       // 1er cas 
            
                      /* initialisation de la fonction srand puis 2 tirages
                         l'un compris entre 1 et 13  pour le numero
                         de la carte ( AS, 2 ...,10,.. ,ROI)
                         et l'autre la famille (COEUR,..) */
                        
              {           
             srand(time(NULL));
           
                      m = (rand() % (MAX2 - MIN1 + 1)) + MIN1;
                      switch(m) 
                      { 
                        case 1 : {tirage.couleur= PIQUE;
                                 break;}
                        case 2 : {tirage.couleur=CARREAU;
                                 break;}
                        case 3 : {tirage.couleur=COEUR;
                                 break;}
                        case 4 : {tirage.couleur=TREFFE;
                                 break;}
                        }
              
                      n=(rand() % (MAX1 - MIN1 + 1)) + MIN1;
                      switch(n)    // utilisation d'un compteur som
                      {
                  case 1 : {if((som+11)>21) 
                                         {som++;
                                          tirage.numero=1;}
                                              else {som+=11;
                                                   tirage.numero=11;}}
                                         break;           
                  case 2 : {tirage.numero=deux;
                           som+=2;
                              break;}
                  case 3 : {tirage.numero=trois;
                           som+=3;
                              break;}
                  case 4 : {tirage.numero=quatre;
                           som+=4;
                              break;}
                  case 5 : {tirage.numero=cinq;
                            som+=5;
                              break;}
                  case 6 : {tirage.numero=six;
                            som+=6;
                              break;}
                  case 7 : {tirage.numero=sept;
                            som+=7;
                              break;}
                  case 8 : {tirage.numero=huit;
                            som+=8;
                              break;}
                  case 9 : {tirage.numero=neuf;
                            som+=9;
                             break;}
                  case 10 : {tirage.numero=dix;
                             som+=10;
                             break;}
                  case 11 : {tirage.numero=VALET;
                             som+=10;
                             break;}
                  case 12 : {tirage.numero=DAME;
                             som+=10;
                             break;}
                  case 13 : {tirage.numero=ROI;
                             som+=10;
                             break;}
                       }
                       //problème de format : en sortie on a un type Carte
               printf("vous avez tire %d %s \n\n",tirage.numero,tirage.couleur);    
               printf("votre score est de %d\n",som);    
            
                     } 
                     
                 else // if(c='n')  //2eme cas
                          {
                           banque=(rand()% (max-min+1))+min;
                           
                           printf("le score de la banque est %d\n",banque);
                           if((som<=banque) ||(som>20))
                             {
                               printf("vous avez perdu\n");
                               }
                            else
                               {
                               printf("vous avez gagné\n");
                              } 
                                                
                      
                            }      
             
                                
          //   printf("votre score est de %d\n",som);    
             }             
      
            
return 0;                               
}}

 
