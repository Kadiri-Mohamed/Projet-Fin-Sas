#include "headers.h"

Categorie categories[] = {
    {1, "Electronique"},
    {2, "Maison"},
    {3, "Livres"},
    {4, "Sports"}};

Produit produits[] = {
    {1, "Smartphone", {1, "Electronique"}, 699.99, 50, "Un smartphone haut de gamme avec un excellent appareil photo.", 0},
    {5, "iphone 11", {1, "Electronique"}, 699.99, 50, "Un smartphone haut de gamme avec un excellent appareil photo.", 0},
    {6, "iphone 7", {1, "Electronique"}, 699.99, 50, "Un smartphone haut de gamme avec un excellent appareil photo.", 0},
    {2, "Ordinateur Portable", {4, "Sports"}, 999.99, 30, "Un ordinateur portable puissant pour le travail et le divertissement.", 0},
    {3, "Aspirateur Robot", {3, "Livres"}, 299.99, 20, "Un aspirateur robot intelligent pour un nettoyage sans effort.", 0},
    {4, "Lampe de Bureau", {2, "Maison"}, 49.99, 100, "Une lampe de bureau LED avec intensite reglable.", 0},
};

int produit_count = sizeof(produits) / sizeof(produits[0]);
Client clients[MAX_CLIENT];
// Achat achats[MAX_ACHAT];

int counter_client = 0;

int achat_count = 0;