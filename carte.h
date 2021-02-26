#ifndef
#DEFINE

/*Définition du type carte*/

/* Une case contient [A COMPLETER] */
struct case;

typedef struct case case;

/* Une carte est un tableau de taille n*n dont les cases sont de type "case" */
struct carte;

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

/* requires un pointeur vers un entier positif représentant le nombre d'élèves FISE que le joueur possède
   assigns *fise
   ensures incrémente fise de 1 */
void recruterFISE(int *fise);

/* requires un pointeur vers un entier positif représentant le nombre d'élèves FISA que le joueur possède
   assigns *fisa
   ensures incrémente fisa de 1 */
void recruterFISA(int *fisa);

/* requires un pointeur *statut_fisa vers un entier valant 0 ou 1
   assigns *statut_fisa
   ensures incrémente */
void changerRessourcesFISA(int *statut_fisa);

/* requires rien
   assigns *tour
   ensures incrémente le numéro de tour de 1 */
void finDuTour();

#endif