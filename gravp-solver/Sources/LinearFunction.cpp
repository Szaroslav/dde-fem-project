#include "../Headers/GaussianQuadrature.h"

double e(double x, int i, int N) {
	const double x0 = 3 * (i - 1) / N, x1 = 3 * i / N, x2 = 3 * (i + 1) / N;
	const double A = N / 3;

	if (x >= x0 && x <= x1)
		return A * (x - x0);
	if (x > x1 && x <= x2)
		return -A * (x - x1);
	return 0;
}