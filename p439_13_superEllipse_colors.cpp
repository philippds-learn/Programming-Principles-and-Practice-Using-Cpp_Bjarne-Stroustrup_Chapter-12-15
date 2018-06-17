//  Philipp Siedler
//  Bjarne Stroustrup's PP
//  Chapter 12 Exercise 13

#define _USE_MATH_DEFINES
#include "Simple_window.h"
#include "Graph.h"
#include <cmath>
using namespace Graph_lib;

int main()
try
{
	Point tl(100, 100);
	Simple_window win(tl, 600, 400, "Regular Polygons");

	Point center(win.x_max() / 2, win.y_max() / 2);
	Graph_lib::Open_polyline supEllipse0;
	supEllipse0.set_color(Color::red);
	Graph_lib::Open_polyline supEllipse1;
	supEllipse1.set_color(Color::green);
	Graph_lib::Open_polyline supEllipse2;
	supEllipse2.set_color(Color::blue);
	Graph_lib::Open_polyline supEllipse3;                                                                                                                                                                                                                                                                              
	supEllipse3.set_color(Color::black);

	double a = 100;
	double y;
	double b = 100;
	double n; // 1/2; 3/2; 2; 4;
	n = 4.0;

	for (int x = -100; x < 0; x++) {
		y = b * pow(1 - pow(abs(x / a), n), 1 / n);
		supEllipse0.add(Point(x + center.x, y + center.y));
	}
	for (int x = 0; x < 101; x++) {
		y = b * pow(1 - pow(abs(x / a), n), 1 / n);
		supEllipse1.add(Point(x + center.x, y + center.y));
	}

	for (int x = 100; x > 0; x--) {
		y = b * pow(1 - pow(abs(x / a), n), 1 / n);
		y = -y;
		supEllipse2.add(Point(x + center.x, y + center.y));
	}

	for (int x = 0; x > -101; x--) {
		y = b * pow(1 - pow(abs(x / a), n), 1 / n);
		y = -y;
		supEllipse3.add(Point(x + center.x, y + center.y));
	}

	win.attach(supEllipse0);
	win.attach(supEllipse1);
	win.attach(supEllipse2);
	win.attach(supEllipse3);
	win.wait_for_button();
}
catch (exception& e) {
	cout << e.what() << endl;
	return 1;
}
catch (...) {
	cout << "Exiting" << endl;
	return 2;
}