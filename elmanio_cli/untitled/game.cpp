#include "game.h"

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

/* output interface must have:  void draw() to draw all the boxes
 *                              std::string* userInput() to give info about what's the user choice
*/
void    Game::processUserInput( std::vector < std::string > data ) {
    char    command = convertToOneCommandSymbol( data[ 0 ] );
    switch ( command ) {
    case 'o':
    case 'O':
        openBox( data[ 1 ] );
        break;
    default:
        break;
    }
}
char    Game::convertToOneCommandSymbol( std::string longCommand ) {
    return longCommand.at( 0 );
}

void    Game::openBox( std::string position ) {
    std::stringstream ss;
    ss << position;
    int positionInt;
    ss >> positionInt;
    Box::pos positionPos = idToPositionTranslator( positionInt );

    std::cout << "say 'Booooom'" << std::endl;
}

void    Game::openBox( Box::pos position ) {
    //field.
}

Box::pos     Game::idToPositionTranslator( int positionInt ) {
    Box::pos positionPos;
    positionPos.y = positionInt / length;
    positionPos.x = positionInt % length;
    return positionPos;
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

void Game::say( std::vector < std::string > allThis ) {
    for ( std::string speach : allThis )
        std::cout << speach;
    std::cout << std::endl;
}
