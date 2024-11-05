#ifndef MENU_PLAYER_H
#define MENU_PLAYER_H
#include "PLAY_2P.h"
#include "PLAY_3P.h"
#include <QMainWindow>
#include <QWidget>
#include <QComboBox>
#include <QPushButton>
#include <QLabel>

class MENU_PLAYER : public QWidget   // déclaration de la class
{
    Q_OBJECT


public:

    explicit MENU_PLAYER(QWidget *parent = nullptr);  // Déclaration de notre Widget "Parent"
    
    void start();  // Fonction définissant notre interface graphique
    
private slots :
// Déclaration de nos fonctions qui sont donc des slots pouvant être appelé par des signaux
    void PL_2P();
    void PL_3P();

private:
// Déclaration des Widgets "enfants"    

    QLabel * nbrJ;
    QPushButton * TwoP;
    QPushButton *ThreeP;
    QPushButton * Quit1;
    PLAY_2P *menu2P;  // Initialisation de la class PLAY_2P
    PLAY_3P *menu3P;  // Initialisation de la class PLAY_3P



};

#endif // MENU_PLAYER_H
