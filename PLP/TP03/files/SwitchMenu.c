# include <stdlib.h>
# include <stdio.h>

int main( int argc, char ** argv )
{
	printf( "Faites votre choix\n" );
	printf( "a - Programme sur l'age\n" );
	printf( "q - Quitter\n" );
	printf( "Choix : " );
	switch( getchar() )
	{
		case 'a' :
		{
			unsigned int iAge = 0;
			printf( "Entrez votre age : " );
			scanf( "%d", &iAge );
			if( iAge < 18 )
			{
				printf( "Vous etes mineur\n" );
			}
			else
			{
				printf( "Vous etes majeur\n" );
			}
			break;
		}
		case 'q' :
		{
			printf( "Au revoir\n" );
			return EXIT_SUCCESS;
		}
		default :
		{
			printf( "Choix non-autorise\n" );
			return EXIT_FAILURE;
		}
	}
	return EXIT_SUCCESS;
}
