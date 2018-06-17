//  Philipp Siedler
//  Bjarne Stroustrup's PP
//  Chapter 15 Function Graphing Drill 5

#define _USE_MATH_DEFINES
#include "Simple_window.h"
#include "Graph.h"
#include <cmath>

using namespace Graph_lib;

int main()
try
{
	Point tl(100, 100);
	Simple_window win(tl, 600, 600, "Function graphs.");
	Point center(win.x_max() / 2, win.y_max() / 2);

	Axis x(Axis::x, Point(center.x - 200, center.y), 400, 20, "1 == 20");
	x.set_color(Color::red);

	Axis y(Axis::y, Point(center.x, center.y + 200), 400, 20, "1 == 20");
	y.set_color(Color::red);

	win.attach(x);
	win.attach(y);

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