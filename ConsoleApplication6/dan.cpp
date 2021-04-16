#include <iostream>
#include "interface.h"
#include "formatting_input.h"

using namespace std;

enum ChoiceTypeInput {
	CHOICE_KEYBOARD = 1,
	CHOICE_FILE,
	CHOICE_TESTING
};

const int REPEAT = 1;

double ChordMethod(Interface interface);
void Test(void);

int main() {
	Interface interface;

	interface.Greeting();

	int choice = 0;

	do {
		interface.Menu();

		choice = GetInt(); 

		switch (choice) {
		case CHOICE_KEYBOARD:
			interface.KeyboardInterface();
			
			interface.result_obtained = ChordMethod(interface);
			cout << "x = " << interface.result_obtained << endl;

			interface.SaveInputData();

			interface.SaveResult();

			break;
		case CHOICE_FILE:
			bool opening_file;
			opening_file = interface.FileInterface();

			if (opening_file == true) {
				interface.result_obtained = ChordMethod(interface);
				cout << "x = " << interface.result_obtained << endl;
				interface.SaveResult();
			}
			
			break;
		case CHOICE_TESTING:
			Test();
			break;
		default:
			cout << "There is no such action" << endl;
		}
		
		cout << endl << "Do you want to repeat the program?" << endl
			<< "1 - YES" << endl
			<< "Another key - NO" << endl
			<< "Choice: ";
		cin >> choice;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

	} while (choice == REPEAT);

	return 0;
}
