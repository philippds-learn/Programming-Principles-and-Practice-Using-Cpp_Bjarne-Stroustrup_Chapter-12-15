//  Philipp Siedler
//  Bjarne Stroustrup's PP
//  Chapter 13 Exercise 19

#define _USE_MATH_DEFINES
#include "Simple_window.h"
#include "Graph.h"
#include <cmath>

using namespace Graph_lib;

ostream& operator<<(ostream& out, Point& a) {
	out << "(" << a.x << "," << a.y << ")";
	return out;
}

struct Star : Closed_polyline
{
	Star(Point origin, int radius, int inner_radius, int segments, Fl_Color linecolor)
		: o(origin), r(radius), ir(inner_radius), lc(linecolor)
	{
		s = (s < 3) ? segments : 3;
		generate_points();
	};
	Star(Point origin, int radius, int segments)
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
	int ir;
	int s;
	Fl_Color lc;
};

void Star::generate_points()
{
	for (int i = 1; i < s + 1; i++) {
		add(Point(r * sin(((2 * M_PI) / s) * i) + o.x, r * cos(((2 * M_PI) / s) * i) + o.y));
		add(Point(ir * sin(((2 * M_PI) / s) * i + ((2 * M_PI) / (s * 2))) + o.x, ir * cos(((2 * M_PI) / s) * i + ((2 * M_PI) / (s * 2))) + o.y));
	}
};

void Star::draw_lines() const
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

	Star star1(center, 50, 20, 8, FL_RED);
	star1.set_fill_color(Color::red);

	Star star2(Point(100,300), 70, 20, 10, FL_RED);
	star2.set_fill_color(Color::blue);

	Star star3(Point(600, 200), 20, 100, 16, FL_RED);
	star3.set_fill_color(Color::green);

	win.attach(star1);
	win.attach(star2);
	win.attach(star3);

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