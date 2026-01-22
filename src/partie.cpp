#include "partie.h"
#include <iostream>

using namespace std;



Partie::Partie()
{
    m_tetro_courant = new T();
    m_tetro_suivant = new T();
    m_pu = new Puits();

}



Partie::Partie(const Partie& P)
{
    m_tetro_courant=P.m_tetro_courant;
    m_tetro_suivant=P.m_tetro_suivant;
    m_pu=P.m_pu;
}

Partie::~Partie()
{
    delete m_pu;
    delete m_tetro_courant;
    delete m_tetro_suivant;
}

Partie& Partie::operator=(const Partie& P)
{
    if (this!=&P)
    {
        m_tetro_courant=P.m_tetro_courant;
        m_tetro_suivant=P.m_tetro_suivant;
        m_pu=P.m_pu;
    }
    return *this;
}


void Partie::deletesousgrille(int*** SSG)
{
    for(int i=0;i<4;i++)
    {
        delete[] (*SSG)[i];
    }
    delete[] *SSG;
    *SSG=nullptr;
}

bool Partie::collision(int i,int j)
{
    bool collision=false;
    int **MatT = m_tetro_courant->getmattetro(i,j);
    int **MatP = m_pu->getmat(i,j);

    int k = 0;
    int l = 0;


    while (collision == false && k<4)
    {
        l=0;
        while (collision == false && l<4)
        {
            cout << "(" << k << "," << l << ") : " << MatP[k][l] << " " << MatT[k][l] << endl;
            if ((MatP[k][l]!=0 && MatT[k][l]!=0))
            {
                collision=true;
            }
            l++;
        }
        k++;
    }
    deletesousgrille(&MatT);
    deletesousgrille(&MatP);

    if (collision)
        cout << "collision" << endl;
    else
        cout << "pas collision" << endl;
    return collision;
}

bool Partie::Deplacement(int i,int j)
{
    bool res=false;
    m_tetro_courant->deplacerDe(i,j);
    res = collision(m_tetro_courant->getI(), m_tetro_courant->getJ());
    if (res==true)
    {
        m_tetro_courant->deplacerDe(-i,-j);
    }
    return res;
}

void Partie::dessiner(QPainter * p)
{
    m_pu->dessiner(p);
    m_tetro_courant->dessiner(p);
}



