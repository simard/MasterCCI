//
//
//
//
//*************  CHIKHI  Kamal
//*************  EXERCICE 1.
#include <stdio.h>
int main ()
{
    int n=2, i=0, j=2, k=0, m=0, a=0; // déclaration des variables
    printf ("introduire la valeur d'un nombre entier superieur a 2\n"); // affichage de message pour l'introduction d'un nombre entier > à 2.
    scanf ("%d", &n);    // introdution d'un nombre entiers.
    if (n > 2)           // test du nombre entier s'il est supérieur a 2 on continue.
    {
    unsigned int tab1[n]; // déclaration du premier tableau.
    unsigned int tab2[n]; // déclaration du second tableau.
    {
       for (k=0; k<=n; k++) // condition et intervalle de variation du la variable k.
       {
         tab2[k]=0;        // remplissage du tableau 2 par des zéro '0'.
       }
    }
    {
    for (i=0; i<=n; i++)   // condition et intervalle de variation du la variable i
    {
        tab1[i]=i;        // remplissage du tableau 1 par des nombre a ordre croissant de zéro '0' à n.
    }
    }    
    for (j=2; j<=n; j++)
    {
           for (i=j+1; i<=n; i++)
           {
            a = (i%j);
            if (a != 0)
                       {
                       tab1[i] = tab1[i];
                       }
                       else
                       {
                        tab1[i]=0;
                       }
            }
    } 
    i=2;
    m=0;
    {
    while (i<=n)
    {
          if (tab1[i] != 0)
          {
             tab2[m] = tab1[i];
             m++;
             i++;
          }
          else
          {
          i++;
          }
    }
    }  
    printf ("les nombres premiers compris entre [1 et n] sont:\n");
    for (k=0; k<m; k++)
    {
        printf ("%d\n", tab2[k]);
    } 
}
else
{
    printf ("erreur\n");
}         
     system ("pause");
    return 0;
}
