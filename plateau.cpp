#include <QDebug>
#include "plateau.h"

Plateau::Plateau()
{
    for(int i=0;i<8;i++)
        for(int j=0;j<8;j++)
            m_tab[i][j]=0;
    m_nbcasevide=64;
}

bool Plateau::Aligne4(int x,int y)
{
    int i;
    i=NbAligne(x,y,-1,0)+NbAligne(x,y,1,0)-1;
    if (i>=4) return true;
    i=NbAligne(x,y,-1,1)+NbAligne(x,y,1,-1)-1;
    if (i>=4) return true;
    i=NbAligne(x,y,0,1)+NbAligne(x,y,0,-1)-1;
    if (i>=4) return true;
    i=NbAligne(x,y,-1,-1)+NbAligne(x,y,1,1)-1;
    if (i>=4) return true;
    return false;
}

int Plateau::NbAligne(int x, int y, int dx, int dy)
{
    int i;
    i=1;
    while(LireJeton(x,y)==LireJeton(x+i*dx,y+i*dy))
      i++;
    return i;
}

bool Plateau::PartieNulle()
{
    return (m_nbcasevide==0);
}

int Plateau::PlacerJeton(int nbJoueur, int col)
{
    qDebug()<<"Plateau::PlacerJeton()";
    int y;
    y=0;
    while((y<=7)&&(LireJeton(col,y)!=0))
      y++;
    qDebug()<<"y="<<y;
    if (y>7) return (-1);
    m_tab[col][y]=nbJoueur;
    qDebug()<<"Joueur="<<nbJoueur<<" (Col,Ligne)=("<<col<<","<<y<<")";
    m_nbcasevide--;
    qDebug()<<"Nombre de cases vide : "<<m_nbcasevide;
    return(y);
}

int Plateau::LireJeton(int x,int y)
{
  if ((x<0)||(x>7)||(y<0)||(y>7)) return 3; // sortie de plateau
  else return m_tab[x][y];
}

int Plateau::JoueurGagne(int x,int y)
{
    if (Aligne4(x,y)) return LireJeton(x,y);
    return 0;
}

