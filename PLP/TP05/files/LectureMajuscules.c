# include <stdlib.h>
# include <stdio.h>

int main( int argc, char ** argv )
{
	char cChaine[64] = "Vive les RERs";
	unsigned int i = 0;

	for( i = 0; cChaine[i] != '\0'; i++ )
	{
		if( cChaine[i] <= 90 )
		{
			printf( "%c", cChaine[i] );
		}
	}

	return EXIT_SUCCESS;
}
