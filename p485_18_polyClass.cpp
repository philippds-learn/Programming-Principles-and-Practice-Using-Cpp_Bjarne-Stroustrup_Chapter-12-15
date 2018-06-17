//  Philipp Siedler
//  Bjarne Stroustrup's PP
//  Chapter 13 Exercise 18

#define _USE_MATH_DEFINES
#include "Simple_window.h"
#include "Graph.h"
#include <cmath>

using namespace Graph_lib;

ostream& operator<<(ostream& out, Point& a) {
	out << "(" << a.x << "," << a.y << ")";
	return out;
}

struct Poly : Closed_polyline
{
	Poly(vector<Point> pts, Fl_Color linecolor)
		: pts(pts), lc(linecolor)
	{
		if (pts.size() <= 2) {
			error("Not enough points", pts.size());
		}
		else {
			generate_points();
		}		
	};

	void generate_points();
	void draw_lines() const;

private:
	vector<Point> pts;
	Fl_Color lc;
};

void Poly::generate_points()
{
	for (int i = 0; i < pts.size(); i++) {
		add(pts[i]);
	}
};

void Poly::draw_lines() const
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

	vector<Point> pts = { Point(100, 100), Point(150, 200) };

	Poly p(pts, FL_RED);

	win.attach(p);
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