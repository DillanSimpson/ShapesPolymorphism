#ifndef CUBE_H
#define CUBE_H
#include "ThreeDimensionalShape.h"
class Cube : public ThreeDimensionalShape
{
public:
	// default constructor with parameters: side, x, y, z
	Cube(double side = 0.0, double x = 0.0, double y = 0.0, double z = 0.0) : ThreeDimensionalShape(x, y, z), sideLength(side) {}
	virtual double getArea() const { return 6 * pow(sideLength, 2); }
	virtual double getVolume() const { return pow(sideLength, 3); }
	double getSideLength() const { return sideLength; } // return length of sides
	void print(ostream & out = cout) const {
		out << "Cube with side length " << getSideLength() << "; center at (" << xCenter << "," << yCenter << "," << zCenter << ")";
	}
private:
	double sideLength; // length of sides of Cube
}; // end class Cube
#endif