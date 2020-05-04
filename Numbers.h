#pragma once
#ifndef NUMBERS_H
#define NUMBERS_H
#include <complex>
#include <cmath>
#include <list>
#include <map>
#include <iostream>
#include <iomanip>
#include <cassert>
#include "Eigan/Eigen/Core"

using namespace std;

typedef long double ld;

const ld PI = 3.1415926535898;
const ld DEGREE = 180 / PI;
const ld RADIAN = PI / 180;

class Numbers 

{
public:
	bool sqrt_2(ld);
	map<ld, string> realNumTranslation;
	void addNumTranslation(ld);
	void checkForNumTranslation(const ld)const;
};

#endif