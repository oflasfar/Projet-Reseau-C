#include <stdio.h>
#include <stdlib.h>

// Headers

#include "include/ip.h"
#include "include/mac.h"
#include "include/station.h"
#include "include/table_commutation.h"
#include "include/switch.h"
#include "include/reseau.h"

int main(void)
{
	reseau_t rs;	
	station_t st;
	ip_address_t ip;
	mac_address_t ma;
	init_reseau_t(&rs);
	
	// Initialisations
	init_mac_address_t(&ma, "3C:CD:8D:77:AB:46");
	init_ip_address_t(&ip, "192.168.1.102/24");
	st.ip = ip;
	st.mac = ma;

	for (size_t i = 0 ; i < 1 ; i++)
	{
		printf("DEBUG : %u/%u\n", rs.nb_stations, rs.capacite_stations);
		ajouter_station_t(&rs, st);
		afficher_station(&rs.stations[i]);
	}

	deinit_reseau_t(&rs);
	// Fin tests 
	return EXIT_SUCCESS;
}
