//  Philipp Siedler
//  Bjarne Stroustrup's PP
//  Chapter 13 Exercise 17

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
	Regular_hexagon(Point origin, int radius, Fl_Color lc)
		: o(origin), r(radius), lc(lc)
	{
		generate_points();
	};

	void generate_points();
	void draw_lines() const;
	vector<Point> get_pts() { return pts; };

private:
	Fl_Color lc;
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
	fl_color(lc);
	Closed_polyline::draw_lines();
};

struct rh_tiling : Shape
{
	rh_tiling(Point basepoint, double radius, int num_xdir, int num_ydir)
		: bp(basepoint), r(radius)
	{
		nx = (num_xdir == 0) ? 1 : num_xdir;
		ny = (num_ydir == 0) ? 1 : num_ydir;
		generate_pts();
	}

	void generate_pts();
	void draw_lines() const;

private:
	vector<Point> pts;
	Point bp;
	double r;
	int nx;
	int ny;
};

void rh_tiling::generate_pts()
{
	double triangle_h = sqrt(pow(r, 2) - pow(r / 2, 2));
	cout << triangle_h << endl;
	for (int i = 0; i < nx; i++) {
		for (int j = 0; j < ny; j++) {
			if (j % 2 == 0 || j == 0) {
				pts.push_back(Point(bp.x + (r * 3) * i, bp.y + triangle_h * j));
			}
			else {
				pts.push_back(Point(bp.x + (r * 3) * i + (1.5 * r), bp.y + j * triangle_h));
			}
		}
	}
};

void rh_tiling::draw_lines() const
{
	for (int i = 0; i < pts.size(); i++) {
		Regular_hexagon(pts[i], r, Fl_Color(i)).draw_lines();
	}
};


int main()
try
{
	Point tl(100, 100);
	Simple_window win(tl, 720, 400, "Simple Window");
	Point center(win.x_max() / 2, win.y_max() / 2);

	rh_tiling myTiling(Point(50, 100), 50, 5, 6);
	myTiling.set_color(Color::red);

	win.attach(myTiling);
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