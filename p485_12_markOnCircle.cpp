//  Philipp Siedler
//  Bjarne Stroustrup's PP
//  Chapter 13 Exercise 12

#define _USE_MATH_DEFINES
#include "Simple_window.h"
#include "Graph.h"
#include <cmath>

using namespace Graph_lib;

ostream& operator<<(ostream& out, Point& a) {
	out << "(" << a.x << "," << a.y << ")";
	return out;
}

Point ptOnCircle(Graph_lib::Circle& c, double p) {
	return Point(c.radius() * cos(M_PI * 2 * p) + c.center().x, c.radius() * sin(M_PI * 2 * p) + c.center().y);
}

int main()
try
{
	Point tl(100, 100);
	Simple_window win(tl, 720, 400, "Simple Window");
	Point center(win.x_max() / 2, win.y_max() / 2);

	//Circle
	Circle myCircle(center, 50);
	myCircle.set_color(Color::red);
	win.attach(myCircle);

	//Pt on Circle
	double parameter = 0;
	while (true) {		
		Mark myMark(ptOnCircle(myCircle, parameter), 'x');
		myMark.set_color(Color::red);
		win.attach(myMark);
		win.wait_for_button();
		parameter += 0.1;
	}	
}
catch (exception& e) {
	cout << e.what() << endl;
	return 1;
}
catch (...) {
	cout << "Exiting" << endl;
	return 2;
}