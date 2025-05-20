#pragma once

// Structure pour une entrée de table de commutation 
typedef struct
{
	unsigned short port;
	mac_address_t ma;
} entree_table_commutation_t;

typedef struct
{
	entree_table_commutation_t * entrees;
	unsigned short nb_entree;
	unsigned short capacite;
} table_commutation_t;

void afficher_entree_table_commutation(const entree_table_commutation_t * etc);

void afficher_table_commutation(const table_commutation_t * tc);

void init_table_commutation_t(table_commutation_t * tc);

void deinit_table_commutation_t(table_commutation_t * tc);

void ajouter_entree_table_commutation(table_commutation_t * tc, entree_table_commutation_t etc);
