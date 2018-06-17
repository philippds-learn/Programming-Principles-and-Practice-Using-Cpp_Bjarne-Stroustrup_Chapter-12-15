//  Philipp Siedler
//  Bjarne Stroustrup's PP
//  Chapter 13 Drill 4

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

	//grid
	Lines grid;
	grid.set_color(Color::black);

	for (int x = x_grid; x < x_size; x += x_grid) {
		grid.add(Point(x, 0), Point(x, y_size));
	}
	for (int y = y_grid; y < y_size; y += y_grid) {
		grid.add(Point(0, y), Point(x_size, y));
	}

	//diagonal rectangles
	Vector_ref<Graph_lib::Rectangle> diagonal_rectangles;

	for (int i = 0; i < 8; i++) {
		diagonal_rectangles.push_back(new Graph_lib::Rectangle(Point(x_grid * i, y_grid * i), x_grid, y_grid));
		diagonal_rectangles[i].set_fill_color(Color::red);
		win.attach(diagonal_rectangles[i]);
	}

	//three iamges
	Image image0(Point(2 * x_grid, 0), "Input/Original-JPG-Image_large.jpg");
	image0.set_mask(Point(5 * x_grid, 500), 200, 200);

	Image image1(Point(4 * x_grid, 0), "Input/Original-JPG-Image_large.jpg");
	image1.set_mask(Point(5 * x_grid, 500), 200, 200);

	Image image2(Point(6 * x_grid, 0), "Input/Original-JPG-Image_large.jpg");
	image2.set_mask(Point(5 * x_grid, 500), 200, 200);

	win.attach(image0);
	win.attach(image1);
	win.attach(image2);

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