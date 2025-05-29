#include "include/ip.h"
#include <stdio.h>
#include <stdlib.h>

void afficher_ip_t(const ip_address_t *ip)
{
  for (unsigned int i = 0; i < 4; i++)
  {
    printf("%d", ip->paquet[i]);
    if (i < 3)
      printf(".");
  }
  printf("/%d\n", ip->masque);
}

int init_ip_address_t(ip_address_t *ip, const char *ip_char)
{
  ip_address_t tmp;
  // Extraire chaque octet de l'adresse IP
  if (sscanf(ip_char, "%hhu.%hhu.%hhu.%hhu/%hhu", &tmp.paquet[0],
             &tmp.paquet[1], &tmp.paquet[2], &tmp.paquet[3], &tmp.masque) != 5)
  {
    fprintf(stderr,
            "Erreur dans le sscanf() de init_ip_address_t() : mise à 0\n");
    // 0 partout si échec
    for (size_t i = 0; i < 4; i++)
    {
      ip->paquet[i] = 0;
    }
    ip->masque = 0;

    return EXIT_FAILURE;
  }
  if (tmp.masque > 32 || tmp.masque < 1)
  {
    fprintf(stderr, "Erreur : le masque doit être valide, mise à 0\n");
    // 0 partout si échec
    for (size_t i = 0; i < 4; i++)
    {
      ip->paquet[i] = 0;
    }
    ip->masque = 0;
    return EXIT_FAILURE;
  }

  for (size_t i = 0; i < 4; i++)
  {
    ip->paquet[i] = tmp.paquet[i];
  }
  ip->masque = tmp.masque;

  return EXIT_SUCCESS;
}
