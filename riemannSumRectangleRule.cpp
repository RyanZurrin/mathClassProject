#include <iostream>
#include <cmath>
using namespace std;

double f(double);

int main()
{
	
	double S = 0;	
	double a = -6;
	double b = 4;
	double n = 4;
	double d = (b-a)/(n);
	
	for(int k = 1; k<n; k++)
	{
		S = S + f(a+(k*d))*d;
	} 
	cout << "S= "<<S<<endl;
}

double f(double x){
	return (x-1);
}
