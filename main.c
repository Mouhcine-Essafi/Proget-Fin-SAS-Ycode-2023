#include "todo.h"

int indice = 0;
//GLOBALES VARIABLES
tache tab[100];

//les fonction

void statistiques() {
	int taches_c = 0;
	int taches_inc = 0;
    printf("******Statistiques******\n");
    printf("Nombre total des tâches : %d\n", indice);
	for (int i = 0; i < indice; i++) {
		if (!strcasecmp(tab[i].statut, "Done")) {
			taches_c++;
		}
		else
			taches_inc++;
	}
	printf("Le nombre des tâches complètes : %d\n", taches_c);
	printf("Le nombre des tâches incomplètes : %d\n", taches_inc);
	printf("\nChaque tâche avec leur Délai :\n");

	for (int i = 0; i < indice; i++) {
	int t = temps(i);
		int j_r = t / (60 * 60 * 24) + 1;
	afficher(i);
		printf("Délai : %d\n", j_r);
	}
}

time_t temps(int a){
    struct tm date;
    time_t currentTime;
    time_t seconds;

    time(&currentTime);
    date.tm_mday = tab[a].deadline[0];
    date.tm_mon = tab[a].deadline[1] - 1;
    date.tm_year = tab[a].deadline[2] - 1900;
    date.tm_hour = 0;
    date.tm_min = 0;
    date.tm_sec = 0;

    seconds = mktime(&date);
    return difftime(seconds, currentTime);
}

void modifier(int i_mod){
	int x;
	char new_dis[100];
	char new_stat[50];

		printf("1.Modifier la description\n2.Modifier le statut\n3.Modifier le deadline\n");
		printf("Taper l'option : ");
		scanf("%d", &x);
		switch(x){
			case 1:
				printf("Entrer la nouvelle description : ");
				scanf(" %[^\n]", new_dis);
				strcpy(tab[i_mod].description, new_dis);
				break;
			case 2:
				printf("Entrer le nouvelle statut : ");
                                scanf(" %[^\n]", new_stat);
                                strcpy(tab[i_mod].statut, new_stat);
				break;
			case 3:
				printf("Entrer le nouvelle deadline (jj/mm/aaaa) :");
				scanf("%d/%d/%d",  &tab[i_mod].deadline[0], &tab[i_mod].deadline[1], &tab[i_mod].deadline[2]);
				break;
			default:
				printf("Invalid option !");
				break;
			}
		}

void afficher(int a){
	if (a >= 0){
        printf("\nIdentifiant (ID): %d\n", tab[a].id);
        printf("Titre de tache: %s\n", tab[a].titre);
        printf("Description: %s\n", tab[a].description);
        printf("Deadline: %d/%d/%d\n", tab[a].deadline[0], tab[a].deadline[1], tab[a].deadline[2]);
        printf("statut: %s\n", tab[a].statut);
	}
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
	tab[indice].id = indice + 101;
        printf("\nId de tache : %d\nEntrez son titre : ", tab[indice].id);
        scanf(" %[^\n]", tab[indice].titre);
        printf("Entrez une description : ");
        scanf(" %[^\n]", tab[indice].description);
	printf("Entrez un deadline (jj/mm/aaaa): ");
        scanf("%d/%d/%d", &tab[indice].deadline[0], &tab[indice].deadline[1], &tab[indice].deadline[2]);
	printf("Entrez son statut ('To do','Doing','Done'): ");
        scanf(" %[^\n]", tab[indice].statut);
        printf("Tâche ajouté avec succès!\n");
	i++;
	indice++;
	}
}
//programme
int main()
{
	int n_f;
	while(1){
	menu();
	printf("Entrer votre choix ,(0) pour quitter : ");
	scanf("%d", &n_f);
	switch(n_f){
		case 0:	printf("\e[1;1H\e[2J");
			exit(0);
		case 1:	printf("\e[1;1H\e[2J");
			ajouter(1);
			break;
		case 2:	printf("\e[1;1H\e[2J");
			int n;
			printf("\nCombien des taches à ajouter ?: ");
			scanf("%d", &n);
			ajouter(n);
			break;
		case 3:	printf("\e[1;1H\e[2J");
			int aff;
			int i3;

			printf("1.Afficher les tâches trier par ordre alphabétique\n");
			printf("2.Afficher les tâches trier par deadline.\n");
			printf("3.Afficher les tâches dont le deadline est dans 3 jours ou moins\n");
			printf("Taper de quel manière tu veux l'afficher : ");
			scanf(" %d", &aff);
			switch(aff){
				case 1:
					i3=0;
					trier_alpha();
					 while(i3<indice){
						afficher(i3);
                        			i3++;
                        			}
					break;
				case 2:
					i3 = 0;
					trier_deadline();
					while(i3<indice){
                        			afficher(i3);
                        			i3++;
                        			}
					break;
				case 3:
					days_3();
					break;
				default:
					printf("Invalid option !");
					break;
				}
			break;
		case 4:
			printf("\e[1;1H\e[2J");
			int i4 = 0;
			printf("Entrer l'id : ");
			scanf(" %d",&i4);
			modifier(rechercher_par_id(i4));
			break;
		case 5:
			printf("\e[1;1H\e[2J");
			int i5 = 0;
                        printf("Entrer l'id : ");
                        scanf(" %d",&i5);
			supprimer(rechercher_par_id(i5));
			break;
		case 6:
			printf("\e[1;1H\e[2J");
			printf("1.Rechercher une tâche par son Id.\n");
			printf("2.Rechercher une tâche par son titre.\n");
			printf("Taper l'option : ");
			int i6 = 0;
			scanf("%d", &i6);
			switch(i6){
				case 1:
					int r;
					printf("Entrer l'id : ");
					scanf("%d", &r);
					afficher(rechercher_par_id(r));
					break;
				case 2:
					char r_titre[50];
                                        printf("Entrer le titre : ");
                                        scanf(" %[^\n]", r_titre);
                                        afficher(rechercher_par_titre(r_titre));
					break;
				default :
					printf("Invalid option !\n");
					break;
			}
			break;
		case 7:
			printf("\e[1;1H\e[2J");
			statistiques();
                        break;
		default:
			printf("\e[1;1H\e[2J");
			printf("Invalide fonction\n");
			break;
	}
}
return (0);
}
