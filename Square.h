#ifndef SQUARE_H
#define SQUARE_H
#include "Rectangle.h"

class Square : public Rectangle
{
public:
	// default constructor with parameters: side, x, y
	Square(double side = 0.0, double x = 0.0, double y = 0.0) : sideLength(side), Rectangle(side, side, x, y) {  }
	virtual double getSideLength() const { return sideLength; }
	virtual double getArea() const { return pow(sideLength, 2); } 
	void print(ostream & out = cout) const {
		out << "Square with side length " << sideLength << "; center at (" << getCenterX() << "," << getCenterY() << ")";
	}
private:
	double sideLength; // length of sides
}; // end class Square
#endif

