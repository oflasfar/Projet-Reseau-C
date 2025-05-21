#include <stdio.h>
#include <stdlib.h>
#include "include/ip.h"
#include "include/mac.h"
#include "include/station.h"

void afficher_station(const station_t * st)
{
	printf("IP : ");
	afficher_ip_t(&st->ip);
	printf("\nMAC : ");
	afficher_mac(&st->mac);
}

int init_station_t(station_t * st, const char * ip, const char * mac)
{
	ip_address_t tmp_ip;
	mac_address_t tmp_ma;

	if (init_ip_address_t(&tmp_ip, ip))
	{
		st->ip = tmp_ip;
	}
	else
	{
		st->ip = (ip_address_t){{0, 0, 0, 0}, 0}
		return EXIT_FAILURE;
	}

	if (init_mac_address_t(&tmp_ma, mac))
	{
		st->mac = tmp_ma;
	}
	else 
	{
		st->mac = (mac_address_t){{0, 0, 0, 0}};
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
