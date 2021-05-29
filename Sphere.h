#pragma once

// Part of a final project in c++ II, this program as a whole
// will calculate the properties of 2D and 3D objects and vectors

// prgrammer:   Ryan Zurrin

#ifndef SPHERE_H
#define SPHERE_H

#include <cmath>
#include <iostream>
using namespace std;



class Sphere
{
public:
	void update_circle();
	void calculate_radius();
	void calculate_volume();
	void calculate_surfaceArea();
	void calculate_circumfrance();
	void calculate_diameter();

public:
	Sphere* _sphPt;  //object pointer

	Sphere();
	Sphere(double r);

	double radius;
	double diameter;
	double circumfrance;
	double surfaceArea;
	double volume;

	void setRadius(double);
	void setVolume(double);
	void setDiameter(double);
	void setCircumfrance(double);
	void setSurfaceArea(double);

	void showSphereData()const;
	void showRadius()const;
	void showVolume()const;
	void showSurfaceArea()const;
	void showDiameter()const;
	void showCircumfrance()const;


	double returnRadius() { return radius; }
	double returnVolume() { return volume; }
	double returnSurfaceArea() { return surfaceArea; }
	~Sphere() = default;

};
#endif // !SPHERE_H