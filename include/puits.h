#ifndef PUITS_H
#define PUITS_H
#include <QPainter>
#include "objetgraphique.h"

using namespace std;

class Puits : public ObjetGraphique
{
protected :
    int hauteur;
    int largeur;
    int Mat[22][10];

public:
    Puits(int h=22, int l=10);
    void dessiner(QPainter * p);
};

#endif // PUITS_H
