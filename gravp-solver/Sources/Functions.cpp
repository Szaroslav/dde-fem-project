#include "../Headers/Functions.h"

extern int N;

double xi(int i) {
	return 3.0 * i / N;
}

double e(int i, double x) {
	const double x0 = xi(i - 1), x1 = xi(i), x2 = xi(i + 1);
	const double A = N / 3.0;

	if (x >= x0 && x <= x1)
		return A * (x - x0);
	if (x > x1 && x <= x2)
		return -A * (x - x2);
	return 0;
}


double de(int i, double x) {
	const double x0 = xi(i - 1), x1 = xi(i), x2 = xi(i + 1);
	const double A = N / 3.0;

	if (x >= x0 && x <= x1)
		return A;
	if (x > x1 && x <= x2)
		return -A;
	return 0;
}

double w(Eigen::VectorXd Wi, double x) {
	double result = 0;
	for (int i = 1; i < N; i++)
		result += Wi(i - 1) * e(i, x);

	return result;
}

double phi(Eigen::VectorXd Wi, double x) {
	return 5 - x / 3 + w(Wi, x);
}