# include <stdlib.h>
# include <stdio.h>
# include <math.h>

# define PI 3.14159

struct sComplexe
{
	double dReel;
	double dImaginaire;
};

void AfficherComplexe(\
	struct sComplexe z, unsigned int iNbChiffres );
struct sComplexe AdditionComplexes(\
	struct sComplexe z1, struct sComplexe z2 );
struct sComplexe MultiplicationComplexes(\
	struct sComplexe z1, struct sComplexe z2 );
struct sComplexe ConjugueComplexe(\
	struct sComplexe z );
struct sComplexe DivisionComplexeReel(\
	struct sComplexe z, double r );
struct sComplexe DivisionComplexes(\
	struct sComplexe z1, struct sComplexe z2 );
void AfficherComplexePolaire(\
	struct sComplexe z, unsigned int iPrecisionR, unsigned int iPrecisionT );

int main( int argc, char ** argv )
{
	struct sComplexe z1 = { 1.0, -1.0 };
	struct sComplexe z2 = { -1.0, 3.0 };
	printf( "z1 = " );
	AfficherComplexe( z1, 1 );
	printf( "\n" );
	printf( "z2 = " );
	AfficherComplexe( z2, 1 );
	printf( "\n" );
	printf( "z1+z2 = " );
	AfficherComplexe(\
		AdditionComplexes( z1, z2 ), 1 );
	printf( "\n" );
	printf( "z1*z2 = " );
	AfficherComplexe(\
		MultiplicationComplexes( z1, z2 ), 1 );
	printf( "\n" );
	printf( "\\z1 = " );
	AfficherComplexe(\
		ConjugueComplexe( z1 ), 1 );
	printf( "\n" );
	printf( "z2/3.0 = " );
	AfficherComplexe(\
		DivisionComplexeReel( z2, 3.0 ), 3 );
	printf( "\n" );
	printf( "z1/z2 = " );
	AfficherComplexe(\
		DivisionComplexes( z1, z2 ), 3 );
	printf( "\n" );
	printf( "z1(polaire) = " );
	AfficherComplexePolaire( z1, 3, 0 );
	printf( "\n" );
	return EXIT_SUCCESS;
}

void AfficherComplexe(\
	struct sComplexe z, unsigned int iNbChiffres )
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

struct sComplexe AdditionComplexes(\
	struct sComplexe z1, struct sComplexe z2 )
{
	struct sComplexe sResultat = { 0.0, 0.0 };
	sResultat.dReel = z1.dReel + z2.dReel;
	sResultat.dImaginaire = z1.dImaginaire + z2.dImaginaire;
	return sResultat;
}

struct sComplexe MultiplicationComplexes(\
	struct sComplexe z1, struct sComplexe z2 )
{
	struct sComplexe sResultat = { 0.0, 0.0 };
	sResultat.dReel =\
		z1.dReel * z2.dReel\
		- z1.dImaginaire * z2.dImaginaire;
	sResultat.dImaginaire =\
		z1.dReel * z2.dImaginaire\
		+ z1.dImaginaire * z2.dReel;
	return sResultat;
}

struct sComplexe ConjugueComplexe(\
	struct sComplexe z )
{
	struct sComplexe sResultat =\
		{ z.dReel, -z.dImaginaire };
	return sResultat;
}

struct sComplexe DivisionComplexeReel(\
	struct sComplexe z, double r )
{
	struct sComplexe sResultat = { 0.0, 0.0 };
	sResultat.dReel = z.dReel / r;
	sResultat.dImaginaire = z.dImaginaire / r;
	return sResultat;
}

struct sComplexe DivisionComplexes(\
	struct sComplexe z1, struct sComplexe z2 )
{
	struct sComplexe sResultat = { 0.0, 0.0 };
	struct sComplexe sNumerateur = { 0.0, 0.0 };
	struct sComplexe sDenominateur = { 0.0, 0.0 };
	sNumerateur = MultiplicationComplexes(\
		z1, ConjugueComplexe( z2 ) );
	sDenominateur = MultiplicationComplexes(\
		z2, ConjugueComplexe( z2 ) );
	sResultat = DivisionComplexeReel(\
		sNumerateur, sDenominateur.dReel );
	return sResultat;
}

void AfficherComplexePolaire(\
	struct sComplexe z, unsigned int iPrecisionR, unsigned int iPrecisionT )
{
	char cControleR[6] = "%.3lf";
	char cControleT[6] = "%.3lf";
	double dRayon = 0.0;
	double dTheta = 0.0;
	if( iPrecisionR < 10 )
	{
		cControleR[2] = (char)iPrecisionR + '0';
	}
	else
	{
		return;
	}
	if( iPrecisionT < 10 )
	{
		cControleT[2] = (char)iPrecisionT + '0';
	}
	else
	{
		return;
	}
	dRayon = sqrt( z.dReel * z.dReel + z.dImaginaire * z.dImaginaire );
	dTheta = acos( z.dReel / dRayon );
	if( z.dImaginaire < 0.0 )
	{
		dTheta = -dTheta;
	}
	dTheta = dTheta * 180.0 / PI;
	printf( cControleR, dRayon );
	printf( " * exp[" );
	printf( cControleT, dTheta );
	printf( "i]" );
	return;
}
