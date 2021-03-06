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

    std::string getType();

    // Basic functions

    void setBombHere();

    void debug_showCont();

    // get/set

    bool hasBomb()   { return isBomb; }
    bool hasOpen()   { return isOpen; }
    bool hasFlag()   { return isFlag; }
    bool hasAlt()    { return isAlt ; }

    void setOpen( bool newState ) {
        if ( !newState )
            return; // never should happens
        isOpen = newState;
        return ;
    }

protected:

    // fields
            pos     position;
            bool    isBomb;
            bool    isOpen;
            bool    isFlag;
            bool    isAlt;
};


#endif // BOX_H
