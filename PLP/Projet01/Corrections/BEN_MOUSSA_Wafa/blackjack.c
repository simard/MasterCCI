# include <stdio.h>
# include <stdlib.h>
# include <time.h>
int main ( int argc, char ** argv)
{
enum carte ( deux de coeur, deux de carrau, deux de pic, deux de tr�fle, trois de carrau, trois de coeur, trois de pic, trois de tr�fle, quatre de carrau, quatre de coeur, quatre de pic, quatre de tr�fle, cinq de carrau, cinq de coeur,cinq de tr�fle,cinq de pic, six de carrau, six de coeur, six de tr�fle , six de pic, sept de carrau, sept de coeur, sept de tr�fle, sept de pic,huit de carrau, huit de coeur, huit de pic, huit de tr�fle, neuf de coeur, neuf de carrau, neuf de tr�fle, neuf de pic, six de coeur , dix de carrau, dix de pic, dix de tr�fle,as, valet = 10, dame = 10, Roi = 10) : 
as=11,i= valet = roi = dame = 10, deuc de carrau = deux de coeur = deux de tr�fle = deux de pic = 2, trois de carrau = trois de coeur = trois de pic = trois de tr�fle = 3, quatre de carrau = quatre de coeur = quatre de pic = quatre de tr�fle = 4, cinq de carrau = cinq de coeur = cinq de pic = cinq de tr�fle = 5, six de carrau = six de coeur = six de pic = six de tr�fle = 6, sept de carrau = sept de coeur = sept de pic = sept de tr�fle = 7, huit de carrau = huit de coeur = huit de pic = huit de tr�fle = 8, neuf de carrau = neuf de coeur = neuf de pic = neuf de tr�fle = 9, dix de carrau = dix de coeur = dix de tr�fle = dix de pic = 10
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
printf ( "vous avez tir� %S\n", carte );
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
printf ( " gagn�\n");
}
else
{
printf ( " Perdu /n" );
}
}
return 0;
)