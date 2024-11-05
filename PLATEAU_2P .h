#ifndef PLATEAU_2P_H
#define PLATEAU_2P_H

#include <QWidget>
#include <QGridLayout>
#include "jeton_2p.h"

using namespace std;

class PLATEAU_2P : public QWidget {

    Q_OBJECT

public:

    explicit PLATEAU_2P(QWidget *parent = nullptr);
    bool ajouterJeton(int col, int joueur);
    bool verifierVictoire(int joueur);
    void reinitialiser();


private:

    vector<vector<JETON_2P*>> grille;
    QGridLayout *layoutGrille;   // Met les Laytout en grille
    JETON_2P *JETON;
};

#endif // PLATEAU_2P_H
