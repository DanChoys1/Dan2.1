#include <cmath>
#include "interface.h"
#include "structures.h"

double Function(FunctionCoefficients f, double x);

double ChordMethod(Interface interface) {
	Interval save_interval;
	save_interval.left_border = interface.interval.left_border;
	save_interval.right_border = interface.interval.right_border;

	while (fabs(save_interval.right_border - save_interval.left_border) > interface.epsilon) {

		save_interval.left_border = save_interval.right_border - (save_interval.right_border - save_interval.left_border)
			* Function(interface.f, save_interval.right_border) / (Function(interface.f, save_interval.right_border)
			- Function(interface.f, save_interval.left_border));

		save_interval.right_border = save_interval.left_border - (save_interval.left_border - save_interval.right_border)
			* Function(interface.f, save_interval.left_border) / (Function(interface.f, save_interval.left_border)
			- Function(interface.f, save_interval.right_border));
	}

	return save_interval.right_border;
}