#pragma once

// Structure pour l'@MAC
typedef struct
{
	unsigned char octet[6];
} mac_address;

// Structure pour l'@IP
typedef struct
{
	unsigned char paquet[4]; 
	unsigned char masque;
} ip_address;

// Structure pour une station
typedef struct
{
	ip_address ip;
	mac_address mac;
} station; 

// Fonctions d'affichage
void afficher_mac(const mac_address * ma);

void afficher_ip(const ip_address * ip);

void afficher_station(const station * st);
