# include <stdlib.h>
# include <stdio.h>

struct sPoint
{
	float fAbscisse;
	float fOrdonnee;
};

int main( int argc, char ** argv )
{
	struct sPoint UnPoint = {2.0, -4.3};
	float fX = 0.0, fY = 0.0;

	fX = UnPoint.fAbscisse;
	fY = UnPoint.fOrdonnee;
	printf( "Le point est (%f.3,%f.3)\n", fX, fY );

	return EXIT_SUCCESS;
}
