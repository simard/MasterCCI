/* Houte
   Nicolas
   Le crible d'Eratosthène */


#include <stdio.h>

int main(int argc, char ** argv)
{
  int nombre = 0;
  int i = 2;
  int j = 2;
  int k = 0;

  printf("Entrer un entier : ");
  scanf("%d", &nombre); /* on entre le nombre à cribler.*/


  int crible[nombre];

  /* initialisation du tableau */
   for(k = 0; k < nombre; k++)
    {
      crible[k] = 0;

    }


  /* on vérifie que le nombre entré n'est pas inférieur à 2.*/
  if(( nombre < 2 ))
    {
      printf("Il faut choisir un  nombre entier supérieur ou égal à 2!\n");
      return 0;
    }


/* on élimine les nombres qui ne sont pas premiers */

  for(i = 2; i <= nombre; i++)
  {

    if(crible[i-1] == 0) /* si la valeur a déjà été éliminé pas besoin de l'éliminer à nouveau */
    {
        for(j = (i+1); j <= nombre; j++)
        {
            if((j % i) == 0 )  /* si la valeur de j qui est inferieur au nombre entré est divisible par un nombre sans avoir de reste alors il n'est pas premier */
            {
                crible[j-1] = 1;

            }
        }
    }

  }

  /* on affiche les valeurs  */
      for(i = 2; i <= nombre; i++ )
	{

	    /* les valeurs marqué par 0 dans le tableau sont premiers */

	  if(crible[i - 1] == 0)
	    {
	      printf("%d\n", i);

	    }
	}

  return 0;
}
