# include <stdio.h>
int main ( int argc,char ** argv)
{
  int inbr,i,j;
 
  printf ("etrer un nbr entier\n");
  scanf ("%i", &inbr);
  if (inbr < 2)
	   { printf ("il faut choisir un nobre superieure ou egale a 2\n");
	   } 
  
  unsigned int itab[inbr];
  for (i=2;i<inbr-1;i++)
    itab[i-2]= i;
  for (i=0;i<inbr;i++)
    if (itab[i]!=1)
      { for ( j=i ;j<inbr;j++)
          if ( itab[j+1]% itab[i]==0)
	    { itab [j+1]=1;}
      }
    
  for (i=0;i<inbr;i++)
    if (itab[i]!=1)
    printf ("%i ",itab[i]);
  return 0;
}
