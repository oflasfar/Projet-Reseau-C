#include <stdio.h>
#include <stdlib.h>

// Headers

#include "include/ip.h"
#include "include/mac.h"
#include "include/station.h"
#include "include/table_commutation.h"
#include "include/switch.h"

int main(void)
{
	// Début tests
	mac_address_t ma;
	ip_address_t ip;
	entree_table_commutation_t etc;
	table_commutation_t tc;

	// Test structure mac_address_t avec une @MAC arbitraire
	printf("-- Test mac_address_t --\n");
	for (size_t i = 0 ; i < 6 ; i++)
	{
		ma.octet[i] = 50+i;
	}
	printf("-- Test passé ! --\n");

	// Test structure ip_address_t avec une @IP arbitraire
	printf("-- Test ip_address_t --\n");
	for (size_t i = 0 ; i < 4 ; i++)
	{
		ip.paquet[i] = 100+i;
	}
	ip.masque = 24;
	printf("-- Test passé ! --\n");

	printf("-- Test afficher_mac() --\n");
	afficher_mac(&ma);
	printf("-- Test passé ! --\n");
	
	printf("-- Test afficher_ip() --\n");
	afficher_ip(&ip);
	printf("-- Test passé ! --\n");

	printf("-- Test entree_table_commutation_t --\n");
	etc.ma = ma;
	etc.port = 3;
	printf("-- Test passé ! --\n");

	printf("-- Test afficher_entree_table_commutation() --\n");
	afficher_entree_table_commutation(&etc);
	printf("-- Test passé ! --\n");

	printf("-- Test init_table_commutation_t --\n");
	init_table_commutation_t(&tc);
	printf("-- Test passé ! --\n");	
	
	for (size_t i = 0 ; i < 10 ; i++)
	{
		printf("[DEBUG] tc.nb_entree %u, tc.capacite %u : \n", tc.nb_entree, tc.capacite);
		etc.port = i;
		ajouter_entree_table_commutation(&tc, etc);
	}

	afficher_table_commutation(&tc);

	printf("-- Test deinit_table_commutation_t --\n");
	deinit_table_commutation_t(&tc);
	printf("-- Test passé ! --\n");

	printf("-- Test init_switch_t --\n");
	switch_t sw;
	
	init_switch_t(&sw, ma, 0);

	// Ajout d'entrées pour le test
	for (size_t i = 0 ; i < 10 ; i++)
	{
		etc.port = i;
		ajouter_entree_table_commutation(sw.tc, etc);
	}
	
	afficher_switch(&sw);

	deinit_switch_t(&sw);
	// Fin tests 
	return EXIT_SUCCESS;
}
