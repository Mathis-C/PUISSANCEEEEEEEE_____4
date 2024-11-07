#include "play_2p.h"
#include "PLATEAU_2P.h"
#include "qobjectdefs.h"
#include <QMainWindow>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>


PLAY_2P::PLAY_2P(QWidget *parent) : QWidget(parent),  PLATEAU(new PLATEAU_2P(this)) {

}

// Fontion qui permet le lien entre l'interface 'MENU_PLAYER'
void PLAY_2P:: INTERFACE_2P(){

    setWindowTitle("POWER 4");   // Titre de l'interface
    window()->setStyleSheet("background-color: black;"); // Couleur de fond noire

    QVBoxLayout *mainLayout = new QVBoxLayout();    // Création d'un Layout principal
    setLayout(mainLayout);                         // Dans lequel on va ajouter tous nos widgets et Layout secondaire

    TITRE = new QLabel("POWER 4", this);         // Création du widget TITRE sous forme de QLABEL
    TITRE->setStyleSheet("font-size: 80px; font-weight: bold; color: red;");

    QHBoxLayout *titreLayout = new QHBoxLayout();   // Création du Layout titre qu'on place au milieu
    titreLayout->addStretch();
    titreLayout->addWidget(TITRE);
    titreLayout->addStretch();
    mainLayout->addLayout(titreLayout);   // Ajout du Layout titre dans le layout principal

    // Boutons pour chaque colonne
    QHBoxLayout *colonneLayout = new QHBoxLayout();   // création d'un laytout horizontal pour ajouter nos 7 boutons
    for (int i = 0; i < 7; ++i) {      // Création de 7 boutons avec boucle for
        boutonColonne = new QPushButton(" TOKEN ");  //Création d'un widget bouton, qu'on va répéter 7 fois + Remplissage nbr colonne
        boutonColonne->setFixedSize(45, 45);   // Taille bouton
        boutonColonne->setStyleSheet("font-size: 10px; font-weight: bold;background-color: darkblue; color: white;");
        connect(boutonColonne, &QPushButton::clicked, [this, i]() { colonneCliquee(i); });// Association du bouton i à la colonne i
        colonneLayout->addWidget(boutonColonne);   // Ajout des 7 boutons en ligne
    }
    mainLayout->addLayout(colonneLayout);  // ajout du layout des 7 boutons au layout principal

    mainLayout->addWidget(PLATEAU);  // Ajout du plateau dans le layout princiapl

    // Boutons Reset et Quit
    RESET = new QPushButton("RESET", this);   // Création du bouton widget RESET
    RESET->setStyleSheet("font-size: 25px; font-weight: bold;background-color: darkblue; color: white;");

    Quit1 = new QPushButton("RETURN", this);    // Création du bouton widget QUIT
    Quit1->setStyleSheet("font-size: 25px; font-weight: bold;background-color: darkblue; color: white;");

    connect(RESET, SIGNAL(clicked()), this, SLOT (Reinitialiser()));  // Fonction qui permet d'assosier le bouton RESET à la fonction Reinitialiser()
    connect(Quit1, SIGNAL(clicked()), this, SLOT (close())); // fonction connect qui permet d'associer l'action de quitter au bouton QUIT


    QHBoxLayout *buttonLayout = new QHBoxLayout();  // Création du Layout Bouton en ligne
    buttonLayout->addWidget(RESET);
    buttonLayout->addWidget(Quit1);
    mainLayout->addLayout(buttonLayout);   // Ajout du layout bouton au layout principal

}



int PLAY_2P::changerJoueur() {  // Fonction pour changer de joueur actif

    if (joueurActuel == 1) {   // condition if pour changer de joueur si le joueur 1 est actif
        i++;             // Incrémentation pour obtenir le nbr total de jetons posés par le joueur 1
        joueurActuel = 2;   // le joueur 2 devient actif

    } else if (joueurActuel == 2) {   // condition if pour changer de joueur si le joueur 2 est actif
        j++;                  // Incrémentation pour obtenir le nbr total de jetons posés par le joueur 2
        joueurActuel = 1;   // le joueur 1 devient actif
    }

    if (i > j){   //Condition if pour annoncer le joueur 1 gagnant

        k=i ; // Si le joueur 1 est le dernier à jouer, k prend la valeur du nombre de jeton du joueur 1

    } else if (j == i ){     //Condition if pour annoncer le joueur 2 gagnant
 
        k=j+1 ;  // Si le joueur 2 est le dernier à jouer, k prend la valeur du nombre de jeton du joueur 2
    }

    return k;  // On retourne la valeur du nombres de jetons du gagnant
}

string PLAY_2P::CouleurJ(){

    if(joueurActuel==1){        // Condition if qui vérifie que le joueur 1 est actif
        CP = "RED";             // On associe la valeur de CP à RED si la condition est verifiée
    }else if(joueurActuel==2){  // Condition if qui vérifie que le joueur 2 est actif
        CP = "YELLOW";          // On associe la valeur de CP à YELLOW si la condition est verifiée
    }
    return CP;                  // On retourne la couleur du joueur actuel 
}

void PLAY_2P::colonneCliquee(int col) {    //

    if (PLATEAU->ajouterJeton(col, joueurActuel)) {  // Si la fonction bool return true (victoire) alors afficher le message
        // On ouvre une fenêtre de dialogue si la condition est vérifiée par le if
        // celle-ci indique quel joueur a gagné en utilisant un argument definissant le dernier joueur actif
        QString couleur = QString::fromStdString(CouleurJ()); // On initialise un Qstring pour renvoyer la couleur du gagnant dans la boite de dialogue
        QMessageBox::information(this, "WINNN !!!", QString("PLAYER IN %1 WON!").arg(couleur),QString("WITH %1 TOKENS").arg(k));
        Reinitialiser();

    }else{

    changerJoueur();  // On appelle cette fonction pour changer de joeur quand un joueur a cliqué sur un colonne pour jouer

    }
}

void PLAY_2P::Reinitialiser() {   //Fonction pour réinitialiser le jeu
    
    PLATEAU->reinitialiser();  // On appelle notre fonction de la classe PLATEAU
    // Réinitialisation des variables quand le jeu est relancé
    i=0;
    j=0;
    k=0;
    joueurActuel =1;

}

