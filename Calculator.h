#pragma once
#ifndef CALCULATOR_H
#define CALCULATOR_H
#include <complex>
#include <list>
#include "Numbers.h"
#include "Square.h"
#include <iostream>
using namespace std;


class Calculator// : public Numbers
{
public:
	Calculator();
	Square* sqpt;
	double basicMathOperation(double x, char op, double y);
	Square *squareMathOperation(Square &x, char op0, Square &y);
	~Calculator()
	{
		cout << "in calculator destructor";
		delete this;
	}
};

#endif // !CALCULATOR_H
