#ifndef POWER4_H
#define POWER4_H


#include "menu_player.h"
#include <QMainWindow>
#include <QWidget>
#include <QComboBox>
#include <QPushButton>
#include <QLabel>
#include <QDoubleValidator>

class POWER4 : public QMainWindow
{
    Q_OBJECT

public:
    explicit POWER4(QWidget *parent = nullptr);
    ~POWER4();

private slots: // Déclaration de nos fonctions qui sont donc des slots pouvant être appelé par des signaux

    void play();
    void help();

private:
         // Déclaration des Widgets "enfants"

    QLabel *TITRE;
    QPushButton *PLAY;
    QPushButton *HELP;
    QPushButton *QUIT;
    QLabel *DESIGN;
    MENU_PLAYER *menuPlayer;



};
#endif // POWER4_H
