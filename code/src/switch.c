#include <stdio.h>
#include <stdlib.h>
#include "include/switch.h"
#include "include/ip.h"
#include "include/mac.h"
#include "include/table_commutation.h"

void afficher_switch(const switch_t * sw)
{
	printf("MAC : ");
	afficher_mac(&sw->ma);
	printf("Nombre de ports : %u\n", sw->nb_ports);
	printf("Priorité STP : %u\n", sw->priorite_stp);
	printf("Table de commutation : ");
	afficher_table_commutation(sw->tc);
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

