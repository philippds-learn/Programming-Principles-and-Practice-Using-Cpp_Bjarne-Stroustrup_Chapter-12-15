//  Philipp Siedler
//  Bjarne Stroustrup's PP
//  Chapter 14 Exercise 8

#define _USE_MATH_DEFINES
#include "Simple_window.h"
#include "Graph.h"
#include <cmath>

using namespace Graph_lib;

ostream& operator<<(ostream& out, Point& a) {
	out << "(" << a.x << "," << a.y << ")";
	return out;
}

struct Regular_octagon : Closed_polyline
{
	Regular_octagon(Point origin, int radius)
		: o(origin), r(radius)
	{
		set_color(Color::red);
		generate_points();
	};

	void draw_lines() const;
	
private:
	Point o;
	vector<Point> pts;
	int r;

	void add() {}
	void generate_points();
	vector<Point> get_pts() { return pts; };

};

void Regular_octagon::generate_points()
{
	int n = 8;
	for (int i = 0; i < n; i++) {
		pts.push_back(Point(o.x + r * cos(2 * M_PI * i / n), o.y + r * sin(2 * M_PI * i / n)));
		Closed_polyline::add(pts[i]);
	}
};

void Regular_octagon::draw_lines() const
{
	Closed_polyline::draw_lines();
};


int main()
try
{
	Point tl(100, 100);
	Simple_window win(tl, 720, 400, "Simple Window");
	Point center(win.x_max() / 2, win.y_max() / 2);

	Regular_octagon o(center, 50);

	// add();
	// o.add(); // function inaccesible
	
	// color();
	cout << o.color().as_int() << endl; // Output: 88
	cout << o.color().black << endl; // Output: 56
	cout << o.color().blue << endl; // Output: 216
	cout << o.color().cyan << endl; // Output: 223
	cout << o.color().dark_blue << endl; // Output: 136
	cout << o.color().dark_cyan << endl; // Output: 140
	cout << o.color().dark_green << endl; // Output: 60
	cout << o.color().dark_magenta << endl; // Output: 152
	cout << o.color().dark_red << endl; // Output: 72
	cout << o.color().dark_yellow << endl; // Output: 76
	cout << o.color().green << endl; // Output: 63
	cout << o.color().invisible << endl; // Output: 0
	cout << o.color().magenta << endl; // Output: 248
	cout << o.color().red << endl; // Output: 88
	o.color().set_visibility(Color::Transparency(0));
	o.color().visibility();

	// draw();
	o.draw();

	// draw_lines();
	o.draw_lines();

	// fill_color();
	cout << o.fill_color().as_int() << endl; // Output: 88
	cout << o.fill_color().black << endl; // Output: 56
	cout << o.fill_color().blue << endl; // Output: 216
	cout << o.fill_color().cyan << endl; // Output: 223
	cout << o.fill_color().dark_blue << endl; // Output: 136
	cout << o.fill_color().dark_cyan << endl; // Output: 140
	cout << o.fill_color().dark_green << endl; // Output: 60
	cout << o.fill_color().dark_magenta << endl; // Output: 152
	cout << o.fill_color().dark_red << endl; // Output: 72
	cout << o.fill_color().dark_yellow << endl; // Output: 76
	cout << o.fill_color().green << endl; // Output: 63
	cout << o.fill_color().invisible << endl; // Output: 0
	cout << o.fill_color().magenta << endl; // Output: 248
	cout << o.fill_color().red << endl; // Output: 88
	o.fill_color().set_visibility(Color::Transparency::invisible);
	o.fill_color().set_visibility(Color::Transparency::visible);
	o.fill_color().visibility();

	// move();
	o.move(100, -100);

	// number_of_points();
	cout << o.number_of_points() << endl; // Output: 8

	// Open_polyline
	//o.Open_polyline.add(Point(100, 100)); // typename is not allowed
	
	// point();
	cout << o.point(0) << endl; // Output: (510,100)

	// set_color();
	o.set_color(Color::red); // sets color to red
	
	// set_fill_color();
	o.set_fill_color(Color::cyan); // sets fill_color to cyan

	// set_style();
	o.set_style(Line_style(Line_style::dash, 5)); // sets line style: dashed, 5 width

	// Shape
	//o.Shape // typename is not allowed

	// style();
	cout << o.style().dash << endl; // Output: 1
	cout << o.style().dashdot << endl; // Output: 3
	cout << o.style().dashdotdot << endl; // Output: 4
	cout << o.style().dot << endl; // Output: 2
	cout << o.style().solid << endl; // Output: 0
	cout << o.style().style() << endl; // Output: 1
	cout << o.style().width() << endl; // Output: 5

	// ~Shape
	//o.~Shape // invalid destructor name for type "Regular_octagon"

	win.attach(o);
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

/*
88
56
216
223
136
140
60
152
72
76
63
0
248
88
0
56
216
223
136
140
60
152
72
76
63
0
248
88
8
(510,100)
1
3
4
2
0
1
5
*/