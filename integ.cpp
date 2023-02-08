#include "integ.h"

bool integral::search() {
	bool res = (fun != nullptr && (a < b) && (h > 0) && (h < b - a));
	if (!res)
		cout << "not correct";
	return res;
}
double integral::trap() const {
	double s = 0;
	double i = a;
	for (; i + h < b; i += h) {
		s += (fun(i) + fun(i + h)) * h / 2;
	}
	s += (fun(i) + fun(b)) * (b - i) / 2;
	return s;
}
double integral::lefp_p() const
{
	double s = 0;
	double i = a;
	for (; i + h < b; i += h) {
		s += fun(i) * h;
	}
	s += fun(i) * (b - i);
	return s;
}
double integral::right_p() const
{
	double s = 0;
	double i = a;
	for (; i + h < b; i += h) {
		s += fun(i + h) * h;
	}
	s += fun(b) * (b - i);
	return s;
}
double integral::middle_p() const
{
	double s = 0;
	double i = a;
	for (; i + h < b; i += h) {
		s += fun(i + h / 2) * h;
	}
	s += fun((i + b) / 2) * (b - i);
	return s;
}
integral& integral::operator = (const integral& integ) {
	if (this != &integ) {
		fun = integ.fun;
		a = integ.a;
		b = integ.b;
		h = integ.h;
	}
	search();
	return *this;
}
ostream& operator << (ostream& out, const integral& I) {
	out << "Middle poligon = " << I.middle_p() << endl <<
		"Left poligon = " << I.lefp_p() << endl <<
		"Right poligon = " << I.right_p() << endl <<
		"Trapezoid = " << I.trap() << endl;
	return out;
}
double integral::operator[](double x) {
	return fun(x);
}
void print(integral integ) {
	for (double i = integ.get_a(); i < integ.get_b(); i += integ.get_h())
		cout << i << "\t" << integ[i] << endl;
	cout << integ.get_b() << "\t" << integ[integ.get_b()] << endl;
}