#!/bin/bash
echo "Installation de FLEXIBISONATORZ..."

# Vérifier les dépendances
for cmd in flex bison gcc python3 python3-tk; do
    if ! command -v $cmd &>/dev/null; then
        echo "Erreur : $cmd n'est pas installé."
        exit 1
    fi
done

# Compiler
cd build
make
cd ..

echo "Lancement de l’interface avec : python3 gui/gui.py"

