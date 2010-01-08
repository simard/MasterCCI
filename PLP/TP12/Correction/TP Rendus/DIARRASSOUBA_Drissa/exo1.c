
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct contact{

  char * pcNom;
  char * pcPrenom;
  char * pcMail;
  struct contact *suivant;

} sCONTACT;



/*fonction ajout d'un contact*/

sCONTACT * AJOUT_CONTACT(sCONTACT * premier,sCONTACT *nouveau){
  
  nouveau->suivant = premier; /*nouveau -> prend l'adresse de premier*/

  premier = nouveau;  /*le nouveau devient maintenant le premier*/

  return premier  ;
}

/*creer un contact*/

sCONTACT * CREER_AJOUT_CONTACT(sCONTACT *premier){

  sCONTACT *psTemp;
  /*...........................*/
  /*sCONTACT *courant = premier;*/

  char cTempNom[256];
  char cTempPrenom[256];
  char cTempMail[256];

 

    printf("entrer :Nom\n");
    scanf("%s",cTempNom);
    printf("entrer :Prenom\n");
    scanf("%s",cTempPrenom);
    printf("entrer :Mail\n");
    scanf("%s",cTempMail);
 
  /*allocation memoire*/
 
  psTemp =(sCONTACT *) malloc(sizeof(sCONTACT));

  psTemp->pcNom = (char *) malloc ((strlen(cTempNom)+1)*sizeof(char)); 
  psTemp->pcPrenom = (char *) malloc ((strlen(cTempPrenom)+1)*sizeof(char));
  psTemp->pcMail = (char *) malloc ((strlen(cTempMail)+1)*sizeof(char)); 
  
 
  if(psTemp!=NULL){

   
    strcpy(psTemp->pcNom, cTempNom);
   
    strcpy(psTemp->pcPrenom, cTempPrenom);
   
    strcpy(psTemp->pcMail, cTempMail);

    psTemp->suivant = NULL;
  }

  else{

    printf("probleme de memoire\n");

  }

  /*  psTemp->suivant = NULL;*/

  /*fonction d'ajout du nouveau contact */
 
  if (premier != NULL )
    {
   psTemp =  AJOUT_CONTACT(premier, psTemp);
    }
  
  return psTemp;

}

/*fonction de libération de memoire*/


void LIBERE(sCONTACT * premier){


  sCONTACT * Temp = premier;

  while(Temp!=NULL){

    premier = Temp->suivant;
    free(Temp);
    Temp = premier;
  }
}


/* Affiche contact*/

void AFFICHE_CONTACT(sCONTACT * premier){

  int i=1;

  while(premier!=NULL){

    printf(" CONTACT :%d\n",i);
    printf("Nom :%s\n",premier->pcNom);
    printf("Prenom :%s\n",premier->pcPrenom);
    printf("Mail :%s\n",premier->pcMail);

    premier = premier->suivant; /*j'avance dans ma liste*/
    i=i+1;

  }

  return;
}

/*ecriture dans un fichier*/

void ECRITURE_FICHIER(sCONTACT * premier){

   char * Nom_Fichier;
   char temp[256];
   FILE * pFichier = NULL;

   printf("donner le nom du fichier\n");
   scanf("%s",temp);

/*allocation de la memoire pour la taile du nom du fichier*/
   Nom_Fichier = (char *) malloc ((strlen(temp)+1)*sizeof(char));
 
 /***********/
   strcpy(Nom_Fichier, temp);
   
   /*****ouverture du fichier***/
   pFichier = fopen( Nom_Fichier,"w");

 
  while(premier!=NULL){

    fprintf(pFichier,"%s \n",premier->pcNom);
    fprintf(pFichier,"%s \n",premier->pcPrenom);
    fprintf(pFichier,"%s \n",premier->pcMail);
    fprintf(pFichier,"                     \n");

    premier = premier->suivant;/*j'avance dans ma liste*/
  
  }

  fclose(pFichier);
  return ;
}

/***************************/
/*SUPPRESSION D'UN CONTACT*/
/**************************/
/*Recherche l'element precedent celui �a supprimer*/


sCONTACT * RECHERCHE_PRECEDENT(sCONTACT * premier, char * nom){

  sCONTACT * precedent;
  sCONTACT * courant;
  sCONTACT * last;
  char prenom[256];
  
  courant = premier;
  precedent = courant;
  printf("je suis avant le while\n");
  
  while(courant->suivant != NULL ){
     precedent = courant;
   if((strcmp(courant->suivant->pcNom,nom))==0){
       printf("confirmation par le prenom du contact\n");
       printf("entrer le bon prenom\n");
       scanf("%s",prenom);
       if((strcmp(courant->suivant->pcPrenom,prenom))==0){
       
       return precedent;
       
       }
   }
   
    courant = courant->suivant; 
     
  }
  
}


/***********************************************************************/
/*Supprime un elelment suivant*/

void SUPPRIME_SUIVANT(sCONTACT * precedent){

    sCONTACT * tmp;
   
    tmp = precedent->suivant;/*je fais une copie de l' element a supprimer*/
                             /* dans une variable temporaire afin de pouvoir*/
			     /* la liberer quant j aurai fais le raccordement*/
			     /* entre les deux elements qui l' encadrent*/
			     
    precedent->suivant = precedent->suivant->suivant;
              /*je fais pointe l' element suivant sur l'element qui suit l' element a*/
	      /*supprimer*/
	      
    free(tmp);/*je libere de la memeoire l'element supprime*/
    
    return; 
}

/*Recherche et Supprime un element*/

void RECHERCHE_SUPPRIME (sCONTACT * premier, char * nom){

    sCONTACT * precedent;
    /*sCONTACT * premier;*/
   char temp [256];
    
    printf("donner le nom de la personne a supprimer\n");
    scanf("%s",temp);
    
    /*allocation de la memoire pour la taile du nom de la personne a supprimer*/
 
     nom = (char *) malloc ((strlen(nom)+1)*sizeof(char));
 
     strcpy(nom, temp);
 
     printf("nom saisi;%s\n",nom);
     
    /*appel de la fonction recherche precedent*/
    precedent = RECHERCHE_PRECEDENT(premier,nom);
    
    printf("voici son precedent RECHERCHE_PRECEDENT=%s\n",precedent->pcNom); 
  
    /* appel de la procedure qui supprime le suivant de l'element precedent*/
    SUPPRIME_SUIVANT(precedent);
      
  return;
}

/*.....................................................*/

/*MODIFICATION D'UN CONTACT*/

void MODIFICATION(sCONTACT *premier){

   sCONTACT * courant;
   char nom[100];
   char prenom[100];
   char nom_new[100];
   char prenom_new[100];
   char mail_new[100];
   char rep;
   
   courant = premier;
   
   printf("entrer le nom de contact a modifier\n");
   scanf("%s",nom);
   
   while(courant!=NULL){
     
   if((strcmp(courant->pcNom,nom))==0){
       printf("confirmation par le prenom du contact\n");
       printf("entrer le bon prenom\n");
       scanf("%s",prenom);
       if((strcmp(courant->pcPrenom,prenom))==0){
       
         printf("faites votre choix\n");
	 printf("tapez x pour modifier le nom\n");
	 printf("tapez y pour modifier le prenom\n");
         printf("tapez z pour modifier le mail\n");
	
	 scanf("%c",&rep);
	
	 getchar();  
		
	 if(rep == 'x'){
	
	   printf("donner le nouveau nom\n");
	   scanf("%s",nom_new);
	  
	   courant->pcNom = nom_new;
	  
	 }  	
	 else if(rep == 'y'){
	
	  printf("donnez le nouveau prenom\n");
	  scanf("%s",prenom_new);
	  
	  courant->pcPrenom = prenom_new;	  
	 }
	
	 else if(rep =='z'){
	
	   printf("donner le mail\n");
	   scanf("%s",mail_new);
	 
	   courant->pcMail = mail_new;	  
	 }	
	 else{
	
	  printf("il faut taper x,y ou z\n");
	
	}
	
       }
   }
   
    courant = courant->suivant;
     
   }

 return;
 
}
/*----------------------------------------------------/
/*************FONCTION PRINCIPALE*********/

int main(){


  sCONTACT * HEAD = NULL;
  sCONTACT * PRECEDENT = NULL;
  char   * nom; 
  char car;
 
  do {
    
    printf("faites votre choix\n");
    printf("taper 1 pour creer et ajouter un contact\n");
    printf("taper 2 pour afficher les contacts\n");
    printf("taper 3 pour écrire les contacts dans un fichier\n");
    printf("taper 4 pour supprimer un contact\n");
    printf("taper 5 pour modifier un contact\n");
    
    scanf("%c",&car);

     while(getchar()!='\n'){
                 ;
            } 

    switch (car){
  
    case '1':/*pour ajouter un nouveau contact*/
   
      HEAD = CREER_AJOUT_CONTACT(HEAD);
     
      break;

    case '2':
 
      AFFICHE_CONTACT(HEAD);

      break;

    case '3':/*ecriture dans un fichier*/

      ECRITURE_FICHIER(HEAD);


      break;

    case '4':
 
   
     RECHERCHE_SUPPRIME (HEAD,nom);
   
      break;
      
    case '5':
    
     MODIFICATION (HEAD);
    
    break;  

    default:
      printf("il faut taper 1,2,3,4,5\n");
      break;
    }

   while(getchar()!='\n'){
                 ;
            } 
	    

  }while(car!='q');

  LIBERE(HEAD);

  return 0;
}
