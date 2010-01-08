# include <stdlib.h>
# include <stdio.h>
# include <time.h>

int main( int argc, char ** argv )
{
	int iSolution = 0;
	int iProposition = 0;
	unsigned int iEssais = 5;
	srand( time( NULL ) );
	iSolution = (int)( (double)rand() / ( (double)RAND_MAX + 1.0 ) * 100.0 );
	while( iEssais > 0 )
	{
		printf( "Choix : " );
		scanf( "%d", &iProposition );
		if( iProposition == iSolution )
		{
			printf( "Felicitations\n" );
			return EXIT_SUCCESS;
		}
		else if( iProposition < iSolution )
		{
			printf( "Plus grand\n" );
		}
		else
		{
			printf( "Plus petit\n" );
		}
		iEssais--;
	}
	printf( "Perdu\n" );
	printf( "La solution est %d\n", iSolution );

	return EXIT_SUCCESS;
}
