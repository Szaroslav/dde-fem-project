#pragma once
#include <functional>

/*
 * 2-point Gaussian Quadrature algorithm with change of the interval from [a, b] to [-1, 1]
 */
double integrateQuad2(double a, double b, std::function<double(double)> f);