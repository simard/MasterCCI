# include <stdlib.h>
# include <stdio.h>
# include <time.h>

typedef struct sNombre
{
	unsigned int uiNombre;
	struct sNombre * pSuiv;
	struct sNombre * pPrec;
} Nombre;

Nombre * InitialiserListe( unsigned int uiNbElements )
{
	Nombre * pListe = NULL;
	Nombre * pTemp = NULL;
	unsigned int i = 0;
	srand( uiNbElements );
	for( i = 0; i < uiNbElements; i++ )
	{
		pTemp = (Nombre *) malloc( sizeof( Nombre ) );
		pTemp->uiNombre = (unsigned int)( (double)rand()\
			* (double)uiNbElements / ( (double)RAND_MAX + 1.0 ) );
		pTemp->pSuiv = pListe;
		if( pListe != NULL )
		{
			pTemp->pSuiv->pPrec = pTemp;
		}
		pTemp->pPrec = NULL;
		pListe = pTemp;
	}
	return pListe;
}

void LibererListe( Nombre * pListe )
{
	Nombre * pTemp = pListe;
	while( pTemp != NULL )
	{
		pListe = pTemp->pSuiv;
		free( pTemp );
	}
	return;
}

void AfficherListe( Nombre * pListe )
{
	while( pListe != NULL )
	{
		printf( "%u ", pListe->uiNombre );
		pListe = pListe->pSuiv;
	}
	printf( "\n" );
	return;
}

Nombre * InverserElement( Nombre * pN1, Nombre * pN2 )
{
	Nombre * pTemp = NULL;
	if( pN1->pSuiv != NULL )
	{
		pTemp = pN1->pSuiv;
		pN1->pSuiv = pN2->pSuiv;
		if( pN1->pSuiv != NULL )
		{
			pN1->pSuiv->pPrec = pN1;
		}
		pN2->pSuiv = pTemp;
		pN2->pSuiv->pPrec = pN2;
	}
	else
	{
		pN1->pSuiv = pN2->pSuiv;
		if( pN1->pSuiv != NULL )
		{
			pN1->pSuiv->pPrec = pN1;
		}
		pN2->pSuiv = NULL;
	}
	if( pN1->pPrec != NULL )
	{
		pTemp = pN1->pPrec;
		pN1->pPrec = pN2->pPrec;
		if( pN1->pPrec != NULL )
		{
			pN1->pPrec->pSuiv = pN1;
		}
		pN2->pPrec = pTemp;
		pN2->pPrec->pSuiv = pN2;
	}
	else
	{
		pN1->pPrec = pN2->pPrec;
		if( pN1->pPrec != NULL )
		{
			pN1->pPrec->pSuiv = pN1;
		}
		pN2->pPrec = NULL;
	}
	return pN2;
}

Nombre * TriBulle( Nombre * pListe )
{
	Nombre * pTemp = pListe;
	unsigned int Tri = 0;
	while( Tri != 1 )
	{
		Tri = 1;
		pTemp = pListe;
		while( pTemp->pSuiv != NULL )
		{
			if( pTemp->uiNombre > pTemp->pSuiv->uiNombre )
			{
				pTemp = InverserElement( pTemp, pTemp->pSuiv );
				if( pTemp->pPrec == NULL )
				{
					pListe = pTemp;
				}
				Tri = 0;
			}
			pTemp = pTemp->pSuiv;
		}
	}
	return pListe;
}

Nombre * TriSelection( Nombre * pListe )
{
	Nombre * pMobile = pListe;
	Nombre * pMin = NULL;
	Nombre * pTemp = pMobile;
	while( pMobile != NULL )
	{
		pTemp = pMobile;
		pMin = pTemp;
		while( pTemp != NULL )
		{
			if( pTemp->uiNombre < pMin->uiNombre )
			{
				pMin = pTemp;
			}
			pTemp = pTemp->pSuiv;
		}
		pMobile = InverserElement( pMobile, pMin );
		if( pMobile->pPrec == NULL )
		{
			pListe = pMobile;
		}
		pMobile = pMobile->pSuiv;
	}
	return pListe;
}

Nombre * Insertion( Nombre * pLieu, Nombre * pInsertion )
{
	if( pInsertion->pPrec != NULL )
	{
		pInsertion->pPrec->pSuiv = pInsertion->pSuiv;
	}
	if( pInsertion->pSuiv != NULL )
	{
		pInsertion->pSuiv->pPrec = pInsertion->pPrec;
	}
	pInsertion->pSuiv = pLieu;
	pInsertion->pPrec = pLieu->pPrec;
	pLieu->pPrec = pInsertion;
	if( pInsertion->pPrec != NULL )
	{
		pInsertion->pPrec->pSuiv = pInsertion;
	}
	return pInsertion;
}

Nombre * TriInsertion( Nombre * pListe )
{
	Nombre * pMobile = pListe;
	Nombre * pInsertion = NULL;
	while( ( pMobile != NULL ) && ( pMobile->pSuiv != NULL ) )
	{
		if( pMobile->uiNombre > pMobile->pSuiv->uiNombre )
		{
			pInsertion = pMobile->pSuiv;
			while( pInsertion->pPrec != NULL )
			{
				if( pInsertion->pPrec->uiNombre < pMobile->pSuiv->uiNombre )
				{
					break;
				}
				pInsertion = pInsertion->pPrec;
			}
			pInsertion = Insertion( pInsertion, pMobile->pSuiv );
			if( pInsertion->pPrec == NULL )
			{
				pListe = pInsertion;
			}
		}
		else
		{
			pMobile = pMobile->pSuiv;
		}
	}
	return pListe;
}

int main( int argc, char ** argv )
{
	Nombre * pListe = NULL;
	unsigned int uiNbElements = 0;
	printf( "Entrer le nombre d'elements : " );
	scanf( "%u", &uiNbElements );
	printf( "Avec le tri a bulle\n" );
	pListe = InitialiserListe( uiNbElements );
	AfficherListe( pListe );
	AfficherListe( TriBulle( pListe ) );
	printf( "Avec le tri par selection\n" );
	pListe = InitialiserListe( uiNbElements );
	AfficherListe( pListe );
	AfficherListe( TriSelection( pListe ) );
	printf( "Avec le tri par insertion\n" );
	pListe = InitialiserListe( uiNbElements );
	AfficherListe( pListe );
	AfficherListe( TriInsertion( pListe ) );
	

	return 0;
}
