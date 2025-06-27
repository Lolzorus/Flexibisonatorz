# FLEXIBISONATORZ

**FLEXIBISONATORZ** est un logiciel libre de traduction d’un pseudo-langage pédagogique vers le langage C.Ce projet est destiné aux étudiants débutants afin de les initier à la logique du langage C à travers une syntaxe inspirée du français et une interface intuitive.

---

## 🎯 Objectifs du projet

- Concevoir un pseudo-langage simple, inspiré du français.
- Traduire automatiquement ce langage vers du code C valide.
- Fournir une interface graphique conviviale pour faciliter l’utilisation.
- Initier à l’utilisation de Flex et Bison.

---

## 🧠 Fonctionnalités

- ✅ Déclarations de variables (`int`, `chaine`)
- ✅ Affectations et expressions arithmétiques
- ✅ Affichage (`afficher`)
- ✅ Lecture utilisateur (`demander`)
- ✅ Conditions (`si`, `sinon`)
- ✅ Boucles (`pour ... jusqua ... faire`, `tant que ... faire`)
- ✅ Enchaînements d’instructions avec `et`
- ✅ Commentaires (`# commentaire`)
- ✅ Interface graphique (`gui.py`) avec Tkinter
- ✅ Génération de code C dans un fichier `output.c`

---

## 📦 Installation

### Depuis le paquet `.deb` (Debian/Ubuntu)

```bash
sudo dpkg -i flexibisonatorz-1.0.deb
```

### Dépendances

- Python 3
- Tkinter (`sudo apt install python3-tk`)
- Flex & Bison (`sudo apt install flex bison`)

---

## 🚀 Utilisation

### Lancer l’interface graphique

```bash
python3 /usr/share/gui.py
```

### Depuis les sources

```bash
bison -d traducteur.y
flex traducteur.l
gcc traducteur.tab.c lex.yy.c -o traducteur
./traducteur < input.txt
cat output.c
```

---

## 📂 Structure du projet

```text
.
├── src/                     # Sources Flex/Bison + interface
│   ├── traducteur.l         # Analyse lexicale (Flex)
│   ├── traducteur.y         # Analyse syntaxique (Bison)
│   └── interface_source.py  # Logiciel GUI (Tkinter)
├── gui.py                   # Lanceur de l’interface graphique
├── input.txt                # Exemple de pseudo-code d’entrée
├── output.c                 # Fichier de sortie généré
├── README.md                # Documentation principale
├── LICENSE                  # Licence MIT
├── build_deb.sh            # Script de création du .deb
├── uninstall.sh            # Script de désinstallation
└── flexibisonatorz-1.0.deb  # Paquet Debian généré
```

---

## 🧪 Exemple

### Entrée (pseudo-langage) :

```pseudo
# ceci est un commentaire
declarer int x comme x = 5
afficher x
si x <= 5 alors afficher "OK" sinon afficher "NON"
pour i = 0 jusqua 3 faire afficher i
tant que x > 0 faire x = x - 1 et afficher x
```

### Sortie (C) :

```c
#include <stdio.h>
int main() {
    // ceci est un commentaire
    int x = 5;
    printf("%d\n", x);
    if (x <= 5) printf("OK\n");
    else printf("NON\n");
    for (int i = 0; i <= 3; i++) {
        printf("%d\n", i);
    }
    while (x > 0) {
        x = (x - 1);
        printf("%d\n", x);
    }
    return 0;
}
```

---

## 🛠 Améliorations futures

- ✅ Ajout de types supplémentaires (`float`, `bool`, etc.)
- ✅ Gestion des fonctions personnalisées
- ✅ Détection d’erreurs plus précise et messages colorés
- ✅ Mode console interactif


---

## 📄 Licence

Ce projet est sous licence **MIT**.Voir le fichier [LICENSE](./LICENSE) pour plus d’informations.

---

## 💬 Contact & Contributions

Les contributions sont les bienvenues !Pour toute suggestion ou bug, n’hésitez pas à ouvrir une **Issue** ou un **Pull Request** sur GitHub.
