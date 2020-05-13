#pragma once
// Part of a final project in c++ II, this program as a whole
// will calculate the properties of 2D and 3D objects and vectors

// prgrammer:   Ryan Zurrin

#ifndef SHAPE_H
#define SHAPE_H


#include "Numbers.h"
#include <string>
#include "TwoDimensional.h"
#include "ThreeDimensional.h"


class Shape : public Numbers
{
public:
	//Shape* ptr;
	Shape(); // empty shape object created
	
	TwoDimensional shapes;	
	ThreeDimensional objects;
	Vector vect2d;
	
	~Shape();  //  destructor

	
	//ThreeDimensional* Object;
};

#endif // !SHAPE_H

/*____________________________________________________________________________
                                Junk Yard                                   */
 



/*
template<class T>
inline Shape<T>::Shape()
{
	Shape = nullptr;
	Object = nullptr;

}

template<class T>
inline Shape<T>::~Shape()
{
	cout << "in the shape destructor" << endl;
	delete this;
}
*/
