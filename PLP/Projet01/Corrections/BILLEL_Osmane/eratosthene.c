#include<stdio.h>
int main(int argc, char ** argv)
{
  int N,i,j; 
  
  do
    {  printf("donner un nombre >= 2 =");
      scanf("%i",&N);
      if (N<2)
	printf("Erreur\n");
    }while (N<2);
  unsigned int itab[N];

  for (i=1;i<=N;i++)
    itab[i-1]=i+1;
  
 for (i=0;i<N;i++)
   { if ( itab[i]!=1)
       {
	for (j=i;j<N-1;j++)
	    {if  (itab[j+1] % itab[i]==0)
		{
		  itab[j+1]=1;
		 
		}
	    }
	}
    }
 
  for(i=0;i<N;i++)
    { if (itab[i]!=1)
	printf("%i\n",itab[i]);
    } 
 return 0;
}
