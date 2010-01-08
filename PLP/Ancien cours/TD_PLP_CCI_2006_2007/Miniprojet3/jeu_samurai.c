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
int delete(CLAN*,int);
void display(int[][]);
SAMURAI* fight(SAMURAI*,SAMURAI*);
CLAN* init_clan();
CARTE* init_map(CLAN*);
void init_samurai(CLAN*,SAMURAI*);
SAMURAI* isOpponent(CLAN*,CARTE*,int[]);
int random(double);
SAMURAI* search_position(CLAN*, int[]);
void turn(CLAN*,CARTE*);

/*
 * Fonction main()
 */
int main(){
  srand(time(NULL));
  int i;  
  CLAN *clan=init_clan();
  for(i=0;i<9;i++) addTail(clan);
  CARTE *map=init_map(clan);
  system("cls");
  display(map->damier);
  getchar();
  system("cls");
  while (clan->size>1){
    turn(clan,map);
    display(map->damier);
    getchar();
    system("cls");
  }
  printf("Le survivant est %d",clan->head->ID);
}

/*
 * Fonction addHead
 * Ajouter l'element SAMURAI en debut de liste.
 * Arguments : pointeur sur la liste clan
 * Retourne : pointeur sur le samurai ajouté (NULL si le malloc a echoue)
 */
SAMURAI* addHead(CLAN *clan){
  SAMURAI *s=(SAMURAI*)malloc(sizeof(SAMURAI));
  if(s==NULL) return NULL;
  init_samurai(clan,s);
  clan->nextID++;
  clan->size++;
  s->next=clan->head;
  clan->head=s;
  return s;
}

/*
 * Fonction addTail
 * Ajouter l'element SAMURAI en fin de clan.
 * Arguments : pointeur sur la clan clan
 * Retourne : pointeur sur le samurai ajouté (NULL si le malloc a echoue)
 */
SAMURAI* addTail(CLAN *clan){
  SAMURAI *s=(SAMURAI *)malloc(sizeof(SAMURAI));
  if(s==NULL) return NULL;
  init_samurai(clan,s);
  clan->nextID++;
  clan->size++;
  //si la clan est vide, clan pointe sur l'élément a ajouter (premier element)
  if(clan->head==NULL) clan->head=s;
  //sinon on trouve l'element pointant sur NULL et on le fait pointer sur l'element a ajouter.
  else{
    SAMURAI *ptr=clan->head;
    while(ptr->next!=NULL) ptr=ptr->next;
    ptr->next=s;
  } 
  return s;
}

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
 * Fonction init_clan
 * Initialiser la structure CLAN.
 * Arguments : 
 * Retourne : le pointeur sur le clan initialise.
 */
CLAN* init_clan(){
  CLAN *clan=(CLAN *)malloc(sizeof(CLAN));
  if(clan==NULL) return NULL;
  clan->head=NULL;
  clan->nextID=1;
  clan->size=0;
  return clan;
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
 * Fonction init_samurai
 * Initialiser la structure SAMURAI.
 * Arguments : le pointeur sur le clan et le samourai a initialiser
 * Retourne :
 */
void init_samurai(CLAN *clan,SAMURAI *s){
  s->ID=clan->nextID;
  s->next=NULL;
  s->victoires=0;
  s->vie=VIE+random(N);
  s->attaque=ATTAQUE+random(N/10.0);
  s->defense=DEFENSE+random(N/10.0);
  s->action=0;
  s->position[0]=0;
  s->position[1]=0;
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
 * Fonction turn
 * Decider de l'action d'un samourai pour le tour en cours
 * Arguments : les pointeurs sur le clan et la carte
 * Retourne :
 */
void turn(CLAN *clan, CARTE *map){
  int n,pos[2],id;
  SAMURAI *opponent,*perdant;
  
  //réinitialisation des actions des samourais
  SAMURAI *s=clan->head;
  while(s!=NULL){
    s->action=0;
    s=s->next;
  }
  
  //etude des actions des samourais restant en course
  s=clan->head;
  while(s!=NULL && s->action==0){
    opponent=isOpponent(clan,map,s->position);
    //samourai se déplace
    if(opponent==NULL){
      do{
        n=random(N);
        if(n<N/3) pos[0]=s->position[0]-1;
        else if(n>N/3) pos[0]=s->position[0]+1;
        else pos[0]=s->position[0];
        n=random(N);
        if(n<N/3) pos[1]=s->position[1]-1;
        else if(n>N/3) pos[1]=s->position[1]+1;
        else pos[1]=s->position[1];
      }while(search_position(clan,pos)!=NULL || pos[0]<0 || pos[0]>dimX-1 || pos[1]<0 || pos[1]>dimY-1);    
      map->damier[s->position[0]][s->position[1]]=0;
      s->position[0]=pos[0];
      s->position[1]=pos[1];
      map->damier[s->position[0]][s->position[1]]=s->ID;
      s=s->next;
    }
    //samourai se bat
    else{
      perdant=fight(s,opponent);
      if(perdant==s){
        map->damier[opponent->position[0]][opponent->position[1]]=0;
        opponent->position[0]=s->position[0];
        opponent->position[1]=s->position[1];
        map->damier[opponent->position[0]][opponent->position[1]]=opponent->ID;
        id=s->ID;
        s=s->next;
        delete(clan,id);
      }
      else{
        map->damier[s->position[0]][s->position[1]]=0;
        s->position[0]=opponent->position[0];
        s->position[1]=opponent->position[1];
        map->damier[s->position[0]][s->position[1]]=s->ID;        
        delete(clan,opponent->ID);
        s=s->next;
      }
    }
  }
}

/*
 * Fonction delete (cumule move et delete : a separer)
 * Effacer l'element SAMURAI correspondant a l'ID donne.
 * Arguments : pointeur sur la liste clan et l'ID a effacer
 * Retourne : nombre indiquant si l'action a reussi (0 si pas de samourais dans la liste, 1 samourai efface, 2 pas de samourai avec l'ID correspondant)
 */
int delete(CLAN *clan,int ID){
  //cas ou clan vide
  if(clan->head==NULL) return 0;
  //sinon
  else{
    SAMURAI *ptr=clan->head;
    SAMURAI *prevptr=NULL;
    while(ptr!=NULL){
      if(ptr->ID==ID){
	    //si celui qu'il faut effacer est en tete de clan
	    if(prevptr==NULL) clan->head=ptr->next;
	    else prevptr->next=ptr->next;
	    free(ptr);
	    clan->size--;
	    return 1;
      }
      else{
	    prevptr=ptr;
	    ptr=ptr->next;
      }
    }
  }
  //on n'a pas trouve l'ID
  return 2; 
}
