#ifndef DRAWAPP_H
#define DRAWAPP_H
#include <vector>
#include <memory>
#include "Shape.h"
// may need to include additional headers
using namespace std;

class DrawApp {
public:
    //DrawApp();
    void run();        // loop to get user commands & execute them
    void addShape( std::shared_ptr<Shape> s );
    void addToHistory( std::shared_ptr<Command> );
    void showShapeList();
    bool undo();       // undo 
    bool redo();       // redo
    size_t shapeSize();
    std::shared_ptr<Shape> getShape( size_t );

private:
    void draw() const;                           // draw all shapes
    vector<std::shared_ptr<Shape>>    shapes_;
    vector<std::shared_ptr<Command>>  history_;  // history list
    vector<std::shared_ptr<Command>>::iterator  currentCommand_ = history_.begin();
};
#endif

inline void DrawApp::addShape( std::shared_ptr<Shape> s ) {
    shapes_.push_back( s );
}

inline void DrawApp::addToHistory( std::shared_ptr<Command> c ) {        
    if ( history_.size() != 0) {
        history_.erase( currentCommand_+1, history_.end() );
    }
    history_.push_back( c );
    currentCommand_ = history_.end() - 1;
}

inline void DrawApp::showShapeList() {
    for ( vector<std::shared_ptr<Shape>>::size_type i = 0, sz = shapes_.size(); i < sz; i++ ) {
        cerr << i+1 <<": "; 
        shapes_[i]->draw();
    }
}

inline void run() {
    
    }

inline bool DrawApp::undo() {
    if ( history_.size() == 0 || currentCommand_ < history_.begin() )
        return false;
    else {
        (*currentCommand_)->unexecute();
        currentCommand_--;
        showShapeList();
        return true;
    }
}

inline bool DrawApp::redo() {
    if ( history_.size() == 0 || currentCommand_ == history_.end() - 1 )
        return false;
    else {
        (*(++currentCommand_))->execute();
        showShapeList();
        return true;
    }
    return true;
}

inline size_t DrawApp::shapeSize() {
    return shapes_.size();
}

inline std::shared_ptr<Shape> DrawApp::getShape( size_t i ) {
    return shapes_[i];
}
