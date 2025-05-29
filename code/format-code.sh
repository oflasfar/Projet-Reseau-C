#!/bin/bash

# Programme qui exécute le formatage automatique du code selon le fichier .clang-format
# Actuellement bugué (à fix)

echo "Formatage en cours"
find . -type f \( -name "*.cpp" -o -name "*.hpp" \) | xargs clang-format -i
echo "Formatage terminé"
