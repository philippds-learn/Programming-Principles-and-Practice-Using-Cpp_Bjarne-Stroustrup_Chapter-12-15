//  Philipp Siedler
//  Bjarne Stroustrup's PP
//  Chapter 15 Exercise 6

#define _USE_MATH_DEFINES
#include "Simple_window.h"
#include "Graph.h"
#include <cmath>

ostream& operator<<(ostream& out, Point& a) {
	out << "(" << a.x << "," << a.y << ")";
	return out;
}

// layout
constexpr int xmax = 600;
constexpr int ymax = 600;

constexpr int x_orig = xmax / 2;
constexpr int y_orig = ymax / 2;
Point orig(x_orig, y_orig);

constexpr int r_min = -10;
constexpr int r_max = 10;

constexpr int n_points = 400;

constexpr int x_scale = 20;
constexpr int y_scale = 20;

constexpr int xoffset = 100;
constexpr int yoffset = 100;

constexpr int xspace = 100;
constexpr int yspace = 100;

constexpr int xlength = xmax - xoffset - xspace;
constexpr int ylength = ymax - yoffset - yspace;

// bar graph class

class bar_graph : public Shape
{
public:
	bar_graph(Point origin, vector<double> data, int bar_width, int gap_width, Color col);
		
	void draw_lines() const;

	vector<double> get_data() { return data; }

private:
	Point origin;
	vector<double> data;

	int bar_width;
	int gap_width;

	Color col;
};

bar_graph::bar_graph(Point origin, vector<double> data, int bar_width, int gap_width, Color col)
	: origin(origin), data(data), bar_width(bar_width), gap_width(gap_width), col(col)
{

}

void bar_graph::draw_lines() const
{
	int ds = data.size();

	
	for (int i = 0; i < data.size(); i++) {
		Point p0(origin.x + i * (bar_width + gap_width), origin.y);
		Point p1(origin.x + i * (bar_width + gap_width) + bar_width, origin.y);
		Point p2(origin.x + i * (bar_width + gap_width) + bar_width, origin.y - data[i]);
		Point p3(origin.x + i * (bar_width + gap_width), origin.y - data[i]);

		Closed_polyline cp;
		cp.add(p0);
		cp.add(p1);
		cp.add(p2);
		cp.add(p3);
		
		cp.set_color(col);
		cp.set_fill_color(col);

		cp.draw();
	}
	
}

int main()
try
{
	Point tl(100, 100);
	Simple_window win(tl, xmax, ymax, "Function graphs.");

	Axis x(Axis::x, Point(orig.x - 200, orig.y), 400, 20, "1 == 20");
	x.set_color(Color::black);
	win.attach(x);

	Axis y(Axis::y, Point(orig.x, orig.y + 200), 400, 20, "1 == 20");
	y.set_color(Color::black);
	win.attach(y);

	vector<double> d = { 120, 123, 115, 110, 55};
	
	bar_graph bg(orig, d, 10, 20, Color::red);

	win.attach(bg);

	win.wait_for_button();
	keep_window_open();
}
catch (exception& e) {
	cerr << "error: " << e.what() << '\n';
	keep_window_open();
	return 1;
}

catch (...) {
	cerr << "Unknown exception!\n";
	keep_window_open();
	return 2;
}