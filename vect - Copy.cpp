// author:			Ryan Zurrin
// file:   		  vect.cpp (XL)

// Implementation for Vector class.

#include "vect.h"   
//#include "Vector3D.h"
using namespace std;
int Vector::object_counter = 0;
Vector::Vector()
{
	x = 0;
  y = 0;  
  magnitude = 0;
  angle = 0;
  revolutionAngle_inDegrees = 0;
  mode = 'r';
  //validate_setMode();  
	object_counter++;
	cout<< object_counter << ": " <<"in the default constructor" <<endl;
}
Vector::Vector(char _mode)
{	  
  x = 0;
  y = 0;  
  magnitude = 0;
  angle = 0;
  revolutionAngle_inDegrees = 0;
  mode = _mode;
  validate_setMode();
  object_counter++;
	cout<< object_counter << ": " <<"in the char constructor"<<endl;;
}
/*______________________________________________________________________________ 
  the third argument is the Mode setting. 
  Use 'r'/'R' for rectangular components, 'p'/'P' for polar components
*/ 
Vector::Vector(ld xMag, ld yAng, char _mode)
{  
	mode = _mode;
  setCoordinates(xMag, yAng, _mode);
  object_counter++;
	cout<< object_counter << ": " <<"in the select and set constructor"<<endl;
}
Vector::Vector(const Vector &v)
{
    x=v.x;
    y=v.y;
    calculate_polar();
    object_counter++;
	cout<< object_counter << ": " <<"in the copy constructor"<<endl;
}
void Vector::showAllData()const
{   
  showRectCord();
  showPolarCord();
  showRevolutionAngle();
  returnMode('p');
  returnArcLength('p');
}
void Vector::showVector()const
{
  if (mode == 'r' || mode == 'R') {
   showRectCord();
   returnArcLength('p');
  }
  else {
   showPolarCord();
   returnArcLength('p');
  }      
}
void Vector::showRectCord()const
{  
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
		 cout << resetiosflags(ios::fixed) << endl;  
	 }
	 else{
	 	cout << y << ")" <<endl;
	 }
}
void Vector::showPolarCord()const
{  
	 if(magnitude < 0 || angle < 0){
	 cout << setiosflags(ios::fixed);
   cout << "\n<r,\xE9> = <" << magnitude << "," << angle << "\xF8>" 
         << endl;
   cout << resetiosflags(ios::fixed) << endl;  
 	 }
 	 else{
 	 	cout << "\n<r,\xE9> = <" << magnitude << "," << angle << "\xF8>" 
         << endl;
		}
}
void Vector::showRevolutionAngle()const
{    
  ld temp = 0;
   cout << "\nrevolution degrees:  " << revolutionAngle_inDegrees
         << endl;    
   cout << "full revolutions:    " 
	 			<< static_cast<int>(revolutionAngle_inDegrees/360) << endl;
   if(revolutionAngle_inDegrees < 0){
   cout << "additional degrees:  " << (360 - angle)*(-1) << endl;
   }
   else
   		 cout << "additional degrees:  " << angle << endl; 	
}
void Vector::showPolarCurve()const{
  cout << "\ncartiasian equation of curve is: ";
  cout << "r: " << Curve.r << "  " << "theta: " << Curve.theta << endl;
  cout << "x: " << Curve.x << "  " << "y: " << Curve.y << endl;
}

    /*______________________________________________________________________________
returnX, no arguments or 'r'/'R' will just return, anything else will print out
				 and return.
*/
    ld
    Vector::returnX(char v) const
{
  if (v == 'r' || v == 'R') {
  	return x;    
  }
  else
  	cout << "\nx: " << x << endl;
		return x;     
}
ld Vector::returnY(char v)const
{
  if (v == 'r' || v == 'R') {
  	return y;    
  }
  else
  	cout << "\ny: " << y << endl;
  	return y; 
          
}
ld Vector::returnMag(char v)const
{
  if (v == 'r' || v == 'R') {
  	return magnitude;     
  }
  else
  	cout << "\nr: " << magnitude << endl;
  	return magnitude;
      
}
ld Vector::returnAngle(char v)const
{
  if (v == 'r' || v == 'R') {
  	return angle;    
  }
  else
		cout << "\n\xE9: " << angle << "\xF8" << endl;
		return angle;     
}
ld Vector::returnArcLength(char v) const
{
  if (v == 'r' || v == 'R')
  {
    return arcLength;
  }
  else
    cout << "\narc length: " << arcLength << endl;
  return angle;
}
char Vector::returnMode(char v)const
{
  if (v == 'r' || v == 'R') {
  	return mode;      
  }
  else
  		if (mode == 'p' || mode == 'P') {
        cout << "\nMode: Polar" << endl;     
      }
      else{
        cout << "\nMode: Rectangular" << endl;
      }     
}

/*______________________________________________________________________________
  the third argument is the Mode setting. 
  Use 'r'/'R' for rectangular components, 'p'/'P' for polar components
*/  
void Vector::setCoordinates(ld xMag, ld yAng, char _mode)
{
  validate_setMode();

  if (tolower(_mode) ==  'r') { 
    setRectCord(xMag, yAng); 
    adjust_angle();     
  }        
  else{
      setPolarCord(xMag, yAng);
      adjust_angle();       
  }
  calculate_arcLength();
}
void Vector::setRectCord(ld _x, ld _y)
{
  x = _x;
  y = _y;
  calculate_polar();
  revolutionAngle_inDegrees = angle;
}

void Vector::setPolarCord(ld mag, ld ang)
{
  magnitude = mag;
  validate_magnitude();
  angle =ang;
  revolutionAngle_inDegrees = ang;
  adjust_angle();
  calculate_rectangular(); 
}
void Vector::setX(ld _x)
{
  x = _x;  
  calculate_polar();
}
void Vector::setY(ld _y)
{ 
  y = _y;
  calculate_polar();
}
void Vector::setMag(ld mag)
{  
  magnitude = mag; 
  validate_magnitude();
  calculate_rectangular();
  calculate_arcLength();
}
void Vector::setAngle(ld ang)
{  
  angle = ang;
  adjust_angle();
  calculate_arcLength();
  calculate_rectangular();
}
void Vector::setMode(char _mode)
{
  mode = _mode;
  validate_setMode();
}
void Vector::setPolarCurve()
{
	cout << "\nEnter the Polar Curve to convert to cartiesian equation\n>";
	cin >> Curve.r;
  Curve.x = sqrt(pow(Curve.r, 2) + pow(Curve.y, 2));
  Curve.theta = atan(y / x);
}
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
void Vector::validate_magnitude()
{
  if (magnitude < 0)
    magnitude = abs(magnitude);  
}
void Vector::adjust_angle()
{
  if(angle == -360 || angle == -720 || angle == -1080 || angle == -1440){
  	angle = 0;
  }
	if (angle >= 360){
    int revolutionDegrees = (angle/360);
    int toSubtract = revolutionDegrees*360;
    ld newAngle = angle - toSubtract;
    angle = newAngle;
  }	    
  else if (angle < 0 && angle > -360){
    angle += 360;
    cout <<"test:" << angle << endl;
  }
  else if(angle < -360){
    int revolutionDegrees = (angle/360);
    int toSubtract = revolutionDegrees*360; 
    ld newAngle = angle - toSubtract + 360; 
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

Vector Vector::calculate_parallel_vector2d(const Vector v1, const Vector v2)
{

  cout << "in Calc Parallel vec2d: " << endl;
  return Vector(v2.x - v1.x, v2.y - v1.y);

}

bool Vector::operator<(const Vector &v) const
{
  if (magnitude < v.magnitude)
    return true;
  return false;  
}
bool Vector::operator>(const Vector & v)const
{
  if (magnitude > v.magnitude)
    return true;
  return false;
}
bool Vector::operator==(const Vector & v)const
{
  if (magnitude == v.magnitude)
    return true;
  return false;
}

Vector Vector::operator+(const ld n)const
{
	cout << "in  Vector::operator+(const ld n)const"<<endl;
	Vector total(x + n, y + n);
	total.mode = mode;	
	return total;
}
Vector Vector::operator+(const Vector& v)const
{ 
	cout << "in  Vector::operator+(const Vector& v)const"<<endl;
  Vector sum(x + v.x, y + v.y); 
  sum.mode = mode;  
  return sum;
}

Vector Vector::operator+()const
{ 
	cout << "in  Vector::operator+()const"<<endl;
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
Vector Vector::operator-(const ld number)const
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
Vector operator-(ld s, Vector& v)
{
 Vector total(s-v.returnX(),s-v.returnY(),v.returnMode()); 
 return total;
}
Vector operator+(ld s, Vector& v)
{
 Vector total(s+v.returnX(),s+v.returnY(),v.returnMode()); 
 return total; 
}
Vector &Vector::operator=(const Vector &vec)
{
  x = vec.x;
  y = vec.y;  
  calculate_polar();
  calculate_arcLength();
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
Vector Vector::operator/(ld value)
{
  again:
  if(value != 0)
    return Vector(x / value, y / value);
  else
  {
    do{
    cout << "**ERROR** can't divide by 0, enter new number\n>";
    cin >> value;
    cin.clear();
    cin.ignore(100, '\n');
    }while(!cin || value == 0);
    goto again;
  }  
}
Vector Vector::operator*(const ld scaler)const
{
	Vector results(x*scaler, y*scaler);	
	results.mode = mode;
	return results;	
}
Vector operator*(ld s, Vector& v)
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
    is>> v.Curve.r;
    v.calculate_polar();
    v.calculate_rectangular();
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

