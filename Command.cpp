#include "Command.h"
using namespace std;

void XReflectCommand::execute() {
    shape_->xreflect();
}

void XReflectCommand::unexecute() {
    shape_->xreflect();
}

void YReflectCommand::execute() {
    shape_->yreflect();
}

void YReflectCommand::unexecute() {
    shape_->yreflect();
}
    
void TranslateCommand::execute() {
    shape_->translate( delta_ );
}

void TranslateCommand::unexecute() {
    delta_.reflectX();
    delta_.reflectY();
    shape_->translate( delta_ );
}
