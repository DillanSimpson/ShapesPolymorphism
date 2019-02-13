#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "TwoDimensionalShape.h"

class Triangle : public TwoDimensionalShape 
{
public:
	// default constructor with parameters: x1,y1, x2,y2, x3,y3
	Triangle(double x1, double y1, double x2, double y2, double x3, double y3) : TwoDimensionalShape(0,0) {
		this->x1 = x1;
		this->y1 = y1;
		this->x2 = x2;
		this->y2 = y2;
		this->x3 = x3;
		this->y3 = y3;
		xCenter = ((getSide3Length() *x1)+(getSide2Length()*x2)+(getSide1Length()*x3)) / (getSide1Length()+ getSide2Length() + getSide3Length());
		yCenter = ((getSide1Length() *y1) + (getSide3Length()*y2) + (getSide1Length()*y3)) / (getSide1Length() + getSide2Length() + getSide3Length());
	}
		
	virtual double getPoint1x() const { return x1; } //get coordinates for each of the three points forming the triangle.
	virtual double getPoint1y() const { return y1; }
	virtual double getPoint2x() const { return x2; }
	virtual double getPoint2y() const { return y2; }
	virtual double getPoint3x() const { return x3; }
	virtual double getPoint3y() const { return y3; }
	virtual double getSide1Length() const { return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2)); } // return length of side1 (which is side1 arbitrary but fixed) of triangle
	virtual double getSide2Length() const { return sqrt((x2 - x3)*(x2 - x3) + (y2 - y3)*(y2 - y3)); } // return length of side2 of triangle
	virtual double getSide3Length() const { return sqrt((x3 - x1)*(x3 - x1) + (y3 - y1)*(y3 - y1)); } // return length of side3 of triangle
	virtual double getArea() const {
		double p = (getSide1Length() + getSide2Length() + getSide3Length()) / 2;
		return sqrt(p*(p - getSide1Length())*(p - getSide2Length())*(p - getSide3Length()));
	} // return area of triangle
	void print(ostream & out = cout) const {
		out << "Triangle with three points: (" << x1 << "," << y1 << "), " << "(" << x2 << ", " << y2 << "), " << "(" << x3 << ", " << y3 << "), " << std::endl;
		out << "With respected side lengths " << getSide1Length() << ", " << getSide2Length() << ", " << getSide3Length() << std::endl;
		out << "and center at " << "(" << xCenter << ", " << yCenter << ")";
	}; // output triangle object
private: //some redundancy built-in sides can be computed from points, but we store the side lengths
	double x1, y1; // numbering of points is arbitrary but fixed after chosen
	double x2, y2; // second of three
	double x3, y3; // third of three
	double side1; // side1 = sqrt( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) )
	double side2; // side2 = sqrt( (x2-x3)*(x2-x3) + (y2-y3)*(y2-y3) )
	double side3; // side3 = sqrt( (x3-x1)*(x3-x1) + (y3-y1)*(y3-y1) )
}; // end class Triangle
#endif
