#include "puits.h"
#include <iostream>
using namespace std;

Puits::Puits(int h, int l): ObjetGraphique({50,50},15)
{
    hauteur = h;
    largeur = l;

    for(int i=0; i<hauteur; i++)
    {
        for(int j =0; j<largeur;j++)
        {
            if((i>=4 && i<=25) && (j>=4 && j<=13)){
                m_Mat[i][j] = 0;
            }
            else{
                m_Mat[i][j] = -1;
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
            if(m_Mat[i][j] == 0)
            {
                p->setPen(QPen(Qt::gray,1));
                p->drawRect(coordonnes.x+j*15,  coordonnes.y+i*15, 15, 15);
            }

            else{
                p->setPen(QPen(Qt::green,1));
                p->drawRect(coordonnes.x+j*15,  coordonnes.y+i*15, 15, 15);
            }

        }
    }

}


int** Puits::getmat(int i,int j)
{
    int** Mat=new int*[4];

    for (int k=0;k<4;k++)
    {
        Mat[k]=new int[4];
        for(int l=0;l<4;l++)
        {
            Mat[k][l]=m_Mat[i+k][j+l];
            cout << Mat[k][l] << " ";
        }
        cout << endl;
    }
    return Mat;
}

void Puits::setMat(int*** MAT,int i,int j)
{

    for (int k=0;k<4;k++)
    {
        for(int l=0;l<4;l++)
        {
            m_Mat[k+i][l+j]=*MAT[k][l];
        }
    }
}
