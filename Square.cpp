#include "Square.h"
#include "exceptionHandler.h"
/*______________________________________________________________________________
*/
Square::Square()
{
    //totalLinesInShape = 4;
    _sqrPtr = nullptr;
    side = 0;
    area = 0;
    parimeter = 0;
   // mode = 's';
    //ExceptionHandler negChecker;
   // cout << "Enter single side Length: ";
   //o/// cin >> side;
    //negChecker.negitiveNumCheck(side);
    //adjust_all();
}

Square::Square(const Square& s)
{  
    cout << "in copy constructor";
    _sqrPtr = s._sqrPtr;
    setArea(s.area);
    calculate_side_from_area();
    calculate_paramiter(); 
}

Square::Square(double a)
{
     if (a > 0)
        side = a;
    else {
        do {
            cout << "Enter a value greater than zero;\n>";
            cin >> a;
            cin.ignore(100, '\n');
            cin.clear();
        } while (!cin || a < 0);
    } 
     calculate_area();
    calculate_paramiter();
}

/*______________________________________________________________________________
*/
void Square::showSquare()const
{
    showSideLength();
    showArea();
    showParimeter();
}
void Square::showSideLength()const
{
    cout << "side lenght: " << side << endl;
}
void Square::showArea() const
{
    cout << "area: " << area << endl;
}
void Square::showParimeter() const
{
    cout << "Parimeter: " << parimeter << endl;
}
/*______________________________________________________________________________
                 private member fucntions for keeping data from getting stale*/

void Square::adjust_all()
{
    calculate_area();
    calculate_paramiter();

}
void Square::calculate_area()
{
    area = side * side;
}

void Square::calculate_paramiter()
{
    parimeter = side * 4;
}

void Square::calculate_side_from_area()
{
    side = sqrt(area);
    calculate_paramiter();
}

void Square::calculate_side_from_paramiter()
{
    side = parimeter / 4;
    calculate_area();
}
/*______________________________________________________________________________
                                               overloading the = operator*/
const Square Square::operator=(const Square& right)
{
    Square temp;
    cout << "in the overloaded =operator";
    if (this != &right) {                     
        temp.side = right.side;
        temp.adjust_all();
        this->side = temp.side;
        adjust_all();
    }    
    return *this;
}
/*
const Square Square::operator=(const TwoDimensional& right)
{
    cout << "in the overloaded =operator 2D";
    
        delete this;
        side = right.squareObject.returnSquareSide();
        adjust_all();
        return *this;
  
}

*/

void Square::setSideLength(double num)
{
    //ExceptionHandler negnumchecker;
   // negnumchecker.negativeNumCheck(num);
    side = num;
    adjust_all();
}

void Square::setArea(double num)
{
   // ExceptionHandler negnumchecker;
   // negnumchecker.negativeNumCheck(num);
    double temp;
    temp = num;
    if (temp > 0)
        num = abs(temp);
    area = num;
    side = sqrt(area);
    parimeter = 4 * side;
   // calculate_side_from_area();
    //calculate_paramiter();
}

void Square::setParimeter(double num)
{
    ExceptionHandler negnumchecker;
    negnumchecker.negativeNumCheck(num);
    area = num;
    calculate_side_from_paramiter();
    calculate_area();
}

/*______________________________________________________________________________
                                               overloaded addition opperators*/

Square Square::operator+()const
{
    cout << "in  Square::operator+()const" << endl;
    Square total(area + area);
    return total;
}
Square Square::operator++()
{
    cout << "in  SSquare::operator++() " << endl;
    Square sum(++side);
    return sum;
}
Square Square::operator++(int)
{
    cout << "in  Square::operator++(int) " << endl;
    Square sum(side++);
    return sum;
}
Square Square::operator+(double num)const
{
    cout << "in  Square::operator+(double num)const " << endl;
    return Square(pow((sqrt(area) + num), 2));
}
Square Square::operator+(const Square& s)const
{
    cout << "in  Square::operator+(const square& s)const" << endl;
    Square sum(area + s.area);
    return sum;
}
Square& Square::operator+=(const Square& rhs)
{
    
    area += rhs.area;
    calculate_side_from_area();
    calculate_paramiter();
    return *this;
}

Square operator+(double s, Square& sd)
{
    cout << "in  Squareoperator+(double s, Square& sd)" << endl;
    Square total;
    total.side = sd.side + s;
    total.adjust_all();
    return total;
}
Square operator+(Square lhs, const Square& rhs)
{
    lhs += rhs; // reuse compound assignment
    return lhs; // return the result by value (uses move constructor)  
}
/*______________________________________________________________________________
                                           overloaded subtraction opperators*/
Square Square::operator-()const
{
    cout << "in  Square::operator-()const" << endl;
    Square total(area - area);
    return total;
}
Square Square::operator--()
{
    cout << "in  SSquare::operator--() " << endl;
    Square sum(--side);
    return sum;
}
Square Square::operator--(int)
{
    cout << "in  Square::operator--(int) " << endl;
    Square sum(side--);
    return sum;
}
Square Square::operator-(double num)const
{
    cout << "in  Square::operator-(double num)const " << endl;
    return Square(pow((sqrt(area) - num), 2));
}
Square Square::operator-(const Square& s)const
{
    cout << "in  Square::operator-(const square& s)const" << endl;
    Square sum(area - s.area);
    return sum;
}
Square& Square::operator-=(const Square& rhs)
{
   
    area -= rhs.area;
    calculate_side_from_area();
    calculate_paramiter();
    return *this;
}

Square operator-(double s, Square& sd)
{
    cout << "in  Squareoperator-(double s, Square& sd)" << endl;
    Square total;
    total.side = sd.side - s;
    total.adjust_all();
    return total;
}
Square operator-(Square lhs, const Square& rhs)
{
    lhs -= rhs; // reuse compound assignment
    return lhs; // return the result by value (uses move constructor)  
}
Square operator*(double scaler, Square& square)
{
    return Square(square.side * scaler);
}
Square operator*(Square& v, Square& s)
{
    Square results(pow((v.side * s.side), 2));
    return results;
}
/*______________________________________________________________________________
                                         other overloaded opperators*/
Square Square::operator*(double _side)const
{
    return Square(pow((sqrt(area) * _side), 2));
}

Square Square::operator/(double _side)
{
    return Square(pow((sqrt(area) / _side), 2));
}

Square Square::operator/(const Square& s)
{
	return Square(pow((sqrt(area) / s.side), 2));
}
/*
double& Square::operator[](double& n)
{
    if (n < 0 || n >= 10)
        cout << "tomany squares in box";

    return n;
    // TODO: insert return statement here
}
Square& Square::operator[](Square& sqr)
{
    return *this;
    // TODO: insert return statement here
}
*/
/*
Square::operator double()
{
    double temp = area;
    return temp;
}

Square::operator float()
{
	float temp = area;
	return temp;
}

Square::operator int()
{
    area = round(area);
    int temp = area;
    return temp;
	
}

Square::operator string()
{
    string temp = to_string(area);
    return temp;
}
*/

