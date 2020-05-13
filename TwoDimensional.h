#pragma once
// Part of a final project in c++ II, this program as a whole
// will calculate the properties of 2D and 3D objects and vectors

// prgrammer:   Ryan Zurrin

#ifndef TWODIMENSIONAL_H
#define TWODIMENSIONAL_H
#include "Square.h"
#include "Triangle.h"
#include "vect.h"
#include <string>
#include <iostream>
using namespace std;

class TwoDimensional //: public Shape
{
public:
	// virtual void calculate_area();
	 //virtual void calulate_parimeter();
	// virtual void adjust_other_dimensions();

	//TwoDimensional* shps;
	TwoDimensional();
	TwoDimensional* _twoDpt;
	Triangle TriangleObject;
	Square squareObject;
	Vector vect;

	//Triangle triangleObject;
	//TwoDimensional(string);
	/*
	double area;
	double parimeter;	
	virtual void setArea(double);
	virtual void setParimeter(double);
	
	double returnArea()const;
	double returnParimeter()const;
	*/
	//void showAllData()const;
	~TwoDimensional()
	{
		cout << "in 2d destrutor";
	}
};

#endif // !TWODIMENSIONAL_H
