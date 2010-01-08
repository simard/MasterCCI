# include <stdio.h>
# include <math.h>
# include <string.h>
# include <stdlib.h>

/*
Nom :Payet
prénom :Alexandre
Master CCI*/

/*structure permettant de geré une file (ici on parlera de pile plutot ) de contact*/

typedef struct sPers {
       char* nom;
       char* pre;
       char* mail;
       struct sPers* next;
       } pers ;

/*Fonction permettant de créer une structure contact pointant sur l'element précedent et qui renvois l'adresse memoire de la structure crée */

pers* creat(pers* apres)
      {
// le pointeur et les contact sont generé dans la fonction et non pas dans le main
		pers * bob =NULL;
		bob = (pers *) malloc (sizeof(pers));
	      	int size_s = 0;
		char temp[256];

		printf("\n Nom:" );
		scanf ("%s",  temp);
		
		size_s = strlen (temp)+1;
		
		bob->nom = (char *) malloc(size_s*sizeof (char) );
		strcpy (bob->nom,temp);
	     
		printf("\n Prénom:");
		scanf ("%s",  temp);
		size_s = strlen (temp)+1;
		bob->pre = (char *) malloc(size_s*sizeof (char) );
		strcpy (bob->pre,temp);
	     
		printf("\n Mail:");
		scanf ("%s",  temp);
		size_s = strlen (temp)+1;
		bob->mail = (char *) malloc(size_s * sizeof (char) );
		strcpy (bob->mail,temp);
	       		
		(bob->next) = apres;
		
		return(bob);

      }

/* fonction permettant de retirer d'une liste une personne */
 
 void kill_pers ( pers* tete )
{
	char temp [256];
	printf("\n nom de personne à retirer:");
	scanf("%s",temp);
	pers* P_element = NULL;
	int c=1;
		
		while (  tete ->next -> next != NULL )
		{
// cas ou la personne est dans la liste - on garde en memoire l'element precedent grace a un tete ->next -> nom					
			if (strcmp( ( tete ->next)->nom,temp) == 0)
			{// verifie si c'est a chaque fois la bonne personne
				printf ("C'est la bonne personne ?  %s %s oui(0) ou non(1) \n",tete->next->nom,tete->next->pre);
				scanf ("%d",&c);
				if (c == 0)
				{
					P_element = tete -> next -> next;
					
					free ( tete -> next ->nom);
					free ( tete -> next ->pre);
					free ( tete -> next ->mail);
					free ( tete -> next) ;
					
					tete -> next = P_element;
					printf("Contact effacé\n");return;
				}
				
				tete = tete ->next;
			}
// cas où on doit traiter le premier de la liste 
			if (strcmp( tete->nom,temp) == 0)
			{// verifie si c'est a chaque fois la bonne personne
				printf ("C'est la bonne personne ?  %s %s oui(0) ou non(1) \n",tete->nom,tete->pre);
				scanf ("%d",&c);
				if (c == 0)
				{
					P_element = tete -> next;
					
					free ( tete ->nom);
					free ( tete ->pre);
					free ( tete ->mail);
					free ( tete ) ;
					
					tete = P_element;
					printf("Contact effacé\n");return;
				}
				
				tete = tete ->next;
			}
		
		}
// pour le dernier element
		if (strcmp(tete -> next-> nom,temp == 0) )
			{// verifie si c'est a chaque fois la bonne personne
				printf ("C'est la bonne personne ?  %s %s oui(0) ou non(1) \n",tete->next->nom,tete->next->pre);
				scanf ("%d",&c);
				if (c == 0)
				{
					P_element = tete -> next;
					
					free ( tete -> next ->nom);
					free ( tete -> next ->pre);
					free ( tete -> next ->mail);
					free ( tete -> next) ;
					
					tete -> next = P_element;
					printf("Contact effacé\n");return;
				}
				
				tete = tete ->next;
			}
		printf ("Pas de contact ayant ce nom");
}
//fonction permettant de liberer la memoire à la fin du programme
void kill_all (pers* tete)
	{
		pers* p_element = NULL;
		
		while (tete->next !=NULL)
		{
			p_element = tete -> next;
			
			free ( tete ->nom);
			free ( tete ->pre);
			free ( tete ->mail);
			free ( tete ) ;
			
			tete = p_element;
		}
			
			free ( tete ->nom);
			free ( tete ->pre);
			free ( tete ->mail);
			free ( tete ) ;
	}
	
// fonction permettant d'afficher a l'ecran toute les contact
void print_all (pers* tete)
{
	while (tete->next !=NULL)
	{
		printf (" nom: %s \tprénom: %s \tMail : %s \n",tete ->nom,tete ->pre,tete ->mail);
		tete = tete ->next;
	}
	printf (" nom: %s \tprénom: %s \tMail : %s \n",tete ->nom,tete ->pre,tete ->mail);
}
// fonction imprimant dans un fichier toute les adresse et les contact
void imprime ( pers* tete )
{

	FILE* pFichier =NULL;
	char name[256];
	
	printf ("Nom du fichier ? ");
	scanf ("%s",name);

	pFichier = fopen (name,"w");
	
	while ( tete -> next !=NULL)
	{
		
		fprintf ( pFichier , " Nom: %s \t Prénom : %s \t mail : %s\n" , tete->nom,tete->pre,tete->mail );
		tete = tete -> next;
	}
	fprintf ( pFichier , " Nom: %s \t Prénom : %s \t mail : %s\n" , tete->nom,tete->pre,tete->mail );
	fclose (pFichier);
	
}
// fonction permettant de lire un fichier enregister (non fonctionnelle)

void op_file ( )
{
	FILE* pFichier =NULL;
	char name[256];
	char a[256];
	char b[256];
	char c[256];
	char d[256];
	int i =0; 
	
	printf("Nom du fichier ?");
	scanf("%s",name);
	
	pFichier = fopen (name, "a");

// cette partie n'est pascomplète en effet je n'arrive pas à accedé comme je le souhaite au differente partie de pFichier
	
	fscanf ( pFichier , " Nom: %s \t Prénom : %s \t mail : %s\n" , a , b , c );
	printf ( "%c - %c - %c \n",a,b,c);
	
	
}
// fonction permettant de modifier une personne en memoire
void mod(pers* tete)
{
	char temp [256];
	int c=0;
	printf("Nom de personne à modifier:\n");// necessite le nom de la personne 
	scanf("%s",temp);
	pers* P_element = NULL;
	int test =0;

	while (test !=1)
	{
		if (tete->next->next == NULL)
		{
// traite le dernier element de la liste
			if (strcmp( (tete ->next)->nom,temp) == 0)
			{
				P_element = (tete->next)->next;

				free ( tete -> next ->nom);
			     	free ( tete -> next ->pre);
			      	free ( tete -> next ->mail);
			      	free ( tete -> next) ;

				tete->next= creat(P_element);
			}
			test = 1;
		}
// traite le premier element
		if (strcmp (tete ->nom,temp) == 0)
		{// verifie si c'est a chaque fois c'est la bonne personne
			printf ("C'est la bonne personne ?  %s %s oui(0) ou non(1) \n",tete->nom,tete->pre);
			scanf ("%d",&c);
			if (c == 0)
			{
				P_element = (tete->next)->next;
	
				free ( tete ->nom);
				free ( tete ->pre);
				free ( tete ->mail);
				free ( tete ) ;
	
				tete= creat(P_element);
				test = 1;
			}
		}
// traite les element de la liste
		if (strcmp( (tete ->next)->nom,temp) == 0)
		{ // verifie si c'est a chaque fois c'est la bonne personne
			printf ("C'est la bonne personne ?  %s %s oui(0) ou non(1) \n",tete->next->nom,tete->next->pre);
			scanf ("%d",&c);
			if (c == 0)
			{
				P_element = (tete->next)->next;
	
				free ( tete -> next ->nom);
				free ( tete -> next ->pre);
				free ( tete -> next ->mail);
				free ( tete -> next) ;
	
				tete->next= creat(P_element);
				test = 1;
			}
		}
	}
}	

// fonction principale		
int main ()
{
    pers moi;
    pers* apres = NULL ;
    pers* tete = NULL;
	
	
    int i=0,c=0,fin=0;
   
	while (fin !=1)
	{	
		printf("Commande ?\n");
		printf("1-nouveau contact\n" );
		printf("2-Effacer contact\n");
		printf("3-Afficher carnet\n");
		printf("4-Enregister carnet\n");
		printf("5-Charger contact\n");
		printf("6-Modifier contact\n");
		printf("7-fin\n");
		scanf("%d",&c);

		switch (c)
		{
			case 1 :{tete = creat (apres);
				apres = tete ;break;}
			case 2 :{kill_pers(tete);break;}
			case 3 :{print_all(tete);break;}
			case 4 :{imprime(tete);break;}
			case 5 :{op_file ();break;}
			case 6 :{mod(tete);break;}
			case 7 :{fin=1;break;}
			
			default : printf("Commande incorrecte\n");
		}
	}
	
	kill_all(tete);
	return (0);
}
