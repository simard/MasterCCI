
/*********   M2P  CCI    ********/

/********* Nom : AMRIOU *********/

/***** Prenom : Mohamed Reda ****/

/** Projet 2 : Snake (Serpent) **/


/* Declaration des bibliothéques de travail */

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>

/* Definition de l'environnement d'exploitation pour la fonction system() */

# ifdef __linux__
# define CLRSCR " clear "
# else
# define CLRSCR " cls"
# endif

/* directions */

//enum direction {UP1,DOWN1,RIGHT1,LEFT1};
enum direction 
{
	UP=94,
	DOWN=118,
	RIGHT=62,
	LEFT=60
};

typedef struct
{
	int xposition,yposition;
	enum direction sens;
}
serpent;

/* Declaration des fonctions du programme */

void init_environnement(unsigned int colonne ,unsigned int ligne, char tab[]); 
void init_tableau( unsigned int colonne , unsigned int ligne, char tab[]);
void attente(int t_attente);

int depl_sens_haut( unsigned int colonne , unsigned int ligne ,serpent *serp, char tab[]);
int depl_sens_bas( unsigned int colonne , unsigned int ligne ,serpent *serp, char tab[]);
int depl_sens_droite( unsigned int colonne , unsigned int ligne,serpent *serp, char tab[]);
int depl_sens_gauche( unsigned int colonne , unsigned int ligne ,serpent *serp, char tab[]);


/* Programme principale */

int main (int argc , char** argv)
{

	int ilargeur,ihauteur,nbserpents,temps_attente;

	/* recuperation des arguments de la commande */

	if (argc !=4)  /* teste si le nombre d'arguments est egale a celui specifier pour snake */
	{
		printf("entrer tout vos arguments\n");
	}
	if(argv[0][0]=='.')
	{
		sscanf(argv[1],"%dx%d",&ihauteur,&ilargeur);
		sscanf(argv[2],"%d",&nbserpents);
		sscanf(argv[3],"%d",&temps_attente);
	}
	printf("ilargeur = %d\n",ilargeur);
	printf("ihauteur = %d\n",ihauteur);
	printf("nbserpents = %d\n",nbserpents);
	printf("temps d'attente = %d\n",temps_attente);

	serpent stab[nbserpents];

	/* initialisation de l'environnement */

	char cEchiquier [ihauteur*ilargeur];
	int blocage [nbserpents];
	int somme_blocage=0;
	int t;
	for(t=0; t < nbserpents; t++)
	{
		blocage[t]=0;
	}
	init_tableau( ihauteur, ilargeur, cEchiquier);

	/* Generation et placement des serpents */

	int k,dir;
	srand(time(NULL));

	for(k=0;k<nbserpents;k++)
	{
		stab[k].xposition= rand()%ihauteur ;
		stab[k].yposition= rand()%ilargeur;
		dir=rand()%3;

		/* Trouver le sens de direction */

		switch(dir)
		{
			case 0 : stab[k].sens=UP; 
							 break;
			case 1 : stab[k].sens=DOWN; 
							 break;
			case 2 : stab[k].sens=RIGHT; 
							 break;
			case 3 : stab[k].sens=LEFT; 
							 break;
		}

		printf("%c\n",stab[k].sens); 
		printf("%d\n",stab[k].xposition);
		printf("%d\n",stab[k].yposition);
		cEchiquier[stab[k].xposition*ilargeur+stab[k].yposition]=stab[k].sens; /* Placement du serpent dans le tableau d affichage */
	}

	init_environnement( ihauteur, ilargeur,cEchiquier);    /* affichage */

	while(somme_blocage != nbserpents)
	{      /* teste si tout les serpents sont bloqués ou pas */
		for(k=0;k<nbserpents;k++)
		{             /* boucle gerant les deplacements des serpents */
			switch(stab[k].sens)
			{
				case UP : blocage[k]=depl_sens_haut(ihauteur,ilargeur,&stab[k],cEchiquier);
									break;
				case DOWN: blocage[k]=depl_sens_bas(ihauteur,ilargeur,&stab[k],cEchiquier) ;
									 break;
				case RIGHT : blocage[k]=depl_sens_droite(ihauteur,ilargeur,&stab[k],cEchiquier) ; 
										 break;
				case LEFT : blocage[k]=depl_sens_gauche(ihauteur,ilargeur,&stab[k],cEchiquier);
										break;
			}
		}
		int t;
		somme_blocage=0;
		for(t=0; t < nbserpents; t++)
		{
			somme_blocage=somme_blocage+blocage[t]; /* calcul de la variable somme_blocage */
		}
		attente(temps_attente); /* temporisation */
		system( CLRSCR );        /* effacement de l'ecran */
		init_environnement( ihauteur, ilargeur,cEchiquier); /* affichage du tableau a l'etat suivant (initial+1)*/
	}
	/* statisques du programme */


	int gh;
	int gl;
	int ha=0;
	int ba=0;
	int dr=0;
	int ga=0;
	int occupe=0;
	int vide=0;
	for(gh=0;gh<ihauteur;gh++)
	{
		for(gl=0;gl<ilargeur;gl++)
		{
			if(cEchiquier[gh*ilargeur+gl]==UP)
			{
				occupe=occupe+1;
				ha=ha+1;
			}
			else if(cEchiquier[gh*ilargeur+gl]==DOWN)
			{
				occupe=occupe+1;
				ba=ba+1;
			}
			else if(cEchiquier[gh*ilargeur+gl]==RIGHT)
			{
				occupe=occupe+1;
				dr=dr+1;
			}
			else if(cEchiquier[gh*ilargeur+gl]==LEFT)
			{
				occupe=occupe+1;
				ga=ga+1;
			}
			else if (cEchiquier[gh*ilargeur+gl]==' ')
			{
				vide=vide+1;
			}
		}
	}
	printf("%d\n",ihauteur*ilargeur);
	printf("%d\n",occupe);
	printf("%d\n",vide);

	float pourcentage,pourcentage1,pourcentage2,pourcentage3,pourcentage4;
	pourcentage= ((float)(occupe))/((float)(ilargeur*ihauteur))*100;
	printf("Le plateau est rempli a %0.1f (%d/%d) dont :\n",pourcentage,occupe,ilargeur*ihauteur);
	pourcentage1= ((float)(ha))/((float)(occupe))*100;   
	printf("- %0.1f '^' (%d/%d)\n",pourcentage1,ha,occupe);
	pourcentage2= ((float)(ba))/((float)(occupe))*100;
	printf("- %0.1f 'v' (%d/%d)\n",pourcentage2,ba,occupe);
	pourcentage3= ((float)(dr))/((float)(occupe))*100;
	printf("- %0.1f '>' (%d/%d)\n",pourcentage3,dr,occupe);
	pourcentage4= ((float)(ga))/((float)(occupe))*100;
	printf("- %0.1f '<' (%d/%d)\n",pourcentage4,ga,occupe);                                        

	return 0;
}                  
/* fin du corps principale du programme */


/* Definition de la fonction initialisation de l' environnement */

void init_environnement( unsigned int colonne , unsigned int ligne , char tab[])
{
	int i,j;
	for(i=0;i<ligne+2;i++)
	{
		printf("#");
	}
	printf("\n");
	for(i=0; i< colonne ; i++)
	{
		printf("#");
		for(j=0; j<ligne; j++)
		{
			printf("%c",tab[i*ligne+j]);
		}
		printf("#\n");
	}
	for(i=0; i< ligne+2 ; i++)
	{
		printf("#");
	}
	printf("\n");
}

/* definition de la fonction initialisation de tableau */

void init_tableau( unsigned int colonne, unsigned int ligne , char tab[])
{
	int i;
	for(i=0; i< colonne*ligne ; i++)
	{
		tab[i]=' ';
	}
}

/* definition de la fonction placement de serpents */

/*serpent placement_serpents(unsigned int colonne , unsigned int ligne)
	{
	int dir;
	srand(time(NULL));
	serpent srpt;

	srpt.xposition = rand()%colonne ;
	srpt.yposition = rand()%ligne;
	dir=rand()%3;
	switch(dir)
	{
	case 0 : srpt.sens=UP; 
	break;
	case 1 : srpt.sens=DOWN; 
	break;
	case 2 : srpt.sens=RIGHT;
	break;
	case 3 : srpt.sens=LEFT;
	break;
	}
	return srpt;
	}*/

/* Definition de la fonction d'attente */

void attente(int t_attente)
{
	clock_t fin;
	fin = clock() + t_attente*CLOCKS_PER_SEC/1000;
	while(clock()<fin){}
	return ;
}

/* Definition des fonctions de deplacement */

/* fonction deplacement sens HAUT*/

int depl_sens_haut( unsigned int colonne , unsigned int ligne ,serpent *serp, char tab[])
{
	int etat;
	if(tab[(serp->xposition-1)*ligne+(serp->yposition)]==' ')
	{
		tab[(serp->xposition-1)*ligne+(serp->yposition)]=UP;
		serp->xposition=(serp->xposition)-1;
		serp->yposition=(serp->yposition);
		serp->sens=(serp->sens);
		etat=0;
	}
	else if(tab[(serp->xposition)*ligne+(serp->yposition)-1]==' ')
	{
		tab[(serp->xposition)*ligne+(serp->yposition)-1]=LEFT;
		serp->xposition=(serp->xposition);
		serp->yposition=(serp->yposition)-1;
		serp->sens=LEFT;
		etat=0;
	}
	else if(tab[(serp->xposition)*ligne+(serp->yposition)+1]==' ')
	{
		tab[(serp->xposition)*ligne+(serp->yposition)+1]=RIGHT;
		serp->xposition=(serp->xposition);
		serp->yposition=(serp->yposition)+1;
		serp->sens=RIGHT;
		etat=0;
	}
	else
	{
		etat=1;
	}
	return etat;
}

/* fonction deplacement sens BAS*/

int depl_sens_bas( unsigned int colonne , unsigned int ligne ,serpent *serp, char tab[])
{
	int etat;
	if(tab[(serp->xposition+1)*ligne+serp->yposition]==' ')
	{
		tab[(serp->xposition+1)*ligne+serp->yposition]=DOWN;
		serp->xposition=(serp->xposition)+1;
		serp->yposition=(serp->yposition);
		serp->sens=(serp->sens);
		etat=0;
	}
	else if(tab[(serp->xposition)*ligne+(serp->yposition)+1]==' ')
	{
		tab[(serp->xposition)*ligne+(serp->yposition)+1]=RIGHT;
		serp->xposition=(serp->xposition);
		serp->yposition=(serp->yposition)+1;
		serp->sens=RIGHT;
		etat=0;
	}
	else if(tab[(serp->xposition)*ligne+(serp->yposition)-1]==' ')
	{
		tab[(serp->xposition)*ligne+(serp->yposition)-1]=LEFT;
		serp->xposition=(serp->xposition);
		serp->yposition=(serp->yposition)-1;
		serp->sens=LEFT;
		etat=0;
	}
	else
	{
		etat=1;
	}
	return etat;

}

/* fonction deplacement sens DROITE*/

int depl_sens_droite( unsigned int colonne , unsigned int ligne ,serpent *serp, char tab[])
{
	int etat;
	if(tab[(serp->xposition)*ligne+(serp->yposition)+1]==' ')
	{
		tab[(serp->xposition)*ligne+(serp->yposition)+1]=RIGHT;
		serp->xposition=(serp->xposition);
		serp->yposition=(serp->yposition)+1;
		serp->sens=(serp->sens);
		etat=0;
	}
	else if(tab[((serp->xposition)-1)*ligne+(serp->yposition)]==' ')
	{
		tab[((serp->xposition)-1)*ligne+(serp->yposition)]=UP;
		serp->xposition=(serp->xposition)-1;
		serp->yposition=(serp->yposition);
		serp->sens=UP;
		etat=0;
	}
	else if(tab[((serp->xposition)+1)*ligne+(serp->yposition)]==' ')
	{
		tab[((serp->xposition)+1)*ligne+(serp->yposition)]=DOWN;
		serp->xposition=(serp->xposition)+1;
		serp->yposition=(serp->yposition);
		serp->sens=DOWN;
		etat=0;
	}
	else
	{
		etat=1;
	}
	return etat;    
}


/* fonction deplacement sens GAUCHE*/

int depl_sens_gauche( unsigned int colonne , unsigned int ligne,serpent *serp, char tab[])
{
	int etat;
	if(tab[(serp->xposition)*ligne+(serp->yposition)-1]==' ')
	{
		tab[(serp->xposition)*ligne+(serp->yposition)-1]=LEFT;
		serp->xposition=(serp->xposition);
		serp->yposition=(serp->yposition)-1;
		serp->sens=(serp->sens);
		etat=0;
	}
	else if(tab[((serp->xposition)+1)*ligne+(serp->yposition)]==' ')
	{
		tab[((serp->xposition)+1)*ligne+(serp->yposition)]=DOWN;
		serp->xposition=(serp->xposition)+1;
		serp->yposition=(serp->yposition);
		serp->sens=DOWN;
		etat=0;
	}
	else if(tab[((serp->xposition)-1)*ligne+(serp->yposition)]==' ')
	{
		tab[((serp->xposition)-1)*ligne+(serp->yposition)]=UP;
		serp->xposition=(serp->xposition)-1;
		serp->yposition=(serp->yposition);
		serp->sens=UP;
		etat=0;
	}
	else
	{
		etat=1;
	}
	return etat;  
}
