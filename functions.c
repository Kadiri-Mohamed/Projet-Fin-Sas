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
            Effectuer_achat(product_id, quantity);
            break;
        case 5:
            system("cls");
            printf("_______________________________________________\n");
            afficher_statistiques();
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

// Effectuer achat

void Effectuer_achat(int product_id, int quantity)
{

    int found = 0;
    for (int i = 0; i < produit_count; i++)
    {
        if (produits[i].idProduit == product_id)
        {
            found = 1;
            if (produits[i].stock < quantity)
            {
                printf("\033[31m"
                       "Stock insuffisant pour le produit '%s'. Stock disponible: %d\n"
                       "\033[0m",
                       produits[i].nom, produits[i].stock);
                return;
            }

            float total_price = produits[i].prix * quantity;
            if (clients[counter_client - 1].solde < total_price)
            {
                printf("\033[31m"
                       "Solde insuffisant. Votre solde: %.2fMAD, Montant requis: %.2fMAD\n"
                       "\033[0m",
                       clients[counter_client - 1].solde, total_price);
                return;
            }

            printf("\033[33m"
                   "Confirmer l'achat de %d x '%s' pour un total de %.2fMAD? (o/n): "
                   "\033[0m",
                   quantity, produits[i].nom, total_price);
            char confirm;
            scanf(" %c", &confirm);
            if (confirm == 'n' || confirm == 'N')
            {
                printf("\033[31m"
                       "Achat annule.\n"
                       "\033[0m");
                return;
            }

            produits[i].stock -= quantity;
            clients[counter_client - 1].solde -= total_price;
            produits[i].quantity_sold += quantity;

            printf("\033[32m"
                   "Achat reussi! Vous avez achete %d x '%s' , total est %.2fMAD.\n"
                   "votre solde now: %.2fMAD\n"
                   "\033[0m",
                   quantity, produits[i].nom, total_price, clients[counter_client - 1].solde);
            achat_count++;
            return;
        }
    }

    if (!found)
    {
        printf("\033[31m"
               "Produit avec ID %d non trouve.\n"
               "\033[0m",
               product_id);
    }
}

// Consultation statistiques personnelles
void afficher_statistiques()
{
    if (counter_client == 0)
    {
        printf("\033[31m"
               "Aucun client connecte. Veuillez d'abord creer un profil.\n"
               "\033[0m");
        return;
    }

    printf("\033[34m"
           "Statistiques personnelles\n"
           "\033[0m");

    printf("\033[32m"
           "Client: %s %s\n"
           "\033[0m",
           clients[counter_client - 1].prenom, clients[counter_client - 1].nom);
    printf("\033[32m"
           "Solde actuel: %.2fMAD\n"
           "\033[0m",
           clients[counter_client - 1].solde);
    printf("\033[32m"
           "Nombre total d'achats effectues: %d\n"
           "\033[0m",
           achat_count);

    printf("\033[34m"
           "Produits achetes:\n"
           "\033[0m");
    int any_purchase = 0;
    for (int i = 0; i < produit_count; i++)
    {
        if (produits[i].quantity_sold > 0)
        {
            any_purchase = 1;
            printf("\033[33m"
                   "- %s: %d achetes\n"
                   "\033[0m",
                   produits[i].nom, produits[i].quantity_sold);
        }
    }
    if (!any_purchase)
    {
        printf("\033[33m"
               "Aucun produit achete encore.\n"
               "\033[0m");
    }
}

// helpers
char to_lowercase(char str[20])
{
    static char lower_str[20];
    for (int i = 0; str[i]; i++)
    {
        lower_str[i] = tolower((unsigned char)str[i]);
    }
    return lower_str;
}