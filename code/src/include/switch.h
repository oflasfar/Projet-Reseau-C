#pragma once

#include "mac.h"
#include "table_commutation.h"

// Structure pour un switch
typedef struct
{
	mac_address_t ma;
	unsigned short nb_ports;
	unsigned short priorite_stp;
	table_commutation_t * tc;
} switch_t;

// Fonctions pour switch_t
void afficher_switch(const switch_t * sw);

void init_switch_t(switch_t * sw, mac_address_t ma, unsigned short priorite_stp);

void deinit_switch_t(switch_t * sw);
