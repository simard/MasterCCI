# include <stdlib.h>
# include <stdio.h>

struct sComplexe
{
	double dReel;
	double dImaginaire;
};

void AfficherComplexe( struct sComplexe z, unsigned int iNbChiffres );

int main( int argc, char ** argv )
{
	struct sComplexe UnComplexe = { 2.0, 0.5 };
	AfficherComplexe( UnComplexe, 2 );
	printf( "\n" );
	return EXIT_SUCCESS;
}

void AfficherComplexe( struct sComplexe z, unsigned int iNbChiffres )
{
	char cControle[6] = "%.3lf";
	if( iNbChiffres < 10 )
	{
		cControle[2] = (char)iNbChiffres + '0';
	}
	else
	{
		return;
	}
	printf( cControle, z.dReel );
	if( z.dImaginaire >= 0.0 )
	{
		printf( "+" );
	}
	printf( cControle, z.dImaginaire );
	printf( "i" );
	return;
}
