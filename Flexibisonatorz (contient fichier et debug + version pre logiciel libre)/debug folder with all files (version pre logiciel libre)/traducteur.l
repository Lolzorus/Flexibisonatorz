%{
#include "traducteur.tab.h"  // Inclusion du fichier d'en-tête généré par Bison contenant les définitions de tokens
#include <string.h>      // Pour utiliser strdup et strlen
#include <stdlib.h>      // Pour malloc, free, etc.
%}

%%

"afficher"                { return AFFICHER; }  // Mot-clé pour afficher quelque chose
"si"                      { return SI; }        // Mot-clé pour la condition "si"
"alors"                   { return ALORS; }     // Mot-clé pour "alors" dans une condition
"int"                     { return INT; }       // Mot-clé pour le type entier
"sinon"                   { return SINON; }     // Mot-clé pour la clause "sinon"
"declarer"                { return DECLARER; }  // Mot-clé pour déclarer une variable
"comme"                   { return COMME; }     // Mot-clé pour "comme" (type)
"demander"                { return DEMANDER; }  // Mot-clé pour demander une saisie
"chaine"                  { return CHAINE; }    // Mot-clé pour le type chaîne de caractères
"pour"                    { return POUR; }      // Mot-clé pour la boucle "pour"
"jusqua"                  { return JUSQUA; }    // Mot-clé pour borne supérieure de boucle
"faire"                   { return FAIRE; }     // Mot-clé "faire" (dans les boucles)
"tant que"                { return TANTQUE; }   // Mot-clé pour la boucle "tant que"
"et"                      { return ET; }        // Mot-clé "et" pour enchaîner des instructions ou conditions


">="|"<="|"=="|"!="|">"|"<" { // Opérateurs relationnels reconnus comme un token OP, la valeur yylval est la chaîne correspondante
	yylval = strdup(yytext); // Duplique la chaîne de l'opérateur pour la passer au parser
	return OP; // Retourne le token OP
}

\"[^\"\n]*\"             { // Reconnaissance des chaînes de caractères entre guillemets
	char *tmp = strdup(yytext + 1);  // Duplique la chaîne sans le premier guillemet
	tmp[strlen(tmp) - 1] = '\0';     // Supprime le dernier guillemet en remplaçant par '\0'
	yylval = tmp;                    // Stocke la chaîne dans yylval
	return CHAINE;                   // Retourne le token CHAINE
}

"#"[^\n]*                { // Gestion des commentaires débutant par #
	yylval = strdup(yytext + 1);  // Duplique le commentaire sans le #
	return COMMENTAIRE;           // Retourne le token COMMENTAIRE
}

[0-9]+                   { yylval = strdup(yytext); return ENTIER; } // Reconnaissance des entiers

[a-zA-Z_][a-zA-Z0-9_]*   { yylval = strdup(yytext); return IDENTIFIANT; } // Reconnaissance des identifiants : lettre ou _ suivi de lettres, chiffres ou _



"="                      { return '='; } // Opérateurs arithmétiques retournés tels quels, en utilisant leur code ASCII
"+"                      { return '+'; }
"-"                      { return '-'; }
"*"                      { return '*'; }
"/"                      { return '/'; }
"%"                      { return '%'; }

[\n]+                    { return FINLIGNE; } // Fin de ligne détectée par un ou plusieurs caractères de saut de ligne

[ \t\r]+                 { /* ignorer les espaces */ }

.                        { return *yytext; } // Tous les autres caractères retournés tels quels (caractères ponctuation, etc.)

%%

int yywrap(void) { return 1; } // Fin de fichier : indique que le scan est terminé

