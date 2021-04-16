#pragma once

#include "structures.h"

class Interface final {
public:
	FunctionCoefficients f;
	Interval interval;
	double epsilon;
	bool test_result;
	double result_obtained;

	void Greeting(void);

	void Menu(void);

	void KeyboardInterface(void);

	bool FileInterface(void);

	void SaveInputData(void);

	void SaveResult(void);
};
