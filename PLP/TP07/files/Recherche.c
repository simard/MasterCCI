# include <stdlib.h>
# include <stdio.h>

unsigned int Recherche( char * cSource, char * cCherche )
{
	unsigned int iPosition = 0;
	char * pcIndex = cSource;
	while( *pcIndex != '\0' )
	{
		if( *pcIndex == *cCherche )
		{
			iPosition = 0;
			while( pcIndex[iPosition] == cCherche[iPosition] )
			{
				if( cCherche[iPosition+1] == '\0' )
				{
					return ( pcIndex - cSource + 1 );
				}
				iPosition++;
			}
		}
		pcIndex++;
	}
	return 0;
}

int main( int argc, char ** argv )
{
	unsigned int iPosition = 0;
	if( argc < 3 )
	{
		printf( "Il manque des arguments\n" );
		return EXIT_FAILURE;
	}
	iPosition = Recherche( argv[1], argv[2] );
	printf( "La chaine \"%s\"", argv[2] );
	if( iPosition == 0 )
	{
		printf( " n'est pas dans \"%s\"\n", argv[1] );
	}
	else
	{
		printf( " dans \"%s\"", argv[1] );
		printf( " est a la position %u\n", iPosition );
	}

	return EXIT_SUCCESS;
}
