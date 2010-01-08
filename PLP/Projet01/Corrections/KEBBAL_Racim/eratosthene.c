
/*Projet1_Exercie 1*/

/*BOUGHANEM Mohamed Adel*/


# include <stdio.h>
# include <stdlib.h>
# include <time.h>

int main()
 {
  
   int N,i,j;
   char fin='n';
printf("\n\n\n");
do
{
system("CLS");

/*Taper N par l'utilisateur--------------------------*/

   printf("\n\n\nDonnez la valeur de N:  ");

/*Condition de debut*/


   if (((scanf("%d",&N))==1)&&(N>2))
     

/*TRAITEMENT*/
/*voir les nombre de n et mettre le tableau a zero si modulo egale a zero*/



         int tableau_des_valeurs[N+2];
         for(i=0;i<=N;i++)
          {
          tableau_des_valeurs[i]=1;
          }
         
         for(i=2;i<N;i++)
         {   
          for (j=i+1;j<=N;j++)
           {
            if ( (j%i)==0)
             {
              tableau_des_valeurs[j]=0;
             }
           }
          }
     
/*Affichage des valeurs premieres*/
/*Qui correspondent a 1 dans le tableau*/
     
      printf("\n\n\n  les valeurs premieres        : ");
        for(i=2;i<=N;i++)
          {  
           if (tableau_des_valeurs[i]==1)
            {
            printf("%3d",i);
            }
           }
printf("\n\n\n\n\n");
       }

/*Message pour les valeur erronées*/


else
      {
    printf("Vous Avez introduit une valeur erronée\n\n\n");
      }

/*Message pour rester dans le programme*/

 
 printf("voulez vous quitter l'application ? y/n   ");
 scanf("%s",&fin);  
}
while(fin=='n'); 
   return 0;
}

