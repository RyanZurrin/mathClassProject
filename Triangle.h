#pragma once
// Part of a final project in c++ II, this program as a whole
// will calculate the properties of 2D and 3D objects and vectors

// prgrammer:   Ryan Zurrin

#ifndef  TRIANGLE_H
#define  TRIANGLE_H
#include <cmath>
#include <string>
#include <utility>
#include <iostream>

using namespace std;

class Triangle
{
	//friend class ExceptionHandler;
private:
	//double sVal;
	//double rVal;

	void calculate_angleA();
	void calculate_angleB();
	void calculate_angleC();
	void calculate_All_angles();
	void calculate_All_sides();
	void calculate_height();
	void calculate_sideA();
	void calculate_sideB();
	void calculate_sideC();
	void calculate_base();
	void calculate_area();
	void calculate_parameter();
	void calculate_rVal();
	void calculate_sVal();
	void solve_by_AAA(); // three sides known
	void solve_by_AAS(); // two angles and a side not between
	void solve_by_ASA(); // two angles and a side bewteen them
	void solve_by_SAS(); // two sides and the included angle.
	void solve_by_SSA(); //  two sides and one angle that is not the included angle
	void solve_by_SSS(); //  all three sides of a triangle, but no angles

public:
	Triangle* _triPtr;
	double base;
	double height;
	double side_a;
	double side_b;
	double side_c;
	double angle_A;
	double angle_B;
	double angle_C;
	double area;
	double parameter;
	double sVal;// same as height. need to remove and refactor as my caculations rely on this val
	double rVal;
	bool   sss, aaa, sas, ssa, asa, aas;
	
	string sideType;
	string angleType;
	
	string mode;  // to tell program if your sending sides or angles 
	void update_triangle();
	//ExceptionHandler catcher;
	struct TriangleAsCartesianPoints
	{
		pair<double, double> pt1;
		pair<double, double> pt2;
		pair<double, double> pt3;
	};

	Triangle();
	Triangle(double base, double height); // constructs an equallatteral triangle
	Triangle(double a, double b, double c); // constructs a triangle with given sides and computs all angles
	Triangle(double a, double b, double c, string m); // 
	Triangle(double area);
	Triangle(const Triangle&); // copy constructor
	Triangle make2rights(); // makes two 90 degree triangles by modifiying itself and returning the other part to new object.
	const Triangle operator=(const Triangle& right); //self assignment

	void check_SSS(Triangle&);// by Arnab Kundu 
	void check_SAS(Triangle&);
	void check_AAA(Triangle&);

	bool isTriangle();
	void triangleTypeBySide();
	void triangleTypeByAngle();
	bool checkCongruent(Triangle T);
	void congruentBy();

	void showTriangle()const;
	void showTriangleSides()const;
	void showTriangleAngles()const;
	void showAngleType()const;
	void showSide_a()const { cout << "side a: " << side_a<< endl; }
	void showSide_b()const { cout << "side b: " << side_b << endl; }
	void showSide_c()const { cout << "side c: " << side_c << endl; }
	void showAngle_A()const { cout << "angle A: " << angle_A << endl; }
	void showAngle_B()const { cout << "angle B: " << angle_B << endl; }
	void showAngle_C()const { cout << "angle C: " << angle_C << endl; }

	double returnSide_a()const { return side_a; }
	double returnSide_b()const { return side_b; }
	double returnSide_c()const { return side_c; }
	double returnAngle_A()const { return angle_A; }
	double returnAngle_B()const { return angle_B; }
	double returnAngle_C()const { return angle_C; }
	bool returnSAS()const { return sas; }
	bool returnSSS() const { return sss; }
	bool returnAAA() const { return aaa; }

	double setSide_a(double _a) { side_a = _a; update_triangle(); }
	double setSide_b(double _b) { side_b = _b; update_triangle(); }
	double setSide_c(double _c) { side_c = _c; update_triangle(); }
	void	 setSides(double, double, double);
	void	 setAngles(double, double, double);
	//double setAngle_A(double _A) { angle_A = _A; update_triangle(); }
	//double setAngle_B(double _B) { angle_B = _B; update_triangle(); }
	//double setAngle_C(double _C) { angle_C = _C; update_triangle(); }
	//double setTriangleArea(double tA) { area = tA; update_triangle(); }


	//overloaded relational operators
	bool operator>(const Triangle& s)const { return area > s.area; }
	bool operator>=(const Triangle& s)const { return area >= s.area; }
	bool operator<(const Triangle& s)const { return area < s.area; }
	bool operator<=(const Triangle& s)const { return area <= s.area; }
	bool operator==(const Triangle& s)const { return area == s.area; }
	bool operator!=(const Triangle& s)const { return !(area == s.area); }
	bool operator>(const double& n)const { return area > n; }
	bool operator>=(const double& n)const { return area >= n; }
	bool operator<(const double& n)const { return n < area; }
	bool operator<=(const double& n)const { return n <= area; }
	bool operator==(const double& n)const { return area == n; }
	bool operator!=(const double& n)const { return !(area == n); }

	//overloaded additon operators	

	Triangle operator+()const;
	Triangle operator++();
	Triangle operator++(int);
	Triangle operator+(const Triangle&)const;
	Triangle operator+(double)const;
	Triangle& operator+=(const Triangle&);
	friend Triangle operator+(double num, Triangle&);
	friend Triangle operator+(Triangle lhs, const Triangle&);

	// overloaded subtraction operators 
	Triangle operator-()const;
	Triangle operator--();
	Triangle operator--(int);
	Triangle operator-(const Triangle&)const;
	Triangle operator-(double)const;
	Triangle& operator-=(const Triangle&);
	friend Triangle operator-(double num, Triangle&);
	friend Triangle operator-(Triangle lhs, const Triangle&);

	Triangle operator*(double value)const;   // multiply

	friend Triangle operator*(double s, Triangle& v);
	friend Triangle operator*(Triangle& v, Triangle& s);
	Triangle operator/(double);    //division
	Triangle operator/(const Triangle&);
	
	/*
	operator float();
	operator double();
	operator int();
	operator string();
	*/

	~Triangle()
	{
		cout << "in the triangle destructor";
		//delete this;
	}



};

#endif // ! TRIANGLE_H