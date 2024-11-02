#include "PLATEAU_2P.h"
#include <QMessageBox>

PLATEAU_2P::PLATEAU_2P(QWidget *parent)
    : QWidget(parent), layoutGrille(new QGridLayout(this)){

    setLayout(layoutGrille);
    grille.resize(6, std::vector<JETON_2P*>(7, nullptr));

    // Initialisation de la grille
    for (int row = 0; row < 6; ++row) {
        for (int col = 0; col < 7; ++col) {
            JETON_2P *JETON = new JETON_2P(this);
            grille[row][col] = JETON;
            layoutGrille->addWidget(JETON, row, col);
        }
    }
}

bool PLATEAU_2P::ajouterJeton(int col, int joueur) {
    for (int row = 5; row >= 0; --row) {
        if (grille[row][col]->getJoueur() == 0) {
            grille[row][col]->definirCouleur(joueur);
            return verifierVictoire(joueur);
        }
    }
    return false;
}

bool PLATEAU_2P::verifierVictoire(int joueur) {
    // Vérification de victoire ici (même logique que le code précédent)
    // Vérification des lignes
    for (int row = 0; row < 6; ++row) {
        for (int col = 0; col < 4; ++col) {
            if (grille[row][col]->getJoueur() == joueur &&
                grille[row][col + 1]->getJoueur() == joueur &&
                grille[row][col + 2]->getJoueur() == joueur &&
                grille[row][col + 3]->getJoueur() == joueur) {
                return true;
            }
        }
    }

    // Vérification des colonnes
    for (int col = 0; col < 7; ++col) {
        for (int row = 0; row < 3; ++row) {
            if (grille[row][col]->getJoueur() == joueur &&
                grille[row + 1][col]->getJoueur() == joueur &&
                grille[row + 2][col]->getJoueur() == joueur &&
                grille[row + 3][col]->getJoueur() == joueur) {
                return true;
            }
        }
    }

    // Vérification des diagonales
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 4; ++col) {
            if (grille[row][col]->getJoueur() == joueur &&
                grille[row + 1][col + 1]->getJoueur() == joueur &&
                grille[row + 2][col + 2]->getJoueur() == joueur &&
                grille[row + 3][col + 3]->getJoueur() == joueur) {
                return true;
            }
            if (grille[row][col + 3]->getJoueur() == joueur &&
                grille[row + 1][col + 2]->getJoueur() == joueur &&
                grille[row + 2][col + 1]->getJoueur() == joueur &&
                grille[row + 3][col]->getJoueur() == joueur) {
                return true;
            }
        }
    }



    return false; // Faux par défaut pour simplification
}

void PLATEAU_2P::reinitialiser() {
    for (auto &ligne : grille) {
        for (auto &jeton : ligne) {
            jeton->definirCouleur(0);
        }
    }
}
