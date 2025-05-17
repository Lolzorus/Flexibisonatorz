FLEXIBISONATORZ

FLEXIBISONATORZ est un logiciel libre permettant de traduire un pseudo-langage pédagogique simple en langage C.
Il s'adresse principalement aux étudiants débutants pour comprendre la logique du langage C à travers une interface graphique intuitive.
🧠 Fonctionnalités

    Traduction automatique de pseudo-code en C
    Interface graphique écrite en Python avec Tkinter
    Chargement de fichiers .txt de pseudo-code
    Sauvegarde du code C généré
    Affichage du mode d'emploi dans l'interface

📦 Installation

Après avoir installé le paquet .deb :

sudo dpkg -i Flexibisonatorz-1.0.deb
Utilisation

Lancez l'interface graphique avec la commande suivante :

python3 /usr/share/gui.py

Depuis l'interface :

    Écrivez ou chargez un pseudo-code
    Cliquez sur "Traduire en C"
    Le résultat s'affiche dans la zone de sortie

## 📂 Structure du projet gui.py : Interface graphique (Tkinter) traducteur : Binaire compilé à partir de Flex & Bison input.txt / output.c : Fichiers temporaires d'entrée/sortie README.md : Ce fichier LICENSE : Licence libre du projet build_deb.sh : Script pour générer le paquet Debian uninstall.sh : Script de désinstallation src/ : Contient les sources (.l, .y, interface_source.py)
🛠 Dépendances

Python 3 Tkinter (souvent dans le paquet python3-tk) Flex & Bison (pour la compilation du traducteur)
👥 Auteurs

Moi— développeur principal

## 📄 Licence Ce projet est distribué sous la licence MIT. Voir le fichier LICENSE pour plus de détails.
🧪 Exemple de pseudo-code traduit

Entrée :

declarer int x comme x = 5 si x <= 5 alors afficher "OK" sinon afficher "NON"

Sortie :

int x = 5; if (x <= 5) { printf("OK\n"); } else { printf("NON\n"); }

Merci d’utiliser FLEXIBISONATORZ ✨
