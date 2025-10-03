#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ANIMAUX 100

// Définition de la structure Animal
typedef struct {
    int id;
    char nom[50];
    char espece[50];
    int age;
    char habitat[50];
    float poids;
} Animal;

// Variables globales
Animal animaux[MAX_ANIMAUX] = {
    {1, "Simba", "lion", 5, "savane", 190.5},
    {2, "Tigra", "tigre", 4, "jungle", 220.0},
    {3, "Gigi", "girafe", 7, "savane", 800.3},
    {4, "Rex", "lion", 6, "savane", 210.7},
    {5, "Nala", "lionne", 3, "savane", 180.2},
    {6, "Leo", "lion", 4, "savane", 200.5},
    {7, "Khan", "tigre", 5, "jungle", 230.4},
    {8, "Milo", "lion", 2, "savane", 195.0},
    {9, "Zara", "panthere", 8, "jungle", 160.2},
    {10, "Rocky", "lion", 3, "savane", 180.0},
    {11, "Luna", "lionne", 4, "savane", 175.8},
    {12, "Oscar", "tigre", 6, "jungle", 210.6},
    {13, "Bella", "gazelle", 2, "savane", 120.5},
    {14, "Max", "lion", 7, "savane", 200.0},
    {15, "Ellie", "zèbre", 5, "savane", 300.3},
    {16, "Zazu", "perroquet", 3, "jungle", 2.5},
    {17, "Django", "chimpanzé", 6, "jungle", 50.0},
    {18, "Fluffy", "chat", 2, "jungle", 4.3},
    {19, "Coco", "oiseau", 1, "jungle", 1.2},
    {20, "Nino", "singe", 5, "jungle", 45.6}
};

int compteur_animaux = 20;
int id_courant = 21;

// Liste des habitats valides
char habitats_valides[4][20] = {"savane", "jungle", "désert", "aquatique"};

// Affichage du menu principal
void afficher_menu() {
    printf("\n=== MENU PRINCIPAL ===\n");
    printf("1. Ajouter un animal\n");
    printf("2. Afficher les animaux\n");
    printf("3. Modifier un animal\n");
    printf("4. Supprimer un animal\n");
    printf("5. Rechercher un animal\n");
    printf("6. les statistiques\n");

    printf("0. Quitter\n");
    printf("Choix : ");
}

// Fonction pour verifier si une chaine contient uniquement des lettres
int est_alpha(char str[]) {
    int i = 0;
    while (str[i] != '\0') {
        if (!isalpha(str[i]) && str[i] != ' ')
            return 0;
        i++;
    }
    return 1;
}

// Verifier si le nom ou l'espece est valide
int est_nom_valide(char str[]) {
    int longueur = strlen(str);

    if (longueur < 3) {
        return 0;
    }

    if (!est_alpha(str)) {
        return 0;
    }

    return 1;
}



// Verifie si l'habitat saisi est parmi les 4 valides
int est_habitat_valide(char habitat[]) {
    for (int i = 0; i < 4; i++) {
        if (strcmp(habitat, habitats_valides[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

// Fonction pour ajouter un seul animal avec validation
void ajouter_animal() {
    if (compteur_animaux >= MAX_ANIMAUX) {
        printf("Capacité maximale atteinte\n");
        return;
    }

    Animal a;
    a.id = id_courant++;


    do {
        printf("Nom : ");
        scanf(" %[^\n]", a.nom);
        if (!est_nom_valide(a.nom)) {
            printf(" Le nom doit contenir uniquement des lettres et au moins 3 caracteres\n");
        }
    } while (!est_nom_valide(a.nom));


    do {
        printf("Espece : ");
        scanf(" %[^\n]", a.espece);
        if (!est_nom_valide(a.espece)) {
            printf(" L'espece doit contenir uniquement des lettres et au moins 3 caracteres\n");
        }
    } while (!est_nom_valide(a.espece));


    int retour;
    do {
        printf("Age : ");
        retour=scanf("%d", &a.age);

        while (getchar()!= '\n');
        if (a.age <= 0 || retour == 0) {
            printf(" L'age doit être supérieur a 0\n");
        }
    } while (a.age <= 0 || retour == 0);


    do {
        printf("Habitat (savane, jungle, désert, aquatique) : ");
        scanf(" %[^\n]", a.habitat);
        if (!est_habitat_valide(a.habitat)) {
            printf(" Habitat invalide. Choisissez parmi : savane, jungle, désert, aquatique.\n");
        }
    } while (!est_habitat_valide(a.habitat));


    do {
        printf("Poids (en kg) : ");
        scanf("%f", &a.poids);
        if (a.poids <= 0) {
            printf(" Le poids doit être strictement positif\n");
        }
    } while (a.poids <= 0);

    animaux[compteur_animaux++] = a;
    printf("Animal ajoute avec succes !\n");
}

// Fonction pour ajouter plusieurs animaux
void ajouter_animaux_multiple() {
    int n;
    printf("Combien d'animaux souhaitez-vous ajouter  ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("\n--- Ajout de l'animal %d ---\n", i + 1);
        ajouter_animal();
    }
}

void afficher_animaux() {
    if (compteur_animaux == 0) {
        printf("Aucun animal à afficher.\n");
        return;
    }

    printf("\n=== LISTE DES ANIMAUX ===\n\n");

    // En-tête du tableau
    printf("+----+----------------------+----------------------+-----+-------------+---------+\n");
    printf("| ID | Nom                  | Espece               | age | Habitat     | Poids   |\n");
    printf("+----+----------------------+----------------------+-----+-------------+---------+\n");

    // Contenu avec ligne de séparation après chaque ligne
    for (int i = 0; i < compteur_animaux; i++) {
        printf("| %-2d | %-20s | %-20s | %-3d | %-11s | %-7.2f |\n",
               animaux[i].id,
               animaux[i].nom,
               animaux[i].espece,
               animaux[i].age,
               animaux[i].habitat,
               animaux[i].poids);

        // Ligne de séparation après chaque animal
        printf("+----+----------------------+----------------------+-----+-------------+---------+\n");
    }
}
void trier_animaux_par_nom_asc() {
    Animal temp;
    for (int i = 0; i < compteur_animaux - 1; i++) {
        for (int j = 0; j < compteur_animaux-i-1; j++) {
            if (strcmp(animaux[j].nom, animaux[j+1].nom) > 0) {
                temp = animaux[j];
                animaux[j] = animaux[j+1];
                animaux[j+1] = temp;
            }
        }
    }
}

void trier_animaux_par_nom_desc() {
    Animal temp;
    for (int i = 0; i < compteur_animaux - 1; i++) {
        for (int j = 0; j < compteur_animaux-i-1; j++) {
            if (strcmp(animaux[j].nom, animaux[j+1].nom) < 0) {
                temp = animaux[j];
                animaux[j] = animaux[j+1];
                animaux[j+1] = temp;
            }
        }
    }
}

void trier_animaux_par_age() {
    Animal temp;
    for (int i = 0; i < compteur_animaux - 1; i++) {
        for (int j = 0; j < compteur_animaux-i-1; j++) {
            if (animaux[j].age > animaux[j+1].age) {
                temp = animaux[j];
                animaux[j] = animaux[j+1];
                animaux[j+1] = temp;
            }
        }
    }
}

void AffichHabitat() {
    char habitaCherche[20];
    printf("saisir  L'habitat spécifique que tu veux rechercher");
    scanf("%s",habitaCherche);
    int trouve = 0;

    printf("\nAnimaux dans l'habitat '%s' :\n", habitaCherche);
    printf("-----------------------------------------------------------\n");
    for (int i = 0; i < compteur_animaux; i++) {
        if (strcmp(habitaCherche, animaux[i].habitat) == 0) {

            printf("| %-3d | %-20s | %-20s | %-3d | %-10s | %-6.2f |\n",
                   animaux[i].id, animaux[i].nom, animaux[i].espece,
                   animaux[i].age, animaux[i].habitat, animaux[i].poids);
            trouve = 1;
             printf("-----------------------------------------------------------\n");
        }

    }

    if (!trouve) {
        printf("Aucun animal trouvé dans cet habitat.\n");
    }

}

void modifier_habitat() {
    int id;
    char nouvel_habitat[50];
    int trouve = 0;

    printf("Entrez l'ID de l'animal à modifier : ");
    scanf("%d", &id);

    for (int i = 0; i < compteur_animaux; i++) {
        if (animaux[i].id == id) {
            trouve = 1;
            printf("Habitat actuel : %s\n", animaux[i].habitat);

            do {
                printf("Nouveau habitat (savane, jungle, désert, aquatique) : ");
                scanf(" %[^\n]", nouvel_habitat);
                if (!est_habitat_valide(nouvel_habitat)) {
                    printf("Habitat invalide. Choisissez parmi : savane, jungle, désert, aquatique.\n");
                }
            } while (!est_habitat_valide(nouvel_habitat));

            strcpy(animaux[i].habitat, nouvel_habitat);
            printf("Habitat modifié avec succès.\n");
            break;
        }
    }

    if (!trouve) {
        printf("Animal avec l'ID %d non trouvé.\n", id);
    }
}

void modifier_age(){
    int id;
    int trouve=0;
    printf("saisir l'id : ");
    scanf("\n%d",&id);

    for(int i=0;i<compteur_animaux;i++){
        if(animaux[i].id== id){
            trouve=1;
            printf("l'age actuel %d : ",animaux[i].age);

        int newAge;
        do{
            printf("saisir le nouveau age : ");
            scanf("%d",&newAge);
        }while(newAge<0);

        animaux[i].age=newAge;
        printf("age modifié avec succés");
        break;
        }
    }

    if(!trouve){
        printf("id non trouvé");
    }

}

void supprimer_animal() {
    int id;
    int trouve = 0;

    printf("Saisir l'id de l'animal à supprimer : ");
    scanf("%d", &id);

    for (int i = 0; i < compteur_animaux; i++) {
        if (animaux[i].id == id) {
            // Remplacer l'animal à supprimer par le dernier animal
            animaux[i] = animaux[compteur_animaux - 1];
            compteur_animaux--;
            trouve = 1;
            printf("Animal avec id %d supprim.\n", id);
            break;
        }
    }

    if (!trouve) {
        printf("Animal avec id %d non trouve.\n", id);
    }
}

void recherche_id(){
    int id;
    int trouve=0;
        printf("saisir l'id : ");
        scanf("%d",&id);

        for (int i=0;i<compteur_animaux;i++){
           if(animaux[i].id == id) {
            printf("+----+----------------------+----------------------+-----+-------------+---------+\n");
            printf("| ID | Nom                  | Espece               | age | Habitat     | Poids   |\n");
            printf("+----+----------------------+----------------------+-----+-------------+---------+\n");

            printf("| %-3d | %-20s | %-20s | %-3d | %-10s | %-6.2f |\n",
                   animaux[i].id, animaux[i].nom, animaux[i].espece,
                   animaux[i].age, animaux[i].habitat, animaux[i].poids);
                   trouve = 1;
                   break;
           }
        }
         printf("+----+----------------------+----------------------+-----+-------------+---------+\n");
        if (!trouve) {
        printf("Animal avec id %d non trouve.\n", id);
    }

}



void recherche_nom(){
    char nom[20];
    int trouve = 0;
    printf("saisir le nom recherché : ");
    scanf("\n%s",nom);



    for(int i=0; i<compteur_animaux;i++){

        if(strcmpi(nom,animaux[i].nom)==0){
                printf("+----+----------------------+----------------------+-----+-------------+---------+\n");
                printf("| ID | Nom                  | Espece               | age | Habitat     | Poids   |\n");
                printf("+----+----------------------+----------------------+-----+-------------+---------+\n");
             printf("| %-3d | %-20s | %-20s | %-3d | %-10s | %-6.2f |\n",
                   animaux[i].id, animaux[i].nom, animaux[i].espece,
                   animaux[i].age, animaux[i].habitat, animaux[i].poids);
                   trouve = 1;
                   printf("+----+----------------------+----------------------+-----+-------------+---------+\n");
                   break;
        }
    }


    if(!trouve){
        printf("nom no trouvé");
    }

}

void recherche_par_espece() {
    char espece_recherchee[50];
    int trouve = 0;

    printf("Saisir l'espèce à rechercher : ");
    scanf(" %[^\n]", espece_recherchee);

    printf("+----+----------------------+----------------------+-----+-------------+---------+\n");
    printf("| ID | Nom                  | Espece               | Age | Habitat     | Poids   |\n");
    printf("+----+----------------------+----------------------+-----+-------------+---------+\n");

    for (int i = 0; i < compteur_animaux; i++) {
        if (strcmp(animaux[i].espece, espece_recherchee) == 0) {
            printf("| %-3d | %-20s | %-20s | %-3d | %-10s | %-6.2f |\n",
                   animaux[i].id, animaux[i].nom, animaux[i].espece,
                   animaux[i].age, animaux[i].habitat, animaux[i].poids);
            trouve = 1;
        }
    }

    printf("+----+----------------------+----------------------+-----+-------------+---------+\n");

    if (!trouve) {
        printf("Aucun animal trouvé avec l'espèce \"%s\".\n", espece_recherchee);
    }
}

int nombreTtal(){
    return compteur_animaux ;
}

float Agemoyen() {


    int somme = 0;
    for (int i = 0; i < compteur_animaux; i++) {
        somme += animaux[i].age;
    }
    float moyen =somme/compteur_animaux;
    return moyen;
}


int Plus_jeune(){


    int min= animaux[0].age;
    for (int i =0; i<compteur_animaux ;i++){
        if(animaux[i].age<min){
            min=animaux[i].age;
        }
    }
    return min;
}

int Plus_vieux() {
    if (compteur_animaux == 0) {
        return -1;
    }

    int max_age = animaux[0].age;
    for (int i = 1; i < compteur_animaux; i++) {
        if (animaux[i].age > max_age) {
            max_age = animaux[i].age;
        }
    }
    return max_age;
}

void afficher_stats() {
    int choix_stat;

    do {
        printf("\n--- Sous-menu Statistiques ---\n");
        printf("1. Age du plus vieux animal\n");
        printf("2. Age moyen des animaux\n");
        printf("3. Nombre total d'animaux\n");
        printf("4. Nombre le plus represente\n");
        printf("5. Retour au menu principal\n");
        printf("Choix : ");
        scanf("%d", &choix_stat);

        switch (choix_stat) {
            case 1:
                if (compteur_animaux > 0)
                    printf("Age du plus vieux animal : %d ans\n", Plus_jeune());
                else
                    printf("Aucun animal dans la base.\n");
                break;
            case 2:
                if (compteur_animaux > 0)
                    printf("Age moyen des animaux : %.2f ans\n", Agemoyen());
                else
                    printf("Aucun animal dans la base.\n");
                break;
            case 3:
                printf("Nombre total d'animaux : %d\n", nombreTtal());
                break;
            case 4:
                afficher_espece_plus_representee();
                break;
            case 5:printf("Retour au menu principal\n");
                break;
            default:
                printf("Choix invalide.\n");
        }
    } while (choix_stat != 4);
}

void afficher_espece_plus_representee() {
    // Si aucun animal n'est encore ajouté
    if (compteur_animaux == 0) {
        printf("Aucun animal enregistré.\n");
        return;
    }

    // On déclare un tableau pour stocker les espèces rencontrées
    char especes[MAX_ANIMAUX][50];

    // Un tableau parallèle pour compter combien de fois chaque espèce apparaît
    int compteurs[MAX_ANIMAUX] = {0};

    // Compte combien d'espèces différentes on a trouvées
    int nb_especes = 0;

    // Parcourir tous les animaux pour compter les espèces
    for (int i = 0; i < compteur_animaux; i++) {
        int trouve = 0;

        // Vérifier si l'espèce actuelle est déjà enregistrée
        for (int j = 0; j < nb_especes; j++) {
            if (strcmp(animaux[i].espece, especes[j]) == 0) {
                compteurs[j]++;  // Incrémenter le compteur de cette espèce
                trouve = 1;
                break;
            }
        }

        // Si l'espèce n'a pas encore été vue, on l'ajoute
        if (!trouve) {
            strcpy(especes[nb_especes], animaux[i].espece);
            compteurs[nb_especes] = 1;
            nb_especes++;
        }
    }

    // Trouver l'indice de l'espèce la plus fréquente
    int max_index = 0;
    for (int i = 1; i < nb_especes; i++) {
        if (compteurs[i] > compteurs[max_index]) {
            max_index = i;
        }
    }

    // Affichage final
    printf("\nL'espèce la plus représentée est : %s (%d fois)\n",
           especes[max_index], compteurs[max_index]);
}



int main() {
    int choix;
    int choice;

    do {
        afficher_menu();
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                do {
                    printf("\n--- Sous-menu Ajout ---\n");
                    printf("1. Ajout simple\n");
                    printf("2. Ajout multiple\n");
                    printf("3. Retour au menu principal\n");
                    printf("Choix : ");
                    scanf("%d", &choice);

                    if (choice == 1)
                        ajouter_animal();
                    else if (choice == 2)
                        ajouter_animaux_multiple();
                    else if (choice != 3)
                        printf(" Choix invalide.\n");

                } while (choice != 3);
                break;

           case 2:
    do {
        printf("\n--- Sous-menu Affichage ---\n");
        printf("1. Affichage simple\n");
        printf("2. Tri par nom (A => Z)\n");
        printf("3. Tri par nom (Z => A)\n");
        printf("4. Tri par age (croissant)\n");
        printf("5. Tri par age habitat\n");
        printf("6. Retour\n");
        printf("Choix : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                afficher_animaux();
                break;
            case 2:
                trier_animaux_par_nom_asc();
                afficher_animaux();
                break;
            case 3:
                trier_animaux_par_nom_desc();
                afficher_animaux();
                break;
            case 4:
                trier_animaux_par_age();
                afficher_animaux();
                break;
            case 5: AffichHabitat();
                break;
            case 6:
                break;
            default:
                printf("Choix invalide.\n");
        }

    } while (choice != 6);
    break;


            case 3: {
                int choix_modif;
                do {
                    printf("\n--- Modifier un animal ---\n");
                    printf("1. Modifier habitat\n");
                    printf("2. Modifier âge\n");
                    printf("3. Retour au menu principal\n");
                    printf("Choix : ");
                    scanf("%d", &choix_modif);

                    switch (choix_modif) {
                        case 1:
                            modifier_habitat();
                            break;
                        case 2:
                            modifier_age();
                            break;
                        case 3:
                            printf("Retour au menu principal.\n");
                            break;
                        default:
                            printf("Choix invalide.\n");
                    }
                } while (choix_modif != 3);
            } break;


            case 4: supprimer_animal();

                break;

            case 5: {
                            int choix_recherche;
                            do {
                                printf("\n--- Sous-menu Recherche ---\n");
                                printf("1. Recherche par ID\n");
                                printf("2. Recherche par Nom\n");
                                printf("3. Recherche par Espèce\n");
                                printf("4. Retour au menu principal\n");
                                printf("Choix : ");
                                scanf("%d", &choix_recherche);

                                switch (choix_recherche) {
                                    case 1:
                                        recherche_id();
                                        break;
                                    case 2:
                                        recherche_nom();
                                        break;
                                    case 3:
                                        recherche_par_espece();
                                        break;

                                    case 4:
                                        printf("Retour au menu principal.\n");
                                        break;
                                    default:
                                        printf("Choix invalide.\n");
                                }

                            } while (choix_recherche != 4);
                        } break;

                        case 6 :afficher_stats();
                        break;

            case 0:
                printf(" Au revoir !\n");
                break;

            default:
                printf(" Choix invalide. Veuillez reessayer.\n");
         }
    } while (choix != 0);

    return 0;
}

