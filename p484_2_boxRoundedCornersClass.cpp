//  Philipp Siedler
//  Bjarne Stroustrup's PP
//  Chapter 13 Exercise 2

#define _USE_MATH_DEFINES
#include "Simple_window.h"
#include "Graph.h"
#include <cmath>
using namespace Graph_lib;

struct MyBox : public Shape
{
	MyBox(Point origin, int width, int height, int radius) : o(origin), w(width), h(height), r(radius) {
		a1 = Point(o.x + r, o.y);
		b1 = Point(o.x + w - r, o.y);
		b2 = Point(o.x + w, o.y + r);
		c1 = Point(o.x + w, o.y + h - r);
		c2 = Point(o.x + w - r, o.y + h);
		d1 = Point(o.x + r, o.y + h);
		d2 = Point(o.x, o.y + h - r);
		a2 = Point(o.x, o.y + r);

		a3 = Point(o.x + r, o.y + r);
		b3 = Point(o.x + w - r, o.y + r);
		c3 = Point(o.x + w - r, o.y + h - r);
		d3 = Point(o.x + r, o.y + h - r);
	};

	void draw_lines() const;

private:
	Point o;
	Point a1, a2, b1, b2, c1, c2,d1 ,d2;
	Point a3, b3, c3, d3;
	int w, h, r;
};

void MyBox::draw_lines() const
{	
	if (color().visibility()) {
		fl_line(a1.x, a1.y, b1.x, b1.y);
		fl_line(b2.x, b2.y, c1.x, c1.y);
		fl_line(c2.x, c2.y, d1.x, d1.y);
		fl_line(d2.x, d2.y, a2.x, a2.y);
		
		fl_arc(o.x, o.y, r+r, r+r, 90, 180);
		fl_arc(o.x + w - (r+r), o.y, r+r, r+r, 360, 90);
		fl_arc(o.x + w - (r + r), o.y + h - (r + r), r+r, r+r, 270, 360);
		fl_arc(o.x, o.y + h - (r + r), r+r, r+r, 180, 270);
	}
}

int main()
try
{
	Point tl(100, 100);
	Simple_window win(tl, 600, 400, "Simple Window");

	MyBox testBox(Point(100, 100), 300, 100, 15);
	testBox.set_color(Color::red);

	win.attach(testBox);
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