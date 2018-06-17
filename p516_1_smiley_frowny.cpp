//  Philipp Siedler
//  Bjarne Stroustrup's PP
//  Chapter 14 Exercise 1

#define _USE_MATH_DEFINES
#include "Simple_window.h"
#include "Graph.h"
#include <cmath>
using namespace Graph_lib;

class MyArc : public Shape
{
	Point center;
	float radius;
	float start;
	float end;

public:
	MyArc(Point c, double r, double s, double e)
		: center(c)
		, radius(r)
		, start(s)
		, end(e)
	{
		add(c);
	};

	void draw_lines() const;
};

void MyArc::draw_lines() const
{
	int w = radius + radius;
	int h = w;
	if (color().visibility()) {
		fl_arc(point(0).x, point(0).y, w, h, start, end);
	}
}

Point& operator+(Point& a, Point& b) {
	return Point(a.x + b.x, a.y + b.y);
}

class Face : public Circle
{
public:
	void draw_lines() const;
	void set_color(Color color);
protected:
	Face(Point center, int radius)
		:Circle(center, radius),
		left_eye(Point(center.x - radius / 2, center.y - radius / 2), radius / 8),
		right_eye(Point(center.x + radius / 2, center.y - radius / 2), radius / 8)
	{
		set_color(Color::visible);
	};	
private:
	Circle left_eye;
	Circle right_eye;
};

void Face::draw_lines() const
{
	Circle::draw_lines();
	left_eye.draw();
	right_eye.draw();
}

void Face::set_color(Color color)
{
	Shape::set_color(color);
	left_eye.set_color(color);
	right_eye.set_color(color);
}


class Smiley : public Face
{
public:
	Smiley(Point center, int radius)
		:Face(center, radius), mouth(Point(center.x - radius / 3.0, center.y), radius /3.0, 180.0, 0.0)
	{ };
	void draw_lines() const;

private:
	MyArc mouth;
};

void Smiley::draw_lines() const
{
	Face::draw_lines();
	mouth.draw_lines();
}

class Frowny : public Face
{
public:
	Frowny(Point center, int radius)
		:Face(center, radius), mouth(Point(center.x - radius / 3.0, center.y + radius / 3.0), radius / 3.0, 0.0, 180.0)
	{ };
	void draw_lines() const;

private:
	MyArc mouth;
};

void Frowny::draw_lines() const
{
	Face::draw_lines();
	mouth.draw_lines();
}

class Smiley_hat : public Smiley
{
public:
	Smiley_hat(Point center, int radius)
		:Smiley(center, radius),
		pt1(point_on_circle(Circle(center, radius), 0.65)),
		pt2(point_on_circle(Circle(center, radius), 0.85)),
		pt3(Point(center.x, center.y - radius * 1.5)),
		ln1(pt1, pt3),
		ln2(pt3, pt2)
	{
		ln1.set_color(Color::black);
		ln2.set_color(Color::black);
	};
	
	void draw_lines() const;
	Point point_on_circle(Circle& circle, double paramter);
private:
	Point pt1;
	Point pt2;
	Point pt3;
	Line ln1;
	Line ln2;
};

Point Smiley_hat::point_on_circle(Circle& circle, double paramter) {
	return Point(circle.radius() * cos(M_PI * 2 * paramter) + circle.center().x, circle.radius() * sin(M_PI * 2 * paramter) + circle.center().y);
}

void Smiley_hat::draw_lines() const
{
	Smiley::draw_lines();
	ln1.draw();
	ln2.draw();
}

int main()
try
{
	Point tl(100, 100);
	Simple_window win(tl, 720, 400, "Simple Window");
	Point center(win.x_max() / 2, win.y_max() / 2);

	Smiley_hat smiley(Point(center.x - 100, center.y), 80);
	Frowny frowny(Point(center.x + 100, center.y), 80);

	win.attach(smiley);
	win.attach(frowny);

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