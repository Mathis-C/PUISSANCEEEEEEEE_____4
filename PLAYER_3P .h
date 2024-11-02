#ifndef PLAY_3P_H
#define PLAY_3P_H
#include "plateau_3p.h"
#include <QMainWindow>
#include <QWidget>
#include <QComboBox>
#include <QPushButton>
#include <QLabel>

using namespace std;


class PLAY_3P : public QWidget
{
    Q_OBJECT

public:

    explicit PLAY_3P(QWidget *parent = nullptr);

    void INTERFACE_3P();


public slots:

    void colonneCliquee(int col);
    void Reinitialiser();

private:


    QLabel * TITRE;
    QPushButton * RESET;
    QPushButton * Quit1;
    QPushButton * boutonColonne;
    PLATEAU_3P * PLATEAU;
    int joueurActuel = 1;
    void changerJoueur();

};


#endif // PLAY_3P_H
