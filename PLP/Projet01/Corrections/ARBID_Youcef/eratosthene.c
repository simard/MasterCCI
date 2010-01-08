//ARBID Youcef
//exercice 1 : Le crible d’Ératosthène

//Dans cette methode on propose de créer un tableau de 2^32 (le plus grand entier)
//et puis d'initialiser les N premières cases à 0 
//la valeur 0 indique que le nombre n'est pas premier
//lorsqu'il s'agit d'un nombre entier on lui affecte la valeur 1
//pour savoir si un nombre est premier on propose l'optimisation basée sur l'algorithme d’Ératosthène:
//ce nombre ne doit etre divisible par aucun nombre premier inferieur à lui
# include <stdio.h>

main()
{
    int N;    //declaration du nombre entier N
    int i,j;
    int reste; //reste de la division entiere 
    int Tab[2^32];
    printf("crible\n entrer un entier\n"); //demander à l'utilisateur d'entrer la valeur de N
    scanf("%d",&N);         //lecture de N
    
    getchar();
    
    //verifier si N est positif supérieur ou égal à 2
    if(N<2)
    {
           printf("Il faut choisir un nombre entier superieur a 2");
           getchar();
           return 0;
    }    
    
    //initialiser le tableau
    for (i=1; i<=N; i++)
         Tab[i-1] = 0;
    Tab[1] = 1; //correspondant au nombre 2
    
    
    for(i=3; i<=N; i++)     
    {
           j = 2; //l'indice j correspond aux nombres premiers inferieurs à i
           reste = 1; //initialiser le reste à une valeur non nulle
           
           //faire la division du nombre entier i par tous les nombres premiers inferieurs à lui 
           //jusqu'a ce que le reste de la division soi nul
           while(reste|=0 && j<i)
           {             
                   if(Tab[j-1]==1)
                       reste = i%j ;  
                   j++;
           } 
           
           //si i n'est divisible par aucun nombre premier inferieur a lui il,donc il est premier
           if (j==i)
              Tab[i-1] = 1;             
    }

//afficher tous les nombres premiers trouvés
    for (i=1; i<=N; i++)
        if(Tab[i-1] == 1)
           printf("%d\n",i);
           getchar();

}
