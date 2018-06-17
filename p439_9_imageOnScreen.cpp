//  Philipp Siedler
//  Bjarne Stroustrup's PP
//  Chapter 12 Exercise 9

#include "Simple_window.h"
#include "Graph.h"
using namespace Graph_lib;

int main()
try
{
	Point tl(100, 100);
	Simple_window win(tl, 600, 400, "The Lake");

	Image myImage(Point(0, 0), "Input/Original-JPG-Image_large.jpg");
	win.attach(myImage);

	Text caption(Point(50, 50), "This is a fantastic picture of a lake and mountains in fogg.");
	caption.set_color(Color::black);
	caption.set_font_size(20);
	win.attach(caption);

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