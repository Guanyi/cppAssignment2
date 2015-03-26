#include "Triangle.h"
using namespace std;

Triangle::Triangle( istream& is ) {
    is >> v1_ >> v2_ >> v3_; 
    if ( !is )
      throw "Triangle::Triangle(const std::string&)";
}

void Triangle::draw() const {
    cerr << "[T: " << v1_ << ", " << v2_ << ", " << v3_ << "]" << endl; 
}


void Triangle::xreflect() {
    v1_.reflectX(); v2_.reflectX(); v3_.reflectX();
}

void Triangle::yreflect() {
    v1_.reflectY(); v2_.reflectY(); v3_.reflectY();
}

void Triangle::translate( const Point & delta ) {
    v1_.translate( delta ); v2_.translate( delta ); v3_.translate( delta );
}
