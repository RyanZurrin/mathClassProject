// Part of a final project in c++ II, this program as a whole
// will calculate the properties of 2D and 3D objects and vectors

// prgrammer:   Ryan Zurrin
#include "Calculator.h"

Calculator::Calculator()
{
	sqpt = new Square;
	sqpt->side = 0;
	sqpt->area = 0;
	sqpt->parimeter = 0;

	triptr = new Triangle;
	triptr->base = 0;
	triptr->height = 0;
	triptr->side_a = 0;
	triptr->side_b = 0;
	triptr->side_c = 0;
	triptr->angle_A = 0;
	triptr->angle_B = 0;
	triptr->angle_C = 0;
	triptr->area = 0;
	triptr->parameter = 0;
	triptr->sss = 0;
	triptr->aaa = 0;
	triptr->sas = 0;
	triptr->ssa = 0;
	triptr->asa = 0;
	triptr->aas = 0;
	triptr->sVal = 0;
	triptr->rVal = 0;
	
	vectptr = new Vector;
	vectptr->x = 0;
	vectptr->y = 0;
	vectptr->magnitude = 0;
	vectptr->angle = 0;
	vectptr->arcLength = 0;
	vectptr->mode = 'r';

	
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
	
		default:
			return 0.0;
	}	
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
	
	default:
		cout << "invalid operation performed";
		return 0;
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

	default:
		cout << "invalid operation performed";
		return 0;
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
		cout << "Thank you for using the Object calculator ver 1.0\n"
			<< "Look out for new features to be added on GitHub Regularly\n"
			<< "https://github.com/RyanZurrin/mathClassProject";

	default:
		cout << "invalid operation performed";
		return 0;
	}
	return vectptr;
}
