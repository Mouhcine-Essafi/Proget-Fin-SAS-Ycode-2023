#include "todo.h"

extern int indice;
extern tache tab[100];

void trier_alpha(){
    for(int i = 0 ;i < indice ; i++){
        for(int j = i+1 ;j < indice ; j++){
            if(strcmp(tab[i].titre, tab[j].titre)>0){
                swap(i,j);
            }
        }
    }
}

void trier_deadline(){
    for(int i = 0 ;i < indice ; i++){
        for(int j = i+1 ;j < indice ; j++){
            if(temps(i) > temps(j)){
                swap(i,j);
            }
        }
    }
}

void days_3(){
    int trois_j = 86400 * 3;
    for (int i = 0; i < indice; i++){
        if (temps(i) <= trois_j){
            afficher(i);
        }
    }
}

void swap( int i, int j){
	tache temp;

	temp.id = tab[i].id;
	tab[i].id = tab[j].id;
	tab[j].id = temp.id;

	temp.deadline[0] = tab[i].deadline[0];
	tab[i].deadline[0] = tab[j].deadline[0];
	tab[j].deadline[0] = temp.deadline[0];

	temp.deadline[1] = tab[i].deadline[1];
	tab[i].deadline[1] = tab[j].deadline[1];
	tab[j].deadline[1] = temp.deadline[1];

	temp.deadline[2] = tab[i].deadline[2];
	tab[i].deadline[2] = tab[j].deadline[2];
	tab[j].deadline[2] = temp.deadline[2];

	strcpy(temp.titre,tab[i].titre);
	strcpy(tab[i].titre,tab[j].titre);
	strcpy(tab[j].titre,temp.titre);

	strcpy(temp.description,tab[i].description);
	strcpy(tab[i].description,tab[j].description);
	strcpy(tab[j].description,temp.description);

	strcpy(temp.statut,tab[i].statut);
	strcpy(tab[i].statut,tab[j].statut);
	strcpy(tab[j].statut,temp.statut);
}
