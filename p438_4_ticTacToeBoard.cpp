//  Philipp Siedler
//  Bjarne Stroustrup's PP
//  Chapter 12 Exercise 4

#include "Simple_window.h"
#include "Graph.h"
using namespace Graph_lib;

int main()
try
{
	Point tl(100, 100);
	Simple_window win(tl, 600, 600, "Canvas");

	Graph_lib::Rectangle rect0(Point(0, 0), 200, 200);
	Graph_lib::Rectangle rect1(Point(200, 0), 200, 200);
	Graph_lib::Rectangle rect2(Point(400, 0), 200, 200);

	Graph_lib::Rectangle rect3(Point(0, 200), 200, 200);
	Graph_lib::Rectangle rect4(Point(200, 200), 200, 200);
	Graph_lib::Rectangle rect5(Point(400, 200), 200, 200);

	Graph_lib::Rectangle rect6(Point(0, 400), 200, 200);
	Graph_lib::Rectangle rect7(Point(200, 400), 200, 200);
	Graph_lib::Rectangle rect8(Point(400, 400), 200, 200);

	rect0.set_fill_color(Color::black);
	rect1.set_fill_color(Color::white);
	rect2.set_fill_color(Color::black);

	rect3.set_fill_color(Color::white);
	rect4.set_fill_color(Color::black);
	rect5.set_fill_color(Color::white);

	rect6.set_fill_color(Color::black);
	rect7.set_fill_color(Color::white);
	rect8.set_fill_color(Color::black);

	win.attach(rect0);
	win.attach(rect1);
	win.attach(rect2);

	win.attach(rect3);
	win.attach(rect4);
	win.attach(rect5);

	win.attach(rect6);
	win.attach(rect7);
	win.attach(rect8);

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