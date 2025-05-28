#include <stdio.h>
#include <stdlib.h>
#include "include/table_commutation.h"
#include "include/mac.h"

void afficher_entree_table_commutation(const entree_table_commutation_t * etc)
{
	printf("%d:", etc->port);
	afficher_mac(&etc->ma);
}

void init_table_commutation_t(table_commutation_t * tc)
{
	tc->capacite = 8; // On garantie une capacité de 8 entrées à l'initialisation
	tc->nb_entree = 0;
	tc->entrees = malloc(tc->capacite * sizeof(entree_table_commutation_t));
	if (tc->entrees == NULL)
	{
		fprintf(stderr, "malloc dans init_table_commutation_t !\n");
		exit(EXIT_FAILURE);
	}
}

void deinit_table_commutation_t(table_commutation_t * tc)
{
	free(tc->entrees);
	tc->entrees = NULL;
}

void ajouter_entree_table_commutation(table_commutation_t *tc, entree_table_commutation_t etc)
{
	// TODO : vérifier si l'entrée est valide par je ne sais quel moyen
	
	// Vérification de la taille du tableau d'entrées, l'agrandir si nécessaire
	if (tc->nb_entree == tc->capacite)
	{
		tc->capacite *= 2; // On double la capacité du tableau
		tc->entrees = realloc(tc->entrees, tc->capacite * sizeof(entree_table_commutation_t));
		// Vérification de la bonne exécution de la réallocation
		if (tc->entrees == NULL)
		{
			fprintf(stderr, "Erreur realloc() dans ajouter_entree_table_commutation !\n");
			perror("realloc : ");
			exit(EXIT_FAILURE);
		}
	}
	tc->entrees[tc->nb_entree] = etc;
	tc->nb_entree++;
}

void afficher_table_commutation(const table_commutation_t *tc)
{
    if (tc == NULL || tc->nb_entree == 0)
    {
        printf("Table de commmutation vide.\n");
        return;
    }
	
    for (unsigned short i = 0 ; i < tc->nb_entree ; i++)
	{
		afficher_entree_table_commutation(&tc->entrees[i]);
	}
}

