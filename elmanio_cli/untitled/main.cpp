#include <iostream>

#include "game.h"
#include "ui_cli.h"

using namespace std;

int main(int argc, char *argv[])
{
    Game    game    = Game()    ;
    UI_cli  ui      = UI_cli()  ;

    std::vector < int > v= { Box::BOMB, Box::BOMB, Box::BOMB,
                             Box::CLEAR };

    UI_cli  u_test( v );
    u_test.draw();

    return 0;
}
