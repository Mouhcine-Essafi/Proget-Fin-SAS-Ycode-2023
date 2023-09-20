#include<stdio.h>
#include<stdlib.h>

typedef struct {
	int id;
	char titre[50];
	char description[200];
	int deadline[3];
	char statut[24];

}tache;

//GLOBALES VARIABLES
tache tab[100];
int indice = 0;

void afficher(int a){
        printf("Identifiant (ID): %d\n", tab[indice].id);
        printf("Titre de tache: %s\n", tab[indice].titre);
        printf("Description: %s\n", tab[indice].description);
        printf("Deadline: %d/%d/%d\n", tab[indice].deadline[0], tab[indice].deadline[1], tab[indice].deadline[2]);
        printf("statut: %s\n", tab[indice].statut);
}

void menu()
{
	printf("\nVoici le MENU (selctionner une fonction par taper son nombre) : \n");
	printf("1.Ajouter une nouvelle tâche\n2.Ajouter plusieurs nouvelles tâches\n");
	printf("3.Afficher la liste de toutes les tâches\n");
	printf("4.Modifier une tâche\n5.Supprimer une tâche\n");
	printf("6.Rechercher les Tâches\n7.Statistiques\n");
}

void ajouter(int n){

	int i = 0;

while (i < n){
	tab[indice].id++;
        printf("\nId de tache : %d\nEntrez son titre : ", indice);
        scanf("%s", tab[indice].titre);
        printf("Entrez une description : ");
        scanf("%s", tab[indice].description);
	printf("Entrez un deadline (jj/mm/aaaa): ");
        scanf("%d/%d/%d", &tab[indice].deadline[0], &tab[indice].deadline[1], &tab[indice].deadline[2]);
	printf("Entrez son statut ('To do','Doing','Done'): ");
        scanf("%s", tab[indice].description);
        printf("Tâche ajouté avec succès!\n");
	i++;
	indice++;
	}
}

int main()
{
	int n_f;
	while(1){
	menu();
	printf("Entrer votre choix ,(0) pour quitter : ");
	scanf("%d", &n_f);
	printf("\e[1;1H\e[2J");
	switch(n_f){
		case 0:
			exit(0);
		case 1:
			ajouter(1);
			break;
		case 2:
			int n;
			printf("\nCombien des taches à ajouter ?: ");
			scanf("%d", &n);
			ajouter(n);
			break;
		case 3:
			int i;
			while(i<=indice){
				afficher(i);
				i++;
			}
			break;
		case 4:
			//modifier;
		case 5:
			//supprimer;
		case 6:
			//rechercher;
		case 7:
			//statistique;
		default:
			printf("Invalide fonction\n");
			printf("\e[1;1H\e[2J");
	}
}
return (0);
}
