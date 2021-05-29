/*______________________________________________________________________________
author:			Ryan Zurrin
program:		calculatorCLI.cpp
due date: 			5/11/2020
assignment:		Final Project - calcultor for 2D and 3D objects
______________________________________________________________________________*/

#include "Input.h"

char mainMenuChoice();


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
	Vector3D v3x, v3y;
	Vector3D* vect3D_result = nullptr;
	Cube cx, cy;
	Cube* cube_result = nullptr;
	Sphere ox, oy;
	Sphere* orb_result = nullptr;
	//result.area = 0;
	char op = '+';
	char menu = '0';
	char choice;
	int opCount = 0;
	Calculator c;
	bool calculating = true;


	//Numbers ob;
//	ob.printOutMap(100, 1001);


	do{
		op = '+';
		choice = ' ';
		menu = mainMenuChoice();
		switch (menu)
		{
		//choice = '32';
		case '1':
			// REGULAR MATH PIcKED
			system("cls");
			cout << "using a '~' as the operator in a full math problem\n"
				 << "will give you the option to return to main menu or exit\n" << endl;
			cout << "Basic Calculator - format: (x) [+-*/] (y)\n";

			while (true && op != '~')
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
				else if (op != '~')
				{ // this is the output control for the basic  math
					results = c.basicMathOperation(x, op, y);
					opCount++;
				}
				cout << fixed << " [" << opCount << "] " << "= " << results << endl;
			}
			break;
		case '2':// Root menu for 2d object math
			system("cls");
			char  pick;
			cout << "2D Calculator - chose an object to calculate" << endl
				<< " 1. squares\t2. triangles\t3. 2dVectors" << endl << endl;
			cout << "> ";
			cin >> pick;

			switch (pick)
			{
			// SQUARE OBJECT MATH PICKED
			case '1': // subcases contain the 2d math selections
				system("cls");
				cout << "using a '~' as the operator in a full math problem\n"
					 << "will give you the option to return to main menu or exit\n" << endl;
				cout << "you chose to calculate a square object" << endl;
				cout << "Format Options available at moment:\n";
				cout << "format: (square1 side) [+-*/] (square2 side)" << endl;

				while (true && op != '~')
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
						cin.ignore(100, '\n');
						continue;
					}
					else if (op != '~')
					{ // this is the Square math output control
						sq_result = c.squareMathOperation(sx, op, sy);
						opCount++;
						sq_result->calculate_area();
						sq_result->calculate_paramiter();
						cout << fixed << " [" << opCount << "] "
							<< " new square has a side length of: "
							<< sq_result->side << endl
							<< "with an area of: " << sq_result->area
							<< " and a parameter of: " << sq_result->parimeter << endl;
					}
				}
				break;
			// TRIANGLE OBJECT MATH PICKD
			case '2':
				system("cls");
				cout << "using a '~' as the operator in a full math problem\n"
					 << "will give you the option to return to main menu or exit\n" << endl;
				cout << "you chose to calculate a triangle object" << endl;
				cout << "format: triangle1 sides <-( s1 s2 s3 ) [+-*/] ( s1 s2 s3 )-> triangle2 sides " << endl;
			//		<< "finally triangle2 sides: 1 2 3. \n"
			//		<< "a:a b:b c:c patern for calculation" << endl;
				while (true && op != '~')
				{
					cout << "> ";
					cin >> tx.side_a >> tx.side_b >> tx.side_c >> op >> ty.side_a >> ty.side_b >> ty.side_c;
					if ((op == '/' && tx.side_a == 0) ||
						(op == '/' && tx.side_b == 0) ||
						(op == '/' && tx.side_c == 0) ||
						(op == '/' && ty.side_a == 0) ||
						(op == '/' && ty.side_b == 0) ||
						(op == '/' && ty.side_c == 0))
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
					else if (op != '~')
					{
						tri_result = c.triangleMathOperation(tx, op, ty);
						opCount++;
						if (tri_result->checkTriangle() == true) {
							tri_result->update_triangle();
							cout << fixed << " [" << opCount << "] "
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
			// 2D vector math selected
			case '3':
				system("cls");
				cout << "using a '~' as the operator in a full math problem\n"
					 << "will give you the option to return to main menu or exit\n" << endl;
				cout << "you chose to calculate 2D Vectors, " << endl;
				cout << "rectangular coordinates are used as input" << endl;
				cout << "***addidtional 2D vector operators:\n  -'$' as operator will give distance between"
					 << "the two vectors." << endl;
				cout << "format: vector1 <-( x1, y1 ) [+-*/] ( x2, y2 )-> vector2" << endl;

				cout << "{ [x1:x2] , [y1:y2]} pattern of applied opperations" << endl;
				while (true && op != '~')
				{
					cout << "> ";
					cin >> vx.x >> vx.y >> op >> vy.x >> vy.y;

					if (!cin)
					{
						cout << "bad input entered" << endl;
						cin.clear();
						cin.ignore(100, '\n');
						continue;
					}
					else if (op != '~' &&  op != '$')
					{// this is the 2D vector math output control
						vect_result = c.vectorMathOperation(vx, op, vy);
						opCount++;
						vect_result->calculate_polar();
						vect_result->calculate_arcLength();
						cout << fixed << " [" << opCount << "] "
							<< " The new Vector has the following properties:" << endl;
						vect_result->showAllData();
						continue;
					}
					else if (op != '~' && op == '$') {
						cout << fixed << " [" << opCount << "] ";
						vect_result = c.vectorMathOperation(vx, op, vy);
						opCount++;
					//	vect_result->calculate_polar();
					//	vect_result->calculate_arcLength();

					}
				}
				break;

				  default:
					break;
			}
			break;

		case '3':
			system("cls");
			cout << "3D Calculator - chose an object to calculate" << endl
				<< " 1. Cubes\t2. Spheres\t3. 3dVectors" << endl << endl;
			cout << "> ";
			cin >> pick;
			switch (pick)
			{
			case '1':
				system("cls");
				cout << "using a '~' as the operator in a full math problem\n"
					 << "will give you the option to return to main menu or exit\n" << endl;
				cout << "you chose to calculate a cube object" << endl;
				cout << "format: (cube1 edge) [+-*/] (cube2 edge)" << endl;
				cout << "use a '~' as opperator to exit" << endl;

				while (true && op != '~')
				{
					cout << "> ";
					cin >> cx.edgeLenght >> op >> cy.edgeLenght;
					if (op == '/' && cy.edgeLenght == 0)
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
					else if (op != '~')
					{ // cube math output control
						cube_result = c.cubeMathOperation(cx, op, cy);
						opCount++;
						if (cube_result!=nullptr)
						{
							cube_result->calculate_volume();
							cube_result->calculate_surface_area();


						cout << " [" << opCount << "] "
							<< " new cube has a side length of: "
							<< cube_result->edgeLenght << endl
							<< "with an area of: " << cube_result->volume
							<< " and a parameter of: " << cube_result->surfaceArea << endl;
						}
					}
				}
				break;

			case '2':
				system("cls");
				cout << "using a '~' as the operator in a full math problem\n"
					 << "will give you the option to return to main menu or exit\n" << endl;
				cout << "you chose to calculate a sphere object" << endl;
				cout << "(Sphere1 {radius}) [+-/*] (Sphere2 {radius})" << endl;
				while (true && op != '~')
				{
					cout << "> ";
					cin >> ox.radius >> op >> oy.radius;
					if ((op == '/' && oy.radius <= 0))
					{
						cout << "zero division error" << endl;
						continue;
					}
					else if (!cin || ox.radius <= 0 || oy.radius <= 0)
					{
						cout << "bad input entered" << endl;
						cin.clear();
						cin.ignore(100, '\n');
						continue;
					}
					else if (op != '~')
					{
						orb_result = c.sphereMathOperation(ox, op, oy);
						opCount++;
						orb_result->calculate_diameter();
						orb_result->calculate_volume();
						orb_result->calculate_surfaceArea();
						orb_result->calculate_circumfrance();
							cout << " [" << opCount << "] "
								<< " new Sphere has the following properties:" << endl;
							orb_result->showSphereData();
					}
				}
				break;
			case '3':
				system("cls");
				cout << "using a '~' as the operator in a full math problem\n"
					 << "will give you the option to return to main menu or exit\n" << endl;
				cout << "you chose to calculate 3D Vectors object, " << endl;
				cout << "***addidtional 3D vector operators:\n  -'$' as operator will give distance between"
					<< "the two vectors." << endl;
				cout << "Vector1: x1 y1 z1 (+/-/*//)  Vector2: x2 y2 z2 \n "
					<< "{[x1:x2, y1:y2, z1:z2]} pattern of applied opperations" << endl;
				while (true && op != '~')
				{
					cout << "> ";
					cin >> v3x.x >> v3x.y >> v3x.z >> op >> v3y.x >> v3y.y >> v3y.z;

					if (!cin)
					{
						cout << "bad input entered" << endl;
						cin.clear();
						cin.ignore(100, '\n');
						continue;
					}
					else if (op != '~' && op != '$')
					{
						vect3D_result = c.vector3DMathOperation(v3x, op, v3y);
						opCount++;
						vect3D_result->set_allAngles();
						cout << " [" << opCount << "] "
							<< " The new Vector has the following properties:" << endl;
						vect3D_result->showAllData();
						continue;
					}
					else if (op != '~' && op == '$') {
						cout << fixed << " [" << opCount << "] ";
						vect3D_result = c.vector3DMathOperation(v3x, op, v3y);
						opCount++;
						//vect3D_result->calculate_polar();
						//vect3D_result->calculate_arcLength();
					}
				}
				break;
			case '4':
				cout << "Thank you for using the Object calculator ver 1.1\n"
				<< "Look out for new features to be added on GitHub Regularly\n"
				<< "https://github.com/RyanZurrin/mathClassProject";
				calculating = false;
				break;

			default:
				cout << "invalid operation";
				break;
			}
		}
		cout << "[y/Y] to return to main menu, anything else will exit";
		cin >> choice;
		if (toupper(choice) != 'Y' || !cin) {
			return 0;
		}
		//cin.clear();
		//cin.ignore(100, '\n');

	}while (toupper(choice) == 'Y' && calculating == true);


	return 0;
}
////////////////////////////////////////////////////////////////////////////


char mainMenuChoice()
{
	system("cls");

		char temp;
		cout << "Console Calculator v1.0" << endl;
		cout << "built by Ryan Zurrin" << endl << endl;
		cout << "1) basic operation's" << endl;
		cout << "2) operations on 2D objects" << endl;
		cout << "3) operations on 3D objects" << endl << endl;
		cout << "4) exit program" << endl<<endl;
		cout << "Please enter menu option to what you want to calculate" << endl << endl;
		cin >> temp;

			if (!cin || temp < '1' || temp > '4') {
				do {
				cout << "enter a valid menu option [ 1 - 2 - 3 ]\n>";
					cin >> temp;
					cin.clear();
					cin.ignore(100, '\n');

				} while (!cin || temp < '1' || temp > '6');
			}
			return temp;
		}

