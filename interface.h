#ifndef _INTERFACE_H
#DEFINE _INTERFACE_H

/* requires: rien
   assigns: rien
   ensures: affiche et deamnde au joueur la taille de la carte qu'il veut*/

int DemandeTailleTbaleau(void);




/* requires: Une carte valide
   assigns: rien
   ensures: affiche la carte au joueur */

void AfficheCarte(carte *map);





/* requires:  rien
   assigns: rien
   ensures: Prend comme valeur 1 pour passer au tour suivant, 2 pour ajouter une machine, 3 pour quitter.*/

int ActionJoueur(void);





/* requires:  un pointeur vers type_eleve, un pointeur evrs nombre_eleves, et un entier verif valides
   assigns: rien
   ensures: Renvoit 0 s'il veut retourner au menu, 1 si c'est un fise et 2 pour un fisa */

int Recruter(int* type_eleve, int* nombre_eleves, int verif);




/* requires:  2 pointeurs vers les coordonnées de la carte choisies pour créer une nouvelle machine
   assigns: rien
   ensures: Renvoit 0 s'il veut retourner au menu, sinon renvoit le numéro de la machine à ajouter, en fonction de la valeur de verif, renvoit le message d'erreur correpondant*/

int NouvelleMachine(int* x, int* y, int verif);                               /* Ancienne version: liste d'int de taille 3 (abscisse x, ordonéee y et machine à implémenter) 0 pour le collecteur de ressources ou de déchets, 1 pour le tapis roulant, 2 pour pour la Croix, 3 pour la Déchetterie, 4 pour le Centre de recyclage ex: Déchetterie en (x=17,y=11) alors liste=[16,10,3], message d'erreur si pas assez de ressource, ou s'il y a deja une machine, une porte ou si les coordonnées dépasse la taille de la carte. La liste d'int Personnel de longueur 24 permet de savoir si il y a des reductions ex: j'ai 1 Brunel et 3 Faye alors Personnel=[0,0,0,0,0,0,0,0,1,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0] */





/* requires:  rien
   assigns: rien
   ensures: Renvoit 0 pour revenir au menu, 1 pour améliorer et 2 pour détruire si possible à chaque fois, en fonction de la valeur de verif, renvoit le message d'erreur correpondant */

int ChangerMachine(int* x, int* y, int verif);                                 /* Ancienne version: liste d'int de taille 3 (abscisse x, ordonéee y et chose à lui faire) 0 pour détruire, 1 pour l'améliorer ex: Destruction de la machine en (x=18,y=8) alors liste=[17,7,0], afficher message d'erreur si l'on veut améliorer une machine non améliorable ou s'il n'y a pas de machine aux coordonnées rentrées. La liste d'int Personnel permet de savoir si il y a des reductions */




/* requires:  rien
   assigns: rien
   ensures: Renvoit 0 pour revenir au menu, sinon renvoit le numéro du personnel. En fonction de la valeur de verif, renvoit le message d'erreur correpondant*/

int DemandePersonnel(int verif);                                                 /*Ancienne version:  demande et renvoie le numéro correpondant au prof si les ressources le permettent, message d'erreur sinon. ex: avec 100 E et 100 DD si je veux faye et je tape 13 message d'erreur et on recommence à ActionJoueur, mais si je rentre 5 Pour Merabet alors izok et ca renvoie 5 (ou 4 pour faciliter les listes)*/

#endif

/* verif vaut: 0 s'il n'y a pas de problème
             : 1 s'il n'a pas assez de EE/ DD
             : 1 si les coordonnées rentrées sont en dehors de la carte
             : 2 s'il y a déjà une machine à l'enplacement choisi
             : 3 s'il y a une porte transdimensionnel à l'enplacement choisi
             : 4 si la machine n'est pas améliorable */





/* int DemandeTailleTableau(){
    int taille_tableau;
    printf("Quelle taille de tabelau désirez-vous? Choissez entre 10 (facile), 20 (moyenne), ou 30 (grand)");
    scanf("%d",&taille_tableau);
    return(taille_tableau);
    }


    int ActionJoueur(){
       int n_action;
       printf("Que voulez-vous faire? Entrez 1 pour passer au tour suivant, 2 pour ajouter une machine, 3 pour quitter.");
       scanf("%d",&n_action);
       return(n_action);
    }
} */

