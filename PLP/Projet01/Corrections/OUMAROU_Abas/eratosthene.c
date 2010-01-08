
#include<stdio.h>
     
          //OUMAROU Abas

          /*exercice 1 : l'Algorithme d'Eratosth�ne

   ce programme permet d'afficher des nombres premiers inf�rieurs
   au nombre entr� par l'utilisateur : */

int main(int argc,char**argv) 
 
  
    // cr�ation d'un tableau qui contiendra toutes les valeurs
    // v�rification du nombre entr�� par l utilisateur

{
   int n, i,j;

       printf("ce programme effectue l'algoritme d'Eratosth�ne \n\n");

       printf("entrer un nombre sup�rieur ou �gal � 2\n");

       scanf("%d",&n);

       int tab[n+1];
        
 
     /* initialisation du tableau : toutes les cases sont � 1
      si un nombre n'est pas pr�mier, il est multiple d'un nombre premier
      il suffit donc d'�liminer les multiples des nombres premiers */
      
      

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
