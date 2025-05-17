%{
#include <stdio.h>      // Inclusion de la bibliothèque standard d'entrée/sortie
#include <stdlib.h>     // Inclusion de la bibliothèque standard pour malloc, free, exit...
#include <string.h>     // Inclusion de la bibliothèque pour les fonctions de manipulation de chaînes

#define YYSTYPE char*   // Définition du type des valeurs retournées par le parser : chaîne de caractères
FILE *out;              // Fichier de sortie dans lequel sera généré le code C final
int yylex(void);        // Prototype de la fonction lexicale générée par Flex
int yyerror(char *s);   // Prototype de la fonction d’erreur appelée en cas d’erreur syntaxique

// Structure pour la table des symboles (variables déclarées)
typedef struct Symbole {
	char *nom;             // Nom de la variable
	char *type;            // Type de la variable ("int" ou "chaine")
	struct Symbole *suivant; // Pointeur vers le symbole suivant (liste chaînée)
} Symbole;

Symbole *table_symbole = NULL;  // Pointeur vers le début de la table des symboles

// Fonction pour ajouter une variable dans la table des symboles
void ajouter_symbole(const char *nom, const char *type) {
	// Vérifier si la variable existe déjà (pour éviter doublon)
	for (Symbole *s = table_symbole; s != NULL; s = s->suivant) {
		if (strcmp(s->nom, nom) == 0) return; // Variable déjà présente, on ne fait rien
	}
	// Allocation mémoire d’un nouveau symbole
	Symbole *s = malloc(sizeof(Symbole));
	s->nom = strdup(nom);       // Copier le nom
	s->type = strdup(type);     // Copier le type
	s->suivant = table_symbole; // Insérer en tête de liste chaînée
	table_symbole = s;
}

// Fonction pour récupérer le type d’une variable donnée
const char *type_de_variable(const char *nom) {
	for (Symbole *s = table_symbole; s != NULL; s = s->suivant) {
		if (strcmp(s->nom, nom) == 0) return s->type;  // Retourner le type si trouvée
	}
	return NULL;  // Retourner NULL si variable non trouvée
}

// Fonction utilitaire pour concaténer deux instructions en les séparant par ce qu'on veut (ici un saut de ligne)
char *concat_instruction(const char *i1, const char *i2) {
    char *res = malloc(strlen(i1) + strlen(i2) + 5); // Allocation mémoire
    sprintf(res, "%s\n%s", i1, i2);                 // Formater la chaîne résultat
    return res;
}

// Fonction pour ajouter une tabulation à chaque ligne d'une chaîne (indentation)
char* indent(const char *code) {
    const char *tab = "\t";
    int len = strlen(code);
    char *res = malloc(len * 2 + 1); // allocation large (doublée)
    res[0] = '\0';
    
    const char *ptr = code;
    while (*ptr) {
        strcat(res, tab);  // Ajouter une tabulation
        while (*ptr && *ptr != '\n') {
            strncat(res, ptr, 1);  // Copier caractère par caractère
            ptr++;
        }
        if (*ptr == '\n') {
            strncat(res, ptr, 1);  // Ajouter le \n
            ptr++;
        }
    }
    return res;
}


%}

%define api.value.type {char*}   // Définir que les valeurs retournées par les règles sont des char*
%debug                         // Activer le mode debug Bison

// Déclaration des tokens (mots-clés, opérateurs, identifiants, etc.)
%token AFFICHER SI ALORS INT SINON DECLARER COMME OP DEMANDER POUR JUSQUA FAIRE TANTQUE ET
%token IDENTIFIANT ENTIER CHAINE COMMENTAIRE FINLIGNE

// Priorités des opérateurs pour la résolution des conflits
%left '='
%left '+' '-'
%left '*' '/' '%'
%right ET

%%

// Règle principale : un programme est une suite de lignes ou vide
programme:
	/* vide */
	| programme ligne
	;

// Une ligne est soit une instruction suivie d’un retour à la ligne, soit un commentaire suivi d’un retour à la ligne
ligne:
	instruction FINLIGNE        { fprintf(out, "%s\n", $1); free($1); }  // Écrire instruction dans le fichier de sortie puis libérer la mémoire
	| commentaire FINLIGNE      { fprintf(out, "// %s\n", $1); free($1); }  // Écrire commentaire C dans le fichier et libérer mémoire
	;

// Liste d’instructions, au moins une instruction terminée par FINLIGNE
liste_instructions:
	instruction FINLIGNE liste_instructions
	| instruction FINLIGNE
	;
	
// Liste d’instructions séparées par ET (permet d’enchaîner plusieurs instructions dans un bloc)
liste_et_instructions:
    instruction                          { $$ = $1; }
  | liste_et_instructions ET instruction {
        $$ = concat_instruction($1, $3);  // Concatène les instructions avec un point-virgule et saut de ligne
        free($1); free($3);               // Libère la mémoire temporaire
    }
    ;

// Définition des instructions possibles
instruction:
	affichage
	| DECLARER INT IDENTIFIANT COMME IDENTIFIANT '=' expression {
		ajouter_symbole($3, "int");  // Ajouter la variable à la table des symboles
		$$ = malloc(strlen($3) + strlen($7) + 40);
		sprintf($$, "int %s = %s;", $3, $7);  // Générer le code C correspondant à la déclaration avec initialisation
		free($3); free($7);
	}
	| DECLARER INT IDENTIFIANT {
		ajouter_symbole($3, "int");
		$$ = malloc(strlen($3) + 20);
		sprintf($$, "int %s;", $3);  // Déclaration simple int sans initialisation
		free($3);
	}
	| DECLARER CHAINE IDENTIFIANT {
		ajouter_symbole($3, "chaine");
		$$ = malloc(strlen($3) + 40);
		sprintf($$, "char %s[256];", $3);  // Déclaration tableau de char (chaîne) de taille 256
		free($3);
	}
	| INT IDENTIFIANT '=' expression {
		ajouter_symbole($2, "int");
		$$ = malloc(strlen($2) + strlen($4) + 20);
		sprintf($$, "int %s = %s;", $2, $4);  // Déclaration et initialisation int
		free($2); free($4);
	}
	| IDENTIFIANT '=' expression {
		// Affectation à une variable déjà déclarée
		if (type_de_variable($1) == NULL) {
			fprintf(stderr, "Erreur: variable '%s' non déclarée\n", $1);
			$$ = strdup("// erreur variable non declaree");
		} else {
			$$ = malloc(strlen($1) + strlen($3) + 10);
			sprintf($$, "%s = %s;", $1, $3);  // Génère une affectation C classique
		}
		free($1); free($3);
	}
	| DEMANDER IDENTIFIANT CHAINE {
		// Lecture utilisateur, dépend du type de la variable
		const char *type = type_de_variable($2);
		if (type == NULL) {
			fprintf(stderr, "Erreur: variable '%s' non déclarée\n", $2);
			$$ = strdup("// erreur variable non declaree");
		}
		else if (strcmp(type, "int") == 0) {
			$$ = malloc(strlen($2) + strlen($3) + 80);
			sprintf($$, "printf(\"%s\\n\"); scanf(\"%%d\", &%s);", $3, $2);
		}
		else if (strcmp(type, "chaine") == 0) {
			$$ = malloc(strlen($2) + strlen($3) + 80);
			sprintf($$, "printf(\"%s\\n\"); scanf(\"%%255s\", %s);", $3, $2);
		}
		else {
			$$ = strdup("// type inconnu pour demander");
		}
		free($2); free($3);
	}
	| SI IDENTIFIANT OP ENTIER ALORS affichage {
		// Condition if simple (ex : si x > 5 alors afficher ...)
		char *corps_si = indent($6);
		int taille = snprintf(NULL, 0, "if (%s %s %s) {\n%s}", $2, $3, $4, corps_si);
		$$ = malloc(taille + 1);
		sprintf($$, "if (%s %s %s) {\n%s}", $2, $3, $4, corps_si);
		free(corps_si);
		free($2); free($3); free($4); free($6);
	}
	| SI IDENTIFIANT OP ENTIER ALORS affichage SINON affichage {
		// Condition if-else (ex : si x > 5 alors ... sinon ...)
		char *corps_si = indent($6);
		char *corps_sinon = indent($8);
		int taille = snprintf(NULL, 0, "if (%s %s %s) {\n%s} else {\n%s}", $2, $3, $4, corps_si, corps_sinon);
		$$ = malloc(taille + 1);
		sprintf($$, "if (%s %s %s) {\n%s} else {\n%s}", $2, $3, $4, corps_si, corps_sinon);
		free(corps_si); free(corps_sinon);
		free($2); free($3); free($4); free($6); free($8);
	}
	| POUR IDENTIFIANT '=' expression JUSQUA expression FAIRE bloc_instructions {
		// Boucle for (ex : pour i = 0 jusqu'à 10 faire { ... })
		char *corps_indente = indent($8);
		int taille = snprintf(NULL, 0, "for (int %s = %s; %s <= %s; %s++) {\n%s}", $2, $4, $2, $6, $2, corps_indente);
		$$ = malloc(taille + 1);
		sprintf($$, "for (int %s = %s; %s <= %s; %s++) {\n%s}", $2, $4, $2, $6, $2, corps_indente);
		free(corps_indente);
		free($2); free($4); free($6); free($8);
	}
	| TANTQUE IDENTIFIANT OP ENTIER FAIRE liste_et_instructions {
	    // Boucle while (tant que x faire ...)
	    char* corps = indent($6);
		sprintf($$, "while (%s %s %s) {\n%s}", $2, $3, $4, corps);
		free(corps);

	}

	;

// Bloc d’instructions : soit une seule instruction, soit un bloc entre accolades
bloc_instructions:
	instruction
	| '{' FINLIGNE liste_instructions FINLIGNE '}' {
		$$ = $3;  // On prend la liste d’instructions à l’intérieur du bloc
	}
	;

// Instruction d’affichage (print)
affichage:
	AFFICHER CHAINE {
		$$ = malloc(strlen($2) + 20);
		sprintf($$, "printf(\"%s\\n\");", $2); // Affiche une chaîne littérale
		free($2);
	}
	| AFFICHER expression {
		// Affichage d’une expression, selon son type (int ou chaine)
		const char *type = type_de_variable($2);
		if (type != NULL) {
			if (strcmp(type, "int") == 0) {
				$$ = malloc(strlen($2) + 40);
				sprintf($$, "printf(\"%%d\\n\", %s);", $2);
			} else if (strcmp(type, "chaine") == 0) {
				$$ = malloc(strlen($2) + 40);
				sprintf($$, "printf(\"%%s\\n\", %s);", $2);
			} else {
				$$ = strdup("// type inconnu pour afficher");
			}
		} else {
			// Si type inconnu, on suppose un int par défaut
			$$ = malloc(strlen($2) + 40);
			sprintf($$, "printf(\"%%d\\n\", %s);", $2);
		}
		free($2);
	}
	;

expression:
	ENTIER               { $$ = strdup($1); free($1); }
	// Si l'expression est un entier (token ENTIER), on copie la chaîne du token pour la stocker dans $$ (valeur retournée),
	// puis on libère la mémoire temporaire $1 (valeur du token).
	
	| IDENTIFIANT        { $$ = strdup($1); free($1); }
	// Si l'expression est un identifiant (variable), on fait de même : on duplique la chaîne du nom de la variable.

	| expression '+' expression {
		$$ = malloc(strlen($1) + strlen($3) + 6);
		// On alloue une chaîne assez grande pour contenir la concaténation : 
		// 2 parenthèses + opérateur + espaces + chaîne 1 + chaîne 3 + le '\0'.
		sprintf($$, "(%s + %s)", $1, $3);
		// On génère une chaîne correspondant à une addition en C, avec parenthèses pour la priorité.
		free($1); free($3);
		// On libère la mémoire des sous-expressions temporaires.
	}

	| expression '-' expression {
		$$ = malloc(strlen($1) + strlen($3) + 6);
		sprintf($$, "(%s - %s)", $1, $3);
		free($1); free($3);
	}
	// Même principe que pour '+', mais pour la soustraction.

	| expression '*' expression {
		$$ = malloc(strlen($1) + strlen($3) + 6);
		sprintf($$, "(%s * %s)", $1, $3);
		free($1); free($3);
	}
	// Multiplication avec mise entre parenthèses.

	| expression '/' expression {
		$$ = malloc(strlen($1) + strlen($3) + 6);
		sprintf($$, "(%s / %s)", $1, $3);
		free($1); free($3);
	}
	// Division, même principe.

	| expression '%' expression {
		$$ = malloc(strlen($1) + strlen($3) + 7); 
		// Ici 7 au lieu de 6 car il y a un caractère supplémentaire pour '%%' (le % en sprintf s'écrit '%%')
		sprintf($$, "(%s %% %s)", $1, $3);
		// Modulo en C, on doit échapper le % par %% dans sprintf.
		free($1); free($3);
	}

	| '(' expression ')' {
		$$ = malloc(strlen($2) + 3);
		// On alloue une chaîne pour les parenthèses + l'expression + '\0'
		sprintf($$, "(%s)", $2);
		// On entoure simplement l'expression par des parenthèses.
		free($2);
	}
	;

// Fin de la règle expression

commentaire:
	COMMENTAIRE { $$ = $1; }
	// Le commentaire est simplement transmis tel quel (on ne fait pas de copie),
	// $1 est la chaîne issue du token COMMENTAIRE.
;

%%

// Fonction principale (main) du programme
int main(void) {
	yydebug = 1;  // Active le mode debug de Bison, utile pour voir le déroulement du parseur
	out = fopen("output.c", "w");  // Ouvre le fichier "output.c" en écriture (création ou écrasement)
	if (!out) {
		perror("Erreur ouverture output.c");  // Affiche une erreur si le fichier ne peut être ouvert
		exit(1);  // Quitte le programme avec code erreur
	}
	fprintf(out, "#include <stdio.h>\nint main() {\n");
	// Écrit le début d'un programme C standard dans le fichier de sortie

	yyparse();  // Lance le parseur Bison (analyse syntaxique)

	fprintf(out, "return 0;\n}\n");  // Écrit la fin de la fonction main() dans le fichier

	fclose(out);  // Ferme le fichier de sortie
	return 0;     // Fin normale du programme
}

// Fonction d'erreur appelée par Bison en cas d'erreur de syntaxe
int yyerror(char *s) {
	fprintf(stderr, "Erreur: %s\n", s);  // Affiche le message d'erreur sur la sortie d'erreur standard
	return 0;
}


