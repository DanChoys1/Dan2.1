#include <iostream>
#include <cmath>
#include "interface.h"

using namespace std;

const int all_test_passed = 5;

double ChordMethod(Interface interface);

Interface Test1(void) {
	Interface interface;

	interface.f.a = 1;

	interface.f.b = 0;
	interface.f.c = -18;
	interface.f.d = -83;

	interface.interval.left_border = 3;
	interface.interval.right_border = 8;

	interface.epsilon = 0.001;

	interface.result_obtained = ChordMethod(interface);

	if (abs(interface.result_obtained - 5.70512) < 0.00001) {
		interface.test_result = true;
		return interface;
	}
	else {
		interface.test_result = false;
		return interface;
	}

}

Interface Test2(void) {
	Interface interface;

	interface.f.a = 1;
	interface.f.b = 0;
	interface.f.c = 2;
	interface.f.d = -1;


	interface.interval.left_border = 0;
	interface.interval.right_border = 1;

	interface.epsilon = 0.01;

	interface.result_obtained = ChordMethod(interface);

	if (abs(interface.result_obtained - 0.45336) < 0.00001) {
		interface.test_result = true;
		return interface;
	}
	else {
		interface.test_result = false;
		return interface;
	}

}

Interface Test3(void) {
	Interface interface;

	interface.f.a = 1;
	interface.f.b = 1;
	interface.f.c = 2;
	interface.f.d = -9;

	interface.interval.left_border = -5;
	interface.interval.right_border = 5;

	interface.epsilon = 0.00001;

	interface.result_obtained = ChordMethod(interface);

	if (abs(interface.result_obtained - 1.53145) < 0.00001) {
		interface.test_result = true;
		return interface;
	}
	else {
		interface.test_result = false;
		return interface;
	}

}

Interface Test4(void) {
	Interface interface;

	interface.f.a = -1;
	interface.f.b = 6;
	interface.f.c = -2;
	interface.f.d = 0;

	interface.interval.left_border = -2;
	interface.interval.right_border = 10;

	interface.epsilon = 0.0001;

	interface.result_obtained = ChordMethod(interface);

	if (abs(interface.result_obtained + 0.0000000478675) < 0.0000000000001) {
		interface.test_result = true;
		return interface;
	}
	else {
		interface.test_result = false;
		return interface;
	}

}

Interface Test5(void) {
	Interface interface;

	interface.f.a = -1;
	interface.f.b = -9;
	interface.f.c = -10;
	interface.f.d = 8;

	interface.interval.left_border = -10;
	interface.interval.right_border = 22;

	interface.epsilon = 0.0001;

	interface.result_obtained = ChordMethod(interface);

	if (abs(interface.result_obtained + 7.53113) < 0.00001) {
		interface.test_result = true;
		return interface;
	}
	else {
		interface.test_result = false;
		return interface;
	}

}

void Test(void) {
	Interface interface;
	interface = Test1();
	int tests_passed = 0;

	if (interface.test_result == true) {
		tests_passed++;
	} else {
		cout << endl << "Test 1 failed" << endl
			<< "input data:" << endl
			<< "a = " << interface.f.a << endl
			<< "b = " << interface.f.b << endl
			<< "c = " << interface.f.c  << endl
			<< "d = " << interface.f.d << endl
			<< "point1 = " << interface.interval.left_border  << endl
			<< "point2 = " << interface.interval.right_border  << endl
			<< "epsilon = " << interface.epsilon << endl
			<< "Expected Result = 5.70512" << endl
			<< "The Result Obtained = " << interface.result_obtained  << endl;
	}

	interface = Test2();

	if (interface.test_result == true) {
		tests_passed++;
	} else {
		cout << endl << "Test 2 failed" << endl
			<< "input data:" << endl
			<< "a = " << interface.f.a << endl
			<< "b = " << interface.f.b << endl
			<< "c = " << interface.f.c << endl
			<< "d = " << interface.f.d << endl
			<< "point1 = " << interface.interval.left_border << endl
			<< "point2 = " << interface.interval.right_border << endl
			<< "epsilon = " << interface.epsilon << endl
			<< "Expected Result = 0.45336" << endl
			<< "The Result Obtained = " << interface.result_obtained << endl;
	}

	interface = Test3();

	if (interface.test_result == true) {
		tests_passed++;
	} else {
		cout << endl << "Test 3 failed" << endl
			<< "input data:" << endl
			<< "a = " << interface.f.a << endl
			<< "b = " << interface.f.b << endl
			<< "c = " << interface.f.c << endl
			<< "d = " << interface.f.d << endl
			<< "point1 = " << interface.interval.left_border << endl
			<< "point2 = " << interface.interval.right_border << endl
			<< "epsilon = " << interface.epsilon << endl
			<< "Expected Result = 1.53145" << endl
			<< "The Result Obtained = " << interface.result_obtained << endl;
	}

	interface = Test4();

	if (interface.test_result == true) {
		tests_passed++;
	} else {
		cout << endl <<  "Test 4 failed" << endl
			<< "input data:" << endl
			<< "a = " << interface.f.a << endl
			<< "b = " << interface.f.b << endl
			<< "c = " << interface.f.c << endl
			<< "d = " << interface.f.d << endl
			<< "point1 = " << interface.interval.left_border << endl
			<< "point2 = " << interface.interval.right_border << endl
			<< "epsilon = " << interface.epsilon << endl
			<< "Expected Result = -0.0000000478675" << endl
			<< "The Result Obtained = " << interface.result_obtained << endl;
	}

	interface = Test5();

	if (interface.test_result == true) {
		tests_passed++;
	} else {
		cout << endl << "Test 5 failed" << endl
			<< "input data:" << endl
			<< "a = " << interface.f.a << endl
			<< "b = " << interface.f.b << endl
			<< "c = " << interface.f.c << endl
			<< "d = " << interface.f.d << endl
			<< "point1 = " << interface.interval.left_border << endl
			<< "point2 = " << interface.interval.right_border << endl
			<< "epsilon = " << interface.epsilon << endl
			<< "Expected Result = -7.53113" << endl
			<< "The Result Obtained = " << interface.result_obtained << endl;
	}

	if (tests_passed == all_test_passed) {
		cout << "All tests passed" << endl;
	}

}

