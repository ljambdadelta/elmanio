#include <iostream>


#include "game.h"
#include "ui_cli.h"

using namespace std;

int main(int argc, char *argv[])
{
    srand( time(NULL) );
    //Game    game    = Game()    ;
    //UI_cli  ui      = UI_cli()  ;

    /*std::vector < int > v;

    for ( int i = 0; i < 9; i++) {
        v.push_back( rand() %13 -4 );
        std::cout << v.at( i ) << " ";
    }
    std::cout << std::endl;
    ;*/
    Game test( 10, 10 );
    UI_cli  u_test( test );
    test.start( u_test );
    //u_test.draw();
    std::cout << std::endl << std::endl;

    return 0;
}
