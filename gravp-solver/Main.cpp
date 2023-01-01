#include <iostream>
#include <vector>
#include <Eigen/SparseCore>
#include <Eigen/SparseCholesky>
#include "./Headers/Equations.h"

using std::vector;
using Eigen::SimplicialLDLT;
using Eigen::SparseMatrix;

int main(int argc, char *argv[]) {
	const int N = argc > 1 ? std::atoi(argv[1]) : 4;
	std::cout << N;

	return 0;
}