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

    init_reseau_t(&rs);
	
    deinit_reseau_t(&rs);



    equipement_t eq_station = {
        .type = STATION,
        .contenu.st = {
            .ip = {{192, 168, 1, 42}},
            .mac = {{0x00, 0x1A, 0x2B, 0x3C, 0x4D, 0x5E}}
        }
    };

    equipement_t eq_switch = {
        .type = SWITCH,
        .contenu.sw = {
            .ma = {{0xDE, 0xAD, 0xBE, 0xEF, 0x00, 0x01}},
            .nb_ports = 24,
            .priorite_stp = 32768,
            .tc = NULL
        }
    };

    printf("Affichage station :\n");
    afficher_equipement_t(&eq_station);
    printf("\nAffichage switch :\n");
    afficher_equipement_t(&eq_switch);

    lien_t lien_test = { .id1 = 30, .id2 = 40, .poids = 19 };

    afficher_lien_t(&lien_test);
    return EXIT_SUCCESS;
}
