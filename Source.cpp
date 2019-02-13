#include <vector>
using std::vector;
#include <typeinfo>
#include "Shape.h"
#include "TwoDimensionalShape.h"
#include "ThreeDimensionalShape.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Square.h"
#include "Sphere.h"
#include "Cube.h"
using namespace std;
int main()
{
	const int NUMBER_OF_SHAPES = 7;
	// create vector shapes
	vector < Shape * > shapes(NUMBER_OF_SHAPES);
	// initialize vector with Shapes
	shapes[0] = new Circle(3.5, 6, 9);
	shapes[1] = new Square(12, 2, 2);
	shapes[2] = new Sphere(5, 1.5, 4.5,5.5);
	shapes[3] = new Cube(2.2);
	shapes[4] = new Triangle(0.0, 0.0, 0.0, 3.0, 4.0, 0.0);
	shapes[5] = new Rectangle(3.0, 4.0, 3.0, 4.0);
	shapes[6] = new Triangle(0.0, 0.0, 0.0, -3.0, -4.0, 0.0);

	// output Shape objects and display area and volume as appropriate
	for (int i = 0; i < NUMBER_OF_SHAPES; i++)
	{
		cout << *(shapes[i]) << endl;

		//Downcast pointers
		TwoDimensionalShape *twoDimensionalShapePtr = dynamic_cast<TwoDimensionalShape*>  (shapes[i]);
		Triangle *triangleptr = dynamic_cast<Triangle*> (shapes[i]);
		Square *squareptr = dynamic_cast<Square*> (shapes[i]);
		Rectangle *rectangleptr = dynamic_cast<Rectangle*> (shapes[i]);
		ThreeDimensionalShape *threeDimensionalShapePtr = dynamic_cast<ThreeDimensionalShape*> (shapes[i]);

		// if Shape is a TwoDimensionalShape, display its area
		if (twoDimensionalShapePtr != 0) {
			cout << "Area: " << twoDimensionalShapePtr->getArea() << endl;

			//If shape is triangle, sqaure or rectangle display respected outputs
			if (triangleptr != 0) {
				cout << "Triangle Shape: \n" << "Triangle side1 = " << triangleptr->getSide1Length() << "\nTriangle side2 = " <<
					triangleptr->getSide2Length() << "\nTriangle side3 = " << triangleptr->getSide3Length() << endl;
			}
			else if (squareptr != 0) {
				cout << "Square Shape: " << "\nSqaure side = " << squareptr->getSideLength() << endl;
			}
			else if (rectangleptr != 0) {
				cout << "Rectangle shape: " << "\nRectangle length = " << rectangleptr->getLength() << "\nRectangle width = "
					<< rectangleptr->getWidth() << endl;
			}
		}
		
		// if Shape is a ThreeDimensionalShape, display its area and volume
		if (threeDimensionalShapePtr != 0) {
			cout << "Area: " << threeDimensionalShapePtr->getArea()
				<< "\nVolume: " << threeDimensionalShapePtr->getVolume();
			cout << endl;
		}
		cout << endl;
	} 
	return 0;
}