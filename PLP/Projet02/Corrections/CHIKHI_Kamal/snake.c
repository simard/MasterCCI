//
//
//
//____________CHIKHI   KAMAL
//____________M2 CCI
//
//
//
//
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
int main(void) // fonction principale
{
    int larg, haut, i, j;
    
    while(1)
    {
    printf ("introduire la valeur de la largeur et de la hauteur de l'environement\n");
    scanf ("%d", &larg);
    scanf ("%d", &haut);
    int tab[larg][haut];
    int environement[larg][haut];
    tab[larg][haut] = bordure(larg, haut);
       //system ("cls");
    //tab[larg][haut] = bordure(larg, haut);
    system ("pause");
}
    return 0;
}
// création de l'environement avec la fonction bordure
int bordure(int a, int b, int ll, int kk)
{
    short int mat[a][b];
    int i=0, j=0;
        for (i=0; i<a; i++)
    {
        for (j=0; j<b; j++)
        {
            mat[i][j] = '\x20';
        }
    }
    for (i=0; i<a; i=i+(a-1))
    {
    for (j=0; j<b; j++)
    {
    mat[i][j]='#';
    }
    }
    for (j=0; j<b; j=j+(b-1))
    {
    for (i=0; i<a; i++)
    {
    mat[i][j]='#';
    }
    }
    ll = serpent(ll, kk, a+2, b-3);
    kk = serpent(ll, kk, a+3, b-4);
    mat[ll][kk] = '\x3E';
    j=0;
    while ( j<b)
    {
        for (i=0; i<a; i++)
        {
            printf ("%c", mat[i][j]);
        }
        printf ("\n");
        j++;
     }
    return (mat[i][j]); 
}
//
//
//génération d'un serpent a l'intérieur de l'environement d'une manière aléatoire.
int serpent(int l, int k, int x, int y)
{
    srand (time (NULL));
    l = (int)((double)rand()/((double)RAND_MAX + 3.0)*(x+5));
    k = (int)((double)rand()/((double)RAND_MAX + 1.5)*(y+2));
    return l, k;
}
//
//
//
//fonction qui contrôle le déplacement des serpents.
int move(int i, int j, int a, int b, int mat1[a][b])
{
    int arret;
    arret=0;
    while (arret != 0)
    {
          if (mat1[i][j]='\x3E')
          {
              if (mat1[i][++j]='\x20')
              {
              mat1[i][++j]='\x3E';
              j=j++;
              arret=0;
              }
              else if (mat1[--i][j]='\x20')
              {
              mat1[--i][j]='\x5E';
              i=i--;
              arret=0;
              }
              else if (mat1[++i][j]='\x20')
              {
              mat1[++i][j]='\x76';
              i=i++;
              arret=0;
              }
              else
              { 
              arret=1;
              }
          }
          else if (mat1[i][j]='\x5E')
          {
               if (mat1[--i][j]='\x20')
               {
               mat1[--i][j]='\xE5';
               i=i--;
               arret=0;
               }
               else if (mat1[i][--j]='\x20')
               {
               mat1[i][--j]='\x3C';
               j=j--;
               arret=0;
               }
               else if (mat1[i][++j]='\x20')
               {
               mat1[i][++j]='\x3E';
               j=j++;
               arret=0;
               }
               else
               { 
               arret=1;
               }
          }
          else if (mat1[i][j]='\x3C')
          {
               if (mat1[i][--j]='\x20')
               {
               mat1[i][--j]='\x3C';
               j=j--;
               arret=0;
               }
               else if (mat1[++i][j]='\x20')
               {
               mat1[++i][j]='\x76';
               i=i++;
               arret=0;
               }
               else if (mat1[--i][j]='\x20')
               {
               mat1[--i][j]='\x5E';
               i=i--;
               arret=0;
               }
               else 
               {
               arret=1;
               }
          }
          else if (mat1[i][j]='\x76')
          {
               if (mat1[++i][j]='\x20')
               {
               mat1[++i][j]='\x76';
               i=i++;
               arret=0;
               }
               else if (mat1[i][++j]='\x20')
               {
               mat1[i][++j]='\x3E';
               j=j++;
               arret=0;
               }
               else if (mat1[i][--j]='\x20')
               {
               mat1[i][--j]='\x3C';
               j=j--;
               arret=0;
               }
               else 
               {
               arret=1;
               }
          }
          }
          return ;
}
    
