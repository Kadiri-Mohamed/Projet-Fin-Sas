#include "headers.h"

Categorie categories[] = {
    {1, "Electronique"},
    {3, "Maison"},
    {4, "Livres"},
    {5, "Sports"}};

Produit produits[] = {
    {1, "Smartphone", {1, "Electronique"}, 699.99, 50, "Un smartphone haut de gamme avec un excellent appareil photo."},
    {2, "Ordinateur Portable", {1, "Electronique"}, 999.99, 30, "Un ordinateur portable puissant pour le travail et le divertissement."},
    {3, "Aspirateur Robot", {3, "Maison"}, 299.99, 20, "Un aspirateur robot intelligent pour un nettoyage sans effort."},
    {4, "Lampe de Bureau", {3, "Maison"}, 49.99, 100, "Une lampe de bureau LED avec intensité réglable."},
};

int produit_count = sizeof(produits) / sizeof(produits[0]);
Client clients[MAX_CLIENT];
Achat achats[MAX_ACHAT];

int counter_client = 0;

int achat_count = 0;