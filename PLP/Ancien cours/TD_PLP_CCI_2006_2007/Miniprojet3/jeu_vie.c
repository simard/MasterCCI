#include<stdio.h>

#define dimX 19
#define dimY 19

struct etat{
    int generation,population,present;
    int damier[2][dimX+2][dimY+2];
};

void init(struct etat *jeu){
    int i,j;
    jeu->generation=0;
    jeu->population=5;
    jeu->present=0;
    for(i=0;i<dimX+2;i++){
        for(j=0;j<dimX+2;j++){
            jeu->damier[0][i][j]=0;
        }
    }
    jeu->damier[0][(dimX-1)/2][(dimY+1)/2]=1;
    jeu->damier[0][(dimX-1)/2][(dimY+3)/2]=1;
    jeu->damier[0][(dimX+1)/2][(dimY-1)/2]=1;
    jeu->damier[0][(dimX+1)/2][(dimY+3)/2]=1;
    jeu->damier[0][(dimX+3)/2][(dimY+3)/2]=1;
}

void affichage(int tab[dimX+2][dimY+2]){
    int i,j;
    printf("\n");
    for(i=1;i<dimX+1;i++){
        for(j=1;j<dimX+1;j++){
            if(tab[i][j]==0) printf(" ");
            else printf("X");
        }
        printf("\n");
    }
}

int voisins(struct etat *jeu,int x, int y){
    int i, j, a=0;
    for(i=x-1;i<=x+1;i++){
        for(j=y-1;j<=y+1;j++){
            a=a+jeu->damier[jeu->present][i][j];
        }
    }
    a=a-jeu->damier[jeu->present][x][y];
    return a;
}

void generation(struct etat *jeu){
    int a,i,j;
    for(i=1;i<dimX+1;i++){
        for(j=1;j<dimX+1;j++){
	  if(jeu->damier[jeu->present][i][j]==0){
	    if(voisins(jeu,i,j)==3) jeu->damier[1-jeu->present][i][j]=1;
	    else jeu->damier[1-jeu->present][i][j]=0;
	  }
	  else{
	    if(voisins(jeu,i,j)==2 || voisins(jeu,i,j)==3) jeu->damier[1-jeu->present][i][j]=1;
	    else jeu->damier[1-jeu->present][i][j]=0;
	  }
	}
    }
}

void bords (struct etat *jeu){
  int i,j;
  for(i=1;i<=dimX;i++){
    jeu->damier[1-jeu->present][i][0]=jeu->damier[1-jeu->present][i][dimY];
    jeu->damier[1-jeu->present][i][dimY+1]=jeu->damier[1-jeu->present][i][1];
  }
  for(i=1;i<=dimY;i++){
    jeu->damier[1-jeu->present][0][j]=jeu->damier[1-jeu->present][dimX][j];
    jeu->damier[1-jeu->present][dimX+1][j]=jeu->damier[1-jeu->present][1][j];
  }

  jeu->damier[1-jeu->present][0][0]=jeu->damier[1-jeu->present][dimX][dimY];
  jeu->damier[1-jeu->present][dimX+1][0]=jeu->damier[1-jeu->present][1][dimY];
  jeu->damier[1-jeu->present][0][dimY+1]=jeu->damier[1-jeu->present][dimX][1];
  jeu->damier[1-jeu->present][dimX+1][dimY+1]=jeu->damier[1-jeu->present][1][1];
}

int main(){
  struct etat jeu;
  init(&jeu);
  do{
    generation(&jeu);
    bords(&jeu);
    affichage(jeu.damier[jeu.present]);
    jeu.present=1-jeu.present;
    getchar();
    system("clear");
  }while(1);
}
