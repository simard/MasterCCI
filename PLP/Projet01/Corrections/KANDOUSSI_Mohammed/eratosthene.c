/* projet Mohammed KANDOUSSI en Master 2 CCI : exercice 1: la crible d'eratosthéne*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int m;/* variable dans la boucle d'affichage*/
  int N;/*l'entier entre par l'utilisateur*/

  int i;/*une variable dans la boucle I*/

  int j;/*une variable de la boucle J*/

  int k; /* une variable qui parcourt le tableau de taille N+1 */

 printf ("entrez un entier:");

 scanf ("%d", &N);/*lire l'entier entre par l'utilisateur*/

 int tab[N+1];/* déclaration d'un tableau de taille N+1*/
 
/* boucle d'initialisation des elements du tableau à 0*/
 for (k=0; k<=N;k++) /* */

   {tab[k]=0;}

 if (N<=0 || N==1)/*test de l'entier entré par l'utilisateur*/
   {
     printf("il faut choisir un nombre entier superieur a 2 !!\n");
   }


 /* boucles imbriquees pour distinguer les nombres premiers de ceux qui ne le sont pas*/
 
 for (i=2; i<N;i++){
  
  for (j=i+1;j<=N;j++){
   
   if (tab[j]==0) /* ce test supprime les nombres non premiers (élimine plutot les elements du tableau qui valent 1)*/
    {
    if ((j%i)==0)
	  { tab [j]=1;
       
      }
   }    
  }
 }
 printf ("voici la crible d'Eratosthene jusqu'a l'entier %d\n",N);
 
 /* boucle d'affichage des nombres premiers*/
 
 for(m=2;m<=N;m++){
  if (tab[m]==0){
    printf ("%d\n",m);
  }
 }
 system("PAUSE");
 	
 return 0;
}

