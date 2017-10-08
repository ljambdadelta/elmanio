#include "game.h"

/*Game::Game()
{

}*/
Game::Game()    :length{ -1 },
                 Nmines{ -1 },
                 idOfCurrentBox { -1 }
{
    field = Field();
}

Game::Game( int length ) {
    this->length = length;
    this->field = Field( this->length );
    this->idOfCurrentBox = -1;
}

Game::Game( int length, int number_of_mines ) {
    this->length = length;
    this->Nmines = number_of_mines;
    this->field = Field( this->length, Nmines );
    this->idOfCurrentBox = -1;
}
Game::Game( const Game& g ) {
    this->length = g.length;
    this->Nmines = g.Nmines;
    this->field = g.field;
    this->idOfCurrentBox = -1;
}

/* output interface must have:  void draw() to draw all the boxes
 *                              std::string* userInput() to give info about what's the user choice
*/
void    Game::processUserInput( std::vector < std::string > data ) {
    char    command = convertToOneCommandSymbol( data[ 0 ] ); // TODO check if user enters good value
    switch ( command ) {
    case 'o':
    case 'O':
        bool resultOfOpeningBox = openBox( data[ 1 ] );
        if ( resultOfOpeningBox )
            say("endgame"); // end game
        else

        break;
    default:
        break;
    }
}
char    Game::convertToOneCommandSymbol( std::string longCommand ) {
    return longCommand.at( 0 );
}

int convertFromStringToInt( std::string string ) {
    std::stringstream ss;
    ss << string;
    int integer;
    ss >> integer;
    return integer;
}

bool    Game::openBox( std::string position ) {
    convertFromStringToInt( position );
    Box::pos positionPos = idToPositionTranslator( positionInt );

    return openBox( positionPos );
}

bool    Game::openBox( Box::pos position ) {
    return field.open( position );
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
