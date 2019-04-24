#ifndef __include_Graphe_h__
#include "stdio.h"
#include "stdlib.h"
#include <string.h>


#define __include_Graphe_h__
#define epsilon 1e-6
double alpha ;
struct matriceCreuse{
	float proba;
	int ligne;
	int colonne;
	struct matriceCreuse* suiv;
};

typedef struct matriceCreuse Element;
typedef Element* MatCreuse;

MatCreuse ajout_matrice(MatCreuse mat,float proba, int i, int j);
void initialiser_tab(MatCreuse* tableau_arrive,int *n);
double valeur_absolue(double a, double b);
MatCreuse* read_fiche(int *n,int *m,char* fichier);
#endif 
