#include "Circle.h"
using namespace std;

Circle::Circle( istream & is ) {
    is >> centre_ >> radius_; 
    if ( !is )
        throw "Circle::Circle( const std::string& )";
}  

void Circle::draw() const {
    cerr << "[C: " << centre_ << ", " << radius_ << "]" << endl; 
} 
  
void Circle::xreflect() {
    centre_.reflectX();
}
  
void Circle::yreflect() {
    centre_.reflectY();
}

void Circle::translate( const Point & delta ) {
    centre_.translate( delta );
}
