#include "headers.h"

// main menu
void main_menu()
{
    int choise_main;
    do
    {

        printf("1- Gerer votre profile\n");
        printf("2- Gerer votre solde virtuel\n");
        printf("3- Consulter les produits\n");
        printf("4- Effectuer un achat\n");
        printf("5- Afficher mes statistiques\n");
        printf("0- Quitter l'application\n");

        printf("Entrez votre choix: ");
        scanf("%d", &choise_main);

        switch (choise_main)
        {
        case 1:

            if (counter_client == 0)
            {
                system("cls");
                printf("_______________________________________________\n");
                char nom[20];
                char prenom[20];
                printf("Entrez votre nom: ");
                scanf(" %[^\n]", nom);
                printf("Entrez votre prenom: ");
                scanf(" %[^\n]", prenom);
                printf("Creation de profil\n");
                ajouter_client(clients, nom, prenom);
            }
            else
            {
                system("cls");
                printf("_______________________________________________\n");
                int choise;
                printf("1. Modifier votre profile\n");
                printf("2. Consulter votre profil\n");
                printf("Entrez votre choix: ");
                scanf("%d", &choise);
                gerer_client(choise);
            }
            break;
        case 2:

            if (counter_client == 0)
            {
                system("cls");
                printf("_______________________________________________\n");
                printf("\033[31m"
                       "Aucun client connectem, Connecter un profil.\n"
                       "\033[0m");
            }
            else
            {
                system("cls");
                printf("_______________________________________________\n");
                int choise;
                printf("1. Consulter votre solde\n");
                printf("2. Depot d'argent\n");
                printf("Entrez votre choix: ");
                scanf("%d", &choise);
                gerer_solde(choise);
            }
            break;
        case 3:
            system("cls");
            printf("_______________________________________________\n");

            int choise;

            printf("1. Afficher catalogue \n");
            printf("2. Rechercher produits\n");
            printf("3. Tri des produits\n");
            printf("4. Afficher details d'un produit\n");

            printf("Entrez votre choix: ");
            scanf("%d", &choise);

            consluter_produits(choise);
            break;
        case 4:
            system("cls");
            printf("_______________________________________________\n");
            printf("Effectuer un achat\n");
            if (counter_client == 0)
            {
                printf("\033[31m"
                       "Aucun client connectem, Connecter un profil.\n"
                       "\033[0m");
                break;
            }
            if (achat_count == MAX_ACHAT)
            {
                printf("\033[31m"
                       "Tu as atteint max nombre d'achat.\n"
                       "\033[0m");
                break;
            }
            if (produit_count == 0)
            {
                printf("\033[31m"
                       "Aucun produit disponible pour l'achat.\n"
                       "\033[0m");
                break;
            }
            int product_id, quantity;
            printf("Entrez l'ID du produit a acheter: ");
            scanf("%d", &product_id);
            printf("Entrez la quantite a acheter: ");
            scanf("%d", &quantity);
            Effectuer_achat( product_id, quantity);
            break;
        default:
            system("cls");
            printf("_______________________________________________\n");
            printf("choix invalide\n");
            break;
        }

    } while (choise_main != 0);
}

// menu client
void gerer_client(int choise)
{

    switch (choise)
    {
    case 1:
        if (counter_client == 0)
        {
            printf("\033[31m"
                   "Aucun client connecte. Veuillez d'abord creer un profil.\n"
                   "\033[0m");
            return;
        }
        printf("\033[34m"
               "Modification de profile\n"
               "\033[0m");
        char nom[20];
        char prenom[20];
        printf("Entrez le nouveau nom: ");
        scanf(" %[^\n]", nom);
        printf("Entrez le nouveau prenom: ");
        scanf(" %[^\n]", prenom);
        modifier_client(counter_client, clients, nom, prenom);
        break;
    case 2:
        system("cls");
        printf("_______________________________________________\n");
        if (counter_client == 0)
        {
            printf("\033[31m"
                   "Aucun client connecte. Veuillez d'abord creer un profil.\n"
                   "\033[0m");
            return;
        }
        printf("\033[34m"
               "Votre profile\n"
               "\033[0m");
        afficher_client(clients);
        break;
    default:
        system("cls");
        printf("_______________________________________________\n");
        printf("choix invalide\n");
        break;
    }
}

// menu solde

void gerer_solde(int choise)
{
    switch (choise)
    {
    case 1:

        printf("\033[34m"
               "consulter solde\n"
               "\033[0m");
        consluter_solde(clients);
        break;
    case 2:

        printf("\033[34m"
               "depot d'argent\n"
               "\033[0m");

        float montant;
        printf("Entrez le montant a deposer: ");
        scanf("%f", &montant);
        depot_argent(clients, montant);
        break;
    default:
        system("cls");
        printf("_______________________________________________\n");
        printf("choix invalide\n");
        break;
    }
}

// menu produits
void consluter_produits(int choise)
{
    switch (choise)
    {
    case 1:
        printf("\033[34m"
               "Affichage catalogue\n"
               "\033[0m");
        afficher_produits(produits);
        break;
    case 2:
        printf("\033[34m"
               "Recherche produits\n"
               "\033[0m");
        int search_choise;
        printf("1. Par nom\n");
        printf("2. Par categorie\n");
        printf("Entrez votre choix: ");
        scanf("%d", &search_choise);
        rechercher_produits(search_choise, produits);
        break;
    case 3:
        printf("\033[34m"
               "Tri des produits\n"
               "\033[0m");
        int tri_choise;
        printf("1. Prix croissant\n");
        printf("2. Prix decroissant\n");
        printf("2. Nom alphabetique\n");
        printf("4. Par categorie\n");
        printf("Entrez votre choix: ");
        scanf("%d", &tri_choise);
        tri_produits(tri_choise, produits);
        break;
    case 4:
        printf("\033[34m"
               "Detail produit\n"
               "\033[0m");
        int product_id;
        printf("Entrez l'ID du produit: ");
        scanf("%d", &product_id);
        detailler_produit(product_id, produits);
        break;

    default:
        system("cls");
        printf("_______________________________________________\n");
        printf("choix invalide\n");
        break;
    }
}

// helpers
