#include "headers.h"

void consluter_solde(Client table[MAX_CLIENT])
{
    printf("\033[33m"
           "Votre solde est de: %.2f\n"
           "\033[0m",
           table[counter_client - 1].solde);
}

void depot_argent(Client table[MAX_CLIENT], float montant)
{
    if (montant <= 0)
    {
        printf("\033[31m"
               "Montant invalide. Le depot doit etre superieur a 0.\n"
               "\033[0m");
        return;
    }
    table[counter_client - 1].solde += montant;
    printf("\033[32m"
           "Depot de %.2f effectue avec succes. Nouveau solde: %.2f\n"
           "\033[0m",
           montant, table[counter_client - 1].solde);
}

void ajouter_client(Client table[MAX_CLIENT], char nom[20], char prenom[20])
{
    if (counter_client >= MAX_CLIENT)
    {
        printf("\033[31m"
               "Impossible d'ajouter un client. Capacite maximale depassee.\n"
               "\033[0m");
        return;
    }
    table[counter_client].idClient = counter_client + 1;
    strcpy(table[counter_client].nom, nom);
    strcpy(table[counter_client].prenom, prenom);
    snprintf(table[counter_client].email, sizeof(table[counter_client].email), "%s.%s@shop.com", prenom, nom);
    table[counter_client].solde = 500.0;
    printf("\033[32m"
           "Client ajoute avec succes. ID: %d, Email: %s, Solde initial: %.2f\n"
           "\033[0m",
           table[counter_client].idClient, table[counter_client].email, table[counter_client].solde);

    counter_client++;
}

void afficher_client(Client table[MAX_CLIENT])
{
    if (counter_client == 0)
    {
        printf("\033[31m"
               "Aucun client dans la liste\n"
               "\033[0m");
        return;
    }

    printf("Profil client:\n");
    printf("ID: %d, Prenom: %s, Nom: %s, Email: %s, Solde: %.2f\n",
           table[counter_client - 1].idClient, table[counter_client - 1].prenom,
           table[counter_client - 1].nom, table[counter_client - 1].email,
           table[counter_client - 1].solde);
    printf("---------------------------------------------------------------------------- \n");
};

int verifier_solde(Client table[MAX_CLIENT], float montant)
{
    if (table[counter_client - 1].solde >= montant)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void modifier_client(int searched_id, Client table[MAX_CLIENT], char nom[20], char prenom[20])
{
    int found = 0;

    if (table[0].idClient == searched_id)
    {
        found = 1;
        strcpy(table[0].nom, nom);
        strcpy(table[0].prenom, prenom);
        snprintf(table[0].email, sizeof(table[0].email), "%s.%s@shop.com", prenom, nom);
        printf("\033[32m"
               "Client modifie avec succes. ID: %d, Email: %s\n"
               "\033[0m",
               table[0].idClient, table[0].email);
    }

    if (!found)
    {
        printf("\033[31m"
               "Client avec ID %d non trouve.\n"
               "\033[0m",
               searched_id);
        return;
    }
};