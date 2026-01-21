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
    int Mat[30][18];

public:
    Puits(int h=30, int l=18);
    void dessiner(QPainter * p);
};

#endif // PUITS_H
