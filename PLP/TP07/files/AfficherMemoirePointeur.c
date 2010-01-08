# include <stdlib.h>
# include <stdio.h>

int main( int argc, char ** argv )
{
	int iEntier = 0;
	int * piEntier = &iEntier;
	printf( "Entrer un entier : " );
	scanf( "%d", piEntier );
	printf( "La valeur est %d\n", iEntier );
	printf( "L'adresse memoire est %p\n", piEntier );
	return EXIT_SUCCESS;
}
