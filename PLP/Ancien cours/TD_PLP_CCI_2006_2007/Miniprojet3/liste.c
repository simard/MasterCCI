#include<stdio.h>
#include<stdlib.h>

typedef struct node{
  int ID;
  struct node *next;
}NODE;

typedef struct liste{
  NODE *head;
  int size;
  int nextID;
}LISTE;

LISTE* create(){
  LISTE *entete=(LISTE *)malloc(sizeof(LISTE));
  if(entete==NULL) return NULL;
  entete->head=NULL;
  entete->nextID=1;
  entete->size=0;
  return entete;
}

NODE* addHead(LISTE *liste){
  NODE *new=(NODE *)malloc(sizeof(NODE));
  if(new==NULL) return NULL;
  new->ID=liste->nextID;
  liste->nextID++;
  liste->size++;
  new->next=liste->head;
  liste->head=new;
  return new;
}

NODE* addTail(LISTE *liste){
  NODE *new=(NODE *)malloc(sizeof(NODE));
  if(new==NULL) return NULL;
  new->ID=liste->nextID;
  liste->nextID++;
  liste->size++;
  new->next=NULL;
  //si aucun element au depart, on ajoute
  if(liste->head==NULL)
    liste->head=new;
  //sinon on trouve l'avant dernier element non NULL et on pointe.
  else{
    NODE *ptr=liste->head;
    while(ptr->next!=NULL)
      ptr=ptr->next;
    ptr->next=new;
  } 
  return new;
}

void display(LISTE *liste){
  NODE *ptr=liste->head;
  while(ptr!=NULL){
    printf("%d\t",ptr->ID);
    ptr=ptr->next;
  }
}

int delete(LISTE *liste,int ID){
  //cas où liste vide
  if(liste->head==NULL) return 0;
  //sinon
  else{
    NODE *ptr=liste->head;
    NODE *prevptr=NULL;
    while(ptr!=NULL){
      if(ptr->ID==ID){
	//si celui qu'il faut effacer est en tête de liste
	if(prevptr==NULL) liste->head=ptr->next;
	else prevptr->next=ptr->next;
	free(ptr);
	liste->size--;
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

void connect(LISTE *liste){
  NODE *ptr=liste->head;
  while(ptr->next!=NULL)
    ptr=ptr->next;
  ptr->next=liste->head;
}

int main(){
  int i;  
  LISTE *test=create();
  for(i=0;i<3;i++) addTail(test);
  NODE *ptr=test->head;
  i=1;
  display(test);
  printf("\n");
  while(test->size>1){
    if(i==2){
      i=0;
      delete(test,ptr->ID);
      display(test);
      printf("\n");
    }
    if (ptr->next==NULL) ptr=test->head;
    else ptr=ptr->next;
    i++;
  }
}

/*
int main(){
  int valeur,i;
  struct cellule *temp,*entete=NULL,*fin;
  for(i=0;i<10;i++){
    temp=malloc(sizeof(struct cellule));
    temp->valeur=i;
    if(entete==NULL){
      entete=temp;
      fin=temp;
    }
    fin->suivant=temp;
    temp->suivant=0;
    fin=temp;
  }

  temp=entete;
  do{
    printf("%d\n",temp->valeur);
    temp=temp->suivant;
  }while(temp);
}
*/
