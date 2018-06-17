//  Philipp Siedler
//  Bjarne Stroustrup's PP
//  Chapter 15 Exercise 11

#define _USE_MATH_DEFINES
#include "Simple_window.h"
#include "Graph.h"
#include <cmath>

ostream& operator<<(ostream& out, Point& a) {
	out << "(" << a.x << "," << a.y << ")";
	return out;
}

// layout
constexpr int xmax = 600;
constexpr int ymax = 600;

constexpr int x_orig = xmax / 2;
constexpr int y_orig = ymax / 2;
Point orig(x_orig, y_orig);

constexpr int r_min = -10;
constexpr int r_max = 10;

constexpr int n_points = 400;

constexpr int x_scale = 2;
constexpr int y_scale = 2;

constexpr int xoffset = 100;
constexpr int yoffset = 100;

constexpr int xspace = 100;
constexpr int yspace = 100;

constexpr int xlength = xmax - xoffset - xspace;
constexpr int ylength = ymax - yoffset - yspace;


int main()
try
{
	Point tl(100, 100);
	Simple_window win(tl, xmax, ymax, "Function graphs");

	// x axis
	Axis x(Axis::x, Point(xoffset, ymax - yoffset), xlength, 12,
		"month    Jan  Feb   Mar  Apr  May  Jun   Jul    Aug  Sep  Oct  Nov   Dec");
	x.set_color(Color::black);
	x.label.move(-100, 0);
	win.attach(x);

	// y axis
	Axis y(Axis::y, Point(yoffset, ymax - yoffset), ylength, 20, "temperature in 0 - 20 C");
	y.set_color(Color::black);
	win.attach(y);

	// data
	// Cambridge, England monthly normal weather 2016
	vector<double> camb_eng_temp = { 
		3.7,
		3.8,
		6.1,
		8.0,
		11.4,
		14.3,
		16.8,
		16.9,
		14.1,
		10.5,
		6.5,
		4.7
	};

	// Cambridge, Massachusetts monthly normal weather 2016
	vector<double> camb_mas_temp = {
		-1.9,
		-0.9,
		3.7,
		8.9,
		14.6,
		19.8,
		23.1,
		22.2,
		18.2,
		12.7,
		7.4,
		0.9
	};

	// graph
	Open_polyline cet; // Cambridge, England
	Open_polyline cmt; // Cambridge, Massachusetts

	for (int i = 0; i < 12; i++) {
		cet.add(Point(xoffset + i * (xlength / 12), (yspace + ylength) - camb_eng_temp[i] * 20));
		cmt.add(Point(xoffset + i * (xlength / 12), (yspace + ylength) - camb_mas_temp[i] * 20));
	}

	cet.set_color(Color::red);
	win.attach(cet);

	cmt.set_color(Color::blue);
	win.attach(cmt);

	win.wait_for_button();
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