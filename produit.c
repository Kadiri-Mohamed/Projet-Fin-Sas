#include "headers.h"

void consluter_produits(int choise)
{
    switch (choise)
    {
    case 1:
        printf(" Affichage catalogue\n");
        break;
    case 2:

        printf(" Recherche produits\n");
        break;
    case 3:
        printf(" Tri des produits\n");
        break;
    case 4:
        printf(" Recherche un produit\n");
        break;

    default:
        system("cls");
        printf("_______________________________________________\n");
        printf("choix invalide\n");
        break;
    }
}

// void tri_produits(int tri_choise, Produit table[MAX_CLIENT]);
// void rechercher_produit(int search_choise, Produit table[MAX_CLIENT]);