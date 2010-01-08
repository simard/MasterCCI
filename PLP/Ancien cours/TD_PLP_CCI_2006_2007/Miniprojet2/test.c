#include <stdio.h>
#include "getEntries.c"

int main(){
    char chaine[MAX_SIZE];
    printf("Rentrez un nombre\n");
    double i = getNumber(chaine);
    printf("la valeur en double du nombre rentre au clavier est : %.3f\n",i);
    int y = (int) i;
    printf("la valeur entiere du nombre rentre au clavier est : %i\n",y);
    printf("Rentrez une chaine de caracteres\n");
    getLine(chaine);
    printf("la chaine rentree au clavier est : %s\n",chaine);
    printf("Rentrez un caractere\n");
    char c=getChar(chaine);
    printf("le caractere rentre au clavier est : %c\n",c);
}
