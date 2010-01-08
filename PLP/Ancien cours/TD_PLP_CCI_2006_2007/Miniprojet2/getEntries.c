//charge les librairies utilisées
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

//définition de la taille maximale de la chaine que l'on peut rentrer au clavier
#define MAX_SIZE 10

//déclaration des différentes fonctions
void flush_stdin();
void getLine(char[]);
double getNumber(char[]);
char getChar(char[]);
int isNumber(char[]);
double string_to_number(char[]);

/*
  Vide le fichier tampon comportant ce qu'on a rentré au clavier.
  Arguments : 
  Retourne :
*/
void flush_stdin(){
     int c,trop=0;
     while( (c = fgetc(stdin)) != EOF && c != '\n' ){trop=1;}
     if(trop) printf("Seuls les %i premiers caracteres de votre chaine ont ete consideres\n",MAX_SIZE);
}

/*
  Teste si la chaine rentrée au clavier est bien une chaîne ne comportant que des chiffres
  Arguments : 
      - chaine (char[]) : la chaine comportant ce qu'on a rentré au clavier
  Retourne :  
      - int : 1 si la conversion est possible, 0 sinon.
*/
int isNumber(char chaine[]){
    char *err = NULL;
    errno = 0;
    double result = strtod(chaine, &err);
    if (err == chaine) {
        printf("Erreur de conversion\n");
        return 0;
    } 
    else if(errno == ERANGE){
        printf("Erreur de depassement\n");
        return 0;
    } 
    else {
        if(*err == '\0' || (int)*err==MAX_SIZE) {
            return 1;
        }
        else{
            printf("La chaine ne comporte pas que des chiffres\n");
            return 0;
        }
    }
}


/*
  Convertit la chaine de caractères en nombre
  Arguments : 
      - chaine (char[]) : la chaine comportant ce qu'on a rentré au clavier
  Retourne :  
      - double : le nombre correspondant à chaine.
*/
double string_to_number(char chaine[]){
    char *err = NULL;
    return strtod(chaine, &err);
}

/*
  Demande à l'utilisateur de rentrer une chaine de caractères.
  Utilise la fonction fgets qui lit une ligne dans un fichier.
  Le fichier ici est stdin qui est le fichier tampon comportant les rentrées de clavier.
  La boucle for teste si on doit ou pas vider le buffer.
  Arguments : 
      - chaine (char[]) : la chaine qui comportera ce qu'on a rentré au clavier
  Retourne :  
*/
void getLine(char chaine[]){
     int i,end=0;
     fgets(chaine,MAX_SIZE,stdin);
     for(i=0;i<MAX_SIZE;i++){
     	if(chaine[i]=='\n') end=1;
     }
     if(!end) flush_stdin();
}

/*
  Demande à l'utilisateur de rentrer un nombre (double par défaut).
  Tant que l'utilisateur ne rentre pas une chaîne, la fonction reboucle.
  Arguments : 
      - chaine (char[]) : la chaine qui comportera ce qu'on a rentré au clavier
  Retourne :
      - le nombre correspondant à la chaine de caractères rentrée.
*/
double getNumber(char chaine[]){
    do{
        getLine(chaine);
    }while(!isNumber(chaine));
    return string_to_number(chaine);
}

/*
  Demande à l'utilisateur de rentrer un caractère.
  Arguments : 
      - chaine (char[]) : la chaine qui comportera ce qu'on a rentré au clavier
  Retourne : 
      - char : le premier caractère rentré par l'utilisateur
*/
char getChar(char chaine[]){
    getLine(chaine);
    return chaine[0];
}
