#include "game.h"
#include "ui_cli.h"
/*Game::Game()
{

}*/
Game::Game()    :length{ -1 },
                 Nmines{ -1 }
{
    field = Field();
}

Game::Game( int length ) {
    this->length = length;
    this->field = Field( this->length );
}

Game::Game( int length, int number_of_mines ) {
    this->length = length;
    this->Nmines = number_of_mines;
    this->field = Field( this->length, Nmines );
}
Game::Game( const Game& g ) {
    this->length = g.length;
    this->Nmines = g.Nmines;
    this->field = g.field;
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
    return result;
}

