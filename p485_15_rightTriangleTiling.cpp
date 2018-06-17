//  Philipp Siedler
//  Bjarne Stroustrup's PP
//  Chapter 13 Exercise 15

#define _USE_MATH_DEFINES
#include "Simple_window.h"
#include "Graph.h"
#include <cmath>

using namespace Graph_lib;

ostream& operator<<(ostream& out, Point& a) {
	out << "(" << a.x << "," << a.y << ")";
	return out;
}

Point operator-(Point& p1, Point& p2) {
	Point p3 = Point(p1.x - p2.x, p1.y - p2.y);
	return p3;
}

Point operator+(Point& p1, Point& p2) {
	Point p3 = Point(p1.x + p2.x, p1.y + p2.y);
	return p3;
}

double pointVecMag(Point vec) {
	return sqrt(pow(vec.x, 2) + pow(vec.y, 2));;
}

struct Regular_triangle : Closed_polyline
{
	Regular_triangle(Point origin, int edge, int height, Fl_Color linecolor)
		: o(origin), e(edge), h(height), lc(linecolor)
	{
		generate_points();
	};

	void generate_points();
	void rotate_triangle(double rad);
	void draw_lines() const;

private:
	Point o;
	int e;
	int h;
	Fl_Color lc;
};

void Regular_triangle::generate_points()
{
	add(o);
	add(Point(o.x + e, o.y));
	add(Point(o.x + e / 2, o.y - h));
};

void Regular_triangle::draw_lines() const
{
	fl_color(lc);
	Closed_polyline::draw_lines();
};

void Regular_triangle::rotate_triangle(double rad)
{
	Point origin_Pt1 = Regular_triangle::point(0) - Regular_triangle::point(2);
	Point origin_Pt2 = Regular_triangle::point(1) - Regular_triangle::point(2);

	Point rotated_Pt1 = Point(cos(rad) * origin_Pt1.x - sin(rad) * origin_Pt1.y, sin(rad) * origin_Pt1.x + cos(rad) * origin_Pt1.y);
	Point rotated_Pt2 = Point(cos(rad) * origin_Pt2.x - sin(rad) * origin_Pt2.y, sin(rad) * origin_Pt2.x + cos(rad) * origin_Pt2.y);

	Regular_triangle::set_point(0, rotated_Pt1 + Regular_triangle::point(2));
	Regular_triangle::set_point(1, rotated_Pt2 + Regular_triangle::point(2));
};

struct rt_tiling : Shape
{
	rt_tiling(Point basepoint, int edge, int height, int xcount, int ycount)
		:bp(basepoint), e(edge), h(height)
	{
		xc = (xcount == 0) ? 1 : xcount;
		yc = (ycount == 0) ? 1 : ycount;
		generate_pts();
	}

	void draw_lines() const;
	void generate_pts();

private:
	vector<Point> pts;
	Point bp;
	int e;
	int h;
	int xc;
	int yc;
};

void rt_tiling::generate_pts() {
	for (int i = 0; i < yc; i++) {
		for (int j = 0; j < xc; j++) {
			if (i % 2 == 0) {
				if (j % 2 == 0) {
					pts.push_back(Point(bp.x + (e / 2) * j, bp.y + h * i));
				}
				else {
					pts.push_back(Point(bp.x + (e / 2) * j, bp.y + h * i + h));
				}
			}
			else {
				if (j % 2 == 0) {
					pts.push_back(Point(bp.x + (e / 2) * j, bp.y + h * i + h));
				}
				else {
					pts.push_back(Point(bp.x + (e / 2) * j, bp.y + h * i));
				}
			}
		}
	}
}

void rt_tiling::draw_lines() const
{
	for (int i = 0; i < xc; i++) {
		for (int j = 0; j < yc; j++) {
			Regular_triangle rt(pts[i + j * xc], e, h, Color::red);
			if (j % 2 == 0) {
				if (i % 2 != 0 && j % 2 == 0) {
					rt.rotate_triangle(M_PI);
				}
			}
			else {
				if (i % 2 == 0 && j % 2 != 0) {
					rt.rotate_triangle(M_PI);
				}
			}
			rt.draw_lines();
		}
	}
};

int main()
try
{
	Point tl(100, 100);
	Simple_window win(tl, 720, 400, "Simple Window");
	Point center(win.x_max() / 2, win.y_max() / 2);

	int edge = 50;
	int height = 0.5 * (1 + sqrt(2.0)) * edge; //r = 1/2 * ( 1 + sqrt(2)) * s

	rt_tiling myRtTiling(Point(10, 100), edge, height, 20, 5);

	win.attach(myRtTiling);
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