// author:			Ryan Zurrin
// file:   		  vect.cpp (XL)

// Implementation for Vector class.

#include "vect.h"

#include <cassert>

#include "exceptionHandler.h"

using namespace std;
int Vector::object_counter = 0;
Vector::Vector()
{
  vptr2d = nullptr;
  x = 0;
  y = 0;
  magnitude = 0.0;
  angle = 0.0;
  calculate_arcLength();
  arcLength = 0.0;
  revolutionAngle_inDegrees = 0.0;
  mode = 'r';
  validate_setMode();

  object_counter++;
  //cout<< object_counter << ": " <<"in the default constructor" <<endl;
}

Vector::Vector(char _mode)
{
	vptr2d = nullptr;
	x = 0;
	y = 0;
	magnitude = 0;
	angle = 0;
	calculate_arcLength();
	arcLength = return_angle();
	revolutionAngle_inDegrees = 0;
	mode = _mode;
	validate_setMode();
	object_counter++;
	//cout<< object_counter << ": " <<"in the char constructor"<<endl;;
}
/*______________________________________________________________________________
  the third argument is the mode setting.
  Use 'r'/'R' for rectangular components, 'p'/'P' for polar components
*/
Vector::Vector(double xMag, double yAng, char _mode)
{

  mode = _mode;
  set_coordinates(xMag, yAng, _mode);
  object_counter++;
	//cout<< object_counter << ": " <<"in the select and set constructor"<<endl;
}
Vector::Vector(const Vector &v)
{

	x=v.x;
	y=v.y;
	mode = v.mode;
	calculate_polar();
	object_counter++;
	//cout<< object_counter << ": " <<"in the copy constructor"<<endl;
}
void Vector::showAllData()const
{

  showRectCord();
  showPolarCord();
  showRevolutionAngle();
 // show_mode();
  show_arcLength();
}
void Vector::showVector()const
{
  if (mode == 'r' || mode == 'R') {
   showRectCord();
   show_arcLength();
  }
  else {
   showPolarCord();
   show_arcLength();
  }
}
void Vector::showRectCord()const
{
	 cout << setprecision(5) << fixed;

	 cout << "\n(x,y) = ";
	 if(x < 0 && x > -1 ){
		 cout << setiosflags(ios::fixed);
	 cout << fixed << "(" << x << ","
		 << resetiosflags(ios::fixed);
   }
	 else{
	 cout << "(" << x << ",";
   }
   if(y<0 && y>-1){
	   cout << setiosflags(ios::fixed);
	   cout << y << ")" <<endl;
		 cout << resetiosflags(ios::fixed);
	 }
	 else{
		cout << y << ")";
	 }
}
void Vector::showPolarCord()const
{
	cout << setprecision(5) << fixed;
	 if(magnitude < 0 || angle < 0){
		cout << setiosflags(ios::fixed);
		cout << "\n<r,\xE9> = <" << magnitude << "," << angle * RADIAN << ">";
		cout << resetiosflags(ios::fixed) << endl;
	 }
	 else{
		 cout << "\n<r,\xE9> = <" << magnitude << "," << angle * RADIAN << ">";
		}
}
void Vector::showRevolutionAngle()const
{
  double temp = 0;
  cout << "Angle in degrees:  " << revolutionAngle_inDegrees;

   //cout << "full revolutions:    "
	// 			<< static_cast<int>(revolutionAngle_inDegrees/360) << endl;
 //  if(revolutionAngle_inDegrees < 0){
   //cout << "additional degrees:  " << (360 - angle)*(-1) << endl;
   //}
   //else
		// cout << "additional degrees:  " << angle << endl;
}
void Vector::show_x() const
{
	cout << "\nx: " << x << endl;
}

void Vector::show_y() const
{
	cout << "\ny: " << y << endl;
}

void Vector::show_mag() const
{
	cout << "\nr: " << magnitude << endl;
}

void Vector::show_angle() const
{
	cout << "\n\xE9: " << angle << "\xF8" << endl;
}

void Vector::show_mode()const
{
	if (mode == 'p' || mode == 'P') {
		cout << "\nmode: Polar" << endl;
	}
	else
		cout << "\nmode: Rectangular" << endl;
}

void Vector::show_arcLength() const
{
   cout << setprecision(7)<< fixed;
	cout << "\narc length: " << arcLength << endl;
}


/*
void Vector::showPolarCurve()const{
  cout << "\ncartiasian equation of curve is: ";
  cout << "r: " << Curve.r << "  " << "theta: " << Curve.theta << endl;
  cout << "x: " << Curve.x << "  " << "y: " << Curve.y << endl;
}
*/

	/*______________________________________________________________________________
returnX, no arguments or 'r'/'R' will just return, anything else will print out
				 and return.
*/

double Vector::return_x() const
{
	return x;
}
double Vector::return_y()const
{
	return y;
}
double Vector::return_mag()const
{
	return magnitude;
}
double Vector::return_angle()const
{
	return angle;
}
double Vector::return_arcLength() const
{
	return arcLength;
}
char Vector::return_mode()const
{
  return mode;
}


/*______________________________________________________________________________
  the third argument is the mode setting.
  Use 'r'/'R' for rectangular components, 'p'/'P' for polar components
*/
void Vector::set_coordinates(double xMag, double yAng, char _mode)
{
  validate_setMode();

  if (tolower(_mode) ==  'r') {
	set_rectCord(xMag, yAng);
	adjust_angle();
  }
  else{
	  set_polarCord(xMag, yAng);
	  adjust_angle();
  }
  calculate_arcLength();
}
void Vector::set_rectCord(double _x, double _y)
{
  x = _x;
  y = _y;
  calculate_polar();
  revolutionAngle_inDegrees = angle;
}

void Vector::set_polarCord(double mag, double ang)
{
  magnitude = mag;
  normalize_magnitude();
  angle =ang;
  revolutionAngle_inDegrees = ang;
  adjust_angle();
  calculate_rectangular();
}
void Vector::set_x(double _x)
{
  x = _x;
  calculate_polar();
}
void Vector::set_y(double _y)
{
  y = _y;
  calculate_polar();
}
void Vector::set_mag(double mag)
{
  magnitude = mag;
  normalize_magnitude();
  calculate_rectangular();
  calculate_arcLength();
}
void Vector::set_angle(double ang)
{
  angle = ang;
  adjust_angle();
  calculate_arcLength();
  calculate_rectangular();
}
void Vector::set_mode(char _mode)
{
  mode = _mode;
  validate_setMode();
}
double Vector::square()
{
	return  x * x + y * y;
}
double Vector::dot_product(const Vector& vec)
{
	return  x * vec.x + vec.y * y;
}
double Vector::distance(const Vector& vec)
{
	double x1, x2, y1, y2, t1, t2;
	x1 = this->x;
	x2 = vec.x;
	y1 = this->y;
	y2 = vec.y;
	t1 = x2 - x1;
	t2 = y2 - y1;
	return sqrt(pow(t1, 2) + pow(t2, 2));
}
double Vector::cross_product2D(const Vector& v)
{
	return (x * v.y) - (y * v.x);
}
Vector Vector::normalization()
{
	assert(find_magnitude() != 0);
	*this /= find_magnitude();
	return *this;
}
double Vector::find_magnitude()
{
	return sqrt(square());
}
/*
void Vector::setPolarCurve()
{
	cout << "\nEnter the Polar Curve to convert to cartiesian equation\n>";
	cin >> Curve.r;
  Curve.x = sqrt(pow(Curve.r, 2) + pow(Curve.y, 2));
  Curve.theta = atan(y / x);
}
*/
void Vector::validate_setMode()
{
	do{
		  if (tolower(mode) == 'r' || tolower(mode) == 'p') {
	   break;
		  }
			else {
		cout << "\nEnter a valid mode, r/R for rectangular\n"
			 << "or p/P or polar components\n>";
		cin >> mode;
		cin.clear();
		cin.ignore(100, '\n');
			 }
  }while(!cin || tolower(mode) != 'r' || tolower(mode) != 'p');
}
void Vector::normalize_magnitude()
{
  if (magnitude < 0)
	magnitude = abs(magnitude);
}
void Vector::calculate_magnitude()
{
   magnitude = sqrt(x * x + y * y);
}
void Vector::calculate_angle()
{
	angle = atan2(y, x) * DEGREE;
}
void Vector::adjust_angle()
{
  if(angle == -360 || angle == -720 || angle == -1080 || angle == -1440){
	angle = 0;
  }
	if (angle >= 360){
		const int rev_degrees = static_cast<int>(angle) / 360;
		const int to_subtract = rev_degrees *360;
		const double new_angle = angle - to_subtract;
		angle = new_angle;
	}else if (angle < 0 && angle > -360){
		angle += 360;
		cout <<"test:" << angle << endl;
	}else if(angle < -360){
		const int rev_degrees = static_cast<int>(angle) /360;
		const int to_subtract = rev_degrees *360;
		const double newAngle = angle - to_subtract + 360;
		angle = newAngle;
	}
}
void Vector::calculate_rectangular()
{
  x = magnitude* cos(angle*RADIAN);
  y = magnitude* sin(angle*RADIAN);
}
void Vector::calculate_polar()
{
	 magnitude = sqrt(x * x + y * y);
	if (x == 0.0 && y == 0.0)
		angle = 0.0;
	else
		angle = atan2(y, x)*DEGREE;

	adjust_angle();
	calculate_arcLength();
	revolutionAngle_inDegrees = angle;
}
void Vector::calculate_arcLength()
{
  adjust_angle();
  arcLength = (PI * (magnitude*2)) *
		(angle / 360.0);
}
Vector Vector::check_division(double d)
{
	cout << "in 2dmemberFunction/check division double\n";
	Vector temp;
	ExceptionHandler checker;
	if (checker.zeroDivisorCheck(d) == 0 && checker.checkedFlag == false) {
		checker.checkedFlag = true;
		temp.set_coordinates(x / d, y / d, 'r');
		calculate_polar();
		calculate_angle();
		return temp;
	}
	else if (checker.zeroDivisorCheck(d) != 0 && checker.checkedFlag == false) {
		d = checker.zeroDivideFix(d);
		checker.checkedFlag = true;
		temp.set_coordinates(x / d, y / d, 'r');
		calculate_polar();
		calculate_angle();
		return temp;
	}
	return *this;
}


Vector Vector::check_division(Vector d)
{
	cout << "in 2dmemberFunction/check division Vector\n";
	Vector temp;
	ExceptionHandler checker;
	if (checker.zeroDivisorCheck(d) == false ) {// && checker.checkedFlag == false
		checker.checkedFlag = true;
		temp.set_coordinates(x / d.x, y / d.y, 'r');
		calculate_polar();
		calculate_angle();
		return temp;
	}
	else if (checker.zeroDivisorCheck(d) != 0 && checker.checkedFlag == false) {
		d.magnitude = checker.zeroDivideFix(d.magnitude);
		checker.checkedFlag = true;
		temp.set_coordinates(x / d.x, y / d.y,'r');
		calculate_polar();
		calculate_angle();
		return temp;
	}
	return temp;
}
/*
Vector Vector::calculate_parallel_vector2d(Vector & v1, Vector & v2)
{
  cout << "in Calc Parallel vec2d: " << endl;
  return Vector(v2.x - v1.x, v2.y - v1.y);
}
*/
bool Vector::operator<(const Vector &v) const
{
  if (magnitude < v.magnitude)
	return true;
  return false;
}
bool Vector::operator<=(const Vector& v) const
{
	if (magnitude <= v.magnitude)
		return true;
	return false;
}
bool Vector::operator>(const Vector & v)const
{
  if (magnitude > v.magnitude)
	return true;
  return false;
}
bool Vector::operator>=(const Vector& v) const
{
	if (magnitude >= v.magnitude)
		return true;
	return false;
}
bool Vector::operator==(const Vector & v)const
{
  if (magnitude == v.magnitude && angle == v.angle)
	return true;
  return false;
}

bool Vector::operator!=(const Vector& v) const
{
	if (!(magnitude == v.magnitude && angle == v.angle))
		return true;
	else
		return false;
}

Vector Vector::operator+(const double n)const
{
	//cout << "in  Vector::operator+(const double n)const"<<endl;
	Vector total(x + n, y + n);
	total.mode = mode;
	return total;
}
Vector& Vector::operator+=(const Vector& v)
{
	//cout << "in Vector& Vector::operator+=(const Vector& v)" << endl;
	Vector sum;
	sum.x += v.x;
	sum.y += v.y;
	sum.mode = v.mode;
	return *this;
}
Vector Vector::operator+(const Vector& v)const
{
  //cout << "in  Vector::operator+(const Vector& v)const"<<endl;
  Vector sum(x + v.x, y + v.y);
  sum.mode = mode;
  return sum;
}

Vector Vector::operator+()const
{
	//cout << "in  Vector::operator+()const"<<endl;
	Vector total(x+x, y+y);
	total.mode = mode;
  return total;
}
Vector Vector::operator++()
{
	Vector sum(++x, ++y);
	sum.mode = mode;
  return sum;
}
Vector Vector::operator++(int)
{
  Vector sum(x++, y++, mode);
  return sum;
}
Vector Vector::operator-(const Vector& v)
{
  Vector sum(x-v.x, y-v.y, mode);
  return sum;
}
Vector Vector::operator-(const double number)const
{
	Vector total(x - number, y - number);
	total.mode = mode;
	return total;
}
Vector Vector::operator-()const
{
	Vector total(-x, -y);
	total.mode = mode;
  return total;
}
Vector Vector::operator--()
{
  Vector difference(--x, --y);
  difference.mode = mode;
  return difference;
}
Vector Vector::operator--(int)
{
  Vector difference(x--, y--);
  difference.mode = mode;
  return difference;
}
Vector operator-(double s, Vector& v)
{
 Vector total(s-v.return_x(),s-v.return_y(),v.return_mode());
 return total;
}
Vector operator+(double s, Vector& v)
{
 Vector total(s+v.return_x(),s+v.return_y(),v.return_mode());
 return total;
}
const Vector Vector::operator=(const Vector &right)
{
  if (this != &right) {

		x = right.x;
		y = right.y;
		calculate_polar();
		calculate_arcLength();
	}
  return *this;
}
Vector &Vector::operator=(const Vector *vec)
{
  x = vec->x;
  y = vec->y;
  calculate_polar();
  calculate_arcLength();
  return *this;
}
Vector& Vector::operator=(Vector&& right)noexcept
{
	 if (this != &right)
	 {
		 swap(x, right.x);
		 swap(y, right.y);
		 this->calculate_polar();
	 }
	 return *this;
}
Vector::Vector(Vector&& temp) noexcept
{
	x = temp.x;
	y = temp.y;
	mode = temp.mode;
	calculate_polar();
	calculate_arcLength();
	revolutionAngle_inDegrees = return_angle();
	angle = return_angle();
	magnitude = return_mag();
	arcLength = return_arcLength();
	calculate_arcLength();
}
Vector Vector::operator/(double d)
{
	return check_division(d);
}

Vector Vector::operator/(int d)
{
	return check_division(d);
}
Vector Vector::operator/(Vector v)
{
	return check_division(v);
}
Vector &Vector::operator/=(double value)
{
	cout << "in 2D operator/= double value\n";
	ExceptionHandler checker;
	checker.zeroDivisorCheck(value);
	x /= value;
	y /= value;
	calculate_polar();
	calculate_angle();
	return *this;

}
Vector Vector::operator*(const double scalar)const
{
	Vector results(x*scalar, y*scalar);
	results.mode = mode;
	return results;
}
Vector operator*(double s, Vector& v)
{
  return v * s;
}
Vector operator*(Vector& v, Vector& s)
{
   Vector results(v.x*s.x, v.y*s.y, v.mode);
   return results;
}
ostream& operator<<(ostream& os, const Vector& v)
{
  if(v.mode == 'R' || v.mode == 'r'){
	v.showRectCord();
  }
  else{
	v.showPolarCord();
  }
  return os;
}
istream& operator>>(istream& is, Vector& v)
{
  if(v.mode == 'R' || v.mode == 'r'){
	is>> v.x >> v.y;
	v.calculate_polar();
  }
  else{
	is>> v.magnitude >> v.angle;
	v.calculate_rectangular();
  }
  return is;
}

Vector::~Vector()
{
	--object_counter;
	cout << "In Vector destructor : "<< object_counter << " objects remain\n"
			 << endl;
}

