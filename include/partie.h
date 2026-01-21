#ifndef PARTIE_H
#define PARTIE_H
#include "Tetromino.h"
#include "puits.h"

class Partie
{
protected:
    Tetromino* m_tetro;
    Puits* m_pu;
public:
    Partie();
    Partie(const Partie& P);
    ~Partie();
    Partie& operator=(const Partie& P);
    void collision();



};

#endif // PARTIE_H
