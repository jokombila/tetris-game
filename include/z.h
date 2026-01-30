#ifndef Z_H
#define Z_H

#include "Tetromino.h"
class Z: public Tetromino
{
public:
    Z(point p={155,110},point p2={7,4});
    Tetromino*  clone();
};

#endif // Z_H
