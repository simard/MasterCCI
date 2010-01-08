
//SAIDOUN Nabil
//M2P CCI
////////////////////////// EXERCICE 1 /////////////////////////////////////////////////////////////////////////////////////
#include<stdio.h>   

int main( int argc , char ** argv ){   ///// fonction principale///////////////////

    /////////////////////////initialisation/////////////////////////////////////////////////////////
    int i;    
    int j,k;   
    float a;       
    while(1){        ////////////BOUCLE INFINI EXECUTION CONTINUELLE
    printf("entrer un nombre entier superieur à 2 : ");     
    scanf("%f",&a);    ////// LIT LA VALEUR ENTRER
    i=(int)a;           /////// RECUPERE LA VALEUR ENTIERE DU  NOMBRE
    int tab1[i-1];       
    int tab2[i-1];        
    if ((i==a)&&(i>=2)){     // la valeur est testée si c'est un nombre entier supérieur a deux
                        for(j=0;j<=i-2;j++){      //// REMPLISSAGE DES TABLEAUX
                                            tab1[j]=0;        
                                            tab2[j]=j+2;        
                                            }

                               ///////////////////////////ALGORITHME D ERATOSTHENE////////////////////////////////////////          
                        for( j=0;j<=i-2;j++){        
                             for(k=j+1;k<=i-2;k++){    
                                                   if((tab2[k]%tab2[j])==0){  ///// TESTE LES DIVISEURS
                                                                            tab1[k]=1;  /// SI LA VALEUR tab2[k] n'est pas premier
                                                                            }
                                                   }
                                             }
                              ///////////////////////////////////AFFICHAGE DES NOMNRE PREMIER DE L INTERVALLE [1,N]
                                                                            printf("voici le crible d'Eratosthene jusqu'a l'entier %d\n",i);
                                                                            for(j=0;j<=i-2;j++){
                                                                                                if(tab1[j]==0)  ////RECUPERE L INDICE DU NOMBRE PREMIER AVANT AFFICHAGE
                                                                                                printf("%d\n",tab2[j]); 
                                                                                                }
                        }
                        else{ 
                             printf(" la valeur du nombre rentrer est erronée"); ////MESSAGE D ERREUR SI LE NOMBRE
                             }                                                   //// N EST PAS ENTIER POSITIF > 2
}
    return 0;

}
