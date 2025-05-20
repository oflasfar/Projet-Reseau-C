#pragma once

// Structure pour l'@MAC
typedef struct
{
	unsigned char octet[6];
} mac_address_t;

// Structure pour l'@IP
typedef struct
{
	unsigned char paquet[4]; 
	unsigned char masque;
} ip_address_t;

// Structure pour une station
typedef struct
{
	ip_address_t ip;
	mac_address_t mac;
} station_t;

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

// Structure pour un switch
typedef struct
{
	mac_address_t ma;
	unsigned short nb_ports;
	unsigned short priorite_stp;
	table_commutation_t * tc;
} switch_t;

// Fonctions d'affichage
void afficher_mac(const mac_address_t * ma);

void afficher_ip(const ip_address_t * ip);

void afficher_station(const station_t * st);

void afficher_entree_table_commutation(const entree_table_commutation_t * etc);

void afficher_table_commutation(const table_commutation_t * tc);

void afficher_switch(const switch_t * sw);

// Fonctions pour table_commutation_t
void init_table_commutation_t(table_commutation_t * tc);

void deinit_table_commutation_t(table_commutation_t * tc);

void ajouter_entree_table_commutation(table_commutation_t * tc, entree_table_commutation_t etc);

// Fonctions pour switch_t
void init_switch_t(switch_t * sw, mac_address_t ma, unsigned short priorite_stp);

void deinit_switch_t(switch_t * sw);

