#include <iostream>
#include <vector>
#include <Eigen/Core>
#include <Eigen/SparseCore>
#include <Eigen/SparseCholesky>
#include "./Headers/Equations.h"

using std::vector;
using Eigen::SimplicialLDLT;
using Eigen::SparseMatrix;
using Eigen::VectorXd;
using Eigen::ComputationInfo;

int main(int argc, char *argv[]) {
	const int N = argc > 1 ? std::atoi(argv[1]) : 4;
	
	SimplicialLDLT<SparseMatrix<double>> solver;
	SparseMatrix<double> B = BMatrix(N);
	VectorXd L = LMatrix(N);
	VectorXd w = VectorXd(N - 1);

	solver.compute(B);
	if (solver.info() != ComputationInfo::Success) return -1;
	w = solver.solve(L);
	if (solver.info() != ComputationInfo::Success) return -1;

	std::cout << N;
	return 0;
}