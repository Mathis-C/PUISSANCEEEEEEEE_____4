#ifndef PLAY_2P_H
#define PLAY_2P_H
#include "PLATEAU_2P.h"
#include <QMainWindow>
#include <QWidget>
#include <QComboBox>
#include <QPushButton>
#include <QLabel>

using namespace std;


class PLAY_2P : public QWidget   // déclaration de la class
{
    Q_OBJECT

public:

    explicit PLAY_2P(QWidget *parent = nullptr);  // Déclaration de notre Widget "Parent"
    
    // Fonction qui permet le lien entre les interfaces
    void INTERFACE_2P(); 


public slots:
    
    //Initialisation de nos fonctions, qui permettent la gestion et la mise en place du jeu
    void colonneCliquee(int col);   
    void Reinitialiser();

private:
    
    // Initialisation des widgets 'enfant'
    QLabel * TITRE;
    QPushButton * RESET;
    QPushButton * Quit1;
    QPushButton *boutonColonne;
    
    // Initialisation de notre class PLATEAU_2P
    PLATEAU_2P *PLATEAU;
    
    // Initialisation des variables et fonctions
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
