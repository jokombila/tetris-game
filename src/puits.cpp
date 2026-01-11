#include "puits.h"

Puits::Puits(int h, int l): ObjetGraphique({0,0},15)
{
    hauteur = h;
    largeur = l;

    for(int i=0; i<hauteur; i++)
    {
        for(int j =0; j<largeur;j++)
        {

            Mat[i][j] = 0;

        }
    }

}


void Puits::dessiner(QPainter* p)
{
    for(int i = 0; i < hauteur; i++)
    {
        for(int j = 0; j < largeur; j++)
        {
            if(Mat[i][j] != 0)
            {
                p->fillRect(coordonnes.x + j * 15,coordonnes.y + i * 15,15,15, QBrush(Qt::gray));
            }
        }
    }
}

