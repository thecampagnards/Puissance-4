#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets/QMainWindow>
#include "controleur.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void Joueur1();
    void Joueur2();

public:
    void mousePressEvent(QMouseEvent *);
    void close();
    void OnAbout();
    void PartieNulle();
    void PartieGagne(int joueur);
    void FinPartie();
    void paintEvent(QPaintEvent *);
    void Joueur(int numero); //joueur numero commence

private:
    controleur *m_controleur;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
