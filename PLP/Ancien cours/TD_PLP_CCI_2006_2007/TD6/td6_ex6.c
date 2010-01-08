#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "getEntries.c"

#define NB 5


char chaine[MAX_SIZE];



typedef struct adresse
{
	int numero_de_rue;
	char *nom_de_rue;
	int code_postal; 
	char *pays;



};


typedef struct personne
{
	char *nom;
	char *prenom;

	struct personne *pere;
	struct personne *mere;
	struct adresse *adresse;

};



void init(struct personne *personne,int i);
char* getString();
void suppression_redondance(struct personne *personne[NB],int tab[NB]);
void affichage(struct personne *personne,int i);



//struct personne






int main()
{

	struct personne *personne[NB];
	int tab[NB];
	int i;


	for(i=0;i<NB;i++)
	{
		personne[i]=(struct personne *)malloc(sizeof(struct personne));	
		init(personne[i],i);
	}


	suppression_redondance(personne,tab);
			

	for(i=0;i<NB;i++)
	affichage(personne[i],i);

	for(i=0;i<NB;i++)
	{
		free(personne[i]->pere);
		free(personne[i]->mere);
		if(tab[i]!=1)
			free(personne[i]->adresse);
		free(personne[i]);
	}
	
}


char* getString()
{

	char temp[200];
	int i,end=0;
	char *nom;
  
	fgets(temp,200,stdin);
	for(i=0;i<200;i++)
    {
		if(temp[i]=='\n') end=1;
    }
	if(!end) flush_stdin();
  
	//printf("nom1 : %s\n",temp);
	nom=(char *)malloc(strlen(temp)+1);
	strcpy(nom,temp);
	//printf("nom2 : %s\n",nom);
	return nom;
	  
}

void init(struct personne *personne,int i)
{

	//personne=(struct personne *)malloc(sizeof(struct personne));
	printf("Personne %d\n",i+1);

	printf("Nom : ");
	personne->nom=getString();

	printf("Prenom : ");
	personne->prenom=getString();

	printf("Nom du pere : ");
	personne->pere=(struct personne *)malloc(sizeof(struct personne));
	personne->pere->nom=getString();

	printf("Prenom du pere : ");
	personne->pere->prenom=getString();

	printf("Nom de la mere : ");
	personne->mere=(struct personne *)malloc(sizeof(struct personne));
	personne->mere->nom=getString();

	printf("Prenom de la mere : ");
	personne->mere->prenom=getString();

	
	printf("Votre adresse\n");
	personne->adresse=(struct adresse *)malloc(sizeof(struct adresse));
	printf("Numero : ");
	personne->adresse->numero_de_rue=(int)getNumber(chaine);
	printf("Nom de la rue : ");
	personne->adresse->nom_de_rue=getString();
	printf("Code postal : ");
	personne->adresse->code_postal=(int)getNumber(chaine);
	printf("Pays : ");
	personne->adresse->pays=getString();


}


void suppression_redondance(struct personne *personne[NB],int tab[NB])
{

	int i,j;
	struct adresse *adr_temp;

	for(i=0;i<NB;i++)
		tab[i]=0;

	for(i=0;i<NB;i++)
		for(j=i+1;j<NB;j++)
			if(personne[i]->adresse->numero_de_rue==personne[j]->adresse->numero_de_rue)
			//if(*(personne[i].adresse->nom_de_rue)==*(personne[j].adresse->nom_de_rue))
			if(!strcmp(personne[i]->adresse->nom_de_rue,personne[j]->adresse->nom_de_rue))
			if(personne[i]->adresse->code_postal==personne[j]->adresse->code_postal)
			//if(*(personne[i].adresse->pays)==*(personne[j].adresse->pays))
			if(!strcmp(personne[i]->adresse->pays,personne[j]->adresse->pays))
			{
					adr_temp=personne[j]->adresse;
					personne[j]->adresse=personne[i]->adresse;
					if(adr_temp!=personne[i]->adresse)
					{
						free(adr_temp);
						tab[j]=1;
						printf("l adresse de la personne %d a ete supprimee\n",j);
					}
			}
			



}


void affichage(struct personne *personne,int i)
{

	printf("Personne numero %d\nNom : %s\nPrenom  : %s\nNom du pere %s\nPrenom du pere : %s\nNom de la mere : %s\nPrenom de la mere : %s\nAdresse\nNumero %d\nNom de la rue : %s\nCode postal : %d\nPays : %s\n",i+1,personne->nom,personne->prenom,personne->pere->nom,personne->pere->prenom,personne->mere->nom,personne->mere->prenom,personne->adresse->numero_de_rue,personne->adresse->nom_de_rue,personne->adresse->code_postal,personne->adresse->pays);




}
