#include "jeton_2p.h"



JETON_2P::JETON_2P(QWidget *parent) : QPushButton(parent), joueur(0)  {
    setStyleSheet("background-color: darkblue;");
    setFixedSize(45, 45);  // Definition de la taille du jeton
}

void JETON_2P::definirCouleur(int joueurId) {   // Fonction pour définir la couleur du jeton


    joueur = joueurId;

    if (joueur == 1) {  // Condition pour vérifier s'il s'agit du joueur 1

        setStyleSheet("background-color: red;");   // attribuer une couleur au jeton pour le joueur 1

    } else if (joueur == 2) {   // Condition pour vérifier s'il s'agit du joeur 2

        setStyleSheet("background-color: yellow;"); // attribuer une couleur au jeton pour le joueur 2

    }else if (joueur == 3) { // Condition pour vérifier s'il s'agit du joueur 3

        setStyleSheet("background-color: green;");  // attribuer une couleur au jeton pour le joueur 3

    } else {   // Condition si aucun des joueurs a remplit la case

        setStyleSheet("background-color: darkblue;"); // attribuer une couleur à la case vide du plateau (aucun joueur)
    }
}


int JETON_2P:: getJoueur() const{   // Fonction pour relever le joueur actif
    return joueur;
}
