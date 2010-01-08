# include <stdlib.h>
# include <stdio.h>

int main( int argc, char ** argv )
{
	unsigned long int iFactorielle = 1;
	unsigned int iNombre = 0;
	unsigned int i = 0;
	printf( "Entrer un nombre entre 0 et 15 : " );
	scanf( "%d", &iNombre );
	if( ( iNombre >= 0 ) && ( iNombre <= 15 ) )
	{
		for( i = 1; i <= iNombre; i++ )
		{
			iFactorielle *= i;
		}
		printf( "%d! = %ld\n", iNombre, iFactorielle );
	}
	else
	{
		printf( "Valeur incorrecte\n" );
	}

	return EXIT_SUCCESS;
}
