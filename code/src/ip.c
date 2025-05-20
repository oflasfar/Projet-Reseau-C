#include <stdio.h>
#include "include/ip.h"

void afficher_ip(const ip_address_t * ip)
{
	for (unsigned int i = 0 ; i < 4 ; i++)
	{
		printf("%d", ip->paquet[i]);
		if (i < 3)
			printf(".");
	}
	printf("/%d\n", ip->masque);
}

