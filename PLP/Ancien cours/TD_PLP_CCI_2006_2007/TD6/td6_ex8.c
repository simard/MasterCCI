#include <stdio.h>
#include <stdlib.h>
#include "getEntries.c"
#include <time.h>
//#define NB 10;

char chaine[MAX_SIZE];

//void tri_extraction(int *tab);
void init(int *tab);
void affichage(int *tab);
void tri_bulles(int *tab);

int main()
{

  int tab[10];

  srand((int)time(NULL));

  init(tab);
  affichage(tab);
  tri_bulles(tab);
  affichage(tab);


}


/*void tri_extraction(int *tab)
{
  int i,j,k,temp1,temp2;
  int NB=10;

  for(j=0;j<(NB-1);j++)
    {
      temp1=*(tab+j);// c est celui la le plus petit
      k=j;
      for(i=j;i<NB;i++)
	{
	  if((*(tab+i))<temp1)
	    {
	      temp1=*(tab+i);
	      k=i;
	    }

	  // on remplace le plus petit
	}
      temp2=*(tab+j);
      *(tab+j)=temp1;
      *(tab+k)=temp2;

    }

}
*/
void tri_bulles(int *tab)
{
  int i,condition,temp; 

  i=0;

  condition=1;

  while(condition==1)
    {
      if(*(tab+i)>*(tab+i+1))
	{
	  temp=*(tab+i);
	  *(tab+i)=*(tab+i+1);
	  *(tab+i+1)=temp;
	  if(i>0) i=i-1;
	  else i=i+1;
	}
      else if(i<9) 
	{
	  if(i==8) condition=0;
	  i=i+1;
     
	}      

    }
}




void init(int *tab)
{
  /* int i;
   int NB=10;

  for(i=0;i<NB;i++)
    {
      *(tab+i)=(int)(rand() % (21));
      }*/
  
*(tab+0)=10;
*(tab+1)=9;
*(tab+2)=56;
*(tab+3)=7;
*(tab+4)=23;
*(tab+5)=5;
*(tab+6)=12;
*(tab+7)=3;
*(tab+8)=98;
*(tab+9)=1;


}

void affichage(int *tab)
{
  int i;
  int NB=10;

  for(i=0;i<NB;i++)
    {
      printf("%3d  ",*(tab+i)); 
    }

  printf("\n");

}
