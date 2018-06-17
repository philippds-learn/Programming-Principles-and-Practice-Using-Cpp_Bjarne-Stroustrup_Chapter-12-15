//  Philipp Siedler
//  Bjarne Stroustrup's PP
//  Chapter 13 Exercise 11

#define _USE_MATH_DEFINES
#include "Simple_window.h"
#include "Graph.h"
#include <cmath>

using namespace Graph_lib;

ostream& operator<<(ostream& out, Point& a) {
	out << "(" << a.x << "," << a.y << ")";
	return out;
}

Point ptOnEllipse(Graph_lib::Ellipse& e, double p) {
	int a = e.major(); //width
	int b = e.minor(); //height

	int x = e.center().x + a * cos(M_PI * 2 * p);
	int y = e.center().y - b * sin(M_PI * 2 * p);

	return Point(x, y);
}

int main()
try
{
	Point tl(100, 100);
	Simple_window win(tl, 1000, 800, "Simple Window");
	Point center(win.x_max() / 2, win.y_max() / 2);

	//Ellipse
	Graph_lib::Ellipse myEllipse(center,300, 200);
	myEllipse.set_color(Color::red);
	//Foci
	Mark focus1(myEllipse.focus1(), 'x');
	focus1.set_color(Color::red);
	Mark focus2(myEllipse.focus2(), 'x');
	focus2.set_color(Color::red);
	//Pt on Ellipse
	double ptParameter = 0.7;
	Point pt = ptOnEllipse(myEllipse, ptParameter);
	Mark markOnEllipse(pt, 'x');
	markOnEllipse.set_color(Color::red);

	//Lines
	Lines fociLines;
	fociLines.add(myEllipse.focus1(), pt);
	fociLines.add(myEllipse.focus2(), pt);
	fociLines.set_color(Color::blue);

	//xyAxis
	Axis xa(Axis::x, center, 400, 20, "x axis");
	xa.set_color(Color::black);
	Axis ya(Axis::y, center, 300, 15, "y axis");
	ya.set_color(Color::black);

	win.attach(myEllipse);
	win.attach(focus1);
	win.attach(focus2);
	win.attach(markOnEllipse);
	win.attach(fociLines);
	win.attach(xa);
	win.attach(ya);
	
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