#include "ui_cli.h"

UI_cli::UI_cli()
{
gameinfo = std::vector < int >;
}
UI_cli::UI_cli( std::vector < int > info) {
    gameinfo = info;
}

UI_cli::draw() {
    int length = sqrt( gameinfo.size() );


}
