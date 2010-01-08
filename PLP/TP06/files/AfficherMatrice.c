void AfficherMatrice()
{
	unsigned int i = 0;
	unsigned int j = 0;
	for( i = 0; i < 3; i++ )
	{
		for( j = 0; j < 3; j++ )
		{
			printf( "%lf\t", dMatrice[i][j] );
		}
		printf( "\n" );
	}
	return;
}
