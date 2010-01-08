
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct sContact
{
	char * pNom;
	char * pPrenom;
	char * pCourriel;
	struct sContact *pSuivant;
} Contact;

/*######################################################### fonction AjoutContact*/

Contact* AjoutContact (Contact *pNew ,Contact *pHead )

{
	

	if (pHead  == NULL)
	{
		pHead  = pNew;
	}
	else
	{	
		pNew->pSuivant = pHead;
		pHead = pNew ;
	}
	
	return pHead;
}

/*######################################################### fonction Carnet*/
Contact* Carnet(Contact *ptete )

{
	Contact *UnContact = NULL;
	char cTemp[256];


	UnContact = (Contact *) malloc( sizeof(Contact) );
	/* le nom */
	printf( "\nEntrer le nom : " );
	scanf( "%s", cTemp );
	UnContact->pNom = (char *) malloc(( strlen( cTemp ) + 1 ) * sizeof( char ) );
	strcpy( UnContact->pNom, cTemp );

	/* le prenom*/
	printf( "Entrer le prenom : " );
	scanf( "%s", cTemp );
	UnContact->pPrenom = (char *) malloc(( strlen( cTemp ) + 1 ) * sizeof( char ) );
	strcpy( UnContact->pPrenom, cTemp );

	/* le mail */
	printf( "Entrer le courriel : " );
	scanf( "%s", cTemp );
	UnContact->pCourriel = (char *) malloc(( strlen( cTemp ) + 1 ) * sizeof( char ) );
	strcpy( UnContact->pCourriel, cTemp );
	UnContact->pSuivant = NULL;

	/* Ajout du maillon creeé a la liste */
	
	ptete = AjoutContact (UnContact , ptete );

	return ptete;
}

/*######################################################### fonction AfficherContact*/

void AfficherContact( Contact *ptete )

{	int i = 0;
	Contact *pParcour = ptete;
	 
	while( pParcour != NULL )
	{	
		i = i + 1;
		printf( "\n ### Contact numéro %d ### \n",i );
		printf( " Nom : %s\n", pParcour->pNom);
		printf( " Prenom : %s\n", pParcour->pPrenom);
		printf( " Courriel : %s\n", pParcour->pCourriel);
		printf( " \n########\n\n");


		pParcour = pParcour->pSuivant;
	}
	return;
}

/*######################################################### fonction  Liberer*/


Contact* Liberer (Contact *ptete)
{
	Contact *pParcour = ptete;
	Contact *h = NULL;
	
	
	h = pParcour->pSuivant;
	free( pParcour->pNom);
	free( pParcour->pPrenom);	
	free( pParcour->pCourriel);
	free( pParcour);	
	ptete = h;

	return ptete;
}

/*######################################################### fonction Enregistrer*/


void Enregistrer (Contact *pParcour)
{

	FILE* pFichier = NULL;
	char Temp[256];
		
	printf( "\n entrez le nom du fichier \n");
	scanf( "%s", Temp );
	pFichier = fopen (Temp , "w"); /*ouvrir le fichier en mode ecriture*/
	
	while (pParcour != NULL)
	{

	fprintf (pFichier,"Nom: %s\n", pParcour->pNom );
	fprintf (pFichier,"Prenom: %s\n", pParcour->pPrenom );
	fprintf (pFichier,"Courriel: %s\n\n", pParcour->pCourriel );
	pParcour = pParcour->pSuivant;	
	
	}

	fclose (pFichier);
	return ;

}

/*######################################################### fonction ChargerCarnet */


Contact * ChargerCarnet ()
{
	int i ;
	FILE* pFichier = NULL;
	char Temp[1000],Temp1[256];
	Contact * pDebut;
	Contact * pNouveau;	
	
	
	
	
	printf( "\n entrez le nom du fichier \n");
	scanf( "%s", Temp );
	pFichier = fopen (Temp , "r");

	while (!feof(pFichier) ) /*( fgetc(pFichier) != EOF )*/
	 
	{ 
		pNouveau = (Contact *) malloc( sizeof(Contact) );
		fscanf(pFichier,"%s %s", Temp, Temp1 );/*temp contient les cartères "Nom"*/
		pNouveau->pNom = (char *) malloc(( strlen( Temp1 ) + 1 ) * sizeof( char ) );
		strcpy(pNouveau->pNom, Temp1);
		/*printf(" nom : %s ",pNouveau->pNom);*/
		
		fscanf(pFichier,"%s %s", Temp, Temp1 );/*temp contient les cartères "Prenom"*/
		pNouveau->pPrenom = (char *) malloc(( strlen( Temp1 ) + 1 ) * sizeof( char ) );
		strcpy(pNouveau->pPrenom, Temp1);
		/*printf(" prenom : %s ",pNouveau->pPrenom);*/
		
		fscanf(pFichier,"%s %s", Temp, Temp1 );
		pNouveau->pCourriel = (char *) malloc(( strlen( Temp1 ) + 1 ) * sizeof( char ) );
		strcpy(pNouveau->pCourriel, Temp1);
		/*printf(" courriel : %s ",pNouveau->pCourriel);*/
		
		pDebut = AjoutContact (pNouveau ,  pDebut);
	}

fclose (pFichier);

	return pDebut;
}
/*######################################################### fonction suprimer*/
Contact * suprimer( Contact *ptete )

{	Contact *pParcour= ptete ;
	Contact	*pDeriere = ptete;
	char choi,Nom[200];


	printf( "\nEntrer le Nom à suprimer : " );
	scanf( "%s", Nom );

	while (pParcour != NULL )
	{
		if (strcmp(pParcour->pNom, Nom) == 0)
		{
		
			printf ("\n /!/ Vous etes sûr de vouloir suprimer le contact \n");		
			
			printf ("\nnom : %s \n",pParcour->pNom); 
			printf ("prenom : %s \n",pParcour->pPrenom);
			printf ("courriel : %s \n",pParcour->pCourriel);
	
			printf ("\ntapez : N pour NON , Y pour Yes : \n");
			getchar ();
			scanf ("%c",&choi);	
			
			switch (choi)	
			{
						
				case 'N' :
				case 'n' :					
					pDeriere = pParcour;
					pParcour = pParcour->pSuivant;
					break;
		
				case 'Y' :	
				case 'y' :

					if (pParcour == ptete)
					{
						printf("\n########>\n");
						if (pParcour->pSuivant == NULL)
						{
							ptete = Liberer (pParcour);
							return NULL;
						}
						else 
						{
							ptete = Liberer (pParcour);
							return ptete;
						}
					}
					
					else 
					{
						pDeriere->pSuivant = pParcour->pSuivant;
						free( pParcour->pNom);
						free( pParcour->pPrenom);	
						free( pParcour->pCourriel);
						free( pParcour);
						return ptete;
					}
					break;
					
				default :
					printf (" \n\nErreur !? choix non valide ! \n\n");
					pDeriere = pParcour;
					pParcour = pParcour->pSuivant;
				break;	
				
			}	
			
		}
		else 
		{	
			pDeriere = pParcour;
			pParcour = pParcour->pSuivant;
		}
					
	
		
	}
	return ptete;
}
/*######################################################### fonction modifier*/

Contact * modifier( Contact *ptete )

{
	Contact *pParcour= ptete ;
	Contact	*pDeriere = ptete;
	char choi,chi,Nom[200],cNom[200];


	printf( "\nEntrer le Nom à Modifier : " );
	scanf( "%s", Nom );

	while (pParcour != NULL )
	{
		if (strcmp(pParcour->pNom, Nom) == 0)
		{
			printf ("\n /!/ Vous etes sûr de vouloir modifier le contact \n");
			printf ("\nnom : %s \n",pParcour->pNom); 
			printf ("prenom : %s \n",pParcour->pPrenom);
			printf ("courriel : %s \n",pParcour->pCourriel);
	
			printf ("\ntapez : N pour NON , Y pour Yes : \n");
			getchar ();
			scanf ("%c",&choi);	
			getchar ();
			switch (choi)	
			{
						
				case 'N' :
				case 'n' :					
					pDeriere = pParcour;
					pParcour = pParcour->pSuivant;
					break;
		
				case 'Y':	
				case 'y':
					printf ("\nVoulez vous modifier : \n");	
					printf ("A-Nom.\nB-Prenom.\nC-Couriel.\n");
					/*getchar ();*/
					scanf ("%c",&chi);
					getchar ();
					switch (chi)	
					{		
						case 'A' :
						case 'a' :
						printf( "\nEntrer le Nom à Modifier : " );
						scanf( "%s", cNom );
						/*getchar ();*/	
						strcpy(pParcour->pNom, cNom);
						pDeriere = pParcour;
						pParcour = pParcour->pSuivant;
						break;

						case 'B' :
						case 'b' :
						
						printf( "\nEntrer le prenom à Modifier : " );
						scanf( "%s", cNom );	
						/*getchar ();*/
						strcpy(pParcour->pPrenom, cNom);
						pDeriere = pParcour;
						pParcour = pParcour->pSuivant;
						break;
	
						case 'C' :
						case 'c' :
						
						printf( "\nEntrer le Courriel à Modifier:" );
						scanf( "%s", cNom );
						/*getchar ();*/	
						strcpy(pParcour->pCourriel, cNom);
						pDeriere = pParcour;
						pParcour = pParcour->pSuivant;
						break;

						default :
						printf (" \n\nErreur !? choix non valide1 ! \n\n");
						pDeriere = pParcour;
						pParcour = pParcour->pSuivant;
						break;	
						
					}
					break;
					
				default :
					printf (" \n\nErreur !? choix non valide2 ! \n\n");
					pDeriere = pParcour;
					pParcour = pParcour->pSuivant;
				break;	
			
			}	
			
		}
		else 
		{	
			pDeriere = pParcour;
			pParcour = pParcour->pSuivant;
		}
					
	/*getchar ();*/
		
	}
	return ptete;
}


/*######################################################### fonction Main */


int main( int argc, char ** argv )
	
{	char choix,toto;
	Contact *ptete = NULL;
	

	while ( toto != 'q' )
	{
		printf("\n########> tapez : \n");
		printf("\n     C -> Creer un contact.\n"); 
		printf("\n     S -> Suprimer un contact.\n ");
		printf("\n     M -> Modifier un contact.\n ");
		printf("\n     A -> Affichage des contacts. \n" );
		printf("\n     E -> Enregistrer sur un fichier.   \n");
		printf("\n     h -> Chargement d'un carnet d'adresse .   \n");
		printf("\n     Q -> Quitter l'application.   \n\n");
		printf("##################################\n\n");
		scanf( "%c", &choix );
			
		   
		switch (choix)
	
		{
			case 'C' :
			case 'c' :
		
				ptete = Carnet( ptete );
					
				break;
	
			case 'A' :
			case 'a' :
				

				if (ptete != NULL)
				{
					AfficherContact( ptete );
				}
				else 
				{
					printf("\n \n Liste vide___il y a rien à afficher \n \n");
				}
				break;

			case 'E' :
			case 'e' :

				Enregistrer(ptete);
				break;

			case 'H' :
			case 'h' :

				ptete = ChargerCarnet ();
				break;

			case 'S' :
			case 's' :
			    	
				ptete = suprimer(ptete);
				break;

			case 'M':
			case 'm':

				ptete = modifier(ptete);
				break;

			case 'Q' :
			case 'q' :
		
				toto = 'q';
	
				break;
			
			default :
				printf (" \n\nErreur !? choix non valide ! \n\n");
				break;
		
		}
		getchar ();
	}
	
	return 0;
	

}
