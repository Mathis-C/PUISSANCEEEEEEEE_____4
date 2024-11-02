#ifndef JETON_2P_H
#define JETON_2P_H

#include <QPushButton>

class JETON_2P : public QPushButton {
    Q_OBJECT

public:
    explicit JETON_2P(QWidget *parent = nullptr);


    void definirCouleur(int joueur); // Change la couleur en fonction du joueur
    int getJoueur() const { return joueur; }

private:
    int joueur; // 0 = vide, 1 = joueur 1, 2 = joueur 2
};

#endif
