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

// Enum pour le type ici
typedef enum
{
    STATION,
    SWITCH
} type_equipement_t;

// Union pour représenter un élément du réseau
typedef struct
{
    type_equipement_t type;
    unsigned short id;
    union
    {
        station_t st;
        switch_t sw;
    } contenu;
} equipement_t;

// Structure pour représenter un réseau
typedef struct 
{
	equipement_t * equipements;
    unsigned short nb_equipements;
    unsigned short capacite_equipements;

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

void afficher_lien_t(const lien_t * ln);

void afficher_equipement_t(const equipement_t * eq);
