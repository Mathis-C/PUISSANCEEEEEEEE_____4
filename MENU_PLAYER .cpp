#include "menu_player.h"
#include "PLAY_2P.h"
#include "PLAY_3P.h"
#include "qobjectdefs.h"
#include <QMainWindow>
#include <QWidget>
#include <QComboBox>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>

MENU_PLAYER::MENU_PLAYER(QWidget *parent) : QWidget(parent) {   // Déclaration de notre constructeur
}

void MENU_PLAYER:: start(){

    setWindowTitle("POWER 4");   // Titre de l'interface
    window()->setStyleSheet("background-color: black;"); // Couleur de fond noire
    window()->setMinimumSize(1000, 500);   // Taille de l'interface

    nbrJ = new QLabel (" SELECT NUMBERS OF PLAYERS ", this);    // Declaration du widget TITRE
    nbrJ->setStyleSheet("font-size: 60px; font-weight: bold; color: red;"); // Personnalisation du titre


    TwoP = new QPushButton ("2 PLAYERS" , this);   // Declaration du widget TwoP
    TwoP->setStyleSheet("font-size: 25px; font-weight: bold;background-color: darkblue; color: white;");  // Personnalisation du bouton 2 PLAYERS

    ThreeP = new QPushButton (" 3 PLAYERS" , this);    // Declaration du widget ThreeP
    ThreeP->setStyleSheet("font-size: 25px; font-weight: bold;background-color: darkblue; color: white;");  // Personnalisation du bouton 3 PLAYERS

    Quit1 = new QPushButton ( " RETURN " , this);    // Declaration du widget Quit1
    Quit1->setStyleSheet("font-size: 25px; font-weight: bold;background-color: darkblue; color: white;"); // Personnalisation du bouton Quit1

    // Fonction connect qui permet de donner l'action de quitter l'interface quand le bouton est cliqué:
    connect(Quit1, SIGNAL(clicked()), this, SLOT(close()));

    //Fonction connect qui permet de lier la nouvelle interface PLAY_2P quand on appuie sur le bouton 2 PLAYERS:
    connect(TwoP, SIGNAL(clicked()), this, SLOT(PL_2P()));

    //Fonction connect qui permet de lier la nouvelle interface PLAY_3P quand on appuie sur le bouton 3 PLAYERS:
    connect(ThreeP, SIGNAL(clicked()), this, SLOT(PL_3P()));



    QHBoxLayout * titreP = new QHBoxLayout(); // Création du Layout titre qu'on place au milieu
    titreP->addStretch();
    titreP->addWidget(nbrJ);
    titreP->addStretch();

    QHBoxLayout * TWO_PLAYER = new QHBoxLayout(); // Création du Layout secondaires TWO_PLAYERS
    TWO_PLAYER -> addWidget(TwoP);  // On ajoute le bouton TwoP a ce Layout

    QHBoxLayout * THREE_PLAYER = new QHBoxLayout();   // Création du Layout secondaires THREE_PLAYERS
    THREE_PLAYER -> addWidget(ThreeP);   // On ajoute le bouton ThreeP a ce Layout

    QHBoxLayout * QUIT = new QHBoxLayout(); // Création du Layout secondaires QUIT
    QUIT -> addWidget(Quit1);   // On ajoute le bouton Qui1 a ce Layout

    QVBoxLayout * MENUP = new QVBoxLayout(this);  // Création d'un Layout principal

    MENUP -> addLayout(titreP);            // On ajout tous les layout secondaires
    MENUP -> addLayout(TWO_PLAYER);        // au Layout principal
    MENUP -> addLayout(THREE_PLAYER);
    MENUP -> addLayout(QUIT);

    setLayout(MENUP);  // On place le Layout principal dans notre interface

}

// Fonction play qui permet de faire le lien entre nos interfaces, pour afficher le PLAY_2P
void MENU_PLAYER:: PL_2P(){

    menu2P = new PLAY_2P;    // Délcaration de ma classe pour ensuite l'afficher
    menu2P -> show();
    menu2P -> INTERFACE_2P();

}

// Fonction play qui permet de faire le lien entre nos interfaces, pour afficher le PLAY_3P
void MENU_PLAYER:: PL_3P(){

    menu3P = new PLAY_3P;    // Délcaration de ma classe pour ensuite l'afficher
    menu3P -> show();
    menu3P -> INTERFACE_3P();

}
