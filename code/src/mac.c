#include <stdio.h>
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

