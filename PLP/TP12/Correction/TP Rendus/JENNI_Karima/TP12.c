#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*-----------------------------------------------------------------------------------------*/
/*################## Structure ##############*/
/*----------------------------------------------------------------------------------------*/

typedef struct contact
{
	char * pNom;
	char * pPrenom;
	char * pMail;
	struct contact * pSuivant;
}contact;

/*-----------------------------------------------------------------------------------------*/
/*################## Ajouter contact ##############*/
/*----------------------------------------------------------------------------------------*/

contact * AjouterContact (contact * pNouveau , contact * pDebut )
{
	contact * pTemp;
	
	if (pDebut == NULL)
	{
		pDebut = pNouveau;
	}
	else
	{	
		pTemp = pDebut;
		while (pTemp->pSuivant != NULL)
		{
			pTemp = pTemp->pSuivant;
		}
		pTemp->pSuivant = pNouveau;
	}

	return pDebut;	
}

/*-----------------------------------------------------------------------------------------*/
/*############### Creer un contact ############*/
/*----------------------------------------------------------------------------------------*/

contact * CreerContact (contact * pDebut)
{		
	contact * pNouveau;
	char pTab[256];

	pNouveau = (contact *) malloc (sizeof (contact));

	printf ("entrer le nom :");
	scanf ("%s", pTab);
	pNouveau->pNom = (char*) malloc((strlen(pTab)+1) * sizeof(char));
	strcpy(pNouveau->pNom, pTab);

	printf ("entrer le prenom :");
	scanf ("%s", pTab);
	pNouveau->pPrenom = (char*) malloc((strlen(pTab)+1) * sizeof(char));
	strcpy(pNouveau->pPrenom, pTab);

	printf ("entrer le mail :");
	scanf ("%s", pTab);
	pNouveau->pMail = (char*) malloc((strlen(pTab)+1) * sizeof(char));
	strcpy(pNouveau->pMail, pTab);

	pNouveau->pSuivant = NULL;
	
	pDebut = AjouterContact ( pNouveau , pDebut );

	return pDebut;
}

/*-----------------------------------------------------------------------------------------*/
/*############## Afficher un contact ############*/
/*------------------------------------------------------------------------------------------*/

void AfficherContact ( contact * pDebut )
{	
	contact * pTemp; 
	pTemp= pDebut;
	
	if (pDebut == NULL)
	{
		printf ("liste vide");
	}
	else 
	{
		do
		{
			printf(" Nom : %s\n", pTemp->pNom);
			printf(" Prenom : %s\n", pTemp->pPrenom);
			printf(" Mail : %s\n\n", pTemp->pMail);
			
			pTemp = pTemp->pSuivant;
		}
		while (pTemp!= NULL);
	}
}

/*----------------------------------------------------------------------------------------*/
/*############## liberer la memoire ############*/
/*----------------------------------------------------------------------------------------*/

contact * LibererContact (contact * pDebut)
{
	contact * pTemp;
	contact * pOld;
	char pTab[256];
	char choix;
	
	
	if (pDebut == NULL)
	{
		printf ("liste vide");
		return NULL;
	}
	else 
	{
		printf ("entrer le nom du contact à supprimer:");
		scanf("%s", pTab);
		pTemp = pDebut;
		pOld = pTemp;
		
		do
		{		
			if(strcmp(pTab,pTemp->pNom)==0)
			{

				printf("es ce bien le contact %s%s à modifier \n", pTemp->pNom, pTemp->pPrenom);
				printf("tapez 'O' pour confirmer, 'N' pour chercher un autre %s \n", pTab);
				choix=getchar();
				getchar();
					
				switch(choix)
				{
					case 'O':
					case 'o':
					{
						if (pTemp == pDebut)
						{	
							pDebut = pDebut->pSuivant;
							free (pTemp->pNom);
							free (pTemp->pPrenom);
							free (pTemp->pMail);
							free(pTemp);
						}	
						else					
						{	
							pTemp = pTemp->pSuivant;						
							pOld->pSuivant = pTemp->pSuivant;
							free (pTemp->pNom);
							free (pTemp->pPrenom);
							free (pTemp->pMail);
							free(pTemp);
							pTemp = pOld->pSuivant;
						}
					}
					break;
		
					case 'N':
					case 'n':
					break;
				
					default:
						printf("choix incorrect");
					break;
				}
			}
			else
				pTemp = pTemp->pSuivant;
		}
		while (choix != 'o' || choix != 'O' || choix != 'n' || choix != 'N' );
		
	}
	return pDebut;
}	

/*----------------------------------------------------------------------------------------*/
/*############  modifier/carnet  ###############*/
/*----------------------------------------------------------------------------------------*/

contact * modifierContact (contact * pDebut)
{
	contact * pTemp;
	char pTab[256];
	char choix;

	printf("quel est le nom du contact à modifier ?/n");
	scanf("%s", pTab);
	
	if (pDebut == NULL)
	{
		printf("liste vide");
		return NULL;
	}
	else
	{
		pTemp = pDebut;
		
		do
		{
			if(strcmp(pTab,pTemp->pNom)==0)
			{
				printf("es ce bien le contact %s  %s à modifier \n", pTemp->pNom, pTemp->pPrenom);
				printf("tapez 'O' pour confirmer, 'N' pour chercher un autre %s \n", pTab);
				scanf("%c", &choix);
				getchar();
				
				switch(choix)
				{
					case 'O':
					case 'o':
					{
						printf("nouveau nom:");
						scanf("%s", pTemp->pNom);
						printf("nouveau prenom:");
						scanf("%s", pTemp->pPrenom);
						printf("nouveau mail:");
						scanf("%s", pTemp->pMail);
					}
					break;
				
					case 'N':
					case 'n':
					break;
			
					default:
						printf("choix incorrect\n");
					break;
				}
				
			}
			else
				pTemp = pTemp->pSuivant;
		}
		while (choix != 'o' || choix != 'O' || choix != 'n' || choix != 'N');
	}
	
	return pDebut;
}

/*----------------------------------------------------------------------------------------*/
/*#########  Enregistrer dans fichier  ############*/
/*----------------------------------------------------------------------------------------*/

void Enregistrer (contact * pDebut)
{
	contact * pTemp= NULL;
	FILE * pFichier = NULL;
	char pTab[256];
		
	printf( "entrez le nom du fichier \n");
	scanf( "%s", pTab );
	pFichier = fopen (pTab , "w");
	
	if(pFichier == NULL)
	{
	    printf("Erreur: fichier non crée.\n");
	}
	
	pTemp = pDebut;
	while (pTemp != NULL)
	{
		fprintf (pFichier,"Nom: %s\n", pTemp->pNom );
		fprintf (pFichier,"Prenom: %s\n", pTemp->pPrenom );
		fprintf (pFichier,"Courriel: %s\n\n", pTemp->pMail );
		pTemp = pTemp->pSuivant;
	}
	
	fclose (pFichier);
}

/*----------------------------------------------------------------------------------------*/
/*############## fichier >> carnet ############*/
/*----------------------------------------------------------------------------------------*/

void ChargerListe ()
{
	FILE* pFichier = NULL;
	char pTab[256], pTab1[256];
	contact * pNouveau;
	
	printf( "entrez le nom du fichier \n");
	scanf( "%s", pTab );
	pFichier = fopen (pTab , "r");
	
	if(pFichier == NULL) 
	{
		printf("Erreur : fichier inexistant %s \n", pTab);
		
	}
	
	pNouveau = (contact * ) malloc ( sizeof(* pNouveau));

	while (feof(pFichier) !=0 )
	{ 
		fscanf(pFichier,"%s %s", pTab, pTab1 );
		pNouveau->pNom = (char *) malloc(( strlen( pTab1 ) + 1 ) * sizeof( char ) );
		strcpy(pNouveau->pNom, pTab1);
		printf("\n nom %s ",pNouveau->pNom);
		
		fscanf(pFichier,"%s %s", pTab, pTab1 );
		pNouveau->pPrenom = (char *) malloc(( strlen( pTab1 ) + 1 ) * sizeof( char ) );
		strcpy(pNouveau->pPrenom, pTab1);
		printf("\n prenom%s ",pNouveau->pPrenom);
		
		fscanf(pFichier,"%s %s", pTab, pTab1 );
		pNouveau->pMail = (char *) malloc(( strlen( pTab1 ) + 1 ) * sizeof( char ) );
		strcpy(pNouveau->pMail, pTab1);
		printf("\n Mail %s ",pNouveau->pMail);
	}	
}

/*----------------------------------------------------------------------------------------*/
/*################### MAIN ###############*/
/*----------------------------------------------------------------------------------------*/

int main(int argc, char ** argv)
{
	contact * pDebut= NULL;
	char choix;
	do 
	{
		printf("-----------------------------------------------------------\n");
		printf("appuyer sur la touche:\n");
		printf("C : creer un contact\n");
		printf("S : supprimer un contact\n");
		printf("A : afficher un contact\n");
		printf("M : modifier un contact\n");
		printf("E : enregistrer un contact\n");
		printf("L : creer un carnet à partir d'un fichier de contact\n");
		printf("q : quitter\n");
		printf("-----------------------------------------------------------\n");
		scanf("%c", &choix);
		

		switch (choix)
		{
			case 'c':
			case 'C':
				pDebut = CreerContact (pDebut);
			break;
		
			case 's':
			case 'S':
				pDebut = LibererContact (pDebut);
			break;
			
			case 'a':
			case 'A':
				AfficherContact ( pDebut );
			break;
			
			case 'm':
			case 'M':
				pDebut = modifierContact (pDebut);
			break;
			
			case 'e':
			case 'E':
				Enregistrer (pDebut);
			break;
			
			case 'l':
			case 'L':
				ChargerListe ();
			break;
			
			default :
				printf("choix non valide \n");
			break;
		}
		getchar();
	}
	while (choix != 'q' || choix != 'Q');
		
	return 0;
}
