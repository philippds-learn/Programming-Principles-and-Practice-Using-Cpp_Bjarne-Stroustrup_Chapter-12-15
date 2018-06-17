//  Philipp Siedler
//  Bjarne Stroustrup's PP
//  Chapter 14 Exercise 7

#define _USE_MATH_DEFINES
#include "Simple_window.h"
#include "Graph.h"
#include <cmath>
using namespace Graph_lib;

Point operator+(Point& p1, Point& p2) {
	Point p3 = Point(p1.x + p2.x, p1.y + p2.y);
	return p3;
}

Point operator-(Point& p1, Point& p2) {
	Point p3 = Point(p1.x - p2.x, p1.y - p2.y);
	return p3;
}

ostream& operator<<(ostream& out, Point& a) {
	out << "(" << a.x << "," << a.y << ")";
	return out;
}

class Striped_closed_polyline : public Closed_polyline
{
public:
	Striped_closed_polyline(vector<Point> pts)
		:points(pts)
	{
		for (int i = 0; i < pts.size(); i++) {
			Closed_polyline::add(pts[i]);
		}

		points.push_back(pts[0]);
		Closed_polyline::set_color(Color::red);
		set_fill_color();
	}


	void set_fill_color();
	void draw_lines() const;

	vector<Point> inters;
	vector<Mark> marks;
	Lines pattern;

private:
	Point a;
	int r;
	
	vector<Point> points;
};

void Striped_closed_polyline::set_fill_color()
{
	Point ymax = points[0];
	Point ymin = points[0];

	for (int i = 0; i < points.size(); i++) {
		if (points[i].y > ymax.y) {
			ymax = points[i];
		}
		if (points[i].y < ymin.y) {
			ymin = points[i];
		}
	}
		
	int delta = ymax.y - ymin.y;
	int step_size = 5;
	
	for (int i = 0; i < points.size() - 1; i++) {
		int counter = 0;
		for (int j = 0; j < delta; j += step_size) {			
			if (points[i].y <= j + ymin.y && points[i + 1].y >= j + ymin.y) {

				Point temp = points[i + 1] - points[i];

				double slope = (double)temp.y / (double)temp.x;

				int x = (double)counter / slope;

				inters.push_back(Point(x + points[i].x, ymin.y + j));
				counter += step_size;
			}
			else if (points[i + 1].y <= j + ymin.y && points[i].y >= j + ymin.y) {

				Point temp = points[i] - points[i + 1];

				double slope = (double)temp.y / (double)temp.x;

				int x = (double)counter / slope;

				inters.push_back(Point(x + points[i + 1].x, ymin.y + j));
				counter += step_size;
			}
		}
	}
		
	// insertion_sort according to y
	int i, j;
	for (i = 1; i < inters.size(); i++) {
		j = i;
		while ((j>0) && (inters[j].y < inters[j - 1].y)) {
			swap(inters[j], inters[j - 1]);
			j = j - 1;
		}
	}
	
	for (int i = 0; i < inters.size() - 1; i++) {
		if (inters[i].y == inters[i + 1].y) {
			pattern.add(inters[i], inters[i + 1]);
		}		
	}	

	pattern.set_color(Color::blue);	
}

void Striped_closed_polyline::draw_lines() const
{
	for (int i = 0; i < inters.size(); i++) {
		Mark myMark(inters[i], 'x');
		myMark.draw();		
	}

	pattern.draw();
	Closed_polyline::draw_lines();
}

int main()
try
{
	Point tl(100, 100);
	Simple_window win(tl, 720, 400, "Simple Window");
	Point center(win.x_max() / 2, win.y_max() / 2);

	vector<Point> pts;
	pts.push_back(Point(100, 100));
	pts.push_back(Point(70, 150));
	pts.push_back(Point(200, 300));
	pts.push_back(Point(400, 120));

	Striped_closed_polyline scp(pts);	

	win.attach(scp);
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