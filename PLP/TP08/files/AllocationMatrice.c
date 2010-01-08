# include <stdlib.h>
# include <stdio.h>

typedef struct sMatrice
{
	double ** dMat;
	unsigned int uiNbLignes;
	unsigned int uiNbColonnes;
} Matrice;

int main( int argc, char ** argv )
{
	Matrice UneMat;
	unsigned int uiLignes = 0, uiColonnes = 0;
	unsigned int i = 0;
	printf( "Entrer le nombre de lignes de la Matrice : " );
	scanf( "%u", &uiLignes );
	printf( "Entrer le nombre de colonnes de la Matrice : " );
	scanf( "%u", &uiColonnes );
	UneMat.uiNbLignes = uiLignes;
	UneMat.uiNbColonnes = uiColonnes;
	UneMat.dMat = (double **) malloc( UneMat.uiNbLignes * sizeof( double * ) );
	for( i = 0; i < UneMat.uiNbLignes; i++ )
	{
		UneMat.dMat[i] = (double *) malloc( UneMat.uiNbColonnes * sizeof( double ) );
	}
	return EXIT_SUCCESS;
}
