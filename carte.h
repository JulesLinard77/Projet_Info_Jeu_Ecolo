#ifndef _CARTE_H
#define _CARTE_H

#include <stdlib.h>
#include "machine.h"
#include "personnel.h"

/*Définition du type carte*/

/* Identifiant des différents contenus des cases:
- 0 si la case est vide
- 1 si la case contient la porte transuniverselle
- 2 si la case produit des ressources
- 3 si la case contient une machine*/


/* Une case contient un entier valant 1 si la porte si situe sur cette case, 0 sinon; un pointeur valant NULL si aucune machine n'est présente, une machine sinon ainsi que le nb de déchets et de ressources*/
struct carre {
   int porte;
   machine* machine;
   int nb_ressources;
   int nb_dechets;
};

typedef struct carre carre;

/* Une carte est un tableau de taille n*n dont les cases sont de type "case", deux entiers qui représentent les quantités DD et E, deux entiers représentant le nombre d'élèves FISE et FISA du joueur, et un tableau représentant le personnel et leur nombre */
struct carte {
   carre** carte;
   int DD;
   int E;
   int fise;
   int fisa;
   int production_fisa;
   int* personnels;
};

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

/* requires un pointeur vers la carte *map, un pointeur vers un entier positif représentant le nombre d'élèves FISE que le joueur possède, et un entier strictement positif représentant le nombre d'élève(s) à recruter
   assigns *fise
   ensures incrémente fise de 1, et renvoie 0 si c'est possible et 1 sinon */
int recruterFISE(carte *map,  int nb_recrue);

/* requires un pointeur vers la carte *map, un pointeur vers un entier positif représentant le nombre d'élèves FISA que le joueur possède, et un entier strictement positif représentant le nombre d'élève(s) à recruter
   assigns *fisa
   ensures incrémente fisa de 1, et renvoie 0 si c'est possible et 1 sinon */
int recruterFISA(carte *map, int nb_recrue);

/* requires un pointeur vers la carte *map
   assigns *map
   ensures change le type de ressources produits par les FISA */
void changerRessourcesFISA(carte *map);

/* requires un pointeur vers la carte *map, et un pointeur vers un entier *tour représentant le numéro de tour
   assigns *map, *tour
   ensures incrémente le numéro de tour de 1, et termine le tour suivant les règles définies dans la section 1.8 "Tour du jeu" du sujet */
void finDuTour(carte *map, int *tour);

/* requires un pointeur vers la carte map, l'abscisse et l'ordonée de la case où ajouter la machine, ainsi qu'un entier donnant l'utilisation de la machine
   assigns *map
   ensures ajoute une machine du type utilisation à la case (x,y) si on a le budget, et renvoie 0 si c'est possible et 1 sinon */
int ajouterNouvelleMachine(carte *map,int x_case, int y_case,int utilisation);


/* requires un pointeur vers la carte map, l'abscisse et l'ordonnée de la case où améliorer la machine
   assigns *map
   ensures améliore la machine se trouvant sur la case (x,y) si elle existe et qu'on a le budget, et renvoie 0 si c'est possible et 1 sinon */
int ameliorerMachine(carte *map,int x_case,int y_case);

/* requires un pointeur vers la carte map, l'abscisse et l'ordonnée de la case où améliorer la machine
   assigns *map
   ensures détruit la machine se trouvant sur la case (x,y) si elle existe et qu'on a le budget, et renvoie 0 si c'est possible et 1 sinon */
int detruireMachine(carte *map,int x_case,int y_case);

/* requires le numero du membre du personnel que l'on souhaite acheter
   assigns rien
   ensures ajouter un membre du personnel au joueur, et renvoie 0 si c'est possible et 1 sinon */
int acheterMembrePersonnel(carte *map, int numero);

#endif