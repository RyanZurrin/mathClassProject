#pragma once
// Part of a final project in c++ II, this program as a whole
// will calculate the properties of 2D and 3D objects and vectors

// prgrammer:   Ryan Zurrin

#ifndef CALCULATOR_H
#define CALCULATOR_H



#include "Shape.h"
//#include "ThreeDimensional.h"
//#include "TwoDimensional.h"




class Calculator// : public Numbers
{
public:
	Calculator();
	Square* sqpt;
	Triangle* triptr;
	Vector* vectptr;
	double basicMathOperation(double x, char op, double y);
	Square *squareMathOperation(Square &x, char op0, Square &y);
	Triangle* triangleMathOperation(Triangle& x, char op0, Triangle& y);
	Vector* vectorMathOperation(Vector& x, char op0, Vector& y);
	~Calculator()
	{
		cout << "in calculator destructor";
		delete this;
	}
};

#endif // !CALCULATOR_H
