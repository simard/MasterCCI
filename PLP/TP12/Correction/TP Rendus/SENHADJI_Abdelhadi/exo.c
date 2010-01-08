Nom : SENHADJI 
Prenom : ABDELHADI 




 
/*  Exo1: structure d'adresse  */
 
#define max_nom 30
struct adresse
    {
     char nom [max_nom];
     char prn [max_nom];
     char email [max_nom];
    }; 
    struct adresse var_adresse[100]; 

/*  Exo2: menue d'affichage   */
	
void main()
{
    int ChoixMenu;
      
     do
	{ printf("Votre choix: ");
	  scanf("%d",&ChoixMenu);
	} while ((ChoixMenu != 1) && (ChoixMenu != 2) && (ChoixMenu != 3) && (ChoixMenu != 4) && (ChoixMenu != 5) &&(ChoixMenu !=6) && (CoixMenu !=7));
	switch (ChoixMenu)
	{
	case 1:	nouveau_contact (Liste * liste, char *donnee );  /*creation d'un nouveau contact*/ 
	break;
	
	case 2:	Liberer_liste (Liste * liste();                  /*libereration de l'espace memoire*/
	break;
	
	case 3:	affiche (Liste * liste)();                       /*affichage de tous les contacts*/ 
	break;
	
	case 4:	enregestrement ();                               /*enregistrement des: nom, prenom et email dans un fichier*/ 
	break;
	
	case 5: charger () ;                                     /*chargement d'un carnet d'adresse*/ 
    break;
    
	case 6 : supprimer (int j ) ;                            /*suppression d'un contact*/ 
    break;
    
	case 7: modifier() ;                                     /*modification d'un contact*/ 
    break;
    }
}
/*  Exo 3: création d'un contact   */
/*  initialisation de notre liste chainée   */
  
void initialisation (Liste *liste)
{
	liste->debut = NULL;
	liste->fin = NULL;
	taille = 0;
}
    int nouveau_contact (Liste * liste, char *donnee)     /*la fonction "nouveau_contact renvoie -1 en cas d'échec sinon elle renvoie 0 */
{
    Element *nouveau_element;
    
	if  ((nouveau_element = (Element *) malloc (sizeof (Element))) == NULL)
    return -1;
    
	if ((nouveau_element->donnee = (char *) malloc (50 * sizeof (char))) == NULL)
    return -1;
    
	strcpy (nouveau_element->donnee, donnee);
    
	printf ("entrer votre nom %s:" nom );
    scanf ("%s ", &nom );
    nouveau_element= nom ;
    nouveau_element->suivant = NULL;
    liste->debut = nouveau_element;
    liste->fin = nouveau_element;
    liste->taille++;
  
    printf ("entrer votre prenom %s: " prenom );
    scanf (" %s ", &prenom );
    nouveau_element=prenom ;
    liste->debut = nouveau_element;
    liste->fin = nouveau_element;
    liste->taille++;
  
    printf ("entrer votre adresse couriel %s: " email);
    scanf ("%s ",&email );
    liste->debut = nouveau_element;
    liste->fin = nouveau_element;
    liste->taille++;
    return 0;
}

/*  Exo 4:  Liberer l'espace mémoire  */
/*  suppression au début de la liste */

int Liberer_liste (Liste * liste)
{
    if (liste->taille == 0)
    return -1;
    Element *supp_element;
    supp_element = liste->debut;
    liste->debut = liste->debut->suivant;
  
    if (liste->taille == 1)
    liste->fin = NULL;
    free (supp_element->donnee);
    free (supp_element);
    liste->taille--;
    return 0;
}

/*  Exo 5:  Afficher les contacts  */

void affiche (Liste * liste)
{
    Element *courant;
    courant = liste->debut;
    
	while (courant != NULL)
	{
      printf ("%p - %s\n", courant, courant->donnee);
      courant = courant->suivant;
    }
}
  
/*  Exo 6 : Enregistrer le carnet d'adresse dans un fichier   */ 

void enregestrement ()
{
    char nom [], prenom[],email[], espace[] 
    int Nbcontacts ;
    printf ("entrer le nombre de contact %d : " Nbcontacts )
    scanf (" %d "&Nbcontacts  );

    printf (" Entrer le nom du fichier %s : ", Nomfichier ) ;
    scanf ("s" , &Nomfichier  );
    Fille* Nomfichier ;    /* déclaration  d'un fichier */  
/* la fonction "FPUTS" ecrit une chaine dans un fichier et retourne une valeur positive ou, EOF s'il ya eu une erreur */
    while (Nbcontacts !=0  )  
    {
    printf (" Entrer le nom %s : ", nom );
    scanf (" s" ,&nom );
    int fputs (const char* nom, fille* stream )
    
	printf (" Entrer le prenom %s : ", prenom );
    scanf (" s" ,&prenom );
    int fputs (const char* prenom, fille* stream )
    
	printf (" Entrer l'adresse couriel  %s : ", email );
    scanf (" s" ,&email );
    int fputs (const char* email, fille* stream )
    
	printf ("\n " );    
    }
}

/*  Exo 7 :  Chargement d'un carnet d'adresse  */

void charger ()
{	
    char FNom[20],FPrenom[20],FMail[10],	
    int RepAffichage ;
    printf (" entrer le nom de fichier  %s : ", Nomfichier  );
    scanf (" s " , &Nomfichier ) ;
    fichier = fopen(Nomfichier,"r");   /*lecture de fichier*/ 
	
    while (!feof(fichier))             /*tester la fin du fichier  */
	{	
	fscanf(fichier," %s %s %s \n",&FNom,&FPrenom,&FMail);
	}
	fichier = fopen(Nomfichier,"r");
	printf("\n\n\n");
	RepAffichage = 0;
	do
	{ 
	printf("\nVoulez-vous visualiser toutes les fiches (0.Non - 1.Oui) ?");
	scanf("%d",&RepAffichage);
	} 
	while ((RepAffichage != 0) && (RepAffichage = 1));
	{
	switch (RepAffichage)
	{	
	    case 1:
	    {
	    while (!feof(fichier))   /*test de la fin du fichier*/ 
		{
		fscanf(fichier,"%d %s %s %s  \n",&FNumEnreg,&FNom,&FPrenom,&FMail);
		printf("\n");	
		printf("Nø d'enregistrement : %d\n",FNumEnreg);
		printf("Nom : %s\n",FNom);
		printf("Prenom : %s\n",FPrenom);
		printf("Mail : %s\n",FMail);
		system("pause");
		}
		fclose(fichier);
		}
		break;
	}
	}
}                                                       
/*  Exo 8 :  supprission  d'un contact */  

void supprimer (int j )
{
    char Nom [],
    int i;
    printf ("entrer le nombre de contacts dans ce carnet  %d :", Nbdecontacts ) .
    scanf ("%d ",&Nbdecontacts  );
    printf(" Entrer le Nom que vous voulez le supprimer %s :" );
    scanf(" %s\n",&Nom  );
    
	do
	{ 
	printf("\nVoulez-vous vraiment supprimer ce contact (0.Non - 1.Oui) ?");
	scanf("%d",&choix);
	} 
	while ((choix != 0) && (choix = 1));
	{
	switch (choix)
	{	
	    case 1: i=j;
        while ( i < Nbdecontacts  )
        {
        if (strcmp (Nom, var_adresse[i].nom) == NULL )
	    {
	    gotoxy (strlen ("Nom: ") + 8, 38);  /*la fonction "GOTOXY" pour effacer  le nom*/ 
	    printf ("Appyer sur une touche pour continuer...");
	    getch();  
		}
        }
        i++
    }
    }
}
/*la fonction  "Modification de contact " */  

void Modifier ()
{
    int i, j, k ;
    printf ("entrer le nombre de contacts dans ce carnet  %d :" Nbdecontacts );
    scanf ("%d ",&Nbdecontacts  );
    
	do
	{
    printf(" taper 1=pour modifier le nom  2=pour modifier le prenom ou 3=pour modifier email  %d : );
    scanf(" %d\n",&choix  );
    } 
	while ((choix = 1) && (choix = 2) && (choix = 3));
	{
	switch (choix)
	{	
		case 1: printf ("Appuyer sur une touche pour modifier...ESC pour annuler");
        if ((c = getch()) != 27 )
        {
        while ( i < Nbdecontacts  )
        {
        if (strcmp (Nom, var_adresse[i].nom) == NULL )
	    {
	    gotoxy (strlen ("Nom: ") + 8, 38);    /*la fonction "GOTOXY" pour effacer le nom*/ 
	    printf ("Appyer sur une touche pour continuer...");
	    getch();  
		}
        printf("taper le nouveau nom : " );
        gets (var_adresse[i].nom);           
        }
        }
        i++
        case 2 : printf ("Appuyer sur une touche pour modifier...ESC pour annuler");
        if ((c = getch()) != 27 )
        {
        while ( j < Nbdecontacts  )
        {
        if (strcmp (Prenom, var_adresse[j].prenom) == NULL )
	    {
	    gotoxy (strlen ("Prenom: ") + 8, 38);   /*la fonction "GOTOXY" pour effacer le prenom*/ 
	    printf ("Appyer sur une touche pour continuer...");
	    getch();  
		}
        printf("taper le nouveau prenom %s: " );
        gets (var_adresse[j].prenom); 
        }
        }
        j++
        case 3 :
        printf ("Appuyer sur une touche pour modifier...ESC pour annuler");
        if ((c = getch()) != 27 )
        {
        while ( k < Nbdecontacts  )
        {
        if (strcmp (Email, var_adresse[i].email) == NULL )
	    {
	    gotoxy (strlen ("Email: ") + 8, 38);   /*la fonction "GOTOXY" pour effacer  le nom*/ 
	    printf ("Appyer sur une touche pour continuer...");
	    getch();  
		}
        printf("taper le nouveau email %s : " );
        gets (var_adresse[k].email);    
        }
        }
        k++
        
    }
    }
}
