import tkinter as tk
from tkinter import filedialog, messagebox
import subprocess
import os

def traduire():
	pseudo_code = champ_texte.get("1.0", tk.END)
	
	# Écrit le pseudo-code dans un fichier temporaire
	with open("input.txt", "w") as f:
		f.write(pseudo_code)
	
	# Lance le traducteur
	result = subprocess.run(["/usr/share/traducteur"], input=pseudo_code.encode(), stdout=subprocess.PIPE, stderr=subprocess.PIPE)

	
	if os.path.exists("output.c"):
		with open("output.c", "r") as f:
			code_c = f.read()
		champ_resultat.delete("1.0", tk.END)
		champ_resultat.insert(tk.END, code_c)
	else:
		messagebox.showerror("Erreur", "La traduction a échoué.\n" + result.stderr.decode())

def afficher_mode_emploi():
    fenetre_aide = tk.Toplevel(root)
    fenetre_aide.title("Mode d'emploi")

    texte = """\
✅ MODE D’EMPLOI POUR FLEXIBISONATORZ

🧠 Description :
FLEXIBISONATORZ est un traducteur pédagogique qui transforme un pseudo-langage simplifié en code C.
Il est conçu pour aider les débutants à comprendre la logique du langage C via des instructions en français.

📌 Comment utiliser ce programme :
1. Écrivez ou chargez un fichier .txt contenant du pseudo-code dans la zone supérieure.
2. Cliquez sur "Traduire en C".
3. Le code C généré s'affiche dans la zone inférieure.
4. Vous pouvez sauvegarder le résultat dans un fichier output.c.

🧾 Syntaxe du pseudo-langage :

| Instruction pseudo                           | Traduction C                          |
|---------------------------------------------|---------------------------------------|
| # commentaire                               | // commentaire                        |
| afficher "Texte"                            | printf("Texte\\n");                    |
| afficher x                                  | printf("%d\\n", x);                   |
| declarer int x comme x = 5                  | int x = 5;                             |
| declarer int x                              | int x;                                 |
| declarer chaine nom                         | char nom[256];                         |
| demander nom "Quel est ton nom ?"          | printf(...); scanf(...);              |
| si x == 5 alors afficher "ok" sinon ...     | if (...) { ... } else { ... }         |
| pour i = 0 jusqua 10 faire afficher i       | for (...) { ... }                     |
| tant que condition faire ...                | while (...) { ... }                   |
| et                                          | Permet d'enchaîner plusieurs actions  |

🧪 Exemple de pseudo-code :

# ceci est un commentaire
afficher "Initial"
declarer int x comme x = 5
afficher x
si x <= 5 alors afficher "OK" sinon afficher "NON"
pour i = 0 jusqua 10 faire afficher i

🔁 Génère le code C suivant :

#include <stdio.h>
int main() {
    // ceci est un commentaire
    printf("Initial\\n");
    int x = 5;
    printf("%d\\n", x);
    if (x <= 5) {
        printf("OK\\n");
    } else {
        printf("NON\\n");
    }
    for (int i = 0; i <= 10; i++) {
        printf("%d\\n", i);
    }
    return 0;
}

⚠️ Remarques :
- Le pseudo-langage est sensible à la syntaxe.
- Respectez bien les mots-clés définis : afficher, declarer, si, etc.
- Le traducteur (./traducteur) doit être compilé et accessible dans le dossier du programme.
"""

    # Widget Texte + Scrollbar
    cadre = tk.Frame(fenetre_aide)
    cadre.pack(fill=tk.BOTH, expand=True)

    scrollbar = tk.Scrollbar(cadre)
    scrollbar.pack(side=tk.RIGHT, fill=tk.Y)

    zone_texte = tk.Text(cadre, wrap=tk.WORD, yscrollcommand=scrollbar.set, height=30, width=100)
    zone_texte.insert(tk.END, texte)
    zone_texte.config(state=tk.DISABLED)
    zone_texte.pack(fill=tk.BOTH, expand=True)

    scrollbar.config(command=zone_texte.yview)


# Interface graphique principale
root = tk.Tk()
root.title("FLEXIBISONATORZ - Traducteur vers le C")

champ_texte = tk.Text(root, height=15, width=80)
champ_texte.pack(padx=10, pady=10)

btn_traduire = tk.Button(root, text="Traduire en C", command=traduire)
btn_traduire.pack(pady=(0,5))

champ_resultat = tk.Text(root, height=15, width=80, bg="#f0f0f0")
champ_resultat.pack(padx=10, pady=(0,5))

btn_mode_emploi = tk.Button(root, text="📘 Mode d'emploi", command=afficher_mode_emploi)
btn_mode_emploi.pack(pady=(0, 10))

root.mainloop()

