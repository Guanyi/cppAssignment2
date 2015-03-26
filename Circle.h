#ifndef CIRCLE_H
#define CIRCLE_H
#include <iostream>
#include <string>
#include "Shape.h"
#include "Point.h"

class Circle: public Shape {
public:
    explicit Circle( std::istream & is );

    virtual void draw() const override;
    
    //void save(std::ostream& os) const;
    
    virtual void xreflect() override;
  
    virtual void yreflect() override;

    virtual void translate( const Point & ) override;

private:
    Point  centre_;
    int    radius_;
};
#endif
