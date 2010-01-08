
/* Auteur Safia Hamiche */

/* Master II Compétences Complémentaire en Informatique */

/* Mini-projet n°: 3 */

/* Chargement des bibliothèques <stdio.h>, <stlib.h>, <string.h> */

# include <stdio.h>
# include <stdlib.h>
# include <string.h>

/* ### Création d'une structure comportant le nom, le prénom et l'adresse courriel du contact ### */

typedef struct sContact
 
{
	char   cNom[255] ;
	char  cPrenom[255] ;
	char  cCourriel[255] ;
	struct sContact * suivant ; 
} Contact;

Contact * Tete=NULL; /* Initialisation de la Tête de la liste de contacts à NULL */


/* ### Fonction Ajouter un contact au début ou à la fin de la chaîne ### */

int AjouterContact(Contact * C,int choix)
{

	if(Tete== NULL) 
		{ 
			/* La liste des contacts est vide*/
		Tete=C; 
		C->suivant=NULL;
		}
	else
		{

 	switch (choix)

		{
			
		case 1: 
			
			/* Ajouter un contact au Debut(C); */
			{
			C->suivant=Tete;
			Tete=C;
			break;
			}
			
		case 2: 
			
			/* Ajouter un contact à la Fin(C); */
			{
			Contact * Queue=Tete;
			while(Queue->suivant != NULL) Queue=Queue->suivant;
			Queue->suivant=C;
			C->suivant=NULL;
			/*Queue=C;*/
			break;
			}

		case 3: 
			
			/* AjouterEmplacement(C); */
			break;

		}
	}

return 1;
}
	
/* ###  Fonction qui affiche un seul contact ### */

void AfficherContact ( Contact * c) 

{
	if(c!=NULL)

	{	printf ( "Nom: %s\n" , c->cNom ) ;
		printf ( "Prénom: %s\n" , c->cPrenom ) ;
		printf ( "Courriel: %s\n\n" , c->cCourriel ) ;
	}
	else
	{

	printf("Contact Vide!! \n");

	}
}

/* ### Fonction qui affiche tous les contacts du carnet d'adresses ### */

void AfficherContacts()

{

	if(Tete==NULL)

	{
	printf("Le carnet d'adresses est vide!!\n");
	}
	else
	{
	int i=0;
	Contact *p=Tete;
	
		while(p!=NULL)
			{
			i=i+1;
			printf("Contact numéro %d\n",i);
			AfficherContact(p);
			p=p->suivant;
			}
		printf("Le nombre de contacts affichés est : %d \n",i);
	}

}

/* ### Enregistrer la liste des contacts du carnet d'adresses ### */

int SauvegarderListe()

{
FILE * pFichier = NULL ; /* Pointeur sur un File */
printf("Sauvegarde de la liste courante des contacts dans un fichier \n");
char NomFichier[50]="TP12.txt";
printf("Veuillez donner le nom du fichier destination...\n");
scanf("%s",NomFichier);

	if(Tete ==NULL) /* Null, si la liste des contact est vide */
	{
	printf("La liste est vide. Il n y a rien à enregistrer\n");
	}
	else
	{
		pFichier = fopen ( NomFichier, "w");
		Contact * p=Tete;
		while(p!= NULL)
		{	
		/* Ecrire le contenu de p dans le fichier pFichier */
		fwrite(p, sizeof(Contact),1, pFichier);
		p=p->suivant;	
		}
		fclose ( pFichier); /* Fermer le fichier à la fin */
		printf("Ecriture avec succès dans le fichier %s\n",NomFichier);
	}

}


/* ### Lire la liste des contacts à partir d'un fichier ### */

int ChargerListe()
{
	FILE * pFichier = NULL ;
	printf("Chargement d'une nouvelle liste des contacts à partir d'un fichier\n");
	char NomFichier[50]="TP12.txt";
	printf("Veuillez donner le nom du fichier à lire:\n");
	scanf("%s",NomFichier);
	pFichier = fopen ( NomFichier, "r");

		if(pFichier==NULL) 
		{
    		printf("Erreur: Impossible d'ouvrir le fichier %s \n", NomFichier);
    		return 1;
		}
		else
		{
		Tete=NULL;/* Queue=NULL; */
		Contact *p= (Contact *) malloc (sizeof (Contact)) ;
		int i=1;
			while( fread(p, sizeof(Contact), 1, pFichier)!=0){
			AjouterContact(p,2);
			p= (Contact *) malloc (sizeof (Contact)) ;
			printf("Element ajouté %d",i);
			i++;
		}
		free(p); 
		
		/* Le dernier espace a été alloué pour rien dans les deux cas soit le Fichier est Vide ou alors on est arrivé vers la fin du fichier */
		
		fclose ( pFichier); /*Fermer le fichier vers la fin*/
		printf("Lecture avec succès à partir du fichier %s\n",NomFichier);
	}

}

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
	/* Queue=NULL; */
	printf("La liste vient d'être vidée\n");
}



int SupprimerContact(char * Nom )
{

	Contact * Courant;
	Contact * Precedent;
	Contact * Vide;
	Courant=Tete;

int NbSupp=0;
char cc,cchaine[10];

/* On traiter d'abord la tête de la liste des contacts */
	
	while (Tete!=NULL && strcmp(Nom,Tete->cNom)==0)
	{
			printf("Contact Prénom: %s, Nom: %s, Courriel: %s trouvé. Voulez vous le supprimer? Taper o si oui ou autre touche sinon...\n", Tete->cPrenom,Tete->cNom,Tete->cCourriel);
			scanf("%s",cchaine);
			cc=cchaine[0];
				if(cc=='o' || cc=='O')
			{ 
				
			/* Suppression confirmée */
				
			Vide=Tete;
			Tete=Tete->suivant;
			free(Vide);
			NbSupp++;
			}
			
			/* Si on ne supprime pas de contact, on passe au contact suivant */
			
}

	if (Tete==NULL) 
	return NbSupp; /* On quitte la fonction */
	else 
	{
	Courant=Tete->suivant;
	Precedent=Tete;
	}

	while( Courant !=NULL) /* Tester si le contact existe dans e carnet d'adresses */
{
	if(strcmp(Nom,Courant->cNom)==0)
	{ 
	/* Chaîne trouvée */
		printf("Contact Prenom: %s, Nom: %s, Courriel: %s trouvé. Voulez vous le supprimer? Taper o si oui ou autre touche sinon...\n", Courant->cPrenom,Courant->cNom,Courant->cCourriel);
		scanf("%s",cchaine);
		cc=cchaine[0];
		if(cc=='o' || cc=='O')
		{ 
		/* Suppression confirmée */
			Vide=Courant;
			Courant=Courant->suivant;
			Precedent->suivant=Courant;
			free(Vide); /* Liberer l'espace occupé */
			NbSupp++;
		}
		else
		{ 
			Precedent=Courant;
			Courant=Courant->suivant;
		}
	}
	else
	{
		Precedent=Courant;
		Courant=Courant->suivant;
	}
}


return NbSupp;
}



int ModifierContact(char * Nom)
{
Contact * Courant;
Courant=Tete;
int NbMod=0;
char cc,cchaine[10];

	while(Courant !=NULL)
	{
	if(strcmp(Nom,Courant->cNom)==0)
	{ 
	/* Chaine trouvée */
		printf("Contact Prenom: %s, Nom: %s, Courriel: %s trouvé. Voulez vous le modifier? Taper o si oui ou autre touche sinon...\n", Courant->cPrenom,Courant->cNom,Courant->cCourriel);
		scanf("%s",cchaine);
		cc=cchaine[0];
		if(cc=='o' || cc=='O')
		{ 
		/* Modification confirmée */
			

			/* Début de la modification */

			char cTemp [255] ;
			
	
			printf ( "Ancien nom : \"%s\".Entrez le nouveau Nom\n",Courant->cNom ) ;
			scanf ( "%s" , cTemp ) ;
	
			strcpy (Courant->cNom , cTemp) ;
	
			printf ( "Ancien prénom : \"%s\".Entrez le nouveau Prénom\n",Courant->cPrenom ) ;
			scanf ( "%s" , cTemp ) ;
	
			strcpy (Courant->cPrenom , cTemp) ;
	
			printf ( "Ancien courriel : \"%s\".Entrez la nouvelle adresse courriel \n",Courant->cCourriel ) ;
			scanf ( "%s" , cTemp ) ;
	
			strcpy (Courant->cCourriel , cTemp) ;

			/* Fin de la modification */

			NbMod++;
			}
		}

	Courant=Courant->suivant;
}


return NbMod;
}



int main ( int argc, char ** argv )
{
	char choix = 'q';
	char choixx[10];
	char Nom[255];
	int r=0;
	char quitter='8';
	do 
	{	
		printf ("\n###############################################\n") ;
		printf ( "###            Carnet d'adresses           ###\n" ) ;
		printf ("###############################################\n") ;
		printf ( "1 - Ajouter  un nouveau contact\n" ) ;
		printf ( "2 - Afficher tous les contacts du carnet d'adresses\n") ;
		printf ( "3 - Modiffier un contact\n" ) ;
		printf ( "4 - Supprimer d'un contact\n" ) ;
		printf ( "5 - Enregister le carnet d'adresses actuel dans un fichier\n") ;
		printf ( "6 - Charger un carnet d'adresses à partir d'un fichier\n") ;
		printf ( "7 - Liberer l'espace mémoire.\n") ;
		printf ( "8 - Quitter\n") ;
		/* Choix = getchar() ; */
		
		scanf("%s",choixx);
			
		choix=choixx[0];
		if(strlen(choixx)>1) choix='h';

		switch (choix)
		{
		/* ### Création d'un nouveau contact ### */

		case '1' :

		{
			char cTemp [255] ;
			
	
			Contact * C ;
			C = (Contact *) malloc (sizeof (Contact)) ;
			
			printf ( "Entrez le Nom\n" ) ;
			scanf ( "%s" , cTemp ) ;
	
			/* C->cNom = (char *) malloc ((strlen (cTemp) + 1)* sizeof (char)) ; */
			strcpy (C->cNom , cTemp) ;
	
			printf ( "Entrez le Prénom\n" ) ;
			scanf ( "%s" , cTemp ) ;
	
			/*C->cPrenom = (char *) malloc ((strlen (cTemp) + 1)* sizeof (char)) ;*/
			strcpy (C->cPrenom , cTemp) ;
	
			printf ( "Entrez l'adresse courriel \n" ) ;
			scanf ( "%s" , cTemp ) ;
	
			/*C->cCourriel = (char *) malloc ((strlen (cTemp) + 1)* sizeof (char)) ;*/
			strcpy (C->cCourriel , cTemp) ;
			
			r=AjouterContact(C,2);	
			if (r==1) printf("Le contact %s  %s ( E-mail: %s ) a été ajouté avec succès \n", C->cPrenom,C->cNom,C->cCourriel);		

			break ;
		} 


		/* ### Affichage des contacts ### */	

		case '2' :

			{
			printf ("#########################################################################\n") ;
			printf ("##########      Affichage du carnet d'adresses   	      ###########\n") ;
			printf ("#########################################################################\n") ;
			AfficherContacts(); 	
			break ;
		}		

		/* ### Modification d'un contact ### */
		
		case '3' :

			{
			if(Tete!=NULL)
			{
				printf ("Quel est le Nom du contact que vous voulez modifier\n") ;
				scanf ("%s", Nom) ; 
				int r=ModifierContact(Nom);
				if(r==0) printf("Contact introuvable dans le carnet d'adresses\n");
				else printf("Le nombre de contacts modifiés est : %d",r);
			}
			else{
				printf("Le carnet d'addresses est vide!!");
			}
			break ;
		} 
		/* ### Suppression d'un contact ### */
		
		case '4' :

			{
			if(Tete!=NULL)
			{
				printf ("Quel est le Nom du contact que vous voulez supprimer\n") ;
				scanf ("%s", Nom) ; 
				int r=SupprimerContact(Nom);
				if(r==0) printf("Contact introuvable dans le carnet d'adresses\n");
				else printf("Le nombre de contacts supprimés est : %d",r);
			}
			else{
				printf("Le carnet d'adresses est vide!!");
			}
			break ;
		} 

		case '5' :

			{
			/* Sauvegarde du carnet de contacts dans un fichier */
			SauvegarderListe();
			break ;	
		} 

		case '6' :

			{ /* Chargement du carnet de contacts à partir d'un fichier */

			ViderListe(); /* Liberer l'espace memoire occupé par l'ancienne liste de contacts */
			ChargerListe();
			break ;	
		} 

		case '7' :

			{ /* Chargement du carnet de contacts à partir d'un fichier */

			ViderListe(); /* Liberer l'espace memoire occupé par l'ancienne liste de contacts */
			break ;	
		} 

		case '8' :

			{ 
			/* Quitter le programme */
			printf ("Nous quittons le programme\n") ;
			printf ("Libération de l'espace\n") ;
			ViderListe();
			break ;	
		} 

		default :
			{
			printf( "Erreur: Ce choix ne figure pas dans le menu. Veuillez taper un chiffre entre 1 et %d \n", quitter);
		}
		}
		
	} while( choix != quitter );
		
return 0 ;
}


	
