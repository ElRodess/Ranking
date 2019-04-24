#include "stdio.h"
#include "stdlib.h"
#include <string.h>
#include "time.h"
#include "Graphe.h"
#include "Powers.h"
#include "Aitken.h"
int main(int argc, char *argv[]){
	int n=0;
	int m=0;
	int i;
	MatCreuse* tableau_arrive = NULL;
	int *E;
	
	if (argv[2] != NULL)
	{
		alpha = atof(argv[2]);
	}
	else 
	{
		alpha = 0.85;
	}
	if(argv[3] != NULL)
	{
		periode = atoi(argv[3]);
	}
	else
	{
		periode = 30;
	}
	
	if(argv[4] != NULL)
	{
		log_aitken = fopen(argv[4], "w");
	}
	else
	{
		log_aitken = fopen("log_aitken.data", "w");
	}
	if(argv[5] != NULL)
	{
		log_power = fopen(argv[5], "w");
	}
	else
	{
		log_power = fopen("log_power.data", "w");
	}
	//~ clock_t start1, finish1;
	clock_t start2, finish2;
	clock_t start3, finish3;	
	
	// lecture graphe etc 
	tableau_arrive = read_fiche(&n,&m,argv[1]);
	
	E = (int*) malloc((n)*sizeof(int)+1);

   
	for(i=0; i<n; i++){
		E[i]=1;
	}
	
	
	printf("\nMatrice creuse est  \n");
	MatCreuse temp;
	for(i=0; i<n; i++) {
		temp = tableau_arrive[i];
		while(temp != NULL){
			//printf("line:%d column:%d :%f\n", temp->ligne,temp->colonne,temp->proba);

			E[(temp->ligne)-1]=0;//definir la valeur de 'f-T (T= E ??)'
			temp = temp->suiv;
		}
	}
	
	//~ printf("\n<<< Methode Power >>>\n");
	//~ start1 = clock();

	//	ranking_matM(tableau_arrive, n);

	//~ finish1= clock();
	//~ printf( "\n%f seconds\n", (double)(finish1-start1) / CLOCKS_PER_SEC);
	
	printf("\n<<< Methode Power Google >>>\n");
	start2 = clock();

	ranking_matG(tableau_arrive,E,n);

	finish2 = clock();
	printf( "\n%f seconds\n", (double)(finish2-start2) / CLOCKS_PER_SEC);
	
	
	printf("\n<<< Methode Aitken >>>\n");
	start3 = clock();

	Aitken(tableau_arrive,E,n);

	finish3 = clock();
	printf( "\n%f seconds\n", (double)(finish3-start3) / CLOCKS_PER_SEC);
	
	free(tableau_arrive);
	free(E);
	
	fclose(log_aitken);
	fclose(log_power);
}
