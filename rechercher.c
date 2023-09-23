#include "todo.h"

extern int indice;
extern tache tab[100];

int rechercher_par_id(int id){
	int i;
	for(i = 0;i<indice;i++){
		if (tab[i].id == id)
			return(i);
	}
	printf("id incorrect\n");
	return (-1);
}

int rechercher_par_titre(char r_titre[]){
	int i;
		for(i = 0;i<indice;i++){
		if (!strcasecmp(tab[i].titre, r_titre))
			return(i);
        }
        if (i = indice){
                printf("titre incorrect\n");
                return (-1);
        }
}

void supprimer(int a){
    if (a >= 0){
    for (int i = a; i < indice; i++){
        swap(i,i+1);
    }
    indice--;
    }
}