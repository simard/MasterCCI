# include <stdlib.h>
# include <stdio.h>

int main( int argc, char ** argv )
{
	int iNote = 0;
	printf( "Entrez votre age : " );
	scanf( "%d", &iNote );
	if( ( iNote >= 0 ) && ( iNote <= 10 ) )
	{
		if( iNote < 5 )
		{
			printf( "Vous n'avez pas la moyenne\n" );
		}
		else
		{
			printf( "Vous avez la moyenne\n" );
		}
	}
	else
	{
		printf( "Note incorrecte\n" );
	}
	return EXIT_SUCCESS;
}
