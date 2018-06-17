//  Philipp Siedler
//  Bjarne Stroustrup's PP
//  Chapter 15 15.5

#define _USE_MATH_DEFINES
#include "Simple_window.h"
#include "Graph.h"
#include <cmath>

int fac_recursive(int n) { return n > 1 ? n * fac_recursive(n - 1) : 1; } // factorial n!

																		  // layout
constexpr int xmax = 600;
constexpr int ymax = 600;

constexpr int x_orig = xmax / 2;
constexpr int y_orig = ymax / 2;
Point orig(x_orig, y_orig);

constexpr int r_min = -10;
constexpr int r_max = 10;

constexpr int n_points = 400;

constexpr int x_scale = 20;
constexpr int y_scale = 20;

constexpr int xoffset = 100;
constexpr int yoffset = 100;

constexpr int xspace = 100;
constexpr int yspace = 100;

constexpr int xlength = xmax - xoffset - xspace;
constexpr int ylength = ymax - yoffset - yspace;

// graphing functions

/*
double exp0(double x) { return 0; }
double exp1(double x) { return 1; }
double exp2(double x) { return 1 + x; }
double exp3(double x) { return 1 + x + pow(x, 2) / fac_recursive(2); }
double exp4(double x) { return 1 + x + pow(x, 2) / fac_recursive(2) + pow(x,3) / fac_recursive(3); }
double exp5(double x) { return 1 + x + pow(x, 2) / fac_recursive(2) + pow(x, 3) / fac_recursive(3) + pow(x, 4) / fac_recursive(4); }
*/

double term(double x, int n) { return pow(x, n) / fac_recursive(n); }

double expe(double x, int n)
{
	double sum = 0;
	for (int i = 0; i < n; ++i) { sum += term(x, i); }
	return sum;
}

int expN_number_of_terms = 10;

double expN(double x)
{
	return expe(x, expN_number_of_terms);
}

int main()
try
{
	Point tl(100, 100);
	Simple_window win(tl, xmax, ymax, "Function graphs.");

	Axis x(Axis::x, Point(orig.x - 200, orig.y), 400, 20, "1 == 20");
	x.set_color(Color::black);
	win.attach(x);

	Axis y(Axis::y, Point(orig.x, orig.y + 200), 400, 20, "1 == 20");
	y.set_color(Color::black);
	win.attach(y);

	Function real_exp(exp, r_min, r_max, orig, 200, x_scale, y_scale);
	real_exp.set_color(Color::blue);

	for (int n = 0; n < 50; ++n)
	{
		ostringstream ss;
		ss << "exp approximation, n == " << n;
		win.set_label(ss.str());
		//get next approximation:
		expN_number_of_terms = n;
		Function e(expN, r_min, r_max, orig, 200, x_scale, y_scale);
		e.set_color(Color::red);
		win.attach(e);
		win.wait_for_button();
		win.detach(e);
	}
	keep_window_open();
}
catch (exception& e) {
	cerr << "error: " << e.what() << '\n';
	keep_window_open();
	return 1;
}

catch (...) {
	cerr << "Unknown exception!\n";
	keep_window_open();
	return 2;
}