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
    char    command = grabFirstCharFromString( data[ 0 ] ); // TODO check if user enters good value
    int     x = convertFromStringToInt( data[ 1 ] ) - 1 ;
    int     y = convertFromStringToInt( data[ 2 ] ) - 1 ;
    int     index   =  x * length + y;
    switch ( command ) {
    case 'o':
    case 'O': {
        bool resultOfOpeningBox = openBox( index );
        if ( resultOfOpeningBox )
            say( { std::string("endgame") }); // end game
        else

        break;
    }
    default:
         say( { std::string("wow") }); // end game
        //break;
    }
}

char    Game::grabFirstCharFromString( std::string longCommand ) {
    return longCommand.at( 0 );
}

int     Game::countNeighbousOfClearBox( int index ) {
    bool    neighb[ SURROUNDING_SQUARE_SIZE ] ;
    for( bool any : neighb )
        any = true;
   kickUnexistingNeighbours( neighb, index);
   checkLastNeigbous( neighb, index );
   return countTrues( neighb );
}

void Game::kickUnexistingNeighbours( bool (&target)[ SURROUNDING_SQUARE_SIZE ], int index ) {
    int     touchingBorder                      = positionOfCenterInField( index );
            target[ CENTER_3x3 ]                = false ;

    switch ( touchingBorder ) {
    case TOP_LINE:
    case BOT_LINE:
        dropLine( target, touchingBorder );
    break;

    case LEFT_COLUMN:
    case RIGHT_COLUMN:
        dropColumn( target, touchingBorder );
    break;
    }
}

void Game::dropLine( bool (&target)[ SURROUNDING_SQUARE_SIZE ], int positionOfLine ) {
    int borderLine      = ( positionOfLine == TOP_LINE ) ? TOP_3x3_BORDER   : BOT_3x3_BORDER;
    for( int allOverBorder = borderLine; allOverBorder <= borderLine + 2; borderLine++ )
        target[ allOverBorder ] = false;
}

void Game::dropColumn( bool (&target)[ SURROUNDING_SQUARE_SIZE ], int positionOfColumn ) {
    int borderColumn    = ( positionOfColumn == LEFT_COLUMN ) ? LEFT_3x3_BORDER     : RIGHT_3x3_BORDER;
    for( int allOverBorder = borderColumn; allOverBorder <= borderColumn + 2 * SQUARE_SIDE ; allOverBorder++ )
        target[ allOverBorder ] = false;
}

int Game::positionOfCenterInField( int index ) {
    if ( ( index / length ) == 0 )  return TOP_LINE;
    if ( ( index % length ) == 1 )  return LEFT_COLUMN;
    if ( ( index / length ) + 1 == length ) return BOT_LINE;
    if ( ( index % length ) > length - 1 )  return RIGHT_COLUMN;
    return NO_BORDER_NEIGHBOUR;
}

void Game::checkLastNeigbous( bool (&arr)[ SURROUNDING_SQUARE_SIZE ], int index ) {
    index -= SQUARE_SIDE;
    for( int middle = index, in = 0 ; middle <= ( index + SQUARE_SIDE * 2 ); middle += SQUARE_SIDE, in++ )
        checkThreeInLine(  arr[ index + in * SQUARE_SIDE - 1 ], arr[ index + in * SQUARE_SIDE ], arr[ index + in * SQUARE_SIDE + 1 ] , middle );
}

void Game::checkThreeInLine( bool &a1, bool &a2, bool &a3, int middle ) {
    a1 = checkOne( middle - 1 );
    a2 = checkOne( middle );
    a3 = checkOne( middle + 1 );
}

bool Game::checkOne( int index ) {
    return field.getBoxAt( index ).hasBomb();
}

int Game::countTrues( bool ( &input )[ SURROUNDING_SQUARE_SIZE ] ) {
    int counter = 0;
    for ( bool thisOne : input )
        if ( thisOne )
            ++counter;
    return counter;
}

int Game::convertFromStringToInt( std::string string ) {
    std::stringstream ss;
    ss << string;
    int integer;
    ss >> integer;
    return integer;
}

/*
bool    Game::openBox( std::string position ) {
    convertFromStringToInt( position );
    Box::pos positionPos = idToPositionTranslator( positionInt );
    int positionInt = positionToIdTranslator( positionPos );
    return openBox( positionInt );
}
*/

bool    Game::openBox( int position ) {
    return field.open( position );
}

Box::pos     Game::idToPositionTranslator( int positionInt ) {
    Box::pos positionPos;
    positionPos.y = positionInt / length;
    positionPos.x = positionInt % length;
    return positionPos;
}
int     Game::positionToIdTranslator( Box::pos position ) {
    return  ( position.x * length ) + position.y ;
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
