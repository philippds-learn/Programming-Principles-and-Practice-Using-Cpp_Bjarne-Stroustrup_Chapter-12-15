//  Philipp Siedler
//  Bjarne Stroustrup's PP
//  Chapter 12 Exercise 1

#include "Simple_window.h"
#include "Graph.h"
using namespace Graph_lib;

int main()
try
{
	Point tl(100, 100);
	Simple_window win(tl, 600, 400, "Canvas");

	Graph_lib::Rectangle rect(Point(100,150),150,100);
	rect.set_color(Color::blue);

	Graph_lib::Polygon poly;
	poly.add(Point(350, 150));
	poly.add(Point(500, 150));
	poly.add(Point(500, 250));
	poly.add(Point(350, 250));
	poly.set_color(Color::red);

	win.attach(rect);
	win.attach(poly);	

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