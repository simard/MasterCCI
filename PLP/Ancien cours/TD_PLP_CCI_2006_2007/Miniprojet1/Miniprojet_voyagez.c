/* Miniprojet 1 : Voyagez */

//librairie permettant l'utilisation les fonctions printf et scanf
#include <stdio.h>

//définitions des constantes du programme (portée globale)
#define AVION_PS 0.1
#define AVION_VIT 500
#define AVION_ECO 1
#define AVION_AFF 1.5 
#define AVION_PRE 2.2
#define AVION_REDUC 0.05
#define AVION_REDUC_AGE_0_12 0.25
#define AVION_REDUC_AGE_13_25 0.5
#define AVION_REDUC_AGE_26_59 0.25
#define AVION_REDUC_AGE_60 0.25
#define AVION_ASSUR 0.1

#define TRAIN_PS 0.05
#define TRAIN_VIT 200
#define TRAIN_SEC 1 
#define TRAIN_PRE 1.5
#define TRAIN_REDUC 0.01
#define TRAIN_REDUC_AGE_0_12 0.25
#define TRAIN_REDUC_AGE_13_25 0.5
#define TRAIN_REDUC_AGE_26_59 0.25
#define TRAIN_REDUC_AGE_60 0.25
#define TRAIN_ASSUR 0.1

#define BATEAU_PS 0.03
#define BATEAU_VIT 37.04
#define BATEAU_SEC 1 
#define BATEAU_PRE 1.5
#define BATEAU_REDUC 0.01
#define BATEAU_REDUC_AGE_0_12 0.15
#define BATEAU_REDUC_AGE_13_25 0.25
#define BATEAU_REDUC_AGE_26_59 0.2
#define BATEAU_REDUC_AGE_60 0.1
#define BATEAU_ASSUR 0.15

#define REPAS 20
#define TVA 0.196

struct prix{
       float standard;
       float initial;
       float repas;
       float reservation;
       float age;
       float assurance;
       float final;
};

//fonction principale
int main(){
    
    //déclaration des variables utilisées (portée locale à la fonction principale)
    int date,moyen,age,carte,confort,repas,annulation;
    float distance,prix_temp,confort_temp,vitesse_temp,reduc_temp,reduc_age_temp, annulation_temp;
    struct prix p;
    
    //Message de bienvenue
    printf("*****************************************************\n");
    printf("* Voyagez en toute tranquilite avec CCI.com.        *\n");
    printf("* Bienvenue sur notre site de reservation en ligne. *\n");
    printf("*****************************************************\n\n");
    
    /*Date de départ
      SI SUPERIEUR A 6 QUITTER
      SINON SI INFERIEUR A 0 QUITTER
      SINON CONTINUER
      FIN SI
    */
    printf("Veuillez d'abord saisir votre date de depart en nombre entier de mois :\n");
    scanf("%d",&date);
    if( date > 6 ){
         printf("Nous sommes desoles, mais nous ne pouvons reserver plus de 6 mois a l'avance.\nAu revoir\n");
    }
    else if(date <0){
         printf("Nous sommes desoles, mais nous ne pouvons pas reserver un trajet dans le passe.\nAu revoir\n");   
    }
    else{
         /*Distance
           SI INFERIEUR A 0 QUITTER
           SINON CONTINUER
           FIN SI
         */
         printf("Veuillez saisir la distance que vous souhaitez parcourir :\n");
         scanf("%f",&distance);
         if( distance < 0 ){
              printf("Nous sommes desoles, mais nous ne pouvons pas effectuer un tel trajet.\nAu revoir\n");
         }
         else{
              /*Moyen de transport : 1 pour l'avion, 2 pour le train, 3 pour le bateau
                SI DIFFERENT DES CHOIX 1 2 ou 3 QUITTER
                SINON CONTINUER
                FIN SI
              */
              printf("Veuillez saisir le moyen de transport choisi :\n");
              printf("- Tapez 1 pour choisir l'avion\n");
              printf("- Tapez 2 pour choisir le train\n");
              printf("- Tapez 3 pour choisir le bateau\n");
              scanf("%d",&moyen);
              if( (moyen != 1) && (moyen != 2) && (moyen != 3)){
                   printf("Nous sommes desoles, mais nous ne connaissons pas ce type de transport.\nAu revoir\n");
              }
              else{
                   /*Age
                     SI INFERIEUR A 0 OU SUPERIEUR A 130 QUITTER
                     SINON 
                          SI SUPERIEUR OU EGAL A 26 ET INFERIEUR OU EGAL A 59 DEMANDER CARTE
                               SI DIFFERENT DE 0 CARTE
                               FIN SI
                          FIN SI
                          
                          SWITCH
                               CAS AVION
                               CAS BATEAU
                               CAS TRAIN                          
                     FIN SI
                   */
                   printf("Veuillez saisir votre age en arrondissant :\n");
                   scanf("%d",&age);
                   if( (age<=0) || (age>130) ){
                        printf("Nous sommes desoles, votre cas ne peut etre couvert par nos assurances.\nAu revoir\n");
                   }
                   else{
                        if( (age >= 26) && (age <=59) ){
                             printf("Avez vous une carte de réduction ?");
                             printf("- Tapez 0 pour non\n");
                             printf("- Tapez 1 pour oui\n");
                             scanf("%d",&carte);
                             if( carte!=0 ){
                                 carte=1;
                             }
                        }
                        
                        switch (moyen){
                             case 1: //sélection des données concernant l'avion
                                     prix_temp = AVION_PS;
                                     vitesse_temp=AVION_VIT;
                                     reduc_temp=AVION_REDUC;
                                     annulation_temp=AVION_ASSUR;

                                     //sélection du confort
                                     printf("Veuillez saisir le confort choisi :\n");
                                     printf("- Tapez 1 pour la premiere classe\n");
                                     printf("- Tapez 2 pour la classe affaires\n");
                                     printf("- Tapez 3 pour la classe economique\n");
                                     scanf("%d",&confort);
                                     if( (confort != 1) && (confort != 2) && (confort != 3)){
                                          printf("Nous sommes desoles, mais nous ne connaissons pas ce type de confort.\nAu revoir\n");
                                          return;
                                     }
                                     else{
                                          if( confort==1 ){confort_temp = AVION_PRE;}
                                          else if(confort == 2){confort_temp = AVION_AFF;}
                                          else{confort_temp = AVION_ECO;}
                                     }
                                     
                                     //reduction selon l'age
                                     if( age <= 12 ){reduc_age_temp=AVION_REDUC_AGE_0_12;}
                                     else if( age <= 25 ){reduc_age_temp=AVION_REDUC_AGE_13_25;}
                                     else if( age <= 59 ){
                                          if(carte==1) {reduc_age_temp=AVION_REDUC_AGE_26_59;}
                                          else {reduc_age_temp=0;}
                                     }
                                     else{reduc_age_temp=AVION_REDUC_AGE_60;}
                        
                                     break;
                             
                             case 2: //sélection des données concernant le train
                                     prix_temp = TRAIN_PS;
                                     vitesse_temp=TRAIN_VIT;
                                     reduc_temp=TRAIN_REDUC;
                                     annulation_temp=TRAIN_ASSUR;

                                     //sélection du confort
                                     printf("Veuillez saisir le confort choisi :\n");
                                     printf("- Tapez 1 pour la premiere classe\n");
                                     printf("- Tapez 2 pour la seconde classe\n");
                                     scanf("%d",&confort);
                                     if( (confort != 1) && (confort != 2)){
                                          printf("Nous sommes desoles, mais nous ne connaissons pas ce type de confort.\nAu revoir\n");
                                          return;
                                     }
                                     else{
                                          if( confort==1 ){confort_temp = TRAIN_PRE;}
                                          else if(confort == 2){confort_temp = TRAIN_SEC;}
                                     }
                                     
                                     //reduction selon l'age
                                     if( age <= 12 ){reduc_age_temp=TRAIN_REDUC_AGE_0_12;}
                                     else if( age <= 25 ){reduc_age_temp=TRAIN_REDUC_AGE_13_25;}
                                     else if( age <= 59 ){
                                          if(carte==1) {reduc_age_temp=TRAIN_REDUC_AGE_26_59;}
                                          else {reduc_age_temp=0;}
                                     }
                                     else{reduc_age_temp=TRAIN_REDUC_AGE_60;}
                                     
                                     break;
                             
                             case 3: //sélection des données concernant le bateau
                                     prix_temp = BATEAU_PS;
                                     vitesse_temp=BATEAU_VIT;
                                     reduc_temp=BATEAU_REDUC;
                                     annulation_temp=BATEAU_ASSUR;

                                     //sélection du confort
                                     printf("Veuillez saisir le confort choisi :\n");
                                     printf("- Tapez 1 pour la premiere classe\n");
                                     printf("- Tapez 2 pour la seconde classe\n");
                                     scanf("%d",&confort);
                                     if( (confort != 1) && (confort != 2)){
                                          printf("Nous sommes desoles, mais nous ne connaissons pas ce type de confort.\nAu revoir\n");
                                          return;
                                     }
                                     else{
                                          if( confort==1 ){confort_temp = BATEAU_PRE;}
                                          else if(confort == 2){confort_temp = BATEAU_SEC;}
                                     }
                                     
                                     //reduction selon l'age
                                     if( age <= 12 ){reduc_age_temp=BATEAU_REDUC_AGE_0_12;}
                                     else if( age <= 25 ){reduc_age_temp=BATEAU_REDUC_AGE_13_25;}
                                     else if( age <= 59 ){
                                          if(carte==1) {reduc_age_temp=BATEAU_REDUC_AGE_26_59;}
                                          else {reduc_age_temp=0;}
                                     }
                                     else{reduc_age_temp=BATEAU_REDUC_AGE_60;}
                                     
                                     break;
                             
                             default: break;
                        }
                        //calcul des prix standard et initial
                        p.standard=prix_temp*distance;
                        p.initial=p.standard*confort_temp;

                        //calcul du nombre de repas
                        repas=(distance/vitesse_temp)/8;
                        p.repas=p.initial + repas * REPAS;
                        
                        //calcul de réduction selon la date
                        p.reservation=p.repas*(1-reduc_temp*date);
                        
                        //calcul du prix age
                        p.age=p.reservation*(1-reduc_age_temp);
                        
                        /*Assurance et calcul du prix assurance
                          SI EGAL A 0 PAS D'ASSURANCE
                          SINON ASSURANCE
                          FIN SI
                        */
                        printf("Voulez-vous souscrire une assurance annulation ?\n");
                        printf("- Tapez 0 pour non\n");
                        printf("- Tapez 1 pour oui\n");
                        scanf("%d",&annulation);
                        if( annulation==0 ){p.assurance=p.age;} 
                        else{p.assurance=p.age*(1+annulation_temp);}
                        
                        //calcul du prix final
                        p.final=p.assurance*(1+TVA);

                        //bilan récapitulatif
                        printf("Voici le bilan recapitulatif :\n\n");
                        if(date!=0){printf("Vous souhaitez partir dans %i mois.\nVous beneficiez de %.0f pour cent de reduction pour la reservation a l'avance.\n",date,100*reduc_temp*date);}
                        else{printf("Vous souhaitez partir maintenant.\nVous ne pouvez pas beneficier de réduction.\n");}
                        printf("La distance choisie est de %.2f km.\n",distance);
                        if(moyen==1){printf("Le moyen de transport choisi est l'avion.\n");}
                        else if(moyen==2){printf("Le moyen de transport choisi est le train.\n");}
                        else{printf("Le moyen de transport choisi est le bateau.\n");}
                        if(confort==1){printf("Vous avez choisi la premiere classe.\n");}
                        else if(confort==2 && moyen!=1 ){printf("Vous avez choisi la seconde classe.\n");}
                        else if(confort==2 && moyen==1 ){printf("Vous avez choisi la classe affaires.\n");}
                        else{printf("Vous avez choisi la classe économique.\n");}
                        if(age==1){printf("Vous avez 1 an.\nVous beneficiez de %.0f pour cent de reduction pour l'age.\n",reduc_age_temp*100);}
                        else{printf("Vous avez %i ans.\nVous beneficiez de %.0f pour cent de reduction pour l'age.\n\n",age,reduc_age_temp*100);}
                        printf("Le prix standard est de : %.2f euros\n",p.standard);
                        printf("Le prix initial est de : %.2f euros\n",p.initial);
                        printf("Le prix avec les repas compris est de  : %.2f euros\n",p.repas);
                        printf("Le prix avec la reduction selon la date de reservation est de : %.2f euros\n",p.reservation);
                        printf("Le prix avec la reduction selon l'age est de : %.2f euros\n",p.age);
                        printf("Le prix avec le choix de l'assurance est de : %.2f euros\n",p.assurance);
                        printf("Le prix TTC est de : %.2f euros\n\n",p.final);
                        printf("Votre billet vous sera envoye dans les meilleurs delais.\nMerci et a bientot.\n");
                   }
              }
         }
    }
} 
