/* Mini-projet 3 */
# include <stdio.h>
# include <stdlib.h>
# include <string.h>


typedef struct sContact

/*#une structure qui comporte le nom, le prenom et l'adresse courriel d'un contact#*/
{
	char   cNom[255] ;
	char  cPrenom[255] ;
	char  cCourriel[255] ;
	struct sContact * suivant ; 
} Contact;

Contact * Tete=NULL; 


/*L'ajout du contact au debut ou à la fin de la chaine*/
int AjouterContact(Contact * C,int choix)
{

if(Tete== NULL) { /*il n'y a rien*/
	Tete=C; 
	C->suivant=NULL;
	}
else{
 	switch (choix)
		{
		case 1: {/*AjouterDebut(C);*/
			C->suivant=Tete;
			Tete=C;
			break;
			}
			
		case 2: /*AjouterFin(C);*/
			{
			Contact * Queue=Tete;
			while(Queue->suivant != NULL) Queue=Queue->suivant;
			Queue->suivant=C;
			C->suivant=NULL;
			/*Queue=C;*/
			break;
			}
		case 3: /*AjouterEmplacement(C);*/
			break;
		}
	}
return 1;
}
	
/*L'affichage d'un seul contact*/
void AfficherContact ( Contact * c) 
{
	if(c!=NULL)
	{	printf ( "Nom: %s\n" , c->cNom ) ;
		printf ( "Prenom: %s\n" , c->cPrenom ) ;
		printf ( "Courriel: %s\n\n" , c->cCourriel ) ;
	}else
	{
	printf("Contact Vide!! \n");
	}
}

/*L'affichage de tous les contacts*/
void AfficherContacts()
{
if(Tete==NULL)
	{
	printf("Le carnet d'addresses est vide!!\n");
	}
else
	{
	int i=0;
	Contact *p=Tete;
	while(p!=NULL){
		i=i+1;
		printf("Contact numero %d\n",i);
		AfficherContact(p);
		p=p->suivant;
		}
	printf("Nombre de contacts affichés: %d \n",i);
	}

}

int SauvegarderListe()
{
FILE * pFichier = NULL ;
printf("Sauvegarde de la liste courante des contacts dans un fichier \n");
char NomFichier[50]="TP12.txt";
printf("Veuillez donner le nom du fichier destination...\n");
scanf("%s",NomFichier);

if(Tete ==NULL) /*si la liste est vide*/
{
	printf("La liste est vide. il n y a rien à sauvegarder\n");
}
else
{
	pFichier = fopen ( NomFichier, "w");
	Contact * p=Tete;
	while(p!= NULL)
	{	/*ecrie le contenu de p dans le fichier pFichier*/
		fwrite(p, sizeof(Contact),1, pFichier);
		p=p->suivant;	
	}
	fclose ( pFichier); /*Fermer le fichier vers la fin*/
	printf("Ecriture avec succès dans le fichier %s\n",NomFichier);
}

}


/*Lire à partir d'un fichier*/
int ChargerListe()
{
FILE * pFichier = NULL ;
printf("Chargement d'une nouvelle liste à partir d'un fichier\n");
char NomFichier[50]="TP12.txt";
printf("Veuillez donner le nom du fichier à lire:\n");
scanf("%s",NomFichier);
pFichier = fopen ( NomFichier, "r");

if(pFichier==NULL) {
    	printf("Erreur: impossible d'ouvrir le fichier %s \n", NomFichier);
    	return 1;
}
else{
	Tete=NULL;/*Queue=NULL;*/
	Contact *p= (Contact *) malloc (sizeof (Contact)) ;
	int i=1;
	while( fread(p, sizeof(Contact), 1, pFichier)!=0){
		AjouterContact(p,2);
		p= (Contact *) malloc (sizeof (Contact)) ;
		printf("Element ajouté %d",i);
		i++;
	}
	free(p); 
	fclose ( pFichier); /*Fermer le fichier vers la fin*/
	printf("Lécture avec succès à partir du fichier %s\n",NomFichier);
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
/*Queue=NULL;*/
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


while (Tete!=NULL && strcmp(Nom,Tete->cNom)==0)
{
			printf("Contact Prenom: %s, Nom: %s, Courriel: %s trouvé. Voulez vous le supprimer? Taper o si oui ou autre touche sinon...\n", Tete->cPrenom,Tete->cNom,Tete->cCourriel);
			scanf("%s",cchaine);
			cc=cchaine[0];
			if(cc=='o' || cc=='O'){ 
			Vide=Tete;
			Tete=Tete->suivant;
			free(Vide);
			NbSupp++;
			} 
}

if (Tete==NULL) return NbSupp; 
else {
	Courant=Tete->suivant;
	Precedent=Tete;
}

while( Courant !=NULL) 
{
	if(strcmp(Nom,Courant->cNom)==0){ 
		printf("Contact Prenom: %s, Nom: %s, Courriel: %s trouvé. Voulez vous le supprimer? Taper o si oui ou autre touche sinon...\n", Courant->cPrenom,Courant->cNom,Courant->cCourriel);
		scanf("%s",cchaine);
		cc=cchaine[0];
		if(cc=='o' || cc=='O'){ 
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



int ModifierContact(char * Nom)
{
Contact * Courant;
Courant=Tete;
int NbMod=0;
char cc,cchaine[10];
while(Courant !=NULL)
{
	if(strcmp(Nom,Courant->cNom)==0){ 
		printf("Contact Prenom: %s, Nom: %s, Courriel: %s trouvé. Voulez vous le modifier? Taper o si oui ou autre touche sinon...\n", Courant->cPrenom,Courant->cNom,Courant->cCourriel);
		scanf("%s",cchaine);
		cc=cchaine[0];
		if(cc=='o' || cc=='O'){ /*Modification confirmée*/
			

			/*Debut de la modification*/

			char cTemp [255] ;
			
	
			printf ( "Ancien nom: \"%s\".Entrez le nouveau Nom\n",Courant->cNom ) ;
			scanf ( "%s" , cTemp ) ;
	
			strcpy (Courant->cNom , cTemp) ;
	
			printf ( "Ancien prénom: \"%s\".%sEntrez le nouveau Prenom\n",Courant->cPrenom ) ;
			scanf ( "%s" , cTemp ) ;
	
			strcpy (Courant->cPrenom , cTemp) ;
	
			printf ( "Ancien courriel: \"%s\".Entrez la nouvelle adresse courriel \n",Courant->cCourriel ) ;
			scanf ( "%s" , cTemp ) ;
	
			strcpy (Courant->cCourriel , cTemp) ;

			/*Fin de la modification*/

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
	Contact UnContact ;
	char Nom[255];
	int r=0;
	char quitter='8';
	do 
	{	
		printf ("\n###############################################\n") ;
		printf ( "###            Carnet d'adresse           ###\n" ) ;
		printf ("###############################################\n") ;
		printf ( "1 - Ajouter  un nouveau contact\n" ) ;
		printf ( "2 - Afficher tous les contacts du carnet d'addresses\n") ;
		printf ( "3 - Modiffier un contact\n" ) ;
		printf ( "4 - Suppression d'un contact\n" ) ;
		printf ( "5 - Enregister le carnet d'addresses actuel dans un fichier\n") ;
		printf ( "6 - Charger un carnet d'addresses à partir d'un fichier\n") ;
		printf ( "7 - Liberer l'espace mémoire.\n") ;
		printf ( "8 - Quitter\n") ;
		
		
		scanf("%s",choixx);
			
		choix=choixx[0];
		if(strlen(choixx)>1) choix='h';

		switch (choix)
		{
		
		case '1' :

		{
			char cTemp [255] ;
			
	
			Contact * C ;
			C = (Contact *) malloc (sizeof (Contact)) ;
			
			printf ( "Entrez le Nom\n" ) ;
			scanf ( "%s" , cTemp ) ;
	
			/*C->cNom = (char *) malloc ((strlen (cTemp) + 1)* sizeof (char)) ;*/
			strcpy (C->cNom , cTemp) ;
	
			printf ( "Entrez le Prenom\n" ) ;
			scanf ( "%s" , cTemp ) ;
	
			/*C->cPrenom = (char *) malloc ((strlen (cTemp) + 1)* sizeof (char)) ;*/
			strcpy (C->cPrenom , cTemp) ;
	
			printf ( "Entrez l'adresse courriel \n" ) ;
			scanf ( "%s" , cTemp ) ;
	
			/*C->cCourriel = (char *) malloc ((strlen (cTemp) + 1)* sizeof (char)) ;*/
			strcpy (C->cCourriel , cTemp) ;
			
			r=AjouterContact(C,2);	
			if (r==1) printf("Le contact %s  %s ( E-mail: %s ) a été ajoouté avec succès \n", C->cPrenom,C->cNom,C->cCourriel);		

			break ;
		} 



		case '2' :

			{
			printf ("#########################################################################\n") ;
			printf ("##########      Affichage du carnet d'addresses   	      ###########\n") ;
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
				if(r==0) printf("Contact introuvable dans le carnet d'addresse\n");
				else printf("Nombre de contacts modifiés: %d",r);
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
				if(r==0) printf("Contact introuvable dans le carnet d'addresse\n");
				else printf("Nombre de contacts supprimés: %d",r);
			}
			else{
				printf("Le carnet d'addresses est vide!!");
			}
			break ;
		} 

		case '5' :

			{
			SauvegarderListe();
			break ;	
		} 

		case '6' :

			{ /*Chargement du carnet de contacts à partir d'un fichier*/

			ViderListe(); /*Liberer l'espace memoire occupé par l'ancienne liste*/
			ChargerListe();
			break ;	
		} 

		case '7' :

			{ /*Chargement du carnet de contacts à partir d'un fichier*/

			ViderListe(); /*Liberer l'espace memoire occupé par l'ancienne liste*/
			break ;	
		} 

		case '8' :

			{ /*sortir du programme*/
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


	
