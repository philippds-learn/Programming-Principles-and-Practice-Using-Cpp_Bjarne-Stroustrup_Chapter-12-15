//  Philipp Siedler
//  Bjarne Stroustrup's PP
//  Chapter 13 Drill 2

#define _USE_MATH_DEFINES
#include "Simple_window.h"
#include "Graph.h"
#include <cmath>
using namespace Graph_lib;

int main()
try
{
	Point tl(100, 100);
	Simple_window win(tl, 1000, 800, "Simple Window");

	int x_grid = 100;
	int y_grid = 100;
	int x_size = 800;
	int y_size = 800;

	Lines grid;
	grid.set_color(Color::black);

	for (int x = x_grid; x < x_size; x += x_grid) {
		grid.add(Point(x, 0), Point(x, y_size));
	}
	for (int y = y_grid; y < y_size; y += y_grid) {
		grid.add(Point(0, y), Point(x_size, y));
	}

	win.attach(grid);
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