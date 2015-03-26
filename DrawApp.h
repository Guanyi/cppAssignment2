#ifndef DRAWAPP_H
#define DRAWAPP_H
#include <vector>
#include <memory>
#include "Shape.h"
// may need to include additional headers
using namespace std;

class DrawApp {
public:
    DrawApp();
    void run();        // loop to get user commands & execute them
    void addShape(std::shared_ptr<Shape> s);
    bool undo();       // undo 
    bool redo();       // redo

private:
    void draw() const;                           // draw all shapes
    vector<std::shared_ptr<Shape>>    shapes_;
    vector<std::shared_ptr<Command>>  history_;  // history list
    // additional data members if necessary
};
#endif

