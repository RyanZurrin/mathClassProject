// Part of a final project in c++ II, this program as a whole
// will calculate the properties of 2D and 3D objects and vectors

// prgrammer:   Ryan Zurrin
#include "Cube.h"

Cube::Cube()
{
	cubptr = nullptr;
	edgeLenght = 0.0;
	volume = 0.0;
	surfaceArea = 0.0;
}

Cube::Cube(double set, char mode)
{
	if (toupper(mode)=='E' && set > 0)
	{
		edgeLenght = set;
		calculate_surface_area();
		calculate_volume();
	}
	else if (toupper(mode) == 'V' && set > 0)
	{
		volume = set;
		calculate_edge();
		calculate_surface_area();
	}
	else if (toupper(mode) == 'S' && set > 0) {
		surfaceArea = set;
		calculate_edge();
		calculate_volume();
	}
}

void Cube::setEdgeLength(double el)
{
	if (el > 0) {
		edgeLenght = el;
		calculate_volume();
		calculate_surface_area();
	}	
}

void Cube::setVolume(double v)
{
	if (v > 0) {
		volume = v;
		calculate_edge();
		calculate_surface_area();
	}
}

void Cube::setSurfaceArea(double sa)
{
	if (sa > 0) {
		surfaceArea = sa;
		calculate_edge();
		calculate_volume();
	}
}

void Cube::calculate_volume()
{
	if (edgeLenght != 0) {
		volume = pow(edgeLenght, 3);
	}
	else if(surfaceArea !=0 ){
		volume = sqrt(6 * (pow(surfaceArea, 3 / 2)) / (36));
	}

}

void Cube::calculate_surface_area()
{
	if (edgeLenght != 0) {
		surfaceArea = 6 * (edgeLenght * edgeLenght);
	}
	else if (volume != 0) {
		surfaceArea = 6 * pow(volume, 2 / 3);
	}
}

void Cube::calculate_edge()
{
	if (surfaceArea != 0) {
		edgeLenght = returEdgefromSurfaceArea();
	}
	else if (volume != 0) {
		edgeLenght = returnEdgefromVolume();
	}
}

void Cube::showAllSquareInfo()
{
}

void Cube::showEdgeLength()
{
}

void Cube::showVolume()
{
}

void Cube::showSurfaceArea()
{
}
