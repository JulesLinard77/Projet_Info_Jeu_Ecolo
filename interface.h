int DemandeTailleTbaleau(void);
void AfficheCarte(carte Carte);
int ActionJoueur(void);                 /* prend comme valeur 1 pour passer au tour suivant, 2 pour ajouter une machine, 3 pour quitter.*/
int* NouvelleMachine(carte Carte, int E, int DD int* Personnel);     /* liste d'int de taille 3 (abscisse x, ordonéee y et machine à implémenter) 0 pour le collecteur de ressources ou de déchets, 1 pour le tapis roulant, 2 pour pour la Croix, 3 pour la Déchetterie, 4 pour le Centre de recyclage ex: Déchetterie en (x=17,y=11) alors liste=[16,10,3], message d'erreur si pas assez de ressource, ou s'il y a deja une machine, ou si les coordonnées dépasse la taille de la carte. La liste d'int Personnel de longueur 24 permet de savoir si il y a des reductions ex: j'ai 1 Brunel et 3 Faye alors Personnel=[0,0,0,0,0,0,0,0,1,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0] */
int* ChangerMachine(carte Carte, int E, int DD, int* Personnel);       /* liste d'int de taille 3 (abscisse x, ordonéee y et chose à lui faire) 0 pour détruire, 1 pour l'améliorer ex: Destruction de la machine en (x=18,y=8) alors liste=[17,7,0], afficher message d'erreur si l'on veut améliorer une machine non améliorable ou s'il n'y a pas de machine aux coordonnées rentrées. La liste d'int Personnel permet de savoir si il y a des reductions */
int DemandePersonnel(int E, int DD);                    /* demande et renvoie le numéro correpondant au prof si les ressources le permettent, message d'erreur sinon. ex: avec 100 E et 100 DD si je veux faye et je tape 13 message d'erreur et on recommence à ActionJoueur, mais si je rentre 5 Pour Merabet alors izok et ca renvoie 5 (ou 4 pour faciliter les listes)*/



/* int DemandeTailleTableau(){
    int taille_tableau;
    printf("Quelle taille de tabelau désirez-vous?");
    scanf("%d",&taille_tableau);
    return(taille_tableau);


    int ActionJoueur(){
       int n_action;
       printf("Que voulez-vous faire? Entrez 1 pour passer au tour suivant, 2 pour ajouter une machine, 3 pour quitter.");
       scanf("%d",&n_action);
       return(n_action);
    }
} */

