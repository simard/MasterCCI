# include <stdio.h>
# include <stdlib.h>
# include <time.h>

typedef enum eCouleur {
	CARREAU,
	TREFLE,
	COEUR,
	PIQUE
} tCouleur;
typedef enum eCarte {
	DEUX,
	TROIS,
	QUATRE,
	CINQ,
	SIX,
	SEPT,
	HUIT,
	NEUF,
	DIX,
	VALET,
	DAME,
	ROI,
	AS
} tCarte;

int main( int argc, char ** argv )
{
	unsigned int iBanque = 0;
	unsigned int iSomme = 0;
	unsigned char isFini = 'y';
	unsigned int iAs = 0;

	srand( time( NULL ) );

	iBanque = (unsigned int)( (double)rand() / ( (double)RAND_MAX + 1.0 ) * 5.0 ) + 16;

	while( 1 )
	{
		printf( "Votre score est %u", iSomme );
		if( iAs > 0 )
		{
			printf( " (avec %u as)", iAs );
		}
		printf( "\nVoulez-vous tirer une nouvelle carte [y/n] ? " );
		if( ( scanf( "%1s", &isFini ) == EOF ) || !( ( isFini == 'y' ) ^ ( isFini == 'n' ) ) )
		{
			continue;
		}
		if( isFini != 'n' )
		{
			tCouleur Couleur = (unsigned int)( (double)rand() / ( (double)RAND_MAX + 1.0 ) * 4.0 );
			tCarte Carte = (unsigned int)( (double)rand() / ( (double)RAND_MAX + 1.0 ) * 13.0 );
			printf( "Vous tirez " );
			switch( Carte )
			{
				case DEUX :
					printf( "un deux " );
					iSomme += 2;
					break;
				case TROIS :
					printf( "un trois " );
					iSomme += 3;
					break;
				case QUATRE :
					printf( "un quatre " );
					iSomme += 4;
					break;
				case CINQ :
					printf( "un cinq " );
					iSomme += 5;
					break;
				case SIX :
					printf( "un six " );
					iSomme += 6;
					break;
				case SEPT :
					printf( "un sept " );
					iSomme += 7;
					break;
				case HUIT :
					printf( "un huit " );
					iSomme += 8;
					break;
				case NEUF :
					printf( "un neuf " );
					iSomme += 9;
					break;
				case DIX :
					printf( "un dix " );
					iSomme += 10;
					break;
				case VALET :
					printf( "un valet " );
					iSomme += 10;
					break;
				case DAME :
					printf( "une dame " );
					iSomme += 10;
					break;
				case ROI :
					printf( "un roi " );
					iSomme += 10;
					break;
				case AS :
					printf( "un as " );
					iSomme += 11;
					iAs += 1;
					break;
			}
			switch( Couleur )
			{
				case CARREAU :
					printf( "de carreau\n" );
					break;
				case TREFLE :
					printf( "de trefle\n" );
					break;
				case COEUR :
					printf( "de coeur\n" );
					break;
				case PIQUE :
					printf( "de pique\n" );
					break;
			}
			if( iSomme > 21 )
			{
				if( iAs > 0 )
				{
					iSomme -= 10;
					iAs -= 1;
				}
				else
				{
					printf( "Vous avez depasse 21\nPERDU\n" );
					return 0;
				}
			}
		}
		else
		{
			printf( "Votre score est %u\n", iSomme );
			printf( "Le score de la banque est %u\n", iBanque );
			if( iSomme > iBanque )
			{
				printf( "GAGNE\n" );
			}
			else
			{
				printf( "PERDU\n" );
			}
			break;
		}
	}

	return 0;
}
