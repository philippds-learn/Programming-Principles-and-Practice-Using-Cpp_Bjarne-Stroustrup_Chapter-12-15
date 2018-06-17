//  Philipp Siedler
//  Bjarne Stroustrup's PP
//  Chapter 13 Exercise 13

#define _USE_MATH_DEFINES
#include "Simple_window.h"
#include "Graph.h"
#include <cmath>

using namespace Graph_lib;

ostream& operator<<(ostream& out, Point& a) {
	out << "(" << a.x << "," << a.y << ")";
	return out;
}

int main()
try
{
	Point tl(100, 100);
	Simple_window win(tl, 720, 400, "Simple Window");
	Point center(win.x_max() / 2, win.y_max() / 2);

	Vector_ref<Graph_lib::Rectangle> rect;	
	Graph_lib::Rectangle x(Point(100, 200), Point(200, 300));

	rect.push_back(x);
	rect.push_back(new Graph_lib::Rectangle(Point(50, 60), Point(80, 90)));
	
	for (int i = 0; i < rect.size(); i++) rect[i].move(10, 10);

	Vector_ref<Graph_lib::Rectangle> vr;
	for (int i = 0; i < 16; i++) {
		for (int j = 0; j < 16; j++) {
			vr.push_back(new Graph_lib::Rectangle(Point(i * 20, j * 20), 20, 20));
			vr[vr.size() - 1].set_fill_color(Color(i * 16 + j));
			win.attach(vr[vr.size() - 1]);
		}
	}

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