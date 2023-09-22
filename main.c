#include"todo.h"

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
    for (int i = a; i < indice; i++){
        swap(i,i+1);
    }
    indice--;
}

void days_3(){
    int three_D = 86400 * 3;
    for (int i = 0; i < indice; i++){
        if (temps(i) <= three_D){
            afficher(i);
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

time_t temps(int a){
    struct tm date[1];
    time_t currentTime;
    time_t seconds;

    time(&currentTime);
    date[0].tm_mday = tab[a].deadline[0];
    date[0].tm_mon = tab[a].deadline[1];
    date[0].tm_year = tab[a].deadline[2];

    set_start_date(&date[0]);
    seconds = mktime(&date[0]);
    return difftime(seconds, currentTime);
}

void set_start_date(struct tm date[0])
{
    date[0].tm_mon -= 1; // Month is 0-based (0 = January, 1 =>
    date[0].tm_year -= 1900; // Years since 1900
    // Set the remaining fields of the struct tm
    date[0].tm_hour = 0;
    date[0].tm_min = 0;
    date[0].tm_sec = 0;
    date[0].tm_wday = 0;
    date[0].tm_yday = 0;
    date[0].tm_isdst = 0;
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

int rechercher_par_id(int id){
	int i;
	for(i = 0;i<indice;i++){
		if (tab[i].id == id)
			return(i);
	}
	printf("id incorrect\n");
	return (-1);
}

void trier_alpha(){
    for(int i = 0 ;i < indice ; i++){
        for(int j = i+1 ;j < indice ; j++){
            if(strcmp(tab[i].titre, tab[j].titre)>0){
                swap(i,j);
            }
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
	tab[indice].id = indice;
        printf("\nId de tache : %d\nEntrez son titre : ", indice);
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
