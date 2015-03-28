// an sample program showing how to use a ShapeFactory
#include <iostream>
#include <vector>
#include <memory>
#include <fstream>
#include <sstream>
#include "ShapeFactory.h"
#include "Shape.h"
#include "Command.h"
#include "DrawApp.h"

using namespace std;

void trimLeadingSpace( string & );

int main( int argc, char* argv[] ) {
    shared_ptr<Shape> s;
    DrawApp drawApp;;
    
    if( argc != 2 ) {
        cerr << "Only 1 argument allowed.";
        return 1;
	}

    ifstream reader;
    reader.open( argv[1] );
    if( !reader.is_open() ) {
        cerr << "Cannot open input file.";
        return 1;
    }
    
    ShapeFactory sf( reader );
    while ( ( s = sf.create() ) )
        drawApp.addShape(s);
    drawApp.showShapeList();

    string input;
    string commandType;
    size_t shapeIndex;
    cout << "> ";
    while( getline( cin, input ) ) {
        if (input == "\n")
            continue;
        trimLeadingSpace( input );
        istringstream iss( input );
        Point point;
        if ( iss >> commandType ) {
            if ( commandType == "u" )
                drawApp.undo();
            if ( commandType == "r" )
                drawApp.redo();
            if (commandType == "x" && iss >> shapeIndex && shapeIndex <= drawApp.shapeSize() ) {
                shared_ptr<Command> c ( new XReflectCommand( drawApp.getShape( shapeIndex-1 ) ) );
                c->execute();
                drawApp.addToHistory( c );
                drawApp.showShapeList();
            }
            if ( commandType == "y" && iss >> shapeIndex && shapeIndex <= drawApp.shapeSize() ) {
                shared_ptr<Command> c ( new YReflectCommand( drawApp.getShape( shapeIndex-1 ) ) );
                c->execute();
                drawApp.addToHistory( c );
                drawApp.showShapeList();
            }
            if ( commandType == "t" && iss >> shapeIndex && shapeIndex <= drawApp.shapeSize() && iss >> point ) {
                shared_ptr<Command> c ( new TranslateCommand( drawApp.getShape( shapeIndex-1 ), point ) );
                c->execute();
                drawApp.addToHistory( c );
                drawApp.showShapeList();
            }
        }
        cout << "> ";
    }
}

void trimLeadingSpace( string & command ) {
    int length = command.size();
    int i;
    for( i = 0; i < length; i++) {
        if(command[i] != ' ')
            break;;
    }
    command = command.substr(i, length);
    return;
}




