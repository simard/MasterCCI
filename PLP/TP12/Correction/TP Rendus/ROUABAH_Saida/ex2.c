#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct Contact{

  char* Nom;
  char* Prenom;
  char*Mail;
  struct Contact *pCont_suiv;

}cont;

typedef struct Liste{

  int n;

  cont * pCont;

}liste;

 liste * pListe=NULL;
 cont * pCont=NULL;
 
char nom_fichier[10];


/*************** fonction creer liste***************************/
 
liste * creerliste()
{
  liste * l1=NULL;

  l1=(liste *) malloc(sizeof(liste));
  l1->n=0;
  l1->pCont=NULL;

   return l1;
}


/*************** fonction creer contacte***************************/

 cont* creer_contact(liste * l1,char* nom,char* prenom,char* admail)
{

  cont *c1=NULL;

  c1=(cont *) malloc(sizeof(cont));

  c1->Nom=(char *)malloc(sizeof(strlen(nom)+1));
  c1->Prenom=(char *)malloc(sizeof(strlen(prenom)+1));
  c1->Mail=(char *)malloc(sizeof(strln(admail)+1));

  c1->pCont_suiv=l1->pCont;

  c1->Nom =nom;
  c1->Prenom =prenom;
  c1->Mail =admail;

  l1->pCont=c1;
  l1->n++;
 

  return c1;

}

/*************** fonction afficher contact***************************/

void afficherContact(cont * c1)
{
   
 printf("Nom: %s\n prenom: %s\n mail:%s\n",c1->Nom, c1->Prenom,c1->Mail);

  return;
}
 

/*************** fonction afficher liste***************************/

void afficherList(liste * l1)
{

  cont *tmp=l1->pCont;
 
while(tmp!=NULL)

/*  for(i=0;i<(l1->n);i++ )*/
    {
      afficherContact(tmp);
     tmp=tmp->pCont_suiv;
    }
  return;
}

/*************** fonction supprimer contact***************************/

void suprimContact(liste * l1, char * nom , char * prenom)

{

	cont *contact=l1->pCont;
	cont *prec=NULL;
	int i=0;
	int test=0;
	for(i=0;i<(l1->n);i++ )

	{
		if(((strcmp(contact->Nom,nom)==0)&&(strcmp(contact->Prenom,prenom)==0)))

		{
			printf("Etes vous sure de voloir supprimer:<< %s %s >>? Taper :1 pour confirmer 0: pour annuler\n",contact->Nom,contact->Prenom);
			scanf("%d",&test);


			if(test==1)
			{

				if(prec==NULL)
				{
					l1->pCont=contact->pCont_suiv;
					(l1->n)--;

				}
				else
				{
					prec->pCont_suiv=contact->pCont_suiv;
					(l1->n)--;

				}
			}
		}

		prec=contact;
		contact=contact->pCont_suiv;

	}
	return ;
}

/*************** fonction comparaison contact ***************************/

void comparaison_Contact(liste * l1, char * nom , char * prenom)
{

   int test=0;
   cont *contact=l1->pCont;


  while(contact!=NULL)
   {


	if(((strcmp(contact->Nom,nom)==0)&&(strcmp(contact->Prenom,prenom)==0)))

	{

	test=1;
	afficherContact(contact);

	}
	contact=contact->pCont_suiv;
	}

	if(test==0)
	{
	printf("ce contact n'existe pas \n");
	}
return;
}



/*************** fonction modifier contact***************************/

void modifier_Contact(liste * l1, char * nom )

{

    cont *contact=l1->pCont;
   
    int i=0;
    int test=0;
    char choi='\0';
    char nom2[255];
    char prenom2[255];
    char mail2[255];

    for(i=0;i<(l1->n);i++ )

   {
	if(strcmp(contact->Nom,nom)==0)

     {
	printf("Etes vous sure de voloir modifier:<< %s %s >>? Taper :1 pour confirmer 0: pour annul\n",contact->Nom,contact->Prenom);
	scanf("%d",&test);

    
     if(test==1)
     {
      getchar();
    printf("a:modifier nom , b:modifier prenom ,c:modifier mail\n");
      
      scanf("%c",&choi);

 	getchar();

	switch(choi)
	{
 	case 'a':
	printf("donner le nouveau nom\n");
	scanf("%s",nom2);
	contact->Nom =nom2;
  
	break;

	case 'b':
	printf("donner le nouveau prenom\n");
	scanf("%s",prenom2);
	contact->Prenom =prenom2;
	break;

	case 'c':
	printf("donner le nouveau mail\n");
	scanf("%s",mail2);
	contact->Mail =mail2;

	break;

	default :
	printf("choix incorrect");
	break;

	}
      }
    }

   contact=contact->pCont_suiv;

    }
return;
}



/**************** fonction enregistrer dans fichier ****************************/



void enregistrer(cont * s)

{
  printf("donner le nom du fichier pour enregistrer le contact\n");
  scanf("%s",nom_fichier);

  FILE * pFichier=NULL;
  pFichier= fopen(nom_fichier,"a");
  fprintf(pFichier,"%s\n%s\n%s\n\n",s->Nom,s->Prenom,s->Mail);
  fclose(pFichier);

return;

}

/**************** fonction charger un fichier ****************************/

char*  charger_fichier()

{

  char * contact=NULL ;
  
  printf("donner le nom du fichier a charger\n");
  scanf("%s",nom_fichier);

  FILE * pFichier=NULL;

  pFichier= fopen(nom_fichier,"r");

  fscanf(pFichier,"%s\n",contact);
  fclose(pFichier);

return contact;
}
	

/**************** fonction liberer Contact ****************************/

void liberer_contact(cont * c)
{
if(c->pCont_suiv!=NULL)

 liberer_contact(c->pCont_suiv);

 free(c->Nom);
 free(c->Prenom);
 free(c->Mail);
 free(c);

return;
}

/**************** fonction liberer Liste ****************************/

void liberer_liste(liste * l)
{

 if(l->n !=0 && l->pCont !=NULL )
 {

 liberer_contact(l->pCont );

 }
free(l);

return;
}  

/***************  main  ***************************/

  int main(int argc, char** argv)

  {
   
    char nom[256];
    char prenom[256];
    char admail[256]; 
    char cChoix='\0';
    char * carnet=NULL;
 
   pListe=creerliste();
   cont * cont_creer=NULL;
   
    
while(cChoix !='f')

{

printf("entrer votre choix:\n  a: afficher le carnet \n  b: ajouter un contact\n  c: supprimer un contact\n  d: afficher un contact\n  e: modifier un contact\n  f: fermer le carnet\n");

    scanf("%c",&cChoix);


    switch(cChoix)
      {

      case 'a':
    carnet=charger_fichier(); 
    printf("%s",carnet); 
    
	break;

      case'b':

	printf("Entrer les coordoner de nouveau contact:\n");
        printf("donner un nom : ");
	scanf("%s",nom);
	printf("donner le prenom : ");
	scanf("%s",prenom);
	printf("donner le mail : ");
	scanf("%s",admail);

        cont_creer=creer_contact(pListe,nom,prenom,admail);
        enregistrer(cont_creer);
        afficherList(pListe);

        printf("******************************************\n");
        
	break;

      case 'c':
	printf("suprimer contact\n");
        printf("donner un nom à suprimer: ");
	scanf("%s",nom);
	printf("donner le prenom a supremer: ");
	scanf("%s",prenom);

        suprimContact(pListe, nom ,prenom);
        afficherList(pListe);

	break;

       case 'd':
    	
        printf("afficher un contact\n");
        printf("donner le nom du contact: ");
	scanf("%s",nom);
	printf("donner le prenom  du contact: ");
	scanf("%s",prenom);
        comparaison_Contact(pListe,nom ,prenom);


       break; 
       
       case 'e':
    	
      
        printf("donner le nom du contact à modifier: ");
	scanf("%s",nom);
	modifier_Contact(pListe,nom );
         afficherList(pListe);

       break; 




       case 'f':
       return 1;

        break;

      default:
	printf("Choix incorrect\n");

	break;

      }
   getchar();

   }
 
    printf("\n");


    return 0;
}


