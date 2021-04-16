#include <iostream>
#include "structures.h"

double Function(FunctionCoefficients f, double x) {
	return f.a * x*x*x + f.b * x*x + f.c * x + f.d;
}
