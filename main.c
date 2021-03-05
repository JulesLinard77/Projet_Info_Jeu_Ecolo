
#include "machine.h"
#include "carte.h"
#include "personnel.h"
#include "interface.h"

#define false 0
#define true 1

int main() {
    int ressources = 0;
    int break_jeu = false;
    int break_tour = false;
    int numero_tour = 0;
    carte carte;
    int taille_plateau = DemandeTailleTbaleau();
    creerCarte(taille_plateau);



    int type_eleve = 1;
    int verif = 1;
    int x, y;
    int type_machine = 1;
    int nbr_eleves;
    int indice_personnel;

    while (ressources < 10000 || carte.DD <= 0) {

        while (!break_tour) {
            AfficheCarte(carte);
            /*
                Le type d'action que veut réaliser le joueur:
                    0: recruter des élèves
                    1: construire
                    2: améliorer/détruire une machine
                    3: utiliser un personnel de l'école
                    4: terminer le tour
                    5: quitter le jeu
             */
            switch (ActionJoueur()) {
                case 0 :
                    type_eleve = 1;
                    verif = 1;
                    while (verif != 0 || type_eleve != 0) {
                        type_eleve = Recruter(&nbr_eleves, verif);
                        if (type_eleve == 1) {
                            verif = recruterFISE(&carte, nbr_eleves);
                        }
                        if (type_eleve == 2) {
                            verif = recruterFISA(&carte, nbr_eleves);
                        }
                    }
                    break;
                case 1 :
                    type_machine = 1;
                    verif = 1;
                    while (verif != 0) {
                        type_machine = NouvelleMachine(&x, &y, verif);
                        verif = ajouterNouvelleMachine(&carte, x, y, type_machine);
                    }
                    break;
                case 2:
                    verif = 0;
                    type_machine = 1;
                    while (verif != 0) {
                        type_machine = NouvelleMachine(&x, &y, verif);
                        verif = ajouterNouvelleMachine(&carte, x, y, type_machine);
                    }
                    break;
                case 3 :
                    verif = 1;
                    while (verif != 0) {
                        indice_personnel = DemandePersonnel(verif);
                        verif = acheterMembrePersonnel(&carte, indice_personnel);
                    }
                    break;
                case 4:

                    break_tour = true;
                    break;

                case 5:
                    break_jeu = true;
                    break;
            }
            if (break_tour || break_jeu) {
                finDuTour(&carte, &numero_tour);
                break;
            }
        }
        if (break_jeu) {
            break;
        }
    }
    libererCarte(&carte);
    return 0;
}