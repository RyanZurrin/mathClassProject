#pragma once
// Part of a final project in c++ II, this program as a whole
// will calculate the properties of 2D and 3D objects and vectors

// prgrammer:   Ryan Zurrin

#ifndef CALCULATOR_H
#define CALCULATOR_H
#include "Numbers.h"
#include "Shape.h"


class Calculator : public Numbers
{
public:
	Calculator();
	Square* sqpt;
	Triangle* triptr;
	Vector* vectptr;
	Vector3D* vect3Dptr;
	Cube* cubeptr;
	Sphere* orbptr;
	Calculator* calculate;

	double basicMathOperation(double x, char op, double);
	Square* squareMathOperation(Square& x, char op0, Square& y);
	Triangle* triangleMathOperation(Triangle& x, char op0, Triangle& y);
	//Triangle* triangleMathOperations(char m1, Triangle& x, char op, char m2, Triangle& y);
	Vector* vectorMathOperation(Vector& x, char op0, Vector& y);
	Vector3D* vector3DMathOperation(Vector3D& x, char op0, Vector3D& y);
	Cube* cubeMathOperation(Cube& x, char op0, Cube& y);
	Sphere* sphereMathOperation(Sphere& x, char op0, Sphere& y);


	~Calculator() = default;

};

#endif // !CALCULATOR_H

