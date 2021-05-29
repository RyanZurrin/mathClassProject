#pragma once
// Part of a final project in c++ II, this program as a whole
// will calculate the properties of 2D and 3D objects and vectors

// prgrammer:   Ryan Zurrin


#ifndef CUBE_H
#define CUBE_H
#include <cmath>
#include <iostream>
using namespace std;
class Cube
{
	static int  cube_counter;
public:
	Cube();
	Cube(double, char mode = 'e'); // constructor with a mode to switch from default side
	Cube* cubptr;				  // to volume with a ['v'/'V'] or to surface area with an 's'/'S'
	double surfaceArea;
	double volume;
	double edgeLenght;


	void setEdgeLength(double);
	void setVolume(double);
	void setSurfaceArea(double);

	void calculate_volume();
	void calculate_surface_area();
	void calculate_edge();

	void showAllSquareInfo();
	void showEdgeLength();
	void showVolume();
	void showSurfaceArea();

	double returnSurfaceArea()const{ return 6 * pow(edgeLenght, 2); }
	double returnVolume()const { return pow(edgeLenght, 3); }
	double returnEdgeFromVolume()const { return pow(volume, 1 / 3); }
	double returnEdgeFromSurfaceArea()const { return sqrt(surfaceArea / 6); }
	double cube(double c)const { return pow(c, 3); }
	static int returnCubeCounter() { return cube_counter; }
	~Cube() = default;
};

#endif // !CUBE_H