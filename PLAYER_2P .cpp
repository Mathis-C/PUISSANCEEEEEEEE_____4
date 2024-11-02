#include "PLAY_2P.h"
#include "PLATEAU_2P.h"
#include "qobjectdefs.h"
#include <QMainWindow>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>


PLAY_2P::PLAY_2P(QWidget *parent) : QWidget(parent),  PLATEAU(new PLATEAU_2P(this)), joueurActuel(1) {}


void PLAY_2P:: INTERFACE_2P(){

    setWindowTitle("Puissance 4");

    QVBoxLayout *mainLayout = new QVBoxLayout();
    setLayout(mainLayout);

    // Titre
    TITRE = new QLabel("POWER 4", this);
    QHBoxLayout *titreLayout = new QHBoxLayout();
    titreLayout->addStretch();
    titreLayout->addWidget(TITRE);
    titreLayout->addStretch();
    mainLayout->addLayout(titreLayout);

    // Boutons pour chaque colonne
    QHBoxLayout *colonneLayout = new QHBoxLayout();
    for (int col = 0; col < 7; ++col) {
        QPushButton *boutonColonne = new QPushButton(QString::number(col + 1));
        boutonColonne->setFixedSize(50, 50);
        connect(boutonColonne, &QPushButton::clicked, [this, col]() { colonneCliquee(col); });
        colonneLayout->addWidget(boutonColonne);
    }
    mainLayout->addLayout(colonneLayout);

    // Plateau
    mainLayout->addWidget(PLATEAU);

    // Boutons Reset et Quit
    RESET = new QPushButton("RESET", this);
    Quit1 = new QPushButton("QUIT", this);
    //connect(RESET, &QPushButton::clicked, this, &PLAY_2P::reinitialiser);
    connect(Quit1, &QPushButton::clicked, this, &PLAY_2P::close);

    QHBoxLayout *buttonLayout = new QHBoxLayout();
    buttonLayout->addWidget(RESET);
    buttonLayout->addWidget(Quit1);
    mainLayout->addLayout(buttonLayout);

}

void PLAY_2P::colonneCliquee(int col) {

    if (PLATEAU->ajouterJeton(col, joueurActuel)) {
        QMessageBox::information(this, "Victoire!", QString("Joueur %1 a gagné!").arg(joueurActuel));
        PLATEAU->reinitialiser();
    }
    changerJoueur();
}

void PLAY_2P::changerJoueur() {
    joueurActuel = (joueurActuel == 1) ? 2 : 1;
}







