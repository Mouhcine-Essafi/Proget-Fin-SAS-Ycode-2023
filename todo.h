#ifndef TODO_H
#define TODO_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

typedef struct {
	int id;
	char titre[50];
	char description[100];
	int deadline[3];
	char statut[50];

}tache;


//declaration fonction
void trier_alpha();
void swap(int i, int j);
void afficher(int a);
void menu();
void ajouter(int n);
int rechercher_par_id(int id);
void modifier(int i_mod);
void trier_deadline();
time_t temps(int a);
void modifier(int i_mod);
void days_3();
void supprimer(int a);
int rechercher_par_titre(char r_titre[]);
void statistiques();

#endif