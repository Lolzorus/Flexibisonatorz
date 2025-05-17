#!/bin/bash

# Nettoyage éventuel
rm -f Flexibisonatorz-1.0.deb

# Donne les droits corrects au dossier DEBIAN
chmod 755 Flexibisonatorz-1.0/DEBIAN

# Construction du .deb
dpkg-deb --build Flexibisonatorz-1.0

# Confirmation
echo "✅ Paquet flexibisonatorz-1.0.deb généré avec succès."

