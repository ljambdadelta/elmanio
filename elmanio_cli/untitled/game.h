#ifndef GAME_H
#define GAME_H

#include <vector>
#include <sstream>
#include "field.h"

#define SURROUNDING_SQUARE_SIZE 9
#define SQUARE_SIDE 3
#define LEFT_3x3_BORDER 0
#define TOP_3x3_BORDER 0
#define CENTER_3x3 4
#define RIGHT_3x3_BORDER 2
#define BOT_3x3_BORDER 6
#define COLUMN true
#define LINE false
#define TOP_LINE 1
#define BOT_LINE 2
#define LEFT_COLUMN 3
#define RIGHT_COLUMN 4
#define NO_BORDER_NEIGHBOUR 0

//class UI_cli;
class Game
{
public:

    Game();
    Game( int length );
    Game( int length, int number_of_mines );
    Game( const Game& g );
    static std::vector < int > giveLineByNumber( std::vector < int > input,
                                                    int Nline, int length);
    template < typename T >
    void start( T& output_interface ) {
        //std::string* instruction;
        output_interface.draw();
        //instruction = output_interface.userInput(); // check if it works as i think
        processUserInput( output_interface.userInput() );
        // readline
        // do command from line
        // update output
        // wait for command
    }
    static void say( std::vector < std::string > allThis );
    std::vector < int > getField();
private:
    //
    bool openBox( std::string position );
    bool openBox( int position );
    int         positionToIdTranslator( Box::pos position   );
    Box::pos    idToPositionTranslator( int positionInt     );
    void    processUserInput( std::vector < std::string > data );
    char    grabFirstCharFromString( std::string longCommand );
    int     convertFromStringToInt( std::string string );
    void    getNeighbInfo( bool (&arr)[ SURROUNDING_SQUARE_SIZE ], int line, int column, bool isColumn);
    void    kickUnexistingNeighbours( bool (&arr)[ SURROUNDING_SQUARE_SIZE ], int index );
    void    dropLine( bool (&arr)[ SURROUNDING_SQUARE_SIZE ], int positionOfLine );
    void    dropColumn( bool (&arr)[ SURROUNDING_SQUARE_SIZE ], int positionOfColumn ) ;
    int     countNeighbousOfClearBox( int index );
    int     positionOfCenterInField( int index ) ;
    void    checkLastNeigbous( bool (&arr)[ SURROUNDING_SQUARE_SIZE ], int index );
    void    checkThreeInLine( bool &a1, bool &a2, bool &a3, int middle ) ;
    bool    checkOne( int index );
    int     countTrues( bool ( &input )[ SURROUNDING_SQUARE_SIZE ] );
    int     length;
    int     Nmines;
    int     idOfCurrentBox;
    Field   field;


};

//#include "ui_cli.h"
#endif // GAME_H
