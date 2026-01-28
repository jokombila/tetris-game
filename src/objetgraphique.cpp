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


void ObjetGraphique::setY(int decalage)
{
    coordonnes.y=decalage;
}

void ObjetGraphique::setX(int decalage)
{
    coordonnes.x=decalage;
}
