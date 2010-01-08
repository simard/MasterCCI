# include <stdlib.h>
# include <stdio.h>

int main( int argc, char ** argv )
{
	unsigned int iAge = 0;
	printf( "Entrez votre age : " );
	scanf( "%d", &iAge );
	if( iAge < 18 )
	{
		printf( "Vous etes mineur\n" );
	}
	else
	{
		printf( "Vous etes majeur\n" );
	}
	return EXIT_SUCCESS;
}
