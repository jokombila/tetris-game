#include "partie.h"
#include <iostream>

using namespace std;



Partie::Partie()
{
    srand((unsigned int)time(0));
    m_tetro_courant = TirerTetro();
    m_tetro_suivant = TirerTetro();
    m_tetro_suivantCopy=m_tetro_suivant->clone();
    m_pu = new Puits();
    partie_termine = false;
    m_score=0;
    m_etatTimer=false;
    m_level=0;

}



Partie::Partie(const Partie& P)
{
    m_tetro_courant=P.m_tetro_courant;
    m_tetro_suivant=P.m_tetro_suivant;
    m_pu=P.m_pu;
    m_score=P.m_score;
    m_etatTimer=P.m_etatTimer;
    m_level=P.m_level;
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
        m_score=P.m_score;
        m_etatTimer=P.m_etatTimer;
        m_level=P.m_level;
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
            //cout << "(" << k << "," << l << ") : " << MatP[k][l] << " " << MatT[k][l] << endl;
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

    //if (collision)
        //cout << "collision" << endl;
   //else
        //cout << "pas collision" << endl;
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
bool Partie::Rotation()
{
    bool res=false;
    m_tetro_courant->Pivoter();
    res = collision(m_tetro_courant->getI(), m_tetro_courant->getJ());
    if (res==true)
    {
        m_tetro_courant->Pivoter();
        m_tetro_courant->Pivoter();
        m_tetro_courant->Pivoter();
    }
    return res;
}

void Partie::dessiner(QPainter * p)
{
    m_pu->dessiner(p);
    if(m_tetro_courant!=nullptr)
    {
        m_tetro_courant->dessiner(p);
        m_tetro_suivantCopy->dessiner(p);
        //m_tetro_suivant->dessiner(p);

    }

}

int Partie::fixerPuit()
{
    int i=m_tetro_courant->getI();
    int j=m_tetro_courant->getJ();
    int **MatT = m_tetro_courant->getmattetro(i,j);
    m_pu->setMat(MatT,i,j);
    return i;
}

bool Partie::getFin()
{
    return partie_termine;
}

void Partie::setFin(bool fin)
{
    this->partie_termine=fin;
}


void Partie:: SuppTetroCourant()
{
    delete m_tetro_courant;
    m_tetro_courant=nullptr;
}

void Partie::CreerTetroCourant()
{
    delete m_tetro_courant;
    m_tetro_courant=m_tetro_suivant;
    m_tetro_suivant=TirerTetro();
    if(collision(m_tetro_suivant->getI(),m_tetro_suivant->getJ()))
    {
        cout << "GAME OVER"<<endl;
        partie_termine = true;
    }
    delete m_tetro_suivantCopy;
    m_tetro_suivantCopy=m_tetro_suivant->clone();
}

Tetromino* Partie::TirerTetro()
{
    int valeur  = rand()%7;
    switch(valeur)
    {
        case 0: return new I();
            break;

        case 1: return new J();
            break;

        case 2: return new L();
            break;

        case 3: return new O();
            break;

        case 4: return new S();
            break;

        case 5: return new T();
            break;

        case 6: return new Z();
            break;
    }
}

void Partie::SuppLigne(int ligne)
{
    int nbrligne=m_pu->supplignepuit(ligne);
    switch(nbrligne)
    {
        case 0: break;
        case 1:
        {
            calculerScore(100);
        }
        break;
        case 2:
        {
            calculerScore(300);
        }
        break;
        case 3:
        {
            calculerScore(500);
        }
        break;
        case 4:
        {
            calculerScore(1000);
        }
        break;
    }
    IncrementeLevel();
}

void Partie::setscore(int score)
{
    m_score=score;
}


int Partie::getscore()
{
    return m_score;
}

void Partie::calculerScore(int N)
{
    m_score=m_score+N;
}

bool Partie::getEtatTime()
{
    return m_etatTimer;
}
void Partie::setEtatTime(bool etat)
{
    m_etatTimer=etat;
}

void Partie::setlevel(int level)
{
    m_level=level;
}

int Partie::getlevel()
{
    return m_level;
}

void Partie::IncrementeLevel()
{
    if(m_score<=5000)
        m_level=1;
    else if(m_score>5000 && m_score<=15000)
        m_level=2;
    else
        m_level=3;

}
