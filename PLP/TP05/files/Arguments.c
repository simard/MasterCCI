# include <stdlib.h>
# include <stdio.h>
# include <string.h>

int main( int argc, char ** argv )
{
	unsigned int i = 0;
	/* Verifier le nombre d'arguments */
	if( argc < 4 )
	{
		return EXIT_FAILURE;
	}
	/* Verifier que les nombres sont coherents */
	if( argv[2] > argv[3] )
	{
		return EXIT_FAILURE;
	}
	for( i = argv[2][0] - '0'; i < strlen( argv[1] ); i++ )
	{
		if( i > argv[3][0] - '0' )
		{
			break;
		}
		else
		{
			printf( "%c", argv[1][i] );
		}
	}
	printf( "\n" );

	return EXIT_SUCCESS;
}
