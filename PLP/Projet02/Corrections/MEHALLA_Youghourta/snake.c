//Projet N°2 du module des principes de programmations         
// MEHALLA Youghourta


  // Declaration des bibliotheques 
  
# include <stdio.h>
# include <stdlib.h>
# include <string.h>  
# include <time.h>



# ifdef __linux__
# define CLRSCR " clear "
# else
# define CLRSCR " clr"
# endif

// Definition des directions possibles du mouvements

 enum direction {Up=94,bellow=118,right=62,left=60};
 typedef struct cSnake{
   int axe_x,axe_y;
   enum direction sens;
 }snake;

//Appel de fonction
void creationEnvironnement(int iHeight,int iWidth);  // Création de l'environnement
void eWait(unsigned int ms);  //Attente
void space_initialisation(unsigned int vertical ,unsigned int horizontal, char tab[]); //Initialisation de l'environnement 
int sens_Up( unsigned int vertical , unsigned int horizontal ,snake *eSnake, char tab[]);  // Direction vers le haut
int sens_bellow( unsigned int vertical , unsigned int horizontal ,snake *eSnake, char tab[]); //Direction vers le bas
int sens_right( unsigned int vertical , unsigned int horizontal,snake *eSnake, char tab[]);  //Direction vers la droite
int sens_left( unsigned int vertical , unsigned int horizontal ,snake *eSnake, char tab[]);  //Direction vers la gauche



// Programme Principal
int main(int argc,char **argv)
{
//Déclaration de variables
int iWidth,iHeight,nSnake,cWait;

 // Utilisation des arguments de la commande 
 
  if (argc !=4)  // On teste que le nombre d'arguments est correcte
    {
      printf("Veillez entrer les arguments a utiliser: \n");
    }
  if(argv[0][0]=='.') //test sur l'exécution du code
    {
      sscanf(argv[1],"%d x %d",&iHeight,&iWidth);
      sscanf(argv[2],"%d",&nSnake);
      sscanf(argv[3],"%d",&cWait);
    }
 printf("iWidth = %d\n",iWidth);
 printf("iHeight = %d\n",iHeight);
 printf("nSnake = %d\n",nSnake);
 printf("L'eWait est de = %d\n",cWait);
 
   //Creation de l'espace de mouvements des snakes
 snake UseSnake[nSnake];

// Initialisation de l'espace

 char cSpace [iHeight*iWidth];
 int Uses [nSnake];
 int how_Uses=0;
 int i1;
 for(i1=0; i1 < nSnake; i1++){
          Uses[i1]=0;
          }

space_initialisation( iHeight, iWidth, cSpace);

// Placement aléatoire des snakes
 int k,sens_go;
 srand(time(NULL));

 for(k=0;k<nSnake;k++){

   UseSnake[k].axe_x= rand()%iHeight ;
   UseSnake[k].axe_y= rand()%iWidth;
   sens_go=rand()%3;

    /* Trouver le sens de direction */

    switch(sens_go)
      {
      case 0 : UseSnake[k].sens=Up; 
	break;
      case 1 : UseSnake[k].sens=bellow; 
	break;
      case 2 : UseSnake[k].sens=right; 
	break;
      case 3 : UseSnake[k].sens=left; 
	break;
      }

   printf("%c\n",UseSnake[k].sens); 
   printf("%d\n",UseSnake[k].axe_x);
   printf("%d\n",UseSnake[k].axe_y);
   cSpace[UseSnake[k].axe_x*iWidth+UseSnake[k].axe_y]=UseSnake[k].sens; 
 }
// A cet étape les serpents générés sont dans un tableau
// On doit les afficher

 space_initialisation( iHeight, iWidth,cSpace);    
 
 while(how_Uses != nSnake){      // Test sur la liberté de mouvements des snakes
 
 // La boucle ci-dessous défini les déplacements des snakes

   for(k=0;k<nSnake;k++){             
                            switch(UseSnake[k].sens){
                                        case Up : Uses[k]=sens_Up(iHeight,iWidth,&UseSnake[k],cSpace);
                                        break;
                                        case bellow: Uses[k]=sens_bellow(iHeight,iWidth,&UseSnake[k],cSpace) ;
                                        break;
                                        case right : Uses[k]=sens_right(iHeight,iWidth,&UseSnake[k],cSpace) ; 
                                        break;
                                        case left : Uses[k]=sens_left(iHeight,iWidth,&UseSnake[k],cSpace);
                                        break;
                                        }
                     }
                      int i2;
                      how_Uses=0;
                      for(i2=0; i2 < nSnake; i2++){
			how_Uses=how_Uses+Uses[i2]; 
                               }
		      eWait(cWait); 
		      system( CLRSCR );        
                      space_initialisation( iHeight, iWidth,cSpace); 

                     }

                                 
                                           
            
                          
 return 0;
   } 
 

// Définition des codes des fonctions utilisées dans le main
 
void creationEnvironnement(int iHeight,int iWidth)
{
 //Création de l'espace de mouvements des snakes
    
 char cSpace [iHeight*iWidth];  
 int i,j;

 for(i=0;i<iHeight;i++)
   {

     if(i==0){    
              for(j=0;j<iWidth;j++){
       	                              cSpace[i*j]='#';
	                              printf ("%c",cSpace[i*j]);	 
                                     }
              printf("\n");
     }
 
     if((i!=0)||(i!=iHeight-1)){

                                 cSpace[i*0]='#';
                                 printf ("%c",cSpace[i*0]);

                                 for(j=1;j<iWidth-1;j++){
	                                                   cSpace[i*j]=' ';
	                                                   printf ("%c",cSpace[i*j]);
				 }
                                                           
	                         cSpace[i*iWidth-1]='#';
	                         printf ("%c",cSpace[i*iWidth-1]);
	                         printf("\n");
     }

    if(i==iHeight-1){
                      for(j=0;j<iWidth;j++){
	                                      cSpace[iHeight-1*j]='#';
	                                      printf ("%c",cSpace[iHeight-1*j]);
		      }
      
    }
   }    
     
     
     
    return ; 
}
// Création d'une fonction distinée à faire fonctionner le programme au ralenti
void eWait(unsigned int ms)
{
      clock_t fin;
      fin = clock() + ms*CLOCKS_PER_SEC/1000;
      while(clock()<fin){}
      return ;
}
//Définition de la fonction qui initialise l'espace de mouvement des snakes
void space_initialisation( unsigned int vertical , unsigned int horizontal , char tab[]){
     int i,j;

 for(i=0;i<horizontal+2;i++){
                        printf("#");
                        }
 printf("\n");
 for(i=0; i< vertical ; i++){
                         printf("#");
	                     for(j=0; j<horizontal; j++){
                                                printf("%c",tab[i*horizontal+j]);
                                                }
                         printf("#\n");
                         }
 for(i=0; i< horizontal+2 ; i++){
                            printf("#");
                            }
 
 printf("\n");
}

//Définition des fonctions du déplacement des snakes: 
// Déplacement vers le Up
/* fonction deplacement sens Up*/
int sens_Up( unsigned int vertical , unsigned int horizontal ,snake *eSnake, char tab[]){
     int HOW;
     if(tab[(eSnake->axe_x-1)*horizontal+(eSnake->axe_y)]==' '){
                                    tab[(eSnake->axe_x-1)*horizontal+(eSnake->axe_y)]=Up;
                                    eSnake->axe_x=(eSnake->axe_x)-1;
                                    eSnake->axe_y=(eSnake->axe_y);
                                    eSnake->sens=(eSnake->sens);
                                    HOW=0;
                                    }
                                    else if(tab[(eSnake->axe_x)*horizontal+(eSnake->axe_y)-1]==' '){
                                         tab[(eSnake->axe_x)*horizontal+(eSnake->axe_y)-1]=left;
                                         eSnake->axe_x=(eSnake->axe_x);
                                         eSnake->axe_y=(eSnake->axe_y)-1;
                                         eSnake->sens=left;
                                         HOW=0;
                                         }
                                         else if(tab[(eSnake->axe_x)*horizontal+(eSnake->axe_y)+1]==' '){
                                              tab[(eSnake->axe_x)*horizontal+(eSnake->axe_y)+1]=right;
                                              eSnake->axe_x=(eSnake->axe_x);
                                              eSnake->axe_y=(eSnake->axe_y)+1;
                                              eSnake->sens=right;
                                              HOW=0;
                                              }
                                              else{
                                                   HOW=1;
                                                   }
                                                   return HOW;
                                    
     }
     /* fonction deplacement sens bellow*/
int sens_bellow( unsigned int vertical , unsigned int horizontal ,snake *eSnake, char tab[]){
     int HOW;
     if(tab[(eSnake->axe_x+1)*horizontal+eSnake->axe_y]==' '){
                                    tab[(eSnake->axe_x+1)*horizontal+eSnake->axe_y]=bellow;
                                    eSnake->axe_x=(eSnake->axe_x)+1;
                                    eSnake->axe_y=(eSnake->axe_y);
                                    eSnake->sens=(eSnake->sens);
                                    HOW=0;
                                    }
                                    else if(tab[(eSnake->axe_x)*horizontal+(eSnake->axe_y)+1]==' '){
                                         tab[(eSnake->axe_x)*horizontal+(eSnake->axe_y)+1]=right;
                                         eSnake->axe_x=(eSnake->axe_x);
                                         eSnake->axe_y=(eSnake->axe_y)+1;
                                         eSnake->sens=right;
                                         HOW=0;
                                         }
                                         else if(tab[(eSnake->axe_x)*horizontal+(eSnake->axe_y)-1]==' '){
                                              tab[(eSnake->axe_x)*horizontal+(eSnake->axe_y)-1]=left;
                                              eSnake->axe_x=(eSnake->axe_x);
                                              eSnake->axe_y=(eSnake->axe_y)-1;
                                              eSnake->sens=left;
                                              HOW=0;
                                              }
                                              else{
                                                   HOW=1;
                                                   }
                                                   return HOW;
                                    
     }

/* fonction deplacement sens right*/
int sens_right( unsigned int vertical , unsigned int horizontal ,snake *eSnake, char tab[]){
     int HOW;
     if(tab[(eSnake->axe_x)*horizontal+(eSnake->axe_y)+1]==' '){
                                    tab[(eSnake->axe_x)*horizontal+(eSnake->axe_y)+1]=right;
                                    eSnake->axe_x=(eSnake->axe_x);
                                    eSnake->axe_y=(eSnake->axe_y)+1;
                                    eSnake->sens=(eSnake->sens);
                                    HOW=0;
                                    }
                                    else if(tab[((eSnake->axe_x)-1)*horizontal+(eSnake->axe_y)]==' '){
                                         tab[((eSnake->axe_x)-1)*horizontal+(eSnake->axe_y)]=Up;
                                         eSnake->axe_x=(eSnake->axe_x)-1;
                                         eSnake->axe_y=(eSnake->axe_y);
                                         eSnake->sens=Up;
                                         HOW=0;
                                         }
                                         else if(tab[((eSnake->axe_x)+1)*horizontal+(eSnake->axe_y)]==' '){
                                              tab[((eSnake->axe_x)+1)*horizontal+(eSnake->axe_y)]=bellow;
                                              eSnake->axe_x=(eSnake->axe_x)+1;
                                              eSnake->axe_y=(eSnake->axe_y);
                                              eSnake->sens=bellow;
                                              HOW=0;
                                              }
                                              else{
                                                   HOW=1;
                                                   }
                                                   return HOW;
                                    
     }
     
/* fonction deplacement sens left*/
int sens_left( unsigned int vertical , unsigned int horizontal,snake *eSnake, char tab[]){
     int HOW;
     if(tab[(eSnake->axe_x)*horizontal+(eSnake->axe_y)-1]==' '){
                                    tab[(eSnake->axe_x)*horizontal+(eSnake->axe_y)-1]=left;
                                    eSnake->axe_x=(eSnake->axe_x);
                                    eSnake->axe_y=(eSnake->axe_y)-1;
                                    eSnake->sens=(eSnake->sens);
                                    HOW=0;
                                    }
                                    else if(tab[((eSnake->axe_x)+1)*horizontal+(eSnake->axe_y)]==' '){
                                         tab[((eSnake->axe_x)+1)*horizontal+(eSnake->axe_y)]=bellow;
                                         eSnake->axe_x=(eSnake->axe_x)+1;
                                         eSnake->axe_y=(eSnake->axe_y);
                                         eSnake->sens=bellow;
                                         HOW=0;
                                         }
                                         else if(tab[((eSnake->axe_x)-1)*horizontal+(eSnake->axe_y)]==' '){
                                              tab[((eSnake->axe_x)-1)*horizontal+(eSnake->axe_y)]=Up;
                                              eSnake->axe_x=(eSnake->axe_x)-1;
                                              eSnake->axe_y=(eSnake->axe_y);
                                              eSnake->sens=Up;
                                              HOW=0;
                                              }
                                              else{
                                                   HOW=1;
                                                   }
                                                   return HOW;
                                    
     }



