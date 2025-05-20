#include <stdio.h>
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
