#pragma once

#include "switch.h"
#include "ip.h"
#include "mac.h"
#include "station.h"

// Structure pour représenter un lien
typedef struct 
{
	unsigned short id1;
    	unsigned short id2;
    	unsigned short poids;
} lien_t;

// Structure pour représenter un réseau
typedef struct 
{
	switch_t* switches;
    	unsigned short nb_switches;

    	station_t* stations;
    	unsigned short nb_stations;

    	lien_t* liens;
    	unsigned nb_liens;
} reseau_t;


void init_reseau_t(reseau_t * rs);

void deinit_reseau_t(reseau_t * rs);

void afficher_reseau_t(const reseau_t * rs);

void ajouter_lien_t(reseau_t * rs, lien_t lien);

/*
 * Pas sur pour celui-ci
void supprimer_lien_t(reseau_t * rs);
*/
