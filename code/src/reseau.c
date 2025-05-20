#include <stdlib.h>
#include <stdio.h>

// Fichiers en-tête 

#include "include/ip.h"
#include "include/mac.h"
#include "include/table_commutation.h"
#include "include/switch.h"
#include "include/station.h"

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

void init_table_commutation_t(table_commutation_t * tc)
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
	printf("\n");
	for (unsigned long i = 0 ; i < tc->nb_entree ; i++)
	{
		afficher_entree_table_commutation(&tc->entrees[i]);
	}
}

void init_switch_t(switch_t * sw, mac_address_t ma, unsigned short priorite_stp)
{
	sw->ma = ma;
	sw->nb_ports = 0;
	sw->priorite_stp = priorite_stp;
	
	// Allocation de mémoire pour une structure table_commutation_t
	sw->tc = malloc(sizeof(table_commutation_t));
	if (sw->tc == NULL)
	{
		fprintf(stderr, "Erreur dans le malloc de init_switch_t\n");
		perror("malloc : ");
		exit(EXIT_FAILURE);
	}
	init_table_commutation_t(sw->tc);
}

void deinit_switch_t(switch_t * sw)
{
	deinit_table_commutation_t(sw->tc);
	free(sw->tc);
	sw->tc = NULL;
}


void afficher_switch(const switch_t * sw)
{
	printf("MAC : ");
	afficher_mac(&sw->ma);
	printf("Nombre de ports : %u\n", sw->nb_ports);
	printf("Priorité STP : %u\n", sw->priorite_stp);
	printf("Table de commutation : ");
	afficher_table_commutation(sw->tc);
}

