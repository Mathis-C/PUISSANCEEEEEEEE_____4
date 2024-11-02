#include "jeton_2p.h"




JETON_2P::JETON_2P(QWidget *parent) : QPushButton(parent), joueur(0) {
    setFixedSize(50, 50);
}

void JETON_2P::definirCouleur(int joueurId) {


    joueur = joueurId;
    if (joueur == 1) {
        setStyleSheet("background-color: red;");
    } else if (joueur == 2) {
        setStyleSheet("background-color: yellow;");
    } else {
        setStyleSheet("background-color: lightgray;");
    }
}
