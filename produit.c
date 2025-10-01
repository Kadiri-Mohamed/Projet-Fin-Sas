#include "headers.h"

// afficher
void afficher_produits(Produit table[MAX_PRODUIT])
{
    for (int i = 0; i < produit_count; i++)
    {
        printf("\033[33m"
               "ID: %d, Nom: %s, Categorie: %s, Prix: %.2f, Stock: %d\nDescription: %s\n"
               "\033[0m",
               table[i].idProduit, table[i].nom, table[i].categorie.nom,
               table[i].prix, table[i].stock, table[i].description);
        printf("---------------------------------------------------------------------------- \n");
    }
}

// tri
void tri_produits(int tri_choise, Produit table[MAX_PRODUIT])
{
    switch (tri_choise)
    {
    case 1:
        tri_prix_croissant(table, produit_count);
        afficher_produits(produits);
        break;
    case 2:
        tri_prix_decroissant(table, produit_count);
        afficher_produits(produits);
        break;
    case 3:
        tri_nom_alphabetique(table, produit_count);
        afficher_produits(produits);
        break;
    case 4:
    {
        printf(" Organisation par categorie\n");
        printf("1. Electronique\n");
        printf("2. Maison\n");
        printf("3. Livres\n");
        printf("4. Sports\n");

        printf("Entrez l'ID de la categorie: ");
        int category_id;
        scanf("%d", &category_id);
        organiser_produits_par_categorie(table, category_id);
    }
    break;
    default:
        system("cls");
        printf("_______________________________________________\n");
        printf("choix invalide\n");
        break;
    }
}

void tri_prix_croissant(Produit table[MAX_PRODUIT], int max)
{
    for (int i = 0; i < max - 1; i++)
    {
        for (int j = 0; j < max - i - 1; j++)
        {
            if (table[j].prix > table[j + 1].prix)
            {
                Produit temp = table[j];
                table[j] = table[j + 1];
                table[j + 1] = temp;
            }
        }
    }
}

void tri_prix_decroissant(Produit table[MAX_PRODUIT], int max)
{
    for (int i = 0; i < max - 1; i++)
    {
        for (int j = 0; j < max - i - 1; j++)
        {
            if (table[j].prix < table[j + 1].prix)
            {
                Produit temp = table[j];
                table[j] = table[j + 1];
                table[j + 1] = temp;
            }
        }
    }
}

void tri_nom_alphabetique(Produit table[MAX_PRODUIT], int max)
{
    for (int i = 0; i < max - 1; i++)
    {
        for (int j = 0; j < max - i - 1; j++)
        {
            if (strcasecmp(table[j].nom, table[j + 1].nom) > 0)
            {
                Produit temp = table[j];
                table[j] = table[j + 1];
                table[j + 1] = temp;
            }
        }
    }
}

void organiser_produits_par_categorie(Produit table[MAX_PRODUIT], int category_id)
{
    printf("---------------------------------------------------------------------------- \n");
    int found = 0;
    for (int i = 0; i < produit_count; i++)
    {
        if (table[i].categorie.idCategorie == category_id)
        {
            found = 1;
            printf("\033[33m"
                   "ID: %d, Nom: %s, Categorie: %s, Prix: %.2f, Stock: %d\nDescription: %s\n"
                   "\033[0m",
                   table[i].idProduit, table[i].nom, table[i].categorie.nom,
                   table[i].prix, table[i].stock, table[i].description);
            printf("---------------------------------------------------------------------------- \n");
        }
    }
    if (!found)
    {
        printf("\033[31m"
               "Aucun produit trouve dans la categorie avec l'ID %d.\n"
               "\033[0m",
               category_id);
    }
}

// recherche
void rechercher_produits(int search_choise, Produit table[MAX_PRODUIT])
{
    switch (search_choise)
    {
    case 1:
        printf(" Recherche par nom\n");
        char name[20];
        printf("Entrez le nom du produit: ");
        scanf(" %[^\n]", name);
        rechercher_produits_nom(table, name);
        break;
    case 2:
        printf(" Recherche par categorie\n");
        char category[20];
        printf("Entrez le nom de la categorie: ");
        scanf(" %[^\n]", category);
        rechercher_produits_categorie(table, category);
        break;
    default:
        system("cls");
        printf("_______________________________________________\n");
        printf("choix invalide\n");
        break;
    }
}

void rechercher_produits_nom(Produit table[MAX_PRODUIT], char name[20])
{
    int found = 0;
    for (int i = 0; i < produit_count; i++)
    {
        if (strcasecmp(table[i].nom, name) == 0)
        {
            printf("\033[33m"
                   "ID: %d, Nom: %s, Categorie: %s, Prix: %.2f, Stock: %d\nDescription: %s\n"
                   "\033[0m",
                   table[i].idProduit, table[i].nom, table[i].categorie.nom,
                   table[i].prix, table[i].stock, table[i].description);
            printf("---------------------------------------------------------------------------- \n");
            found = 1;
        }
    }
    if (!found)
    {
        printf("\033[31m"
               "Aucun produit trouve dans la categorie '%s'.\n"
               "\033[0m",
               name);
    }
}

void rechercher_produits_categorie(Produit table[MAX_PRODUIT], char category_name[20])
{

    int found = 0;
    for (int i = 0; i < produit_count; i++)
    {
        if (strcasecmp(table[i].categorie.nom, category_name) == 0)
        {
            printf("\033[33m"
                   "ID: %d, Nom: %s, Categorie: %s, Prix: %.2f, Stock: %d\nDescription: %s\n"
                   "\033[0m",
                   table[i].idProduit, table[i].nom, table[i].categorie.nom,
                   table[i].prix, table[i].stock, table[i].description);
            printf("---------------------------------------------------------------------------- \n");
            found = 1;
        }
    }

    if (!found)
    {
        printf("\033[31m"
               "Aucun produit trouve dans la categorie '%s'.\n"
               "\033[0m",
               category_name);
    }
}

void detailler_produit(int product_id, Produit table[MAX_PRODUIT])
{
    int found = 0;
    for (int i = 0; i < produit_count; i++)
    {
        if (table[i].idProduit == product_id)
        {
            printf("\033[33m"
                   "ID: %d, Nom: %s, Categorie: %s, Prix: %.2f, Stock: %d\nDescription: %s\n"
                   "\033[0m",
                   table[i].idProduit, table[i].nom, table[i].categorie.nom,
                   table[i].prix, table[i].stock, table[i].description);
            printf("---------------------------------------------------------------------------- \n");
            found = 1;
            break;
        }
    }
    if (!found)
    {
        printf("\033[31m"
               "Aucun produit trouve avec l'ID %d.\n"
               "\033[0m",
               product_id);
    }
}
