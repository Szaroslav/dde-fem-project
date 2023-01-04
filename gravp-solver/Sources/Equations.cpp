#include "../Headers/Equations.h"
#include "../Headers/BaseFunctions.h"
#include "../Headers/GaussianQuadrature.h"
#include <cmath>

using std::vector;
using Eigen::MatrixXd;
using Eigen::VectorXd;

MatrixXd BMatrix(int N) {
	MatrixXd B(N - 1, N - 1);
	for (int i = 0; i < N - 1; i++)
		for (int j = 0; j < N - 1; j++)
			B(i, j) = 0;

	for (int i = 1; i < N - 1; i++) {
		auto dei = [=](double x) { return de(i, N, x) * de(i + 1, N, x); };
		B(i - 1, i) = integrateQuad2(xi(i, N), xi(i + 1, N), dei);
		B(i, i - 1) = integrateQuad2(xi(i, N), xi(i + 1, N), dei);
	}

	for (int i = 1; i < N; i++) {
		auto dei = [=](double x) { return de(i, N, x) * de(i, N, x); };
		B(i - 1, i - 1) = 2 * integrateQuad2(xi(i - 1, N), xi(i, N), dei);
	}

	return B;
}

VectorXd LMatrix(int N) {
	VectorXd L(N - 1);
	const double PI = 3.14159265359;
	const double G = 6.674 * pow(10, -11);

	for (int i = 1; i < N; i++) {
		auto ei	 = [=](double x) { return e(i, N, x); };
		auto dei = [=](double x) { return de(i, N, x); };

		/*
		 * Integration of v(x)dx = e_j(x)dx over the interval [1, 2]
		 * ρ(x) = 1 only for x ∈ [1, 2], otherwise ρ(x) = 0
		 */
		double x0 = xi(i - 1, N), x1 = xi(i, N), x2 = xi(i + 1, N);
		double iv = 0;
		if (!(x0 < 1 && x2 < 1) || (x0 > 2 && x2 > 2)) {
			x0 = fmax(x0, 1), x1 = fmax(x1, 1), x1 = fmin(x1, 2), x2 = fmin(x2, 2);
			iv = 4 * PI * G * (integrateQuad2(x0, x1, ei) + integrateQuad2(x1, x2, ei));
		}

		L[i - 1] = 2.0 / 3 * integrateQuad2(xi(i - 1, N), xi(i, N), dei);
	}

	return L;
}