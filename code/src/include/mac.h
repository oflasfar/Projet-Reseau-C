#pragma once

// Structure pour l'@MAC
typedef struct
{
  unsigned char octet[6];
} mac_address_t;

void afficher_mac(const mac_address_t *ma);

int init_mac_address_t(mac_address_t *ma, const char *mac_char);
