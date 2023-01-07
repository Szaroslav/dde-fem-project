#pragma once
#include <cmath>
#include <vector>
#include <Eigen/Core>
#include <Eigen/SparseCore>
#include "./Functions.h"
#include "./GaussianQuadrature.h"

Eigen::SparseMatrix<double> BMatrix();
Eigen::VectorXd LMatrix();