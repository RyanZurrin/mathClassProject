#ifndef VECTOR3D_H
#define VECTOR3D_H
#include "vect.h"


using namespace std;
typedef long double ld;
class Vector3D : public Vector
{
//friend class Vector;
private:
    ld z, xAngle, yAngle, zAngle;
    void set_allAngles();
    void set_magnitude();

public:    
    Vector3D(); //constructor    
    Vector3D(ld, ld, ld);  //initializing object with values.    
    Vector3D(const Vector3D &vec);    //copy constructor    
    
    void setX(ld);
    void setY(ld);
    void setZ(ld);
		void set_xAngle(ld);
		void set_yAngle(ld);
		void set_zAngle(ld);
		
		void showAllData();
		void showPolarCord()const;
		void disp();    //display value old vectors
    ld returnX(); //return x
    ld returnY(); //return y
    ld returnZ(); //return z
    ld return_xAngle()const; //return x angle
    ld return_yAngle()const; //return y angle
    ld return_zAngle()const; //return z angle
    
    ld square(); //gives square old the vector
    
    ld dot_product(const Vector3D &vec); //scalar dot_product
    ld distance(const Vector3D &vec);    //gives distance between two vectors
    ld find_magnitude();  //magnitude of the vector
    Vector3D cross_product(const Vector3D &vec);    //cross_product
    Vector3D normalization();   //normalized vector    
    
    Vector3D operator+(const Vector3D &vec)const;    //addition
    Vector3D operator+(Vector &vec)const;
    Vector3D &operator+=(const Vector3D &vec);  ////assigning new result to the vector
    Vector3D operator-(const Vector3D &vec);    //substraction
    Vector3D operator-(const ld number)const;
    Vector3D operator-()const;
    Vector3D operator--();
    Vector3D operator--(int);
    Vector3D &operator-=(const Vector3D &vec);  //assigning new result to the vector
    Vector3D operator*(ld value);    //multiplication
    Vector3D &operator*=(ld value);  //assigning new result to the vector.
    Vector3D* operator/(ld value);    //division
    Vector3D operator/(double);    //division
    Vector3D operator/(int);
    Vector3D &operator/=(ld value);  //assigning new result to the vector
    Vector3D &operator=(const Vector3D &vec);      
    friend ostream& operator<<(ostream&, const Vector3D&);
    ~Vector3D(); 
};
#endif
