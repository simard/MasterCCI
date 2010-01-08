/* structures et structures recursives
2 structures personne et adresse liees entres elle (une perzsonne habite a une adresse). La structure personne contient également les liens de filiations (pere, mere).
creation de 5 personnes dont 3 habitent a la meme adresse et 2 ont les memes parents. */

#include <stdio.h>
#include<stdlib.h>


/* creation de la structure adresse */
typedef struct adresse {
  int numero;
  char rue[60];
  int cp;
  char ville[20];
}ADRESSE;


/* creation de la structure personne */
typedef struct personne {
  char nom[20];
  char prenom[20];
  struct personne *pere;
  struct personne *mere;
  struct adresse *adresse;
}PERSONNE;


//fonction qui affiche une personne 
void affiche (PERSONNE p){
  printf("Affichage d'une personne\n");
  printf("\nIdentite\n");
  printf("Nom                  : %s\n", p.nom);
  printf("Prenom               : %s\n", p.prenom);
  printf("\nAdresse:\n");
  printf("Numero de votre rue  : %i\n", p.adresse->numero);
  printf("Nom de la rue        : %s\n", p.adresse->rue);
  printf("Code postal          : %i\n", p.adresse->cp);
  printf("Ville                : %s\n", p.adresse->ville);
  printf("\nParents:\n");
  printf("Nom de votre pere    : %s\n", p.pere->nom);
  printf("Prenom de votre pere : %s\n", p.pere->prenom);
  printf("Nom de votre mere    : %s\n", p.mere->nom);
  printf("Prenom de votre mere : %s\n", p.mere->prenom);
}

int main (){
  int i,j;
  
  //creation des parents et des adresses : 3 memoires adresses et 8 memoires personnes
  ADRESSE adr1={14,"boulevard Soult",75012,"Paris"};
  ADRESSE adr2={16,"boulevard Soult",75012,"Paris"};
  ADRESSE adr3={18,"boulevard Soult",75012,"Paris"};

  PERSONNE p1={"Pique","Roi",NULL,NULL,NULL};
  PERSONNE m1={"Pique","Dame",NULL,NULL,NULL};
  PERSONNE p2={"Coeur","Roi",NULL,NULL,NULL};
  PERSONNE m2={"Coeur","Dame",NULL,NULL,NULL};
  PERSONNE p3={"Trefle","Roi",NULL,NULL,NULL};
  PERSONNE m3={"Trefle","Dame",NULL,NULL,NULL};
  PERSONNE p4={"Carreau","Roi",NULL,NULL,NULL};
  PERSONNE m4={"Carreau","Dame",NULL,NULL,NULL};

  //Creation des 5 personnes (3 a la meme adresse, 2 meme parents)
  PERSONNE e1={"Pique","Valet",&p1,&m1,&adr1};
  PERSONNE e2={"Pique","Cavalier",&p1,&m1,&adr2};
  PERSONNE e3={"Coeur","Cavalier",&p2,&m2,&adr2};
  PERSONNE e4={"Trefle","Cavalier",&p3,&m3,&adr2};
  PERSONNE e5={"Carreau","Cavalier",&p4,&m4,&adr3};

  system("clear"); //efface la console
  affiche(e1);
  printf("\n");
  affiche(e2);
  printf("\n");
  affiche(e3);
  printf("\n");
  affiche(e4);
  printf("\n");
  affiche(e5);
  printf("\n");
}
