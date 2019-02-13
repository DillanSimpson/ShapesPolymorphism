#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "TwoDimensionalShape.h"

class Rectangle : public TwoDimensionalShape {
	// default constructor with parameters: length, width, x, y
public:
	Rectangle(double l = 0.0, double w = 0.0, double x = 0.0, double y = 0.0) : length(l), width(w), TwoDimensionalShape(x, y) {}

	virtual double getLength() const { return length; }
	virtual double getWidth() const { return width; }
	virtual double getArea() const { return xCenter * yCenter; }
	void print(ostream & out = cout) const {
		out << "Rectangle with length " << getLength() << " and width " << getWidth() << "; center at (" << xCenter << "," << yCenter << ")";
	}
private:
	double length;
	double width;
};
#endif
