
/********************************************************/
/*					        ABOUBAKRY NDIAYE        						*/
/*									M2 CCI:	Projet n°2									*/
/********************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#ifdef __linux__
#define CLRSCR "clear"
#else
#define CLRSCR "clr"
#endif

struct coordonne   /*les coordonnées du serpent*/
{
    unsigned int x;
    unsigned int y;
};

typedef struct serpent_
{
    struct coordonne position; //coordonnées
    int sens ; //direction de sa tete
}serpent;

typedef struct statistique_
{
		unsigned int compt, haut, bas, gauche, droite;
}statistic;
  
typedef enum direction_
{
    GAUCHE = 0, //deplacement vers la gauche
    DROITE = 1, //deplacement vers la droite
    BAS    = 2, //deplacement vers le haut
    HAUT   = 3 //deplacement vers le bas
}direction;

/***********************************/
  
  void affichage_cadre( unsigned int largeur, unsigned int hauteur, char tab[]);
  void init_tab( unsigned int ligne, unsigned int colonne, char tab[]);
  void effacer( void);
  void animation(char tab[]);
  void attente(unsigned int temps_attente);
  void remplir_tab( char tab[], unsigned int hauteur, unsigned int largeur, serpent snake);
  
  /****************fonction de deplacement****************************/ 
 
  unsigned int avancer( char tab[], unsigned int largeur, unsigned int hauteur, serpent *snake);/* fonction pour avant tout droit*/
  unsigned int tourner_gauche( char tab[],unsigned int largeur, unsigned int hauteur, serpent *snake);
  unsigned int tourner_droite( char tab[], unsigned int largeur, unsigned int hauteur, serpent *snake);
  void deplacement( char tab[], unsigned int largeur, unsigned int hauteur, serpent *snake);/* fonction principale des déplacements du serpent*/
  /************************************************************/
  
  unsigned int valeur_aleatoire( unsigned int position);
  serpent creat_snake( unsigned int largeur, unsigned int hauteur);/****fonction pour generer un serpent****/
  statistic statistique( unsigned int largeur, unsigned int hauteur, char tab[]);/* fonction pour calculer les pourcentages d'occupation*/
 
  
  const unsigned int nbre_sens=4;  /*constante => nombre de sens*/
  unsigned int test=0;		/*  variable devant contenir */



int main(int arg, char** argv)
{
    unsigned int hauteur=0; 
    unsigned int largeur=0;
    unsigned int tempo=0;
    unsigned int nbr_serpent=0;
    serpent init_serpent;
    statistic stat;
    
    
    sscanf(argv[1],"%dx%d",&largeur, &hauteur);		/**/
    sscanf(argv[2],"%d", &nbr_serpent);						/*le nombre de serpent*/
    sscanf(argv[3],"%d", &tempo);									/*recuperation de la valeur du temporisation pour afficher le tableau*/
    
    char tab[hauteur*largeur]; /*declaration du tableau*/
    serpent snake_tab[nbr_serpent];

    init_tab( hauteur, largeur, tab);/* initialisation du tableau*/
    init_serpent = creat_snake( largeur, hauteur); /* crée un serpent */
    remplir_tab( tab, hauteur, largeur, init_serpent);/* remplir le tableau avec la position initial du serpent*/

    printf("position du serpent suivent x : %d\n", init_serpent.position.x);
    printf("position du serpent suivent y : %d\n", init_serpent.position.y);
  
    affichage_cadre( largeur, hauteur, tab); /********affichage_cadre*****************/
    
    while(!test)
    {
    		
    		deplacement( tab, largeur, hauteur, &init_serpent);										/***fonction des déplacements**/
    		//effacer();																														/*appel de la fonction efface pour effacer le terminal*/
		attente(tempo); 																											/*recupération du temps d'attente entre deux affichages*/
    		affichage_cadre( largeur, hauteur, tab); 																							/*affichage_cadre pour la mise à jour*/
    }
   	stat = statistique( largeur, hauteur, tab);/*calcule du pourcentage d'occupation du tableau*/
   	
   	printf("\nLe plateau est rempli a %.2f (%d/%d) dont :\n\n", (float)(stat.compt) , stat.compt, largeur*hauteur);
    printf("- %.2f '^' (%d/%d)\n", (float)(stat.haut)/stat.compt , stat.haut, stat.compt); 		/*afficher le pourcentage '^'*/
    printf("- %.2f 'v' (%d/%d)\n", (float)(stat.bas)/stat.compt , stat.bas, stat.compt);			/*afficher le pourcentage 'v'*/
    printf("- %.2f '<' (%d/%d)\n", (float)(stat.gauche)/stat.compt , stat.gauche, stat.compt);/*afficher le pourcentage '<'*/
    printf("- %.2f '>' (%d/%d)\n", (float)(stat.droite)/stat.compt , stat.droite, stat.compt);/*afficher le pourcentage '>'*/
    
    return 0;
}


/****************************fonction des déplacements************************/

void deplacement( char tab[], unsigned int largeur, unsigned int hauteur, serpent *snake)
{
		if(avancer( tab, largeur, hauteur, snake))
    {
    		
    			if(tourner_gauche( tab, largeur, hauteur, snake))
    			{
    				  if(tourner_droite( tab, largeur, hauteur, snake))
    				  {
    				  		test = 1; /*on a pas pu évolue*/
    				  }
    					    					
    			} 						
    			    			
    }
}

/*-----------generation du serpent et de sa position initiale---------------------*/

serpent creat_snake( unsigned int largeur, unsigned int hauteur)
{
    serpent serpent1;
    direction sens=0;
    
    serpent1.position.x= valeur_aleatoire( largeur-1); 	/* position du serpent suivent x */
    serpent1.position.y = valeur_aleatoire( hauteur-1); /* position du serpent suivent y */
    sens = valeur_aleatoire( nbre_sens);								/* sens de deplacement du serpent */
    
    switch(sens)
    {
      case 0:
	  				serpent1.sens = GAUCHE;
	  	break;
	  
      case 1:
	  				serpent1.sens = DROITE;
	  	break;
	  
      case 2:
	  				serpent1.sens = BAS;
	  	break;
	  
      case 3:
	  				serpent1.sens = HAUT;
	 		break;
    }
    
    return serpent1;
}

/*-------------------------------remplissage du tableau---------------------------------*/

void remplir_tab( char tab[], unsigned int hauteur, unsigned int largeur, serpent snake)
{
    switch(snake.sens)
    {
      case GAUCHE:
	  							tab[largeur*(snake.position.y )+ (snake.position.x)]='<';
	  	break;
	  
      case DROITE:
	  							tab[largeur*(snake.position.y )+ (snake.position.x)]='>';
	  	break;
	  
      case BAS:
	  							tab[largeur*(snake.position.y )+ (snake.position.x)]='v';
	  	break;
	  
      case HAUT:
	  							tab[largeur*(snake.position.y )+ (snake.position.x)]='^';
	  	break;
    }
}


/*----------fonction deplacement tout droit---------------------------*/
unsigned int avancer( char tab[], unsigned int largeur, unsigned int hauteur, serpent *snake)
{
		
		switch(snake->sens)
    {
      case	GAUCHE:
					 	if((snake->position.x >0)&&(tab[largeur*(snake->position.y )+ (snake->position.x -1)]==' '))
						{
								snake->position.x --;
								tab[largeur*(snake->position.y )+ (snake->position.x)]= '<';
								return 0;
						}
	  				else
	  				{
	  						return 1;	
	  				}
	  	break;
	  
      case	DROITE:
      			if((snake->position.x < largeur-1)&&(tab[largeur*(snake->position.y )+ (snake->position.x +1)]==' '))
						{
								snake->position.x ++;
								tab[largeur*(snake->position.y )+ (snake->position.x)]= '>';
								return 0;
						}
	  				else
	  				{
	  						return 1;	
	  				}
	  	break;
	  
      case	BAS:
      			if((snake->position.y < hauteur-1)&&(tab[largeur*(snake->position.y +1 )+ (snake->position.x)]==' '))
						{
								snake->position.y ++;
								tab[largeur*(snake->position.y )+ (snake->position.x)]= 'v';
								return 0;
						}
	  				else
	  				{
	  						return 1;	
	  				}
	  			
	  	break;
	  
      case	HAUT:
      			if((snake->position.y >0)&&(tab[largeur*(snake->position.y -1 )+ (snake->position.x)]==' '))
						{
								snake->position.y --;
								tab[largeur*(snake->position.y )+ (snake->position.x)]= '^';
								return 0;
						}
	  				else
	  				{
	  						return 1;	
	  				}
	  				
	  	break;
    }
    return 1;
}

/*----------fonction deplacement vers la gauche---------------------------*/

unsigned int tourner_gauche( char tab[], unsigned int largeur, unsigned int hauteur, serpent *snake)
{
		switch(snake->sens)
    {
      case	GAUCHE:
					 	if((snake->position.y < hauteur -1)&&(tab[largeur*(snake->position.y +1 )+ (snake->position.x)]==' '))
						{
								snake->position.y ++;
								tab[largeur*(snake->position.y )+ (snake->position.x)]= 'v';
								snake->sens = BAS;
								return 0;
						}
	  				else
	  				{
	  						return 1;	
	  				}
	  	break;
	  
      case	DROITE:
      			if((snake->position.y > 0)&&(tab[largeur*(snake->position.y -1)+ (snake->position.x)]==' '))
						{
								snake->position.y --;
								tab[largeur*(snake->position.y )+ (snake->position.x)]= '^';
								snake->sens = HAUT;
								return 0;
						}
	  				else
	  				{
	  						return 1;	
	  				}
	  	break;
	  
      case	BAS:
      			if((snake->position.x < largeur-1)&&(tab[largeur*(snake->position.y)+ (snake->position.x+1)]==' '))
						{
								snake->position.x++;
								tab[largeur*(snake->position.y )+ (snake->position.x)]= '>';
								snake->sens = DROITE;
								return 0;
						}
	  				else
	  				{
	  						return 1;	
	  				}
	  			
	  	break;
	  
      case	HAUT:
      			if((snake->position.x >0)&&(tab[largeur*(snake->position.y )+ (snake->position.x -1)]==' '))
						{
								snake->position.x --;
								tab[largeur*(snake->position.y )+ (snake->position.x)]= '<';
								snake->sens = GAUCHE;
								return 0;
						}
	  				else
	  				{
	  						return 1;	
	  				}
	  				
	  	break;
    }
		return 1;
}

/*----------fonction deplacement vers la droite---------------------------*/

unsigned int tourner_droite( char tab[], unsigned int largeur, unsigned int hauteur, serpent *snake)
{
		switch(snake->sens)
    {
      case	GAUCHE:
					 	if((snake->position.y > 0)&&(tab[largeur*(snake->position.y -1 )+ (snake->position.x)]==' '))
						{
								snake->position.y --;
								tab[largeur*(snake->position.y )+ (snake->position.x)]= '^';
								snake->sens = HAUT;
								return 0;
						}
	  				else
	  				{
	  						return 1;	
	  				}
	  	break;
	  
      case	DROITE:
      			if((snake->position.y < hauteur -1)&&(tab[largeur*(snake->position.y +1)+ (snake->position.x)]==' '))
						{
								snake->position.y ++;
								tab[largeur*(snake->position.y )+ (snake->position.x)]= 'v';
								snake->sens = BAS;
								return 0;
						}
	  				else
	  				{
	  						return 1;	
	  				}
	  	break;
	  
      case	BAS:
      			if((snake->position.x >0)&&(tab[largeur*(snake->position.y)+ (snake->position.x-1)]==' '))
						{
								snake->position.x--;
								tab[largeur*(snake->position.y )+ (snake->position.x)]= '<';
								snake->sens = GAUCHE;
								return 0;
						}
	  				else
	  				{
	  						return 1;	
	  				}
	  			
	  	break;
	  
      case	HAUT:
      			if((snake->position.x < largeur -1)&&(tab[largeur*(snake->position.y )+ (snake->position.x +1)]==' '))
						{
								snake->position.x ++;
								tab[largeur*(snake->position.y )+ (snake->position.x)]= '>';
								snake->sens = DROITE;
								return 0;
						}
	  				else
	  				{
	  						return 1;	
	  				}
	  				
	  	break;
    }
		return 1;
}

/*---------------*affichage du tableau--------------------------------*/
void affichage_cadre(unsigned int largeur, unsigned int hauteur,char tab[])
{

    unsigned int i, j;

  /*delimitation du cadrant superieur*/
    for(i=0; i< largeur+2 ; i++)
    {
				printf("#");
    }
    printf("\n");

    for(i=0; i< hauteur ; i++)
    {
				printf("#");
				for(j=0; j<largeur; j++)
				{
	     			printf("%c",tab[i*largeur+j]);/**/
				}
				printf("#\n");
    }
    
  /*délimitation du cadrant inferieur*/
    for(i=0; i< largeur+2 ; i++)
    {
				printf("#");
    }
    printf("\n");
}

/*---------------------------tirage d'une valeur aleatoire------------------------------*/

unsigned int valeur_aleatoire( unsigned int position)
{
    unsigned int resultat=0; 
    srand ( time( NULL) );
    resultat= ( unsigned int)( ( double ) rand () / ( (double ) RAND_MAX ) * (position) );
    return resultat;
}

/*-----------------------initialisation du tableau----------------------------------*/
void init_tab( unsigned int ligne, unsigned int colonne, char tab[])
{
    int i;
    for(i=0; i< colonne*ligne ; i++)
    {
				tab[i]=' ';
    }  
}


/*----------------------fonction de temporisation---------------------*/
void attente(unsigned int temps_attente)
{
      clock_t fin;
      fin = clock() + temps_attente*CLOCKS_PER_SEC/1000;
      while(clock()<fin){}
      return ;
}

/************** fonction effacer pour effacer le terminal****************/
void effacer( void)
{
		
		system( CLRSCR);
}


/***********fonction pour calculer les pourcentages d'occupation**************/

statistic statistique( unsigned int largeur, unsigned int hauteur, char tab[])
{
		statistic stat;
		
		stat.compt  = 0;/*initialisation des champs de la variable structure stat*/
		stat.haut   = 0;
		stat.bas    = 0;
		stat.gauche = 0;
		stat.droite = 0;
		
		unsigned int i;
		
		for( i=0; i< largeur*hauteur; i++)
		{
				if( tab[i]!=' ')
				{
						stat.compt++;
				}
			
				switch(tab[i])
				{
						case '^':
							 	stat.haut++;
						break;
		
						case 'v':
							 	stat.bas++;
						break;
		
						case '<':
							 	stat.gauche++;
						break;
		
						case '>':
							 	stat.droite++;
						break;
				}
		}
		
		return stat;
}
