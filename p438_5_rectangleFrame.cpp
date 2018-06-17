//  Philipp Siedler
//  Bjarne Stroustrup's PP
//  Chapter 12 Exercise 5

#include "Simple_window.h"
#include "Graph.h"
using namespace Graph_lib;

int main()
try
{
	Point tl(100, 100);
	Simple_window win(tl, 1920, 1040, "Canvas");

	Graph_lib::Rectangle rect(Point(100, 100), (x_max() / 3) * 2, (y_max() / 4) * 3);
	rect.set_color(Color::black);

	Graph_lib::Rectangle frame(Point(50, 50), (x_max() / 3) * 2 + 100, (y_max() / 4) * 3 + 100);
	frame.set_style(Line_style(Line_style::solid, 30));
	frame.set_color(Color::red);

	win.attach(rect);
	win.attach(frame);

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