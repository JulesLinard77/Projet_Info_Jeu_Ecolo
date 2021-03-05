
#include "machine.h"
#include "carte.h"
#include "personnel.h"
#include "interface.h"

#define false 0
#define true 1

int main() {
    int break_jeu = false;
    int break_tour = false;
    int numero_tour = 0;
    carte carte;
    int taille_plateau = DemandeTailleTbaleau();
    creerCarte(taille_plateau);

    while (ressources < 10000 || carte.dd <= 0) {

        while (!break_tour) {
            AfficheCarte();
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
                    int type_eleve = 1;
                    int verif = 1;
                    while (verif != 0 || type_eleve != 0) {
                        type_eleve = recruter(&nbr_eleves, verif);
                        if (type_eleve == 1) {
                            verif = recruterFISE($(carte.fise), nbr_eleves);
                        }
                        if (type_eleve == 2) {
                            verif = recruterFISA($(carte.fisa), nbr_eleves);
                        }
                    }
                    break;
                case 1 :
                    int x, y;
                    int type_machine = 1;
                    int verif = 1;
                    while (verif != 0) {
                        type_machine = NouvelleMachine(&x, &y, verif);
                        verif = ajouterNouvelleMachine(&carte, x, y, type_machine)
                    }
                    break;
                case 2:
                    int x, y;
                    int verif = 0;
                    int type_machine = 1;
                    while (verif != 0) {
                        type_machine = NouvelleMachine(&x, &y, verif);
                        verif = ajouterNouvelleMachine(&carte, x, y, type_machine, verif_utilisateur)
                    }
                    break;
                case 3 :
                    int verif = 1;
                    int indice_personnel;
                    while (verif != 0) {
                        indice_personnel = DemandePersonnel(verif);
                        verif = acheterMembrePersonnel(&carte, indice_personnel);
                    }
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
    libererCarte(carte);
    return 0;
}