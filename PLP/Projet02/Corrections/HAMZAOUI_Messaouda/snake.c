#include<stdio.h>
#include<stdlib.h>
#include<time.h>
   

typedef enum eDirection{haut,bas,gauche,droite}Direction;             /*definition des differentes directions que doit                                                                                 prendre le serpent*/

void retard(unsigned int time)      /*création de la variable retard qui va arreter le programme pendant un certain laps                                                               de temps defini */
{
   unsigned int f=clock();                          
   unsigned int tempsclock=0;
   tempsclock=time*CLOCKS_PER_SEC/1000;
   while(clock()<f+tempsclock);
   return;
   }
       
typedef struct{int y,x,direct,etat;       
                       }Serpents;   


      
int main (int argc, char ** argv)
{
  int Nsnake;          
  int i,j;
  int test;
  int largeur,hauteur;
                        
 

 sscanf (argv[1] ,"%i * %i", &largeur,&hauteur);   /*lecture des arguments donnant la largeur,la hauteur,et
                                                                          le nombre de serpents */  
 sscanf( argv[2] ,"%i",&Nsnake);
 

   int debut[Nsnake]; 
   int choix;
   Serpents S[Nsnake];
   char cadre[hauteur+2][largeur+2];
   int deptligne[hauteur];                           
   int deptcolonne [largeur];   
                              

 for(i=1;i<hauteur+1;i++)                           
   for(j=1;j<largeur+1;j++)
     cadre[i][j]=' ';
 for(i=0;i<hauteur+2;i++)                      
   {cadre[i][0]='*';
     cadre[i][largeur+1]='*';
   }  
 for (i=0; i<largeur+2;i++)
   {cadre[0][i]= '*';
     cadre[hauteur+1][i]='*';  
   }                           


 for(i=0;i<largeur;i++)                     /*utilisation de la fonction random qui injecte les serpents aléatoirement dans                                                                   l'environnement*/                              
   {deptcolonne[i]=i+1;}
 for(i=0;i<Nsnake;i++)
   {choix=rand()%(largeur-i);
     S[i].y=deptcolonne[choix];
     deptcolonne[choix]=deptcolonne[largeur-i];
   }
 for(i=0;i<hauteur;i++)   
   {deptligne[i]=i+1;}           
 for(i=0;i<Nsnake;i++)
   {choix=rand()%(hauteur-i);
     S[i].x=deptligne[choix];
     deptligne[choix]=deptligne[hauteur-i];
   }
 for(i=0;i<Nsnake;i++)
   {S[i].direct=rand()%4;
   }

   
 for(i=0;i<Nsnake;i++)
   {                           /*definition des differentes directions pour tout les serpents et des caractéres qui                                                             symbolisent les directions des serpents */  
     switch(S[i].direct)          
       {case haut:
	   { cadre[S[i].x][S[i].y]='^';
	   break;}
       case bas:
	 { cadre[S[i].x][S[i].y]='v';
	     break;}
       case gauche:
	 { cadre[S[i].x][S[i].y]='<';
	   break;}
       case droite:
	 { cadre[S[i].x][S[i].y]='>';
	   break;}
       }
   }

 unsigned int time;                      /*declaration de la variable temps */
 sscanf(argv[3],"%d",&time);
  
 for(i=0;i<Nsnake;i++)
   S[i].etat=1;

 int continuer;  /*la variable continuer sert a determiner si les serpents sont bloqués ou pas,tant qu'un serpent n'est pas                           bloqué le programme continue et il s'arrete quand tout les serpents sont bloqués*/
 continuer=1;
 
 while(continuer)
   {test=0;             
     for(i=0;i<Nsnake;i++)                           
     
       {switch(S[i].direct) /*differentes directions des serpents qui se deplacent toujours a gauche tant que les cases                                                           sont libre si non ils se deplacent a droite*/
	   {case haut:      
	       {switch(cadre[(S[i].x)-1][(S[i].y)])
		 {case ' ':                                   
		     { cadre[(S[i].x)-1][(S[i].y)]='^';
		     S[i].x -- ;                             
	
		break; }
		 default:                                    
		   {switch(cadre[(S[i].x)][(S[i].y)-1]) 
                                                                  
		     {case ' ':                                  
			 { cadre[(S[i].x)][(S[i].y)-1]='<';  
			  S[i].y-- ;
			  S[i].direct=2;                            
			  			
			break;
			}
		    default:
		      {switch(cadre[(S[i].x)][(S[i].y)+1])
			    {case ' ':
				{ cadre[(S[i].x)][(S[i].y)+1]='>';
				S[i].y ++ ;
				S[i].direct=3;
			
				
				break;}
				
				default:
				  { S[i].etat=0;
				    break;
				  }
			    }
			  break;  }
		    }
		   break; }
	     }
	   break; }
	   
       case bas:
	 {switch(cadre[(S[i].x)+1][(S[i].y)])
	     {case ' ':
		 { cadre[(S[i].x)+1][(S[i].y)]='v';
		S[i].x++ ;
		
		break; }
	     default:  
	       {switch(cadre[(S[i].x)][(S[i].y)-1])
		    {case ' ':
			{ cadre[(S[i].x)][(S[i].y)-1]='<';
			  S[i].y -- ;
			  S[i].direct=2;
		
			
			  break;}
		    default:
		      {switch(cadre[(S[i].x)][(S[i].y)+1])
			    {case ' ':
				{ cadre[(S[i].x)][(S[i].y)+1]='>';
				S[i].y ++;
				S[i].direct=3;
			
				
				break;}
			    default:
			      { S[i].etat=0;
				  break;}
			    }
			  break; }
		    }
		   break; }
	     }
	 
	     break;}
     case gauche:
       {switch(cadre[(S[i].x)][(S[i].y)-1])
	     {case ' ':
		 { cadre[(S[i].x)][(S[i].y)-1]='<';
		S[i].y-- ;
		break;}
	     default:  
	       {switch(cadre[(S[i].x)+1][(S[i].y)])
		    {case ' ':
			{ cadre[(S[i].x)+1][(S[i].y)]='v';
			  S[i].x++ ;
			  S[i].direct=1;
			
			  break;}
		    default:
		      {switch(cadre[(S[i].x)-1][(S[i].y)])
			    {case ' ':
				{ cadre[(S[i].x)-1][(S[i].y)]='^';
				S[i].x --;
				S[i].direct=0;
				break;	}
			       
			    default:
			     { S[i].etat=0;
				  break;}
			      }
			  break; }
		      }
		   break; }
	        }  
	   break;}
	
 case droite:
       {switch(cadre[(S[i].x)][(S[i].y)+1])
	     {case ' ':
		 { cadre[(S[i].x)][(S[i].y)+1]='>';
		S[i].y ++ ;
		break;}
	     default:  
	       {switch(cadre[(S[i].x)-1][(S[i].y)])
		    {case ' ':
			{ cadre[(S[i].x)-1][(S[i].y)]='^';
			  S[i].x -- ;
			  S[i].direct=0;
			
			  break;}
		    default:
		      {switch(cadre[(S[i].x)+1][(S[i].y)])
			    {case ' ':
				{ cadre[(S[i].x)+1][(S[i].y)]='v';
				S[i].x ++;
				S[i].direct=1;
			       
				break;}
			    default:
			      { S[i].etat=0;
				  break;}
			    }
			  break; }
		    }
		   break; }
	     }
       
	 break;}
       }
   }
     for(i=0;i<Nsnake;i++) 
       {if(S[i].etat==0)                  
	   {test+=1;}     
       }

     if(test==Nsnake)  
       {continuer=0;}   
     else continuer=1;    
   
     retard(time); 
#ifdef __linux__             /*cette fonction permet d'effacer l'ecrance qui est indispensable pour suivre la trajectoire                                                         des serpents*/
#define CLRSCR "clear"                          
# else
#define CLRSCR "clr"
#endif
    
 system(CLRSCR);   

     for(i=0;i<hauteur+2;i++)        
       { for(j=0;j<largeur+2;j++)        /*impression de l'environnement ou se deplace les serpents*/       
	 printf("%c",cadre[i][j]);
	 printf("\n");
       }

} 
 return 0;
}





