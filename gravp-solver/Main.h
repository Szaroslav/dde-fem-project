#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <Eigen/Core>
#include <Eigen/SparseCore>
#include <Eigen/SparseCholesky>
#include <matplot/matplot.h>
#include "./Headers/Equations.h"
#include "./Headers/Functions.h"

typedef Eigen::SparseMatrix<double> SMD;

int main(int argc, char* argv[]);
bool solve(SMD& B, Eigen::VectorXd& L, Eigen::VectorXd& Wi);
void plot(Eigen::VectorXd& Wi);