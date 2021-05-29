#pragma once
// Part of a final project in c++ II, this program as a whole
// will calculate the properties of 2D and 3D objects and vectors

// prgrammer:   Ryan Zurrin

#ifndef THREEDIMENSIONAL_H
#define THREEDIMENSIONAL_H
#include "Cube.h"
#include "Vector3D.h"
#include "Sphere.h"
#include <iostream>
using namespace std;

class ThreeDimensional  //: public Shape
{
public:
	ThreeDimensional* _3Dptr;

	ThreeDimensional();
	Cube box;
	Vector3D vect3D;
	Sphere orb;
	~ThreeDimensional() = default;
};

#endif // !THREEDIMENSIONAL_H

/*
template<class T>
inline T ThreeDimensional<T>::calculate_surface_area()
{
	return T();
}

template<class T>
inline T ThreeDimensional<T>::calulate_volume()
{
	return T();
}

template<class T>
inline T ThreeDimensional<T>::adjust_other_dimensions()
{
	return T();
}

template<class T>
inline T ThreeDimensional<T>::setSurfaceArea(T _sA)
{
	surfaceArea = _sA;
	adjust_other_dimensions();
}

template<class T>
inline T ThreeDimensional<T>::setVolume(T _V)
{
	volume = _V;
	adjust_other_dimensions();
}

template<class T>
inline T ThreeDimensional<T>::returnFaces() const
{
	return numFaces;
}

template<class T>
inline T ThreeDimensional<T>::returnEdges() const
{
	return numEdges;
}

template<class T>
inline T ThreeDimensional<T>::returnVirticies() const
{
	return numVertices;
}

template<class T>
inline T ThreeDimensional<T>::returnVolume() const
{
	return volume;
}

template<class T>
inline T ThreeDimensional<T>::showAllData() const
{
}
*/
