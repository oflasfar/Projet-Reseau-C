#include "include/reseau.h"
#include "include/station.h"
#include "include/switch.h"
#include <stdlib.h>
#include <stdio.h>

void init_reseau_t(reseau_t * rs)
{
	// Toutes les capacités sont à 8 par défaut.
	rs->capacite_liens = 8;
	rs->liens = calloc(rs->capacite_liens, sizeof(lien_t));
	if (rs->liens == NULL)
	{
		fprintf(stderr, "Erreur dans le malloc rs->liens de init_reseau_t()");
		perror("malloc : ");
	}

	rs->capacite_stations = 8;
	rs->stations = calloc(rs->capacite_stations, sizeof(station_t));
	if (rs->stations == NULL)
	{
		fprintf(stderr, "Erreur dans le malloc rs->stations de init_reseau_t()");
		perror("malloc : ");
	}
	rs->nb_stations = 0;

	rs->capacite_switches = 8;
	rs->switches = calloc(rs->capacite_switches, sizeof(switch_t)); 
	if (rs->switches == NULL)
	{
		fprintf(stderr, "Erreur dans le malloc rs->switches de init_reseau_t()");
		perror("malloc : ");
	}
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

void ajouter_station_t(reseau_t * rs, station_t st)
{
	if (rs->nb_stations == rs->capacite_stations)
	{
		// On multiplie par deux la capacité des stations
		rs->capacite_stations *= 2;
		rs->stations = realloc(rs->stations, sizeof(station_t) * rs->capacite_stations);
		if (rs->stations == NULL)
		{
			fprintf(stderr, "Erreur dans le realloc rs->stations de ajouter_station_t()");
			perror("realloc : ");
		}
	}
	rs->stations[rs->nb_stations] = st;
	rs->nb_stations++;
}

/*
void afficher_reseau(const reseau_t * rs)
{

}

void ajouter_lien_t(reseau_t * rs, lien_t lien)
{

}
*/
