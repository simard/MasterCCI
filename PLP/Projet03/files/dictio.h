# ifndef __DICTIO_H__
# define __DICTIO_H__

# include <stdlib.h>
# include <stdio.h>
# include <string.h>

# define TAILLE_TAMPON 64

typedef struct sMot
{
	char * mot;
	char * lang;
	struct sMot * suiv;
} Mot;

typedef struct sDictionnaire
{
	unsigned int id;
	Mot * m;
	struct sDictionnaire * suiv;
} Dictionnaire;

Mot * ajouter_mot( Mot * const m, char * const newMot, char * const newLang );
Dictionnaire * ajouter_trad( Dictionnaire * const d, unsigned char const id, char * const newMot, char * const newLang );
void ecrire_mot( FILE * fFichier, Mot * const m );
void ecrire_dictionnaire( Dictionnaire * const d, const char * nomFichier );
Dictionnaire * lire_dictionnaire( const char * nomFichier );

# endif /* __DICTIO_H__ */
