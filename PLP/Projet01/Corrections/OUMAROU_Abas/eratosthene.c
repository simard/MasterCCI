
#include<stdio.h>
     
          //OUMAROU Abas

          /*exercice 1 : l'Algorithme d'Eratosthène

   ce programme permet d'afficher des nombres premiers inférieurs
   au nombre entré par l'utilisateur : */

int main(int argc,char**argv) 
 
  
    // création d'un tableau qui contiendra toutes les valeurs
    // vérification du nombre entrÃé par l utilisateur

{
   int n, i,j;

       printf("ce programme effectue l'algoritme d'Eratosthène \n\n");

       printf("entrer un nombre supérieur ou égal à  2\n");

       scanf("%d",&n);

       int tab[n+1];
        
 
     /* initialisation du tableau : toutes les cases sont à 1
      si un nombre n'est pas prémier, il est multiple d'un nombre premier
      il suffit donc d'éliminer les multiples des nombres premiers */
      
      

        for(i=0;i<=n;i++)
          
           { 
             tab[i]=1;
             }
    
        if(n<2) 
           {
             printf("erreur, impossible");
	     }
        else  
        
            for(i=2;i<=n/2;i++) 

                for(j=2;j<=n/i;j++)

                   {
                     tab[i*j]=0;
                       }
     
       // impression des nombres premiers
        
    
        for(i=2;i<=n;i++)
            if(tab[i])
               {
                 printf("%d \n\n",i);
                   }
    
 }             
