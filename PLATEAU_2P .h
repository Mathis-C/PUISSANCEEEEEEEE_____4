#ifndef PLATEAU_2P_H
#define PLATEAU_2P_H

#include <QWidget>
#include <QGridLayout>
#include "jeton_2p.h"

class PLATEAU_2P : public QWidget {
    Q_OBJECT

public:
    explicit PLATEAU_2P(QWidget *parent = nullptr);
    bool ajouterJeton(int col, int joueur);
    bool verifierVictoire(int joueur);
    void reinitialiser();

signals:
    void victoire(int joueur);

private:
    std::vector<std::vector<JETON_2P*>> grille;
    QGridLayout *layoutGrille;
};

#endif // PLATEAU_2P_H
