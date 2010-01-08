/* BEN MOUSSA Wafa - miniprojet2- Snake */
# ifdef __linux__
# define CLEAR "clear"
# else
# define CLEAR "cls"
# endif

# include <stdio.h>
# include <stdlib.h>
# include <time.h>

struct Serpent{

  int position;
  int direction;
};

enum{
  HAUT = 94, BAS = 118, GAUCHE = 60, DROITE = 62
};

void initEnvironnement(char*, int*, int*);
void affichage(char*, int*, int*);
void attente(int*);
void initSerpents(struct Serpent*, int*, int*, int*, char*);
void deplacements(struct Serpent*, int*, int*, int*, char*, int*);
void gauche(int*, struct Serpent*);
void droite(int*, struct Serpent*);

int main(int argc, char ** argv)
{
  int largeur = 0;
  int hauteur = 0;
  int nbSerpents = 0;
  int delai = 0;
  int test = 0;
  int k = 0;
  int pourcentage[5] = {0};
  int l = 0;

  /* test si le nombre d'arguments entr� est correct ou non */
  if(argc != 4)
    {
      printf("Le nombre d'arguments est incorrect!\n");
      return 0;
    }

 /* d�chiffrage des arguments entr� */
  sscanf( argv[1], "%dx%d", &largeur, &hauteur);
  sscanf( argv[2], "%d", &nbSerpents);
  sscanf( argv[3], "%d", &delai);

  /* test si la taille entr� est correcte */
  if(largeur <= 0 || hauteur <= 0)
    {
      printf("La taille est incorrecte!\n");
      return 0;
    }

  char espace[largeur*hauteur];
  struct Serpent serpents[nbSerpents];
  
  /* cr�ation et initialisation du tableau de controle de l'arret du programme lorque tous les serpents sont bloqu�s */
  int arret[nbSerpents];

  for(k = 0; k < nbSerpents; k++)
    {
      arret[k] = 0;
    }

  initEnvironnement(espace, &largeur, &hauteur);
  initSerpents(serpents, &nbSerpents,&largeur, &hauteur, espace);
  affichage(espace, &largeur, &hauteur);


  while(test == 0)
    {

      system( CLEAR );
      
      deplacements(serpents, &nbSerpents, &largeur, &hauteur, espace, arret);
      affichage(espace, &largeur, &hauteur);
      attente(&delai);
      
      test = 1;
      for(k = 0; k < nbSerpents; k++)
        {
	  test *= arret[k];
        }
    }
  
  for( l = 0; l < hauteur; l++)
    {
      for( k = 0; k < largeur; k++)
	{
	  if(espace[k + l*largeur] == ' ')
	    {
	      pourcentage[0] +=1;
	      
	    }
	  if(espace[k + l*largeur] == '<')
	    {
	      pourcentage[1] +=1;
	      
	    }
	  if(espace[k + l*largeur] == '>')
	    {
	      pourcentage[2] +=1;
	      
	    }
	  if(espace[k + l*largeur] == '^')
	    {
	      pourcentage[3] +=1;
	      
	    }
	  if(espace[k + l*largeur] == 'v')
	    {
	      pourcentage[4] +=1;
	      
	    }
	}
    }

  for( l = 0; l < 5; l++)
    {
	  pourcentage[l] *=100;
	  pourcentage[l] /= (largeur*hauteur);
    }
  printf("Il y a %d%% d'espace vide restant\n", pourcentage[0]);
  printf("Il y a %d%% de direction gauche\n", pourcentage[1]);
  printf("Il y a %d%% de direction droite\n", pourcentage[2]);
  printf("Il y a %d%% de direction haut\n", pourcentage[3]);
  printf("Il y a %d%% de direction bas\n", pourcentage[4]);
  return 0;
}


void initEnvironnement(char pEspace[], int *pLargeur, int *pHauteur)
{

  int i = 0;
  int j =0;

  for( i = 0; i < *pHauteur; i++)
    {
      for( j = 0; j < *pLargeur; j++)
	{
	  pEspace[j + i*(*pLargeur)] = ' ';
	}
    }
}

void affichage(char pEspace[], int *pLargeur, int *pHauteur)
{
  int i = 0;
  int j = 0;

  for( i = 0; i < (*pLargeur +2); i++)
    {
      printf("#");
    }
  printf("\n");
  
  for( i = 0; i < (*pHauteur); i++)
    {
      printf("#");
      for( j = 0; j < *pLargeur; j++)
	{
	  printf("%c", pEspace[j + i*(*pLargeur)]);
	}
      printf("#\n");
      
    }
  
  
  for( i = 0; i < (*pLargeur +2); i++)
    {
      printf("#");
    }
  printf("\n");
}



void attente(int *pDelai)
{
  int finAttente = (1000 * (clock())/(CLOCKS_PER_SEC)) + *pDelai;

  while((1000 * (clock())/(CLOCKS_PER_SEC)) < finAttente)
    {
    }
}



void initSerpents(struct Serpent pSerpents[], int *pNbSerpents, int *pLargeur, int *pHauteur, char pEspace[] )
{

  int i = 0;
  srand(time(NULL));

  for(i = 0; i < *pNbSerpents; i++)
    {
      pSerpents[i].position = rand()%(*pLargeur * (*pHauteur));
      pSerpents[i].direction = rand()%4 +1;
      
      switch(pSerpents[i].direction)
	{
	case 1:
	  pEspace[pSerpents[i].position] = GAUCHE;
	  pSerpents[i].direction = GAUCHE;
	  break;
	case 2:
	  pEspace[pSerpents[i].position] = DROITE;
	  pSerpents[i].direction = DROITE;
	  break;
	case 3:
	  pEspace[pSerpents[i].position] = HAUT;
	  pSerpents[i].direction = HAUT;
	  break;
	case 4:
	  pEspace[pSerpents[i].position] = BAS;
	  pSerpents[i].direction = BAS;
	  break;
	default:
	  break;
	}

    }

}


void deplacements(struct Serpent pSerpents[], int *pNbSerpents, int *pLargeur, int *pHauteur, char pEspace[], int pArret[])
{
  int i = 0;
  
  for( i = 0; i < *pNbSerpents; i++)
    {
      switch(pSerpents[i].direction)
	{
	case GAUCHE:
	  if(pEspace[pSerpents[i].position - 1] == ' ' && ((pSerpents[i].position) % (*pLargeur)) != 0)
	    {
	      (pSerpents[i].position) -= 1;
	      
	    }
	  else
	    {
	      if(pEspace[pSerpents[i].position + *pLargeur] == ' ' && (pSerpents[i].position + *pLargeur) < (*pLargeur * (*pHauteur)))
		{
		  
		  gauche(pLargeur, &pSerpents[i]);
		}
	      else if(pEspace[pSerpents[i].position - *pLargeur] == ' ')
		{
		  droite(pLargeur, &pSerpents[i]);
		}
	      else
		{
		  pArret[i] = 1;
		}
	      
	    }
	  
	  break;
	case DROITE:
	  if(pEspace[pSerpents[i].position + 1] == ' ' && ((pSerpents[i].position) % (*pLargeur)) != (*pLargeur - 1))
	    {
	      (pSerpents[i].position) += 1;
	      
	    }
	  else
	    {
	      if(pEspace[pSerpents[i].position - *pLargeur] == ' ' && (pSerpents[i].position + *pLargeur) > 0)
		{
		  
		  gauche(pLargeur, &pSerpents[i]);
		}
	      else if(pEspace[pSerpents[i].position + *pLargeur] == ' ')
		{
		  droite(pLargeur, &pSerpents[i]);
		}
	      else
		{
		  pArret[i] = 1;
		}
	    }
	  
	  break;
	case HAUT:
	  if(pEspace[pSerpents[i].position - *pLargeur] == ' ' && ((pSerpents[i].position) - *pLargeur) > 0)
	    {
	      (pSerpents[i].position) -= *pLargeur;
	      
	    }
	  else
	    {
	      if(pEspace[pSerpents[i].position - 1] == ' ' && ((pSerpents[i].position) % (*pLargeur)) != 0)
		{
		  
		  gauche(pLargeur, &pSerpents[i]);
		}
	      else if(pEspace[pSerpents[i].position + 1] == ' ')
		{
		  droite(pLargeur, &pSerpents[i]);
		}
	      else
		{
		  pArret[i] = 1;
		}
	    }
	  
	  break;
	case BAS:
	  if(pEspace[pSerpents[i].position + *pLargeur] == ' ' && ((pSerpents[i].position) + *pLargeur) < (*pLargeur * (*pHauteur)))
	    {
	      (pSerpents[i].position) += *pLargeur;
	      
	    }
	  else
	    {
	      if(pEspace[pSerpents[i].position + 1] == ' ' && ((pSerpents[i].position) % (*pLargeur)) != (*pLargeur -1))
		{
		  
		  gauche(pLargeur, &pSerpents[i]);
		}
	      else if(pEspace[pSerpents[i].position - 1] == ' ')
		{
		  droite(pLargeur, &pSerpents[i]);
		}
	      else
		{
		  pArret[i] = 1;
		}
	    }
	  
	  break;
	default:
	  break;
	}
      pEspace[pSerpents[i].position] = pSerpents[i].direction;
      
    }
  
  
}

void gauche(int *pLargeur, struct Serpent *pSerpents)
{
  switch(pSerpents->direction)
    {
    case GAUCHE:
      pSerpents->direction = BAS;
      (pSerpents->position) += *pLargeur;
      break;
    case DROITE:
      pSerpents->direction = HAUT;
      (pSerpents->position) -= *pLargeur;
      break;
    case HAUT:
      pSerpents->direction = GAUCHE;
      (pSerpents->position)--;
      break;
    case BAS:
      pSerpents->direction = DROITE;
      (pSerpents->position)++;
      break;
    default:
      break;
      
    }
   
}

void droite(int *pLargeur, struct Serpent *pSerpents)
{
  switch(pSerpents->direction)
    {
    case DROITE:
      pSerpents->direction = BAS;
      (pSerpents->position) += *pLargeur;
      break;
    case GAUCHE:
      pSerpents->direction = HAUT;
      (pSerpents->position) -= *pLargeur;
      break;
    case BAS:
      pSerpents->direction = GAUCHE;
      (pSerpents->position)--;
      break;
    case HAUT:
      pSerpents->direction = DROITE;
      (pSerpents->position)++;
      break;
    default:
      break;
      
    }
}
