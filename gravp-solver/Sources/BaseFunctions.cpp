#include "../Headers/BaseFunctions.h"
#include "../Headers/GaussianQuadrature.h"


double xi(int i, int N) {
	return 3 * i / N;
}

double e(int i, int N, double x) {
	const double x0 = xi(i - 1, N), x1 = xi(i, N), x2 = xi(i + 1, N);
	const double A = N / 3;

	if (x >= x0 && x <= x1)
		return A * (x - x0);
	if (x > x1 && x <= x2)
		return -A * (x - x1);
	return 0;
}

double de(int i, int N, double x) {
	const double x0 = xi(i - 1, N), x1 = xi(i, N), x2 = xi(i + 1, N);
	const double A = N / 3;

	if (x >= x0 && x <= x1)
		return A;
	if (x > x1 && x <= x2)
		return -A;
	return 0;
}

int rho(double x) {
	if (x > 1 && x <= 2)
		return 1;
	return 0;
}