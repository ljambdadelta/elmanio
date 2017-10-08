#include "field.h"

#define UNDEFINED -1
#define WILL_BE_DEFINED_LATER 0

// Constructors
Field::Field() :length { UNDEFINED }, Nmines { UNDEFINED }, volume { UNDEFINED }
{
    generate();
    setBombs();
    fieldForOutput = std::vector < int >();
}

Field::Field( int size) :Nmines { WILL_BE_DEFINED_LATER } {
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
    this->fieldForOutput = f.fieldForOutput;
}

// Restart
void Field::clear() {
    field.clear();
    fieldForOutput.clear();
    length = UNDEFINED;
    Nmines = UNDEFINED;
    volume = UNDEFINED;
}

// Start
void Field::generate() {
    if ( length != UNDEFINED )
        generate( DEFAULT_LENGTH );
    return;
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
    if ( Nmines != UNDEFINED )
        setBombs( DEFAULT_LEVEL_OF_SIMPLICITY );
    return;
}

void Field::setBombs( int mines ) {
    Nmines = mines;
    for( int cMineId = 0; cMineId < Nmines; cMineId++ ) {
        int randId = rand() % ( length*length - 1 ) ;
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
    convertFieldForOutput();
    return fieldForOutput;
}

void Field::setVolume() {
    setVolume( length * length );
}

void Field::setVolume( int v ) {
    volume = v;
}

bool Field::open( int id ) {
    if ( field.at( id ).hasOpen() ) {
        return field[ id ].hasBomb();
    }
    field[ id ].setOpen( true );
    return field[ id ].hasBomb();
}

Box    Field::getBoxAt( int index ) {
    return field.at( index );
}
