#include "boxbomb.h"

BoxBomb::BoxBomb() : Box()
{
    this->isBomb = true;
}

BoxBomb::BoxBomb(const Box& b) : Box( b )
{
    this->isBomb = true;
}
