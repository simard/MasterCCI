# include<stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct sContact
{
	char * cNom;
	char * cPrenom;
	char * cCourriel;
} Contact;

void Affichage( Contact * s)

{
	int len = 0;
	char cTemp[256] ;
	FILE * pFichier=fopen( "contact", "w" );
	fprintf( pFichier,"s.cNom %p\n", (*s).cNom );
	scanf( "%s", cTemp);
	len = strlen(  cTemp) +1;
	(*s).cNom= (char *)  malloc( len * sizeof(char));
	strcpy( (*s).cNom, cTemp);
	
	fprintf( pFichier,"s.cPrenom %p\n", (*s).cPrenom);
	scanf( "%s", cTemp);
	len = strlen(  cTemp) +1;
	(*s).cPrenom= (char *)  malloc( len * sizeof(char));
	strcpy( (*s).cPrenom, cTemp);
	
	fprintf( pFichier,"s.cCourriel %p\n",(*s).cCourriel  );
	scanf( "%s", cTemp);
	len = strlen(  cTemp) +1;
	(*s).cCourriel=(char *)  malloc( len * sizeof(char));
	strcpy( (*s).cCourriel, cTemp);
}

int main( int argc, char ** argv )
{	
	Contact s;
	 Affichage( &s );
	
	char a = getchar();
	if( a == 'c' || 's' || 'q' )
	switch( a)
	{
		case 'c':
			
		printf( "entrer le Nom à ajouter");
		scanf( "%s", s.cNom);
		printf( "entrer le Prenom à ajouter")
		scanf( "%s", s.cNom);
		printf( "entrer le Prenom à ajouter")
		scanf( "%s", s.cNom);
		
}
