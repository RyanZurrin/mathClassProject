#ifndef EXCEPTIONHANDLER_H
#define EXCEPTIONHANDLER_H
#include <iostream>
#include <map>
#include "Vector3D.h"
#include "vect.h"
#include "Numbers.h"
using namespace std;

typedef long double ld;

/*
const ld PI		 = 3.1415926535898;
const ld DEGREE = 180/PI;
const ld RADIAN = PI/180; 
*/

class ExceptionHandler //: public std::runtime_error
{
	friend class Vector3D;
	private:
		void addErrorToList(int, string);

	protected:
		int exceptionCode;
		string exceptionSource;
		string exceptionMessage;
		map<int, string> error_codes;

		

	public:
		bool checkedFlag;
		ExceptionHandler();
		ExceptionHandler(int);
		void checkErrorCode(int)const;
		template<typename T> T zeroDivisorCheck(T);
		template<typename T> T zeroDivideFix(T);
		//bool zeroDivisorCheck(ld);
		//bool zeroDivisorCheck(ld, ld, ld);
		bool negitiveNumberCheck(ld);
		string getExceptionSource(string);
		string getExceptionMessage(string);
		int getExceptionCode(int);

};
#endif

template<typename T>
inline T ExceptionHandler::zeroDivisorCheck(T num)
{
	if (num == 0)
		return 1;
	else
		return 0;
}

template<typename T>
inline T ExceptionHandler::zeroDivideFix(T num)
{
	if (checkedFlag == false && num == 0) {
		do {
			cout << "You cannot divide by zero, please enter a new number\n>:";
			cin >> num;
			return num;
			cin.ignore(100, '\n');
			cin.clear();
		} while (!cin || num == 0);
	}
	return num;
}
