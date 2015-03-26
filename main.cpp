// an sample program showing how to use a ShapeFactory
#include <iostream>
#include <vector>
#include <memory>
#include "ShapeFactory.h"
#include "Shape.h"
#include "Command.h"
using namespace std;

int main() {
    vector<std::shared_ptr<Shape>>  shapeList;
    shared_ptr<Shape>               s;
    vector<Command*>                commandList;
    ShapeFactory                    sf( cin );

    while ( ( s = sf.create() ) )
        shapeList.push_back( s );
        
        Command *c = new XReflectCommand(shapeList[1]);
        c->execute();
   
    for ( vector<std::shared_ptr<Shape>>::size_type i = 0, sz = shapeList.size(); i < sz; i++ )
        shapeList[i]->draw();
}
