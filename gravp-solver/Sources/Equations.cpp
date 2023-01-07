#include "../Headers/Equations.h"

using std::vector;
using Eigen::SparseMatrix;
using Eigen::VectorXd;
using Eigen::Triplet;

typedef Triplet<double> TD;

extern int N;

SparseMatrix<double> BMatrix() {
	SparseMatrix<double> B(N - 1, N - 1);
	vector<TD> tripletList(N - 1 + 2 * (N - 2));

	for (int i = 1; i < N - 1; i++) {
		auto dei = [=](double x) { return de(i, x) * de(i + 1, x); };
		tripletList.push_back(TD(i - 1, i, integrateQuad2(xi(i), xi(i + 1), dei)));
		tripletList.push_back(TD(i, i - 1, integrateQuad2(xi(i), xi(i + 1), dei)));
	}

	for (int i = 1; i < N; i++) {
		auto dei = [=](double x) { return de(i, x) * de(i, x); };
		tripletList.push_back(TD(i - 1, i - 1, 2 * integrateQuad2(xi(i - 1), xi(i), dei)));
	}

	B.setFromTriplets(tripletList.begin(), tripletList.end());
	return B;
}

VectorXd LMatrix() {
	VectorXd L(N - 1);
	const double PI = 3.14159265359;
	const double G = 6.674 * pow(10, -11);

	for (int i = 1; i < N; i++) {
		auto ei	 = [=](double x) { return e(i, x); };

		/*
		 * Integral of v'(x)dx over interval [0, 3] is skipped, cause always returns 0
		 */

		/*
		 * Integral of v(x)dx = e_j(x)dx over the interval [1, 2]
		 * ρ(x) = 1 only for x ∈ [1, 2], otherwise ρ(x) = 0
		 */
		double x0 = xi(i - 1), x1 = xi(i), x2 = xi(i + 1);
		double iv = 0;
		if (!(x0 < 1 && x2 < 1) || (x0 > 2 && x2 > 2)) {
			x0 = fmax(x0, 1), x1 = fmax(x1, 1), x1 = fmin(x1, 2), x2 = fmin(x2, 2);
			iv = 4 * PI * G * (integrateQuad2(x0, x1, ei) + integrateQuad2(x1, x2, ei));
		}

		L[i - 1] = iv;
	}

	return L;
}