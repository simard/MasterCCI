/* 	Yacine TAIBI
	M2 CCI _Mini-projet 3 : RÈalisation d'un Carnet d'adresses.
	
*/

# include<stdio.h>
# include<stdlib.h>
# include<string.h>



typedef struct scontact
{
	char  *cNom;
	char  *cPrenom;
	char  *cMail;
	struct scontact * ptSuivant;
} Contact;

int Nb_contacts = 0;
Contact *pt_Temp = NULL;
Contact *pDebut = NULL;
FILE * pt_Carnet =NULL;



// FONCTION : Creation d'un nouveau contact a partir d'une liste vide ou deja existante
//La Fonction renvoie un pointeur et ne prend aucun argument.

Contact * Creer_contact (void)
{
	Contact *pt_New_contact =NULL;
	char tab_Temp [256];
	
	
	
	pt_New_contact = (Contact *) malloc( sizeof( Contact ));
	
	printf("Entrer le nom : ");
	scanf("%s", tab_Temp);
	pt_New_contact->cNom = (char *) malloc ((strlen(tab_Temp)+1) * sizeof(char));
	strcpy(pt_New_contact->cNom , tab_Temp);
	
	printf("Entrer le prenom : ");
	scanf("%s", tab_Temp);
	pt_New_contact->cPrenom = (char *) malloc ((strlen(tab_Temp)+1) * sizeof(char));
	strcpy(pt_New_contact->cPrenom , tab_Temp);
	
	printf("Entrer l'adresse Mail : ");
	scanf("%s", tab_Temp);
	pt_New_contact->cMail = (char *) malloc ((strlen(tab_Temp)+1) * sizeof(char));
	strcpy(pt_New_contact->cMail , tab_Temp);
	
	if (Nb_contacts==0)
	{
		pDebut =pt_New_contact;
		
	}
	else
	{
		(*pt_Temp).ptSuivant = pt_New_contact;
	}
	
	(*pt_New_contact).ptSuivant =NULL;
	pt_Temp = pt_New_contact;
	Nb_contacts =Nb_contacts+1;
	
	return pt_Temp;
	
	free(pt_New_contact->cMail);
	free(pt_New_contact->cNom);
	free(pt_New_contact->cPrenom);
}

// FONCTION: Free  Memoire qui consiste a liberer la mÈmoire elle utilise une variable de type pointeur sur contact
// elle permet de balayer toute la liste pour dÈsalloer la memoire.

void free_Memoire (void)
{
	Contact * pt_free_maillon;
	pt_free_maillon = pDebut;
	
	while (pt_free_maillon != NULL)
	{
		pDebut=pt_free_maillon->ptSuivant;
		free (pt_free_maillon->cNom);
		free (pt_free_maillon->cPrenom);
		free (pt_free_maillon->cMail);
		free (pt_free_maillon);
		pt_free_maillon = pDebut;
	}

}


// FONCTION: Afficher tous les contacts du Carnet d'adresse.
//Cette fonction consiste a passer par  tous les maillons de la chaine  et d'afficher leur contenu.
void Afficher_contacts (Contact*a)
{
	Contact * pt_Temp;
	if (pDebut ==NULL)
	{
		printf("Le Carnet d'adresses est vide! Veuillez creer des contacts\n");
	}
	else
	{
		pt_Temp = pDebut;
		while(pt_Temp!=NULL)
		{
			printf("%s  %s  %s\n", pt_Temp->cNom, pt_Temp->cPrenom, pt_Temp->cMail);
			pt_Temp=pt_Temp->ptSuivant;
		}
		printf("le carnet d adresse contient :%d\n",Nb_contacts);
	}
	
}


//FONCTION: Enregistrement du Carnet permet l'enregistrement d'un carnet d'adresse dans un fichier carnet d'adresse.
 
FILE* EnregistrerCarnet (void)
{
	Contact * pt_courant;
	
	pt_Carnet = fopen ( "Carnet d_adresses.txt", "a+" );
	if (pDebut ==NULL)
	{
		printf("Carnet d_adresses vide! il y a aucun contact\n");
	}
	else
	{
		pt_courant = pDebut;
		while(pt_courant!=NULL)
		{
			fprintf(pt_Carnet, "%s\n%s\n%s\n\n", pt_courant->cNom, pt_courant->cPrenom, pt_courant->cMail);
			//fputs ("255", fichier);
			pt_courant=pt_courant->ptSuivant;
		}
	}
	return pt_Carnet;
}

//FONCTION: Charger carnet permet le chargement du carnet d'adresse

void ChargerCarnet ()
{
	int Nb_contacts = 0;
	int z;
	char tab_Temp [256];
	Contact *pt_New =NULL;
	
	pt_Carnet = fopen ( "Carnet d adresses.txt", "a+" );
	z= fscanf(pt_Carnet, "%s\n", tab_Temp);
	
	while (z != EOF)
	{
		pt_New = (Contact *) malloc( sizeof( Contact ));
		
		pt_New->cNom = (char *) malloc ((strlen(tab_Temp)+1) * sizeof(char));
		strcpy(pt_New->cNom , tab_Temp);
		
		fscanf(pt_Carnet, "%s\n", tab_Temp);
		pt_New->cPrenom = (char *) malloc ((strlen(tab_Temp)+1) * sizeof(char));
		strcpy(pt_New->cPrenom , tab_Temp);
		
		fscanf(pt_Carnet, "%s\n", tab_Temp);
		pt_New->cMail = (char *) malloc ((strlen(tab_Temp)+1) * sizeof(char));
		strcpy(pt_New->cMail , tab_Temp);
		
		if(Nb_contacts==0)
		{
			pDebut = pt_New;
		}
		else
		{
			pt_Temp->ptSuivant = pt_New;
		}
		
		pt_New->ptSuivant =NULL;
		pt_Temp = pt_New;
		Nb_contacts= Nb_contacts+1;
		z=fscanf(pt_Carnet, "\n%s\n", tab_Temp);
		
	}
	
}
//FONCTION: Supprimer contact

void supprimer_contact(void)

{
	char tab_Temp [256];
	Contact *pt_elt_supprimer= NULL;
	Contact *pt_courant= NULL;
	
	printf("Ecrire le nom du contact a supprimer : ");
	scanf("%s", tab_Temp);
	pDebut=pt_Temp;
	pt_courant=pDebut;
	while ( pt_courant != NULL )
	{
		if ( strcmp(pt_courant->cNom, tab_Temp ) ==0)
		{	
			if (pt_courant==pDebut)
			
			{	pt_elt_supprimer=pDebut;
				pDebut=pt_courant->ptSuivant;
				Nb_contacts=Nb_contacts-1;
			}
			
			
		}	
		
		else if (strcmp(pt_courant->ptSuivant->cNom, tab_Temp ) ==0)
			
		{	pt_elt_supprimer=pt_courant->ptSuivant;
			pt_courant->ptSuivant=pt_courant->ptSuivant->ptSuivant;
			Nb_contacts=Nb_contacts-1;
		}
			
		
		else if (pt_courant==NULL)
				
		{	printf("ce nom n'existe pas dans le carnet d'adresse\n");
				
		}	
			
		pt_courant=pt_courant->ptSuivant;	
		
	}
	
			
			free (pt_elt_supprimer->cNom);
			free (pt_elt_supprimer->cPrenom);
			free (pt_elt_supprimer->cMail);
			free (pt_elt_supprimer);
	
}



int main ( int argc, char ** argv )
{
	char choix = '\0';
	
	

	while ( choix != '6' )
	{	
		

			//Afiichage du Menu du programme avec les diff√©rentes options propos√©s 
			
			printf("### Carnet d'adresses ###\n1- Entrer un nouveau contact\n2- Affichage des contacts\n3- Supprimer un contact\n4- Charger un carnet d adresses\n5- Enregistrer le carnet d adresses\n6- Quitter le programme\n");
			
			// Selecion des Choix possible propos√©es dans le menu 
			printf( "Veuillez selectionnez votre choix : ");
			
			scanf( "%c", &choix );
			
	
		switch (choix)
		{
			/*Entrer d'un nouveau contact*/
			case '1' :
				
				
				pt_Temp=Creer_contact();
				
				break;
			
			/*Affichage des contacts*/
			case '2' :
				
				
				Afficher_contacts(pt_Temp);
				
				break;
			
			/*Supprimer un contact*/
			
			case '3' :
				supprimer_contact();
				break;
			/*charger un carnet d'adresse*/
			case '4' :
				ChargerCarnet ();
				break;
			/*Enregistrer le carnet d'adresse*/
			case '5' :
				pt_Carnet=EnregistrerCarnet ();
				break;
			case '6':
				fclose(pt_Carnet);
				free_Memoire ();
				break;
			default :
				printf( "Choix incorrect \n" );
				break;
		}
	}
	return 0;
}


//http://www.commentcamarche.net/forum/affich-924139-lire-et-ecrire-dans-un-fichier-en-c.
//http://routes-linux.scooba.org/ecrire_dans_un_fichier.php.
//http://forum.ubuntu-fr.org/viewtopic.php?id=168142.
