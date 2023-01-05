#include <iostream>
#include <iomanip>
#include <vector>
#include <Eigen/Core>
#include <Eigen/QR>
#include <Eigen/SparseCore>
#include <Eigen/SparseCholesky>
#include <matplot/matplot.h>
#include "./Headers/Equations.h"
#include "./Headers/Functions.h"

using std::vector;
using Eigen::SimplicialLDLT;
using Eigen::MatrixXd;
using Eigen::VectorXd;
using Eigen::ComputationInfo;
using matplot::linspace;
using matplot::transform;
using matplot::plot;
using matplot::show;

int main(int argc, char *argv[]) {
	const int N = argc > 1 ? atoi(argv[1]): 3;
	
	MatrixXd B = BMatrix(N);
	VectorXd L = LMatrix(N);
	VectorXd Wi = VectorXd(N - 1);

	Wi = B.colPivHouseholderQr().solve(L);

	vector<double> x = linspace(0, 3);
	vector<double> y = transform(x, [&](double x) { return phi(Wi, N, x); });
	plot(x, y);
	show();

	return 0;
}