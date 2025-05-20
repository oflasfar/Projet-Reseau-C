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



void lire_fichier_config(const char* nom_fichier) {
    FILE* f = fopen(nom_fichier, "r");
    if (!f) {
        perror("Erreur ouverture fichier");
        exit(EXIT_FAILURE);
    }

    int nb_equipements, nb_liens;
    fscanf(f, "%d %d\n", &nb_equipements, &nb_liens);

    reseau_t* r = malloc(sizeof(reseau_t));
    r->switches = malloc(nb_equipements * sizeof(switch_t)); // sur-allocation
    r->stations = malloc(nb_equipements * sizeof(station_t));
    r->liens = malloc(nb_liens * sizeof(lien_t));
    r->nb_switches = 0;
    r->nb_stations = 0;
    r->nb_liens = nb_liens;

    for (int i = 0; i < nb_equipements; i++) {
        int type;
        fscanf(f, "%d", &type);

        if (type == 2) {
            switch_t sw;
            lire_mac(f, &sw.ma);
            fscanf(f, "%hu %hu", &sw.nb_ports, &sw.priorite_stp);
            sw.tc = malloc(sizeof(table_commutation_t));
            init_table_commutation_t(sw.tc);

            r->switches[r->nb_switches++] = sw;
        }
        else if (type == 1) {
            station_t st;
            lire_mac(f, &st.mac);
            lire_ip(f, &st.ip);
            r->stations[r->nb_stations++] = st;
        }
    }

    for (int i = 0; i < nb_liens; i++) {
        fscanf(f, "%d %d %d", &r->liens[i].id1, &r->liens[i].id2, &r->liens[i].poids);
    }

    fclose(f);
    
}

// TODO ajouter supprimer lien