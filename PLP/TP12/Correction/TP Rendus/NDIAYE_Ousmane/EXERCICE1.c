# include<stdio.h>
# include <stdlib.h>
# include <string.h>
typedef struct sContact
{
  char * cNom;
  char * cPrenom;
  char * cCourriel;
  struct Contact * cnew;
  struct Contact * pSuiv;
  struct Contact * Tete;
  struct Contact * pCourant;
} Contact;
Contact * Nouveau( Contact * pliste)
{
  char cTemp[256];
  int len = 0;
  Contact s;
  Contact *Tete =NULL;
  Contact * pCourant = NULL;
  Contact * cnew = NULL;
  printf( "entrer le nouveau contact\n");
  scanf( "%s", cTemp);
  len = strlen(  cTemp ) +1;
  cnew = (Contact*)malloc(sizeof(Contact));
  (*cnew).pSuiv = Tete;
  printf("entrer le Prenom\n");
  scanf( "%s", &Tete);
   Tete = cnew;
  if(Tete != NULL)
{
    pCourant = Tete;
    while((*pCourant).pSuiv !=NULL)
      pCourant = (*pCourant).pSuiv;
    printf(" entrer le courriel\n");
    scanf("%s", &pCourant);

  }
  else
    {
  cnew = (Contact*)malloc(sizeof(Contact));
  (*pCourant).pSuiv = cnew;
  (*cnew).pSuiv = NULL;
    }
  printf( "%s\n",&Tete);
 return pliste;
}
void Affichage( Contact *s );
int main()
{
  Contact s;
  Contact * pliste = NULL;
  char cTemp[256];
  int len = 0;
  printf( " entrer votre Nom\n" );
  scanf( "%s", cTemp);
  len = strlen(  cTemp ) +1;
  s.cNom= (char *)  malloc( len * sizeof(char));
  strcpy( s.cNom, cTemp);
  printf( "entrer votre prenom\n" );
  scanf( "%s", cTemp );
  len = strlen(  cTemp ) +1;
  s.cPrenom= (char *)  malloc( len * sizeof(char));
  strcpy( s.cPrenom, cTemp);
  printf( "entrer votre courriel\n" );
  scanf( "%s", cTemp );
  len = strlen(  cTemp ) +1;
  s.cCourriel= (char *)  malloc( len * sizeof(char));
  strcpy( s.cCourriel, cTemp);
  Affichage( &s );
  printf(" Entrer la lettre c pour un nouveau contact\n");
  getchar();
  char a = getchar();
  if( a == 'c' || 's' || 'q' )

    switch(a)
      {

      case 'c':
       printf( " Entrer nouveau contact\n" );
       Affichage(&s);
       getchar();
       pliste = Nouveau( pliste);
	break;
      case 's':

	break;

      case 'q':

	break;

      }

  return 0;
}

void Affichage( Contact  *s )
{
  printf( "%s\n", (*s).cNom );
  printf( "%s\n", (*s).cPrenom );
  printf( "%s\n", (*s).cCourriel );
}	
  

       

	     
