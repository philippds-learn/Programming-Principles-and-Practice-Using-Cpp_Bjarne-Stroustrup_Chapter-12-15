//  Philipp Siedler
//  Bjarne Stroustrup's PP
//  Chapter 13 Exercise 10

#define _USE_MATH_DEFINES
#include "Simple_window.h"
#include "Graph.h"
#include <cmath>

using namespace Graph_lib;

ostream& operator<<(ostream& out, Point& a) {
	out << "(" << a.x << "," << a.y << ")";
	return out;
}

struct Regular_polygon : Closed_polyline
{
	Regular_polygon(Point origin, int radius, int segments, Fl_Color linecolor)
		: o(origin), r(radius), lc(linecolor)
	{
		s = (s < 3) ? segments : 3;
		generate_points();
	};
	Regular_polygon(Point origin, int radius, int segments)
		: o(origin), r(radius), lc(Color::black)
	{
		s = (s < 3) ? segments : 3;
		generate_points();
	};


	void generate_points();
	void draw_lines() const;

private:
	Point o;	
	int r;
	int s;
	Fl_Color lc;
};

void Regular_polygon::generate_points()
{
	for (int i = 1; i < s + 1; i++) {
		add(Point(r * sin(((2 * M_PI) / s) * i) + o.x, r * cos(((2 * M_PI) / s) * i) + o.y));
	}
};

void Regular_polygon::draw_lines() const
{
	fl_color(lc);
	Closed_polyline::draw_lines();
};


int main()
try
{
	Point tl(100, 100);
	Simple_window win(tl, 720, 400, "Simple Window");
	Point center(win.x_max() / 2, win.y_max() / 2);

	Regular_polygon h(center, 50, 8, FL_RED);

	win.attach(h);
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