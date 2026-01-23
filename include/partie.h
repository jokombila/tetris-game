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
    Puits* m_pu;
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



};

#endif // PARTIE_H
