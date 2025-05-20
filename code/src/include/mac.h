#pragma once

// Structure pour l'@MAC
typedef struct
{
	unsigned char octet[6];
} mac_address_t;

void afficher_mac(const mac_address_t * ma);

