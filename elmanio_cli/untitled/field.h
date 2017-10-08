#ifndef FIELD_H
#define FIELD_H

#define DEFAULT_LENGTH 10
#define DEFAULT_LEVEL_OF_SIMPLICITY 10

#include <vector>
#include "box.h"

class Field
{
public:


    Field();
    Field( const Field& f);
    Field( int size );
    Field( int size, int mines );

    void generate();
    void generate( int size );

    void setBombs();
    void setBombs( int mines );

    void clear();
    bool open( int id);
    void convertFieldForOutput();

    int getVolume();
    int getNmines();
    std::vector < int > getField();
    Box    getBoxAt( int index );

    void setVolume();
    void setVolume( int v );
private:
    std::vector < Box >    field;
    std::vector < int >    fieldForOutput;
    int length;
    int Nmines;
    int volume;
};

#endif // FIELD_H
