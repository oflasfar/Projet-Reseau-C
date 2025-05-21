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

// Union pour représenter un élément du réseau
typedef union
{
	unsigned short type; // 0 pour une station, 1 pour un switch
	unsigned short id;
	station_t st;
	switch_t sw;
}

// Structure pour représenter un réseau
typedef struct 
{
	switch_t* switches;
    	unsigned short nb_switches;
	unsigned short capacite_switches;

    	station_t* stations;
    	unsigned short nb_stations;
	unsigned short capacite_stations;

    	lien_t* liens;
    	unsigned short nb_liens;
	unsigned short capacite_liens;
} reseau_t;


void init_reseau_t(reseau_t * rs);

void deinit_reseau_t(reseau_t * rs);

void afficher_reseau_t(const reseau_t * rs);

void ajouter_lien_t(reseau_t * rs, lien_t lien);

void ajouter_station_t(reseau_t * rs, station_t st);
/*
 * Pas sur pour celui-ci
void supprimer_lien_t(reseau_t * rs);
*/
