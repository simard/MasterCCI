#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef enum eDirect{gauche,droite,hau,bas}Direct;  /*définition des direction avec la forme enum*/

typedef struct{int y,x,d;        /* declarer un nouveau type de variable qui est 'serps' tel que serps[i].x est l'indice de ligne*/
		}Serps;       /*du serpent i,serps[i].y est l'indice de colonne du serpent i, et enfin serps[i].d est l'indice */                                      /*de direction.                                  */                  


void attendre(unsigned int temps)                    /* création de la fontion attendre qui va faire attendre pendant une période égale*/ 
 {
   unsigned int f=clock();                           /* a 'temps' ms.*/
   unsigned int tempsclock=0;
   tempsclock=temps*CLOCKS_PER_SEC/1000;
   while(clock()<f+tempsclock)
     ;
   return;
   }

typedef struct{int k,h;         /* on créer un nouveau type de varieble pour définir les lieu où on va mettre des obstacles dans le cadre*/
                     }obstacles;




int main (int argc, char ** argv)
{int x;
  int larg,haut;
  int Nserps;                   /* larg est la largeur du cadre, haut est la hauteur du cadre, Nserps est le nombre de serpent a mettre*/
  int i,j;                       /* dans le cadren ,Nobstacles est le nombre des obstacles a mettre dans le cadre */
  int Nobstacles;      /* toutes ces variables sont à récupérées lors la compilation */
 

  sscanf (argv[1] ,"%i * %i", &larg,&haut);                   /*récupération des données entrées lors de l'éxecution du programme*/
  sscanf( argv[2] ,"%i",&Nserps);
  sscanf(argv[4],"%i",&Nobstacles);

   obstacles obsta[Nobstacles];
   Serps serpents[Nserps];
   char tab [haut+2][larg+2];
   int choixligne[haut];                            /* déclaration de different variable qu'on va utilisé au cours du programmes */
   int choixcolonne[larg];                      /* tel que: le tableau serpents qui de type Serps qui contients les information des */
   int start[Nserps];                      /* serpent existants, les tableau choixligne et choix colonne ainsi que start qui vont etres */
   int a;                                   /* afin de donner aux serpent leurs direction et les lieux de départ d'une façon aléatoire*/
                                            /* et enfin le tableau tab qui est la matrice où vont se deplacer les serpents*/ 
 for (i=0; i<larg+2;i++)
   {tab[0][i]= '#';
     tab[haut+1][i]='#';                         /*les trois boucles suivantes vont créer le cadre entouré des caractères '#' et dedans */
   }                                          /* le caractère ' '=espace,en met hauteur+2 et largeur+2 afin de ne changer les tailles */
 for(i=0;i<haut+2;i++)                        /* demandées par l'uilisateur.*/
   {tab[i][0]='#';
     tab[i][larg+1]='#';
   }
 for(i=1;i<haut+1;i++)                               
   for(j=1;j<larg+1;j++)
     tab[i][j]=' ';


 for(i=0;i<haut;i++)              /*les boucles suivantes ce sont des boucles utilisées pour donner les lieux de départ ainsi */
   {choixligne[i]=i+1;}           /* les directions en utilisant la fonction random et ça pour données un air aléatoir.*/
 for(i=0;i<Nserps;i++)
   {a=rand()%(haut-i);
     serpents[i].x=choixligne[a];
     choixligne[a]=choixligne[haut-i];
   }
for(i=0;i<larg;i++)
   {choixcolonne[i]=i+1;}
 for(i=0;i<Nserps;i++)
   {a=rand()%(larg-i);
     serpents[i].y=choixcolonne[a];
     choixcolonne[a]=choixcolonne[larg-i];
   }
 for(i=0;i<Nserps;i++)
   {serpents[i].d=rand()%4;
   }


 int choixligobs[haut];     /*déclaration de nouvelles variables qu'on aura besoin afin de choisir les lieux des obstacles  */
 int choixcolonobs[larg];
 int w;
 for(i=0;i<haut;i++)             /* les boucles suivantes sont construites afin de choisir les lieux des obstacles d'une façon  */       
   {choixligobs[i]=i+1;}         /*  hasardeuse    */
 for(i=0;i<Nobstacles;i++)
   {w=rand()%(haut-i);
     obsta[i].k=choixligobs[w];
     choixligobs[w]=choixligobs[Nobstacles-i];
   }
 for(i=0;i<larg;i++)             
   {choixcolonobs[i]=i+1;}         
 for(i=0;i<Nobstacles;i++)
   {w=rand()%(larg-i);
     obsta[i].h=choixcolonobs[w];
     choixcolonobs[w]=choixcolonobs[Nobstacles-i];
   }
 for (i=0;i<Nobstacles;i++)
   {tab[obsta[i].k][obsta[i].h]='*';
   }






 for(i=0;i<Nserps;i++)
   {                                                  /* la boucle suivante consiste à mettre les caractère dans les case de départs*/
     switch(serpents[i].d)                           /* dans lieu de départ de chacun des serpant selon son indice de direction */   
       {case gauche:
	   { tab[serpents[i].x][serpents[i].y]='<';
	   break;}
       case droite:
	 { tab[serpents[i].x][serpents[i].y]='>';
	     break;}
       case hau:
	 { tab[serpents[i].x][serpents[i].y]='^';
	   break;}
       case bas:
	 { tab[serpents[i].x][serpents[i].y]='v';
	   break;}
       }
   }

 unsigned int temps;                   /* déclaration d'autres variables qu'on a besoin, 'temps' est un entier non signé il définit le */
 sscanf(argv[3],"%d",&temps);     /* temps que doit la fonction "attendre" mettre le programme en someil, et le tableau continuer qu'on */
                                    /* va utiliser afin de savoir es ce qu'il ya un serpent encore qui bouge ou pas et ça pour le teste */
 int continuer[Nserps];             /* du programme. */

 for(i=0;i<Nserps;i++)             /* initialisation du tableau en supposant que tout les serpants ont l'espace pour se déplacer au debut*/
   continuer[i]=1;

 int cont;         /*declaration de la variable 'cont' qui sert a rassemblée les infomation de au moins un serpents qui se déplace */
 cont=1;
 
 while(cont)         /*la boucle while sert a arrêter le programme lorsque cont=0 c'est à dire tout les serpents sont bloqués*/
   {x=0;              /* déclaration de la variable x qui nous sert a compter le nombre de serpents qui sont bloqués*/
     for(i=0;i<Nserps;i++)           /*la boucle for nous y utile pour déplacer les serpents un par un*/                
     
       {switch(serpents[i].d) /*switch teste la direction du serpent afin de savoir quel carctère qu'on va le rajouter à l'étape suivante*/
	   {case gauche:       /*le premier cas a tester c'est es que la direction est vars la gauche de l'ecran si c'est le cas*/
	       {switch(tab[serpents[i].x][(serpents[i].y)-1])/*on met une autre switch afin de tester es ce que la case suivante vers la*/
		 {case ' ':                                    /* gauche est vide ou pas si c'est le cas on ajoute le caractère essentiel*/
		 { tab[serpents[i].x][(serpents[i].y)-1]='<';
		     serpents[i].y -- ;                             /*et on decremonte l'indice de colonne .y .*/
	
		break; }
		 default:                                     /*si le cas contraire on declare une nouvelle switch pour tester les autres*/
		   {switch(tab[(serpents[i].x)+1][serpents[i].y]) /* pour que serpent tourne, en premier vers la bas c ad sa gauche,sinon*/
                                                                  /* vers sa droite cad vers le haut et a chaque fois en change l'indice */
		     {case ' ':                                   /* de ligne ou de colonne selon le deplacement du serpent ainsi que */
			 { tab[(serpents[i].x)+1][serpents[i].y]='v';  /*l'indice de direction si on change de direction bien sûr*/
			  serpents[i].x ++ ;
			  serpents[i].d=3;                            /* et cela pendant tout les teste qui suit jusqu'a leurs fin*/
			  			
			break;
			}
		    default:
		      {switch(tab[(serpents[i].x)-1][serpents[i].y])
			    {case ' ':
				{ tab[(serpents[i].x)-1][serpents[i].y]='^';
				serpents[i].x -- ;
				serpents[i].d=2;
			
				
				break;}
				
				default:
				  { continuer[i]=0;
				    break;
				  }
			    }
			  break;  }
		    }
		   break; }
	     }
	   break; }
	   
       case droite:
	 {switch(tab[serpents[i].x][(serpents[i].y)+1])
	     {case ' ':
		 { tab[serpents[i].x][(serpents[i].y)+1]='>';
		serpents[i].y ++ ;
		
		break; }
	     default:  
	       {switch(tab[(serpents[i].x)-1][serpents[i].y])
		    {case ' ':
			{ tab[(serpents[i].x)-1][serpents[i].y]='^';
			  serpents[i].x -- ;
			  serpents[i].d=2;
		
			
			  break;}
		    default:
		      {switch(tab[(serpents[i].x)+1][serpents[i].y])
			    {case ' ':
				{ tab[(serpents[i].x)+1][serpents[i].y]='v';
				serpents[i].x ++;
				serpents[i].d=3;
			
				
				break;}
			    default:
			      { continuer[i]=0;
				  break;}
			    }
			  break; }
		    }
		   break; }
	     }
	 
	     break;}
     case hau:
       {switch(tab[(serpents[i].x)-1][(serpents[i].y)])
	     {case ' ':
		 { tab[(serpents[i].x)-1][(serpents[i].y)]='^';
		serpents[i].x -- ;
		break;}
	     default:  
	       {switch(tab[(serpents[i].x)][(serpents[i].y)-1])
		    {case ' ':
			{ tab[(serpents[i].x)][(serpents[i].y)-1]='<';
			  serpents[i].y -- ;
			  serpents[i].d=0;
			
			  break;}
		    default:
		      {switch(tab[(serpents[i].x)][(serpents[i].y)+1])
			    {case ' ':
				{ tab[(serpents[i].x)][(serpents[i].y)+1]='>';
				serpents[i].y ++;
				serpents[i].d=1;
				break;	}
			       
			    default:
			     { continuer[i]=0;
				  break;}
			      }
			  break; }
		      }
		   break; }
	        }  
	   break;}
	
 case bas:
       {switch(tab[(serpents[i].x)+1][(serpents[i].y)])
	     {case ' ':
		 { tab[(serpents[i].x)+1][(serpents[i].y)]='v';
		serpents[i].x ++ ;
		break;}
	     default:  
	       {switch(tab[(serpents[i].x)][(serpents[i].y)-1])
		    {case ' ':
			{ tab[(serpents[i].x)][(serpents[i].y)-1]='<';
			  serpents[i].y -- ;
			  serpents[i].d=0;
			
			  break;}
		    default:
		      {switch(tab[(serpents[i].x)][(serpents[i].y)+1])
			    {case ' ':
				{ tab[(serpents[i].x)][(serpents[i].y)+1]='>';
				serpents[i].y ++;
				serpents[i].d=1;
			       
				break;}
			    default:
			      { continuer[i]=0;
				  break;}
			    }
			  break; }
		    }
		   break; }
	     }
       
	 break;}
       }
   }
     for(i=0;i<Nserps;i++)                    /*à cette étape là et après avoir déplacer chacun des serpent une étape on va voir*/
       {if(continuer[i]==0)                  /* es ce que il reste encore des serpent qui  ne sont pas bliqués ou pas*/
	   {x+=1;}              /* a chaque fois qu'il y a un serpent bliqué en incrémente x de 1 lui qui était initialisé a 0 au début*/
       }
     if(x==Nserps)    /*apres avoir compté le nombre des serpents bloqués on va voir es ce que le x serpents bloqués correspent au nombre*/
       {cont=0;}      /* de serpents au départ, si c'est le cas on met cont à 0 ce qui signifie l'arrêt de programme, sinon cont reste   */
     else cont=1;    /* à 1 et la procédure continue*/
   
     attendre(temps); /* là, on fait appelle à la fonction attendre, afin de laisser l'écran pendant une période égale a 'temps' en ms*/
#ifdef __linux__
#define CLRSCR "clear"                           /* création d'un fonction pour éffacer l'écran */
# else
#define CLRSCR "clr"
#endif
    
 system(CLRSCR);   /* là aussi, on fait appelle à la fonction clear screen pour éffacer l'écran, apres avoir laisser ce dernier pour*/                        /*un moment précis */

     for(i=0;i<haut+2;i++)                /* apres avoir tout fait et apporter des changement dans le tableau tab on doit l'imprimer */ 
       { for(j=0;j<larg+2;j++)                /* pour montrer les déplacements des serpents */
	 printf("%c",tab[i][j]);
	 printf("\n");
       }


 
} 
 int m=0;
 int p;
 for(i=1;i<haut+1;i++)      /* ces deux variable nous servirons a calculer le pourcentage remplis du cadre */
   {for(j=1;j<larg+1;j++)  /* les deux boucles en cascade vont calculer le pourcentage remplis */
       {if(tab[i][j]!=' ')
	   m+=1;
       }
   }
 p=m*100/(haut*larg);
 printf(" on a remplis %i pour cent du cadre\n",p);
 

 return 0;
}





