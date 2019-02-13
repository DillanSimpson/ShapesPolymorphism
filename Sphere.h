#ifndef SPHERE_H
#define SPHERE_H
#include "ThreeDimensionalShape.h"
class Sphere : public ThreeDimensionalShape
{
public:
	// default constructor with parameters: radius, x, y, z
	Sphere(double r = 0.0, double x = 0.0, double y = 0.0, double z = 0.0) : radius(r), ThreeDimensionalShape(x, y, z) { }
	virtual double getArea() const { return 4 * PI*pow(getRadius(), 2); }
	virtual double getVolume() const {return 1.33333333333 * PI * pow(radius, 3); }  // return volume of Sphere
	double getRadius() const { return radius; }// return radius of Sphere
	void print(ostream & out = cout) const {
		out << "Sphere with radius " << getRadius() << "; center at (" << xCenter << ", " << yCenter << ", " << zCenter << ")";
	}
private:
	double radius; // radius of Sphere
}; // end class Sphere
#endif