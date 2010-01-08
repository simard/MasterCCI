/*définition d'un fichiaer d'en-tête*/
#ifndef SNAKE_H
#define SNAKE_H

/*définition  d'un nouveau type uint   pour abrévier l'écriture*/
typedef unsigned int uint;

/*définition d'une variable énumérée qui correspond aux quatre directions possibles d'un serpent*/
typedef enum   t_eDir {
			HAUT = 94,
			BAS = 118,
			GAUCHE = 60,
			DROITE = 62,
}eDir;

/*définition d'un nouveau type de structure t_Serpent*/
typedef struct {
		      char   forme; /* ex: '>' , '<' , v',..etc*/
		      uint   HSerpent; /*position ligne d'un serpent*/
		      uint   LSerpent; /*position colonne d'un serpent*/
		      eDir   Direction; /*direction d'un serpent*/
}t_Serpent;

/*définition d'un nouveau type de structure t_Cadre*/
typedef struct  {
		      uint Largeur;
		      uint Hauteur;
}t_Cadre;


 
/*prototypes des fonctions*/
void Env_Serpent(char Env[], t_Serpent  Serpent, t_Cadre  Cadre);

void Mouv_Droite(char Env[], t_Serpent  Serpent, t_Cadre  Cadre);

void Init_Env(char Env[], t_Cadre Cadre);

void Affiche(char Env[], t_Cadre Cadre);

void Attendre (uint   ms); /*ms pour MilliSecondes*/

t_Serpent Pos_Hasard(t_Cadre Cadre);

#endif
