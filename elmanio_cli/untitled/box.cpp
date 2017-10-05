#include "box.h"
#include <typeinfo>

// Constructors
Box::Box() :    position { 0, 0 },
                isBomb { false },
                isOpen { false }
{}

Box::Box( const Box& b ){
    this->position  = b.position;
    this->isBomb    = b.isBomb  ;
    this->isOpen    = b.isOpen  ;
}


Box::Box( pos posit, bool bomb, bool open) {
    position.x = posit.x;
    position.y = posit.y;
    isBomb = bomb;
    isOpen = open;
}


std::string Box::getType(){ return "Abstract, Abstract"; }

void Box::setBombHere() {
    this->isBomb = true;

}


void Box::debug_showCont() {
    std::cout << "X\tY\tBomb\topen" << std::endl;
    std::cout << position.x << "\t" << position.y << "\t" << isBomb << "\t" << isOpen << "\t" << std::endl
                     ;
}
