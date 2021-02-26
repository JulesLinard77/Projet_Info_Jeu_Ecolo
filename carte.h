#ifndef
#DEFINE

/*Définition du type carte*/

/* Identifiant des différents contenus des cases:
- 0 si la case est vide
- 1 si la case contient la porte transuniverselle
- 2 si la case produit des ressources
- 3 si la case contient un collecteur
- 4 si la case contient un tapis roulant
- 5 si la case contient une déchetterie
- 6 si la case contient un centre de recyclage */


/* Une case contient un entier représentant le contenu de la case (suivant les instructions ci dessus), et deux entiers positifs représentant les nombres de ressources et de déchets sur la case */
struct case {
   int contenu;
   int nb_ressources;
   int nb_dechets;
}

typedef struct case case;

/* Une carte est un tableau de taille n*n dont les cases sont de type "case" */
struct carte {
   case[][] carte;
}

typedef struct carte carte;

/* Fonctions de l'interface carte.h */

/* requires un entier n valant 10, 20 ou 30
   assigns rien
   ensures une carte de taille n*n si n est valide, rien sinon */
carte creerCarte(int n);

/* requires un pointeur vers une carte valide (non nulle)
   assigns *map
   ensures libère la mémoire associé à *map */
void libererCarte(carte *map);

/* requires un pointeur vers un entier positif représentant le nombre d'élèves FISE que le joueur possède, et un entier strictement positif représentant le nombre d'élève(s) à recruter
   assigns *fise
   ensures incrémente fise de 1 */
void recruterFISE(int *fise,  int nb_recrue);

/* requires un pointeur vers un entier positif représentant le nombre d'élèves FISA que le joueur possède, et un entier strictement positif représentant le nombre d'élève(s) à recruter
   assigns *fisa
   ensures incrémente fisa de 1 */
void recruterFISA(int *fisa, int nb_recrue);

/* requires un pointeur *statut_fisa vers un entier valant 0 ou 1
   assigns *statut_fisa
   ensures incrémente */
void changerRessourcesFISA(int *statut_fisa);

/* requires un pointeur vers la carte *map
   assigns *map, *tour
   ensures incrémente le numéro de tour de 1 */
void finDuTour(carte *map);

#endif