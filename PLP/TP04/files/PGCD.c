# include <stdlib.h>
# include <stdio.h>

int main( int argc, char ** argv )
{
	unsigned int iNombre1 = 0, iNombre2 = 0;
	unsigned int iDividende = 0, iDiviseur = 0;
	unsigned int iReste = 1;

	printf( "Entrer le premier nombre : " );
	scanf( "%d", &iNombre1 );
	printf( "Entrer le second nombre : " );
	scanf( "%d", &iNombre2 );
	iDividende = iNombre1;
	iDiviseur = iNombre2;
	while( iReste != 0 )
	{
		iReste = iDividende % iDiviseur;
		iDividende = iDiviseur;
		iDiviseur = iReste;
	}
	printf( "PGCD(%d,%d) = %d\n",\
		iNombre1, iNombre2, iDividende );

	return EXIT_SUCCESS;
}
