/* Auteur : DJEBBARI  Taous*/
/* TP12 : mini-projet 3*/
/* le 13/11/2008*/
/* le but de ce mini-projet est de créer un programme permettant la gestion d’un carnet d’adresses
de courriel.*/
 /*Pour la création d’un tel programme, plusieurs fonctions peuvent être utiles.*/
 /*pour la céation d'une structure qui contien les trois chaine de caractère : le nom, le prenom et l'adresse courriel 
 nous avons utilisé : */
      /*typedef struct sContact 
{
	char   cNom[255] ;
	char  cPrenom[255] ;
	char  cCourriel[255] ;
	struct sContact * suivant ; 
} Contact;

Contact * Tete=NULL;*/
/* pour l'ajout contact au debut ou a la fin de la chaine nous avons utilisé la structure suivante

int AjouterContact(Contact * C,int choix)
{
if(Tete== NULL)
{ 
si la liste est vide :
	Tete=C; 
	C->suivant=NULL;
	}else{
 	switch (choix)
		{
		case 1:(l'Ajout de Debut(C);) 
             {
			C->suivant=Tete;
			Tete=C;
			break;
			}
			
		case 2: (l'Ajout de Fin(C);)
			{
			Contact * Queue=Tete;
			while(Queue->suivant != NULL) 
            Queue=Queue->suivant;
			Queue->suivant=C;
			C->suivant=NULL;
			break;
			}
		case 3: (l'Ajout de l'emplacement(C);)
			break;
		}
	}
return 1;
}*/
/*pour la construction de la Fonction qui affiche un seul et puis tout les contacts nous avons procédé comme suite :
- construction de la Fonction qui affiche un seul
void AfficherContact ( Contact * c) 
{
	if(c!=NULL)
	{	
        printf ( "Nom: %s\n" , c->cNom ) ;
		printf ( "Prenom: %s\n" , c->cPrenom ) ;
		printf ( "Courriel: %s\n\n" , c->cCourriel ) ;
	}else{
	printf("Contact est Vide!! \n");
	}
}
- construction de la Fonction qui affiche tous les contacts

void AfficherContacts()
{
if(Tete==NULL)
	{
	printf("Le carnet d'addresses est vide!!\n");
	}else{
	int i=0;
	Contact *p=Tete;
	while(p!=NULL)
    {
		i=i+1;
		printf("Contact numero %d\n",i);
		AfficherContact(p);
		p=p->suivant;
		}
	printf("Nombre de contacts affichérs: %d \n",i);
	}
}

int SauvegarderListe()
{
FILE * pFichier = NULL ;
printf("Sauvegarder la liste courante des contacts dans un fichier \n");
char NomFichier[50]="TP12.txt";
printf(" donner le nom du fichier \n");
scanf("%s",NomFichier);

- dans le cas ou si la liste est vide

if(Tete ==NULL) 
{
	printf("La liste est vide, rien a sauvegarder\n");
}
else
{
	pFichier = fopen ( NomFichier, "w");
	Contact * p=Tete;
	while(p!= NULL)
	{	*/
/*pour l'écriture d'un contenu dans un fichier on fait : 
-l'écriture de contenu de p dans le fichier pFichier :
		fwrite(p, sizeof(Contact),1, pFichier);
		p=p->suivant;	
	}
	fclose ( pFichier); (la Fermeture du fichier a la fin)
	printf("l'écriture dans le fichier %s\n",NomFichier);
}

}

/*pour la Licture à partir d'un fichier on procéde comme suite : 
int ChargerListe()
{
FILE * pFichier = NULL ;
printf("le Chargement d'une nouvelle liste a  partir d'un fichier\n");
char NomFichier[50]="TP12.txt";
printf(" donner le nom du fichier a  lire:\n");
scanf("%s",NomFichier);
pFichier = fopen ( NomFichier, "r");

if(pFichier==NULL) 
{
    	printf(" impossible d'ouvrir le fichier %s \n", NomFichier);
    	return 1;
}
else{
	Tete=NULL;
	Contact *p= (Contact *) malloc (sizeof (Contact)) ;
	int i=1;
	while( fread(p, sizeof(Contact), 1, pFichier)!=0)
    {
		AjouterContact(p,2);
		p= (Contact *) malloc (sizeof (Contact)) ;
		printf("l'élement ajouter est %d",i);
		i++;
	}
	free(p); 
/* pour la Ferméture du fichier vers la fin : 
	fclose ( pFichier); 
	printf("L'écture  à partir du fichier %s\n",NomFichier);
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

printf("La liste a été vidé \n");
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
			printf("Contact Prenom: %s, Nom: %s, Courriel: %s trouvé. Voulez vous le supprimer? Taper o si oui ou sinon taper autre touche \n", Tete->cPrenom,Tete->cNom,Tete->cCourriel);
			scanf("%s",cchaine);
			cc=cchaine[0];
/* pour la confirmation de la Suppression :
			if(cc=='o' || cc=='O'){ 
			Vide=Tete;
			Tete=Tete->suivant;
			free(Vide);
			NbSupp++;
			} 
   }
 /*pour quitte la fonction : 
if (Tete==NULL) return NbSupp;
else {
	Courant=Tete->suivant;
	Precedent=Tete;
}

while( Courant !=NULL) 
{
/*pour trouver la chaine : 
	if(strcmp(Nom,Courant->cNom)==0)
    {
		printf("Contact Prenom: %s, Nom: %s, Courriel: %s trouver. Voulez vous le supprimer? Taper o si oui ou  sinon taper autre touche\n", Courant->cPrenom,Courant->cNom,Courant->cCourriel);
		scanf("%s",cchaine);
		cc=cchaine[0];
/*pour confirmer la Suppression : 
		if(cc=='o' || cc=='O')
        { 
			Vide=Courant;
			Courant=Courant->suivant;
			Precedent->suivant=Courant;
/* pour la Liberation de l'espace occupé : 
			free(Vide); 
			NbSupp++;
			}else{ 
			Precedent=Courant;
			Courant=Courant->suivant;
			}
		}else{
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
/* pour trouvé la chaine :
	if(strcmp(Nom,Courant->cNom)==0)
    { 
		printf("Contact Prenom: %s, Nom: %s, Courriel: %s trouvé. Voulez vous le modifier? Taper o si oui ou  sinon autre touche\n", Courant->cPrenom,Courant->cNom,Courant->cCourriel);
		scanf("%s",cchaine);
		cc=cchaine[0];
/*pour la confirmation de la Modification : 
		if(cc=='o' || cc=='O')
        { 
/*le début de la modification : 

			char cTemp [255] ;
			
			printf ( " Entrez le nouveau Nom\n",Courant->cNom ) ;
			scanf ( "%s" , cTemp ) ;
	
			strcpy (Courant->cNom , cTemp) ;
	
			printf ( " Entrez le nouveau Prenom\n",Courant->cPrenom ) ;
			scanf ( "%s" , cTemp ) ;
	
			strcpy (Courant->cPrenom , cTemp) ;
	
			printf ( " Entrez la nouvelle adresse courriel \n",Courant->cCourriel ) ;
			scanf ( "%s" , cTemp ) ;
	
			strcpy (Courant->cCourriel , cTemp) ;

/*la Fin de la modification : 
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
		printf ( "###            le carnet d'adresse           ###\n" ) ;
		printf ("###############################################\n") ;
		printf ( "1 - l'Ajout  d'un nouveau contact\n" ) ;
		printf ( "2 - l'Affichage de tous les contacts du carnet d'addresses\n") ;
		printf ( "3 - la Modiffication d'un contact\n" ) ;
		printf ( "4 - la Suppression d'un contact\n" ) ;
		printf ( "5 - l'Enregistrement du carnet d'addresses actuel dans un fichier\n") ;
		printf ( "6 - le Chargement d'un carnet d'addresses à  partir d'un fichier\n") ;
		printf ( "7 - la Liberation de l'espace mémoire.\n") ;
		printf ( "8 - Quitter\n") ;
        scanf("%s",choixx);
			
		choix=choixx[0];
		if(strlen(choixx)>1) choix='h';

		switch (choix)
		{
/* la creation d'un nouveau contact : 

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
			if (r==1) printf("Le contact %s  %s ( E-mail: %s ) a été ajoouté \n", C->cPrenom,C->cNom,C->cCourriel);		

			break ;
		} 
/* pour l'affichage des  contacts :	

		case '2' :
			{
			printf ("#########################################################################\n") ;
			printf ("##########      l'Affichage du carnet d'addresses   	      ###########\n") ;
			printf ("#########################################################################\n") ;
			AfficherContacts(); 	
			 break ;
		}		

/* pour la modification d'un contact : 
		
		case '3' :
			{
			if(Tete!=NULL)
			{
				printf ("donner le Nom du contact a modifie\n") ;
				scanf ("%s", Nom) ; 
				int r=ModifierContact(Nom);
				if(r==0) 
                printf("le contact est introuvable dans le carnet d'addresse\n");
				else 
                printf("le Nombre de contacts a été modifie: %d",r);
			}else{
				printf("Le carnet d'addresses est vide!!");
			}
			break ;
		} 
/* la Suppression d'un contact : 
		
		case '4' :
			{
			if(Tete!=NULL)
			{
				printf ("donner le Nom du contact a supprimé\n") ;
				scanf ("%s", Nom) ; 
				int r=SupprimerContact(Nom);
				if(r==0) 
                printf("le contact est introuvable dans le carnet d'addresse\n");
				else 
                printf("Nombre de contacts a été supprimés: %d",r);
			}else{
				printf("Le carnet d'addresses est vide!!");
			}
			break ;
		} 
/*la Sauvegarde du carnet de contacts dans un fichier : 
		case '5' :
			{
   			SauvegarderListe();
			break ;	
		} 
/*le Chargement du carnet de contacts à  partir d'un fichier: 
		case '6' :
			{
  /* pour la Liberation de l'espace memoire occupé par l'ancienne liste on fait :
   			ViderListe(); 
			ChargerListe();
			break ;	
		} 
/*le Chargement du carnet de contacts à  partir d'un fichier :
		case '7' :
			{ 
/*la Liberation de l'espace memoire occupé par l'ancienne liste ce fait comme suite :
     			ViderListe(); 
			break ;	
		} 
/*pour Quitter le programme : 
       		case '8' :
			{ 
			printf ("on quitte le programme\n") ;
			printf ("la Libération de l'espace mémoire\n") ;
			ViderListe();
			break ;	
		} 

		default :
			{
			printf( "Ce choix ne figure pas dans le menu. Veuillez taper un chiffre entre 1 et %d \n", quitter);
		}
		}
		
	} while( choix != quitter );
		
return 0 ;
}

pour la compilation et l'exicution de ce programme j'ai utilisé : 
      gcc -lm -o TP12-tdjebbari TP12-tdjebbari.c -Wall -ansi
pour l'Ã©xicution de ce programme : 
./TP12-tdjebbari

	
