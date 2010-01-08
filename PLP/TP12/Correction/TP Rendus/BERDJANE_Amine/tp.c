/*TP12*/
#include <stdio.h>
#include <stdlib.h>


/***************************************************/

typedef struct carnet_adresse {
							char  cNom [256];
							char  cPrenom[256];
							char  cCourriel [256];
							struct carnet_adresse * psuivant;
} carnet;


/********************Fonction supression**********************************/
carnet* supprimer (carnet * p){
	carnet * nouvelle_liste;	
	char rep[256];
	printf("veuillez introduiure le contact que vous vouler supprimer");
	scanf("%s",rep);
	while (p!=NULL){
		if(strcmp(rep,p->cNom)==0){
			
				nouvelle_liste=p->psuivant;
				free (p);
				p=nouvelle_liste;
				p=p->psuivant;
		}
	}
	return p;
}		


/* fonction enregistrement dans un fichier********************/

void enregistrement (carnet * liste){

		FILE * pfichier=NULL;
		
		pfichier=fopen("carnet_d'adresse", "w");
		fprintf(pfichier," Nom:%s", liste->cNom,"\n");
		fprintf(pfichier,"\n");
		fprintf(pfichier, "Prenom:%s",liste->cPrenom,"\n");
		fprintf(pfichier, "\n");
		fprintf(pfichier, "courriel: %s", liste->cCourriel,"\n");
		fprintf(pfichier, "\n");
		//fclose(pfichier);
	}

/******************************Fonction création de contact*******************************/

carnet* creer_contact (carnet * liste){
	carnet * tete = NULL;
	carnet * nouveau= NULL;
		
				
			
			printf("--------------------------------\n");
			printf(" Créer une liste de contact  \n");
			printf("--------------------------------\n");
			liste= (carnet*) malloc (sizeof (carnet));			
			printf("Nom:");
			scanf("%s",&liste->cNom);
			printf("Prenom:");
			scanf("%s", &liste->cPrenom);
			printf("Courriel:");
			scanf("%s", &liste->cCourriel);
			//nouveau=(carnet*) malloc(sizeof(liste));
			
			liste->psuivant=tete;
			tete=liste;
			//nouveau->psuivant=NULL;
					
			
			
		//}	
	
		return tete;

}
		
			
/************************Fonction affichage*****************************************/

void affichage ( carnet * p){
			
	while (p!=NULL){
		printf("Nom: %s\n",p->cNom);
		printf("Prenom: %s\n", p->cPrenom);
		printf("Courriel:%s\n", p->cCourriel);

		p=p->psuivant;
		
		}
		printf("\n");
		return ;
}




int main (int argc, char ** argv){
	
	char reponse ='0';
	carnet *  p;
	carnet * d;
	while( reponse!='5'){
		printf("-----------------------------------\n");
		printf("-                                  \n");
		printf("-		CHOIX              \n");
		printf("-                                  \n");
		printf("-----------------------------------\n");
		printf("1-Ajouter un contact \n");
		printf("2-Supprimer un contact\n");
		printf("3-Afficher tous mes contact\n");
		printf("4-Enregistrement de la liste\n");
		printf("5-Quitter\n");
		printf("---------------------------------------\n");
		scanf("\n%c", & reponse);
		switch (reponse){
			case '1': 
				d=creer_contact(p);
				break;
			case '2' :
				
				d=supprimer(p);
				break;
			case'3':
				affichage(d);
				break;
			case '4':
				enregistrement(p);
				break;
			case '5':
				return 0;
		
		};
	};
return 0;	
}
			
	
	
