#include <stdio.h>
#include <stdlib.h>

// Nos headers
#include "include/reseau.h"


int main(void)
{
	mac_address ma;
	for (size_t i = 0 ; i < 6 ; i++)
	{
		ma.octet[i] = 50+i;
	}

	afficher_mac(&ma);

	return EXIT_SUCCESS;
}
