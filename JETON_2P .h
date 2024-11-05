#ifndef JETON_2P_H
#define JETON_2P_H

#include <QPushButton>

class JETON_2P : public QPushButton {
    Q_OBJECT

public:
    explicit JETON_2P(QWidget *parent = nullptr);


    void definirCouleur(int joueur); // Change la couleur en fonction du joueur
    int getJoueur() const ;

private:
    int joueur;
};

#endif
