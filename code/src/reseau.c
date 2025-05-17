#include "include/reseau.h"
#include <stdlib.h>
#include <stdio.h>

void afficher_mac(const mac_address_t * ma)
{
	for (unsigned int i = 0 ; i < 6 ; i++)
	{
		printf("%02X", ma->octet[i]);
		if (i < 5)
			printf(":");
	}
	printf("\n");
}

void afficher_ip(const ip_address_t * ip)
{
	for (unsigned int i = 0 ; i < 4 ; i++)
	{
		printf("%d", ip->paquet[i]);
		if (i < 3)
			printf(".");
	}
	printf("/%d\n", ip->masque);
}



void afficher_entree_table_commutation(const entree_table_commutation_t * etc)
{
	printf("%d:", etc->port);
	afficher_mac(&etc->ma);
}

void init_table_commutation_t(table_commutation_t *tc)
{
	tc->capacite = 8; // On garantie une capacité de 8 entrées à l'initialisation
	tc->nb_entree = 0;
	tc->entrees = calloc(tc->capacite, sizeof(entree_table_commutation_t));
	if (tc->entrees == NULL)
	{
		fprintf(stderr, "Erreur calloc() dans init_table_commutation_t !\n");
		perror("calloc : ");
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
	for (unsigned long i = 0 ; i < tc->nb_entree ; i++)
	{
		afficher_entree_table_commutation(&tc->entrees[i]);
	}
}

/*
void afficher_switch(const switch_t * sw)
{
}
*/
