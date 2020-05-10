
#include "Calculator.h"




Calculator::Calculator()
{
	sqpt = new Square;
	sqpt->side = 0;
	sqpt->area = 0;
	sqpt->parimeter = 0;
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
	default:
		cout << "invalid operation performed";
		return 0;
	}
	
}
