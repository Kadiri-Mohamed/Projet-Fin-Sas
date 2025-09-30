#include "headers.h"

void main_menu()
{
    int choise_main;

    int choise;
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
                printf("Creation de profil\n");
                ajouter_client(clients);
            }
            else
            {
                int choise;
                printf("1. Modifier votre profile\n");
                printf("2. Consulter votre profil\n");
                printf("Entrez votre choix: ");
                scanf("%d", &choise);
                gerer_client(choise);
            }
            break;
        case 2:
            system("cls");
            printf("_______________________________________________\n");

            if (counter_client == 0)
            {
                printf("Aucun client connecte. Veuillez d'abord creer un profil.\n");
            }
            else
            {
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

            // int choise;

            printf("1. Afficher catalogue \n");
            printf("2. Rechercher produit\n");
            printf("3. Tri des produits\n");
            printf("4. Rechercher un produit\n");

            printf("Entrez votre choix: ");
            scanf("%d", &choise);

            consluter_produits(choise);
            break;
        case 4:
            system("cls");
            printf("_______________________________________________\n");
            // Effectuer_achat();
            break;
        default:
            system("cls");
            printf("_______________________________________________\n");
            printf("choix invalide\n");
            break;
        }

    } while (choise_main != 0);
}
