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
    void draw();
private:
     std::vector < int > gameinfo;
     void drawLine();
     void drawBox();
};

#endif // UI_CLI_H
