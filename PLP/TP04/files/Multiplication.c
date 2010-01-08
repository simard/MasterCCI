# include <stdlib.h>
# include <stdio.h>

int main( int argc, char ** argv )
{
	double dMatrice1[5][5], dMatrice2[5][5], dMatriceRes[5][5];
	unsigned int i = 0, j = 0, k = 0;
	for( i = 0; i < 5; i++ )
	{
		for( j = 0; j < 5; j++ )
		{
			dMatrice1[i][j] = 5.0 * (double)i + (double)j + 1.0;
			dMatrice2[i][j] = 5.0 * (double)i + (double)j + 1.0;
			dMatriceRes[i][j] = 0.0;
		}
	}
	for( i = 0; i < 5; i++ )
	{
		for( j = 0; j < 5; j++ )
		{
			for( k = 0; k < 5; k++ )
			{
				dMatriceRes[i][j] += dMatrice1[i][k] * dMatrice2[k][j];
			}
		}
	}

	return EXIT_SUCCESS;
}
