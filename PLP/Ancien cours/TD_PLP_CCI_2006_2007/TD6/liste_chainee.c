#include<stdio.h>
#include<stdlib.h>

typedef struct node{
  int ID;
  struct node *next;
}NODE;

int main(){
  int i;
  NODE *temp,*debut=NULL,*fin=NULL;
  
  //creation de la 1ere cellule (=entete)
  debut=(NODE*)malloc(sizeof(NODE));
  debut->ID=0;
  debut->next=NULL; //pas de cellule suivante pour l'instant
  
  fin=debut; //ce pointeur me garde le dernier noeud rentre
  
  for(i=1;i<10;i++){
    temp=(NODE*)malloc(sizeof(NODE)); //allocation mémoire
    temp->ID=i;  	//affectation de l'identifiant
    fin->next=temp; 	//l'ancien dernier element pointe sur le nouveau dernier element
    temp->next=NULL;	//le dernier element pointe sur NULL (pas de cellule suivante)
    fin=temp;		//on rafraichit le dernier element dans fin
  }

  //Affichage, on se met au debut de la liste
  temp=debut;
  while(temp!=NULL){
    printf("%d\n",temp->ID);
    temp=temp->next;
  }
}
