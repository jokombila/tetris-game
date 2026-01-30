#include "s.h"

S::S(point p,point p2):Tetromino(p, p2, 15,"Vert","S",0) {
    Mat[0][0][1] = 1;
    Mat[0][1][1]=1;
    Mat[0][1][2]=1;
    Mat[0][2][2]=1;

    Mat[1][1][2] = 1;
    Mat[1][1][3]=1;
    Mat[1][2][1]=1;
    Mat[1][2][2]=1;

    Mat[2][0][1] = 1;
    Mat[2][1][1]=1;
    Mat[2][1][2]=1;
    Mat[2][2][2]=1;

    Mat[3][1][2] = 1;
    Mat[3][1][3]=1;
    Mat[3][2][1]=1;
    Mat[3][2][2]=1;

}

Tetromino* S:: clone()
{
    return new S({400,100}, {50,50});
}
