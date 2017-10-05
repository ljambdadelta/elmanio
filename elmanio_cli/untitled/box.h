#ifndef BOX_H
#define BOX_H

#include <iostream>

class Box
{
public:

    // Structues
     struct  pos{
       int x;
       int y;
    };
    enum Type {
         QUESTION = -4,
         ALT,
         FLAG,
         BOMB,
         CLEAR, // 0
        ONE,
        TWO,
        THREE,
        FOUR,
        FIVE,
        SIX,
        SEVEN,
        EIGHT,
        ERROR
     } ;

    // Constructors
    Box();
    Box( const Box &b );
    Box( pos posit, bool bomb, bool open);

    // Virtual functions

    virtual std::string getType();

    // Basic functions

    void setBombHere();

    void debug_showCont();

    // get/set

    bool hasBomb()   { return isBomb; }
    bool hasOpen()   { return isOpen; }
protected:

    // fields
            pos     position;
            bool    isBomb;
            bool    isOpen;
};


#endif // BOX_H
