/*______________________________________________________________________________
author:			Ryan Zurrin
program:		testVect.cpp
due date: 			
assignment:	build and test a Vector class for doing math on vectors	
purpose:    gain a deeper understanding of classes and operator overloading
______________________________________________________________________________*/
//#include "vect.h"
//#include "Vector3D.h"
//#include "Numbers.h"
//#include "TwoDimensional.h"
//#include "ThreeDimensional.h"
//#include "Square.h"
#include "Shape.h"
#include "Calculator.h"

char mainMenuChoice();
//#include "Triangle.h"

using namespace std;
//______________________________________________________________________________
//
double squareLoop(int, int);

int main()
{
	double x = 0.0;
	double y = 0.0;
	double results = 0.0;
	Square sx, sy;
	Square* result = nullptr;
	//result.area = 0;
	char op = '+';
	char menu = '1';
	int opCount = 0;
	Calculator c;
	
	menu = mainMenuChoice();
  
  switch(menu)
  {
  	case '1':  		
		cout << "Basic Calculator - format: a + b | a - b | a * b | a / b" << endl;
  		while (true || !cin)
  		{
			//cin.ignore(100, 'n');
			//	cin.clear();
			
			cout << "> ";
  			cin >> x >> op >> y;  			
  		if(!cin)
  		{
  			cout << "unrecognized character used" << endl;
  			cin.ignore(100, '\n');
  			cin.clear();
  			continue;
			}
			if (op == '/' && y == 0)
			{
				cout << "zero division error" << endl;
				continue;
			}
			else
			{
				results = c.basicMathOperation(x, op, y);
				opCount++;
			}
  			
  			cout << " ["<<opCount<<"] "<< "= " << results << endl;
			}
			break;
		case '2':
			char  pick;
			cout << "2D Calculator - chose an object to calculate" << endl
				<< " 1. squares\t2. triangles\t3. circles" << endl << endl;
			cin >> pick;
			switch (pick)
			{
			case '1':
				system("cls");
				cout << "you chose to calculte a square object" << endl;
				cout << "format: squareSide1 +/-/*// squareSide2" << endl;
				while (true)
				{
					cout << "> ";
					cin >> sx.side >> op >> sy.side;
					if (op == '/' && sy.side == 0)
					{
						cout << "zero division error" << endl;
						continue;
					}
					else
					{
						result = c.squareMathOperation(sx, op, sy);
						opCount++;
						result->calculate_area();
						result->calculate_paramiter();
						cout << " [" << opCount << "] " 
								 << " new square would have a side length of: " 
								 << result->side << endl
								 << " making a combined area of: " << result->area 
								 << " and a parameter of: " << result->parimeter << endl;
					}

					//cout << " [" << opCount << "] " << " new square would have a side length of: " << result.side << endl
					//<< " making a compined area of: " << result.area << " and a parameter of: " << result.parimeter << endl;
				}
				break;
			case '2':
				cout << "you chose to calculte a triangle object" << endl;

				break;
			case '3':
				cout << "you chose to calculte a circle object" << endl;
				
			case '4':
				cout << "you chose to calculate a 2D vector  << endl";
					

			default:
				break;
			}			
    		break;

 		case '3':
 			break;
		default:
			cout << "invalid operation";
	}
  
	return 0;

}
////////////////////////////////////////////////////////////////////////////
double squareLoop(int min, int max)
	{
		double totalLoop = 0;
		cout << "the square roots of the numbers from "<<min
				 << " to " << max << endl;
	 for(int i = min; i < max; i++){
		 cout << "Sqrt of # " << i << " is equal to: " << sqrt(i) <<endl;
		 totalLoop += sqrt(i);
	}
	return totalLoop;
}

char mainMenuChoice()
{	
	
		char temp;
		cout << "Console Calculator v1.0" << endl << endl;
		cout << "1) basic operation's" << endl;
		cout << "2) operations on 2D objects" << endl;
		cout << "3) operations on 3D objects" << endl;
		cout << "4) ***complex algebraic function menu***" << endl;
		cout << "5)***trigonometry and unit circle***stub" << endl;
		cout << "6) ***calculus operations***stub" << endl;
		cout << "Please enter menu option to what you want to calculate" << endl << endl;
		cin >> temp;
		
			if (!cin || temp < '1' || temp > '6') {
				do {
				cout << "enter a valid menu option [ 1 - 2 - 3 - 4 - 5 - 6 ]\n>";
					cin >> temp;
					cin.ignore(100, '\n');
					cin.clear();
				} while (!cin || temp < '1' || temp > '6');
			}
			return temp;
		}
		


/*


	cout << setprecision(8) << fixed;
	double x = 10.0;
	double y = 30.0; //*DEGREE;//(PI)/4*DEGREE;
	double z = 50.0;
	double t, k, l;
	//squareLoop(1, 10);
	//cout << squareLoop(1, 10);
	t = 0;
	k = x / z;
	l = 16;
	

	Shape testthing;
	testthing.shapes.squareObject.setArea(100);
	testthing.shapes.squareObject.showSquare();

	Shape testSquare;
	testSquare.shapes.squareObject.setSideLength(5);
	testSquare.shapes.squareObject.showSquare();
	string testerthing = "Square";
	Square test;
	Shape testSq; //= testthing + testSquare;
	test.side = testSq.makeNewSquare();
	test.adjust_all();
	
	//Shape test2;
	
	

	test.showSquare();
	test.setArea(36);
	test.showSquare();
	Square test2(100);
	test2.showSquare();
	Square test3 = test2 * 4.0/7.5;
	test3.showSquare();
	Vector v(40,45,'p');
	Vector v1(2,3, 'p');
	Vector v3 = v/v1;
	v3.showAllData();
	if (v > 40)
		 cout << "v is bigger" << endl;
  else if (v == 40)
  		 cout << "v and 40 are equal" << endl;
	 else if (v < 40)
	 			cout << "40 is bigger" << endl;
	 			else
	 			  cout << "dont know what is bigger" << endl;




*/
