#pragma once
#include <iostream>
#include <math.h>
using namespace std;
using TFunc = double(*)(double);

class integral {
	double a, b; // boundaries of the integral
	double h; // integral step
	TFunc fun; // pointer to function
	bool search(); // checking for correctness

public:
	integral(TFunc F = nullptr, double A = 0, double B = 0, double H = 0) {
		fun = F;
		a = A;
		b = B;
		h = H;
		search();
	}
	integral(const integral& I) {
		a = I.a;
		b = I.b;
		h = I.h;
		fun = I.fun;
		search();
	}
	~integral() {
		;
	}
	void step(double H) {
		h = H; // change step
	}
	void border(double A, double B) {
		a = A;
		b = B;
	}
	double get_a() {
		return a;
	}
	double get_b() {
		return b;
	}
	double get_h() {
		return h;
	}
	double trap()const;
	double lefp_p()const;
	double right_p()const;
	double middle_p()const;
	void print(const integral integ);
	friend ostream& operator << (ostream& out, const integral& I);
	integral& operator = (const integral& integ);
	double operator[](double x); // return value of the function at a specific point
};
void print(integral integ); // printout on the interval