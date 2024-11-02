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


PLAY_2P::PLAY_2P(QWidget *parent) : QWidget(parent),  PLATEAU(new PLATEAU_2P(this)) {}


void PLAY_2P:: INTERFACE_2P(){

    setWindowTitle("Puissance 4");   // Titre de l'interface

    QVBoxLayout *mainLayout = new QVBoxLayout();    // Création d'un Layout principal
    setLayout(mainLayout);                         // Dans lequel on va ajouter tous nos widgets et Layout secondaire

    TITRE = new QLabel("POWER 4", this);         // Création du widget TITRE sous forme de QLABEL
    QHBoxLayout *titreLayout = new QHBoxLayout();   // Création du Layout titre qu'on place au milieu
    titreLayout->addStretch();
    titreLayout->addWidget(TITRE);
    titreLayout->addStretch();
    mainLayout->addLayout(titreLayout);   // Ajout du Layout titre dans le layout principal

    // Boutons pour chaque colonne
    QHBoxLayout *colonneLayout = new QHBoxLayout();   // création d'un laytout horizontal pour ajouter nos 7 boutons
    for (int i = 0; i < 7; ++i) {      // Création de 7 boutons avec boucle for
        boutonColonne = new QPushButton(QString::number(i + 1));  //Création d'un widget bouton, qu'on va répéter 7 fois + Remplissage nbr colonne
        boutonColonne->setFixedSize(50, 50);   // Taille bouton
        connect(boutonColonne, SIGNAL(clicked()), this, SLOT ({colonneCliquee(i);}));  // Association du bouton i à la colonne i
        // Association du bouton i à la colonne i
        colonneLayout->addWidget(boutonColonne);   // Ajout des 7 boutons en ligne
    }
    mainLayout->addLayout(colonneLayout);  // ajout du layout des 7 boutons au layout principal

    mainLayout->addWidget(PLATEAU);  // Ajout du plateau dans le layout princiapl

    // Boutons Reset et Quit
    RESET = new QPushButton("RESET", this);   // Création du bouton widget RESET
    Quit1 = new QPushButton("QUIT", this);    // Création du bouton widget QUIT
    connect(RESET, SIGNAL(clicked()), this, SLOT (Reinitialiser()));  // Fonction qui permet d'assosier le bouton RESET à la fonction Reinitialiser()
    connect(Quit1, SIGNAL(clicked()), this, SLOT (close())); // fonction connect qui permet d'associer l'action de quitter
                                                             // au bouton QUIT

    QHBoxLayout *buttonLayout = new QHBoxLayout();  // Création du Layout Bouton en ligne
    buttonLayout->addWidget(RESET);
    buttonLayout->addWidget(Quit1);
    mainLayout->addLayout(buttonLayout);   // Ajout du layout bouton au layout principal

}

void PLAY_2P::colonneCliquee(int col) {    //

    if (PLATEAU->ajouterJeton(col, joueurActuel)) {  // Si la fonction bool return true (victoire) alors afficher le message
        // On ouvre une fenêtre de dialogue si la condition est vérifiée par le if
        // celle-ci indique quel joeur a gagné en utilisant un argument definissant le dernier joueur actif
        QMessageBox::information(this, "Victoire!", QString("Joueur %1 a gagné!").arg(joueurActuel));
        PLATEAU->reinitialiser();
    }
    changerJoueur();  // On appelle cette fonction pour changer de joeur quand un joueur a cliqué sur un colonne pour jouer
}

void PLAY_2P::changerJoueur() {  // Fonction pour changer de joueur actif

    if (joueurActuel == 1) {   // condition if pour changer de joueur si le joeur 1 est actif
        joueurActuel = 2;
    } else {
        joueurActuel = 1;   // Si le joeur 1 n'est pas actif, le joueur 1 devient actif
    }
}


void PLAY_2P::Reinitialiser() {   //Fonction pour réinitialiser le jeu
    PLATEAU->reinitialiser();
}






