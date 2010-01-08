/*Hanane BOUAZAZE*/
/*le crible d Eratosthene*/
# include <stdio.h>

int main(int argc, char ** argv)
{
	/* Declaration et Initialisation de l'entier N */
	unsigned int N = 0;
	/* Etape 1 : demandez � l'utilisateur un entier positif N >= 2 */
	printf( " Entrez un entier postif : " );
	scanf( "%d", &N);
	
	/* declaration de la table et 2 entier i et j */
	unsigned int iEratosthene [N], i, j;
	
	/* Etape 2 : Verification de la condition sur N (N >= 2) */
	if( N < 2 )
	{
		printf( " Il faut choisir un nombre entier superieur a 2 \n" );
		
		return 0;
	}
	else
	{
		/* Etape 3 : remplir le tableau par des nombres de 1 a N*/
		for (i = 0; i <= (N-1); i++)
		{
			iEratosthene [ i ] = i+1;
		}
		
		/* recherche des valeurs premiers :  pour chaque nombre iEratosthene [ i ], on fait 
		   une boucle � la recherche de ces multiples et on les remplace par 0 
		   et donc les nombres premiers sont ceux da la table iEratosthene qui restent different de 0 */
		   
		for (i = 1; i <= N-1; i++) 
		{
			if ( iEratosthene [ i ] != 0 )
			{
				for ( j=( i+ 1 ) ;j <= (N-1) ;j++ ) 
				{
					/* On verifie si sa valeur est differente de 0 */
					if ( iEratosthene [ j ] != 0 ) 
					{
						/* On verifie si les deux element iEratosthene[j] est un multiple de iEratosthene [i] */
						if ( ( iEratosthene [ j ] % iEratosthene [ i ] ) == 0 ) 
						{
							iEratosthene [ j ] = 0;
						}
					}
				}
			}
		}
	}
	
	/* Affichage des nombres premiers */
	printf(" Voici le crible d' Eratosthene jusqu �a l� entier %d " , N );
	 for (i = 1; i <= N-1 ; i++) 
	 {
		 if ( iEratosthene [ i ] != 0 )
		 {
			 /* Imprimer tous les elements de la table iEratosthene different de 0 */
			 printf ( " \n %d" , iEratosthene [ i ]);
			 printf("\n");
		 }
	 }
	 
	 return 0;
}

