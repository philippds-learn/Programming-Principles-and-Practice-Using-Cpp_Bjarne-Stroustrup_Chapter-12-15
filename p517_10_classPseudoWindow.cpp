//  Philipp Siedler
//  Bjarne Stroustrup's PP
//  Chapter 14 Exercise 10

#define _USE_MATH_DEFINES
#include "Simple_window.h"
#include "Graph.h"
#include <cmath>

using namespace Graph_lib;

ostream& operator<<(ostream& out, Point& a) {
	out << "(" << a.x << "," << a.y << ")";
	return out;
}

struct Pseudo_window : public Shape
{
	Pseudo_window(Point origin, int width, int height, int radius, string label, string content_location)
	: o(origin), w(width), h(height), r(radius), l(label), content_location(content_location)
	{
		initialize_outline();
		initialize_label_bar();
	};

	void draw_lines() const;
	void initialize_outline();
	void initialize_label_bar();

private:
	Point o;
	Point a1, a2, b1, b2, c1, c2, d1, d2;
	Point a3, b3, c3, d3;
	int w, h, r;
	string l;

	Point bar_line_s; // label bar line start
	Point bar_line_e; // label bar line end

	Point bar_close_s;
	Point bar_close_e;

	Point bar_extend_s;
	Point bar_extend_e;

	Point bar_minimize_s;
	Point bar_minimize_e;

	string content_location;
};

void Pseudo_window::initialize_outline()
{
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
}

void Pseudo_window::initialize_label_bar()
{
	// add point for label text
	add(Point(o.x + 10, o.y + 17));

	// add points for label bar line
	bar_line_s = Point(o.x + 3, o.y + 23);
	bar_line_e = Point(o.x + w - 3, o.y + 23);

	// add label bar buttons
	bar_close_s = Point(o.x + w - 20, o.y + 7);
	bar_close_e = Point(o.x + w - 10, o.y + 17);

	bar_extend_s = Point(o.x + w - 40, o.y + 7);
	bar_extend_e = Point(o.x + w - 30, o.y + 17);

	bar_minimize_s = Point(o.x + w - 60, o.y + 7);
	bar_minimize_e = Point(o.x + w - 50, o.y + 17);
}

void Pseudo_window::draw_lines() const
{
	// buttons
	Graph_lib::Rectangle close(bar_close_s, bar_close_e);
	Graph_lib::Rectangle extend(bar_extend_s, bar_extend_e);
	Graph_lib::Rectangle minimize(bar_minimize_s, bar_minimize_e);

	close.set_fill_color(Color::red);
	extend.set_fill_color(Color::green);
	minimize.set_fill_color(Color::yellow);

	// image content
	Image image0(Point(o.x + 10, o.y + 33), content_location);
	image0.set_mask(Point(o.x + 100, o.y + 300), w - 20, h - 20 - 23);

	// content window
	Graph_lib::Rectangle content_rect(Point(o.x + 10, o.y + 33), Point(o.x + w - 10, o.y + h - 10));

	if (color().visibility()) {
		// draw label bar text
		fl_draw(l.c_str(), point(0).x, point(0).y);

		// draw label bar line
		fl_line(bar_line_s.x, bar_line_s.y, bar_line_e.x, bar_line_e.y);

		// draw buttons
		close.draw();
		extend.draw();
		minimize.draw();

		// draw content image
		image0.draw();

		// draw content rectangle
		content_rect.draw();
				
		fl_line(a1.x, a1.y, b1.x, b1.y);
		fl_line(b2.x, b2.y, c1.x, c1.y);
		fl_line(c2.x, c2.y, d1.x, d1.y);
		fl_line(d2.x, d2.y, a2.x, a2.y);

		fl_arc(o.x, o.y, r + r, r + r, 90, 180);
		fl_arc(o.x + w - (r + r), o.y, r + r, r + r, 360, 90);
		fl_arc(o.x + w - (r + r), o.y + h - (r + r), r + r, r + r, 270, 360);
		fl_arc(o.x, o.y + h - (r + r), r + r, r + r, 180, 270);
	}
}

int main()
try
{
	Point tl(100, 100);
	Simple_window win(tl, 720, 400, "Simple Window");
	Point center(win.x_max() / 2, win.y_max() / 2);
	
	Pseudo_window p_win(Point(60, 50), 600, 300, 10, "pseudowin", "Input/Original-JPG-Image_large.jpg");
	p_win.set_color(Color::black);

	win.attach(p_win);
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