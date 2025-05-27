# TODO

1. ✅ Compléter les fonctions dans `reseau.c` :
   - [ ] `init_reseau_t(reseau_t * rs)`
   - [ ] `deinit_reseau_t(reseau_t * rs)`
   - [ ] `ajouter_station_t(reseau_t * rs, station_t st)`
   - [ ] `ajouter_lien_t(reseau_t * rs, lien_t lien)`
   - [ ] `afficher_reseau(const reseau_t * rs)`

2. ✅ Ajouter la vérification du retour de `init_mac_address_t` dans `config.c` :
   - [ ] Ligne : `init_mac_address_t(&mac, mac_str);` → vérifier le `return` (sinon continuer avec des valeurs potentiellement invalides).

3. ✅ Dans `station.c` :
   - [ ] Corriger la logique de retour de `init_station_t` :
     Actuellement, la logique est inversée : `init_ip_address_t` et `init_mac_address_t` retournent `EXIT_SUCCESS` (0) en cas de succès.
     Il faut tester `== EXIT_SUCCESS` et non simplement `if (...)` qui traite 0 comme faux.

4. ✅ Dans `switch.c` :
   - [ ] Utiliser `init_switch_t` dans `config.c` au lieu de manuellement initialiser le `switch_t`.

5. ✅ Dans `reseau.c` :
   - [ ] Les fonctions `ajouter_station_t` et `ajouter_lien_t` doivent mettre à jour les compteurs `nb_stations` et `nb_liens` du réseau.

6. ✅ Dans `reseau.c` :
   - [ ] Ajouter vérification que la capacité n’est pas dépassée avant ajout de stations ou de liens.

7. ✅ Dans `table_commutation.c` :
   - [ ] Compléter `ajouter_entree_table_commutation` (incomplète : partie après le `*= 2;` absente).

8. ✅ Vérifier la gestion des erreurs dans toutes les fonctions d'initialisation (poursuivre sur valeur invalide peut provoquer des segfaults).

9. ✅ Protéger tous les appels à `malloc` et `calloc` avec des vérifications systématiques.

10. ✅ Facultatif : Ajouter un logger ou une macro de debug légère pour faciliter le suivi de l’exécution.
