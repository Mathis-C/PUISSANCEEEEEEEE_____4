#ifndef JETON_2P_H
#define JETON_2P_H

#include <QPushButton>

class JETON_2P : public QPushButton {   // déclaration de la class
    Q_OBJECT

public:
    explicit JETON_2P(QWidget *parent = nullptr);  // Déclaration de notre Widget "Parent"

// Fonctions qui vont nous permettre de gérer les différents joueurs
    void definirCouleur(int joueur); 
    int getJoueur() const ; 

private:
    int joueur;
};

#endif

