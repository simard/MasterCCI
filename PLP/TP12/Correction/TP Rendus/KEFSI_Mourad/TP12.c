/*######################### Mourad KEFSI ##
########################### Master 2 CCI ##
########################### TP n°12 #######*/ 

# include <stdio.h>
# include <stdlib.h>
# include <string.h>



/* ### Creation d'une structure comportant les informations nécessaire d'un contact
A savoir le nom, le prenom et l'adresse courriel  ### */

typedef struct sContact 
{
	char   cNom[255] ;
	char  cPrenom[255] ;
	char  cCourriel[255] ;
	struct sContact * suivant ; 
} Contact;

/* initialisation de la tete de la liste*/
Contact * Tete=NULL; 


/* Création d'une fonction pour ajouter un contact au debut ou à la fin de la chaine*/
int AjouterContact(Contact * C,int choix)
{

if(Tete== NULL) { /* Vérification si la liste est vide */
	Tete=C; 
	C->suivant=NULL;
	}
else{
 	switch (choix)
		{
			/* Ajout d'un contact au début de la liste */
		case 1: {
			C->suivant=Tete;
			Tete=C;
			break;
			}
		
			/* Ajout d'un contact à la fin de la liste */			
		case 2: 
			{
			Contact * Queue=Tete;
			while(Queue->suivant != NULL) Queue=Queue->suivant;
			Queue->suivant=C;
			C->suivant=NULL;
			break;
			}
			/* Ajout d'un contact à un enmplacement de la liste */
		case 3: 
			break;
		}
	}
return 1;
}

/* Création d'une fonction qui affiche un seul contact */

void AfficherContact ( Contact * c) 
{
	if(c!=NULL)
	{	printf ( "Le nom du contact est: %s\n" , c->cNom ) ;
		printf ( "Le prenom du contact est: %s\n" , c->cPrenom ) ;
		printf ( "L'adresse courriel du contact est: %s\n\n" , c->cCourriel ) ;
	}else
	{
	printf("Ce contact n'existe pas \n");
	}
}

/* Création d'une fonction qui affiche tous les contacts */
void AfficherContacts()
{
if(Tete==NULL)
	{
	printf("Votre carnet d'addresses est vide!!\n");
	}
else
	{
	int i=0;
	Contact *p=Tete;
	while(p!=NULL){
		i=i+1;
		printf("Contact n° %d\n",i);
		AfficherContact(p);
		p=p->suivant;
		}
	printf("Vous avez %d contacts affichés \n",i);
	}

}

/* Création d'une fonction qui affiche tous les contacts */
int SauvegarderListe()
{
FILE * pFichier = NULL ;
printf("Vous voulez sauvegarder de la liste des contacts dans un fichier \n");
char NomFichier[50]="TP12.txt";
printf("Quel est le nom du fichier destination\n");
scanf("%s",NomFichier);

	/* Vérifiction de la liste si elle est vide */
if(Tete ==NULL) 
{
	printf("La sauvegard a échoué, la liste est vide\n");
}
else
{
	pFichier = fopen ( NomFichier, "w");
	Contact * p=Tete;
	while(p!= NULL)
	{	
		/* Si la liste n'est pas vide, alors tout son contenu sera dans le fichier pFichier */
		fwrite(p, sizeof(Contact),1, pFichier);
		p=p->suivant;	
	}
	fclose ( pFichier); /*Fermer le fichier vers la fin*/
	printf("La sauvegard effectuée avec succès dans le fichier %s\n",NomFichier);
}

}


/* Fonction de lecture d'une liste à partir d'un fichier */
int ChargerListe()
{
FILE * pFichier = NULL ;
printf("Lecture d'une liste à partir d'un fichier\n");
char NomFichier[50]="TP12.txt";
printf(" Quel est le nom du fichier à lire:\n");
scanf("%s",NomFichier);
pFichier = fopen ( NomFichier, "r");

if(pFichier==NULL) {
    	printf(" Le fichier %s que vous demander n'existe pas\n", NomFichier);
    	return 1;
}
else{
	Tete=NULL;
	Contact *p= (Contact *) malloc (sizeof (Contact)) ;
	int i=1;
	while( fread(p, sizeof(Contact), 1, pFichier)!=0){
		AjouterContact(p,2);
		p= (Contact *) malloc (sizeof (Contact)) ;
		printf("L'element %d a été ajouté ",i);
		i++;
	}
	/* Libération de l'espace mémoir allouer a p */
	free(p); 
	fclose ( pFichier); 
	printf("La liste à bien été lu à partir du fichier %s\n",NomFichier);
}




}

/* Suppression de la liste après l'avoir vider de tous les contacts */

int ViderListe()
{
Contact *p=Tete;
Contact * q;
while(p!=NULL)
{
	q=p;
	p=p->suivant;
	free(q);
}
Tete=NULL;
/*Queue=NULL;*/
printf("La liste vient est supprimée\n");
}

/* Fonction pour supprimer un contact */

int SupprimerContact(char * Nom )
{


Contact * Courant;
Contact * Precedent;
Contact * Vide;
Courant=Tete;
int NbSupp=0;
char cc,cchaine[10];

while (Tete!=NULL && strcmp(Nom,Tete->cNom)==0)
{
			printf("Voulez vous supprimer le contact : Prenom: %s, Nom: %s, Courriel: %s ? Taper y ou Y si oui ou une autre touche sinon...\n", Tete->cPrenom,Tete->cNom,Tete->cCourriel);
			scanf("%s",cchaine);
			cc=cchaine[0];
	/* Si la suppression est confermée */
			if(cc=='y' || cc=='Y'){ 
			Vide=Tete;
			Tete=Tete->suivant;
			free(Vide);
			NbSupp++;
			}
}
/* On sort de la boucle si la tete est null */
if (Tete==NULL) return NbSupp; 
else {
	Courant=Tete->suivant;
	Precedent=Tete;
}

while( Courant !=NULL) /*Tester si le contact a supprimer existe */
{
	if(strcmp(Nom,Courant->cNom)==0){ /*chaine trouvée*/
		printf("Voulez vous supprimer le contact : Prenom: %s, Nom: %s, Courriel: %s ? Taper y ou Y si oui ou une autre touche sinon...\n", Courant->cPrenom,Courant->cNom,Courant->cCourriel);
		scanf("%s",cchaine);
		cc=cchaine[0];
		if(cc=='y' || cc=='Y'){ /* Dans le cas au la suppression est confirmée*/

			Vide=Courant;
			Courant=Courant->suivant;
			Precedent->suivant=Courant;
			free(Vide);
			NbSupp++;
			}
		else{ 
			Precedent=Courant;
			Courant=Courant->suivant;
			}
		}
	else{
		Precedent=Courant;
		Courant=Courant->suivant;
		}
	}


return NbSupp;
}

/* Création d'un fonction pour modifier un contact */

int ModifierContact(char * Nom)
{
Contact * Courant;
Courant=Tete;
int NbMod=0;
char cc,cchaine[10];
while(Courant !=NULL)
{
	if(strcmp(Nom,Courant->cNom)==0){ /*chaine trouvée*/
		printf("Voulez vous modifier le contact Prenom: %s, Nom: %s, Courriel: %s? Taper y ou Y si oui ou une autre touche sinon...\n", Courant->cPrenom,Courant->cNom,Courant->cCourriel);
		scanf("%s",cchaine);
		cc=cchaine[0];
		if(cc=='y' || cc=='Y'){ /* Dans le cas au la modification est confirmée*/

			char cTemp [255] ;
			
	/* Modification du nom */
			printf ( "L'ancien nom est: \"%s\".Entrez le nouveau Nom\n",Courant->cNom ) ;
			scanf ( "%s" , cTemp ) ;
	
			strcpy (Courant->cNom , cTemp) ;
	
			/* Modification du prénom */
			printf ( "L'ancien prénom est: \"%s\".%sEntrez le nouveau Prenom\n",Courant->cPrenom ) ;
			scanf ( "%s" , cTemp ) ;
	
			strcpy (Courant->cPrenom , cTemp) ;
			
	/* Modification de l'adresse courriel */
			printf ( "L'ancienne adresse courriel est: \"%s\".Entrez la nouvelle adresse courriel \n",Courant->cCourriel ) ;
			scanf ( "%s" , cTemp ) ;
	
			strcpy (Courant->cCourriel , cTemp) ;

			
			NbMod++;
			}
		}

	Courant=Courant->suivant;
}


return NbMod;
}

 /* Début du programme */

int main ( int argc, char ** argv )
{
	char choix = 'q';
	char choixx[10];
	Contact UnContact ;
	char Nom[255];
	int r=0;
	char quitter='8';
	while( choix != quitter )
		{
			printf ("Carnet d'adresse\n" ) ;
			printf (" Veillez faire votre choix\n" ) ;
			printf ( "1 - Ajout d'un nouveau contact\n" ) ;
			printf ( "2 - Affichage de tous les contacts du carnet d'addresses\n") ;
			printf ( "3 - Modiffication d'un contact\n" ) ;
			printf ( "4 - Suppression d'un contact\n" ) ;
			printf ( "5 - Enregistrement du carnet d'addresses dans un fichier\n") ;
			printf ( "6 - Chargement d'un carnet d'addresses à partir d'un fichier\n") ;
			printf ( "7 - Suppression du carnet d'adresse\n") ;
			printf ( "8 - Quitter\n") ;
	
			scanf("%s",choixx);
			choix=choixx[0];
			if(strlen(choixx)>1) choix='h';
				switch (choix)
			{
		/* Ajout d'un nouveau contact */

				case '1' :
					{
						char cTemp [255] ;
						Contact * C ;
						C = (Contact *) malloc (sizeof (Contact)) ;
						printf ( "Entrez le Nom\n" ) ;
						scanf ( "%s" , cTemp ) ;
						strcpy (C->cNom , cTemp) ;
	
						printf ( "Entrez le Prenom\n" ) ;
						scanf ( "%s" , cTemp ) ;		
						strcpy (C->cPrenom , cTemp) ;
	
						printf ( "Entrez l'adresse courriel \n" ) ;
						scanf ( "%s" , cTemp ) ;
						strcpy (C->cCourriel , cTemp) ;
			
						r=AjouterContact(C,2);	
						if (r==1) printf("Le contact %s  %s ( E-mail: %s ) a été ajoouté avec succès \n", C->cPrenom,C->cNom,C->cCourriel);
							break ;
					} 


		/* Affichage de tous les contacts ### */	

				case '2' :
					{
					printf ("Le carnet d'adresse contien les contacts suivants:\n") ;
					AfficherContacts(); 	
					break ;
					}		

		/* Modification d'un contact */
		
				case '3' :
					{
					if(Tete!=NULL)
						{
						printf ("Quel est le Nom du contact que vous voulez modifier\n") ;
						scanf ("%s", Nom) ; 
						int r=ModifierContact(Nom);
						if(r==0) printf("Contact introuvable dans le carnet d'addresse\n");
						else printf("Nombre de contacts modifiés: %d",r);
						}
						else{
							printf("Le carnet d'addresses est vide!!");
							}
					break ;
					} 
		/* Suppression d'un contact */
		
				case '4' :
					{
					if(Tete!=NULL)
						{
						printf ("Quel est le Nom du contact que vous voulez supprimer\n") ;
						scanf ("%s", Nom) ; 
						int r=SupprimerContact(Nom);
						if(r==0) printf("Contact introuvable dans le carnet d'addresse\n");
						else printf("Nombre de contacts supprimés: %d",r);
						}
						else{
							printf("Le carnet d'addresses est vide!!");
							}
					break ;
					} 

		/* Enregistrement du carnet d'adresse dans un fichier */
				case '5' :
					{
					SauvegarderListe();
					break ;	
					} 

		/* Charger un carnet d'adresse a partir d'un fichier */
				case '6' :
					{ 
					ViderListe(); 
					ChargerListe();
					break ;	
					} 

		/* Suppression du carnet d'adresse */
				case '7' :
					{ 
					ViderListe(); 
					break ;	
					} 

		/* Quetter le programme */
				case '8' :
					{ 
					printf ("Nous quittons le programme\n") ;
					printf ("Libération de l'espace\n") ;
					ViderListe();
					break ;	
					} 

				default :
				{
				printf( "Mauvaise entree, vuillez taper un chiffre entre 1 et %d\n", quitter);
				}
			}
		
		} 
		return 0 ;
}


	
