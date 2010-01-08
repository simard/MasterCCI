#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct {
  char coul;
  char rang;
  char val;
  
}carte;
  int  main(int argc, char ** argv)
  {
    

    carte  ranger[3][52];
    char rangcarte[13]={'2','3','4','5','6','7','8','9','K','L','M','N','O'};

    int i,j;
    for(i=0;i<3;i++)
      {
	for(j=0;j<13;j++)
	  {
	    ranger[i][j].coul='T';
	    if(j<8){
	      ranger[i][j].rang=rangcarte[j]-'0'-2;}
	    if((j>7)&(j<=12))
	      {ranger[i][j].rang=rangcarte[j]-'A'-2;}
	  }
	for(j=13;j<26;j++)
	  {
	    ranger[i][j].coul='K';
	    if(j<21){
	      ranger[i][j].rang=rangcarte[j-13]-'0'-2;}
	    if((j>20)&(j<26))
	      {ranger[i][j].rang=rangcarte[j-13]-'A'-2;}
	    
	  }
	for(j=26;j<39;j++)
	  {
	    ranger[i][j].coul='C';
	    if(j<34){
	      ranger[i][j].rang=rangcarte[j-26]-'0'-2;}
	    if((j>33)&(j<39)){
	      ranger[i][j].rang=rangcarte[j-26]-'A'-2;}
	    
	  }
	for(j=39;j<52;j++)
	  {
	    ranger[i][j].coul='P';
	    if(j<47){
	      ranger[i][j].rang=rangcarte[j-39]-'0'-2;}
	    if((j>46)&(j<52)){
	      ranger[i][j].rang=rangcarte[j-39]-'A'-2;
	    }

	    
	  }
      }
 
   
    int a;
    a=0;
    for(j=0;j<52;j++)
      { 
      if(ranger[1][j].rang<9)
	  {
	    ranger[2][j].val=a+2;
	    a++;
	  }
	if ((ranger[1][j].rang<12)&(ranger[1][j].rang>8))
	  {ranger[2][j].val=10;
	  }
	if(ranger[1][j].rang==12)
	  
	  {ranger[2][j].val=11;
	    a=0;
	  }
	
      }
for (i=0;i<52;i++)
  printf("%i\n",ranger[2][i].val);
    printf("bienvenue dans le jeu blackjack\n");
    printf("les carte sont dans l'ordre suivant: 2-3-4-5-6-7-8-9-K'10'-L'Vallé'-M'Damme'-N'Le roi'\n");
    printf(" les couleur sont , P'pique'-K'carreau'-C'Coeur'-T'Trefle'\n");
    printf("on commence:......\n");
    int n;
    int score=0;
   printf("votre score est de %i\n",score);
    while (score<21)
      {
    printf("voulez vous retirer une carte?,[1/0]");
    scanf("%i",&n);
    if(n==1)
      {srand(time(0));
	
	int colonne=rand()%51;
	printf("vous avez retiré %c de couleur de %c\n",rangcarte[ranger[1][colonne].rang],ranger[0][colonne].coul);

	score=score+ranger[2][colonne].val;
printf("votre score est de %i\n",score);
	
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
   int banque=rand()%5;

    scorebanque=itab[banque];
    printf("votre score est de %i\n",score);
    printf("le score de la banque est de %i\n",scorebanque);
   
      
    if (score>21){
      printf("votre score a dépassé 21, vous avez perdu\n");} 
    else { if (scorebanque>score)
      {printf("désolé, vous avez perdu\n");
      }
      else printf("félicitation, vous avez gagné\n");}
    
return 0;  

      
  }
