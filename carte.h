#ifndef

/*Définition du type carte*/

struct carte;

typedef struct carte carte;

struct case;

typedef struct case case;

/* Fonctions de l'interface carte.h */

/* requires un entier n valant 10, 20 ou 30
   assigns rien
   ensures une carte de taille n*n si n est valide, rien sinon */
carte creer_carte(int n);

/* requires un pointeur vers une carte valide (non nulle)
   assigns *map
   ensures libère la mémoire associé à *map */
void liberer_carte(carte *map);

/* requires un pointeur vers un entier positif représentant le nombre d'élèves FISE que le joueur possède
   assigns *fise
   ensures incrémente fise de 1 */
void recruter_FISE(int *fise);

/* requires un pointeur vers un entier positif représentant le nombre d'élèves FISA que le joueur possède
   assigns *fisa
   ensures incrémente fisa de 1 */
void recruter_FISE(int *fisa);

/* requires un pointeur vers un FISA
   assigns fisa
   ensures incrémente */
void changer_ressources_FISA(/* mettre ici */);

/* requires un pointeur vers un entier positif représentant le nombre d'élèves FISE que le joueur possède
   assigns *fisa
   ensures change le type de ressources produites par le FISA */
void changer_ressources_FISA(/* mettre ici le truc pour les FISA */);

/* requires un pointeur vers un entier positif représentant le numéro du tour
   assigns *tour
   ensures incrémente le numéro de tour de 1 */
void fin_du_tour(int *tour);

#endif