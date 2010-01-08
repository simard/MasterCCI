#include <stdio.h>

//MEHALLA Youghourta
//La crible d'Erastosthène
int main()
{
  int nombre,i,j;
  

  //Acquésition du nombre
  printf("Veillez rentrez un nombre: ");
  scanf("%d",&nombre);
    
  //Création du tableau
  unsigned int tableau [nombre];
   
  //Test
  if (nombre <2)
      {
      printf("Veillez entrez un nombre superieur à deux!!\n");
      }
   else
     //Initialisation à zéro du tableau
     {
     for (i=1;i<nombre;i++)
       {
         tableau[i]=0;
        } 
     //Mettre la première case à 1
         tableau[0]=1;
            
     //Test: On effectue le test pout trouver les nombres entiers 
         for (i=2;i<nombre-1;i++)
            {
                 
              for (j=i+1;j<=nombre;j++) 
                 {
                     if (tableau[i-1]!=1)
                   { 
                    if(j%i==0)
                       {
                           tableau[j-1]=1;
                       }
                   }                 
                 }                  
           
            }

        // Affichage des nombres entiers de 0 à Nombre  
          for (i=0;i<nombre;i++)
             {
               if (tableau[i]==0){ 
               printf(" %d\n",i+1);}
             }
       }


      
 return 0;
}


