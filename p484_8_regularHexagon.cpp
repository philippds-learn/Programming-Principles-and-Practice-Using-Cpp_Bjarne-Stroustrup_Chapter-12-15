//  Philipp Siedler
//  Bjarne Stroustrup's PP
//  Chapter 13 Exercise 8

#define _USE_MATH_DEFINES
#include "Simple_window.h"
#include "Graph.h"
#include <cmath>

using namespace Graph_lib;

ostream& operator<<(ostream& out, Point& a) {
	out << "(" << a.x << "," << a.y << ")";
	return out;
}

struct Regular_hexagon : Closed_polyline
{
	Regular_hexagon(Point origin, int radius)
	: o(origin), r(radius)
	{
		generate_points();
	};
			
	void generate_points();
	void draw_lines() const;
	vector<Point> get_pts() { return pts; };
	
private:
	Point o;
	vector<Point> pts;
	int r;
};

void Regular_hexagon::generate_points()
{
	int n = 6;
	for (int i = 0; i < n; i++) {
		pts.push_back(Point(o.x + r * cos(2 * M_PI * i / n), o.y + r * sin(2 * M_PI * i / n)));
		add(pts[i]);
	}
};

void Regular_hexagon::draw_lines() const
{
	Closed_polyline::draw_lines();
};


int main()
try
{
	Point tl(100, 100);
	Simple_window win(tl, 720, 400, "Simple Window");
	Point center(win.x_max() / 2, win.y_max() / 2);

	Regular_hexagon h(center, 50);
	
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