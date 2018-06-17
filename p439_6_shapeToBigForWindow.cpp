//  Philipp Siedler
//  Bjarne Stroustrup's PP
//  Chapter 12 Exercise 6

#include "Simple_window.h"
#include "Graph.h"
using namespace Graph_lib;

int main()
try
{
	Point tl(100, 100);
	
	//drawing a shape that does not fit inside a window
	/*
	Simple_window win(tl, 600, 400, "Canvas");
	Graph_lib::Rectangle rect(Point(100, 100), 600, 400);
	rect.set_color(Color::black);
	*/

	//drawing a window that does not fit on my screen
	Simple_window win(tl, 2000, 2000, "Canvas");
	Graph_lib::Rectangle rect(Point(100, 100), 600, 400);
	rect.set_color(Color::black);

	win.attach(rect);

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