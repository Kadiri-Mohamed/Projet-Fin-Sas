#include "headers.h"

void gerer_client(int choise)
{

    switch (choise)
    {
    case 1:

        printf(" modification de profile\n");
        break;
    case 2:

        printf(" Consultation de profile\n");
        break;
        
    default:
        system("cls");
        printf("_______________________________________________\n");
        printf("choix invalide\n");
        break;
    }
}
void gerer_solde(int choise)
{
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

void ajouter_client(Client table[MAX_CLIENT]);
void afficher_client(Client table[MAX_CLIENT]);
void modifier_client(int searched_id, Client table[MAX_CLIENT]);