//  Philipp Siedler
//  Bjarne Stroustrup's PP
//  Chapter 14 Exercise 6

#define _USE_MATH_DEFINES
#include "Simple_window.h"
#include "Graph.h"
#include <cmath>
using namespace Graph_lib;

Point operator+(Point& p1, Point& p2) {
	Point p3 = Point(p1.x + p2.x, p1.y + p2.y);
	return p3;
}

class Striped_circle : public Circle
{
public:
	Striped_circle(Point a, int r)
		:Circle(a, r), a(a), r(r)
	{
		Circle::set_color(Color::red);
		set_fill_color();
	}

	void set_fill_color();
	void draw_lines() const;

private:
	Point a;
	int r;
	Lines pattern;
};

void Striped_circle::set_fill_color()
{

	for (int i = - r; i < r; i += 5) {
		int x = sqrt(pow(r, 2) - pow(i, 2));
		Point pt(x, i);
		pattern.add(pt + a, Point(-pt.x, pt.y) + a);
	}
	pattern.set_color(Color::blue);
}

void Striped_circle::draw_lines() const
{
	pattern.draw();
	Circle::draw_lines();
}

int main()
try
{
	Point tl(100, 100);
	Simple_window win(tl, 720, 400, "Simple Window");
	Point center(win.x_max() / 2, win.y_max() / 2);

	Striped_circle circle(center, 100);

	win.attach(circle);
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