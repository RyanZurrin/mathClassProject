#include <iostream>
#include <cmath>
#define pi 3.14159265358989

using namespace std;

double A = 0;
double a = 0;
double B = 0;
double b = 0;
double C = 0;
double c = 0;
double areavar;
double area;


void degrad();//Converts Degrees to Radians
void raddeg();//Converts Radians to Degrees
void missang();//Finds the missing angle if two are known in a triangle
void los();//Law of Sines
void loc();//Law of Cosines
void printhead();//Prints the title screen
void angcheck();//Checks for an angle >180


int main()
{
    printhead();

    cout << "Hello, This program will solve a triangle given certain information." << endl;
    cout << "Note, It does not have to be a right triangle." << endl;
    system("pause");
    system("cls");
    cout << "Enter any information that you know (Angles in degrees) (If you dont, enter 0)" << endl;
    system("pause");
    system("cls");

    //Enter known parts
    cout << "m<A = "; cin >> A;
    cout << "a = "; cin >> a;
    cout << "m<B = "; cin >> B;
    cout << "b = "; cin >> b;
    cout << "m<C = "; cin >> C;
    cout << "c = "; cin >> c;

    angcheck();

    missang();
    degrad();


    for (int i = 1; i != 10; i++)
    {

        los();
        raddeg();
        missang();
        degrad();
        loc();
        raddeg();
        missang();
        degrad();
    }

    raddeg();


    system("cls");
    cout << "The Solution of the triangle is:" << endl << endl;
    cout << "m<A = " << A << endl;
    cout << "a = " << a << endl;
    cout << "m<B = " << B << endl;
    cout << "b = " << b << endl;
    cout << "m<C = " << C << endl;
    cout << "c = " << c << endl << endl;



    area = 1/2 * a * b * sin(C);

    cout << "The area is " << area << endl;
    cout << "The perimiter is " << a + b + c << endl << endl;

    system("pause");




    return 0;
}

void degrad()
{
    //Converts degrees to radians
    A = A * (pi / 180);
    B = B * (pi / 180);
    C = C * (pi / 180);
}

void raddeg()
{
    //Converts radians back to degrees for final answer
    A = A * (180 / pi);
    B = B * (180 / pi);
    C = C * (180 / pi);
}

void los()
//Uses Law of Sines
{
    for (int i = 1; i <= 10; i++)
    {
        //solves for a
        if (C != 0 && c != 0 && A != 0)
        {
                a = (sin(A) * c) / sin(C);
        }



        //Solves for b
        else if (A != 0 && a != 0 && B != 0)
        {
                b = (sin(B) * a) / sin(A);
        }


        //Solves for c
        else if (A != 0 && a != 0 && C!= 0)
        {
                c = (sin(C) * a) / sin(A);
        }

        //Solves for A
        else if (C != 0 && c != 0 && a != 0)
        {
                A = asin((a * sin(B) / b));
        }

        //Solves for B
        else if (A != 0 && a != 0 && B != 0)
        {
                B = asin((b * sin(A) / a));
        }

        //Solves for C
        else if (B != 0 && b != 0 && c != 0)
        {
                C = asin((c * sin(B) / b));
        }

        else if (A != 0 && a != 0 && B != 0 && b != 0 && C != 0 && c != 0)
        {
            break;
        }
    }
}

void missang()
//Finds the missing angle if only 2 are entered
{
    //Finds A
    if (A == 0 && B != 0 && C != 0)
    {
        A = 180 - C - B;
    }

    //Finds B
    else if (A != 0 && B == 0 && C !=0)
    {
        B = 180 - A - C;
    }

    //Finds C
    else if (A != 0 && B != 0 && C == 0)
    {
        C = 180 - A - B;
    }

}

void loc()
//Uses Law of cosines.
{
    for (int i = 1; 1 <= 10; i++)
    {
        //Solves for a
        if (A != 0 && b != 0 && c != 0)
        {
            a = sqrt( b*b + c*c -2*b*c*cos(A));
        }

        //Solves for b
        else if (B != 0 && a != 0 && c != 0)
        {
            b = sqrt( a*a + c*c - 2*a*c*cos(B));
        }

        //Solves for c
        else if (C != 0 && a != 0 && b !=0)
        {
            c = sqrt( a*a + b*b - 2*a*b*cos(C));
        }

        //Solves for A FIX
        else if (a != 0 && b != 0 && c != 0 && A == 0)
        {
            A = acos((b*b + c*c - a*a) / 2*b*c);
        }

        //Solves for B
        else if (a != 0 && b != 0 && c != 0 && B == 0)
        {
            B = acos((a*a + c*c - b*b) / 2*a*c);
        }

        //Solves for C
        else if (a != 0 && b != 0 && c != 0 && C == 0)
        {
            C = acos((a*a + b*b - c*c) / 2*a*b);
        }
    }
}

void printhead()
{
    cout << " -------------------------------------------------------------" << endl;
    cout << "                  Welcome to Triangle Solver                  "   << endl;
    cout << " -------------------------------------------------------------" << endl << endl;
}

void angcheck()
{
    if (A >= 180 || B >= 180 || C >= 180)
    {
        cout << "Error, one or more angle(s) is/are too large. Please try again." << endl;
        system("pause");
    }
}
