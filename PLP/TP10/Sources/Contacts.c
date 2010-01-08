# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct sContact
{
	char * cNom;
	char * cPrenom;
	char * cCourriel;
} Contact;

void AffichageContact( Contact * c )
{
	printf( "L'adresse de courriel de %s %s ", c->cNom, c->cPrenom );
	printf( "est %s\n", c->cCourriel );
	return;
}

int main( int argc, char ** argv )
{
	Contact UnContact;
	char cTemp[256];
	printf( "Entrer votre nom : " );
	scanf( "%s", cTemp );
	UnContact.cNom = (char *) malloc(\
		( strlen( cTemp ) + 1 ) * sizeof( char ) );
	strcpy( UnContact.cNom, cTemp );
	printf( "Entrer votre prenom : " );
	scanf( "%s", cTemp );
	UnContact.cPrenom = (char *) malloc(\
		( strlen( cTemp ) + 1 ) * sizeof( char ) );
	strcpy( UnContact.cPrenom, cTemp );
	printf( "Entrer votre courriel : " );
	scanf( "%s", cTemp );
	UnContact.cCourriel = (char *) malloc(\
		( strlen( cTemp ) + 1 ) * sizeof( char ) );
	strcpy( UnContact.cCourriel, cTemp );
	AffichageContact( &UnContact );

	free( UnContact.cNom );
	free( UnContact.cPrenom );
	free( UnContact.cCourriel );

	return 0;
}
