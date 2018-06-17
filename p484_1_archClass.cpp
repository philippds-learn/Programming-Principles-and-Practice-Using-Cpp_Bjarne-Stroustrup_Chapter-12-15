//  Philipp Siedler
//  Bjarne Stroustrup's PP
//  Chapter 13 Exercise 1

#define _USE_MATH_DEFINES
#include "Simple_window.h"
#include "Graph.h"
#include <cmath>
using namespace Graph_lib;

class MyArc : public Shape
{
	Point center;
	float radius;
	float start;
	float end;

public:
	MyArc(Point c, double r, double s, double e)
		: center(c)
		, radius(r)
		, start(s)
		, end(e)
	{
		add(c); //Add center point to Shape
	};

	void draw_lines() const;
};

void MyArc::draw_lines() const
{
	int w = radius + radius;
	int h = w;
	if (color().visibility()) {
		fl_arc(point(0).x, point(0).y, w, h, start, end);
	}
}

int main()
try
{
	Point tl(100, 100);
	Simple_window win(tl, 600, 400, "Simple Window");

	MyArc arc(Point(100, 100), 50.0, 30.0, 180.0);
	arc.set_color(Color::red);
	win.attach(arc);

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