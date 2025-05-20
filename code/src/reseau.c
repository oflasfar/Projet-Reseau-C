#include "include/reseau.h"
#include "include/station.h"
#include "include/switch.h"
#include <stdlib.h>

void init_reseau_t(reseau_t * rs)
{
	rs->liens = malloc(sizeof(lien_t));
	rs->nb_liens = 0;

	rs->stations = malloc(sizeof(station_t));
	rs->nb_stations = 0;

	rs->switches = malloc(sizeof(switch_t));
	rs->nb_switches = 0;
}

void deinit_reseau_t(reseau_t * rs)
{
	free(rs->switches);
	rs->switches = NULL;

	free(rs->stations);
	rs->stations = NULL;

	free(rs->liens);
	rs->liens = NULL;
}

/*
void afficher_reseau(const reseau_t * rs)
{

}

void ajouter_lien_t(reseau_t * rs, lien_t lien)
{

}
*/
