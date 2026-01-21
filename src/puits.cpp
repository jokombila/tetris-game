#include "puits.h"

Puits::Puits(int h, int l): ObjetGraphique({50,50},15)
{
    hauteur = h;
    largeur = l;

    for(int i=0; i<hauteur; i++)
    {
        for(int j =0; j<largeur;j++)
        {
            if((i>=4 && i<=25) && (j>=4 && j<=13)){
                Mat[i][j] = 0;
            }
            else{
                Mat[i][j] = -1;
            }

        }
    }

}


void Puits::dessiner(QPainter* p)
{

    for(int i = 0; i < hauteur; i++)
    {
        for(int j = 0; j < largeur; j++)
        {
            if(Mat[i][j] == 0)
            {
                p->setPen(QPen(Qt::gray,1));
                p->drawRect(coordonnes.x+j*15,  coordonnes.y+i*15, 15, 15);
            }
            /*
            else{
                p->setPen(QPen(Qt::green,1));
                p->drawRect(coordonnes.x+j*15,  coordonnes.y+i*15, 15, 15);
            }
            */
        }
    }


}

