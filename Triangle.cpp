#include "Triangle.h"
#include "exceptionHandler.h"
#include <string>
#include <algorithm>
/*______________________________________________________________________________
*/
Triangle::Triangle()
{
	_triPtr = nullptr;
	base = 0;
	height = 0;
	side_a = 0;
	side_b = 0;
	side_c = 0;
	angle_A = 0;
	angle_B = 0;
	angle_C = 0;
	area = 0;
	parameter = 0;
	sss = 0;
	aaa = 0;
	sas = 0;
	ssa = 0;
	asa = 0;
	aas = 0;
	rVal = 0;
	sVal = 0;
	/*
	cout << "in the default Triangle constructor" << endl;
	ExceptionHandler negchecker;
	double a = 0, b = 0, c = 0;
	int path = 0;
tryover:
	cout << "What information do you want to enter?\n"
		<< "1. For triangle side lengths\n"
		<< "2. For triangle angles\n"
		<< "3. For two sides and an angle\n>"
		<< "4. For base and height\n>";
	cin >> path;
	if (path == 1) {
		cout << "**please enter side a: ";
		cin >> a;
		if (a <= 0) {
			negchecker.negativeNumCheck(a);
			side_a = negchecker.negativeNumFix(a);
		}
		else
			side_a = a;

		cout << "**please enter side b: ";
		cin >> b;
		if (b <= 0) {
			negchecker.negativeNumCheck(b);
			side_b = negchecker.negativeNumFix(b);
		}
		else
			side_b = b;

		cout << "**please enter side c: ";
		cin >> c;
		if (c <= 0) {
			negchecker.negativeNumCheck(c);
			side_c = negchecker.negativeNumFix(c);
		}
		else
			side_c = c;
	}
	else if (path == 2) {
		cout << "**please enter Angle A: ";
		cin >> a;
		if (a <= 0) {
			negchecker.negativeNumCheck(a);
			angle_A = negchecker.negativeNumFix(a);
		}
		else
			angle_A = a;

		cout << "**please enter Angle B: ";
		cin >> b;
		if (b <= 0) {
			negchecker.negativeNumCheck(b);
			angle_B = negchecker.negativeNumFix(b);
		}
		else
			angle_B = b;

		cout << "**please enter Angle C: ";
		cin >> c;
		if (c <= 0) {
			negchecker.negativeNumCheck(c);
			angle_C = negchecker.negativeNumFix(c);
		}
		else
			angle_C = c;
	}
	else if (path == 3) {
		cout << "**please enter side a: ";
		cin >> a;
		if (a <= 0) {
			negchecker.negativeNumCheck(a);
			side_a = negchecker.negativeNumFix(a);
		}
		else
			side_a = a;

		cout << "**please enter side b: ";
		cin >> b;
		if (b <= 0) {
			negchecker.negativeNumCheck(b);
			side_b = negchecker.negativeNumFix(b);
		}
		else
			side_b = b;

		cout << "**please enter known angle: ";
		cin >> c;
		if (c < 0 || c > 359) {
			negchecker.negativeNumCheck(c);
			side_b = negchecker.negativeNumFix(c);
		}
		else
			side_c = c;
	}
	else if (path == 4) {
		cout << "**please enter the Base: ";
		cin >> b;
		if (a <= 0) {
			negchecker.negativeNumCheck(a);
			side_a = negchecker.negativeNumFix(a);
		}
		else
			side_b = a;

		cout << "**please enter the height: ";
		cin >> a;
		if (b <= 0) {
			negchecker.negativeNumCheck(b);
			height = negchecker.negativeNumFix(b);
		}
		else
			height = a;
	}
	else
	{
		cout << "you didn't enter a valid menu option, try again";
		goto tryover;
	}

	calculate_All_angles();
	calculate_area();
	calculate_parameter();
	calculate_rVal();
	calculate_sVal();
	triangleTypeByAngle();
	triangleTypeBySide();
	*/

}

Triangle::Triangle(double b, double h)
{
	side_b = b;
	height = h;
	calculate_area();
	calculate_All_angles();
	calculate_rVal();
	calculate_sVal();
	calculate_parameter();
}

Triangle::Triangle(double a, double b, double c)
{
		_triPtr = nullptr;
	base = 0;
	height = 0;
	side_a = a;
	side_b = b;
	side_c = c;
	angle_A = 0;
	angle_B = 0;
	angle_C = 0;
	area = 0;
	parameter = 0;
	sss = 0;
	aaa = 0;
	sas = 0;
	ssa = 0;
	asa = 0;
	aas = 0;
	rVal = 0;
	sVal = 0;
	isTriangle();
	//calculate_All_angles();

	/*

	if (isTriangle() == true) {
	
		//update_triangle();
	}
	else {
		cout << "bad triangle";
		//ExceptionHandler catcher;
	//	catcher.badTriangle(*this);			
	}
*/

}

Triangle::Triangle(double a, double b, double c, string m)
{
	if (isTriangle() == true && m == "ang" || m == "angle" || m == "a" || m == "A")
	{
		angle_A = a;
		angle_B = b;
		angle_C = c;
		update_triangle();
	}
}

Triangle::Triangle(double a)
{
	area = a;
	calculate_base();
}

Triangle::Triangle(const Triangle& t)
{
	//*this = t;
	cout << "in copy Triangle constructor";

	side_a = t.side_a;
	side_b = t.side_b;
	side_c = t.side_c;
	angle_A = t.angle_A;
	angle_B = t.angle_B;
	angle_C = t.angle_C;
	parameter = t.parameter;
	height = t.height;


	calculate_All_angles();
	calculate_parameter();
	calculate_sVal();
	calculate_rVal();
	calculate_area();
	calculate_height();

	update_triangle();

	//return *this;
}


const Triangle Triangle::operator=(const Triangle& right)
{
	Triangle temp;
	cout << "in the overloaded Triangle =operator";
	if (this != &right) {
		//delete this;
		temp.side_a = right.side_a;
		temp.side_b = right.side_b;
		temp.side_c = right.side_c;
		temp.update_triangle();

		return temp;
	}
	return *this;
}

Triangle Triangle::make2rights()
{
	return Triangle();
}
/*______________________________________________________________________________
*/

void Triangle::update_triangle()
{
	//calculate_All_sides();
	//calculate_All_angles();	
	solve_by_SSS();
	calculate_parameter();
	calculate_sVal();
	calculate_area();
	calculate_rVal();
	calculate_height();
	triangleTypeByAngle();
	triangleTypeBySide();
	//checkCongruent();
	check_AAA(*this);
	check_SAS(*this);
	check_SSS(*this);
}

void Triangle::calculate_angleA()
{
	angle_A = (180 / PI) * asin(side_a / (2 * rVal));
}

void Triangle::calculate_angleB()
{
	angle_B = (180 / PI) * asin(side_b / (2 * rVal));
}

void Triangle::calculate_angleC()
{
	angle_C = (180 / PI) * asin(side_c / (2 * rVal));
}

void Triangle::calculate_All_angles()
{
	calculate_angleA();
	calculate_angleB();
	calculate_angleC();
}

void Triangle::calculate_All_sides()
{
	calculate_sideA();
	calculate_sideB();
	calculate_sideC();
}

void Triangle::calculate_height()
{
	height = area / 2;	
}

void Triangle::calculate_sideA()
{

}

void Triangle::calculate_sideB()
{
}

void Triangle::calculate_sideC()
{
}
void Triangle::calculate_base()
{

}
void Triangle::calculate_area()
{
	area = sqrt(sVal * (sVal - side_a) * (sVal - side_b) * (sVal - side_c));
}
void Triangle::calculate_parameter()
{
	parameter = side_a + side_b + side_c;
}
void Triangle::calculate_rVal()
{
	rVal = (side_a * side_b * side_c) / (4 * area);
}
void Triangle::calculate_sVal()
{
	sVal = parameter / 2;
}
void Triangle::solve_by_AAA()
{
	cout << "need at least one side as well,\n"
		 << "shape known but size undeterminable" << endl;
}
void Triangle::solve_by_AAS()
{
	cout << "stub call to solve by AAS" << endl;
}
void Triangle::solve_by_ASA()
{
	cout << "stub call to solve by ASA" << endl;
}
void Triangle::solve_by_SAS()
{
	cout << "stub call to solve by SAS" << endl;
}
void Triangle::solve_by_SSA()
{

}
void Triangle::solve_by_SSS() //law of cosines to solve angle C
{							 // law of sines to sovle angle B
	double a=0, b=0, c=0, A=0, B=0, C=0;
	double alpha = 0.0;
	double betta = 0.0;
	double gamma = 0.0;
	a = sqrt(side_a);
	b = sqrt(side_b);
	c = sqrt(side_c);
	alpha = acos((side_b + side_c - side_a) / (2 * b * c))*DEGREE;
	betta = acos((side_a + side_c - side_b) / (2 * a * c)) * DEGREE;
	gamma = acos((side_a + side_b - side_c) / (2 * a * b)) * DEGREE;
	angle_A = alpha;
	angle_B = betta;
	angle_C = gamma;

	
	
}


void Triangle::check_SSS(Triangle& t)
{

	double s1[] = { side_a, side_b, side_c };
	double s2[] = { t.side_a, t.side_b, t.side_c };

	double a1[] = { angle_A, angle_B, angle_C };
	double a2[] = { t.angle_A, t.angle_B, t.angle_C };
	// Function for SSS similarity 
	//double simi_sss(double s1[], double s2[]);


	sort(s1, s1 + 3);
	sort(s2, s2 + 3);

	// Check for SSS 
	if (s1[0] / s2[0] == s1[1] / s2[1] &&
		s1[1] / s2[1] == s1[2] / s2[2] &&
		s1[2] / s2[2] == s1[0] / s2[0])
		sss = 1;

	sss = 0;

}
void Triangle::check_SAS(Triangle& t)
{// Function for SAS similarity

	double s1[] = { side_a, side_b, side_c };
	double s2[] = { t.side_a, t.side_b, t.side_c };

	double a1[] = { angle_A, angle_B, angle_C };
	double a2[] = { t.angle_A, t.angle_B, t.angle_C };

	sort(a1, a1 + 3);
	sort(a2, a2 + 3);
	sort(s1, s1 + 3);
	sort(s2, s2 + 3);

	// Check for SAS 

	// angle b / w two smallest 
	// sides is largest. 
	if (s1[0] / s2[0] == s1[1] / s2[1])
	{
		if (a1[2] == a2[2])
			sas = 1;
	}
	if (s1[1] / s2[1] == s1[2] / s2[2])
	{
		if (a1[0] == a2[0])
			sas = 1;
	}
	if (s1[2] / s2[2] == s1[0] / s2[0])
	{
		if (a1[1] == a2[1])
			sas = 1;
	}
	sas = 0;
}

void Triangle::check_AAA(Triangle& t)
{

	double s1[] = { side_a, side_b, side_c };
	double s2[] = { t.side_a, t.side_b, t.side_c };

	double a1[] = { angle_A, angle_B, angle_C };
	double a2[] = { t.angle_A, t.angle_B, t.angle_C };


	sort(a1, a1 + 3);
	sort(a2, a2 + 3);

	// Check for AAA 
	if (a1[0] == a2[0] &&
		a1[1] == a2[1] &&
		a1[2] == a2[2])
		aaa = 1;
	else
		aaa = 0;
}
/*______________________________________________________________________________
*/



bool Triangle::isTriangle()
{
	if (
		side_a + side_b > side_c &&
		side_c + side_b > side_a &&
		side_a + side_c > side_b
		)
		return true;
	else
		return false;
}

bool Triangle::checkCongruent(Triangle T)
{
	check_AAA(T);
	check_SAS(T);
	check_SSS(T);
	if (sss == true ||
		sas == true ||
		sss == true
		)
		return true;

	return false;

}
void Triangle::congruentBy()
{
	cout << "Triangles are "
		<< "similar by ";
	if (aaa == 1) cout << "AAA ";
	if (sss == 1) cout << "SSS ";
	if (sas == 1) cout << "SAS.";
}

void Triangle::triangleTypeBySide()
{
	if (!isTriangle()) {
		//cout << "Not a valid triangle" << endl;
		sideType = "invalid";
	}
	else {
		if (side_a == side_b && side_b == side_c) {
			//cout << "Equilateral" << endl;
			sideType = "Equilateral";
		}
		else if (side_a == side_b || side_b == side_c || side_c == side_a) {
			//cout << "Isosceles" << endl;
			sideType = "Isosceles";
		}
		else {
			//cout << "scalene" << endl;
			sideType = "Scalene";
		}

	}
}

void Triangle::triangleTypeByAngle()
{
	double longest, a, b, c;
	a = side_a;
	b = side_b;
	c = side_c;

	if (!isTriangle()) {
		//cout << "Not a valid triangle" << endl;
		//throw ExceptionHandler.
		angleType = "invalid";
	}
	else {
		longest = c;
		if (longest < side_a) {
			side_c = longest;
			longest = side_a;
			side_a = side_c;
		}
		if (longest < side_b) {
			side_c = longest;
			longest = side_b;
			side_b = side_c;
		}
		if (side_a * side_a + side_b * side_b == longest * longest) {
			//cout << "This is a right-angled triangle.\n";
			angleType = "Right";
		}
		else if (side_a * side_a + side_b * side_b > longest * longest) {
			//cout << "This is an acute-angled triangle.\n";
			angleType = "Acute";
		}
		else
			//cout << "This is an obtuse-angled triangle.\n";
			angleType = "Obtuse";
	}
}


void Triangle::showTriangle() const
{
	showTriangleSides();
	showTriangleAngles();
	showAngleType();
}

void Triangle::showTriangleSides() const
{
	showSide_a();
	showSide_b();
	showSide_c();
}

void Triangle::showTriangleAngles() const
{
	showAngle_A();
	showAngle_B();
	showAngle_C();

}
void Triangle::showAngleType() const
{
	cout << "type: " << angleType << "  " << sideType << endl;
}
void Triangle::setSides(double _a, double _b, double _c)
{
		side_a = _a;
		side_b = _b;
		side_c = _c;
		if (isTriangle() == true) {
			update_triangle();
		}
		else {
			ExceptionHandler t;
			t.badTriangle(this);
		}
			

	
	

}
void Triangle::setAngles(double aA, double aB, double aC)
{
	
	
		angle_A = aA;
		angle_B = aB;
		angle_C = aC;
	
	//update_triangle();
}
/*______________________________________________________________________________
											   overloaded addition opperators*/
Triangle Triangle::operator+() const
{
	return Triangle();
}

Triangle Triangle::operator++()
{
	return Triangle();
}

Triangle Triangle::operator++(int)
{
	return Triangle();
}

Triangle Triangle::operator+(const Triangle&) const
{
	return Triangle();
}

Triangle Triangle::operator+(double) const
{
	return Triangle();
}

Triangle& Triangle::operator+=(const Triangle& rhs)
{
	side_a += rhs.side_a;
	side_b += rhs.side_b;
	side_c += rhs.side_c;
	calculate_All_angles();
	return *this;
}
Triangle operator+(double num, Triangle&)
{
	return Triangle();
}

Triangle operator+(Triangle lhs, const Triangle&)
{
	return Triangle();
}



/*______________________________________________________________________________
											overloaded subtraction opperators*/

Triangle Triangle::operator-() const
{
	return Triangle();
}

Triangle Triangle::operator--()
{
	return Triangle();
}

Triangle Triangle::operator--(int)
{
	return Triangle();
}

Triangle Triangle::operator-(const Triangle&) const
{
	return Triangle();
}

Triangle Triangle::operator-(double) const
{
	return Triangle();
}

Triangle& Triangle::operator-=(const Triangle& rhs)
{
	side_a -= rhs.side_a;
	side_b -= rhs.side_b;
	side_c -= rhs.side_c;
	calculate_All_angles();
	return *this;
}

Triangle operator-(double num, Triangle&)
{
	return Triangle();
}

Triangle operator-(Triangle lhs, const Triangle&)
{
	return Triangle();
}

/*______________________________________________________________________________
												overloaded division opperators*/
Triangle Triangle::operator/(double d)
{
	return Triangle();
}

Triangle Triangle::operator/(const Triangle& t)
{
	return Triangle(side_a / t.side_a, side_b / t.side_b, side_c / t.side_c);
}

/*______________________________________________________________________________
										 overloaded multiplication opperators*/

Triangle Triangle::operator*(double t) const
{
	return Triangle(side_a * t, side_b * t, side_c * t);
}

Triangle operator*(double s, Triangle& t)
{
	return Triangle(t.side_a * s, t.side_b * s, t.side_c * s);
}

Triangle operator*(Triangle& v, Triangle& s)
{
	Triangle results(v.side_a * s.side_a, v.side_b * s.side_b, v.side_c * s.side_c);

	return results;

}
/*______________________________________________________________________________
										 overloaded conversion opperators*/
/*
Triangle::operator float()
{
	float temp = area;
	return temp;
}

Triangle::operator double()
{
	double temp = area;
	return temp;
}

Triangle::operator int()
{
	area = round(area);
	int temp = area;
	return temp;
}

Triangle::operator string()
{
	string temp = to_string(area);
	return temp;
}
*/
