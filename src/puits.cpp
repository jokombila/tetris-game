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
            if (m_Mat[i][j] == 1)
            {
                p->fillRect(coordonnes.x+j*15,  coordonnes.y+i*15, 15, 15, QBrush(Qt::green) );
            }
            else if (m_Mat[i][j] == 2)
            {
                p->fillRect(coordonnes.x+j*15,  coordonnes.y+i*15, 15, 15, QBrush(Qt::cyan) );
            }
            else if (m_Mat[i][j] == 3)
            {
                p->fillRect(coordonnes.x+j*15,  coordonnes.y+i*15, 15, 15, QBrush(Qt::red) );
            }
            else if (m_Mat[i][j] == 4)
            {
                p->fillRect(coordonnes.x+j*15,  coordonnes.y+i*15, 15, 15, QBrush(Qt::blue) );
            }
            else if (m_Mat[i][j] == 5)
            {
                p->fillRect(coordonnes.x+j*15,  coordonnes.y+i*15, 15, 15, QBrush(QColorConstants::Svg::coral) );

            }
            else if (m_Mat[i][j] == 6)
            {
                p->fillRect(coordonnes.x+j*15,  coordonnes.y+i*15, 15, 15, QBrush(Qt::magenta) );
            }
            else if (m_Mat[i][j] == 7)
            {
                p->fillRect(coordonnes.x+j*15,  coordonnes.y+i*15, 15, 15, QBrush(Qt::gray) );
            }
            else if (m_Mat[i][j] == 0)
            {
                p->fillRect(coordonnes.x+j*15,  coordonnes.y+i*15, 15, 15, QBrush(Qt::white) );
                //p->setPen(QPen(Qt::gray,1));
                //p->drawRect(coordonnes.x+j*15,  coordonnes.y+i*15, 15, 15);
            }

            /*if(m_Mat[i][j] != 0)
            {
                p->setPen(QPen(Qt::gray,1));
                p->drawRect(coordonnes.x+j*15,  coordonnes.y+i*15, 15, 15);
            }
            else{
                p->setPen(QPen(Qt::green,1));
                p->drawRect(coordonnes.x+j*15,  coordonnes.y+i*15, 15, 15);
            }
            */
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
        }
        cout << endl;
    }
    return Mat;
}

void Puits::setMat(int** MAT,int i,int j)
{

    for (int k=0;k<4;k++)
    {
        for(int l=0;l<4;l++)
        {
            if (MAT[k][l]!=0)
                m_Mat[k+i][l+j]=MAT[k][l];
        }
    }
}

int Puits::supplignepuit(int ligne)
{
    // à expliquer dans le rapport
    // aussi, faire un schema
    bool res=true;
    int i = ligne+3;
    int cpt = 0;
    int compteurligne=0;
    while (cpt < 4)
    {
        res=true;
        for(int j=4;j<14;j++)
        {
            if(m_Mat[i][j]<=0)
            {
                res=false;
            }
        }
        if (res==true)
        {
            compteurligne++;
            for (int k=i;k>=5;k--)
            {
                for(int j=4;j<14;j++)
                {
                    m_Mat[k][j]=m_Mat[k-1][j];
                }
            }
            for(int j=4;j<14;j++)
            {
                m_Mat[4][j]=0;
            }
        }
        else
        {
            i--;
        }
        cpt++;
    }
    return compteurligne;
}
