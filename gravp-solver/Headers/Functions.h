#pragma once
#include <Eigen/Core>
#include "./GaussianQuadrature.h"

double xi(int);
double e(int, double);
double de(int, double);
double w(Eigen::VectorXd, double);
double phi(Eigen::VectorXd, double);