//  Philipp Siedler
//  Bjarne Stroustrup's PP
//  Chapter 15 Exercise 5

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

// Leibniz Series graphing functions

/*
double exp0(double x) { return 1; }
double exp1(double x) { return 1 - 1/3 + 1/5; }
double exp2(double x) { return 1 - 1/3 + 1/5 - 1/7 + 1/9; }
*/

double expe(double n)
{
	double sum = 0;
	int denom = 1;
	int sign = 1;
	for (int i = 1; i <= n; i++)
	{
		sum += sign * 4.0 / denom;
		denom += 2;
		sign *= -1;
	}
	return sum;
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

	Open_polyline poly;
	poly.add(orig);
	win.attach(poly);

	
	for (int n = 1; n < 50; ++n)
	{
		ostringstream ss;
		ss << "exp approximation, n == " << n;
		win.set_label(ss.str());
		//get next approximation:
		Function e(expe, r_min, r_max, orig, n, x_scale, y_scale);
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