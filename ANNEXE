#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QGridLayout>
#include <QMessageBox>
#include <vector>
#include <QMouseEvent>

class Token : public QWidget
{
    Q_OBJECT

public:
    explicit Token(int col, QWidget *parent = nullptr)
        : QWidget(parent), player(0), column(col) {
        setFixedSize(70, 70);
        setAutoFillBackground(true);
        updateColor();
    }

    void updateColor() {
        QPalette palette = this->palette();
        if (player == 1) {
            palette.setColor(QPalette::Window, Qt::red);
        } else if (player == 2) {
            palette.setColor(QPalette::Window, Qt::yellow);
        } else {
            palette.setColor(QPalette::Window, Qt::blue);
        }
        setPalette(palette);
    }

    void setPlayer(int p) {
        player = p;
        updateColor();
    }

    int getPlayer() const { return player; }

signals:
    void clicked(int col); // Signal émis lors du clic sur le jeton

protected:
    void mousePressEvent(QMouseEvent *event) override {
        if (event->button() == Qt::LeftButton) {
            emit clicked(column); // Émettre le signal avec la colonne
        }
    }

private:
    int player; // 0 = vide, 1 = joueur 1, 2 = joueur 2
    int column; // La colonne à laquelle ce jeton appartient
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void columnClicked(int col);

private:
    std::vector<std::vector<int>> board; // 0 = vide, 1 = joueur 1, 2 = joueur 2
    int currentPlayer;
    QGridLayout *gridLayout;
    std::vector<std::vector<Token*>> tokens; // Matrice de jetons

    void checkWinner();
    void resetGame();
    void updateToken(int row, int col);
};

#endif // MAINWINDOW_H
