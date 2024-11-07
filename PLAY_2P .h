#ifndef PLAY_2P_H
#define PLAY_2P_H
#include "PLATEAU_2P.h"
#include <QMainWindow>
#include <QWidget>
#include <QComboBox>
#include <QPushButton>
#include <QLabel>

using namespace std;


class PLAY_2P : public QWidget
{
    Q_OBJECT

public:

    explicit PLAY_2P(QWidget *parent = nullptr);

    void INTERFACE_2P();


public slots:

    void colonneCliquee(int col);
    void Reinitialiser();

private:


    QLabel * TITRE;
    QPushButton * RESET;
    QPushButton * Quit1;
    QPushButton *boutonColonne;
    PLATEAU_2P *PLATEAU;
    int joueurActuel =1;
    int changerJoueur();
    string CouleurJ();
    string CP;

    // Initialisations des variables pour compter les nombres de jetons gagant
    int i =0;
    int j=0;
    int k=0;
};

#endif // PLAY_2P_H
