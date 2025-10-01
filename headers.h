#ifndef HEADERS_H
#define HEADERS_H
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define Title "=== SYSTEME D'ACHAT CLIENT ==="
#define MAX_CLIENT 1
#define MAX_PRODUIT 100
#define MAX_ACHAT 10

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

// fonctions principales 
void gerer_client(int choise);
void gerer_solde(int choise);
void consluter_produits(int choise);

// fonctions client
void ajouter_client(Client table[MAX_CLIENT], char nom[20], char prenom[20]);
void afficher_client(Client table[MAX_CLIENT]);
void modifier_client(int searched_id, Client table[MAX_CLIENT] , char nom[20], char prenom[20]);

// fonctions solde
void depot_argent(Client table[MAX_CLIENT], float montant);
void consluter_solde(Client table[MAX_CLIENT]);
int verifier_solde(Client table[MAX_CLIENT], float montant);

// fonctions produits
void afficher_produits(Produit table[MAX_PRODUIT]);
void tri_produits(int tri_choise, Produit table[MAX_PRODUIT]);
void tri_prix_croissant(Produit table[MAX_PRODUIT], int max);
void tri_prix_decroissant(Produit table[MAX_PRODUIT], int max);
void tri_nom_alphabetique(Produit table[MAX_PRODUIT], int max);
void organiser_produits_par_categorie(Produit table[MAX_PRODUIT], int category_id);
void rechercher_produits(int search_choise, Produit table[MAX_PRODUIT]);
void rechercher_produits_nom(Produit table[MAX_PRODUIT], char name[20]);
void rechercher_produits_categorie(Produit table[MAX_PRODUIT], char category_name[20]);
void detailler_produit(int product_id, Produit table[MAX_PRODUIT]);

// helpers


// void tri_produits(int tri_choise, Produit table[MAX_PRODUIT]);
// void rechercher_produit(int search_choise, Produit table[MAX_PRODUIT]);
// void Effectuer_achat();
// void afficher_statistiques();

void main_menu();

#endif