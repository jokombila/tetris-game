#ifndef PARTIE_H
#define PARTIE_H
#include "Tetromino.h"
#include "puits.h"
#include "I.h"
#include "J.h"
#include "L.h"
#include "O.h"
#include "S.h"
#include "T.h"
#include "Z.h"
#include <QPainter>
#include <cstdlib>

class Partie
{
protected:
    Tetromino* m_tetro_courant;
    Tetromino* m_tetro_suivant;
    Tetromino* m_tetro_suivantCopy;
    Puits* m_pu;
    bool partie_termine;
    int m_score;
    bool m_etatTimer;
    int m_level;
public:
    Partie();
    Partie(const Partie& P);
    ~Partie();
    Partie& operator=(const Partie& P);
    bool collision(int i,int j);
    void deletesousgrille(int*** SSG);
    bool Deplacement(int i,int j);
    void dessiner(QPainter * p);
    bool Rotation();
    int fixerPuit();
    void SuppTetroCourant();
    void CreerTetroCourant();
    Tetromino* TirerTetro();
    void SuppLigne(int ligne);
    bool getFin();
    void setFin(bool fin);
    void setscore(int score);
    int getscore();
    void calculerScore(int N);
    bool getEtatTime();
    void setEtatTime(bool etat);
    void setlevel(int level);
    int getlevel();
    void IncrementeLevel();

};

#endif // PARTIE_H
