# include <stdlib.h>
# include <stdio.h>

int main( int argc, char ** argv )
{
	unsigned int iMatrice[5][5];
	unsigned int i = 0, j = 0;
	for( i = 1; i <= 5; i++ )
	{
		for( j = 1; j <= 5; j++ )
		{
			iMatrice[i][j] = 5 * i + j;
		}
	}

	return EXIT_SUCCESS;
}
