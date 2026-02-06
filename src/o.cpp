#include "o.h"

O::O(point p,point p2):Tetromino(p, p2, 15,"Bleu","O",0) {
    Mat[0][0][1] = 4;
    Mat[0][0][2]=4;
    Mat[0][1][1]=4;
    Mat[0][1][2]=4;

    Mat[1][0][1] = 4;
    Mat[1][0][2]=4;
    Mat[1][1][1]=4;
    Mat[1][1][2]=4;

    Mat[2][0][1] = 4;
    Mat[2][0][2]=4;
    Mat[2][1][1]=4;
    Mat[2][1][2]=4;

    Mat[3][0][1] = 4;
    Mat[3][0][2]=4;
    Mat[3][1][1]=4;
    Mat[3][1][2]=4;

}

Tetromino* O:: clone()
{
    return new O({340,140}, {50,50});
}
