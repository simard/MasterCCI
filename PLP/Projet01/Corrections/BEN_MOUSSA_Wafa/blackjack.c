# include <stdio.h>
# include <stdlib.h>
# include <time.h>
int main ( int argc, char ** argv)
{
enum carte ( deux de coeur, deux de carrau, deux de pic, deux de trèfle, trois de carrau, trois de coeur, trois de pic, trois de trèfle, quatre de carrau, quatre de coeur, quatre de pic, quatre de trèfle, cinq de carrau, cinq de coeur,cinq de trèfle,cinq de pic, six de carrau, six de coeur, six de tréfle , six de pic, sept de carrau, sept de coeur, sept de trèfle, sept de pic,huit de carrau, huit de coeur, huit de pic, huit de trèfle, neuf de coeur, neuf de carrau, neuf de trèfle, neuf de pic, six de coeur , dix de carrau, dix de pic, dix de tréfle,as, valet = 10, dame = 10, Roi = 10) : 
as=11,i= valet = roi = dame = 10, deuc de carrau = deux de coeur = deux de trèfle = deux de pic = 2, trois de carrau = trois de coeur = trois de pic = trois de trèfle = 3, quatre de carrau = quatre de coeur = quatre de pic = quatre de trèfle = 4, cinq de carrau = cinq de coeur = cinq de pic = cinq de trèfle = 5, six de carrau = six de coeur = six de pic = six de trèfle = 6, sept de carrau = sept de coeur = sept de pic = sept de trèfle = 7, huit de carrau = huit de coeur = huit de pic = huit de trèfle = 8, neuf de carrau = neuf de coeur = neuf de pic = neuf de trèfle = 9, dix de carrau = dix de coeur = dix de trèfle = dix de pic = 10
srand ( time (NULL ) ) ;
score banque = (int)(((double)rand() / ((double)\RAND_MAX + 1.0) * 21.0 )+ 16);
score joueur = (int) ((doublke) rand() / ((double)\RAND_MAX + 1.0) * 21.0);
{
printf ( Voulez vous tirer une carte [y/n]?\n");
carte = getchar;
getchar();
switch (carte)
{
case 'y':
{
printf ( "vous avez tiré %S\n", carte );
if (score joueur < 21)
{
Score joueur = score joueur + carte;
}
else
{
printf ( "PERDU: votre score est %d\n", score joueur);
}
}
case 'n' :
{
printf ( "score joueur\n" );
printf ( " score banque\n");
}
if (( score joueur < 21 ) && ( score joueur < score banque ))
{
printf ( " gagné\n");
}
else
{
printf ( " Perdu /n" );
}
}
return 0;
)