#include <stdio.h>
#include <stdlib.h>

// Headers

#include "include/ip.h"
#include "include/mac.h"
#include "include/station.h"
#include "include/table_commutation.h"
#include "include/switch.h"
#include "include/reseau.h"
#include "include/config.h"

int main(void)
{
	reseau_t rs;
	
	init_reseau_t(&rs);

	charger_configuration(&rs, "configurations/lan1.lan");
	

	printf("Configuration chargée !\n");
	

	afficher_reseau_t(&rs);

	deinit_reseau_t(&rs);

	return EXIT_SUCCESS;
}
