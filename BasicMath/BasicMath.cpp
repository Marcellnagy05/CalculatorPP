#include "BasicMath.h"
#include <stdexcept>

namespace BasicMath {
	BasicCalculator::BasicCalculator() : lastResult(0.0){}


	double BasicCalculator::pow(double base, double exp) {
		double result = 1.0;
		if (exp == 0) {
			return result;
		}

		return result;
	};

	double BasicCalculator::sqrt(double base, double exp) {
		double result;
		if (exp == 0) {
			throw std::runtime_error("ERROR! Squarerooting by 0!");
			return;
		}


		return result;
	};
}