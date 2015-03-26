#ifndef POINT_H
#define POINT_H
#include <iostream>

// Note: you may need to add more operations for transformations
class Point {
public:
    explicit Point( int x = 0, int y = 0 ): x_( x ), y_( y ) {}

    friend std::istream& operator>>( std::istream & is, Point & pt );
    friend std::ostream& operator<<( std::ostream & os, const Point & pt );
    inline int getX() const;
    inline int getY() const;
	inline void reflectX();
    inline void reflectY();
    inline void translate( const Point & );

private:
    int x_, y_;
};

// reads input points of the form (x, y)
inline std::istream & operator>>(std::istream& is, Point& pt) {
    char  c1, c2, c3;
    int   x, y;

    is >> c1 >> x >> c2 >> y >> c3;
    if (is && c1 == '(' && c2 == ',' && c3 == ')')
        pt.x_ = x, pt.y_ = y;
    else
        is.setstate(std::ios_base::failbit);
    return is;
}

inline std::ostream & operator<<( std::ostream & os, const Point & pt ) {
    os << '(' << pt.x_ << ',' << pt.y_ << ')';
    return os;
}

inline int Point::getX() const { return x_; }
inline int Point::getY() const { return y_; }
inline void Point::reflectX() { x_ = -x_; }
inline void Point::reflectY() { y_ = -y_; }
inline void Point::translate( const Point & delta ) { x_ += delta.getX(); y_ += delta.getY(); }
#endif
