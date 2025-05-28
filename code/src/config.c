#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/config.h"

#define TAILLE_BUFFER 256

void charger_configuration(reseau_t * rs, const char * path) 
{
	// Charger les données contenues dans le fichier de configuration se situant dans path dans le réseau passé en argument
	FILE * fichier = fopen(path, "r");

	if (fichier == NULL)
	{
		perror("fopen (charger_configuration)");
		deinit_reseau_t(rs);
		exit(EXIT_FAILURE);
	}

	char ligne_buffer[TAILLE_BUFFER];

	if (fgets(ligne_buffer, sizeof(ligne_buffer), fichier) != NULL)
	{
		// Parsing du nombre d'équipements et du nombre de liens
		if (sscanf(ligne_buffer, "%hu %hu", &rs->nb_equipements, &rs->nb_liens) != 2)
		{
			fprintf(stderr, "Erreur : fichier de configuration malformé\n");
			deinit_reseau_t(rs);
			fclose(fichier);
			exit(EXIT_FAILURE);
		}
		
		// Ajout des équipements
		for (size_t i = 0 ; i < rs->nb_equipements ; i++)
		{
			if (fgets(ligne_buffer, sizeof(ligne_buffer), fichier) != NULL)
    			{
        			ajouter_equipement_t(rs, ligne_buffer);
    			}
    			else
    			{
        			fprintf(stderr, "Erreur : nombre de liens incorrect dans le fichier\n");
				deinit_reseau_t(rs);
        			fclose(fichier);
        			exit(EXIT_FAILURE);
    			}
		}

		// Ajout des liens
		for (size_t i = 0 ; i < rs->nb_liens ; i++) // rs->nb_liens ; i++)
		{
    			if (fgets(ligne_buffer, sizeof(ligne_buffer), fichier) != NULL)
    			{
        			ajouter_lien_t(rs, ligne_buffer);
    			}
    			else
    			{
        			fprintf(stderr, "Erreur : nombre de liens incorrect dans le fichier\n");
				deinit_reseau_t(rs);
        			fclose(fichier);
        			exit(EXIT_FAILURE);
    			}
		}
		
	}

		

	fclose(fichier);
}

