#ifndef GAME_H
#define GAME_H

#include <vector>
#include <sstream>
#include "field.h"



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
    void openBox( std::string position );
    void openBox( Box::pos position );
    int         positionToIdTranslator( Box::pos position   );
    Box::pos    idToPositionTranslator( int positionInt     );
    void    processUserInput( std::vector < std::string > data );
    char    convertToOneCommandSymbol( std::string longCommand );

    int     length;
    int     Nmines;
    Field   field;


};
//#include "ui_cli.h"
#endif // GAME_H
