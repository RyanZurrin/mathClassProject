#include "Sphere.h"
#include "exceptionHandler.h"

void Sphere::update_circle()
{
	calculate_diameter();
	calculate_volume();
	calculate_surfaceArea();
	calculate_circumfrance();
	calculate_radius();
}

void Sphere::calculate_radius()
{
	if (circumfrance > 0) {
		radius = circumfrance / (2 * PI);
	}
	else if (diameter > 0) {
		radius = diameter / 2;
	}
	else if (volume > 0) {
		radius = pow((3 * volume) / (4 * PI), 1 / 3);
	}
}

void Sphere::calculate_volume()
{
	if (radius > 0) {
		volume = (4*PI / 3) * pow(radius, 3);
	}
	else if(circumfrance > 0) {
		volume = (4 / 3) * PI * pow((circumfrance / (2 * PI)), 3);
	}
}

void Sphere::calculate_surfaceArea()
{
	if (radius > 0) {
	surfaceArea =	4 * PI * pow(radius, 2);
	}
	else if (volume > 0) {
		surfaceArea = pow(PI, 1 / 3) * (pow(6 * volume, 2 / 3));
	}
	else if (circumfrance > 0) {
		surfaceArea = (circumfrance * circumfrance) / (2 * PI);
	}
}

void Sphere::calculate_circumfrance()
{
	if (radius > 0) {
		circumfrance = 2 * PI * radius;
	}

}

void Sphere::calculate_diameter()
{
	if (radius > 0) {
		diameter = 2 * radius;
	}
	else if (circumfrance > 0) {
		diameter = circumfrance / PI;
	}
	else if (surfaceArea > 0) {
		diameter = sqrt(surfaceArea / PI);
	}
	else if (volume > 0) {
		diameter = pow(6 * (volume / PI), 1 / 3);
	}
}

Sphere::Sphere()
{
	_sphPt = nullptr;
	circumfrance = 0;
	surfaceArea = 0;
	diameter = 0;
	volume = 0;
	radius = 0;
}

Sphere::Sphere(double r)
{
	_sphPt = nullptr;
	circumfrance = 0;
	surfaceArea = 0;
	diameter = 0;
	volume = 0;
	radius = 0;
	if (r < 0) {
		do {
			cout << "can't have a negitive radius, enter a new value\n>";
			cin >> r;
			cin.clear();
			cin.ignore(100, '\n');
		} while (!cin || r < 0);		
	}
	radius = r;
	update_circle();
}

void Sphere::setRadius(double r)
{
	if (r < 0) {
		do {
			cout << "can't have a negitive radius, enter a new value\n>";
			cin >> r;
			cin.clear();
			cin.ignore(100, '\n');
		} while (!cin || r < 0);	
	}
	radius = r;
	calculate_diameter();
	calculate_surfaceArea();
	calculate_volume();
	calculate_circumfrance();
	//update_circle();
}

void Sphere::setVolume(double v)
{
	if (v < 0) {
		do {
			cout << "can't have a negitive volume, enter a new value\n>";
			cin >> v;
			cin.clear();
			cin.ignore(100, '\n');
		} while (!cin || v < 0);
	}
	volume = v;
	calculate_radius();
	calculate_diameter();
	calculate_surfaceArea();	
	calculate_circumfrance();
	//update_circle();
}
void Sphere::setDiameter(double d)
{
	if (d < 0) {
		do {
			cout << "can't have a negitive diameter, enter a new value\n>";
			cin >> d;
			cin.clear();
			cin.ignore(100, '\n');
		} while (!cin || d < 0);
	}
	diameter = d;
	radius = diameter / 2;	
	calculate_surfaceArea();
	calculate_volume();
	calculate_circumfrance();
	//update_circle();
}
/*nots on process if circumrfrance is given to find rest of circle
1)if we got circumfrance we need to next solve for the diameter which is d = circumfrance/pi.
2)with diameter we can solve for the radius which is r = d/2.
3)with radius we can solve for surface area


*/
void Sphere::setCircumfrance(double c)
{
	
		if (c < 0) {
			do {
				cout << "can't have a negitive circumfrance, enter a new value\n>";
				cin >> c;
				cin.clear();
				cin.ignore(100, '\n');
			} while (!cin || c < 0);
		}
		circumfrance = c;
		calculate_radius();
		calculate_diameter();
		calculate_surfaceArea();
		calculate_volume();	

}

void Sphere::setSurfaceArea(double r)
{
	if (r < 0) {
		do {
			cout << "can't have a negitive surface area, enter a new value\n>";
			cin >> r;
			cin.clear();
			cin.ignore(100, '\n');
		} while (!cin || r < 0);		
	}
	surfaceArea = r;
	update_circle();
}

void Sphere::showSphereData() const
{
	cout << fixed;
	cout << "Radius: " << radius << endl;
	cout << "Volume: " << volume << endl;
	cout << "Surface Area: " << surfaceArea << endl;
	cout << "Diameter: " << diameter << endl;
	cout << "Circumfrance: " << circumfrance << endl;

}

void Sphere::showRadius() const
{
	cout << "Radius: " << radius << endl;
}

void Sphere::showVolume() const
{
	cout << "Volume: " << volume << endl;
}

void Sphere::showSurfaceArea() const
{
	cout << "Surface Area: " << volume << endl;
}

void Sphere::showDiameter() const
{
	cout << "Diameter: " << diameter << endl;
}

void Sphere::showCircumfrance() const
{
	cout << "Circumfrance: " << circumfrance << endl;
}
