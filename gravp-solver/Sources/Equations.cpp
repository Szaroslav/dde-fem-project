#include "../Headers/Equations.h"
#include "../Headers/BaseFunctions.h"
#include "../Headers/GaussianQuadrature.h"
#include <cmath>

using std::vector;
using Eigen::SparseMatrix;
using Eigen::VectorXd;

SparseMatrix<double> BMatrix(int N) {
	SparseMatrix<double> B(N - 1, N - 1);

	for (int i = 0; i < N - 1; i++) {
		auto dei = [=](double x) { return de(i, N, x) * de(i + 1, N, x); };
		B.insert(i, i + 1) = inegrateQuad2(xi(i + 1, N), xi(i + 2, N), dei);
		B.insert(i + 1, i) = inegrateQuad2(xi(i + 1, N), xi(i + 2, N), dei);
	}

	for (int i = 0; i < N - 1; i++) {
		auto de0 = [=](double x) { return de(i, N, x) * de(i, N, x); };
		auto de1 = [=](double x) { return de(i + 1, N, x) * de(i + 1, N, x); };
		B.insert(i, i) = inegrateQuad2(xi(i, N), xi(i + 1, N), de0) + inegrateQuad2(xi(i + 1, N), xi(i + 2, N), de1);
	}

	return B;
}

VectorXd LMatrix(int N) {
	VectorXd L(N - 1);
	const double PI = 3.14159265359;
	const double G = 6.674 * pow(10, -11);

	for (int i = 0; i < N - 1; i++) {
		auto rhoei  = [=](double x) { return rho(x) * e(i, N, x); };
		auto dei    = [=](double x) { return de(i, N, x) * de(i + 1, N, x); };
		L[i] = 2 / 3 * inegrateQuad2(xi(i, N), xi(i + 1, N), dei) - 4 * PI * G * (inegrateQuad2(xi(i, N), xi(i + 1, N), rhoei) + inegrateQuad2(xi(i + 1, N), xi(i + 2, N), rhoei));
	}

	return L;
}