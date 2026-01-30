#ifndef I_H
#define I_H

#include "Tetromino.h"
class I: public Tetromino
{
public:
    I(point p={155,110},point p2={7,4});
    Tetromino* clone();


};

#endif // I_H
