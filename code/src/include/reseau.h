#pragma once

typedef struct {
    int id1;
    int id2;
    int poids;
} lien_t;

typedef struct {
    switch_t* switches;
    int nb_switches;

    station_t* stations;
    int nb_stations;

    lien_t* liens;
    int nb_liens;
} reseau_t;


void init_reseau_t(reseau_t * rs);

void deinit_reseau_t(reseau_t * rs);

void afficher_reseau_t(const reseau_t * rs);

void ajouter_lien_t(reseau_t * rs,lien_t lien);

// TODO ajouter supprimer lien
