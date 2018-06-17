//  Philipp Siedler
//  Bjarne Stroustrup's PP
//  Chapter 12 Exercise 7

#include "Simple_window.h"
#include "Graph.h"
using namespace Graph_lib;

int main()
try
{
	Point tl(100, 100);
	Simple_window win(tl, 600, 400, "Canvas");

	Graph_lib::Rectangle body(Point(250, 320), 100, 80);
	body.set_color(Color::black);

	Graph_lib::Rectangle door(Point(300, 360), 20, 40);
	door.set_color(Color::black);

	Graph_lib::Polygon roof;
	roof.add(Point(250, 320));
	roof.add(Point(350, 320));
	roof.add(Point(300, 280));
	roof.set_color(Color::black);
	roof.set_fill_color(Color::red);

	win.attach(body);
	win.attach(door);
	win.attach(roof);

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