#pragma once

// Structure pour l'@IP
typedef struct
{
	unsigned char paquet[4]; 
	unsigned char masque;
} ip_address_t;

void afficher_ip_t(const ip_address_t * ip);

int init_ip_address_t(ip_address_t * ip, const char * ip_char);
