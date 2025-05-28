#include "include/reseau.h"
#include "include/mac.h"
#include "include/station.h"
#include "include/switch.h"
#include <stdlib.h>
#include <stdio.h>

#define CAPACITE_INITIALE 8
#define TAILLE_BUFFER 256

void init_reseau_t(reseau_t * rs)
{
    // Le réseau pourra contenir jusqu'à CAPACITE_INITIALE équipements initialement
    // Il en est de même pour les liens
    rs->nb_equipements = 0;
    rs->index_equipement_actuel = 0;
    rs->capacite_equipements = CAPACITE_INITIALE;

    rs->equipements = malloc(rs->capacite_equipements * sizeof(equipement_t)); // Pas de calloc() dans le code pour une lecture plus intuitive
    if (rs->equipements == NULL)
    {
        perror("malloc (init_reseau_t -> equipements) : ");
        exit(EXIT_FAILURE);
    }

    rs->nb_liens = 0;
    rs->index_lien_actuel = 0;
    rs->capacite_liens = CAPACITE_INITIALE;

    rs->liens = malloc(rs->capacite_liens * sizeof(lien_t));
    if (rs->liens == NULL)
    {
        perror("malloc (init_reseau_t -> liens) : ");
        free(rs->equipements);
        exit(EXIT_FAILURE);
    }


}


void deinit_reseau_t(reseau_t * rs)
{
    // Mise à zéro et libération de la mémoire allouée
    rs->capacite_equipements = 0;
    rs->capacite_liens = 0;
    rs->nb_equipements = 0;
    rs->nb_liens = 0;
    free(rs->equipements);
    rs->equipements = NULL;
    free(rs->liens);
    rs->liens = NULL;
}

/*
void ajouter_station_t(reseau_t * rs, station_t st)
{

}
*/

void afficher_reseau_t(const reseau_t * rs)
{
    // Afficher le contenu d'un réseau (équipements, liens, etc)
    printf("=== Réseau ===\n");
    printf("Nombre d'équipements : %hu\n", rs->nb_equipements);

    for (size_t i = 0 ; i < rs->nb_equipements ; i++)
    {
        afficher_equipement_t(&rs->equipements[i]);
    }

    printf("\n");

    printf("Nombre de liens : %hu\n", rs->nb_liens);
    for (size_t i = 0 ; i < rs->nb_liens ; i++)
    {
        afficher_lien_t(&rs->liens[i]);
    }
    printf("\n");
}

void afficher_equipement_t(const equipement_t * eq)
{
    // Afficher un équipement selon son type défini dans la structure via l'énumération
    switch (eq->type)
    {
        case STATION:
            printf("Type : Station\nAdresse IP : ");
            afficher_ip_t(&eq->contenu.st.ip);
            printf("Adresse MAC : ");
            afficher_mac(&eq->contenu.st.mac);
	    printf("\n");
            break;
        case SWITCH:
            printf("Type : Switch\nAdresse MAC : ");
            afficher_mac(&eq->contenu.sw.ma);
            printf("\nNombre de ports : %hu\nPriorité STP : %hu\nTable de commutation :\n", eq->contenu.sw.nb_ports, eq->contenu.sw.priorite_stp);
            afficher_table_commutation(eq->contenu.sw.tc);
            break;
        default:
            fprintf(stderr, "Erreur : type d'équipement inconnu\n");
            break;
    }
}

void afficher_lien_t(const lien_t * ln)
{
    printf("ID équipement 1 : %hu\nID équipement 2 : %hu\nPoids : %hu\n", ln->id1, ln->id2, ln->poids);
}

void ajouter_equipement_t(reseau_t * rs, char * eq_desc)
{
	// Parsing de la ligne contenant l'équipement
	unsigned short eq_type_us;

	type_equipement_t eq_type;

	printf("[DEBUG] : %s", eq_desc);

	// Parsing du type pour le switch-case
	if (sscanf(eq_desc, "%hu", &eq_type_us) != 1)
		perror("sscanf (ajouter_equipement_t)");

	
	if (eq_type_us == 1)
		eq_type = STATION;
	if (eq_type_us == 2)
		eq_type = SWITCH;


	switch (eq_type)
	{
		case STATION:
			{
				equipement_t eq;
				unsigned short tmp;
				if (sscanf(eq_desc, 
							// 1;54:d6:a6:82:c5:23;130.79.80.21 
							"%hu;%hhx:%hhx:%hhx:%hhx:%hhx:%hhx;%hhu.%hhu.%hhu.%hhu", 
							&tmp, 
							&eq.contenu.st.mac.octet[0], 
							&eq.contenu.st.mac.octet[1], 
							&eq.contenu.st.mac.octet[2], 
							&eq.contenu.st.mac.octet[3], 
							&eq.contenu.st.mac.octet[4], 
							&eq.contenu.st.mac.octet[5], 
							&eq.contenu.st.ip.paquet[0],
							&eq.contenu.st.ip.paquet[1],
							&eq.contenu.st.ip.paquet[2],
							&eq.contenu.st.ip.paquet[3]
							) != 11)
				{
					fprintf(stderr, "sscanf (ajouter_equipement_t) : chaîne d'équipement mal formatée\nchaîne fautive : %s \n", eq_desc);
				}
				eq.type = eq_type;
				rs->equipements[rs->index_equipement_actuel] = eq;
				rs->index_equipement_actuel++;
				// ajouter_station_t(rs, st); // TODO : à ajouter
				break;
			}
		// 1;c8:69:72:5e:43:af;130.79.80.27
		case SWITCH:

			break;
		default:
			// should never occur
			break;

	}
}


void ajouter_lien_t(reseau_t * rs, char * lien)
{
	lien_t ln;

	if (sscanf(
				lien, 
				"%hu;%hu;%hu", 
				&ln.id1, &ln.id2, 
				&ln.poids
				) != 3)
	{
		fprintf(stderr, "scanf (ajouter_lien_t) : erreur de format dans la chaîne à parser\n");
		fprintf(stderr, "chaîne fautive : '%s'\n", lien);
		deinit_reseau_t(rs);
		exit(EXIT_FAILURE);
	}

	if (rs->index_lien_actuel == rs->capacite_liens)
	{
		rs->capacite_liens *= 2;
		rs->liens = realloc(rs->liens, sizeof(lien_t) * rs->capacite_liens);
		if (rs->liens == NULL)
		{
			perror("realloc (ajouter_lien_t) ");
			deinit_reseau_t(rs);
			exit(EXIT_FAILURE);
		}
	}
	rs->liens[rs->index_lien_actuel] = ln;
	rs->index_lien_actuel++;
}

