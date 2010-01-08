# include <stdlib.h>
# include <stdio.h>
# include <string.h>

int main( int argc, char **  argv )
{
	char cChaine[64] = "Vive les RERs";
	unsigned int iLongueur = 0;

	while( cChaine[iLongueur] != '\0' )
	{
		iLongueur++;
	}
	if( iLongueur == strlen( cChaine ) )
	{
		printf( "C'est egal\n" );
	}
	else
	{
		printf( "C'est different\n" );
	}

	return EXIT_SUCCESS;
}
