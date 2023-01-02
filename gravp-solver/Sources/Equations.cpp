#include "../Headers/Equations.h"
#include "../Headers/BaseFunctions.h"
#include "../Headers/GaussianQuadrature.h"
#include <cmath>
#include <iostream>

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
		B(i - 1, i) = inegrateQuad2(xi(i, N), xi(i + 1, N), dei);
		B(i, i - 1) = inegrateQuad2(xi(i, N), xi(i + 1, N), dei);
	}

	for (int i = 1; i < N; i++) {
		auto dei = [=](double x) { return de(i, N, x) * de(i, N, x); };
		B(i - 1, i - 1) = 2 * inegrateQuad2(xi(i - 1, N), xi(i, N), dei);
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