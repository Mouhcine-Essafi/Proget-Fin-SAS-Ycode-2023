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

//GLOBALES VARIABLES
tache tab[100];
int indice = 0;

//declaration fonction
void trier_alpha();
void swap(int i, int j);
void afficher(int a);
void menu();
void ajouter(int n);
int rechercher(int id);
void modifier(int i_mod);
void set_start_date(struct tm date[]);
void trier_deadline();
time_t temps(int a);
void set_start_date(struct tm date[]);
void modifier(int i_mod);
void days_3();

//les fonction

void days_3(){
    const int three_D = 86400 * 3;
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

void set_start_date(struct tm date[])
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
			case 1:printf("Entrer la nouvelle description : ");
				scanf("%[^\n]", new_dis);
				strcpy(tab[i_mod].description, new_dis);
				break;
			case 2:printf("Entrer le nouvelle statut : ");
                                scanf("%[^\n]", new_stat);
                                strcpy(tab[i_mod].statut, new_stat);
				break;
			case 3:printf("Entrer le nouvelle deadline (jj/mm/aaaa) :");
				scanf("%d/%d/%d",  &tab[indice].deadline[0], &tab[indice].deadline[1], &tab[indice].deadline[2]);
				break;
			default:
				printf("Invalid option !");
				break;
			}
		}

        

int rechercher(int id){
	for(int i = 0;i<indice;i++){
	if (tab[i].id == id)
		return(i);
	}
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
        printf("Identifiant (ID): %d\n", tab[a].id);
        printf("Titre de tache: %s\n", tab[a].titre);
        printf("Description: %s\n", tab[a].description);
        printf("Deadline: %d/%d/%d\n", tab[a].deadline[0], tab[a].deadline[1], tab[a].deadline[2]);
        printf("statut: %s\n", tab[a].statut);
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
        scanf("%s", tab[indice].statut);
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
			int i;

			printf("1.Afficher les tâches trier par ordre alphabétique\n");
			printf("2.Afficher les tâches trier par deadline.\n");
			printf("3.Afficher les tâches dont le deadline est dans 3 jours ou moins\n");
			printf("Taper de quel manière tu veux l'afficher : ");
			scanf(" %d", &aff);
			switch(aff){
				case 1:
					trier_alpha();
					 while(i<indice){
						afficher(i);
                        			i++;
                        			}
					break;
				case 2:
					trier_deadline;
					 while(i<indice){
                        			afficher(i);
                        			i++;
                        			}
					break;
				case 3:
					//affich 3j;
					break;
				default:
					printf("Invalid option !");
					break;
				}
			break;
		case 4:	printf("\e[1;1H\e[2J");
			printf("Entre");
			modifier;
		case 5:	printf("\e[1;1H\e[2J");
			//supprimer;
		case 6:	printf("\e[1;1H\e[2J");
			//rechercher;
		case 7: printf("\e[1;1H\e[2J");
			//statistique;
		default:
			printf("Invalide fonction\n");
			printf("\e[1;1H\e[2J");
			break;
	}
}
return (0);
}
