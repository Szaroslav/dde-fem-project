#pragma once
#include <Eigen/Core>

double xi(int, int);
double e(int, int, double);
double de(int, int, double);
double w(Eigen::VectorXd, int, double);
double phi(Eigen::VectorXd, int, double);