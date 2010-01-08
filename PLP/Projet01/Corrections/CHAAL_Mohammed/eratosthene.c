//MOHAMMED CHAAL
//Exercice 1 "Le crible d’Ératosthène"
////////////////////////// EXERCICE 1 /////////////////////////////////////////////////////////////////////////////////////
#include<stdio.h>

int main( int argc , char ** argv ){   ///// FONCTION PRINCIPALE/////////////

    int i;
    int j,k;
    int a;
    while(1){
    printf("Fait entrer un nombre entier  ");
    scanf("%d",&a);
    i=(int)a;
    int tab1[i-1];
    int tab2[i-1];
    if ((i==a)&&(i>=2)){    // ON TESTE UNE VALEUR ENTIERE SUPERIEUR A DEUX
                        
                        
                        for(j=0;j<=i-2;j++){
                            tab1[j]=0;
                            tab2[j]=j+2;
                                        }
for( j=0;j<=i-2;j++){
                for(k=j+1;k<=i-2;k++){
                  if((tab2[k]%tab2[j])==0){
                      tab1[k]=1;
                                            }
                                             }
                                             }

          printf(" Crible d'Eratosthene %d\n",i);
          for(j=0;j<=i-2;j++){
                          if(tab1[j]==0)
                 printf("%d\n",tab2[j]);
                                             }
                                            }
                        else{
                             printf("Erreur");
                             }
}
    //system("pause");

    return 0;

}
