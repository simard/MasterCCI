# include "dictio.h"

void menu( Dictionnaire * d );
void afficher_mot( Mot * const m );
void afficher_dictionnaire( Dictionnaire * const d );
void free_dictionnaire( Dictionnaire * d );
Mot * ajouter_mot( Mot * const m, char * const newMot, char * const newLang );
Dictionnaire * ajouter_trad( Dictionnaire * const d, unsigned char const id, char * const newMot, char * const newLang );

int main( int argc, char ** argv )
{
	Dictionnaire * d = NULL;
	if( argc > 1 )
	{
		d = lire_dictionnaire( argv[1] );
	}
	menu( d );

	free_dictionnaire( d );

	return EXIT_SUCCESS;
}

void menu( Dictionnaire * d )
{
	unsigned char cChoix = '\0';
	unsigned int id = 0;
	char tampon[TAILLE_TAMPON];
	char tempL[3];
	while( 1 )
	{
		system( "clear" );
		printf( "1 - Afficher le dictionnaire\n" );
		printf( "2 - Ajouter un mot dans le dictionnaire\n" );
		printf( "3 - Sauvegarder le dictionnaire\n" );
		printf( "\n" );
		printf( "0 - Quitter\n" );
		printf( "Choix>" );
		scanf( "%1s", &cChoix );
		switch( cChoix )
		{
			case '1' :
				system( "clear" );
				afficher_dictionnaire( d );
				printf( "Appuyez sur n'importe quelle touche...\n" );
				getchar();
				getchar();
				break;
			case '2' :
				printf( "Entrer l'indice de la traduction (0 si nouveau mot)>" );
				scanf( "%u", &id );
				printf( "Entrer le mot>" );
				scanf( "%s", tampon );
				printf( "Entrer la langue (2 lettres)>" );
				scanf( "%2s", tempL );
				d = ajouter_trad( d, id, tampon, tempL );
				break;
			case '3' :
				printf( "Entrer le nom du fichier>" );
				scanf( "%s", tampon );
				ecrire_dictionnaire( d, tampon );
				break;
			case '0' :
				return;
			default :
				break;
		}
	}
	return;
}

void afficher_mot( Mot * const m )
{
	Mot * tempM = m;
	while( tempM )
	{
		printf( "(%s) %s\n", tempM->lang, tempM->mot );
		tempM = tempM->suiv;
	}
	return;
}

void afficher_dictionnaire( Dictionnaire * const d )
{
	Dictionnaire * tempD = d;
	while( tempD )
	{
		printf( "- %u -\n", tempD->id );
		afficher_mot( tempD->m );
		tempD = tempD->suiv;
	}
	printf( "-----\n" );
	return;
}

void free_dictionnaire( Dictionnaire * d )
{
	Dictionnaire * tempD = NULL;
	Mot * tempM = NULL;
	while( d )
	{
		tempD = d;
		while( tempD->m )
		{
			tempM = tempD->m;
			tempD->m = tempD->m->suiv;
			free( tempM );
		}
		d = d->suiv;
		free( tempD );
	}
	return;
}

Mot * ajouter_mot( Mot * const m, char * const newMot, char * const newLang )
{
	Mot * tempM = m;
	Mot * newM = (Mot *) malloc ( sizeof( Mot ) );
	newM->mot = (char *) malloc ( ( strlen( newMot ) + 1 ) * sizeof(char) );
	strcpy( newM->mot, newMot );
	newM->lang = (char *) malloc ( ( strlen( newLang ) + 1 ) * sizeof(char) );
	strcpy( newM->lang, newLang );
	newM->suiv = NULL;
	if( tempM )
	{
		while( tempM->suiv )
		{
			tempM = tempM->suiv;
		}
		tempM->suiv = newM;
		return m;
	}
	return newM;
}

Dictionnaire * ajouter_trad( Dictionnaire * const d, unsigned char const id, char * const newMot, char * const newLang )
{
	Dictionnaire * tempD = d;
	if( tempD )
	{
		if( id == 0 )
		{
			Dictionnaire * newD = (Dictionnaire *) malloc( sizeof( Dictionnaire ) );
			newD->m = ajouter_mot( NULL, newMot, newLang );
			while( tempD->suiv )
			{
				tempD = tempD->suiv;
			}
			newD->id = tempD->id + 1;
			newD->suiv = NULL;
			tempD->suiv = newD;
			return d;
		}
		else
		{
			while( tempD->id != id )
			{
				if( tempD->suiv == NULL )
				{
					Dictionnaire * newD = (Dictionnaire *) malloc( sizeof( Dictionnaire ) );
					newD->id = tempD->id + 1;
					newD->m = ajouter_mot( NULL, newMot, newLang );
					newD->suiv = NULL;
					tempD->suiv = newD;
					return d;
				}
				tempD = tempD->suiv;
			}
			ajouter_mot( tempD->m, newMot, newLang );
			return d;
		}
	}
	else
	{
		Dictionnaire * newD = (Dictionnaire *) malloc( sizeof( Dictionnaire ) );
		newD->id = 1;
		newD->m = ajouter_mot( NULL, newMot, newLang );
		newD->suiv = NULL;
		return newD;
	}
	return NULL;
}
