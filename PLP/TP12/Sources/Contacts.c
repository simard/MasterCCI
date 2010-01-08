# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct sContact
{
	char * cNom;
	char * cPrenom;
	char * cCourriel;
	struct sContact * pSuiv;
} Contact;

void LibererContact( Contact * pContact )
{
	if( pContact != NULL )
	{
		free( pContact->cNom );
		free( pContact->cPrenom );
		free( pContact->cCourriel );
		free( pContact );
	}
	return;
}

void AffichageContact( Contact * c )
{
	printf( "L'adresse de courriel de %s %s ", c->cNom, c->cPrenom );
	printf( "est %s\n", c->cCourriel );
	return;
}

Contact * AjouterContact( Contact * pDebut )
{
	Contact * pNouveau = NULL;
	Contact * pTemp = pDebut;
	char cTemp[256];
	pNouveau = (Contact *) malloc( sizeof( Contact ) );
	printf( "----- Creation -----\n" );
	printf( "Entrer votre nom : " );
	scanf( "%s", cTemp );
	pNouveau->cNom = (char *) malloc(\
		( strlen( cTemp ) + 1 ) * sizeof( char ) );
	strcpy( pNouveau->cNom, cTemp );
	printf( "Entrer votre prenom : " );
	scanf( "%s", cTemp );
	pNouveau->cPrenom = (char *) malloc(\
		( strlen( cTemp ) + 1 ) * sizeof( char ) );
	strcpy( pNouveau->cPrenom, cTemp );
	printf( "Entrer votre courriel : " );
	scanf( "%s", cTemp );
	pNouveau->cCourriel = (char *) malloc(\
		( strlen( cTemp ) + 1 ) * sizeof( char ) );
	strcpy( pNouveau->cCourriel, cTemp );
	pNouveau->pSuiv = NULL;
	if( pDebut == NULL )
	{
		return pNouveau;
	}
	while( pTemp->pSuiv != NULL )
	{
		pTemp = pTemp->pSuiv;
	}
	pTemp->pSuiv = pNouveau;
	return pDebut;
}

Contact * SupprimerContact( Contact * pDebut )
{
	Contact * pTemp = pDebut;
	Contact * pPrec = NULL;
	char cNom[256];
	char cChoix = '\0';
	printf( "----- Suppression -----\n" );
	printf( "Entrer le nom a supprimer : " );
	scanf( "%s", cNom );
	while( pTemp != NULL )
	{
		if( strcmp( pTemp->cNom, cNom ) == 0 )
		{
			printf( "----- Suppression de %s %s (%s) -----\n",\
				pTemp->cPrenom, pTemp->cNom, pTemp->cCourriel );
			printf( "o - Oui\n" );
			printf( "n - Non\n" );
			printf( "Choix : " );
			getchar();
			scanf( "%c", &cChoix );
			if( cChoix == 'o' )
			{
				if( pPrec != NULL )
				{
					pPrec->pSuiv = pTemp->pSuiv;
					LibererContact( pTemp );
					pTemp = pPrec->pSuiv;
				}
				else
				{
					pDebut = pTemp->pSuiv;
					LibererContact( pTemp );
					pTemp = pDebut;
				}
			}
		}
		else
		{
			pPrec = pTemp;
			pTemp = pTemp->pSuiv;
		}
	}
	return pDebut;
}

Contact * ModifierContact( Contact * pDebut )
{
	Contact * pTemp = pDebut;
	char cChoix = '\0';
	char cNom[256];
	char cChaine[256];
	printf( "----- Modification -----\n" );
	printf( "Entrer le nom a modifier : " );
	scanf( "%s", cNom );
	while( pTemp != NULL )
	{
		if( strcmp( pTemp->cNom, cNom ) == 0 )
		{
			do
			{
				printf( "----- Modification de %s %s (%s) -----\n",\
					pTemp->cPrenom, pTemp->cNom, pTemp->cCourriel );
				printf( "n - Modifier le nom\n" );
				printf( "p - Modifier le prenom\n" );
				printf( "c - Modifier l'adresse de courriel\n" );
				printf( "s - Ne pas modifier\n" );
				printf( "Choix : " );
				getchar();
				scanf( "%c", &cChoix );
				switch( cChoix )
				{
					case 'n' :
					case 'N' :
						printf( "Entrer le nouveau nom : " );
						scanf( "%s", cChaine );
						free( pTemp->cNom );
						pTemp->cNom = (char *) malloc(\
							strlen( cChaine ) * sizeof( char ) );
						strcpy( pTemp->cNom, cChaine );
						break;
					case 'p' :
					case 'P' :
						printf( "Entrer le nouveau prenom : " );
						scanf( "%s", cChaine );
						free( pTemp->cPrenom );
						pTemp->cPrenom = (char *) malloc(\
							strlen( cChaine ) * sizeof( char ) );
						strcpy( pTemp->cPrenom, cChaine );
						break;
					case 'c' :
					case 'C' :
						printf( "Entrer la nouvelle adresse de courriel : " );
						scanf( "%s", cChaine );
						free( pTemp->cCourriel );
						pTemp->cCourriel = (char *) malloc(\
							strlen( cChaine ) * sizeof( char ) );
						strcpy( pTemp->cCourriel, cChaine );
						break;
					case 's' :
					case 'S' :
						printf( "Pas de modification sur ce contact\n" );
						break;
					default :
						printf( "Choix incorrect\n" );
						cChoix = 'r';
						break;
				}
			} while( cChoix == 'r' );
		}
		pTemp = pTemp->pSuiv;
	}
	return pDebut;
}

void AffichageContacts( Contact * c )
{
	printf( "----- Affichage -----\n" );
	while( c != NULL )
	{
		AffichageContact( c );
		c = c->pSuiv;
	}
	return;
}

void LibererCarnet( Contact * pDebut )
{
	Contact * pTemp = NULL;
	if( pDebut == NULL )
	{
		return;
	}
	while( pDebut->pSuiv != NULL )
	{
		pTemp = pDebut;
		pDebut = pDebut->pSuiv;
		LibererContact( pTemp );
	}
	return;
}

void EnregistrerFichier( Contact * pDebut )
{
	FILE * pFichier = NULL;
	char cNomFichier[256];
	printf( "----- Enregistrer -----\n" );
	printf( "Entrer le nom du fichier : " );
	scanf( "%s", cNomFichier );
	pFichier = fopen( cNomFichier, "w" );
	while( pDebut != NULL )
	{
		fprintf( pFichier, "%s\n", pDebut->cNom );
		fprintf( pFichier, "%s\n", pDebut->cPrenom );
		fprintf( pFichier, "%s\n", pDebut->cCourriel );
		fprintf( pFichier, "\n" );
		pDebut = pDebut->pSuiv;
	}
	return;
}

Contact * ImporterFichier()
{
	FILE * pFichier = NULL;
	Contact * pDebut = NULL;
	Contact * pTemp = NULL;
	char cNomFichier[256];
	char cTemp[256];
	printf( "----- Importer -----\n" );
	printf( "Entrer le nom du fichier : " );
	scanf( "%s", cNomFichier );
	pFichier = fopen( cNomFichier, "r" );
	if( pFichier == NULL )
	{
		printf( "Erreur de lecture du fichier\n" );
		return NULL;
	}
	while( fscanf( pFichier, "%s\n", cTemp ) != EOF )
	{
		pTemp = (Contact *) malloc( sizeof( Contact ) );
		pTemp->cNom = (char *) malloc(\
			strlen( cTemp ) * sizeof( char ) );
		strcpy( pTemp->cNom, cTemp );
		if( fscanf( pFichier, "%s\n", cTemp ) != EOF )
		{
			pTemp->cPrenom = (char *) malloc(\
				strlen( cTemp ) * sizeof( char ) );
			strcpy( pTemp->cPrenom, cTemp );
		}
		if( fscanf( pFichier, "%s\n\n", cTemp ) != EOF )
		{
			pTemp->cCourriel = (char *) malloc(\
				strlen( cTemp ) * sizeof( char ) );
			strcpy( pTemp->cCourriel, cTemp );
		}
		pTemp->pSuiv = pDebut;
		pDebut = pTemp;
	}
	return pDebut;
}

int main( int argc, char ** argv )
{
	Contact * DebutCarnet = NULL;
	char cChoix = '\0';
	do
	{
		printf( "----- Menu -----\n" );
		printf( "c - Creer un contact\n" );
		printf( "m - Modifier un contact\n" );
		printf( "s - Supprimer un contact\n" );
		printf( "a - Afficher les contacts\n" );
		printf( "e - Enregistrer le carnet d'adresses\n" );
		printf( "i - Importer un carnet d'adresses\n" );
		printf( "q - Quitter\n" );
		printf( "Choix : " );
		scanf( "%c", &cChoix );
		switch( cChoix )
		{
			case 'c' :
			case 'C' :
				DebutCarnet = AjouterContact( DebutCarnet );
				break;
			case 'm' :
			case 'M' :
				DebutCarnet = ModifierContact( DebutCarnet );
				break;
			case 's' :
			case 'S' :
				DebutCarnet = SupprimerContact( DebutCarnet );
				break;
			case 'a' :
			case 'A' :
				AffichageContacts( DebutCarnet );
				break;
			case 'e' :
			case 'E' :
				EnregistrerFichier( DebutCarnet );
				break;
			case 'i' :
			case 'I' :
				DebutCarnet = ImporterFichier();
				break;
			case 'q' :
			case 'Q' :
				LibererCarnet( DebutCarnet );
				return 0;
			default :
				printf( "Choix incorrect\n" );
				break;
		}
		getchar();
	} while( cChoix != 'q' );

	return 0;
}
