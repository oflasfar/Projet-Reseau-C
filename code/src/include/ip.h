#pragma once

// Structure pour l'@IP
typedef struct
{
	unsigned char paquet[4]; 
	unsigned char masque;
} ip_address_t;

void afficher_ip(const ip_address_t * ip);
