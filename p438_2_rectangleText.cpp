//  Philipp Siedler
//  Bjarne Stroustrup's PP
//  Chapter 12 Exercise 2

#include "Simple_window.h"
#include "Graph.h"
using namespace Graph_lib;

int main()
try
{
	Point tl(100, 100);
	Simple_window win(tl, 600, 400, "Canvas");

	Graph_lib::Rectangle rect(Point(250, 185), 100, 30);
	rect.set_color(Color::black);

	Text t(Point(275, 205), "Howdy!");
	t.set_color(Color::black);
	
	win.attach(rect);
	win.attach(t);

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