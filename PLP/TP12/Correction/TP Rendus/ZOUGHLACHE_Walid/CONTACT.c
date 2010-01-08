# include<stdio.h>
# include<stdlib.h>
# include<string.h>



typedef struct sContact
{
char * cNom;
char * cPrenom;
char * cCourriel;
struct sContact * suivant;
}Contact;

Contact* INFOContact (Contact* UnContact )
			{
			
			char cTemp[256];
			void AffichageContact( Contact* );
			UnContact = (Contact*)malloc( sizeof( Contact ) ) ;
			printf ("Entrer votre nom:");
			scanf ("%s",cTemp);
			UnContact -> cNom=(char *) malloc((strlen(cTemp)+1) * sizeof(char));
			strcpy (UnContact -> cNom, cTemp);	

			printf ("Entrer votre prenom:");
			scanf ("%s",cTemp);
			UnContact -> cPrenom=(char *) malloc((strlen(cTemp)+1) * sizeof(char));
			strcpy (UnContact -> cPrenom, cTemp);
				
			
			printf ("Entrer votre Courriel:");
			scanf ("%s",cTemp);
			UnContact -> cCourriel=(char *) malloc((strlen(cTemp)+1) * sizeof(char));
			strcpy (UnContact -> cCourriel, cTemp);
			
			UnContact -> suivant = NULL;	
				
				
				
			return UnContact;
			}

Contact* insererEnTete( Contact* debut ) /*insrer un contact au debut de la liste*/
		{
		    
		     Contact* nouveau=debut ;
		     nouveau = INFOContact (nouveau);
				     
			if (debut==NULL)
			{
				debut =nouveau;
				nouveau -> suivant = NULL;
			}else 
				{
				nouveau -> suivant = debut;
				debut = nouveau ;
				}
		return debut ;
			    
		}
		                        
Contact* supprimerSuivant( Contact* debut )
{
	char tmp1[256];
	char tmp2[256];
	char cm=0;
	Contact* courant=debut;
	Contact* prec=debut;


	printf("donner le nom a supprimer: ");
	scanf("%s",tmp1);
	printf("donner le prenom a supprimer: ");
	scanf("%s",tmp2);
	/*printf("ete vous sur\nsi oui tappez '0' sinon '1'");
		scanf("%c",&cm);
		getchar();
		switch (cm)
		{
		case '0':
		{*/
	if( strcmp (debut->cNom, tmp1) == 0 && strcmp (debut->cPrenom, tmp2) == 0 ) /*le test sur la tete de la liste */
	{
		prec =debut->suivant;
		free( debut-> cNom );
		free( debut-> cPrenom );
		free( debut -> cCourriel );
		free(debut) ;
		debut=prec;
		return  debut;


	}
	else{
		while (courant != NULL )
		{
			if( strcmp (courant->cNom,tmp1 ) == 0 && strcmp (debut->cPrenom, tmp2) == 0) /*test sur les autres contacts de la liste*/
			{

				prec -> suivant =courant ->suivant;

				free( courant -> cNom ) ;
				free( courant -> cPrenom ) ;
				free( courant -> cCourriel ) ;
				free(courant) ;
				return debut;

			}else{ 
				prec = courant;
				courant = courant ->suivant ;
			}
		}
	}
	return debut;
	/*}break;
		case '1':
		{
		return debut;
		}break;default:
		{

		}
		}*/		
}

void AffichageContact( Contact * MOT) /*afficher la liste*/
			{
			int i=0;
				
			while (MOT != NULL )
				{
				i++;
				printf ("contact num %d\n",i);
			
				printf ("\nNom:%s\n",MOT -> cNom);
				printf ("Prenom:%s\n",MOT -> cPrenom);
				printf ("Courriel:%s\n\n",MOT -> cCourriel);
				MOT = MOT -> suivant;
				 
				}
				return ;
				
			}

Contact* ModifierContact( Contact* debut ) /*modifier un contact de la liste*/
		{
			char tmp[256];
			char tmpNom[256];
			char tmpPrenom[256];
			char tmpCourriel[256];
		 	Contact* courant=debut;
			Contact* prec=debut;
			
		     printf("donner le nom a Modiffier: ");
			scanf("%s",tmp);
			
			
			while (courant != NULL )
			{
			    if( strcmp (courant->cNom,tmp ) == 0) 
			    {
			     	printf("donner le nouveau nom: ");
				scanf("%s",tmpNom);
				printf("donner le nouveau prenom: ");
				scanf("%s",tmpPrenom);
				printf("donner le nouveau courriel: ");
				scanf("%s",tmpCourriel);		   
				strcpy (courant -> cNom, tmpNom);
				strcpy (courant -> cPrenom, tmpPrenom);
				strcpy (courant -> cCourriel, tmpCourriel);
				   	return debut;
								    
			    }else{ 
				printf("Ce nom n'existe pas\n");
			    prec = courant;
			    courant = courant ->suivant ;
			   }
			    
			    
			}
		    return debut;
		}
/*Contact* fichier( Contact * Fich )
{
	FILE * pFichier = NULL;

	pFichier = fopen( Fich, "w" );
	if( pFichier == NULL )
	{
		printf( "!!! ERREUR !!! Impossible d'enregistrer le fichier\n" );
		return Fich;
	}
	
	fwrite( Fich, pFichier );
	fclose( pFichier );

	return Fich;
}*/
/*Contact* ficher( Contact* Fich )
{
	
	FILE * pFichier = NULL;

	fopen( Contact* Fich, "r" );
	if( pFichier == NULL )
	{
		printf( "!!! ERREUR !!! Impossible d'ouvrir le fichier\n" );
		return Fich;
	}
	fclose( pFichier );

	return Fich;
}*/
int main (int argc , char ** argv)
{
Contact* info=NULL;
Contact* debut=NULL;
Contact* tete=NULL;
Contact* MOT=NULL;
char val=0;
int res=0;

do{	
printf ("**************MENU****************\n");

printf ("pour ajouter un contact tapez  'a'\n");
printf ("pour afficher les contacts tapez  'f'\n");
printf ("pour supprimer un contact tapez 's'\n");
printf ("pour modifier un contact tapez 'm'\n");
printf ("pour quitter le menu  tapez  'q'\n");
scanf("%c",&val);
/*getchar();*/
printf ("\n\n");

switch (val)
			{
			case 'a':
			case 'A':
					{
					tete = insererEnTete(tete);
				
					}break;
			case 'f':
			case 'F':
					{
					AffichageContact(tete);
					/*tete =fichier(tete);*/
					}break;
			case 's':
			case 'S':
					{
					tete=supprimerSuivant(tete);
					}break;
			
			case 'm':
			case 'M':
					{
					tete=ModifierContact(tete);
					}break;
			
			case 'q':
			case 'Q':
					{
					printf ("merci !!!\n");
					return 0;
					}break;
					default:
						{
						printf ("choix non autoriser\n");
						}
				
			}
getchar();
		}while( val == 'f' || val=='a' || val== 'm' || val== 's' );

return 0;
	
}

