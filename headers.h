#ifndef HEADERS_H
#define HEADERS_H
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define Title "=== SYSTEME D'ACHAT CLIENT ==="
#define MAX_CLIENT 1
#define MAX_PRODUIT 100

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
extern Client client[MAX_CLIENT];

void gerer_client(int choise);
void gerer_solde(int choise);
void consluter_produits(int choise);
void ajouter_client(Client table[MAX_CLIENT]);
void afficher_client(Client table[MAX_CLIENT]);
void modifier_client(int searched_id, Client table[MAX_CLIENT]);
void tri_produits(int tri_choise, Client table[MAX_CLIENT]);
void rechercher_produit(int search_choise, Client table[MAX_CLIENT]);

void main_menu();

#endif