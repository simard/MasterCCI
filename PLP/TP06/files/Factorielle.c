unsigned long int Factorielle( unsigned long int iN )
{
	unsigned long int iResultat = 1;
	for( ; iN > 0; iN-- )
	{
		iResultat *= iN;
	}
	return iResultat;
}
