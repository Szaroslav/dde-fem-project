#include <iostream>

int main(int argc, char *argv[]) {
	const int N = argc > 0 ? std::atoi(argv[0]) : 4;
	std::cout << N;

	return 0;
}