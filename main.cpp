#include "integ.h"

double fun_sin(double x) {
	return sin(x);
}
int main() {
	integral I(fun_sin, 0, 6.283, 0.001);
	cout << I;
	print(I);
	return 0;
}