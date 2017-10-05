#include "field.h"


// Constructors
Field::Field()
{
    generate();
    setBombs();
    fieldForOutput = std::vector < int >();
}

Field::Field( int size) {
    generate( size );
    setBombs();
    fieldForOutput = std::vector < int >();
}

Field::Field( int size, int mines) {
    generate( size );
    setBombs( mines );
    fieldForOutput = std::vector < int >();
}

Field::Field( const Field& f) {
    this->field = f.field;
    this->length = f.length;
    this->Nmines = f.Nmines;
    fieldForOutput = f.fieldForOutput;
}

// Restart
void Field::clear() {
    field.clear();
    fieldForOutput.clear();
    length = -1;
    Nmines = -1;
    volume = -1;
}

// Start
void Field::generate() {
    generate( DEFAULT_LENGTH );
}

void Field::generate( int size ) {
    field = std::vector < Box >();
    length = size;
    setVolume();
    for( int id = 0; id < ( volume ); id++ ) {
        Box b;
        field.push_back(b);
    }
}

void Field::setBombs() {
    setBombs( DEFAULT_LEVEL_OF_SIMPLICITY );
}

void Field::setBombs( int mines ) {
    Nmines = mines;
    for( int cMineId = 0; cMineId < Nmines; cMineId++ ) {
        int randId = rand() % ( length*length - 1) ;
        field.at( randId ).setBombHere();
    }
}

void Field::convertFieldForOutput() {
    fieldForOutput = std::vector < int >();
    for ( Box box : field ) {
        //TODO: rework for all types
        if      ( box.hasOpen() )       fieldForOutput.push_back( Box::CLEAR );
        else if ( box.hasBomb() )       fieldForOutput.push_back( Box::BOMB  );
        else                            fieldForOutput.push_back( Box::CLEAR );
    }

}

// Get/Set
int Field::getVolume() {
    return volume;
}

int Field::getNmines() {
    return Nmines;
}

std::vector < int > Field::getField() {
    return fieldForOutput;
}

void Field::setVolume() {
    setVolume( length * length );
}

void Field::setVolume( int v ) {
    volume = v;
}
