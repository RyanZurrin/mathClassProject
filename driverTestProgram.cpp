/*______________________________________________________________________________
author:			Ryan Zurrin
program:		driverTestProgram.cpp
due date: 			5/11/2020
assignment:		Final Project - calcultor for 2D and 3D objects
______________________________________________________________________________*/
//#include "Shape.h"
#include "Input.h"

//using namespace std;

char mainMenuChoice();

double squareLoop(int, int);

int main()
{
	double x = 0.0;
	double y = 0.0;
	double results = 0.0;
	Square sx, sy;
	Square* sq_result = nullptr;
	Triangle tx, ty;
	Triangle* tri_result = nullptr;
	Vector vx, vy;
	Vector* vect_result = nullptr; 
	//result.area = 0;
	char op = '+';
	char menu = '1';
	int opCount = 0;
	Calculator c;
	

	Numbers ob;
	//ob.printOutMap(100, 1001);

	menu = mainMenuChoice();
  
  switch(menu)
  {
  	case '1': 
		system("cls");
		cout << "Basic Calculator - format:[ a + b | a - b | a * b | a / b  ]\n"
			 << "use a '~' as opperator to exit"  << endl;
		
  		while (true || !cin)
  		{			
			cout << "> ";
  			cin >> x >> op >> y; 

			if (op == '/' && y == 0)
			{
				cout << "zero division error" << endl;
				continue;
			}
			else if (!cin)
					{
						cout << "bad input entered" << endl;						
						cin.clear();
						cin.ignore(100, '\n');
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
				<< " 1. squares\t2. triangles\t3. 2dVectors" << endl << endl;
			cin >> pick;
			switch (pick)
			{
			case '1':
				system("cls");
				cout << "you chose to calculte a square object" << endl;
				cout << "format: squareSide1 +/-/*// squareSide2" << endl;
				cout << "use a '~' as opperator to exit" << endl;
				while (true)
				{
					cout << "> ";
					cin >> sx.side >> op >> sy.side;
					if (op == '/' && sy.side == 0)
					{
						cout << "zero division error" << endl;
						continue;
					}
					else if (!cin)
					{				
						cout << "bad input entered" << endl;
						cin.clear();
						cin.ignore(100,'\n');
						continue;
					}
					else
					{
						sq_result = c.squareMathOperation(sx, op, sy);
						opCount++;
						sq_result->calculate_area();
						sq_result->calculate_paramiter();
						cout << " [" << opCount << "] " 
								 << " new square has a side length of: " 
								 << sq_result->side << endl
								 << "with an area of: " << sq_result->area 
								 << " and a parameter of: " << sq_result->parimeter << endl;
					}					
				}
				break;
			case '2':
				cout << "you chose to calculte a triangle object" << endl;
				cout << "format: all #'s seperated by spaces\ntriangle1 sides: 1 2 3 \n"
					 << "than the operator you wish to apply +/-/*// \n"
					 << "finally triangle2 sides: 1 2 3. \n"
					 << "a:a b:b c:c ratios applied to sides" << endl;
				while (true)
				{
					cout << "> ";
					cin >>tx.side_a >>tx.side_b >> tx.side_c >> op >>ty.side_a >>ty.side_b >>ty.side_c ;
					if ((op == '/' &&  tx.side_a == 0) ||
						(op == '/' &&  tx.side_b == 0) ||
						(op == '/' &&  tx.side_c == 0) ||
						(op == '/' &&  ty.side_a == 0) ||
						(op == '/' &&  ty.side_b == 0) ||
						(op == '/' &&  ty.side_c == 0  ))					
					{
						cout << "zero division error" << endl;
						continue;
					}
					else if (!cin)
					{
						cout << "bad input entered" << endl;
						cin.clear();
						cin.ignore(100, '\n');
						continue;
					}
					else
					{
						tri_result = c.triangleMathOperation(tx, op, ty);
						opCount++;
						if (tri_result->isTriangle() == true) {
							tri_result->update_triangle();
							cout << " [" << opCount << "] "
								<< " new Triangle has the following properties:" << endl;
							tri_result->showTriangle();
						}
						else {
							cout << "the new triangle was not a good triangle try again" << endl;
							continue;
						}									
					}
				}
				break;
			case '3':
				cout << "you chose to calculte 2D Vectors object" << endl;
				cout << "format: spaces seperate the x and y values " << endl;
				cout << "Vector1 x y  +/-/*// Vector2 xy \n " 				
					 << "x1:x2  y1:y2 pattern of applied opperations" << endl;
				while (true)
				{
					cout << "> ";
					cin >> vx.x >> vx.y >> op >> vy.x >> vy.y >> ty.side_c;
					
					if (!cin)
					{
						cout << "bad input entered" << endl;
						cin.clear();
						cin.ignore(100, '\n');
						continue;
					}
					else
					{
						vect_result = c.vectorMathOperation(vx, op, vy);  
						opCount++;
										
							cout << " [" << opCount << "] "
								 << " The new Vector has the following properties:" << endl;
							vect_result->showAllData();			
						
						continue;						
					}
				}
				break;
				
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
			break;
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
		
