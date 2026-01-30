#include "j.h"

J::J(point p,point p2):Tetromino(p, p2, 15,"Gris","J",3) {
    Mat[0][0][2] = 7;
    Mat[0][1][2]=7;
    Mat[0][2][2]=7;
    Mat[0][2][1]=7;

    Mat[1][1][1] = 7;
    Mat[1][1][2]=7;
    Mat[1][1][3]=7;
    Mat[1][2][3]=7;

    Mat[2][0][1] = 7;
    Mat[2][0][2]=7;
    Mat[2][1][1]=7;
    Mat[2][2][1]=7;

    Mat[3][1][1] = 7;
    Mat[3][2][1]=7;
    Mat[3][2][2]=7;
    Mat[3][2][3]=7;

}

Tetromino* J:: clone()
{
    return new J({400,100}, {50,50});
}
