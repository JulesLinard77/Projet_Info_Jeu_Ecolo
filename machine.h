#ifndef _MACHINE_H
#define _MACHINE_H

typedef struct machine {
    char nom;
    int niveau;
    int utilisation; // 1 = tapis roulant, 2 = croix, 3 = déchetterie, 4 = centre de recyclage
    char orientation; // G = Gauche, D = Droite, H = Haut, B = Bas
    int entree;
    int sortie;
    int cout_construction_e;
    int cout_construction_dd; 
    int cout_amelioration_e;
    int cout_amelioration_dd;
    int cout_destruction_e;
    int cout_destruction_dd;
} machine;





#endif