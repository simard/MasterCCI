# include <stdlib.h>
# include <stdio.h>

struct sComplexe
{
	double dReel;
	double dImaginaire;
};

void AfficherComplexe( struct sComplexe z );

int main( int argc, char ** argv )
{
	struct sComplexe UnComplexe = { 2.0, 0.5 };
	AfficherComplexe( UnComplexe );
	printf( "\n" );
	return EXIT_SUCCESS;
}

void AfficherComplexe( struct sComplexe z )
{
	printf( "%lf", z.dReel );
	if( z.dImaginaire < 0.0 )
	{
		printf( "%lfi", z.dImaginaire );
	}
	else
	{
		printf( "+%lfi", z.dImaginaire );
	}
	return;
}
