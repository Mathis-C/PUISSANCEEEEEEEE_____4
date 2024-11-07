#ifndef PLATEAU_3P_H
#define PLATEAU_3P_H

#include <QWidget>
#include <QGridLayout>
#include "jeton_2p.h"

using namespace std;

class PLATEAU_3P : public QWidget { // déclaration de la class

    Q_OBJECT

public:

    explicit PLATEAU_3P(QWidget *parent = nullptr);  // Déclaration de notre Widget "Parent"

    //Initialisation de nos fonctions, qui permettent la gestion et la mise en place du jeu
    bool ajouterJeton(int col, int joueur);
    bool verifierVictoire(int joueur);
    void reinitialiser();

private:

    //Initialisation d'un vector à deux dimensions qui contient les jetons, définit avec la classe JETON_2P
    vector<vector<JETON_2P*>> grille;
    QGridLayout *layoutGrille;  // Met les Laytout en grille
    JETON_2P *JETON; // Initialisation de notre class JETON

};

#endif // PLATEAU_3P_H
