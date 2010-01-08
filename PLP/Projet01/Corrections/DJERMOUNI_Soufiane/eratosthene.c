/*----------Nom: DJERMOUI; Prénom: Soufiane-------------*/ 

/* ------------------------------ EXERCICE1: Le crible d'eratothène -------------------------------------*/

#include<stdio.h>   

int main( int argc , char ** argv ) 
{   
  // Variables globales 
  
  int i;    
  int j,k;   
  float a;
          
  while(1)   // Pour répéter 
  {  
                   
    /*entrer un entier supérieur à 2*/
    printf("entrer un nombre entier superieur à 2 : \n");     
    scanf("%f",&a);    
    
    i=(int)a;           
    int tab1[i-1];       
    int tab2[i-1];        
    
    if ((i==a)&&(i>=2)) /* on teste si la valeur entrée est un nombre entier supérieur à 2*/
       {    
        for(j=0;j<=i-2;j++)
         {      
           tab1[j]=0;        
           tab2[j]=j+2;        
         }

                                         
        for( j=0;j<=i-2;j++)
         {        
            for(k=j+1;k<=i-2;k++)
            {    
              if((tab2[k]%tab2[j])==0)
               { 
                 tab1[k]=1; 
               }
            }
         }
                              
    printf("le crible d'Eratosthene jusqu'a l'entier %d\n",i);
    for(j=0;j<=i-2;j++)
        {
        if(tab1[j]==0)  
        printf("%d\n",tab2[j]); 
        }
      }
    else /* Si le nombre n'est pas ni entier ni supérieur à deux*/
      { 
       printf(" Message d'erreur\n"); 
      }
   }

    
return 0;

}
