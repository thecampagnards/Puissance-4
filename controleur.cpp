#include <QDebug>
#include "controleur.h"
#include "plateau.h"
#include "mainwindow.h"

controleur::controleur(MainWindow* frame,int etatjoueur)
{
    m_frame=frame;
    m_plateau=new Plateau;
    m_etat=etatjoueur;
}

controleur::~controleur()
{
    delete m_plateau;
}

void controleur::ChangerEtat()
{
    qDebug()<<"controleur::ChangerEtat();";
    if (m_etat==1) m_etat=2;
    else m_etat=1;
    qDebug()<<"etat="<<m_etat;
}

void controleur::clique_gauche(int col)
{
    qDebug()<<"controleur::clique_gauche();";
    // on retrouve le super etat ici
    int nbgagne,ligne;
    //dans notre cas on peut faire cela car simple ici sinon utiliser un switch ou pattern etat
    ligne=m_plateau->PlacerJeton(m_etat,col);
    if (ligne!=-1) {
        m_frame->repaint(); // ici on informe la fenetre cf sequence
        // ici on retrouve la sortie du super etat
        if (m_plateau->PartieNulle()) m_frame->PartieNulle(); // diag etat
        else {
            nbgagne=m_plateau->JoueurGagne(col,ligne);
            if (nbgagne!=0) m_frame->PartieGagne(nbgagne);
            else ChangerEtat();  // on change d etat cf diag etat
        }
    }
}

Plateau* controleur::LirePlateau()
{
    return m_plateau;
}
