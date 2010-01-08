/* BOUARAR KARIMA 
  Le crible d'ERATOSTHENE */

#include <stdio.h>
int main ()
{
  
  int n;

  printf("Entrer un entier : ");
  
   scanf("%d", &n);
   
   /* On test si l'entier en entree est superieur a 2.
      Sinon on affiche un message d'erreur. */
   
   if (n<2) {
     
     printf("Il faut choisir un nombre entier superieur a 2 \n");   
     
   } else {
     
     /*On cree un tableau de taille n pour le crible d'Eratosthene*/
     
     int tab[n];
     int i;
     
     /* la variable indice indique la case du tableau contenant le nombre entier.
	indice =0 : la premiere case contient le premier nombre entier (2).
	la variable k est utilisee pour trouver le prochain nombre entier sur lequel
	on applique notre algorithme */
     
     int indice=0;
     int k;
     
     /* On initialise le tableau tab avec des 0 */
     
     for(i = 0; i < n; i++) 
       tab[i]=0;
     
     
     while (indice < n) {   
       
       /* On parcours le tableau tab en cherchant 
          les diviseurs du nombre entier indice+2.
          Exemple: a l'indice 0 se trouve le nombre entier 0+2 donc 2.
          On commence toujours par la case suivant celle ou se trouve
          le nombre entier (d'ou i=indice+1). 
          Cela evite de parcourir a chaque fois le tableau depuis le début. 
          On affect 1 a chaque case du tableau indiquant un diviseur.*/
       
       for(i = indice+1; i < n; i++) { 
	 
	 if ((i+2)%(indice+2) ==0) 
	   tab[i]=1;  
       } 
       
       k=indice+1;
       
       /* On cherche le prochain nombre entier sur lequel on doit
	  appliquer l'algorithme. Utiliser la boucle while evite de
	  parcourir tout le tableau tab.*/
       
       while (tab[k]!=0) {
	 k=k+1;
	 
       }
       
       /* Une fois l'indice du prochain nombre entier trouvé. On applique
          dessus notre algorithme (premiere boucle while). */
       
       indice=k;
       
     }
     
     /* On imprime en sortie les nombres entiers trouvés. */
     
     printf("Voici le crible d'Eratosthène jusqu'à l'entier %d\n",n);
     
     for(i = 0; i <= n-2; i++) {  
       if (tab[i]==0)
	 printf("%d\n", i+2);
       
     }
   }
   
}
