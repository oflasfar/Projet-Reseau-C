#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/config.h"

int charger_configuration(reseau_t* reseau, const char* chemin) {
    FILE* f = fopen(chemin, "r");
    if (!f) {
        perror("Erreur ouverture fichier");
        return 0;
    }

    char ligne[128];
    if (!fgets(ligne, sizeof(ligne), f)) return 0;

    unsigned short nb_eq, nb_liens;
    sscanf(ligne, "%hu %hu", &nb_eq, &nb_liens);

    // Initialiser capacité du réseau
    reseau->capacite_stations = nb_eq;
    reseau->capacite_switches = nb_eq;
    reseau->capacite_liens = nb_liens;

    reseau->stations = malloc(nb_eq * sizeof(station_t));
    reseau->switches = malloc(nb_eq * sizeof(switch_t));
    reseau->liens = malloc(nb_liens * sizeof(lien_t));
    reseau->nb_stations = reseau->nb_switches = reseau->nb_liens = 0;

    while (fgets(ligne, sizeof(ligne), f)) {
        char type;
        sscanf(ligne, "%c", &type);

        if (type == '2') {
            // Switch
            char mac_str[32];
            unsigned short nb_ports, priorite;
            sscanf(ligne, "2;%31[^;];%hu;%hu", mac_str, &nb_ports, &priorite);
            mac_address_t mac;
            // fonction à écrire : init_mac_address_t(&mac, mac_str)
            init_mac_address_t(&mac, mac_str);

            switch_t sw;
	  
            sw.nb_ports = nb_ports;
            sw.priorite_stp = priorite;
            sw.ma = mac;
	    sw.tc = malloc(sizeof(table_commutation_t));
	    if (!sw.tc) {
		perror("malloc");
		exit(EXIT_FAILURE);
		}

            init_table_commutation_t(sw.tc);
            reseau->switches[reseau->nb_switches++] = sw;

        } else if (type == '1') {
            // Station
            char mac_str[32], ip_str[32];
            sscanf(ligne, "1;%31[^;];%31[^\n]", mac_str, ip_str);
            station_t st;
            init_station_t(&st, ip_str, mac_str);
            ajouter_station_t(reseau, st);

        } else if (type == '0') {
            // Lien
            unsigned short id1, id2, poids;
            sscanf(ligne, "0;%hu;%hu;%hu", &id1, &id2, &poids);
            lien_t l = { id1, id2, poids };
            ajouter_lien_t(reseau, l);
        }
    }

    fclose(f);
    return 1;
}
