//  Philipp Siedler
//  Bjarne Stroustrup's PP
//  Chapter 14 Exercise 4

#define _USE_MATH_DEFINES
#include "Simple_window.h"
#include "Graph.h"
#include <cmath>
using namespace Graph_lib;

class Immobile_Circle : public Circle
{
public:
	Immobile_Circle(Point p, int rad)
		:Circle(p, rad) { }
	void move() { }
	
};

int main()
try
{
	Point tl(100, 100);
	Simple_window win(tl, 720, 400, "Simple Window");
	Point center(win.x_max() / 2, win.y_max() / 2);

	Immobile_Circle ic(center, 50);
	ic.set_color(Color::red);
	ic.move(); //no constructors to be placed

	win.attach(ic);
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