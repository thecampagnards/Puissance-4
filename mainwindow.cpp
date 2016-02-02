#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qdebug.h"
#include "qpainter.h"
#include "qmessagebox.h"
#include "QMouseEvent"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_controleur=NULL;
    Joueur1();
    connect(ui->actionJoueur_1_commence,SIGNAL(triggered()),this,SLOT(Joueur1()));
    connect(ui->actionJoueur_2_commence,SIGNAL(triggered()),this,SLOT(Joueur2()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *evt)
{
    qDebug()<<"MainWindow::mousePressEvent();";
    int col;
    col=8*evt->x()/width();
    qDebug()<<"col="<<col;
    qDebug()<<(m_controleur!=NULL);
    if (m_controleur) m_controleur->clique_gauche(col);
}

void MainWindow::PartieNulle()
{

}

void MainWindow::paintEvent(QPaintEvent *)
{
    qDebug()<<"MainWindow::paintEvent();";
    QPainter painter(this);
    QColor couleur[3];
    int nbcoul;

    couleur[0]=painter.background().color();
    couleur[1]=QColor(255,0,0);
    couleur[2]=QColor(0,255,0);
    painter.setBrush(QBrush(QColor(255,255,255)));
    for(int i=0;i<=8;i++)
    {
      painter.drawLine(0,50*i,400,50*i);
      painter.drawLine(50*i,0,50*i,400);
    }
    for(int x=0;x<=7;x++)
      for(int y=0;y<=7;y++)
      {
          if (m_controleur) nbcoul=m_controleur->LirePlateau()->LireJeton(x,y);
          else nbcoul=0;
          painter.setBrush(couleur[nbcoul]);
          painter.drawEllipse(x*50,400-(y*50),50,50);
      }
}

void MainWindow::Joueur1()
{
    Joueur(1);
}

void MainWindow::Joueur2()
{
    Joueur(2);
}

void MainWindow::PartieGagne(int joueur)
{
    QString val;
    QMessageBox::about(this,"Fin de partie",val.sprintf("Joueur %d a gagne",joueur));
    FinPartie();
}

void MainWindow::FinPartie()
{
    if (m_controleur) delete m_controleur;
    m_controleur=NULL;
}
