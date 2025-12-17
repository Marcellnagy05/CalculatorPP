#include "SimpleMath.h"
#include <cmath>
#include <stdexcept>

namespace SimpleMath {
	Calculator::Calculator() : lastResult(0.0) {}

	void Calculator::updateLastResult(double result) {
		lastResult = result;
	}

	double Calculator::add(double a, double b) {
		double result = a + b;
		updateLastResult(result);
		return result;
	}

	double Calculator::sub(double a, double b) {
		double result = a - b;
		updateLastResult(result);
		return result;
	}

	double Calculator::mult(double a, double b) {
		double result = a * b;
		updateLastResult(result);
		return result;
	}

	double Calculator::div(double a, double b) {
		if (b == 0.0) {
			throw std::runtime_error("Division by zero!");
		}
		double result = a / b;
		updateLastResult(result);
		return result;
	}

	double Calculator::percentage(double base, double percentage) {
		double result = base * (percentage / 100);
		updateLastResult(result);
		return result;
	}

	double Calculator::changeSign(double value) {
		double result = value * (-1);
		updateLastResult(result);
		return result;
	}

	void Calculator::reset() {
		lastResult = 0.0;
	}
}
