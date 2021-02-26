
#include "machine.h"
#include "carte.h"
#include "personnel.h"
#include "interface.h"

#define false 0
#define true 1


int main() {
    int ressources;
    int e = 100;
    int dd = 20;
    int fise = 5;
    int fisa = 5;
    int status_fisa = 0;
    int taille_plateau;
    int nreak_jeu = false;
    int break_tour = false;
    int recruter = false;
    int action;
    /*
        Le type d'action que veut réaliser le joueur:
            0: recruter des élèves
            1: construire/améliorer/détruire une machine
            2: utiliser un personnel de l'école
            3: terminer le tour
            4: quitter le jeu
     */
    int numero_tour = 0;
    carte carte;

    taille_plateau = demanderTaille();
    creerCarte(taille_plateau);

    while(ressources < 10000) {
        while(!break_tour) {
            afficherCarte();
            switch (demanderAction()) {
                case 0 :
                    int recruter = true;
                    break;
                case 1 :
                    action = 0;
                    break;
                case 2:
                    action = 1;
                    break;
                case 3 :
                    break_tour = true;
                    break;
                case 4:
                    break_jeu = true;
                    findutour(&numero_tour);
                    break;
            }

            if(recruter) {
            }





            if (break_jeu) {
                break;
            }

        }
        if(break_jeu) {
            break;
        }










    libererCarte(carte);
    return 0;
}