#pragma once
#include <vector>
#include <Eigen/Core>
#include <Eigen/SparseCore>

Eigen::SparseMatrix<double> BMatrix(int N);
Eigen::VectorXd LMatrix(int N);