#pragma once
// Part of a final project in c++ II, this program as a whole
// will calculate the properties of 2D and 3D objects and vectors

// prgrammer:   Ryan Zurrin

#ifndef THREEDIMENSIONAL_H
#define THREEDIMENSIONAL_H
#include "Vector3D.h"
#include <iostream>
using namespace std;

class ThreeDimensional  //: public Shape
{
private:
	//virtual void calculate_surface_area();
	//virtual void calulate_volume();
	//virtual void adjust_other_dimensions();
	//virtual void setFaces(int);
	//virtual void setEdges(int);
	//virtual void setVirtices(int);
public:
	ThreeDimensional()
	{
		cout << "in the 3D constructor";
	}
	//double numFaces, numEdges, numVertices;
	//double surfaceArea;
	//double volume;

	

	//void setSurfaceArea(double);
	//void setVolume(double);

	

	//int returnFaces()const;
	//int returnEdges()const;
	//int returnVirticies()const;
	//double returnVolume()const;
	//double returnSurfaceArea();

	//void showAllData()const;
	~ThreeDimensional()
	{
		cout << "in the 3D destructor";
	}
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
