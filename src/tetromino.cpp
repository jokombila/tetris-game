#include "Tetromino.h"
#include <iostream>
using namespace std;

Tetromino::Tetromino(point p,  point p2, int taille,string c, string t,int k):ObjetGraphique(p,taille) {
    couleur=c;
    type=t;
    position = k;
    coordonnesGrille = p2;
    for (int k=0;k<4;k++)
    {
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            {
                Mat[k][i][j]=0;
            }
        }
    }

}

string Tetromino :: GetCouleur()
{
    return couleur;
}

string Tetromino :: Gettype()
{
    return type;
}


void Tetromino::dessiner(QPainter * p) {
    int k=position;

    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if (Mat[k][i][j] == 1)
            {
                p->fillRect(coordonnes.x+j*15,  coordonnes.y+i*15, 15, 15, QBrush(Qt::green) );
            }
            else if (Mat[k][i][j] == 2)
            {
                p->fillRect(coordonnes.x+j*15,  coordonnes.y+i*15, 15, 15, QBrush(Qt::cyan) );
            }
            else if (Mat[k][i][j] == 3)
            {
                p->fillRect(coordonnes.x+j*15,  coordonnes.y+i*15, 15, 15, QBrush(Qt::red) );
            }
            else if (Mat[k][i][j] == 4)
            {
                p->fillRect(coordonnes.x+j*15,  coordonnes.y+i*15, 15, 15, QBrush(Qt::blue) );
            }
            else if (Mat[k][i][j] == 5)
            {
                p->fillRect(coordonnes.x+j*15,  coordonnes.y+i*15, 15, 15, QBrush(QColorConstants::Svg::coral) );

            }
            else if (Mat[k][i][j] == 6)
            {
                p->fillRect(coordonnes.x+j*15,  coordonnes.y+i*15, 15, 15, QBrush(Qt::magenta) );
            }
            else if (Mat[k][i][j] == 7)
            {
                p->fillRect(coordonnes.x+j*15,  coordonnes.y+i*15, 15, 15, QBrush(Qt::gray) );
            }
        }
    }
}



void Tetromino::deplacerDe(int dx, int dy) {
    coordonnes.x+=dx;
    coordonnes.y+=dy;
    coordonnesGrille.x+=dx/15;
    coordonnesGrille.y+=dy/15;
}

void Tetromino:: Pivoter()
{
    if (position ==0)
        position = 1;
    else if (position ==1)
        position = 2;
    else if (position ==2)
        position = 3;
    else if (position ==3)
        position = 0;
}


int** Tetromino::getmattetro(int i,int j)
{
    int** Mat_tetro=new int*[4];

    for (int k=0;k<4;k++)
    {
        Mat_tetro[k]=new int[4];
        for(int l=0;l<4;l++)
        {
            Mat_tetro[k][l]=Mat[position][k][l];
            cout << Mat_tetro[k][l] << " ";

        }
        cout << endl;
    }
    return Mat_tetro;
}


int Tetromino:: getI()
{
    return this->coordonnesGrille.y;
}

int Tetromino:: getJ()
{
    return this->coordonnesGrille.x;
}
