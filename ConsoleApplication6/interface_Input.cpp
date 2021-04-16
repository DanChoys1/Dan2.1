#include <iostream>
#include <fstream>
#include <string>
#include "interface.h"
#include "open_file.h"

using namespace std;

enum IncorrectInput {
	INCORRECT_A,
	INCORRECT_INTERVAL,
	INCORRECT_EPSILON
};

enum Opening {
	FAILED,
	COMPLITE
};

double GetDouble(void);
double Function(FunctionCoefficients f, double x);

void Interface::KeyboardInterface(void) {
	cout << "Enter a: ";

	do {
		f.a = GetDouble();

		if (f.a == 0) {
			cout << "a should not = 0." << endl << "Enter a: ";
		}

	} while (f.a == 0);

	cout << "Enter b: ";
	f.b = GetDouble();

	cout << "Enter c: ";
	f.c = GetDouble();

	cout << "Enter d: ";
	f.d = GetDouble();

	cout << "Enter interval:" << endl;

	do {
		cout << "Enter point1 = ";
		interval.left_border = GetDouble();

		cout << "Enter  point2 = ";
		interval.right_border = GetDouble();

		if (!((Function(f, interval.left_border) > 0 && Function(f, interval.right_border) < 0)
			|| (Function(f, interval.right_border) > 0 && Function(f, interval.left_border) < 0))) {
			cout << "Function at point 2 must be = - functions at point 1" << endl << "Try again:" << endl;
		}

	} while (!((Function(f, interval.left_border) > 0 && Function(f, interval.right_border) < 0)
		|| (Function(f, interval.right_border) > 0 && Function(f, interval.left_border) < 0)));


	do {
		cout << "Enter Epsilon = ";
		epsilon = GetDouble();

		if (epsilon <= 0) {
			cout << "Epsilon must be >  0" << endl << "Try again:" << endl;
		}

	} while (epsilon <= 0);

}

bool Interface::FileInterface(void) {
	ifstream file;
	file = OpenFileInput();

	try {
		string value;

		getline(file, value);
		f.a = stod(value);

		if (f.a == 0) {
			throw INCORRECT_A;
		}

		getline(file, value);
		f.b = stod(value);

		getline(file, value);
		f.c = stod(value);

		getline(file, value);
		f.d = stod(value);

		getline(file, value);
		interval.left_border = stod(value);

		getline(file, value);
		interval.right_border = stod(value);

		if (!((Function(f, interval.left_border) > 0 && Function(f, interval.right_border) < 0)
			|| (Function(f, interval.right_border) > 0 && Function(f, interval.left_border) < 0))) {
			throw INCORRECT_INTERVAL;
		}

		getline(file, value);
		epsilon = stod(value);

		if (epsilon <= 0) {
			throw INCORRECT_EPSILON;
		}

		file.close();

		cout << "Data retrieved from file" << endl;
		cout << "a = " << f.a << endl;
		cout << "b = " << f.b << endl;
		cout << "c = " << f.c << endl;
		cout << "d = " << f.d << endl;
		cout << "left_border = " << interval.left_border << endl;
		cout << "right_border = " << interval.right_border << endl;
		cout << "epsilon = " << epsilon << endl;

	} catch (IncorrectInput incorrect) {

		if (incorrect == INCORRECT_A) {
			cout << "Value 'a' in the file are not correct. a coud not = 0" << endl;
		} else if (incorrect == INCORRECT_INTERVAL) {
			cout << "Interval value in the file are not correct. Function at point 2 must be = - functions at point 1" << endl;
		} else if (incorrect == INCORRECT_EPSILON) {
			cout << "Value 'epsilon' in the file are not correct. Epsilon must be >  0" << endl;
		}

		file.close();
		return FAILED;
	} catch (invalid_argument inv_arg) {
		cout << "The values in the file are not correct" << endl;
		file.close();
		return FAILED;
	}

	return COMPLITE;
}
