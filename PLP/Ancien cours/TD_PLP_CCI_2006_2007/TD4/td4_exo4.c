/* TD 5 de C */

/* exercice 4 : les tableaux */

/* on commence par inclure les bibliothèque */
#include <stdio.h>
#include <stdlib.h>

int main()
{
	char tab[7];
	char choix;
	int i=0;

	//printf("Entrer une lettre au clavier au choix entre :\nb,t ou a\n(presser q pour sortir)\n: ");
	//scanf("%s",&choix);

	while(i!=1)
	{
		printf("Entrer une lettre au clavier au choix entre :\nb,t ou a\n(presser q pour sortir)\n: ");
		scanf("%s",&choix);
		switch (choix)
		{
			case 'b' :
			case 'B' :
			{
				i=0;
				tab[0]='b';
				tab[1]='a';
				tab[2]='t';
				tab[3]='e';
				tab[4]='a';
				tab[5]='u';

				printf("\n");
				for (i=0;i<6;i++)
				{
					printf("%c",tab[i]);
				}
				printf("\n");
				i=1;
				break;
			}

			case 't' :
			case 'T' :
			{
				i=0;
				tab[0]='t';
				tab[1]='r';
				tab[2]='a';
				tab[3]='i';
				tab[4]='n';

				printf("\n");
				for (i=0;i<5;i++)
				{
					printf("%c",tab[i]);
				}
				printf("\n");
				i=1;
				break;
			}

			case 'a' :
			case 'A' :
			{
				i=0;
				tab[0]='a';
				tab[1]='v';
				tab[2]='i';
				tab[3]='o';
				tab[4]='n';
	
				printf("\n");
				for (i=0;i<5;i++)
				{
					printf("%c",tab[i]);
				}
				printf("\n");
				i=1;
				break;
			}

			case 'q' :
			case 'Q' :
				i=1;
				exit(0);
		}
	}
}
