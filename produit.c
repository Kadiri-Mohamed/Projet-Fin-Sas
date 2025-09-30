#include "headers.h"

void consluter_produits(int choise){
    switch (choise)
    {
    case 1:

        printf(" Consultation de solde\n");
        break;
    case 2:

        printf(" depot d'argent\n");
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