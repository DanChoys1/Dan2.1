#include <iostream>
#include "interface.h"

using namespace std;

void Interface::Menu(void) {
	cout << "What do you want?" << endl
		<< "1)Enter data from the keyboard" << endl
		<< "2)Enter data from file" << endl
		<< "3)Test the program" << endl
		<< "Choice: ";
}