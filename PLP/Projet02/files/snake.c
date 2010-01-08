# include <stdlib.h>
# include <stdio.h>
# include <time.h>

# define FALSE 0
# define TRUE 1

# define NB_SNAKE 1

typedef struct sPoint
{
	unsigned int x;
	unsigned int y;
} Point;

typedef enum eDir
{
	HAUT = 94,
	BAS = 118,
	GAUCHE = 60,
	DROITE = 62
} Dir;

typedef struct sTete
{
	Point SnakePos;
	Dir SnakeDir;
} Tete;

void attendre( unsigned int seconds );
void initialisation( char * const cPlateau, unsigned int iHauteur, unsigned int iLargeur, Tete * const tTete, unsigned int iNbSnake );
void afficher_cadre( char * cPlateau, unsigned int iHauteur, unsigned int iLargeur );
unsigned int parcours_devant( char * const cPlateau, unsigned int iHauteur, unsigned int iLargeur, Tete * tTete );
unsigned int parcours_gauche( char * const cPlateau, unsigned int iHauteur, unsigned int iLargeur, Tete * tTete );
unsigned int parcours_droite( char * const cPlateau, unsigned int iHauteur, unsigned int iLargeur, Tete * tTete );
unsigned int evolution( char * const cPlateau, unsigned int iHauteur, unsigned int iLargeur, Tete * const tTete , unsigned int iNbSnake );
void statistiques( char * const cPlateau, unsigned int iHauteur, unsigned int iLargeur );

int main( int argc, char ** argv )
{
	unsigned iLargeur = 0, iHauteur = 0;
	unsigned int iNbSnake = 0;
	unsigned int isFini = 0;
	unsigned int iTemps = 0;

	if( argc < 4 )
	{
		printf( "Mauvaise utilisation du programme\n" );
		printf( "snake <LARGEUR>x<HAUTEUR> <NB_SERPENTS> <TEMPS>\n" );
		return EXIT_FAILURE;
	}
	sscanf( argv[1], "%dx%d", &iLargeur, &iHauteur );
	char cPlateau[iHauteur*iLargeur];
	sscanf( argv[2], "%d", &iNbSnake ); 
	Tete tTete[iNbSnake];
	sscanf( argv[3], "%d", &iTemps );

	initialisation( (char * const)cPlateau, iHauteur, iLargeur, tTete , iNbSnake );
	srand( time( NULL ) );
	system( "clear" );

	while( !isFini )
	{
		attendre( iTemps );

		system( "clear" );
		afficher_cadre( (char * const)cPlateau, iHauteur, iLargeur );
		isFini = evolution( (char * const)cPlateau, iHauteur, iLargeur, tTete, iNbSnake );

	}
	statistiques( (char * const)cPlateau, iHauteur, iLargeur );
	return EXIT_SUCCESS;
}

void attendre( unsigned int useconds )
{
	clock_t fin;
	fin = clock () + useconds * CLOCKS_PER_SEC / 1000 ;
	while( clock() < fin ){}
	return;
}

void initialisation( char * const cPlateau, unsigned int iHauteur, unsigned int iLargeur, Tete * const tTete, unsigned int iNbSnake )
{
	unsigned int i = 0;
	unsigned int j = 0;

	srand( time( NULL ) );
	for( i = 0; i < iHauteur; i++ )
	{
		for( j = 0; j < iLargeur; j++ )
		{
			cPlateau[i*iLargeur+j] = ' ';
		}
	}
	for( i = 0; i < iNbSnake; i++ )
	{
		do
		{
			tTete[i].SnakePos.x = (int)( (double)rand()/((double)RAND_MAX + 1.0) * (double)iHauteur );
			tTete[i].SnakePos.y = (int)( (double)rand()/((double)RAND_MAX + 1.0) * (double)iLargeur );
		} while( cPlateau[tTete[i].SnakePos.x*iLargeur+tTete[i].SnakePos.y] != ' ' );
		switch( (int)( (double)rand()/((double)RAND_MAX + 1.0) * 4.0 ) )
		{
			case 0 :
				cPlateau[tTete[i].SnakePos.x*iLargeur+tTete[i].SnakePos.y] = HAUT;
				tTete[i].SnakeDir = HAUT ;
				break;
			case 1 :
				cPlateau[tTete[i].SnakePos.x*iLargeur+tTete[i].SnakePos.y] = BAS;
				tTete[i].SnakeDir = BAS ;
				break;
			case 2 :
				cPlateau[tTete[i].SnakePos.x*iLargeur+tTete[i].SnakePos.y] = GAUCHE;
				tTete[i].SnakeDir = GAUCHE ;
				break;
			case 3 :
				cPlateau[tTete[i].SnakePos.x*iLargeur+tTete[i].SnakePos.y] = DROITE;
				tTete[i].SnakeDir = DROITE ;
				break;
			default :
				break;
		}
	}
	return;
}

void afficher_cadre( char * const cPlateau, unsigned int iHauteur, unsigned int iLargeur )
{
	unsigned int i = 0;
	unsigned int j = 0;
	for( i = 0; i < iLargeur + 2; i++ )
	{
		printf( "#" );
	}
	printf( "\n" );
	for( i = 0; i < iHauteur; i++ )
	{
		printf( "#" );
		for( j = 0; j < iLargeur; j++ )
		{
			printf( "%c", cPlateau[i*iLargeur+j] );
		}
		printf( "#\n" );
	}
	for( i = 0; i < iLargeur + 2; i++ )
	{
		printf( "#" );
	}
	printf( "\n" );
	return;
}

unsigned int parcours_devant( char * const cPlateau, unsigned int iHauteur, unsigned int iLargeur, Tete * tTete )
{
	switch( tTete->SnakeDir )
	{
		case HAUT :
			if( tTete->SnakePos.x == 0 )
			{
				return 0;
			}
			if( cPlateau[(tTete->SnakePos.x-1)*iLargeur+tTete->SnakePos.y] != ' ')
			{
				return 0;
			}
			else
			{
				cPlateau[(tTete->SnakePos.x-1)*iLargeur+tTete->SnakePos.y] = HAUT;
				tTete->SnakePos.x = tTete->SnakePos.x-1 ;
				tTete->SnakeDir = HAUT ;
				return 1;
			}
			break;
		case BAS :
			if( tTete->SnakePos.x == iHauteur-1 )
			{
				return 0;
			}
			if( cPlateau[(tTete->SnakePos.x+1)*iLargeur+tTete->SnakePos.y] != ' ' )
			{
				return 0;
			}
			else
			{
				cPlateau[(tTete->SnakePos.x+1)*iLargeur+tTete->SnakePos.y] = BAS;
				tTete->SnakePos.x = tTete->SnakePos.x+1 ;
				tTete->SnakeDir = BAS ;
				return 1;
			}
			break;
		case GAUCHE :
			if( tTete->SnakePos.y == 0 )
			{
				return 0;
			}
			if( cPlateau[(tTete->SnakePos.x)*iLargeur+tTete->SnakePos.y-1] != ' ' )
			{
				return 0;
			}
			else
			{
				cPlateau[(tTete->SnakePos.x)*iLargeur+tTete->SnakePos.y-1] = GAUCHE;
				tTete->SnakePos.y = tTete->SnakePos.y-1 ;
				tTete->SnakeDir = GAUCHE ;
				return 1;
			}
			break;
		case DROITE :
			if( tTete->SnakePos.y == iLargeur-1 )
			{
				return 0;
			}
			if( cPlateau[(tTete->SnakePos.x)*iLargeur+tTete->SnakePos.y+1] != ' ' )
			{
				return 0;
			}
			else
			{
				cPlateau[(tTete->SnakePos.x)*iLargeur+tTete->SnakePos.y+1] = DROITE;
				tTete->SnakePos.y = tTete->SnakePos.y+1 ;
				tTete->SnakeDir = DROITE ;
				return 1;
			}
			break;
	}
	return 0;
}

unsigned int parcours_gauche( char * const cPlateau, unsigned int iHauteur, unsigned int iLargeur, Tete * tTete )
{
	switch( tTete->SnakeDir )
	{
		case HAUT :
			if( tTete->SnakePos.y == 0 )
			{
				return 0;
			}
			if( cPlateau[(tTete->SnakePos.x)*iLargeur+tTete->SnakePos.y-1] != ' ')
			{
				return 0;
			}
			else
			{
				cPlateau[(tTete->SnakePos.x)*iLargeur+tTete->SnakePos.y-1] = GAUCHE;
				tTete->SnakePos.y = tTete->SnakePos.y-1 ;
				tTete->SnakeDir = GAUCHE ;
				return 1;
			}
			break;
		case BAS :
			if( tTete->SnakePos.x == iLargeur-1 )
			{
				return 0;
			}
			if( cPlateau[(tTete->SnakePos.x)*iLargeur+tTete->SnakePos.y+1] != ' ' )
			{
				return 0;
			}
			else
			{
				cPlateau[(tTete->SnakePos.x)*iLargeur+tTete->SnakePos.y+1] = DROITE;
				tTete->SnakePos.y = tTete->SnakePos.y+1 ;
				tTete->SnakeDir = DROITE ;
				return 1;
			}
			break;
		case DROITE :
			if( tTete->SnakePos.x == 0 )
			{
				return 0;
			}
			if( cPlateau[(tTete->SnakePos.x-1)*iLargeur+tTete->SnakePos.y] != ' ' )
			{
				return 0;
			}
			else
			{
				cPlateau[(tTete->SnakePos.x-1)*iLargeur+tTete->SnakePos.y] = HAUT;
				tTete->SnakePos.x = tTete->SnakePos.x-1 ;
				tTete->SnakeDir = HAUT ;
				return 1;
			}
			break;
		case GAUCHE :
			if( tTete->SnakePos.x == iHauteur-1 )
			{
				return 0;
			}
			if( cPlateau[(tTete->SnakePos.x+1)*iLargeur+tTete->SnakePos.y] != ' ' )
			{
				return 0;
			}
			else
			{
				cPlateau[(tTete->SnakePos.x+1)*iLargeur+tTete->SnakePos.y] = BAS;
				tTete->SnakePos.x = tTete->SnakePos.x+1 ;
				tTete->SnakeDir = BAS ;
				return 1;
			}
			break;
	}
	return 0;
}

unsigned int parcours_droite( char * const cPlateau, unsigned int iHauteur, unsigned int iLargeur, Tete * tTete )
{
	switch( tTete->SnakeDir )
	{
		case HAUT :
			if( tTete->SnakePos.y == iLargeur-1 )
			{
				return 0;
			}
			if( cPlateau[(tTete->SnakePos.x)*iLargeur+tTete->SnakePos.y+1] != ' ')
			{
				return 0;
			}
			else
			{
				cPlateau[(tTete->SnakePos.x)*iLargeur+tTete->SnakePos.y+1] = DROITE;
				tTete->SnakePos.y = tTete->SnakePos.y+1 ;
				tTete->SnakeDir = DROITE ;
				return 1;
			}
			break;
		case BAS :
			if( tTete->SnakePos.y == 0 )
			{
				return 0;
			}
			if( cPlateau[(tTete->SnakePos.x)*iLargeur+tTete->SnakePos.y-1] != ' ' )
			{
				return 0;
			}
			else
			{
				cPlateau[(tTete->SnakePos.x)*iLargeur+tTete->SnakePos.y-1] = GAUCHE;
				tTete->SnakePos.y = tTete->SnakePos.y-1 ;
				tTete->SnakeDir = GAUCHE ;
				return 1;
			}
			break;
		case GAUCHE :
			if( tTete->SnakePos.x == 0 )
			{
				return 0;
			}
			if( cPlateau[(tTete->SnakePos.x-1)*iLargeur+tTete->SnakePos.y] != ' ' )
			{
				return 0;
			}
			else
			{
				cPlateau[(tTete->SnakePos.x-1)*iLargeur+tTete->SnakePos.y] = HAUT;
				tTete->SnakePos.x = tTete->SnakePos.x-1 ;
				tTete->SnakeDir = HAUT ;
				return 1;
			}
			break;
		case DROITE :
			if( tTete->SnakePos.x == iHauteur-1 )
			{
				return 0;
			}
			if( cPlateau[(tTete->SnakePos.x+1)*iLargeur+tTete->SnakePos.y] != ' ' )
			{
				return 0;
			}
			else
			{
				cPlateau[(tTete->SnakePos.x+1)*iLargeur+tTete->SnakePos.y] = BAS;
				tTete->SnakePos.x = tTete->SnakePos.x+1 ;
				tTete->SnakeDir = BAS ;
				return 1;
			}
			break;
	}
	return 0;
}

unsigned int evolution( char * const cPlateau, unsigned int iHauteur, unsigned int iLargeur, Tete * const tTete , unsigned int iNbSnake )
{
	unsigned int isFini = 1 ;
	unsigned int i = 0;
	for( i = 0; i < iNbSnake; i++ )
	{
		if( !parcours_devant( cPlateau, iHauteur, iLargeur, &tTete[i] ) )
		{
			if( !parcours_gauche( cPlateau, iHauteur, iLargeur, &tTete[i] ) )
			{
				if( parcours_droite( cPlateau, iHauteur, iLargeur,  &tTete[i] ) )
				{
					isFini = 0;
				}
			}
			else
			{
				isFini = 0 ;
			}
		}
		else
		{
			isFini = 0 ;
		}
	}
	return isFini;
}

void statistiques( char * const cPlateau, unsigned int iHauteur, unsigned int iLargeur )
{
	unsigned int i = 0;
	unsigned int j = 0;
	unsigned int caseHAUT = 0;
	unsigned int caseBAS = 0;
	unsigned int caseGAUCHE = 0;
	unsigned int caseDROITE = 0;
	unsigned int total = 0;
	for( i = 0; i < iHauteur; i++ )
	{
		for( j = 0; j < iLargeur; j++ )
		{
			switch( cPlateau[i*iLargeur+j] )
			{
				case HAUT :
					caseHAUT++;
					break;
				case BAS :
					caseBAS++;
					break;
				case GAUCHE :
					caseGAUCHE++;
					break;
				case DROITE :
					caseDROITE++;
					break;
				default :
					break;
			}
		}
	}
	total = caseHAUT + caseBAS + caseGAUCHE + caseDROITE;
	printf( "Le plateau est rempli a %.1f (%d/%d) dont :\n", 100.0*(double)total/(double)(iLargeur*iHauteur), total, iLargeur*iHauteur );
	printf( "- %.1f '%c' (%d/%d)\n", 100.0*(double)caseHAUT/(double)total, HAUT, caseHAUT, total );
	printf( "- %.1f '%c' (%d/%d)\n", 100.0*(double)caseBAS/(double)total, BAS, caseBAS, total );
	printf( "- %.1f '%c' (%d/%d)\n", 100.0*(double)caseGAUCHE/(double)total, GAUCHE, caseGAUCHE, total );
	printf( "- %.1f '%c' (%d/%d)\n", 100.0*(double)caseDROITE/(double)total, DROITE, caseDROITE, total );
	return;
}
