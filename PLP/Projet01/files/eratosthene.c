# include <stdio.h>

int main( int argc, char ** argv )
{
	int iMax = 0;
	unsigned int iEntier = 0;
	unsigned int iFacteur = 0;
	int iErreur = 0;
	printf( "Entrer un entier : " );
	iErreur = scanf( "%d", &iMax );
	if( ( iErreur == EOF ) || ( iMax < 2 ) )
	{
		printf( "Il faut choisir un nombre entier superieur a 2.\n" );
		return 1;
	}
	printf( "Voici le crible d'Eratosthene jusqu'a l'entier %u\n", iMax );
	unsigned int iCrible[iMax];
	for( iEntier = 0; iEntier < iMax; iEntier++ )
	{
		iCrible[iEntier] = 0;
	}
	iCrible[0] = 1;
	for( iEntier = 3; iEntier < iMax; iEntier++ )
	{
		for( iFacteur = 1; iFacteur < iEntier; iFacteur++ )
		{
			if( ( iCrible[iFacteur] == 0 ) && ( ( (iEntier+1) % (iFacteur+1) ) == 0 ) )
			{
				iCrible[iEntier] = 1;
				break;
			}
		}
	}
	for( iEntier = 0; iEntier < iMax; iEntier++ )
	{
		if( iCrible[iEntier] == 0 )
		{
			printf( "%d\n", iEntier+1 );
		}
	}

	return 0;
}
