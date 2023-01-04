#include <iostream>
#include <iomanip>
#include <vector>
#include <Eigen/Core>
#include <Eigen/QR>
#include <Eigen/SparseCore>
#include <Eigen/SparseCholesky>
#include "./Headers/Equations.h"

using std::vector;
using Eigen::SimplicialLDLT;
using Eigen::MatrixXd;
using Eigen::VectorXd;
using Eigen::ComputationInfo;

int main(int argc, char *argv[]) {
	const int N = 9;
	
	MatrixXd B = BMatrix(N);
	VectorXd L = LMatrix(N);
	VectorXd w = VectorXd(N - 1);

	std::cout << std::setprecision(2) << B << std::endl;
	std::cout << L << std::endl;

	w = B.colPivHouseholderQr().solve(L);

	std::cout << w << std::endl;
	return 0;
}