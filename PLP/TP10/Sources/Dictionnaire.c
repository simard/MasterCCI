# include <stdlib.h>
# include <stdio.h>

typedef struct sMot
{
	char * cMot;
	struct sMot * pSuivant;
} Mot;

void AfficherDictionnaire( Mot * pDict )
{
	while( pDict != NULL )
	{
		printf( "%s\n", pDict->cMot );
		pDict = pDict->pSuivant;
	}
	return;
}

int main( int argc, char ** argv )
{
	Mot * pDict = NULL;
	Mot * UnMot = NULL;
	unsigned int i = 0;
	for( i = 1; i < argc; i++ )
	{
		UnMot = (Mot *) malloc( sizeof( Mot * ) );
		UnMot->cMot = argv[i];
		UnMot->pSuivant = pDict;
		pDict = UnMot;
	}
	AfficherDictionnaire( pDict );

	return 0;
}
