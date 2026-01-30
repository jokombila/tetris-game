#ifndef T_H
#define T_H

#include "Tetromino.h"
class T: public Tetromino
{
public:
    T(point p={155,110},point p2={7,4});
    Tetromino*  clone();
};

#endif // T_H
