// TP noté : gestion d'un répertoire
// 07/11/08
// Benoit Lafeuillade


# include <stdio.h>
# include <stdlib.h>
# include <string.h>

/* fonctions :
	- initialisation d'un contact => DONE
	- remplissage d'un contact => DONE
	- présence d'un nom dans le répertoire => DONE
	- ajout contact dans carnet => cf remplissage contact (dernières lignes de la fonction), problème nopn réglé
	- supprimer contact => DONE
	- libérer mémoire pour 1 contact => DONE
	- libérer mémoire pour tous les contacts => DONE, non testé
	- sauvegarde du carnet => DONE
	- affichage d'un contact => DONE
	- modification d'un contact => DONE, non testé
	- recherche d'un contact (retourne null si pas de contact) => DONE
	- charger un carnet => DONE, non fonctionnel
	- affichage du menu => DONE
	- fermer un carnet => DONE
*/



//******************************************************************************************************//
//                                                                                                      //
//                                                                                                      //
//                                  Structures et variables globales                                    //
//                                                                                                      //
//                                                                                                      //
//******************************************************************************************************//



int ouvert = 0; // la variable ouvert va déterminer si un carnet est ouvert au moment où l'utilisateur tente de lire ou d'enregistrer
char nom_repertoire[100]; // permet de garder en mémoire le nom du répertoire, afin de ne pas avoir à le redemander lors de la sauvegarde

typedef struct sContact
{
	char *cNom;
	char *cPrenom;
	char *cCourriel;
	struct sContact *pSuivant;
} contact;





//******************************************************************************************************//
//                                                                                                      //
//                                                                                                      //
//                                            Fonctions                                                 //
//                                                                                                      //
//                                                                                                      //
//******************************************************************************************************//




// *********************************************************** vide_tampon
void videtampon() // fonction qui vide la mémoire tampon
{
	int c = 0; 
	while (c != '\n' && c != EOF)
	{
		c = getchar();
	}
	
	return;
}


// *********************************************************** affichage d'un unique contact
void affichage(contact *temp)
{
	printf("Adresse de %s %s : %s\n\n", (*temp).cNom, (*temp).cPrenom, (*temp).cCourriel);

	return;
}


// *********************************************************** nom_present
int nom_present (char *nom, contact *repertoire) // fonction de recherche de la présence d'un nom spécifique dans le répertoire
{
	int i = 1;
	contact *curseur = repertoire;
	
	while(curseur != NULL)
	{
		i = strcmp(nom, (*curseur).cNom);

		curseur = (*curseur).pSuivant;
		if (i == 0)
			break;

	}
	
	return i;
}





// *********************************************************** désallouer
void desallouer(contact *personne)
{
	(*personne).cNom = NULL;
	free((*personne).cNom);
	(*personne).cPrenom = NULL;
	free((*personne).cPrenom);
	(*personne).cCourriel = NULL;
	free((*personne).cCourriel);
	free((*personne).pSuivant);
	
	free(personne);
	
	return;	
}







// *********************************************************** recherche
contact *recherche(contact *repertoire, char *nom, char *prenom)
{
	int i,j;
	
	contact *temp = NULL;
	contact *curseur = repertoire;
	
	while(curseur != NULL) // parcours du répertoire
	{
		i = 1;
		j = 1;
		i = strcmp(nom, (*curseur).cNom); // strcmp renvoie 0 si les 2 chaines à comparer sont égales
		if (i == 0)
		{
			j = strcmp(prenom, (*curseur).cPrenom);
			if (j == 0)
			{
				temp = curseur;
				break; // dès que le programme trouve un contact correspondant aux nom & prenom, il arrete le while, et renvoir temp, qui aura la valeur du contact trouvé
			}
		}
		curseur = (*curseur).pSuivant;
	}
	return temp;
}





// *********************************************************** allouer
contact *allouer(int n, int p, int a)
{
	contact *temp;
	temp = (contact *) malloc (sizeof(contact));
	
	(*temp).cNom = (char *) malloc (n * sizeof(char));
	(*temp).cPrenom = (char *) malloc (p * sizeof(char));
	(*temp).cCourriel = (char *) malloc (a * sizeof(char));
	(*temp).pSuivant = NULL;
	
	return temp;
}



// *********************************************************** affichage de tous les contacts du répertoire appelé
void affichage_tout(contact *repertoire)
{
	contact *curseur = repertoire;
	
	while(curseur != NULL)
	{
		affichage(curseur);
		curseur = (*curseur).pSuivant;
	}
	
	return;
}



// *********************************************************** affichage de tous les contacts correspondant à un nom/prenom donné
void affichage_plusieur(contact *repertoire, char *nom, char *prenom)
{
	contact *curseur = NULL;
	int c = 0;
	
	curseur = recherche(repertoire, nom, prenom);
	
	if(curseur == NULL)
		printf("Il n'y a pas de contact %s %s dans le répertoire.\n", nom, prenom);
	else
	{
		while(c == 0)
		{
			c = 1;
			affichage(curseur); // affichage de l'adresse
				
			if((*curseur).pSuivant != NULL)
			{
				if((*curseur->pSuivant).cNom == nom && (*curseur->pSuivant).cPrenom == prenom) // recherche si seconde adresse associée au nom & prenom
					c = 0;
			}
		}
	}
	
	return;
}


// *********************************************************** ajout
contact *ajout(contact *repertoire)
{
	char nom[256];
	char prenom[256];
	char adresse[256];
	int verif = 1; // verif = variable qui vérifie que l'adresse saisie est de la bonnne forme (***@**.**)
	int c = 1; // c = variable qui vérifie que le choix d'ajouter un nom/prénom est bien correct
	char choix;
	contact *temp;
	contact *aj;
	
	printf("Ajout d'un contact.\n");
	
	printf("Entrez le nom du contact :");
	scanf("%s", nom);
	if (nom_present(nom, repertoire) == 0)
	{
		printf("Nom déjà présent, voulez vous ajoutez un autre contact avec le même nom? (o/n)\n");
		while (c != 0)
		{
			videtampon();
			scanf("%c", &choix);
			
			if ( &c == NULL)
			{
				printf("Choix incorrect. (o/n)\n");
			}
			else if (choix == 'n' || choix == 'N')
			{
				printf("Retour au menu.\n");
				return repertoire;
			}
			else if (choix == 'o' || choix == 'O')
			{
				printf("Poursuite de la saisie.\n");
				c = 0;
			}
			else
			{
				printf("Choix incorrect. (o/n)\n");
			}
		}
	}
	
	c = 1;
	// 2nde étape, saisie du prénom du contact
	printf("Entrez le prénom du contact: ");
	scanf("%s", prenom);
	if (recherche(repertoire, nom, prenom) != NULL)
	{			// vérification présence contact
		printf("Ce contact existe déjà. Ajouter quand même une adresse? (o/n)\n");
		while (c != 0)
		{
			videtampon();
			scanf("%c", &choix);
			if ( &c == NULL)
			{
				printf("Choix incorrect. (o/n)\n");
			}
			else if (choix == 'n' || choix == 'N')
			{
				printf("Retour au menu.\n");
				return repertoire;
			}
			else if (choix == 'o' || choix == 'O')
			{
				printf("Poursuite de la saisie.\n");
				c = 0;
			}
			else
			{
				printf("Choix incorrect. (o/n)\n");
			}
		}
	}
	
	c = 1;
	videtampon();
	
	temp = (contact *) malloc (sizeof(contact));
	(*temp).cNom = (char *) malloc (strlen(nom) * sizeof(char));
	(*temp).cPrenom = (char *) malloc (strlen(prenom) * sizeof(char));
	(*temp).cCourriel = (char *) malloc (strlen(adresse)* sizeof(char));
	(*temp).pSuivant = NULL;
	
	temp = recherche(repertoire, nom, prenom);
	
	printf("Saisissez l'adresse du contact: ");
	while (verif != 0)
	{
		scanf("%s", adresse);
		if(temp != NULL)
		{
			if ((*temp).cCourriel == adresse)
			{
				printf("L'adresse a déjà été enregistrée dans ce contact. Retour au menu.\n"); // impossibilité d'avoir 2 contacts identiques dans le répertoire
				return repertoire;
			}
		}
		else // vérifie que l'adresse est sous la forme xxxx@xxx.xx
		{
			int i = 0;
			int j = 0;
			while (adresse[i] != '@' && adresse[i]!= '\0')
			{
				i++;
			}
			j = i;
			while (adresse[j] != '.' && adresse[i] != '\0')
				j++;
			
			if (adresse[i] != '@' || adresse[j] != '.')
					printf("L'adresse entrée est dans un format erronée.\n");
			else
				verif = 0;			
		}
	}
	//suppression contact temporaire
	free(temp);

	//allocation mémoire pour contact à ajouter

	aj = allouer(strlen(nom), strlen(prenom), strlen(adresse));

	//initialisation contact à ajouter par les données entrées
	strcpy((*aj).cNom, nom);
	strcpy((*aj).cPrenom, prenom);
	strcpy((*aj).cCourriel, adresse);

	// ajout du nouveau contact en tête de répertoire
	(*aj).pSuivant = repertoire;
	repertoire = aj;
	free(aj);
	
	return repertoire;
}




// *********************************************************** supprimer
contact *supprimer(contact *repertoire, contact *personne)
{
	contact *curseur = repertoire;
	contact *precedent;
	contact *temp;
	
	while((*curseur).pSuivant != personne && curseur != NULL)
		curseur = (*curseur).pSuivant;
		
	precedent = curseur;
	temp = (*precedent).pSuivant;
	(*precedent).pSuivant = (*curseur).pSuivant;
	
	if (curseur != NULL)
		desallouer(curseur);
	
	return repertoire;
}




// *********************************************************** supprimer_carnet
contact *supprimer_carnet(contact *repertoire)
{
	contact *curseur = repertoire;
	contact *precedent;
	
	while(curseur != NULL)
	{
		precedent = curseur;
		curseur = (*curseur).pSuivant;
		if(precedent != NULL)
		{
			desallouer(precedent);		
		}
	}
	
	return NULL;
}





// *********************************************************** modifier
contact *modifier(contact *repertoire, char *nom, char *prenom)
{
	contact *curseur;
	char *pn;
	char *nm;
	char *ad;
	char choix = 0;
	int verif;
	int c = 0; // permet de trouver le bon contact, s'il y en a plusieurs portant les mêmes noms / prénoms
	
	printf("Modification d'un contact.\n");
	
	curseur = recherche(repertoire, nom, prenom);
	
	if(curseur == NULL)
		printf("Ce contact n'est pas présent.\n");
	else
	{
		while(c == 0 && (*curseur).cNom == nom && (*curseur).cPrenom == prenom)
		{
			affichage(curseur);
			printf("Souhaitez-vous modifier ce contact? (o/n)\n");
			scanf("%c", &choix);
			videtampon();
			
			if(choix == 'o' || choix == 'O')
				c = 1;
			else
			{
				if((*curseur).pSuivant != NULL)
					curseur = (*curseur).pSuivant;
				else
					printf("Pas d'autre contact avec ce nom et prénom. Retour au menu principal.\n");
					return repertoire;
			}
		}
	}
	if (c == 1)
	{
		while( choix != 'a' || choix != 'A')
		{
			// affichage menu pour la modification
			printf("Que souhaitez vous modifier?\n");
			printf("p - prenom\n");
			printf("n - nom\n");
			printf("c - courriel\n");
			printf("s - supprimer\n");
			printf("a - annuler\n");
				scanf("%s", &choix);
			videtampon();
			
			switch (choix)
			{
				case 'p' :
				case 'P' :
						verif = 0;
						printf("Entrez le nouveau prénom.\n");
						while (verif == 0)
							{
							verif = 1;
							if(scanf("%s", pn) != 0)
								strcpy((*curseur).cPrenom, pn);
							else
							{	
								printf("Saisie invalide. Veuillez recommencer.\n");
								verif = 0;
							}
						}
							choix = 'a';
						break;
						
				case 'n' :
				case 'N' :
						verif = 0;
						printf("Entrez le nouveau nom.\n");
						while (verif == 0)
						{
							verif = 1;
							if(scanf("%s", nm) != 0)
								strcpy((*curseur).cNom, nm);
							else
							{	
									printf("Saisie invalide. Veuillez recommencer.\n");
								verif = 0;
							}
						}
						choix = 'a';
						break;
							
				case 'c' :
				case 'C' :
						verif = 0;
							printf("Entrez la nouvelle adresse courriel.\n");
						while (verif == 0)
						{
								if(scanf("%s", ad)!= 0)
							{
								verif = 0;
								int i = 0;
								int j = 0;
								while (ad[i] != '@' && ad[i]!= '\0')
								{
										i++;
								}
								j = i;
								while (ad[j] != '.' && ad[i] != '\0')
									j++;
							
								if (ad[i] != '@' || ad[j] != '.')
								{
									printf("L'adresse entrée est dans un format erronée.\n");
									verif = 0;
								}
								else
									strcpy((*curseur).cCourriel, ad);
							}
						}
						choix = 'a';
						break;
						
				case 's' :
				case 'S' :
						verif = 1;
						repertoire = supprimer(repertoire, curseur);
						choix = 'a';
						break;
						
				case 'a' :
				case 'A' :
						break;
						
				default :
						printf("Saisie incorrecte, veuillez recommencer.\n");
			} 
		}
	}		
	
	return repertoire;
}

// ********************************************************* charger

contact *charger()
{
	contact *repertoire = NULL;
	contact *temp;
	FILE *fichier;
	char nom_fichier[50];
	char nom[256];
	char prenom[256];
	char adresse[256];
	int i = 0;
	
	printf("Entrez le nom du répertoire que vous souhaitez ouvrir.\n");
	
	scanf("%s", nom_fichier);
	printf("nia\n");
	fichier = fopen(nom_fichier, "r");
	printf("nia\n");
	if (fichier == NULL)
		printf("Fichier introuvable. Retour au menu.\n");
	else
	{
		while(i != 3)
		{
			fscanf(fichier, "Nom : %s\n", nom);
			fscanf(fichier, "Prenom : %s\n", prenom);
			fscanf(fichier, "Adresse : %s\n\n", adresse);
			temp = allouer(strlen(nom), strlen(prenom), strlen(adresse));
			
			strcpy((*temp).cNom, nom);
			strcpy((*temp).cPrenom, prenom);
			strcpy((*temp).cCourriel, adresse);
			
			printf("%s\n", (*temp).cNom);
			printf("%s\n", (*temp).cPrenom);

			
			if(repertoire == NULL)
			{
				repertoire = allouer(strlen(nom), strlen(prenom), strlen(adresse));
				repertoire = temp;
			}
			else
			{
				(*temp).pSuivant = repertoire;
				repertoire = temp;
			}

			i = i+1;

			
		}	
		
		fclose(fichier);	
		ouvert = 1;
		strcpy(nom_repertoire, nom_fichier);
	}
			

	return repertoire;
}


// ********************************************************* sauver
void sauver(contact *repertoire)
{
	FILE *fichier;
	contact *curseur = repertoire;
	fichier = fopen(nom_repertoire, "w");
	
	while(curseur != NULL)
	{
		fprintf(fichier, "Nom : %s\n", (*curseur).cNom);
		fprintf(fichier, "Prenom : %s\n", (*curseur).cPrenom);
		fprintf(fichier, "Adresse : %s\n\n", (*curseur).cCourriel);
		
		curseur = (*curseur).pSuivant;
	}
	
	fclose(fichier);
	
	return;
}



// ******************************************************** affichage du menu
int menu()
{	
	int choix = 0;
	
	while (choix == 0)
	{
		printf("\n***************************************\n");
		printf("***************** MENU ****************\n");
		printf("***************************************\n\n");
	
		printf("1 - Charger un répertoire.\n");
		printf("2 - Creer un nouveau carnet d'adresses.\n");
		printf("3 - Afficher un contact.\n");
		printf("4 - Afficher tous les contacts.\n");
		printf("5 - Ajouter un contact au répertoire courant.\n");
		printf("6 - Modifier ou supprimer un contact.\n");
		printf("7 - Sauvegarder le répertoire courant.\n");
		printf("8 - Fermer le répertoire courant.\n");
		printf("9 - Quitter sans sauver les modifications courantes.\n\n");
		
		printf("Choix : ");
		if(scanf("%d", &choix) != 0)
		{
			if(choix < 1 || choix > 9)
			{
				printf("Choix incorrect, veuillez recommencer.\n");
				choix = 0;
			}
			else
			{
				videtampon();
			}
		}
		else
		{
			printf("Saisie incorrecte.\n");
			choix = 0;
			videtampon();
		}
	}
	
	return choix;
}



// ******************************************************** fermeture d'un répertoire
void fermer()
{
	strcpy(nom_repertoire, "void");
	ouvert = 0;
	return;
}


// ******************************************************** création d'un repertoire
contact *creer(char *name)
{
	strcpy(nom_repertoire, name);
	ouvert = 1;
	
	return NULL;
}


// ******************************************************** création d'un repertoire
int fin(char *name)
{
	int lg = strlen(name);
	
	if(name[lg-1] != 't' || name[lg-2] != 'x' || name[lg-3] != 't' || name[lg-4] != '.' )
		return 1;
	else
		return 0;
}
	

//******************************************************************************************************//
//                                                                                                      //
//                                                                                                      //
//                                        Corps du programme                                            //
//                                                                                                      //
//                                                                                                      //
//******************************************************************************************************//







int main (int argc, char **argv)
{
	int choix = 0;
	int verif = 0;
	char name[100];
	char nom[256];
	char prenom[256];
	contact *repertoire = NULL;

	while(choix != 9)
	{
		choix = menu();
		
		switch(choix)
		{
			case 1 :
				if (ouvert == 1)
					printf("Un répertoire est déjà actif.\n");
				else
				{
					repertoire = charger();
				}
				break;
				
			case 2 :
				if (ouvert == 1)
					printf("Un répertoire est déjà actif.\n");
				else
				{
					printf("Entrez le nom du répertoire que vous voulez créer.\n");
					while(verif == 0)
					{
						verif = 1;
						if (scanf("%s", name) == 0)
						{
							printf("Saisie incorrecte. Veuillez entrez un nom de répertoire correct.\n");
							verif = 0;
						}
						else
						{
							if(fin(name) != 0) // vérifie que le nom entré est de la forme *.txt
							{
								printf("Le nom doit être sous la forme ***.txt . Veuillez entre un nom de répertoire correct.\n");
								verif = 0;
							}
							else
								repertoire = creer(name);
						}
					}
				}	
				break;
			
			case 3 :
				if (ouvert == 0)
					printf("Ouvrez ou créez d'abord un répertoire.\n");
				else
				{
					printf("Entrez le nom du contact à chercher.\n");
					scanf("%s", nom);
					printf("Entrez le prénom du contact à \n");
					scanf("%s", prenom);
					affichage_plusieur(repertoire, nom, prenom);
				}
				break;
				
			case 4 :
				if (ouvert == 0)
					printf("Ouvrez ou créez d'abord un répertoire.\n");
				else
				{
					affichage_tout(repertoire);
				}
				break;
				
			case 5 :
				if (ouvert == 0)
					printf("Ouvrez ou créez d'abord un répertoire.\n");
				else
				{
					repertoire = ajout(repertoire);
					affichage(repertoire);
				}
				break;
			
			case 6 :
				if (ouvert == 0)
					printf("Ouvrez ou créez d'abord un répertoire.\n");
				else
				{
					printf("Entrez le nom du contact à chercher.\n");
					scanf("%s", nom);
					printf("Entrez le prénom du contact à \n");
					scanf("%s", prenom);
					repertoire = modifier(repertoire, nom, prenom);
				}
				break;
				
			case 7 :
				if (ouvert == 0)
					printf("Ouvrez ou créez d'abord un répertoire.\n");
				else
				{
					sauver(repertoire);
				}
				break;
				
			case 8 :
				repertoire = supprimer_carnet(repertoire);
				fermer();
				break;
				
			default :
				choix = 9;
		}
	}
							
							
							
							
		
	printf("_______________________________\n");
	printf("Fin du programme. Merci d'avoir utilisé la Ben & Co' Company.\n");
	return 0;
}
