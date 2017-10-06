#ifndef GAME_H
#define GAME_H

#include <vector>
#include "field.h"


class Game
{
public:

    Game();
    Game( int length );
    Game( int length, int number_of_mines );
    Game( const Game& g );
    static std::vector < int > giveLineByNumber( std::vector < int > input,
                                                    int Nline, int length);
    std::vector < int > getField();
private:
    //
    void openBox();
    void openBox( Box::pos position);
    int     positionToIdTranslator( Box::pos position );



    int     length;
    int     Nmines;
    Field   field;


};

#endif // GAME_H
