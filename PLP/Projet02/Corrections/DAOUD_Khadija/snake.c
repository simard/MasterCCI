#include <stdio.h>
#include <stdlib.h>
#include <time.h> 


typedef struct XY {int x,y;
        } ;
        void attendre (unsigned int temps){
     unsigned int f=clock();
     unsigned int temps_clock=0;
     temps_clock=temps*CLOCKS_PER_SEC/1000;
     while(clock()<f+temps_clock);
     return;
     }

void Fonction_cadre(int iLargeur, int iHauteur, char *cEchiquier){
int i,j;

for(i=0;i<iLargeur;i++){
cEchiquier[i]='#';
}

for(i=1*iLargeur;i<(iHauteur-1)*(iLargeur);i=i+iLargeur){
cEchiquier[i]='#';
cEchiquier[i+iLargeur-1]='#';
for(j=1;j<iLargeur-1;j++){
cEchiquier[i+j]=' ';
}
}

for(i=(iHauteur-1)*(iLargeur);i<iLargeur*iHauteur;i++){
cEchiquier[i]='#';
}

for (i=0;i<iHauteur;i++){
for(j=0;j<iLargeur;j++){
printf("%c",cEchiquier[i*iLargeur+j]);
}
printf("\n");
}     
}

int gotoxy(int , int , unsigned int );
bool Fonction_deplacement_directe (char *, struct XY *, int, int, int);
bool Fonction_deplacement_droite (char *, struct XY *, int, int, int);
bool Fonction_deplacement_gauche (char *, struct XY *, int, int, int);
void Fonction_cadre(int, int, char *);
void Fonction_deplacement(char *, struct XY *, int, int); 

int main (int argc, char **argv){
unsigned int iLargeur = 0, iHauteur = 0;
int NbSerpent=0; ;
int i,j,x=0;;

sscanf (argv[1], "%d*%d*%d", &iLargeur,&iHauteur,&NbSerpent);
//iLargeur représente le nombre de colones dans le tableau 
//et iHauteur représente le nombre de ligne

char cEchiquier[iLargeur*iHauteur]; 
for(i=0;i<iHauteur;i++){
for(j=0;j<iHauteur;j++){
cEchiquier[i*iHauteur+j]='\0';

}
}

Fonction_cadre(iHauteur, iLargeur, cEchiquier);

struct XY Poitions_Serpents[NbSerpent];
bool Egaux;

for(i=0;i<NbSerpent;i++){
do{   
                    
srand(rdtsc());
Poitions_Serpents[i].x=1+rand()%iLargeur-2;//les lignes, x compris entre 1 et iLargeur-2
Poitions_Serpents[i].y=1+rand()%iHauteur-2;//les colonnes, y compris entre 1 et iHauteur-2

Egaux=false;

for (j=0;j<i;j++){
    if (Poitions_Serpents[j].x==Poitions_Serpents[i].x && Poitions_Serpents[j].y==Poitions_Serpents[i].y) Egaux=true; 
}//for j

}//do
while (Egaux=true);
}//for i

int position=0;

for (i=0;i<NbSerpent;i++){

position = gotoxy(Poitions_Serpents[i].x, Poitions_Serpents[i].y, iLargeur);
cEchiquier[position]='>';
}

Fonction_deplacement (cEchiquier, Poitions_Serpents, NbSerpent, iLargeur);

return 0;

}


int gotoxy(int x, int y, unsigned int iLargeur)
{
 
return (y*iLargeur+x); 
/* cette fonction retourne la position dans le tableau cEchiquier unidimentionnel*/ 

}

void Fonction_deplacement(char *cEchiquier, struct XY *Poitions_Serpents, int NbSerpent, int iLargeur){
int position=0;
int k=0;
bool fin_deplacement=false;
bool etat=false;
int i;
char tete;

do {
    
for (i=0;i<NbSerpent;i++){
    
position = gotoxy(Poitions_Serpents[i].x, Poitions_Serpents[i].y, iLargeur); 

etat = Fonction_deplacement_directe (cEchiquier, Poitions_Serpents, position,  iLargeur, i);
if (etat==true);
else {
     etat = Fonction_deplacement_droite (cEchiquier, Poitions_Serpents, position, iLargeur, i)==true;   
     if (etat==true);
     else {
          etat =Fonction_deplacement_gauche (cEchiquier, Poitions_Serpents, position, iLargeur, i)==true;
          if (etat==true);
          else k++;
          }
          }
}

}while(k<NbSerpent);// on continue jusqu'à l'arret de tt les serpents

}
bool Fonction_deplacement_directe (char *cEchiquier, struct XY  *Poitions_Serpents, int position, int iLargeur, int i){
char tete;
tete = cEchiquier[position];
switch (tete){
       case '>' : {
            if (cEchiquier[position+1]==' ') {
                                             
                                              cEchiquier[position+1]='>';
                                              Poitions_Serpents[i].x=Poitions_Serpents[i].x+1;
                                              
                                                  }
                                                  
  }
       case 'V' :{
            if (cEchiquier[position+iLargeur]==' ') {
                                                 cEchiquier[position+iLargeur]='V';
                                              Poitions_Serpents[i].y=Poitions_Serpents[i].y+1;
                                              
                                             }
   }
       case 'V' :{
            if (cEchiquier[position+iLargeur]==' ') {
                                             
                                              cEchiquier[position+iLargeur]='V';
                                              Poitions_Serpents[i].y=Poitions_Serpents[i].y+1;
                                              
                                             }
            

}
       case '<' :{
            if (cEchiquier[position-1]==' ') {
                                             
                                              cEchiquier[position-1]='<';
                                              Poitions_Serpents[i].x=Poitions_Serpents[i].x-1;
                                              
                                             }
                                             
    }
            
       case '^' :{
            if (cEchiquier[position-iLargeur]==' ') {
                                             
                                              cEchiquier[position-iLargeur]='^';
                                              Poitions_Serpents[i].y=Poitions_Serpents[i].y-1;
                                              
                                             }
                                             
           }
}//fin switch

return true; 

}


bool Fonction_deplacement_droite (char *cEchiquier, struct XY  *Poitions_Serpents, int position, int iLargeur, int i){
char tete;
tete = cEchiquier[position];
switch (tete){
       
       case '>' : {
            if (cEchiquier[position+iLargeur]==' ') {
                                             
                                              cEchiquier[position+iLargeur]='V';
                                              Poitions_Serpents[i].y=Poitions_Serpents[i].y+1;
                                              
                                             }
            
       }
       case 'V' :{
            if (cEchiquier[position-1]==' ') {
                                             
                                              cEchiquier[position-1]='<';
                                              Poitions_Serpents[i].x=Poitions_Serpents[i].x-1;
                                              
                                             }
                                             
         };
       case '<' :{
            if (cEchiquier[position-iLargeur]==' ') {
                                             
                                              cEchiquier[position-iLargeur]='^';
                                              Poitions_Serpents[i].y=Poitions_Serpents[i].y-1;
                                              
                                             }
                                   
                                    };
                                    
         
          case '^' :{
            if (cEchiquier[position+1]==' ') {
                                             
                                              cEchiquier[position+1]='>';
                                              Poitions_Serpents[i].x=Poitions_Serpents[i].x+1;
                                              
                                             }
                                             
     };
}//fin switch

return true; 

}

bool Fonction_deplacement_gauche (char *cEchiquier, struct XY  *Poitions_Serpents, int position, int iLargeur, int i){
char tete;
tete = cEchiquier[position];
switch (tete){
       case '>' : {
            if (cEchiquier[position-iLargeur]==' ') {
                                                 
                                                 cEchiquier[position-iLargeur]='^';
                                              Poitions_Serpents[i].y=Poitions_Serpents[i].y-1;
                                              
                                             }
             }
       case 'V' :{
            if (cEchiquier[position+1]==' ') {
                                             
                                              cEchiquier[position+1]='>';
                                              Poitions_Serpents[i].x=Poitions_Serpents[i].x+1;
                                              
                                             }
                                             
        }
       case '<' :{
            if (cEchiquier[position+iLargeur]==' ') {
                                                 cEchiquier[position+iLargeur]='V';
                                              Poitions_Serpents[i].y=Poitions_Serpents[i].y+1;
                                              
                                             }
                                             
        }
            
       case '^' :{
            if (cEchiquier[position-1]==' ') {
                                             
                                              cEchiquier[position-1]='<';
                                              Poitions_Serpents[i].x=Poitions_Serpents[i].x-1;
                                              
                                             }
                                             
   }
}//fin switch

return true; 

}



                                             
          
          
                                             
                                             
                    
                                             
