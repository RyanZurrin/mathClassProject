#include "Vector3D.h"
#include "exceptionHandler.h"
using namespace std;
Vector3D::Vector3D() //constructor
{
  x=0;
  y=0;
  z=0;
  _ptr3d = nullptr;
  _ptr2d = nullptr;
  set_allAngles();
  object_counter++;
  cout<< object_counter << ": " <<"in the 3dVector default constructor"<<endl;
}
Vector3D::Vector3D(ld x1,ld y1,ld z1)  //initializing object with values.
{
  x=x1;
  y=y1;
  z=z1;
  _ptr3d = nullptr;
  _ptr2d = nullptr;
  set_magnitude();
  set_allAngles();  
  object_counter++;
	cout<< object_counter << ": " <<"in the x,y,z constructor" << endl;;
}
Vector3D::Vector3D(const Vector3D &vec)
{
  x=vec.x;
  y=vec.y;
  z=vec.z;
  _ptr3d = vec._ptr3d;
  _ptr2d = vec._ptr2d;
  set_magnitude();
  set_allAngles();
  object_counter++;
	cout<< object_counter << ": " <<"in the 3dcopy constructor";
}
void Vector3D::setX(ld _x)
{
    x = _x;
    set_allAngles();
    set_magnitude();
}
void Vector3D::setY(ld _y)
{
    y = _y;
    set_allAngles();
    set_magnitude();
}
void Vector3D::setZ(ld _z)
{
    z = _z;
    set_allAngles();
    set_magnitude();
}
void Vector3D::set_xAngle(ld _xa)
{
    xAngle = _xa;
    set_allAngles();
    set_magnitude();
}
void Vector3D::set_yAngle(ld _ya)
{
    yAngle = _ya;
    set_allAngles();
    set_magnitude();
}
void Vector3D::set_zAngle(ld _za)
{
    zAngle = _za;
    set_allAngles();
    set_magnitude();
}
void Vector3D::showAllData()
{
    magnitude = find_magnitude();
    cout<< setprecision(2) << fixed;
  	cout<< "x: " << x << " ";
    cout<< "y: " << y << " ";
    cout<< "z: " << z << endl;
    cout<< "mag: " << magnitude << endl;
    cout << "angles aX: "<< xAngle << ", aY: "<<yAngle<<", aZ: "<<zAngle
         << endl;		
	show_mode();	  
}
void Vector3D::showPolarCord()const
{
	cout << "polar<" << x << ", " << y << ", " << z << ">" << endl;
}
void Vector3D::set_allAngles()
{
    xAngle = return_xAngle();
    yAngle = return_yAngle();
    zAngle = return_zAngle();
    //angle = 
}

void Vector3D::set_magnitude()
{
    magnitude = find_magnitude();
}

Vector3D Vector3D::check_division(ld d)
{
    cout << "in 3Doperator/check division ld\n";
    ExceptionHandler checker;
    if (checker.zeroDivisorCheck(d) == 0 && checker.checkedFlag == false) {
        checker.checkedFlag = true;
        Vector3D temp(x / d, y / d, z / d);
        set_allAngles();
        return temp;
    }
    else if (checker.zeroDivisorCheck(d) != 0 && checker.checkedFlag == false) {
        d = checker.zeroDivideFix(d);
        checker.checkedFlag = true;
        Vector3D temp(x / d, y / d, z / d);
        set_allAngles();
        return temp;
    }
    //return *this;
}

//addition
Vector3D Vector3D::operator+(const Vector3D &vec)const
{
	cout << "in Vector3D::operator+(const Vector3D &vec)"<<endl;
    return Vector3D(x+vec.x,y+vec.y,z+vec.z);
}
Vector3D Vector3D::operator+(Vector &vec)const
{
	cout << "in Vector3D::operator+(Vector &vec)const "<<endl;
    return Vector3D(x+vec.x,y+vec.y,z);
}

Vector3D &Vector3D::operator+=(const Vector3D &vec)
{
	cout << "in &Vector3D::operator+=(const Vector3D &vec)"<<endl;
    x+=vec.x;
    y+=vec.y;
    z+=vec.z;
    set_allAngles();
    return *this;
}

//substraction//
Vector3D Vector3D::operator-(const Vector3D &vec)
{
    return Vector3D(x-vec.x,y-vec.y,z-vec.z);
}
Vector3D Vector3D::operator-(const ld n) const
{
    return Vector3D(x-n, y-n, z-n);
}
Vector3D Vector3D::operator-() const
{
    return Vector3D(-x, -y, -z);
}
Vector3D Vector3D::operator--()
{
    return Vector3D(--x, --y, --z);
}
Vector3D Vector3D::operator--(int)
{
    return Vector3D(x--, y--, z--);
}
Vector3D &Vector3D::operator-=(const Vector3D &vec)
{
    x-=vec.x;
    y-=vec.y;
    z-=vec.z;
    set_allAngles();
    return *this;
}

//scalar multiplication
Vector3D Vector3D::operator*(ld value)
{
    return Vector3D(x*value,y*value,z*value);
}
Vector3D &Vector3D::operator*=(ld value)
{
    x*=value;
    y*=value;
    z*=value;
    set_allAngles();
    return *this;
}

//scalar division

Vector3D Vector3D::operator/(ld d)
{
   return check_division(d);
   
}



Vector3D Vector3D::operator/(double d)
{
    return check_division(d);
   
}
Vector3D Vector3D::operator/(int d)
{
    return check_division(d);
   
}

Vector3D &Vector3D::operator/=(ld value)
{
    cout << "in 3D operator/= ld value\n";
    ExceptionHandler checker;
    checker.zeroDivisorCheck(value);
    x/=value;
    y/=value;
    z/=value;
    set_allAngles();
    return *this;
}
Vector3D &Vector3D::operator=(const Vector3D &vec)
{
    x=vec.x;
    y=vec.y;
    z=vec.z;
    return *this;
}

ostream& operator<<(ostream& os, const Vector3D & v)
{	
  if(v.mode == 'R' || v.mode == 'r'){
  	v.showRectCord(); 
  }
  else{
  	v.showPolarCord();
  }  
  return os;
} 


//Dot product
ld Vector3D::dot_product(const Vector3D &vec)
{
    return x * vec.x + vec.y * y + vec.z * z;
}
//cross product
Vector3D Vector3D::cross_product(const Vector3D &vec)
{
    ld ni=y*vec.z-z*vec.y;
    ld nj=z*vec.x-x*vec.z;
    ld nk=x*vec.y-y*vec.x;
    return Vector3D(ni,nj,nk);
}
ld Vector3D::find_magnitude()
{
    return sqrt(square());
}
ld Vector3D::square()
{
    return x*x+y*y+z*z;
}
Vector3D Vector3D::normalization()
{
    assert(find_magnitude()!=0);
    *this/=find_magnitude();
    return *this;
}


ld Vector3D::distance(const Vector3D &vec)
{
    Vector3D dist=*this-vec;
    return dist.find_magnitude();
}
ld Vector3D::returnX()
{
    return x;
}
ld Vector3D::returnY()
{
    return y;
}
ld Vector3D::returnZ()
{
    return z;
}
ld Vector3D::return_xAngle()const
{
    return atan2(sqrt(y * y + z * z), x) * DEGREE;
}
ld Vector3D::return_yAngle()const
{
    return atan2(sqrt(x * x + z * z), y) * DEGREE;
}
ld Vector3D::return_zAngle()const
{
    return atan2(sqrt(x * x  + y * y), z) * DEGREE;
}
void Vector3D::disp()
{
    cout<<x<<" "<<y<<" "<<z<<endl;
}

Vector3D::~Vector3D()
{	
	--object_counter;
	cout << "In Vector3D destructor: "<< object_counter << " objects remain\n"
			 << endl;
}


