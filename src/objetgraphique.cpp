#include "objetgraphique.h"

ObjetGraphique::ObjetGraphique(point p, int taille) {
    coordonnes.x = p.x;
    coordonnes.y = p.y;
    this->taille = taille;
}

int ObjetGraphique::getX()
{
    return coordonnes.x;
}

int ObjetGraphique::getY()
{
    return coordonnes.y;
}
