#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define dimX 20
#define dimY 20
#define N 100.0
#define VIE 500.0
#define ATTAQUE VIE/10.0
#define DEFENSE VIE/20.0

//definitions des structures
typedef struct samurai{
  int ID,victoires,vie,attaque,defense,action;
  int position[2];
  char nom[100];
  struct samurai *next;
}SAMURAI;

typedef struct liste{
  SAMURAI *head;
  int size;
  int nextID;
}CLAN;

typedef struct carte{
    int tours;
    int damier[dimX][dimY];
}CARTE;

//déclarations des fonctions
SAMURAI* addHead(CLAN*);
SAMURAI* addTail(CLAN*);
int damage(int,int);
int delete();
void display(int[][]);
SAMURAI* fight(SAMURAI*,SAMURAI*);
CLAN* init_clan();
CARTE* init_map(CLAN*);
SAMURAI* init_samurai(CLAN*);
SAMURAI* isOpponent(CLAN*,CARTE*,int[]);
int move(CLAN*,CLAN*,SAMURAI*);
int random(double);
SAMURAI* search_position(CLAN*, int[]);
void turn(CLAN*,CARTE*);

/*
 * Fonction damage
 * Calculer les points de dommages.
 * Arguments : attaque (int), defense (int)
 * Retourne : dommages (int)
 */
int damage(int attaque,int defense){
  int damage=0,n=random(N);
  if(n>N/2) damage=attaque;
  else return 0;
  n=random(N);
  if(n>N/2) damage=damage-defense;
  return damage;
}

/*
 * Fonction display
 * Afficher l'etat de l'arene.
 * Arguments : damier 2D
 * Retourne :
 */
void display(int damier[dimX][dimY]){
  int i,j;
  for(i=-1;i<dimX+1;i++){
    for(j=-1;j<dimY+1;j++){
      //murs
      if(i==-1 || i==dimY || j==-1 || j==dimY) printf("X");
      //personne
      else if(damier[i][j]==0) printf(" ");
      //samurai
      else printf("%d",damier[i][j]);
    }
    printf("\n");
  }
}

/*
 * Fonction fight
 * Designer le vaincu lors d'un combat.
 * Arguments : les pointeurs sur les 2 samourais qui s'affrontent
 * Retourne : le pointeur du samourai vaincu
 */
SAMURAI* fight(SAMURAI* s1,SAMURAI* s2){
  int vie1=s1->vie,vie2=s2->vie,temp;
  s1->action=1;
  s2->action=1;
  while(s1->vie>0 && s2->vie>0){
    s2->vie=s2->vie-damage(s1->attaque,s2->defense);
    if(s2->vie>0) s1->vie=s1->vie-damage(s2->attaque,s1->defense);
  }
  if(s2->vie<=0){
    temp=(int)((double)vie1*0.75);
    if(temp>s1->vie) s1->vie=temp;
    //printf("gagnant:%d perdant:%d\n",s1->ID,s2->ID);
    return s2;
  }
  else{
    temp=(int)((double)vie2*0.75);
    if(temp>s2->vie) s2->vie=temp;
    //printf("gagnant:%d perdant:%d\n",s2->ID,s1->ID);
    return s1;
  }
}

/*
 * Fonction init_map
 * Initialiser la structure CARTE.
 * Arguments : le pointeur sur le clan qui occupe l'arene
 * Retourne : le pointeur sur la carte initialise.
 */
CARTE* init_map(CLAN *clan){
  int i,j,pos[2];
  CARTE *map=(CARTE *)malloc(sizeof(CARTE));
  if(map==NULL) return NULL;
  map->tours=0;
  for(i=0;i<dimX;i++){
    for(j=0;j<dimY;j++){
      map->damier[i][j]=0;
    }
  }
  //placement randomtoire des samurais
  SAMURAI *s=clan->head;
  while(s!=NULL){
    do{
      pos[0]=random((double)dimX);
      pos[1]=random((double)dimY);
    }while(search_position(clan,pos)!=NULL);
    s->position[0]=pos[0];
    s->position[1]=pos[1];
    map->damier[pos[0]][pos[1]]=s->ID;
    s=s->next;
  }
  return map;
}


/*
 * Fonction isOpponent
 * Trouver s'il y a un adversaire, si plusieurs, lequel
 * Arguments : les pointeurs sur le clan et la carte, ainsi que la position du samourai où on cherche un adversaire potentiel
 * Retourne : l'adversaire potentiel (NULL si aucun)
 */
SAMURAI* isOpponent(CLAN *clan, CARTE *map, int pos[]){
  int i,j,temp[2];
  SAMURAI *opponent=NULL,*candidat=NULL;
  for(i=pos[0]-1;i<=pos[0]+1;i++){
    for(j=pos[1]-1;j<=pos[1]+1;j++){
      if(i!=pos[0] || j!=pos[1]){
        temp[0]=i;
        temp[1]=j;
        candidat=search_position(clan,temp);
        if(candidat!=NULL && candidat->action==0){
          if(opponent==NULL) opponent=candidat;
          else{
            if(candidat->ID<opponent->ID) opponent=candidat;
          }
        }
      }
    }
  }
  return opponent;
}

/*
 * Fonction random
 * Choisir un nombre aléatoire
 * Arguments : n nombre strictement superieur a la valeur randomtoire (compris entre 0 et n-1)
 * Retourne : nombre entier compris entre 0 et n-1
 */
int random(double n){
  return (int)((double)rand() / ((double)RAND_MAX + 1) * n);
}

/*
 * Fonction search_position
 * Trouver un samouraï connaissant une position (x,y)
 * Arguments : le pointeur sur le clan et la position où on cherche un samourai
 * Retourne : le pointeur sur le samourai (NULL si aucun samourai ne se trouve sur la position recherchee)
 */
SAMURAI* search_position(CLAN *clan, int pos[]){
  SAMURAI *s=clan->head;
  while(s!=NULL){
    if(s->position[0]==pos[0] && s->position[1]==pos[1]) return s;
    s=s->next;
  }
  return NULL;
}

/*
 * Fonction main()
 */
int main(){
}

/*
 * Fonction addHead
 * Ajouter l'element SAMURAI en debut de liste.
 * Arguments : pointeur sur la liste clan
 * Retourne : pointeur sur le samurai ajouté (NULL si le malloc a echoue)
 */
SAMURAI* addHead(CLAN *clan){
}

/*
 * Fonction addTail
 * Ajouter l'element SAMURAI en fin de clan.
 * Arguments : pointeur sur la clan clan
 * Retourne : pointeur sur le samurai ajouté (NULL si le malloc a echoue)
 */
SAMURAI* addTail(CLAN *clan){
}

/*
 * Fonction delete
 * Effacer la liste.
 * Arguments :
 * Retourne : nombre indiquant si l'action a reussi (0 si pas de samourais dans la liste, 1 liste effacee)
 */
int delete(){
}

/*
 * Fonction init_clan
 * Initialiser la structure CLAN.
 * Arguments : 
 * Retourne : le pointeur sur le clan initialise.
 */
CLAN* init_clan(){
}

/*
 * Fonction init_samurai
 * Initialiser la structure SAMURAI.
 * Arguments : le pointeur sur le clan et le samourai a initialiser
 * Retourne :
 */
SAMURAI* init_samurai(CLAN *clan){
}


/*
 * Fonction move
 * Deplacer un samourai d'un clan a un autre
 * Arguments : les pointeurs sur les clans et le samurai
 * Retourne : 0 si probleme, 1 si reussi
 */
int move(CLAN*,CLAN*,SAMURAI*){
}

/*
 * Fonction turn
 * Decider de l'action d'un samourai pour le tour en cours
 * Arguments : les pointeurs sur le clan et la carte
 * Retourne :
 */
void turn(CLAN *clan, CARTE *map){
  
  //réinitialisation des actions des samourais
  
  //etude des actions des samourais restant en course
  
    //samourai se déplace
    if(){
    }
    //samourai se bat
    else{
    }
  }
}
