#include "headers.h"

void gerer_client(int choise)
{

    switch (choise)
    {
    case 1:
        if (counter_client == 0)
        {
            printf("Aucun client connecte. Veuillez d'abord creer un profil.\n");
            return;
        }
        printf("Modification de profile\n");
        modifier_client(counter_client, clients);
        break;
    case 2:
        printf("Consultation de profile\n");
        afficher_client(clients);
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

void ajouter_client(Client table[MAX_CLIENT])
{
    if (counter_client >= MAX_CLIENT)
    {
        printf("Impossible d'ajouter un client. Capacite maximale depassee.\n");
        return;
    }

    table[counter_client].idClient = counter_client + 1;

    printf("Donner le prenom: ");
    scanf(" %[^\n]", table[counter_client].prenom);

    printf("Donner le nom: ");
    scanf(" %[^\n]", table[counter_client].nom);

    snprintf(table[counter_client].email, sizeof(table[counter_client].email), "%s.%s@shop.com", table[counter_client].prenom, table[counter_client].nom);

    table[counter_client].solde = 500.0;

    printf("Client ajoute avec succes avec l'id = %d\n", table[counter_client].idClient);
    printf("Email genere: %s\n", table[counter_client].email);

    counter_client++;
}

void afficher_client(Client table[MAX_CLIENT])
{
    if (counter_client == 0)
    {
        printf("Aucun client dans la liste\n");
        return;
    }

    printf("Profil client:\n");
    printf("ID: %d, Prenom: %s, Nom: %s, Email: %s, Solde: %.2f\n",
           table[counter_client - 1].idClient, table[counter_client - 1].prenom,
           table[counter_client - 1].nom, table[counter_client - 1].email,
           table[counter_client - 1].solde);
    printf("---------------------------------------------------------------------------- \n");
};

void modifier_client(int searched_id, Client table[MAX_CLIENT])
{
    int found = 0;
    for (int i = 0; i < counter_client; i++)
    {
        if (table[searched_id].idClient == searched_id)
        {
            found = 1;
            printf("Modification du client avec l'ID %d\n", searched_id);

            printf("Donner le nouveau prenom (actuel: %s): ", table[i].prenom);
            scanf(" %[^\n]", table[i].prenom);

            printf("Donner le nouveau nom (actuel: %s): ", table[i].nom);
            scanf(" %[^\n]", table[i].nom);

            snprintf(table[i].email, sizeof(table[i].email), "%s.%s@shop.com", table[i].prenom, table[i].nom);
            printf("Nouveau email genere: %s\n", table[i].email);
            printf("Client modifie avec succes.\n");
            break;
        }
    }
    if (!found)
    {
        printf("Client avec l'ID %d non trouve.\n", searched_id);
    }
};