# include <stdio.h>
# include <stdio.h>

int main( int argc, char ** argv )
{
	printf( "int = %ld octets\n", sizeof( int ) );
	printf( "short int = %ld octets\n", sizeof( short int ) );
	printf( "long int = %ld octets\n", sizeof( long int ) );
	printf( "unsigned int = %ld octets\n", sizeof( unsigned int ) );
	printf( "char = %ld octets\n", sizeof( char ) );
	printf( "unsigned char = %ld octets\n", sizeof( unsigned char ) );

	return EXIT_SUCCESS;
}
