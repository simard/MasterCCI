# include <stdlib.h>
# include <stdio.h>

int main( int argc, char ** argv )
{
	char cEchTemp = '\0';
	double dTemperature = 0.0;
	char cEchConv = '\0';
	printf( "### Programme de conversion ###\n" );
	printf( "1 - Kelvin\n" );
	printf( "2 - Celsius\n" );
	printf( "3 - Fahrenheit\n" );
	printf( "Choisissez l'echelle de la temperature a convertir : " );
	cEchTemp = getchar();
	getchar(); /* Pour lire le caractere <Entree> */
	printf( "Entrez la temperature a convertir : " );
	scanf( "%lf", &dTemperature );
	getchar(); /* Pour lire le caractere <Entree> */
	switch( cEchTemp )
	{
		case '1' :
		{
			printf( "1 - Celsius\n" );
			printf( "2 - Fahrenheit\n" );
			printf( "Choisissez la temperature de conversion : " );
			cEchConv = getchar();
			if( cEchConv == '1' )
			{
				printf( "Une temperature de %.3lf K",\
					dTemperature );
				printf( " correspond a %.3lf C.\n",\
					dTemperature - 273.15 );
			} else {
				printf( "Une temperature de %.3lf K",\
					dTemperature );
				printf( " correspond a %.3lf F.\n",\
					( dTemperature - 273.15 ) * 1.8 + 32.0 );
			}
			break;
		}
		case '2' :
		{
			printf( "1 - Kelvin\n" );
			printf( "2 - Fahrenheit\n" );
			printf( "Choisissez la temperature de conversion : " );
			cEchConv = getchar();
			if( cEchConv == '1' )
			{
				printf( "Une temperature de %.3lf C",\
					dTemperature );
				printf( " correspond a %.3lf K.\n",\
					dTemperature + 273.15 );
			} else {
				printf( "Une temperature de %.3lf C",\
					dTemperature );
				printf( " correspond a %.3lf F.\n",\
					dTemperature * 1.8 + 32.0 );
			}
			break;
		}
		case '3' :
		{
			printf( "1 - Celsius\n" );
			printf( "2 - Kelvin\n" );
			printf( "Choisissez la temperature de conversion : " );
			cEchConv = getchar();
			if( cEchConv == '1' )
			{
				printf( "Une temperature de %.3lf F",\
					dTemperature );
				printf( " correspond a %.3lf C.\n",\
					( dTemperature - 32.0 ) / 1.8 );
			} else {
				printf( "Une temperature de %.3lf F",\
					dTemperature );
				printf( " correspond a %.3lf K.\n",\
					( dTemperature - 32.0 ) / 1.8 + 273.15 );
			}
			break;
		}
		default :
		{
			printf( "Choix incorrect\n" );
			return EXIT_FAILURE;
		}
	}
	printf( "### Fin du programme ###\n" );
	return EXIT_SUCCESS;
}
