/* 	Abdelmoundher GHECHAMI
	M2 CCI
	TP4 - Principe des Langages de Programation
	Mini-projet 3.
	Programme : Carnet d adresses de courriel.
*/

# include<stdio.h>
# include<stdlib.h>
# include<string.h>

typedef struct sContact
{
	char * cNom;
	char * cPrenom;
	char * cCourriel;
	struct sContact * pSuivant;
} Contact;

int NbContacts = 0;
Contact *pDebut = NULL;
Contact *pTemp = NULL;
FILE * pCarnet =NULL;

/*FONCTION
 *CreerContact
 */
int CreerContact ()
{
	
	char cTemp [256];
	Contact *pNew =NULL;
	
	pNew = (Contact *) malloc( sizeof( Contact ));
	
	printf("Entrer le nom : ");
	scanf("%s", cTemp);
	pNew->cNom = (char *) malloc ((strlen(cTemp)+1) * sizeof(char));
	strcpy(pNew->cNom , cTemp);
	
	printf("Entrer le prenom : ");
	scanf("%s", cTemp);
	pNew->cPrenom = (char *) malloc ((strlen(cTemp)+1) * sizeof(char));
	strcpy(pNew->cPrenom , cTemp);
	
	printf("Entrer le courriel : ");
	scanf("%s", cTemp);
	pNew->cCourriel = (char *) malloc ((strlen(cTemp)+1) * sizeof(char));
	strcpy(pNew->cCourriel , cTemp);
	
	if(NbContacts==0)
	{
		pDebut = pNew;
	}
	else
	{
		pTemp->pSuivant = pNew;
	}
	
	pNew->pSuivant =NULL;
	pTemp = pNew;
	NbContacts ++;
	
	return 0;
}

/* FONCTION
 * SupprimerContact
 */
int SupprimerContact()
{
	char cTemp [256];
	Contact *pPrecedent = NULL;
	Contact *pEC = NULL;
	
	printf("Ecrire le nom du contact a supprimer : ");
	scanf("%s", cTemp);
	
	pEC=pDebut;
	while ( pEC != NULL )
	{
		if ( strcmp(pEC->cNom, cTemp ) ==0)
			break;
		pPrecedent = pEC;
		pEC=pEC->pSuivant;
	}
	
	if (pEC == NULL)
	{
		printf("ce nom ne figure pas dans la liste des contacts\n");
	}
	else if(strcmp(pEC->cNom,cTemp)==0)
	{
		if (pEC == pDebut)
		{
			pDebut = pEC->pSuivant;
		}
		else
		{
			pPrecedent->pSuivant = pEC->pSuivant;
			free (pEC->cNom);
			free (pEC->cPrenom);
			free (pEC->cCourriel);
			free (pEC);
		}
		NbContacts--;
	}
	return 0;
}

/* FONCTION
 * LibererMemoire
 */
int LibererMemoire ()
{
	Contact * pMaillonALiberer;
	pMaillonALiberer = pDebut;
	
	while (pMaillonALiberer != NULL)
	{
		pDebut=pMaillonALiberer->pSuivant;
		free (pMaillonALiberer->cNom);
		free (pMaillonALiberer->cPrenom);
		free (pMaillonALiberer->cCourriel);
		free (pMaillonALiberer);
		pMaillonALiberer = pDebut;
	}
	return 0;
}

/* FONCTION
 * ModifierContact
 */
int ModifierContact()
{
	char cTemp [256];
	Contact *pEC = NULL;
	
	printf("Ecrire le nom du contact a modifier : ");
	scanf("%s", cTemp);
	
	pEC=pDebut;
	while ( pEC != NULL )
	{
		if ( strcmp(pEC->cNom, cTemp ) ==0)
			break;
		pEC=pEC->pSuivant;
	}
	
	if (pEC == NULL)
	{
		printf("ce nom ne figure pas dans la liste des contacts\n");
	}
	else if( strcmp(pEC->cNom, cTemp) ==0 )
	{
		printf("Entrer le nouveau nom : ");
		scanf("%s", cTemp);
		pEC->cNom = (char *) realloc (pEC->cNom, (strlen(cTemp)+1) * sizeof(char));
		strcpy(pEC->cNom , cTemp);
		
		printf("Entrer le nouveau prenom : ");
		scanf("%s", cTemp);
		pEC->cPrenom = (char *) realloc (pEC->cPrenom, (strlen(cTemp)+1) * sizeof(char));
		strcpy(pEC->cPrenom , cTemp);
		
		printf("Entrer le nouveau courriel : ");
		scanf("%s", cTemp);
		pEC->cCourriel = (char *) realloc (pEC->cCourriel, (strlen(cTemp)+1) * sizeof(char));
		strcpy(pEC->cCourriel , cTemp);
	}
	return 0;
}

/* FONCTION
 * AfficherCarnet
 */
int AfficherContacts ()
{
	Contact * pEC;
	if (pDebut ==NULL)
	{
		printf("Carnet d adresses vide ou pas encore charge\n");
	}
	else
	{
		printf("Nom :   Prenom :   Courriel :\n");
		
		pEC = pDebut;
		while(pEC!=NULL)
		{
			printf("%s   %s   %s\n", pEC->cNom, pEC->cPrenom, pEC->cCourriel);
			pEC=pEC->pSuivant;
		}
	}
	return 0;
}

/* FONCTION
 * EnregistrerCarnet
 */
int EnregistrerCarnet ()
{
	Contact * pEC;
	
	pCarnet = fopen ( "Carnet d adresses.txt", "w" );
	if (pDebut ==NULL)
	{
		printf("Carnet d adresses vide! il y a aucun contact\n");
	}
	else
	{
		pEC = pDebut;
		while(pEC!=NULL)
		{
			fprintf(pCarnet, "%s\n%s\n%s\n\n", pEC->cNom, pEC->cPrenom, pEC->cCourriel);
			pEC=pEC->pSuivant;
		}
	}
	fclose(pCarnet);
	return 0;
}

/* FONCTION
 * ChargerCarnet
 */
int ChargerCarnet ()
{
	int a;
	char cTemp [256];
	Contact *pNew =NULL;
	
	pTemp = NULL;
	NbContacts = 0;
	
	pCarnet = fopen ( "Carnet d adresses.txt", "a+" );
	a = fscanf(pCarnet, "%s\n", cTemp);
	
	while (a != EOF)
	{
		pNew = (Contact *) malloc( sizeof( Contact ));
		
		pNew->cNom = (char *) malloc ((strlen(cTemp)+1) * sizeof(char));
		strcpy(pNew->cNom , cTemp);
		
		fscanf(pCarnet, "%s\n", cTemp);
		pNew->cPrenom = (char *) malloc ((strlen(cTemp)+1) * sizeof(char));
		strcpy(pNew->cPrenom , cTemp);
		
		fscanf(pCarnet, "%s\n", cTemp);
		pNew->cCourriel = (char *) malloc ((strlen(cTemp)+1) * sizeof(char));
		strcpy(pNew->cCourriel , cTemp);
		
		if(NbContacts==0)
		{
			pDebut = pNew;
		}
		else
		{
			pTemp->pSuivant = pNew;
		}
		
		pNew->pSuivant =NULL;
		pTemp = pNew;
		NbContacts ++;
		
		a = fscanf(pCarnet, "\n%s\n", cTemp);
	}
	fclose(pCarnet);
	return 0;
}

int main ( int argc, char ** argv )
{
	char choix = '\0';
	char sChoix [10];
	int length = 0;
	
	/* nettoyer l'ecran du terminal*/
	system("clear");
	
	while ( choix != '7' )
	{	
		do
		{
			/*Afficher un menu pour l utilisateur qui affichera les differentes 
			operations proposees par le programme*/
			printf("\n### Carnet d adresses de courriel ###\n1- Afficher la liste des contacts\n2- Creer un nouveau contact\n3- Modifier un contact\n4- Supprimer un contact\n5- Charger un carnet d adresses\n6- Enregistrer le carnet d adresses\n7- Quitter le programme\n\n");
			
			/* proposition de choisir le numero correspondant */
			printf( "Entrer votre choix : ");
			
			/* controler si le choix est correct et que l utilisateur a bien tappe un seul caractere */
			scanf( "%s", sChoix );
			choix = (char) sChoix[0];
			length = strlen (sChoix );
			
			if (length > 1)
			{
				printf( "%s\n","choix incorrect" );
				
				/* vider le tampon stdin due au scan de plusieurs caracteres */
				fflush(stdin);
			}
		}
		while (length !=1);
		
		switch (choix)
		{
			/*Afficher la liste des contacts*/
			case '1' :
				AfficherContacts();
				break;
			/*Creer un nouveau contact*/
			case '2' :
				CreerContact();
				break;
			/*Modifier un contact*/
			case '3' :
				ModifierContact();
				break;
			/*Supprimer un contact*/
			case '4' :
				SupprimerContact();
				break;
			/*Charger un carnet d adresses*/
			case '5' :
				ChargerCarnet();
				break;
			/*Enregistrer le carnet d adresses*/
			case '6' :
				EnregistrerCarnet ();
				break;
			/*Quitter le programme*/
			case '7' :
				LibererMemoire ();
				break;
			default :
				printf( "Choix incorrect \n" );
				break;
		}
	}	
	return 0;
}
