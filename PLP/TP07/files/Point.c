# include <stdlib.h>
# include <stdio.h>
# include <math.h>

# define PI 3.1415926535897932384626433

typedef struct sPoint
{
	double dX;
	double dY;
} Point;

void AffichagePoint( Point * pP );
void TranslationPoint( Point * pP, double dTX, double dTY );
void RotationPoint( Point * pP, Point * pCentreR, double dAngle );
void SymetriePoint( Point * pP, Point * pCentreS );

int main( int argc, char ** argv )
{
	Point P = { 0.0, 0.0 };
	Point CentreR = { 1.0, 0.0 };
	Point CentreS = { 1.5, 0.0 };
	AffichagePoint( &P );
	printf( "\n" );
	TranslationPoint( &P, 1.0, -2.0 );
	AffichagePoint( &P );
	printf( "\n" );
	RotationPoint( &P, &CentreR, 90.0 );
	AffichagePoint( &P );
	printf( "\n" );
	SymetriePoint( &P, &CentreS );
	AffichagePoint( &P );
	printf( "\n" );
	return EXIT_SUCCESS;
}

void AffichagePoint( Point * pP )
{
	printf( "(%.3lf,%.3lf)", pP->dX, pP->dY );
	return;
}

void TranslationPoint( Point * pP, double dTX, double dTY )
{
	pP->dX += dTX;
	pP->dY += dTY;
	return;
}

void RotationPoint( Point * pP, Point * pCentreR, double dAngle )
{
	double dR = 0.0;
	double dTheta = 0.0;
	Point PTemp = { 0.0, 0.0 };
	PTemp.dX = pP->dX - pCentreR->dX;
	PTemp.dY = pP->dY - pCentreR->dY;
	dR = sqrt( PTemp.dX * PTemp.dX + PTemp.dY * PTemp.dY );
	dTheta = acos( PTemp.dX / dR );
	if( PTemp.dY < 0.0 )
	{
		dTheta = -dTheta;
	}
	dTheta = dTheta * 180.0 / PI;
	dTheta += dAngle;
	dTheta *= PI / 180.0;
	pP->dX = dR * cos( dTheta ) + pCentreR->dX;
	pP->dY = dR * sin( dTheta ) + pCentreR->dY;
	return;
}

void SymetriePoint( Point * pP, Point * pCentreS )
{
	pP->dX += 2.0 * ( pCentreS->dX - pP->dX );
	pP->dY += 2.0 * ( pCentreS->dY - pP->dY );
	return;
}
