#include <stdio.h>

int main ()
{
	int prix, somme, arendre;

	printf("\n*** Le monnayeur ***\n\n");	

	printf("Entrez le prix a payer : ");
	scanf("%d",&prix);
	printf("Entrez la somme donnee par le client : ");
	scanf("%d",&somme);
	printf("\n\n");

	arendre = somme - prix;

	if ( arendre < 0 )
	{
		printf("Vous n'essayeriez pas de m'arnaquer?");
		return;
	}

	printf("Il faut rendre :\n");
	
	/* Combien de billets de 5 euros? */
	int nb = arendre / 500;
	if ( nb > 0 )
	{
		printf(" - %d billet(s) de 5 euros ", nb);
		/* met a jour ce qui reste a rendre */	
		arendre = arendre - nb*500;
		// *OU* arendre = ((int)(arendre*100)) % 500 ; /* On recupere le reste de la division precedente (i.e. ce qui reste a rendre) */
		printf("(reste a rendre %d euros)\n",arendre);
	}

	/* Combien de piece de 2 euros */
    nb = arendre / 200;
	if ( nb > 0 )
	{
	        printf(" - %d piece(s) de 2 euros ", nb);
        	arendre = arendre - nb*200;
	        printf("(reste a rendre %d cents)\n",arendre);
	}

    /* Combien de piece de 1 euros */
	nb = arendre / 100;
    if ( nb > 0 )
    {
	       	printf(" - %d piece(s) de 1 euro ", nb);
        	arendre = arendre - nb*100;
	        printf("(reste a rendre %d cents)\n",arendre);
	}

    /* Combien de piece de 0.5  euros */
	nb = arendre / 50;
    if ( nb > 0 )
    {
        	printf(" - %d piece(s) de 50 cts d'euros ", nb);
	        arendre = arendre - nb*50;
        	printf("(reste a rendre %d cents)\n",arendre);
	}

	/* Combien de piece de 0.2  euros */
    nb = arendre / 20;
    if ( nb > 0 )
    {
            printf(" - %d piece(s) de 20 cts d'euros ", nb);
            arendre = arendre - nb*20;
            printf("(reste a rendre %d cents)\n",arendre);
    }

    /* Combien de piece de 0.1  euros */
    nb = arendre / 10;
    if ( nb > 0 )
    {
            printf(" - %d piece(s) de 10 cts d'euros ", nb);
            arendre = arendre - nb*10;
            printf("(reste a rendre %d cents)\n",arendre);
    }

    /* Combien de piece de 0.01  euros */
    nb = arendre;
    if ( nb > 0 )
    {
            printf(" - %d piece(s) de 1 cts d'euros ", nb);
    }
    
	printf("\n\n");
}
