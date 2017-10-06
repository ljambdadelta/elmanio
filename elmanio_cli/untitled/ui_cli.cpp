#include "ui_cli.h"

UI_cli::UI_cli() :length { -1 }
{
    gameinfo = std::vector < int >();
}

UI_cli::UI_cli( std::vector < int > info) {
    gameinfo = info;
    length   = sqrt( gameinfo.size() );
}

UI_cli::UI_cli( Game g ) :UI_cli( g.getField() ) { }

UI_cli::UI_cli( const UI_cli& u ) :length { -1 } {
    this->gameinfo = u.gameinfo;
    this->length   = u.length;
 }

void UI_cli::draw() {
    for( int i=0; i < length; i++) {
        std::vector < int > current  = Game::giveLineByNumber( gameinfo, i, length);
        drawLine( current );
    }
}

void UI_cli::drawLine( std::vector < int > input ) {
    for ( int i = 0; i < length; i++ ) {
        drawBox( input.at( i ) );
    }
    std::cout << std::endl;
}

void UI_cli::drawBox( int input ) {
    switch ( input ) {
        case Box::BOMB:
            std::cout << "[-]";
        break;
        case Box::ALT:
            std::cout << "[#]";
        break;
        case Box::FLAG:
            std::cout << "[+]";
        break;
        case Box::QUESTION:
            std::cout << "[?]";
        break;
        default:
            int local = input;
            if ( ( local < 0 ) || ( local > 8) )
                throw 1;
            std::cout << "[" << local << "]";
    }
}

void UI_cli::debug_showGameinfo( std::vector < int > v) {
    std::cout << "Start ";
    for (  int i : v )
        std::cout << i << " " ;
    std::cout << " end" << std::endl;
}
