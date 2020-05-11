#pragma once
// Part of a final project in c++ II, this program as a whole
// will calculate the properties of 2D and 3D objects and vectors

// prgrammer:   Ryan Zurrin

#ifndef SQUARE_H
#define SQUARE_H
#include <cmath>
#include <iostream>
using namespace std;

class Square 
{
//friend class TwoDimensional;

	//these private member functions are for updating data when a user changes 
	//object data
public:
	Square* _sqrPtr;
	double	side;
	double	area;
	double	parimeter;
	//int		totalLinesInShape;
	//char	mode;
	void	calculate_area();
	void	calculate_paramiter();
	void	calculate_side_from_area();
	void	calculate_side_from_paramiter();

	Square();  // default constructor
	Square(const Square&); // copy constructor
	const Square operator=(const Square& right); //self assignment
	//const Square operator=(const TwoDimensional& right);
	//template<typename T> Square(T);  //template constructors??
	Square(double);
	void setSideLength(double);
	void setArea(double);
	void setParimeter(double);

	/*
	// temp;ate mutators so the user can put in any type number
	template<typename T> T setSideLenght(T);
	template<typename T> T setArea(T);
	template<typename T> T setParimeter(T);
	*/
	void	adjust_all();
	// data accessors 
	void showSquare()const;
	void showSideLength()const;
	void showArea()const;
	void showParimeter()const;

	double returnSquareSide()const { return side; }
	double returnSquareArea()const { return area; }
	double returSquareParimeter()const { return parimeter; }

	//overloaded relational operators
	bool operator>(const Square& s)const { return area > s.area; }
	bool operator>=(const Square& s)const { return area >= s.area; }
	bool operator<(const Square& s)const { return area < s.area; }
	bool operator<=(const Square& s)const { return area <= s.area; }
	bool operator==(const Square& s)const { return area == s.area; }
	bool operator!=(const Square& s)const { return !(area == s.area); }
	bool operator>(const double& n)const { return area > n; }
	bool operator>=(const double& n)const { return area >= n; }
	bool operator<(const double& n)const { return n < area; }
	bool operator<=(const double& n)const { return n <= area; }
	bool operator==(const double& n)const { return area == n; }
	bool operator!=(const double& n)const { return !(area == n); }

	//overloaded additon operators	
	
	Square operator+()const;
	Square operator++();
	Square operator++(int);
	Square operator+(const Square&)const;
	Square operator+(double)const;
	Square& operator+=(const Square&);
	friend Square operator+(double num, Square&);
	friend Square operator+(Square lhs, const Square&);

	// overloaded subtraction operators 
	Square operator-()const;
	Square operator--();
	Square operator--(int);
	Square operator-(const Square&)const;
	Square operator-(double)const;
	Square& operator-=(const Square&);
	friend Square operator-(double num, Square&);
	friend Square operator-(Square lhs, const Square&);

	Square operator*(double value)const;   // multiply
	
	friend Square operator*(double s, Square& v);
	friend Square operator*(Square& v, Square& s);
	Square operator/(double);    //division
	Square operator/(const Square&);

	//double& operator[]( double&);
	//Square& operator[]( Square&);
	/*
	operator double();
	operator float();
	operator int();
	operator string();
	*/

	~Square()
	{
		cout << "in the square desructor" << endl;
	}
};
#endif // !SQUARE_H

/*
//template constructor to define area of square
template<typename T>
inline Square::Square(T num)
{
	ExceptionHandler negnumchecker;
	negnumchecker.negitiveNumCheck(num);
	TwoDimensional::area = num;
	calculate_side_from_area();
	calculate_paramiter();
}


template<typename T>
inline T Square::setSideLenght(T num)
{
	ExceptionHandler negnumchecker;
	negnumchecker.negitiveNumCheck(num);
	side = num;
	adjust_all();
}

template<typename T>
inline T Square::setArea(T num)
{
	ExceptionHandler negnumchecker;
	negnumchecker.negitiveNumCheck(num);
	TwoDimensional::area = num;
	calculate_side_from_area();
	calculate_paramiter();
}

template<typename T>
inline T Square::setParimeter(T num)
{
	ExceptionHandler negnumchecker;
	negnumchecker.negitiveNumCheck(num);
	TwoDimensional::area = num;
	calculate_side_from_paramiter();
	calculate_area();
}

*/
