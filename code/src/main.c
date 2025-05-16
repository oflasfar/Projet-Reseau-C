#include <stdio.h>
#include <stdlib.h>

// Nos headers
#include "include/reseau.h"


int main(void)
{
	mac_address ma;
	ip_address ip;

	for (size_t i = 0 ; i < 6 ; i++)
	{
		ma.octet[i] = 50+i;
	}

	for (size_t i = 0 ; i < 4 ; i++)
	{
		ip.paquet[i] = 100+i;
	}
	ip.masque = 24;

	afficher_mac(&ma);

	afficher_ip(&ip);

	return EXIT_SUCCESS;
}
