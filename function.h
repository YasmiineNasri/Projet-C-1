#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <stdio.h>
typedef struct 
{ int jour;
int mois;
int année;
} date;
typedef struct
{ int ID liste;
char Nom[30];
char prenom[30];
char orientation[10];
char profession[30];
date date_ajout;
int age; } LE;
int Modifier_LE(char* LE, int id, LE L1);
int Supprimer_LE(char* LE, int id);

#endif //HEADER_H_INCLUDED
	
