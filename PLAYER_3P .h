#ifndef PLAY_3P_H
#define PLAY_3P_H
#include "plateau_3p.h"
#include <QMainWindow>
#include <QWidget>
#include <QComboBox>
#include <QPushButton>
#include <QLabel>

using namespace std;


class PLAY_3P : public QWidget   // déclaration de la class
{
    Q_OBJECT

public:

    explicit PLAY_3P(QWidget *parent = nullptr);  // Déclaration de notre Widget "Parent"
    
    // Fonction qui permet le lien entre les interfaces    
    void INTERFACE_3P();


public slots:
    
    //Initialisation de nos fonctions, qui permettent la gestion et la mise en place du jeu
    void colonneCliquee(int col);
    void Reinitialiser();

private:
    
    // Initialisation des widgets 'enfant'
    QLabel * TITRE;
    QPushButton * RESET;
    QPushButton * Quit1;
    QPushButton * boutonColonne;
    
    // Initialisation de notre class PLATEAU_3P    
    PLATEAU_3P * PLATEAU;
    
    // Initialisation des variables et fonctions    
    int joueurActuel = 1;
    int changerJoueur();
    string CouleurJ();
    string CP;

    // Initialisations des variables pour compter les nombres de jetons gagant
    int i =0;
    int j=0;
    int l =0;
    int k=0;

};


#endif // PLAY_3P_H
