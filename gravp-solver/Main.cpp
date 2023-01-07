/*
 * Author: Jakub Szaredko
 * Repository: https://github.com/Szaroslav/dde-fem-project
 */

#include "./Main.h"

using namespace std;
using namespace Eigen;
using namespace matplot;

int N;

int main(int argc, char *argv[]) {
	try {
		N = argc > 1 ? stoi(string(argv[1])) : 3;
	}
	catch (invalid_argument ex) {
		cerr << "Inavalid argument: " << ex.what() << endl;
		cout << "Exiting" << endl;
		return -1;
	}
	if (N <= 0) {
		cerr << "Invalid argument, N is less or equal 0" << endl;
		cout << "Exiting" << endl;
		return -1;
	}

	cout << "N = " << N << endl;

	cout << "Evaluating B and L matrixes [...]" << endl;
	SMD B = BMatrix();
	VectorXd L = LMatrix();
	VectorXd Wi = VectorXd(N - 1);

	if (!solve(B, L, Wi))
		return -1;

	plot(Wi);

	return 0;
}

bool solve(SMD &B, VectorXd &L, VectorXd &Wi) {
	cout << "Solving system of equations L x Wi = B [...]" << endl;
	SimplicialLLT<SMD> solver;

	solver.compute(B);
	if (solver.info() != ComputationInfo::Success) {
		cout << "Decomposition failed\n";
		return false;
	}
	Wi = solver.solve(L);
	if (solver.info() != ComputationInfo::Success) {
		cout << "Solving failed\n";
		return false;
	}

	return true;
}

void plot(VectorXd &Wi) {
	cout << "Displaying a plot of the solution [...]" << endl;

	vector<double> x = linspace(0, 3);
	vector<double> y = transform(x, [&](double x) { return phi(Wi, x); });
	plot(x, y)->line_width(2);
	title("Gravitational potential for x = [0, 3]");
	grid(on);
	show();
}