#pragma once
// Part of a final project in c++ II, this program as a whole
// will calculate the properties of 2D and 3D objects and vectors

// prgrammer:   Ryan Zurrin

#ifndef ALGEBRA_H
#define ALGEBRA_H
#include "Numbers.h"
//#include <viennamath/manipulation/integrate.hpp>
//#include <viennamath/expression.hpp>

class Algebra : public Numbers
{
public:
	double _x, _y, _z, _u, _a, _b, _c, _i, _j;
	Algebra():_x(0),_y(0),_z(0),_u(0),_a(0),_b(0),_c(0),_i(0),_j(0){}
	~Algebra() = default;
};


#endif
