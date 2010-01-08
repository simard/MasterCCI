#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct {
  char couleur;
  char position;
  char valeur;
  
}cartes;
  int  main(int argc, char ** argv)
  {
    

    cartes  jeux[3][52];
    char type[13]={'2','3','4','5','6','7','8','9','K','L','M','N','O'};

    int i,j;
    for(i=0;i<3;i++)
      {
	for(j=0;j<13;j++)
	  {
	    jeux[i][j].couleur='T';
	    if(j<8){
	      jeux[i][j].position=type[j]-'0'-2;}
	    if((j>7)&(j<=12))
	      {jeux[i][j].position=type[j]-'A'-2;}
	  }
	for(j=13;j<26;j++)
	  {
	    jeux[i][j].couleur='K';
	    if(j<21){
	      jeux[i][j].position=type[j-13]-'0'-2;}
	    if((j>20)&(j<26))
	      {jeux[i][j].position=type[j-13]-'A'-2;}
	    
	  }
	for(j=26;j<39;j++)
	  {
	    jeux[i][j].couleur='C';
	    if(j<34){
	      jeux[i][j].position=type[j-26]-'0'-2;}
	    if((j>33)&(j<39)){
	      jeux[i][j].position=type[j-26]-'A'-2;}
	    
	  }
	for(j=39;j<52;j++)
	  {
	    jeux[i][j].couleur='P';
	    if(j<47){
	      jeux[i][j].position=type[j-39]-'0'-2;}
	    if((j>46)&(j<52)){
	      jeux[i][j].position=type[j-39]-'A'-2;
	    }

	    
	  }
      }
 
   
    int a;
    a=0;
    for(j=0;j<52;j++)
      { 
      if(jeux[1][j].position<9)
	  {
	    jeux[2][j].valeur=a+2;
	    a++;
	  }
	if ((jeux[1][j].position<12)&(jeux[1][j].position>8))
	  {jeux[2][j].valeur=10;
	  }
	if(jeux[1][j].position==12)
	  
	  {jeux[2][j].valeur=11;
	    a=0;
	  }
	
      }

 
    int  m;
    int scojoueur=0;

   printf("votre score est de %i\n",scojoueur);
    while (scojoueur<21)
      {
    printf("voulez vous retirer une carte?,[1/0]");
    scanf("%i",&m);
    if(m==1)
      {srand(time(0));
	
	int choix=rand()%51;
	printf("vous avez retiré %c de couleur de %c\n",type[jeux[1][choix].position],jeux[0][choix].couleur);

	scojoueur=scojoueur+jeux[2][choix].valeur;
printf("votre score est de %i\n",scojoueur);
	
      }
    else break;
      }

    int itab[6];
    for(i=0;i<5;i++)
      {itab[i]=i+16;
      } 
    int scorebanque;
    srand(time(0));
    scorebanque=0;
   int choixb=rand()%5;

    scorebanque=itab[choixb];
    printf("votre score est de %i\n",scojoueur);
    printf("le score de la banque est de %i\n",scorebanque);
   
      
    if (scojoueur>21){
      printf("votre score a dépassé 21, vous avez perdu\n");} 
    else { if (scorebanque>scojoueur)
      {printf("désolé, vous avez perdu\n");
      }
      else printf("félicitation, vous avez gagné\n");}
    
return 0;  

      
  }
