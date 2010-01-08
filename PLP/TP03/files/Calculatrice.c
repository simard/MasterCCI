# include <stdlib.h>
# include <stdio.h>

int main( int argc, char ** argv )
{
	int iA = 0, iB = 0;
	char cOperateur = '\0';
	printf( "### Calculatrice ###\n" );
	printf( "Entrez un calcul (A <operateur> B)\n" );
	scanf( "%d%c%d", &iA, &cOperateur, &iB );
	switch( cOperateur )
	{
		case '+' :
		{
			printf( "Resultat = %d\n", iA + iB );
			break;
		}
		case '-' :
		{
			printf( "Resultat = %d\n", iA - iB );
			break;
		}
		case '*' :
		{
			printf( "Resultat = %d\n", iA * iB );
			break;
		}
		case '/' :
		{
			printf( "Resultat = %d\n", iA / iB );
			break;
		}
		default :
		{
			printf( "Operateur incorrect\n" );
			return EXIT_FAILURE;
		}
	}
	printf( "### Fin du programme ###\n" );
	return EXIT_SUCCESS;
}
