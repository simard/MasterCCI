# include <stdlib.h>
# include <stdio.h>

int iVarGlobale = 0;

int main( int argc, char ** argv )
{
	int iVarLocale = 1;
	int iAutreVarLocale = 2;
	printf( "iVarGlobale = %d\n", iVarGlobale );
	printf( "iVarLocale = %d\n", iVarLocale );
	printf( "iAutreVarLocale = %d\n", iAutreVarLocale );

	return EXIT_SUCCESS;
}
