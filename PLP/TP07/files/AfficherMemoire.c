# include <stdlib.h>
# include <stdio.h>

int main( int argc, char ** argv )
{
	int iEntier = 0;
	printf( "Entrer un entier : " );
	scanf( "%d", &iEntier );
	printf( "La valeur est %d\n", iEntier );
	printf( "L'adresse memoire est %p\n", &iEntier );
	return EXIT_SUCCESS;
}
