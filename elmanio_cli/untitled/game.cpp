#include "game.h"

/*Game::Game()
{

}*/
Game::Game()    :length{ -1 },
                 Nmines{ -1 }
{
    field = Field();

}


void    Game::openBox() {

}
int     Game::positionToIdTranslator( Box::pos position ) {
    return ( position.x * length ) + position.y ;
}

std::vector < int > Game::getField() {
    std::vector < int > realField ;
    realField = field.getField();

    // TODO: logic in function
    return  realField;
}
std::vector < int > Game::giveLineByNumber( std::vector < int > input,
                                                    int Nline, int length) {
    int startId = Nline * length;
    int endId   = ( Nline + 1 ) * length ;
    std::vector < int > result;
    for ( int i = startId ; i < endId; i++ ) {
       result.push_back( input.at( i ) );
    }
    return input;
}

