#include "plateau.h"

#ifndef CONTROLEUR_H_INCLUDED
#define CONTROLEUR_H_INCLUDED

class MainWindow;
class Plateau;

class controleur
{
    public:
        controleur(MainWindow* frame,int etatjoueur);
        ~controleur();
        void clique_gauche(int col);
        void ChangerEtat();
        Plateau* LirePlateau();
    private:
        MainWindow* m_frame;
        Plateau* m_plateau;
        int m_etat;
};

#endif // CONTROLEUR_H_INCLUDED
