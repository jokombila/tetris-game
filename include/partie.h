#ifndef PARTIE_H
#define PARTIE_H
#include "Tetromino.h"
#include "puits.h"
#include "t.h"
#include <QPainter>

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


};

#endif // PARTIE_H
