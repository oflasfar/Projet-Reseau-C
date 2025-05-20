#include <stdio.h>
#include <stdlib.h>
#include "include/mac.h"

void afficher_mac(const mac_address_t * ma)
{
	for (unsigned int i = 0 ; i < 6 ; i++)
	{
		printf("%02X", ma->octet[i]);
		if (i < 5)
			printf(":");
	}
	printf("\n");
}

int init_mac_address_t(mac_address_t * ma, const char * mac_char)
{
	mac_address_t tmp;
	// Extraire chaque octet de l'adresse IP
	if (sscanf(mac_char, "%hhx:%hhx:%hhx:%hhx:%hhx:%hhx", &tmp.octet[0], &tmp.octet[1], &tmp.octet[2], &tmp.octet[3], &tmp.octet[4], &tmp.octet[5]) != 6)
	{
		fprintf(stderr, "Erreur dans le sscanf() de init_mac_address_t() : mise à 0\n");
		// 0 partout si échec
		for (size_t i = 0 ; i < 6 ; i++)
		{
			ma->octet[i] = 0;
		}
		return EXIT_FAILURE;
	}

	for (size_t i = 0 ; i < 6 ; i++)
	{
		ma->octet[i] = tmp.octet[i];
	}

	return EXIT_SUCCESS;
}

