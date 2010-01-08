#include <stdio.h>
#include <stdlib.h>
#include "getEntries.c"
#define N 10
#define N_MAX 100


char chaine[MAX_SIZE];

int main()
{
  int tab[N],i,*dernier,j,*temp2,temp1;

    srand((int)time(NULL));

    dernier=(int*)malloc(sizeof(int));
    temp2=(int*)malloc(sizeof(int));


    for(i=0;i<N;i++)
      {
	*(tab+i) = rand() % (N_MAX+1);
	printf("%d\n",*(tab+i));

      }
    dernier=tab+(N-1);
    temp2=dernier;
    
    for(i=1;i<=N;i++)
      {

	for(j=N-i;j>=0;j--)
	  if(*dernier>*(tab+j)) dernier=tab+j;
	    
	temp1=*(tab+N-i);

	*(tab+N-i)=*dernier;
	
	*dernier=temp1;

	dernier=temp2;

	if(i!=N)
	  {
	    dernier=dernier-1;

	    temp2=temp2-1;
	  }
   
      }

    printf("\n\n");
    for(i=N-1;i>=0;i--)
      {
	printf("%d\n",*(tab+i));

      }

    free(dernier);
    free(temp2);
    
}
