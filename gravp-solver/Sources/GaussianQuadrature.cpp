#include "../Headers/GaussianQuadrature.h"

double integrateQuad2(double a, double b, std::function<double(double)> f) {
	const double x1 = -1 / sqrt(3), x2 = 1 / sqrt(3);
	const double w = 1;
	const double c1 = (b - a) / 2, c2 = (a + b) / 2;

	return c1 * w * (f(c1 * x1 + c2) + f(c1 * x2 + c2));
}