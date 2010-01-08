#include <stdio.h>
#include <stdlib.h>
#include "getEntries.c"

char chaine[MAX_SIZE];

typedef struct cellule
{
  int id;
  struct cellule *suivant;
};


void desallocation(struct cellule *cellule, int i);

void affichage(struct cellule *cellule, int i);

void creation(struct cellule *cellule, int i);



int main()
{

  int i;

  struct cellule cellule;

  i=0;

  creation(&cellule,i);

  i=0;

  affichage(&cellule,i);

  i =0;
  
  desallocation(&cellule,i);


}

void affichage(struct cellule *cellule, int i)
{
  if(i<10)
    {
      printf("%d   ",cellule->id);
      affichage(cellule->suivant,i+1);

    }
  else 
    {
      printf("\n");
      printf("Fin\n");
    }
  


}

void creation(struct cellule *cellule, int i)
{

  int entier;


  if(i<10)
    {
      printf("Rentrez un entier : ");
      entier=(int)getNumber(chaine);
      cellule->id=entier;
      cellule->suivant=(struct cellule *)malloc(sizeof(struct cellule));
      creation(cellule->suivant,i+1);

    }


}

void desallocation(struct cellule *cellule, int i)
{
  if(i<10)
    {
      free(cellule->suivant);
      desallocation(cellule->suivant,i+1);
    }

}
