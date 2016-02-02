#ifndef PLATEAU_INCLUDED
#define PLATEAU_INCLUDED

class Plateau {
  public:
    Plateau();
    bool PartieNulle();
    int JoueurGagne(int x,int y); //on regarde si 4 alignes en (x,y)
    int PlacerJeton(int nbjoueur,int col); // 1ere colonne 0-->7, renvoie -1 si erreur sinon la ligne
    int LireJeton(int x,int y); //y=0 ligne du bas !!
  private:
    bool Aligne4(int x, int y);
    int NbAligne(int x,int y,int dx,int dy);
    int m_tab[8][8];
    int m_nbcasevide;
};

#endif // PLATEAU_INCLUDED
