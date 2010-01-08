 
// librairie
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

// structure
typedef struct sElement
{
  char* Nom,
    *Prenom,*email;
  struct sElement* suivant;
} Element;
typedef struct sFile{
        char *Nom,*Prenom,*Email;
        }File;

// Fonction Ajouter
Element* Ajouter(Element* liste)
{
  char s[30];
  Element* element= (Element *) malloc( sizeof( Element ) );
  // la valeur de l'élément
  printf("donner Nom:");
  scanf("%s",&element->Nom);
  printf("donner Prenom:");
  scanf("%s",&element->Prenom);
  printf("donner email:");
  scanf("%s",&element->email);
  element->suivant = liste;
  return element;
}

// Fonction Rechercher
Element* Rechercher(char* nm, Element* liste)
{
  
  Element* element=NULL, *ele=NULL;
  while(( element!= NULL) && (strcmp(nm,liste->Nom)!=0))
    element = element->suivant;
  if (element!=NULL)
    {
      ele= (Element *) malloc( sizeof( Element ) );
      ele->Nom=element->Nom;
      ele->Prenom=element->Prenom;
      ele->email=element->email;
      ele->suivant=NULL;
    }
  return element;

}
// Fonction libérer
void liberer(Element* liste)
{
  Element* Tmp;
  while(liste !=NULL)
    {
      Tmp=liste;
      liste=liste->suivant;
      free(Tmp);
    }
}


// Fonction Affiher
void Afficher(Element* liste)
{  int i=0;
   Element* element = liste;
  if(liste==NULL) printf("Liste vide\n");
  //printf("je suis ici\n");
  while(element != NULL)
    {
      printf("%s %s %s \n", element->Nom,element->Prenom,element->email,"\n");
      printf("je suis dans l'itteration %d\n",++i);
      element = element->suivant;
    }

}

// Fonction supprimer
Element* Supprimer(Element* liste)
{
	char* nm;
	Element* ele =NULL;
	Element* Tmp=NULL;
	printf("donner nombre à supprimer:");
	scanf("%s",&nm);
	printf("%s\n",nm);
	if(liste!=NULL)
	{
		if((strcmp(liste->Nom,nm))==0)
		{
			Tmp=liste;
			liste=liste->suivant;
			free(Tmp);
		}
		else
		{
			ele=liste;
			while(ele->suivant!=NULL)
			{
				if((strcmp(liste->Nom,nm))!=0)
				{
					Tmp=ele->suivant;
					ele->suivant=ele->suivant->suivant;
					free(Tmp);
				}
				else ele=ele->suivant;
			}
		}
	}
	return liste;
}
// Fonction principale
int main(void)
{
  
  Element* Liste=NULL;
  Element* e=NULL;
  Liste=Ajouter(Liste);
  Liste=Ajouter(Liste);
  Afficher(Liste);
  e = Rechercher("HH",Liste);
  Afficher(e);
  Liste=Supprimer(Liste);
  e=Rechercher("za",Liste);
  Afficher(e);
  Afficher(Liste);
  liberer(Liste);
  return 0;
  
}

