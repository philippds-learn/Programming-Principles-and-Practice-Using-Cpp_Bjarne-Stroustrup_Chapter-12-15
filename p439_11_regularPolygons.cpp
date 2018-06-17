//  Philipp Siedler
//  Bjarne Stroustrup's PP
//  Chapter 12 Exercise 11

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

	Graph_lib::Closed_polyline triangle;
	triangle.set_color(Color::black);

	triangle.add(Point(260, 200));
	triangle.add(Point(340, 200));
	triangle.add(Point(300, 200 - (tan((60 * (M_PI / 180))) * 40)));

	Graph_lib::Closed_polyline quad;
	quad.set_color(Color::black);

	quad.add(Point(260, 200 - (tan((60 * (M_PI / 180))) * 40)));
	quad.add(Point(340, 200 - (tan((60 * (M_PI / 180))) * 40)));
	quad.add(Point(340, 280 - (tan((60 * (M_PI / 180))) * 40)));
	quad.add(Point(260, 280 - (tan((60 * (M_PI / 180))) * 40)));

	Graph_lib::Closed_polyline pentagon;
	pentagon.set_color(Color::black);
	
	Point center(300, (240 - (tan((60 * (M_PI / 180))) * 40)));
	Graph_lib::Circle cl(center, 2);
	cl.set_color(Color::black);

	double radius = 64;

	double s1 = sin((2 * M_PI) / 5) * radius;
	double c1 = cos(M_PI / 5) * radius;

	double s2 = sin((2 * M_PI) / 5) * radius;
	double c2 = cos((4 * M_PI) / 5) * radius;

	vector<double> pentaX;
	vector<double> pentaY;

	for (int i = 0; i < 5; i++) {
		pentaX.push_back(radius * cos(2 * M_PI*i / 5));
		pentaY.push_back(radius * sin(2 * M_PI*i / 5));
	}
	for (int i = 0; i < 5; i++) {
		pentagon.add(Point(pentaX[i] + center.x + 6, pentaY[i] + center.y));
	}

	win.attach(cl);
	win.attach(quad);
	win.attach(triangle);
	win.attach(pentagon);

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