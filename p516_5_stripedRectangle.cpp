//  Philipp Siedler
//  Bjarne Stroustrup's PP
//  Chapter 14 Exercise 5

#define _USE_MATH_DEFINES
#include "Simple_window.h"
#include "Graph.h"
#include <cmath>
using namespace Graph_lib;

Point operator+(Point& p1, Point& p2) {
	Point p3 = Point(p1.x + p2.x, p1.y + p2.y);
	return p3;
}

class Striped_rectangle : public Rectangle
{
public:
	Striped_rectangle(Point a, Point b)
		:Rectangle(a, b), a(a), b(b)
	{
		Rectangle::set_color(Color::red);
		set_fill_color();		
	}
	
	void set_fill_color();
	void draw_lines() const;

private:
	Point a;
	Point b;
	Lines pattern;
};


void Striped_rectangle::set_fill_color()
{
	double delta = abs(a.y - b.y);
	for (int i = 0; i < delta; i += 5) {
		pattern.add(Point(a.x, a.y + i), Point(b.x, a.y + i));
	}
	pattern.set_color(Color::blue);
}


void Striped_rectangle::draw_lines() const
{	
	pattern.draw();
	Rectangle::draw_lines();	
}



int main()
try
{
	Point tl(100, 100);
	Simple_window win(tl, 720, 400, "Simple Window");
	Point center(win.x_max() / 2, win.y_max() / 2);

	Striped_rectangle rec(center, center + Point(200, 100));

	win.attach(rec);
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