#include "menu_player.h"
#include "play_2p.h"
#include "play_3p.h"
#include "qobjectdefs.h"
#include <QMainWindow>
#include <QWidget>
#include <QComboBox>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>

MENU_PLAYER::MENU_PLAYER(QWidget *parent) : QWidget(parent) {
}

void MENU_PLAYER:: start(){

    setWindowTitle("POWER 4");   // Titre de l'interface
    window()->setStyleSheet("background-color: black;"); // Couleur de fond noire
    window()->setMinimumSize(1000, 500);

    nbrJ = new QLabel (" SELECT NUMBERS OF PLAYERS ", this);
    nbrJ->setStyleSheet("font-size: 60px; font-weight: bold; color: red;");

    TwoP = new QPushButton ("2 PLAYERS" , this);
    TwoP->setStyleSheet("font-size: 25px; font-weight: bold;background-color: darkblue; color: white;");

    ThreeP = new QPushButton (" 3 PLAYERS" , this);
    ThreeP->setStyleSheet("font-size: 25px; font-weight: bold;background-color: darkblue; color: white;");

    Quit1 = new QPushButton ( " RETURN " , this);
    Quit1->setStyleSheet("font-size: 25px; font-weight: bold;background-color: darkblue; color: white;");


    connect(Quit1, SIGNAL(clicked()), this, SLOT(close()));
    connect(TwoP, SIGNAL(clicked()), this, SLOT(PL_2P()));
    connect(ThreeP, SIGNAL(clicked()), this, SLOT(PL_3P()));



    QHBoxLayout * titreP = new QHBoxLayout();
    titreP->addStretch();
    titreP->addWidget(nbrJ);
    titreP->addStretch();

    QHBoxLayout * TWO_PLAYER = new QHBoxLayout();
    TWO_PLAYER -> addWidget(TwoP);

    QHBoxLayout * THREE_PLAYER = new QHBoxLayout();
    THREE_PLAYER -> addWidget(ThreeP);

    QHBoxLayout * QUIT = new QHBoxLayout();
    QUIT -> addWidget(Quit1);

    QVBoxLayout * MENUP = new QVBoxLayout(this);

    MENUP -> addLayout(titreP);
    MENUP -> addLayout(TWO_PLAYER);
    MENUP -> addLayout(THREE_PLAYER);
    MENUP -> addLayout(QUIT);

    setLayout(MENUP);

}

void MENU_PLAYER:: PL_2P(){

    menu2P = new PLAY_2P;
    menu2P -> show();
    menu2P -> INTERFACE_2P();

}

void MENU_PLAYER:: PL_3P(){

    menu3P = new PLAY_3P;
    menu3P -> show();
    menu3P -> INTERFACE_3P();

}

