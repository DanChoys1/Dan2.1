#include <iostream>
#include <fstream>
#include "interface.h"
#include "open_file.h"

using namespace std;

const int SAVE_DATA = 1;

void Interface::SaveInputData(void) {
	cout << "Do you want to save the initial data in a file?" << endl;
	cout << "a = " << f.a << endl;
	cout << "b = " << f.b << endl;
	cout << "c = " << f.c << endl;
	cout << "d = " << f.d << endl;
	cout << "left_border = " << interval.left_border << endl;
	cout << "right_border = " << interval.right_border << endl;
	cout << "epsilon = " << epsilon << endl;
	cout << "1 - YES" << endl
		<< "Another key - NO" << endl
		<< "Choice: ";
	int choice = 0;
	cin >> choice;
	cin.clear(); 
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	if (choice == SAVE_DATA) {
		ofstream file;
		file = OpenFileOutput();
		file << f.a << endl;
		file << f.b << endl;
		file << f.c << endl;
		file << f.d << endl;
		file << interval.left_border << endl;
		file << interval.right_border << endl;
		file << epsilon << endl;

		file.close();
	}

};

void Interface::SaveResult(void) {
	int choice = 0;

	cout << "Do you want to save the result of the program?" << endl;
	cout << "x = " << result_obtained << endl;
	cout << "1 - YES" << endl
		<< "Another key - NO" << endl
		<< "Choice: ";
	cin >> choice;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	if (choice == SAVE_DATA) {
		ofstream file;
		file = OpenFileOutput();

		file << result_obtained;

		file.close();
	}

}