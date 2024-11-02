#include "PLATEAU_2P.h"
#include <QMessageBox>

using namespace std;


PLATEAU_2P::PLATEAU_2P(QWidget *parent)
    : QWidget(parent), layoutGrille(new QGridLayout(this)){

    setLayout(layoutGrille);    // Ajout du Layout en grille
    grille.resize(6, vector<JETON_2P*>(7, nullptr));   // Redimensionnement des jetons à la taille de la grille

    // Initialisation de la grille
    for (int row = 0; row < 6; ++row) {   // On parcours les lignes de la grille de 0 à 5 (6 lignes au total)
        for (int col = 0; col < 7; ++col) {  // On parcours les colonnes de 0 à 6 (7 colonnes au total)
            JETON = new JETON_2P(this);  // Création d'un Widget "JETON" qui provirnt de la classe "JETON_2P"
            grille[row][col] = JETON;   // Remplissage de tt les jetons dans la grilles
            layoutGrille->addWidget(JETON, row, col); // Ajout des WIDGETS dans la grille
        }
    }
}

bool PLATEAU_2P::ajouterJeton(int col, int joueur) { //Fontion pour ajouter un jeton en tant que joueur
    for (int row = 5; row >= 0; --row) {  // Boucle for pour tourner sur les différentes lignes de la colonne choisit
        if (grille[row][col]->getJoueur() == 0) {  // Condition if pour voir si les lignes sont vides
                                                   // Verification en partant du bas de la grille
                                                   // On remonte la colonne jusqu'à une case vide
                                                   //  pour pouvoir ajouter un jeton de couleur

            grille[row][col]->definirCouleur(joueur);  // Ajout de la couleur du jeton dans la première case vide en partant du bas
                                                       // en fonction du joueur actif
            return verifierVictoire(joueur);           // Après ajout du jeton, on verifit si le joueur actif a gagné
        }
    }
    return false;   // return flase si le joueur n'a pas encore gagné -> le jeu continu
}

bool PLATEAU_2P::verifierVictoire(int joueur) {

    // Vérification des lignes
    for (int row = 0; row < 6; ++row) {     // boucle for pour tourner sur toutes les lignes de la grille
        for (int col = 0; col < 4; ++col) {  // boucle  for pour tourner sur les 4 premières colonnes (4+3 =7)
            if (grille[row][col]->getJoueur() == joueur &&             // Condition if pour vérifier
                grille[row][col + 1]->getJoueur() == joueur &&         // Si les 4 jetons d'une même ligne
                grille[row][col + 2]->getJoueur() == joueur &&         // appartiennent au même joueur
                grille[row][col + 3]->getJoueur() == joueur) {         // 4 conditions doit être vérifiées (car PUISSANCE 4)
                return true;   // Return true pour VICTOIRE
            }
        }
    }

    // Vérification des colonnes
    for (int col = 0; col < 7; ++col) {            // boucle for pour tourner sur toutes les colonnes de la grille
        for (int row = 0; row < 3; ++row) {           // boucle  for pour tourner sur les 3 premières lignes (3+3 =6)
            if (grille[row][col]->getJoueur() == joueur &&                  //condition if qui suit le même principe
                grille[row + 1][col]->getJoueur() == joueur &&              // que la vérification des lignes
                grille[row + 2][col]->getJoueur() == joueur &&
                grille[row + 3][col]->getJoueur() == joueur) {
                return true;    // Return true pour VICTOIRE
            }
        }
    }

    // Vérification des diagonales
    for (int row = 0; row < 3; ++row) {      // boucle  for pour tourner sur les 3 premières lignes (3+3 =6)
        for (int col = 0; col < 4; ++col) {  // boucle  for pour tourner sur les 4 premières colonnes (4+3 =7)
            if (grille[row][col]->getJoueur() == joueur &&              //condition if qui suit le même principe
                grille[row + 1][col + 1]->getJoueur() == joueur &&       // que la vérification des lignes et colonnes
                grille[row + 2][col + 2]->getJoueur() == joueur &&
                grille[row + 3][col + 3]->getJoueur() == joueur) {
                return true;  // Return true pour VICTOIRE
            }
            if (grille[row][col + 3]->getJoueur() == joueur &&            //condition if qui suit le même principe
                grille[row + 1][col + 2]->getJoueur() == joueur &&        // que la vérification des lignes et colonnes
                grille[row + 2][col + 1]->getJoueur() == joueur &&
                grille[row + 3][col]->getJoueur() == joueur) {
                return true;   // Return true pour VICTOIRE
            }
        }
    }



    return false; // Return flase si le joueur n'a pas encore gagné -> le jeu continu
}

void PLATEAU_2P::reinitialiser() {  // Fonction pour réinitialiser le jeu
    for (int i = 0; i < grille.size(); ++i) {     // 2 boucles for pour tourner sur les deux dimensions du vector grille
        for (int j = 0; j < grille[i].size(); ++j) {    // Vector grille qui stock tt les jetons
            grille[i][j]->definirCouleur(0);   // On colore tt les jetons en Gris (comme appartenant à aucun joueur)
        }
    }
}

