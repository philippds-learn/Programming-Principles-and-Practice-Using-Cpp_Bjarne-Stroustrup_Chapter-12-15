//  Philipp Siedler
//  Bjarne Stroustrup's PP
//  Chapter 12 Exercise 8

#include "Simple_window.h"
#include "Graph.h"
using namespace Graph_lib;

int main()
try
{
	Point tl(100, 100);
	Simple_window win(tl, 600, 400, "Canvas");

	Circle c0(Point(150, 200), 50);
	c0.set_color(Color::blue);
	Circle c1(Point(230, 200), 50);
	c1.set_color(Color::black);
	Circle c2(Point(310, 200), 50);
	c2.set_color(Color::red);
	Circle c3(Point(190, 280), 50);
	c3.set_color(Color::green);
	Circle c4(Point(270, 280), 50);
	c4.set_color(Color::yellow);

	win.attach(c0);
	win.attach(c1);
	win.attach(c2);
	win.attach(c3);
	win.attach(c4);

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