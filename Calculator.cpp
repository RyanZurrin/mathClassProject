// Part of a final project in c++ II, this program as a whole
// will calculate the properties of 2D and 3D objects and vectors

// prgrammer:   Ryan Zurrin
#include "Calculator.h"

Calculator::Calculator()
{
	calculate = nullptr;


	sqpt = new Square;
	sqpt->side = 0;
	sqpt->area = 0;
	sqpt->parimeter = 0;

	triptr = new Triangle;
	triptr->maxside = 0;
	triptr->height_a = 0;
	triptr->side_a = 0;
	triptr->side_b = 0;
	triptr->side_c = 0;
	triptr->angle_A = 0;
	triptr->angle_B = 0;
	triptr->angle_C = 0;
	triptr->area = 0;
	triptr->perimeter = 0;
	triptr->sssFlag = 0;
	triptr->aaaFlag = 0;
	triptr->sasFlag = 0;
	triptr->ssaFlag = 0;
	triptr->asaFlag = 0;
	triptr->aasFlag = 0;
	triptr->sVal = 0;
	triptr->rVal = 0;

	vectptr = new Vector;
	vectptr->x = 0;
	vectptr->y = 0;
	vectptr->magnitude = 0;
	vectptr->angle = 0;
	vectptr->arcLength = 0;
	vectptr->mode = 'r';

	vect3Dptr = new Vector3D;
	vect3Dptr->x = 0;
	vect3Dptr->y = 0;
	vect3Dptr->z = 0;
	vect3Dptr->xAngle = 0;
	vect3Dptr->yAngle = 0;
	vect3Dptr->zAngle = 0;
	vect3Dptr->arcLength = 0;
	vect3Dptr->mode = 'r';
	vect3Dptr->angle = 0;

	cubeptr = new Cube;
	cubeptr->volume = 0;
	cubeptr->edgeLenght = 0;
	cubeptr->surfaceArea = 0;

	orbptr = new Sphere;
	orbptr->circumfrance = 0;
	orbptr->diameter = 0;
	orbptr->radius = 0;
	orbptr->surfaceArea = 0;
	orbptr->volume = 0;




}

double Calculator::basicMathOperation(double x, char op0, double y)
{
	switch (op0)
	{
		case '+':
			return x + y;
			break;
		case '-':
			return x - y;
			break;
		case '*':
			return x * y;
			break;
		case '/':
			return x / y;
			break;
		case '=':
			if (x == y)
				return true;
			return false;
			break;
		case '<':
			if (x < y)
				return true;
			return false;
			break;
		case '>':
			if (x > y)
				return true;
			return false;
			break;
		case '~':
			break;
		default:
			cout << "bad operation";
			break;
	}
	return 0;
}

Square* Calculator::squareMathOperation(Square &sx, char op0, Square &sy)
{
	switch (op0)
	{
	case '+':
		sqpt->side = sx.side + sy.side;
		return  sqpt;
		break;
	case '-':
		sqpt->side = sx.side - sy.side;
		return sqpt;
		break;
	case '*':
		sqpt->side = sx.side * sy.side;
		return  sqpt;
		break;
	case '/':
		sqpt->side = sx.side / sy.side;
		return sqpt;
		break;
	case '=':
		if (sx.side == sy.side)
			cout << "true";
		cout << "false";
		break;
	case '<':
		if (sx.side < sy.side)
			cout << "true";
		cout << "false";
		break;
	case '>':
		if (sx.side > sy.side)
			cout << "true";
		cout << "false";
		break;
	case '~':
		break;
	default:
		cout << "invalid operation performed";
		break;
	}
	return sqpt;
}

Triangle* Calculator::triangleMathOperation(Triangle& tx, char op0, Triangle& ty)
{

	switch (op0)
	{
	case '+':
		triptr->side_a = tx.side_a + ty.side_a;
		triptr->side_b = tx.side_b + ty.side_b;
		triptr->side_c = tx.side_c + ty.side_c;
		triptr->update_triangle();
		return  triptr;
		break;
	case '-':
		triptr->side_a = tx.side_a - ty.side_a;
		triptr->side_b = tx.side_b - ty.side_b;
		triptr->side_c = tx.side_c - ty.side_c;
		triptr->update_triangle();
		return triptr;
		break;
	case '*':
		triptr->side_a = tx.side_a * ty.side_a;
		triptr->side_b = tx.side_b * ty.side_b;
		triptr->side_c = tx.side_c * ty.side_c;
		triptr->update_triangle();
		return  triptr;
		break;
	case '/':
		triptr->side_a = tx.side_a / ty.side_a;
		triptr->side_b = tx.side_b / ty.side_b;
		triptr->side_c = tx.side_c / ty.side_c;
		triptr->update_triangle();
		return triptr;
		break;
	case '=':
		if (tx.area == ty.area)
			cout << "true";
		cout << "false";
		break;
	case '<':
		if (tx.area < ty.area)
			cout << "true";
		cout << "false";
		break;
	case '>':
		if (tx.area > ty.area)
			cout << "true";
		cout << "false";
		break;
	case '~':
		break;
	default:
		cout << "invalid operation performed";
		break;
	}
	return triptr;
}

Vector* Calculator::vectorMathOperation(Vector& vx, char op0, Vector& vy)
{
	switch (op0)
	{
	case '+':
		vectptr->x = vx.x + vy.x;
		vectptr->y = vx.y + vy.y;
		vectptr->calculate_polar();
		vectptr->calculate_magnitude();
		vectptr->calculate_angle();
		vectptr->adjust_angle();
		return  vectptr;
		break;
	case '-':
		vectptr->x = vx.x - vy.x;
		vectptr->y = vx.y - vy.y;
		vectptr->calculate_polar();
		vectptr->calculate_magnitude();
		vectptr->calculate_angle();
		vectptr->adjust_angle();
		return  vectptr;
		break;
	case '*':
		vectptr->x = vx.x * vy.x;
		vectptr->y = vx.y * vy.y;
		vectptr->calculate_polar();
		vectptr->calculate_magnitude();
		vectptr->calculate_angle();
		vectptr->adjust_angle();
		return  vectptr;
		break;
	case '/':
		vectptr->x = vx.x / vy.x;
		vectptr->y = vx.y / vy.y;
		vectptr->calculate_polar();
		vectptr->calculate_magnitude();
		vectptr->calculate_angle();
		vectptr->adjust_angle();
		return  vectptr;
		break;
	case '=':
		if (vx.x == vy.x && vx.y == vy.y)
			cout << "true";
		cout << "false";
		break;
	case '<':
		if (vx.magnitude < vy.magnitude)
			cout << "true";
		cout << "false";
		break;
	case '>':
		if (vx.magnitude > vy.magnitude)
			cout << "true";
		cout << "false";
		break;
	case '$':
		cout << "distance between the two vectors is: " << vx.distance(vy) << endl;
		break;
	case '~':
		break;
	default:
		cout << "invalid operation performed";
		break;
	}
	return vectptr;
}

Vector3D* Calculator::vector3DMathOperation(Vector3D& vx, char op0, Vector3D& vy)
{
	switch (op0)
	{
	case '+':
		vect3Dptr->x = vx.x + vy.x;
		vect3Dptr->y = vx.y + vy.y;
		vect3Dptr->z = vx.z + vy.z;
		vect3Dptr->set_allAngles();
		vect3Dptr->set_magnitude();
		return  vect3Dptr;
		break;
	case '-':
		vect3Dptr->x = vx.x - vy.x;
		vect3Dptr->y = vx.y - vy.y;
		vect3Dptr->z = vx.z - vy.z;
		vect3Dptr->set_allAngles();
		vect3Dptr->set_magnitude();
		return  vect3Dptr;
		break;
	case '*':
		vect3Dptr->x = vx.x * vy.x;
		vect3Dptr->y = vx.y * vy.y;
		vect3Dptr->z = vx.z * vy.z;
		vect3Dptr->set_allAngles();
		vect3Dptr->set_magnitude();
		return  vect3Dptr;
		break;
	case '/':
		vect3Dptr->x = vx.x / vy.x;
		vect3Dptr->y = vx.y / vy.y;
		vect3Dptr->z = vx.z / vy.z;
		vect3Dptr->set_allAngles();
		vect3Dptr->set_magnitude();
		return  vect3Dptr;
		break;
	case '=':
		if (vx.x == vy.x && vx.y == vy.y && vx.z == vy.z)
			cout << "true";
		cout << "false";
		break;
	case '<':
		if (vx.magnitude < vy.magnitude)
			cout << "true";
		cout << "false";
		break;
	case '>':
		if (vx.magnitude > vy.magnitude)
			cout << "true";
		cout << "false";
		break;
	case '$':
		cout << "distance between the two vectors is: " << vx.distance(vy) << endl;
		break;
	case '~':
		exit(0);
	default:
		cout << "invalid operation performed";
		break;
	}
	return vect3Dptr;
}


Cube* Calculator::cubeMathOperation(Cube& x, char op0, Cube& y)
{
	bool badFlag = false;
	do{

		switch (op0)
		{
		case '+':
			cubeptr->edgeLenght = x.edgeLenght + y.edgeLenght;
			return  cubeptr;
		case '-':
			cubeptr->edgeLenght = x.edgeLenght - y.edgeLenght;
			return cubeptr;
		case '*':
			cubeptr->edgeLenght = x.edgeLenght * y.edgeLenght;
			return  cubeptr;
		case '/':
			cubeptr->edgeLenght = x.edgeLenght / y.edgeLenght;
			return cubeptr;
		case '=':
			if (x.edgeLenght == y.edgeLenght)
				cout << "true";
			cout << "false";
			break;
		case '<':
			if (x.edgeLenght < y.edgeLenght)
				cout << "true";
			cout << "false";
			break;
		case '>':
			if (x.edgeLenght > y.edgeLenght)
				cout << "true";
			cout << "false";
			break;
		case '~':
			exit(0);
		default:
			cout << "invalid operation performed, try again\n>>";
			badFlag = true;
		}

	}
	while (badFlag == true);

	return cubeptr;
}

Sphere* Calculator::sphereMathOperation(Sphere& x, char op0, Sphere& y)
{
	switch (op0)
	{
	case '+':
		orbptr->radius = x.radius + y.radius;
		return  orbptr;
		break;
	case '-':
		orbptr->radius = x.radius - y.radius;
		return  orbptr;
		break;
	case '*':
		orbptr->radius = x.radius * y.radius;
		return  orbptr;
		break;
	case '/':
		orbptr->radius = x.radius / y.radius;
		return  orbptr;
		break;
	case '=':
		if (x.radius == y.radius)
			cout << "true";
		cout << "false";
		break;
	case '<':
		if (x.radius < y.radius)
			cout << "true";
		cout << "false";
		break;
	case '>':
		if (x.radius > y.radius)
			cout << "true";
		cout << "false";
		break;
	case '~':
		exit(0);
	default:
		cout << "invalid operation performed";
		break;
	}
	return orbptr;
}
