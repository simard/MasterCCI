

#include<stdio.h>

int main(int arc, char**argv)
{

  unsigned int i=0,j=0,valeur=0; // j'ai choisi des unsigned int au lieu de int pour optimiser de l'espace memoire.
  
  printf("Entrer un entier.");
  scanf("%d", &valeur);

  unsigned int crible[valeur];

  for(i=1; i< valeur; i++)  // initialisation du tableau par 0
   {
      crible[i]=0;
   }
  crible[0]=1; // mettre la premiere case du tableau a 1
 
  if(valeur<2)  // verifier que valeur entrée par l'utilisateur est positif et superieur ou egale a 2. 
    {
      printf("il faut choisir un nombre superieur a 2.");
    }
  else
    {
      for(i=2; i<= valeur; i++)  // faire l'operation modulo entre les valeurs de l'indice i et i+1, i+2,....  
	  {
	    for(j=i+1; j<=valeur; j++) // pour eliminer les elements du tableau multiples de l'element a l'indice i.
	      {
		if(crible[i-1]!=1)
		  {
		    if((j%i)==0)         // test pour voir si i est divisible par j 
		      {
			crible[j-1]=1;   // si oui i est un nombre premier 
		      }                  //

		  }
	      }
	    
	  }
	printf("Voici le crible de Eratosthene jusqu'a l'entier:%d\n ", valeur);
	
	for(i=0; i<valeur; i++) //parcourir tout le tableau et choisir que les case
	  {
	    if(crible[i]!=1)    //qui contiennent des 0
	      {
		printf("%d\n",i+1);
	      }
	  }
    }

  return 0;
}
