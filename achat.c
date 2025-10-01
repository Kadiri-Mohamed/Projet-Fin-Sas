#include "headers.h"

void Effectuer_achat(int product_id, int quantity){

    int found = 0;
    for (int i = 0; i < produit_count; i++)
    {
        if (produits[i].idProduit == product_id)
        {
            found = 1;
            if (produits[i].stock < quantity)
            {
                printf("\033[31m"
                       "Stock insuffisant pour le produit '%s'. Stock disponible: %d\n"
                       "\033[0m",
                       produits[i].nom, produits[i].stock);
                return;
            }

            float total_price = produits[i].prix * quantity;
            if (clients[counter_client - 1].solde < total_price)
            {
                printf("\033[31m"
                       "Solde insuffisant. Votre solde: %.2fMAD, Montant requis: %.2fMAD\n"
                       "\033[0m",
                       clients[counter_client - 1].solde, total_price);
                return;
            }
            
            printf("Confirmer l'achat de %d x '%s' pour un total de %.2fMAD? (o/n): ", quantity, produits[i].nom, total_price);
            char confirm;
            scanf(" %c", &confirm);
            if (confirm == 'n' || confirm == 'N')
            {
                printf("\033[31m""Achat annule.\n");
                return;
            }

            produits[i].stock -= quantity;
            clients[counter_client - 1].solde -= total_price;
            produits[i].quantity_sold += quantity;

            printf("\033[32m"
                   "Achat reussi! Vous avez achete %d x '%s' , total est %.2fMAD.\n"
                   "votre solde now: %.2fMAD\n"
                   "\033[0m",
                   quantity, produits[i].nom, total_price, clients[counter_client - 1].solde);
            return;
        }
    }

    if (!found)
    {
        printf("\033[31m"
               "Produit avec ID %d non trouve.\n"
               "\033[0m",
               product_id);
    }
}
