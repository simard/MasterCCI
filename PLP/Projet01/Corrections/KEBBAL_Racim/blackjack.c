
/*Projet n°1_Exercie 2*/
/*Racim KEBBAL*/

# include <stdio.h>
# include <stdlib.h>
# include <time.h>



int tirrer_une_carte_hasard()
    {
     int i,carte_tiree;
     /*temporisation pour changer le temps et avoir une nouvelle variable*/
     for (i = 0; i<100; i++)
      {
       carte_tiree =(i+4)*20;
       carte_tiree = 1+( int)( ( double ) rand () / ( ( double )RAND_MAX + 1.0 ) * 55.0 );
      }
    return carte_tiree;
    }
    
    

/*Fonction POUR tirer une carte aléatoirement*/
    int score_machine_hasard() 
       {
        int i,carte_tiree;
        srand ( time( NULL ) );
        /*temporisation*/
        for (i = 0; i<100; i++)\
          {
         carte_tiree =(i+4)*20;
         carte_tiree = 16+( int)( ( double ) rand () / ( ( double )RAND_MAX + 1.0 ) * 5.0 );
          }
          return carte_tiree;
       }
  
/*Fonction pour l'Affichage de la carte*/


int affichage_carte(int valeur_a_convertir)
   {
switch(valeur_a_convertir)
{
    case 1 :   printf("As de coeur");
               break;
    case 2 :   printf("deux de coeur");
               break;
    case 3 :   printf("trois de coeur");
               break;
    case 4 :   printf("quatre de coeur");
               break;
    case 5 :   printf("cinq de coeur");
               break;
    case 6 :   printf("six de coeur");
               break;
    case 7 :   printf("sept de coeur");
               break;
    case 8 :   printf("huit de coeur");
               break;
    case 9 :   printf("neuf de coeur");
               break;
    case 10:   printf("dix de coeur");
               break;
    case 11:   printf("valet de coeur");
               break;
    case 12:   printf("dame de coeur");
               break;
    case 13:   printf("roi de coeur");
               break;
    case 14:   printf("As de coeur");
               break;
    
    case 15:   printf("As de pique");
               break;
    case 16:   printf("deux de pique");
               break;
    case 17:   printf("trois de pique");
               break;
    case 18:   printf("quatre de pique");
               break;
    case 19:   printf("cinq de pique");
               break;
    case 20:   printf("six de pique");
               break;
    case 21:   printf("sept de pique");
               break;
    case 22:   printf("huit de pique");
               break;
    case 23:   printf("neuf de pique");
               break;
    case 24:   printf("dix de pique");
               break;
    case 25:   printf("valet de pique");
               break;
    case 26:   printf("dame de pique");
               break;
    case 27:   printf("roi de pique");
               break;
    case 28:   printf("As de pique");
               break;
    
    case 29:   printf("As de trefle");
               break;
    case 30:   printf("deux de trefle");
               break;
    case 31:   printf("trois de trefle");
               break;
    case 32:   printf("quatre de trefle");
               break;
    case 33:   printf("cinq de trefle");
               break;
    case 34:   printf("six de trefle");
               break;
    case 35:   printf("sept de trefle");
               break;
    case 36:   printf("huit de trefle");
               break;
    case 37:   printf("neuf de trefle");
               break;
    case 38:   printf("dix de trefle");
               break;
    case 39:   printf("valet de trefle");
               break;
    case 40:   printf("dame de trefle");
               break;
    case 41:   printf("roi de trefle");
               break;
    case 42:   printf("As de trefle");
               break;
    
    case 43:   printf("As de carreau");
               break;
    case 44:   printf("deux de carreau");
               break;
    case 45:   printf("trois de carreau");
               break;
    case 46:   printf("quatre de carreau");
               break;
    case 47:   printf("cinq de carreau");
               break;
    case 48:   printf("six de carreau");
               break;
    case 49:   printf("sept de carreau");
               break;
    case 50:   printf("huit de carreau");
               break;
    case 51:   printf("neuf de carreau");
               break;
    case 52:   printf("dix de carreau");
               break;
    case 53:   printf("valet de carreau");
               break;
    case 54:   printf("dame de carreau");
               break;
    case 55:   printf("roi de carreau");
               break;
    case 56:   printf("As de carreau");
               break;
    }    
    return 0;
    }


/*Valeurs des cartes dans le cas d'un As*/


int valeur_AS (int valeur_a_convertir)
{
int carte_tiree,bonne_sortie=0,choix_As=0;
do
     {
     printf("\nQuel nombre de points desirez vous donner a votre As  1 ou 11 ?");
     scanf("%d",&choix_As);
       if (choix_As==1)
         {
          carte_tiree=1;
          bonne_sortie=1;
         }
       else
       {
           if (choix_As==11)
            {
             carte_tiree=11;
             bonne_sortie=1;
            }
             else
            {
             printf("veuillez introduire la bonne valeur");
             bonne_sortie=0;
            }
       }
      }
     while(bonne_sortie==0);
     return carte_tiree;
}


/*Valeurs des valets dames et rois*/


int valeur_VDR (int valeur_a_convertir)
{
     valeur_a_convertir=10;
     return valeur_a_convertir;
}



/*Valeurs des cartes restante*/


int valeur_carte_restantes (int valeur_a_convertir)
{
/* rendre tous les valeurs tirees au hasrad dans le meme intervale*/
   if (valeur_a_convertir>14 && valeur_a_convertir<29)
      {
      valeur_a_convertir=valeur_a_convertir-14;
      }

   if (valeur_a_convertir>28 && valeur_a_convertir<43)
      {
      valeur_a_convertir=valeur_a_convertir-28;
      }
   if (valeur_a_convertir>42)
      {
      valeur_a_convertir=valeur_a_convertir-42;
      }
 
     return valeur_a_convertir;
}



/*le corps du Programme*/


int main()
 {
   int carte_tiree,valeur=0,somme_des_carte_joueur=0,temoin_auto_defete=0,\
   erreur_de_frape,somme_des_carte_adversaire=0;
   
   char fin='n',choix_de_continuer='o';

      do
      {
system("CLS");
   printf("\n\n\n");
   printf("                     ++++++++++++++++++++++++++");
   printf("\n                         Start GAME!\n  ");
   printf("                   ++++++++++++++++++++++++++\n\n\n\n");


/*Initialisation des variables pour une nouvelle execution du jeux*/   
      somme_des_carte_joueur=0;
      valeur=0;
      temoin_auto_defete=0;
/*Premiere carte distribuee automatiquement +*/
      
      carte_tiree=tirrer_une_carte_hasard();
      
      if( (carte_tiree==12) || (carte_tiree==26) || (carte_tiree==40)|| (carte_tiree==54))
      printf("\nVous avez comme premiere carte la :         ");
      
      if( (carte_tiree==1) || (carte_tiree==14) || (carte_tiree==15)|| \
      (carte_tiree==28)||(carte_tiree==29) || (carte_tiree==42) || (carte_tiree==43)||\
      (carte_tiree==56))
      
      printf("\nVous avez comme premiere carte l' :         ");
      
      else printf("\nVous avez comme premiere carte le :         ");

      affichage_carte(carte_tiree);
      printf("   \n");

/*valeur de la carte */


       /* 1er cas les As*/
if ((carte_tiree==1) || (carte_tiree==14) || (carte_tiree==15) ||\
    (carte_tiree==28) || (carte_tiree==29) || (carte_tiree==42)||\
    (carte_tiree==43) || (carte_tiree==56))
        {
        valeur=valeur_AS(carte_tiree);
        }
else
 {     
  /* 2eme cas les valets dames Rois*/
  if ((carte_tiree==11) || (carte_tiree==12) || (carte_tiree==13) ||\
     (carte_tiree==25) || (carte_tiree==26) || (carte_tiree==27)|| \
     (carte_tiree==39) || (carte_tiree==40)|| (carte_tiree==41)|| \
     (carte_tiree==53)|| (carte_tiree==54)|| (carte_tiree==55))
  {
   valeur=valeur_VDR(carte_tiree);
  }
 /*3eme cas le reste des carte*/             
  else
  {
    valeur=valeur_carte_restantes(carte_tiree);       
  }
 
        }   

somme_des_carte_joueur+=valeur;
printf("Vous avez %d Points",somme_des_carte_joueur);   
          
          
          do
          {                  
               printf("\n\nVoulez-vous tirer une nouvelle carte [y/n]?   ");
               scanf("%s",&choix_de_continuer);
          /*------erreure de frqpe*/
                  if((choix_de_continuer=='y')||(choix_de_continuer=='n'))
                  {
                      erreur_de_frape=0;
                  }
                
                  else {
                       erreur_de_frape=1;
                       printf("\nVeuillez introduire la bonne lettre");
                       }
           }
           while(erreur_de_frape==1);       
                
         if(choix_de_continuer=='y')        
           {
             do
                {

/*Traitement des cartes*/
                                            
  carte_tiree=tirrer_une_carte_hasard();
      printf("\nVous avez tire la carte :         ");
      affichage_carte(carte_tiree);
      printf("   \n");

/*valeur de la carte*/

       /* 1er cas les As*/
if ((carte_tiree==1) || (carte_tiree==14) || (carte_tiree==15) || \
   (carte_tiree==28) || (carte_tiree==29) || (carte_tiree==42)||\
   (carte_tiree==43) || (carte_tiree==56))
        {
        valeur=valeur_AS(carte_tiree);
        }
else
 {     
  /* 2eme cas les valets dames Rois*/
  if ((carte_tiree==11) || (carte_tiree==12) || (carte_tiree==13) ||\
     (carte_tiree==25) || (carte_tiree==26) || (carte_tiree==27)|| \
     (carte_tiree==39) || (carte_tiree==40)|| (carte_tiree==41)|| \
     (carte_tiree==53)|| (carte_tiree==54)|| (carte_tiree==55))
  {
   valeur=valeur_VDR(carte_tiree);
  }
 /*3eme cas le reste des carte*/             
  else
  {
    valeur=valeur_carte_restantes(carte_tiree);       
  }
 
 }   

somme_des_carte_joueur+=valeur;
printf("Vous avez %d Points",somme_des_carte_joueur);                                                 
  
/*Message pour rester dans le jeux*/


                  if(somme_des_carte_joueur<21)
                    {
                     do
                        {                  
                         printf("\n\nVoulez-vous tirer une nouvelle carte [y/n]?   ");
                         scanf("%s",&choix_de_continuer);
                         /*------erreure de frqpe*/
                         if((choix_de_continuer=='y')||(choix_de_continuer=='n'))
                           {
                            erreur_de_frape=0;
                             }
                        else {
                           erreur_de_frape=1;
                           printf("\nVeuillez introduire la bonne lettre");
                             }
                         }
                       while(erreur_de_frape==1);   
                      }
                     else
                     {
                     if(somme_des_carte_joueur==21)
                      {
                      printf("\n\n\n##############      ");
                    printf(" Blackjack !");
                    temoin_auto_defete=0;
                    choix_de_continuer='n';
                    }
                    else
                    {
                    printf("\n\n\n##############      ");
                    printf("YOU LOSE");
                    temoin_auto_defete=1;
                    choix_de_continuer='n';
                    }
                 }
                 }
                 
                                  while(choix_de_continuer=='y');
            }

/*Score de la machine et Affichage*/


if(temoin_auto_defete==0)
{
somme_des_carte_adversaire=score_machine_hasard();
printf("\nVotre adversaire a %d Points",somme_des_carte_adversaire);
if(somme_des_carte_joueur>somme_des_carte_adversaire)printf("\n\n\n##############      YOU WIN\n\n\n");
else 
{
     if(somme_des_carte_joueur==somme_des_carte_adversaire)printf("n\n\n############## PARTIE NULLE \n\n\n");
     else printf("n\n\n############## VOUS AVEZ PERDUE LA PARTIE\n\n\n");
}
}

/*Message*/


 printf("\n---------------------------------------\n");
 printf("---------------------------------------\n");
 printf("Voulez vous quitter l'application ? y/n");
 scanf("%s",&fin);  
       }
       while(fin=='n');
return 0;
}
