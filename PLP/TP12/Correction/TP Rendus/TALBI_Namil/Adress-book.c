
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

/*******Creation et ajout d'un nouveau contact****************/
Contact* CreerContact(Contact *pTete )

{
	Contact *UnContact = NULL;
	char cTemp[256];


	UnContact = (Contact *) malloc( sizeof(Contact) );
	printf( "\nEntrer le nom : " );
	scanf( "%s", cTemp );
	UnContact->pNom = (char *) malloc(( strlen( cTemp ) + 1 ) * sizeof( char ) );
	strcpy( UnContact->pNom, cTemp );
	printf( "Entrer le prenom : " );
	scanf( "%s", cTemp );
	getchar();
	UnContact->pPrenom = (char *) malloc(( strlen( cTemp ) + 1 ) * sizeof( char ) );
	strcpy( UnContact->pPrenom, cTemp );
	printf( "Entrer le courriel : " );
	scanf( "%s", cTemp );
	getchar();
	UnContact->pCourriel = (char *) malloc(( strlen( cTemp ) + 1 ) * sizeof( char ) );
	strcpy( UnContact->pCourriel, cTemp );
	UnContact->pSuivant = NULL;
	
	pTete = AjoutContact (UnContact , pTete );

	return pTete;
}

/*************afichage de la liste des contact******************/

void AfficherContact( Contact *pTete )

{	int iNumero = 1;
	Contact *plist = pTete;
	 
	while( plist != NULL )
        
	{	  
		iNumero = iNumero + 1;
                printf("***************liste des contact****************\n");
                printf("%d- %s  %s  %s\n",iNumero, plist->pNom, plist->pPrenom, plist->pCourriel);

		plist = plist->pSuivant;
	}
	return;
}

/************liberation de l'espace memoire******************/


Contact* Liberer (Contact *pTete)
{
	Contact *pParcour = pTete;
	Contact *pFree = NULL;
	
	
	pFree = pParcour->pSuivant;
	free( pParcour->pNom);
	free( pParcour->pPrenom);	
	free( pParcour->pCourriel);
	free( pParcour);	
	pTete = pFree;

	return pTete;
}

/*********** Enregistrement des contact**********************************/


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

/*********** ChargerCarnet **********************/


Contact * ChargerCarnet ()
{
	FILE* pFichier = NULL;
	char Temp[1000],Temp1[256];
	Contact *pDebut;
	Contact *pNouveau;	
	
	printf( "\n entrez le nom du fichier \n");
	scanf( "%s", Temp );
	pFichier = fopen (Temp , "r");

	while (!feof(pFichier)) 
	 
	{ 
		pNouveau = (Contact *) malloc( sizeof(Contact) );
		fscanf(pFichier,"%s %s", Temp, Temp1 );
		pNouveau->pNom = (char *) malloc(( strlen( Temp1 ) + 1 ) * sizeof( char ) );
		strcpy(pNouveau->pNom, Temp1);
		
		fscanf(pFichier,"%s %s", Temp, Temp1 );
		pNouveau->pPrenom = (char *) malloc(( strlen( Temp1 ) + 1 ) * sizeof( char ) );
		strcpy(pNouveau->pPrenom, Temp1);

		
		fscanf(pFichier,"%s %s", Temp, Temp1 );
		pNouveau->pCourriel = (char *) malloc(( strlen( Temp1 ) + 1 ) * sizeof( char ) );
		strcpy(pNouveau->pCourriel, Temp1);
		
		pDebut = AjoutContact (pNouveau ,  pDebut);
	}

fclose (pFichier);

	return pDebut;
}
/*######################################################### fonction suprimer*/
Contact * suprimer( Contact *pTete )

{	Contact *pParcour= pTete ;
	Contact	*pDeriere = pTete;
	char choix,Nom[200];


	printf( "\nEntrer le Nom à suprimer : " );
	scanf( "%s", Nom );

	while (pParcour != NULL )
	{
		if (strcmp(pParcour->pNom, Nom) == 0)
		{		
			
			printf ("nom : %s \n",pParcour->pNom); 
			printf ("prenom : %s \n",pParcour->pPrenom);
			printf ("courriel : %s \n",pParcour->pCourriel);
	
			printf ("\ntapez : N pour NON , Y pour Yes : \n");
			getchar ();
			scanf ("%c",&choix);	
			
			switch (choix)	
			{
						
				case 'N' :
									
					pDeriere = pParcour;
					pParcour = pParcour->pSuivant;
					break;
		
				case 'Y' :	

					if (pParcour == pTete)
					{
						if (pParcour->pSuivant == NULL)
						{
							pTete = Liberer (pParcour);
							return NULL;
						}
						else 
						{
							pTete = Liberer (pParcour);
							return pTete;
						}
					}
					
					else 
					{
						pDeriere->pSuivant = pParcour->pSuivant;
						free( pParcour->pNom);
						free( pParcour->pPrenom);	
						free( pParcour->pCourriel);
						free( pParcour);
						return pTete;
					}
					break;
					
				default :
					printf ("Erreur !? choix non valide !\n");
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
	return pTete;
}
/******Modification d'un contact existe deja dans la liste des contact********/

Contact * modifier( Contact *pTete )

{
	Contact *pParcour= pTete ;
	Contact	*pDeriere = pTete;
	char choix,choice,Nom[100],cNom[100];


	printf( "\nEntrer le Nom à Modifier : " );
	scanf( "%s", Nom );

	while (pParcour != NULL )
	{
		if (strcmp(pParcour->pNom, Nom) == 0)
		{
			printf ("\n Veullez vous modifier le contact \n");
			printf ("\nnom : %s \n",pParcour->pNom); 
			printf ("prenom : %s \n",pParcour->pPrenom);
			printf ("courriel : %s \n",pParcour->pCourriel);
	
			printf ("\ntapez : N pour NON , Y pour Yes : \n");
			getchar ();
			scanf ("%c",&choix);	
			getchar ();
			switch (choix)	
			{
						
				case 'N' :					
					pDeriere = pParcour;
					pParcour = pParcour->pSuivant;
					break;
		
				case 'Y':
					printf ("\nVoulez vous modifier : \n");	
					printf ("A-Nom.\nB-Prenom.\nC-Couriel.\n");
					/*getchar ();*/
					scanf ("%c",&choice);
					getchar ();
					switch (choice)	
					{		
						case 'A' :
						printf( "\nEntrer le Nom à Modifier : " );
						scanf( "%s", cNom );
						/*getchar ();*/	
						strcpy(pParcour->pNom, cNom);
						pDeriere = pParcour;
						pParcour = pParcour->pSuivant;
						break;

						case 'B' :
						
						printf( "\nEntrer le prenom à Modifier : " );
						scanf( "%s", cNom );	
						strcpy(pParcour->pPrenom, cNom);
						pDeriere = pParcour;
						pParcour = pParcour->pSuivant;
						break;
	
						case 'C' :
						
						printf( "\nEntrer le Courriel à Modifier:" );
						scanf( "%s", cNom );
						strcpy(pParcour->pCourriel, cNom);
						pDeriere = pParcour;
						pParcour = pParcour->pSuivant;
						break;

						default :
						printf ("Erreur !? choix non valide ! \n");
						pDeriere = pParcour;
						pParcour = pParcour->pSuivant;
						break;	
						
					}
					break;
					
				default :
					printf (" choix non valide ! \n");
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
	return pTete;
}


int main( int argc, char ** argv )
	
{	char cChoix,function;
	Contact *pTete = NULL;
        
	

	while ( function != 'Q' )
	{
                printf("**********************Adress book**********************************\n");
                printf("*                                                                 *\n");
		printf("*   que voullez vous faire Taper votre choix  :                   *\n");
                printf("*                                                                 *\n");
		printf("*\n     1.  Creer un contact.                                        *\n"); 
		printf("*\n     2.  Suprimer un contact.                                     *\n");
		printf("*\n     3.  Modifier un contact.                                     *\n");
		printf("*\n     4.  Affichage de la liste des contacts.                      *\n");
		printf("*\n     5.  Enregistrer un contact dans le fichier.                  *\n");
		printf("*\n     6.  Chargement de la liste d'adresse .                       *\n");
		printf("*\n     Q.  Quitter l'application.                                   *\n");  
                printf("*                                                                    *\n");
		printf("*******************************************************************\n");
		scanf( "%c", &cChoix );
			
		   
		switch (cChoix)
	
		{
			case '1' :
		
				pTete = CreerContact( pTete );
					
				break;
	
			case '4' :
				

				if (pTete != NULL)
				{
					AfficherContact( pTete );
				}
				else 
				{
					printf("Liste Vide\n");
				}
				break;

			case '5' :
			
				Enregistrer(pTete);
				break;

			case '6' :

				pTete = ChargerCarnet ();
				break;

			case '2' :
			    	
				pTete = suprimer(pTete);
				break;

			case '3':

				pTete = modifier(pTete);
				break;

			case 'Q' :
		
				function = 'Q';
	
				break;
			
			default :
				printf ("\n\nchoix non valide !! \n\n");
				break;
		
		}
	}
	
	return 0;
	

}
