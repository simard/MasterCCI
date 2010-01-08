# include <stdlib.h>
# include <stdio.h>

int main( int argc, char ** argv )
{
	unsigned int iSomme = 0;
	unsigned int i = 0;
	for( i = 1; i <= 100; i++ )
	{
		iSomme += i;
	}
	printf( "Somme = %d\n", iSomme );

	return EXIT_SUCCESS;
}
