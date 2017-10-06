#ifndef UI_CLI_H
#define UI_CLI_H

#include <vector>
#include <cmath>
#include "game.h"

class UI_cli
{
public:
    UI_cli();
    UI_cli( std::vector < int > info);
    UI_cli( const UI_cli& u);
    UI_cli( Game g );

    static void debug_showGameinfo( std::vector < int > v);
    void draw();
private:
     std::vector < int > gameinfo;
     int length;
     void drawLine( std::vector < int > input );
     void drawBox( int input );
     //std::vector < int > giveLineByNumber( std::vector < int > input,
     //                                                    int Nline, int length);
};

#endif // UI_CLI_H
