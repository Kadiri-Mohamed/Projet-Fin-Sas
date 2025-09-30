#ifndef HEADERS_H
#define HEADERS_H
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define Title "=== SYSTEME D'ACHAT CLIENT ==="
#define MAX_CLIENT 1
#define MAX_PRODUIT 100
#define MAX_ACHAT 200

typedef struct
{
    int idClient;
    char nom[20];
    char prenom[20];
    char email[50];
    float solde;
} Client;

typedef struct
{
    int idAchat;
    int idClient;
    int idProduit;
    int quantite;
    float montantTotal;
    char date[20];
} Achat;

typedef struct
{
    int idCategorie;
    char nom[50];
} Categorie;

typedef struct
{
    int idProduit;
    char nom[20];
    Categorie categorie;
    float prix;
    int stock;
    char description[100];
} Produit;

extern Categorie categories[];
extern Produit produits[];
extern int produit_count;
extern Client clients[MAX_CLIENT];
extern Achat achats[MAX_ACHAT];

extern int counter_client;
extern int achat_count;
extern int current_client_id;

void gerer_client(int choise);
void gerer_solde(int choise);
void consluter_produits(int choise);

void ajouter_client(Client table[MAX_CLIENT]);
void afficher_client(Client table[MAX_CLIENT]);
void modifier_client(int searched_id, Client table[MAX_CLIENT]);


// void tri_produits(int tri_choise, Produit table[MAX_PRODUIT]);
// void rechercher_produit(int search_choise, Produit table[MAX_PRODUIT]);
// void Effectuer_achat();
// void afficher_statistiques();

void main_menu();

#endif