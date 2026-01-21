#include "partie.h"

Partie::Partie()
{
    m_tetro = new Tetromino();
    m_pu = new Puits**[30];

    for(int i = 0; i<30;i++)
    {
        m_pu[i] = new Puits*[18];
        for(int j = 0;j<18;j++)
        {
            m_pu[i][j] = nullptr;
        }
    }
}



