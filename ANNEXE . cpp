#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), currentPlayer(1)
{
    // Initialisation du tableau 6x7
    board.resize(6, std::vector<int>(7, 0));
    gridLayout = new QGridLayout(this);
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    centralWidget->setLayout(gridLayout);

    // Création des jetons
    for (int col = 0; col < 7; ++col) {
        tokens.push_back(std::vector<Token*>(6, nullptr)); // Initialiser les jetons
        for (int row = 0; row < 6; ++row) {
            Token *token = new Token(col, this); // Créer un jeton vide avec la colonne
            tokens[col][row] = token; // Stocker le jeton
            gridLayout->addWidget(token, row, col);

            // Connecter le signal clicked à columnClicked
            connect(token, &Token::clicked, this, &MainWindow::columnClicked);
        }
    }

    // Titre de la fenêtre
    setWindowTitle("Puissance 4");
}

MainWindow::~MainWindow()
{
    // Libérer la mémoire
    for (auto &col : tokens) {
        for (auto &token : col) {
            delete token;
        }
    }
}

void MainWindow::columnClicked(int col)
{
    // Trouver la première ligne vide dans la colonne
    for (int row = 5; row >= 0; --row) {
        if (board[row][col] == 0) {
            board[row][col] = currentPlayer; // Mettre à jour le plateau
            updateToken(row, col); // Mettre à jour l'affichage du jeton
            checkWinner(); // Vérifier si le joueur a gagné
            currentPlayer = (currentPlayer == 1) ? 2 : 1; // Changer de joueur
            break;
        }
    }
}

void MainWindow::updateToken(int row, int col)
{
    tokens[col][row]->setPlayer(currentPlayer); // Mettre à jour le joueur du jeton
}

void MainWindow::checkWinner()
{
    // Vérifier les lignes, colonnes et diagonales
    // Vérification des lignes
    for (int row = 0; row < 6; ++row) {
        for (int col = 0; col < 4; ++col) {
            if (board[row][col] == currentPlayer &&
                board[row][col + 1] == currentPlayer &&
                board[row][col + 2] == currentPlayer &&
                board[row][col + 3] == currentPlayer) {
                QMessageBox::information(this, "Gagné!", QString("Le Joueur %1 a gagné!").arg(currentPlayer));
                resetGame();
                return;
            }
        }
    }

    // Vérification des colonnes
    for (int col = 0; col < 7; ++col) {
        for (int row = 0; row < 3; ++row) {
            if (board[row][col] == currentPlayer &&
                board[row + 1][col] == currentPlayer &&
                board[row + 2][col] == currentPlayer &&
                board[row + 3][col] == currentPlayer) {
                QMessageBox::information(this, "Gagné!", QString("Le Joueur %1 a gagné!").arg(currentPlayer));
                resetGame();
                return;
            }
        }
    }

    // Vérification des diagonales (de gauche à droite)
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 4; ++col) {
            if (board[row][col] == currentPlayer &&
                board[row + 1][col + 1] == currentPlayer &&
                board[row + 2][col + 2] == currentPlayer &&
                board[row + 3][col + 3] == currentPlayer) {
                QMessageBox::information(this, "Gagné!", QString("Le Joueur %1 a gagné!").arg(currentPlayer));
                resetGame();
                return;
            }
        }
    }

    // Vérification des diagonales (de droite à gauche)
    for (int row = 0; row < 3; ++row) {
        for (int col = 3; col < 7; ++col) {
            if (board[row][col] == currentPlayer &&
                board[row + 1][col - 1] == currentPlayer &&
                board[row + 2][col - 2] == currentPlayer &&
                board[row + 3][col - 3] == currentPlayer) {
                QMessageBox::information(this, "Gagné!", QString("Le Joueur %1 a gagné!").arg(currentPlayer));
                resetGame();
                return;
            }
        }
    }
}

void MainWindow::resetGame()
{
    // Réinitialiser le tableau
    board.assign(6, std::vector<int>(7, 0));
    currentPlayer = 1;

    // Réinitialiser les jetons
    for (auto &col : tokens) {
        for (auto &token : col) {
            token->setPlayer(0); // Réinitialiser chaque jeton à vide
        }
    }
}
