#include "objetgraphique.h"

ObjetGraphique::ObjetGraphique(point p, int taille) {
    coordonnes.x = p.x;
    coordonnes.y = p.y;
    this->taille = taille;
}
