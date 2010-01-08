# include <stdlib.h>
# include <stdio.h>

struct sComplexe
{
	double dReel;
	double dImaginaire;
};

void AfficherComplexe();

struct sComplexe UnComplexe = { 2.0, 5.0 };

int main( int argc, char ** argv )
{
	AfficherComplexe( UnComplexe );
	printf( "\n" );
	return EXIT_SUCCESS;
}

void AfficherComplexe()
{
	printf( "%lf", UnComplexe.dReel );
	if( UnComplexe.dImaginaire < 0.0 )
	{
		printf( "%lfi", UnComplexe.dImaginaire );
	}
	else
	{
		printf( "+%lfi", UnComplexe.dImaginaire );
	}
	return;
}
