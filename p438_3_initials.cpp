//  Philipp Siedler
//  Bjarne Stroustrup's PP
//  Chapter 12 Exercise 3

#include "Simple_window.h"
#include "Graph.h"
using namespace Graph_lib;

int main()
try
{
	Point tl(100, 100);
	Simple_window win(tl, 600, 400, "Canvas");

	Text f(Point(200, 250), "P");
	f.set_color(Color::red);
	f.set_font_size(150);

	Text l(Point(300, 250), "S");
	l.set_color(Color::blue);
	l.set_font_size(150);

	win.attach(f);
	win.attach(l);

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