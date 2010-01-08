# include "dictio.h"

void ecrire_mot( FILE * fFichier, Mot * const m )
{
	Mot * tempM = m;
	while( tempM )
	{
		fprintf( fFichier, "    <mot lang='%s'>\n", tempM->lang );
		fprintf( fFichier, "      %s\n", tempM->mot );
		fprintf( fFichier, "    </mot>\n" );
		tempM = tempM->suiv;
	}
	return;
}

void ecrire_dictionnaire( Dictionnaire * const d, const char * nomFichier )
{
	Dictionnaire * tempD = d;
	FILE * fFichier = NULL;
	fFichier = fopen( nomFichier, "w" );
	fprintf( fFichier, "<?xml version='1.0' encoding='UTF-8'?>\n" );
	fprintf( fFichier, "<dictionary>\n" );
	while( tempD )
	{
		fprintf( fFichier, "  <trad id='%u'>\n", tempD->id );
		ecrire_mot( fFichier, tempD->m );
		fprintf( fFichier, "  </trad>\n" );
		tempD = tempD->suiv;
	}
	fprintf( fFichier, "</dictionary\x3E" );
	fclose( fFichier );
	return;
}

Dictionnaire * lire_dictionnaire( const char * nomFichier )
{
	FILE * fFichier = NULL;
	Dictionnaire * newD = NULL;
	unsigned int newId = 0;
	char newLang[3];
	char newMot[TAILLE_TAMPON];
	char balise[TAILLE_TAMPON];
	unsigned char isNewTrad = 1;
	fFichier = fopen( nomFichier, "r" );
	if( fFichier == NULL )
	{
		printf( "ERREUR - Probleme d'ouverture du fichier\n" );
	}
	fscanf( fFichier, "<?xml version='1.0' encoding='UTF-8'?>\n" );
	fscanf( fFichier, "<%[^>]>", balise );
	if( strcmp( "dictionary", balise ) )
	{
		printf( "ERREUR - Fichier corrompu\n" );
		return NULL;
	}
	while( 1 )
	{
		fscanf( fFichier, "%*[^<]<%[^>]>", balise );
		if( !strncmp( "mot", balise, strlen( "mot" ) ) )
		{
			sscanf( balise, "mot lang='%2s'", newLang );
			fscanf( fFichier, "%s", newMot );
			if( isNewTrad )
			{
				newD = ajouter_trad( newD, 0, newMot, newLang );
				isNewTrad = 0;
			}
			else
			{
				newD = ajouter_trad( newD, newId, newMot, newLang );
			}
			fscanf( fFichier, "%*[^<]<%[^>]>", balise );
			continue;
		}
		if( !strncmp( "trad", balise, strlen( "trad" ) ) )
		{
			sscanf( balise, "trad id='%u'", &newId );
			isNewTrad = 1;
			continue;
		}
		if( !strncmp( "/dictionary", balise, strlen( "/dictionary" ) ) )
		{
			break;
		}
	}
	fclose( fFichier );
	return newD;
}
