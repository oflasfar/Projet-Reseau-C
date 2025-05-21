#pragma once

// Structure pour une station
typedef struct
{
	ip_address_t ip;
	mac_address_t mac;
} station_t;

void afficher_station(const station_t * st);

int init_station_t(station_t * st, const char * ip, const char * mac);
