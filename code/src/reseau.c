#include "include/reseau.h"

// temporaire
#include <stdio.h>

void afficher_mac(const mac_address * ma)
{
	for (unsigned int i = 0 ; i < 6 ; i++)
	{
		printf("%02X", ma->octet[i]);
		if (i < 5)
			printf(":");
	}
	printf("\n");
}
