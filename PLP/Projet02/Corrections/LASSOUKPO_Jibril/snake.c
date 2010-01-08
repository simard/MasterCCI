/*LASSOUKPO Olanréwaju Jibril*/
/*Programme Snake*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

# ifdef __linux__
# define CLRSCR "clear"
# else
# define CLRSCR "clr"
# endif

#define VRAI 1
#define FAUX 0

typedef enum edirection
{
  DROITE = 1,
  GAUCHE = 2,
  HAUT = 3,
  BAS = 4
} tdirection ;

 typedef struct sposition 
 {
   int posi;
   int posj;
 } tposition;

 typedef struct sserpent 
 {
tposition  position;
tdirection direction;
 } tserpent;



int main ( int argc, char ** argv)
{

  int ilargeur = 0;
  int ihauteur = 0;
  int inbserpents = 0;
  int itempsattente = 0;
  char csigne ;

  int i = 0;
  int finSnake = FAUX;
  int finDepAvancer = FAUX;
  int finDepGauche = FAUX;
  int finDepDroite = FAUX;




  if (argc < 4)
    {
      printf("Il manque des arguments\n");
      return 1;
    }
  else 
    {
      if (argc > 4)
	{
	  printf("Il y a trop d'arguments\n");
	  return 1;
	}
    }

  sscanf ( argv[1] , "%d%c%d", &ilargeur, &csigne, & ihauteur);
  sscanf ( argv[2] , "%d", &inbserpents);
  sscanf ( argv[3] , "%d", &itempsattente);
 

  /*printf ("%d\n",ilargeur);
  printf ("%c\n",csigne);
  printf ("%d\n",ihauteur);
  printf ("%d\n",inbserpents);
  printf ("%d\n",itempsattente);*/





tserpent tableauserpents[inbserpents];

 char ctableau[ilargeur * ihauteur];

  /*Prototypes des fonctions*/

  void initialisertableau(int, int, char []);
  void affichertableau(int, int, char []);
  void attendre(int);
  int system (const char * string);

  void creerserpents(int, int, tserpent *, char []);

  int avancer ( int, tserpent *, char []); 
  int tournerGauche ( int, tserpent *, char []);
  int tournerDroite ( int, tserpent *, char []);

  

  /*Appel des fontions*/


  initialisertableau( ilargeur, ihauteur, ctableau);

  affichertableau( ilargeur, ihauteur, ctableau);

  attendre(itempsattente);

  system( CLRSCR );


for ( i = 0; i < inbserpents; i++)
  {  
    creerserpents( ilargeur, ihauteur, &tableauserpents[i], ctableau);
    
  }

  affichertableau( ilargeur, ihauteur, ctableau);

        
      
      for ( i = 0; i < inbserpents; i++)
	{

	  while (finSnake == FAUX)
	    {
   	      
	      finDepAvancer = avancer(ilargeur, &tableauserpents[i], ctableau);

	      affichertableau( ilargeur, ihauteur, ctableau);
	      attendre(itempsattente);
	      system( CLRSCR );
	  
	      if ( finDepAvancer == VRAI )
		{
		  
		  finDepGauche = tournerGauche(ilargeur, &tableauserpents[i], ctableau);
		  affichertableau( ilargeur, ihauteur, ctableau);
		  attendre(itempsattente);
		  system( CLRSCR );
		
		  if ( finDepGauche == FAUX )
		    {
		      
		      finDepAvancer = avancer(ilargeur, &tableauserpents[i], ctableau);
		    }

		  else
		    {

		      finDepDroite = tournerDroite(ilargeur, &tableauserpents[i], ctableau);
		      if (finDepDroite == FAUX)
			{
			  finDepAvancer = avancer(ilargeur, &tableauserpents[i], ctableau);
			  affichertableau( ilargeur, ihauteur, ctableau);
			  attendre(itempsattente);
			  system( CLRSCR );
			}
		      
		      else
			{
			  finSnake = VRAI;
			}

		    }
		}
	      else
		{
		  finSnake = FAUX;
		}

	    }
	  finSnake = VRAI;

        
	
	}


    

  printf("fin du programme\n");

  return 0;

}



 void creerserpents(int ilargeur, int ihauteur, tserpent *ptserpent, char ctableau[])
   {

     int k = 0;

     (ptserpent->position).posi = 1 + (int) ((double) rand()/((double) RAND_MAX + 1) * (ihauteur-1));
     printf ( "%d\n", (ptserpent->position).posi);
     (ptserpent->position).posj = 1 + (int) ((double) rand()/((double) RAND_MAX + 1) * (ilargeur-1));
     printf ( "%d\n", (ptserpent->position).posj);
     ptserpent->direction = 1 + (int) ((double) rand()/((double) RAND_MAX + 1) * 3);
     printf ( "%d\n", ptserpent->direction);
     
     k = ((ptserpent->position).posi-1)*ilargeur +  ((ptserpent->position).posj-1);

      switch(ptserpent->direction)
	{
	case DROITE:
	  ctableau[k] = '>';
	  break;

	case GAUCHE:
	  ctableau[k] = '<';
	  break;

	case HAUT:
	  ctableau[k] = '^';
	  break;

	case BAS:
	  ctableau[k] = 'v';
	  break;

	default:
	  printf("il y a erreur\n");
	  break;

	}

    }

 




void initialisertableau (int ilargeur, int ihauteur, char ctableau [])
{
  int i = 0;/*indice des lignes*/
  

  for( i = 0 ; i < ilargeur * ihauteur ; i++ )
    {
	  ctableau[i] = ' ' ;
	
    }
}



void affichertableau ( int ilargeur, int ihauteur, char ctableau[])
{
  int i = 0;/*indice des lignes*/
  int j = 0;/*indice des colonnes*/
  int ifinallargeur = 0; 
  int ifinalhauteur = 0;
  int indicetableau = 0;

  ifinallargeur = ilargeur + 2;
  ifinalhauteur = ihauteur + 2;


  char cfinaltableau[ ifinalhauteur][ ifinallargeur];

  for ( i = 0; i <ifinalhauteur ; i++ )
    {

      for (  j = 0; j< ifinallargeur; j++)
	{  
	  cfinaltableau[i][j] = '#';
	}

    }

  for (i = 1; i<=ihauteur; i++)
    {
      for (j = 1; j<=ilargeur; j++)
	{
	  indicetableau = (i-1)*ilargeur + j-1;
	  /*printf("i=%d\n",i);
	  printf("j=%d\n",j);
	  printf("indicetableau = %d\n",indicetableau);*/
	  cfinaltableau[i][j] = ctableau[indicetableau] ;
	}
    }

 

  for (i = 0 ; i < ifinalhauteur ; i++)
    {

      for ( j = 0; j  < ifinallargeur; j++)
	{
	  printf("%c", cfinaltableau[i][j]);
          
	  
	}
      printf("\n");

    }



}


void attendre( int itempsattente)
{ 
  clock_t fin;
  
  fin = clock() + itempsattente * CLOCKS_PER_SEC/1000;

  while (clock() < fin)
    {
    }
  return;
}


int avancer ( int ilargeur, tserpent *ptserpent, char ctableau[])
{
  int i = 0; 
  int j = 0;
  int k; /*Indice dans ctableau*/
  int finAvancer = FAUX; /*On suppose que le serpent peut se déplacer*/

  i= (ptserpent->position).posi;
  j= (ptserpent->position).posj;

  k = (i-1)*ilargeur + j- 1;
  /* printf("ancienne valeur de k = %d\n",k);*/

  switch ( ptserpent->direction )
    {
    case DROITE:
  
      while (finAvancer == FAUX)
	{
	  k = (i-1)*ilargeur + j;    
     
	  if ( ctableau[k] == ' ')
	    {
	      ctableau[k] = '>';
	      j++;
	      ptserpent->direction = DROITE; /*Inutile ici mais facilite la compréhension*/
	    }
	  else
	    {
	      finAvancer = VRAI;
	    }
	}

      break;


    case GAUCHE:
      
      while (finAvancer == FAUX)
	{
      
	  k = (i-1)*ilargeur + j- 2;
      

	  if ( ctableau[k] == ' ')
	    {
	      ctableau[k] = '<';
	      j--;
	      ptserpent->direction = GAUCHE; /*Inutile ici mais facilite la compréhension*/
	    }
	  else
	    {
	      finAvancer = VRAI;
	    }
	}      
      break;


    case HAUT:
      
      while (finAvancer == FAUX)
	{
	  k = (i-2)*ilargeur + j- 1;
     

	  if ( ctableau[k] == ' ')
	    {
	      ctableau[k] = '^';
	      i--;
	      ptserpent->direction = HAUT; /*Inutile ici mais facilite la compréhension*/
	    }
	  else
	    {
	      finAvancer = VRAI;
	    }
	}
      break;

    case BAS:
      while ( finAvancer == FAUX )
	{
      
	  k = i*ilargeur + j- 1;
      

	  if ( ctableau[k] == ' ')
	    {
	  
	      ctableau[k] = 'v';
	      i++;
	      ptserpent->direction = BAS; /*Inutile ici mais facilite la compréhension*/
	    }
	  else
	    {
	      finAvancer = VRAI;
	    }
	}
	  break;
      
       default:
	  printf("il y a erreur\n");
	  break;
    }
  
  return ( finAvancer );


}




int tournerGauche ( int ilargeur, tserpent *ptserpent, char ctableau[])
{
  int i = 0; 
  int j = 0;
  int k; /*Indice dans ctableau*/
  int finGauche = FAUX; /*On suppose que le serpent peut se déplacer*/

  i = (ptserpent->position).posi;
  j = (ptserpent->position).posj;

  k = (i-1)*ilargeur + j-1;

  switch ( ptserpent->direction )
    {
    case DROITE:

	  k = (i-2)*ilargeur + j- 1;
	  if ( ctableau[k] == ' ')
	    {
	      ctableau[k] = '^';
	      i--;
	      ptserpent->direction = HAUT; /*Inutile ici mais facilite la compréhension*/
	    }
	  else
	    {
	      finGauche = VRAI;
	    }
	
      break;


    case GAUCHE:
            
	  k = i*ilargeur + j- 1;
	  if ( ctableau[k] == ' ')
	    {
	      ctableau[k] = 'v';
	      i++;
	      ptserpent->direction = BAS; /*Inutile ici mais facilite la compréhension*/
	    }
	  else
	    {
	      finGauche = VRAI;
	    }
	
      break;


    case HAUT:
        
	    k = (i-1)*ilargeur + j- 2;
	    if ( ctableau[k] == ' ')
	      {
		ctableau[k] = '<';
		j--;
		ptserpent->direction = GAUCHE; /*Inutile ici mais facilite la compréhension*/
	      }
	    else
	      {
		finGauche = VRAI;
	      }
	  
	break;

    case BAS:
        
      k = (i-1)*ilargeur + j;
	    if ( ctableau[k] == ' ')
	      {
	  
		ctableau[k] = '>';
		j++;
		ptserpent->direction = DROITE; /*Inutile ici mais facilite la compréhension*/
	      }
	    else
	      {
		finGauche = VRAI;
	      }
	        
	break;
      
    default:
	  printf("il y a erreur\n");
	  break;
    }
  
  return ( finGauche );


}



int tournerDroite ( int ilargeur, tserpent *ptserpent, char ctableau[])
{
  int i = 0; 
  int j = 0;
  int k; /*Indice dans ctableau*/
  int finDroite = FAUX; /*On suppose que le serpent peut se déplacer*/

  i = (ptserpent->position).posi;
  j = (ptserpent->position).posj;

  k = (i-1)*ilargeur + j-1;

  switch ( ptserpent->direction )
    {
    case DROITE:
           
	  k = i*ilargeur + j- 1;
	  if ( ctableau[k] == ' ')
	    {
	      ctableau[k] = 'v';
	      i++;
	      ptserpent->direction = BAS; /*Inutile ici mais facilite la compréhension*/
	    }
	  else
	    {
	      finDroite = VRAI;
	    }
	
      break;


    case GAUCHE:
     
	  k = (i-2)*ilargeur + j- 1;
	  if ( ctableau[k] == ' ')
	    {
	      ctableau[k] = '^';
	      i--;
	      ptserpent->direction = HAUT; /*Inutile ici mais facilite la compréhension*/
	    }
	  else
	    {
	      finDroite = VRAI;
	    }
	
      break;


    case HAUT:
      
	  k = (i-1)*ilargeur + j;
	  if ( ctableau[k] == ' ')
	    {
	      ctableau[k] = '>';
	      j++;
	      ptserpent->direction = DROITE; /*Inutile ici mais facilite la compréhension*/
	    }
	  else
	    {
	      finDroite = VRAI;
	    }
	
      break;

    case BAS:
      
	  k = (i-1)*ilargeur + j- 2;
	  if ( ctableau[k] == ' ')  
	    {
	  
	      ctableau[k] = '<';
	      j--;
	      ptserpent->direction = GAUCHE; /*Inutile ici mais facilite la compréhension*/
	    }
	  else
	    {
	      finDroite = VRAI;
	    }
	
      break;
      
    default:
	  printf("il y a erreur\n");
	  break;
    }
  
  return ( finDroite );


}

