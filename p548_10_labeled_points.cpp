//  Philipp Siedler
//  Bjarne Stroustrup's PP
//  Chapter 15 Exercise 10

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

constexpr int x_scale = 2;
constexpr int y_scale = 2;

constexpr int xoffset = 100;
constexpr int yoffset = 100;

constexpr int xspace = 100;
constexpr int yspace = 100;

constexpr int xlength = xmax - xoffset - xspace;
constexpr int ylength = ymax - yoffset - yspace;

class bar_graph : public Shape
{
public:
	bar_graph(Point origin, vector<Point>& data, int x_scale, int r1_min, int r1_max, int y_scale, int r2_min, int r2_max, Color col, string label);

	void draw_lines() const;

	vector<Point>& get_data() { return data; }

private:
	Point origin;
	vector<Point>& data;

	int x_scale;
	int r1_min;
	int r1_max;

	int y_scale;
	int r2_min;
	int r2_max;

	int bar_width;

	Color col;
	string label;
};

bar_graph::bar_graph(Point origin, vector<Point>& data, int x_scale, int r1_min, int r1_max, int y_scale, int r2_min, int r2_max, Color col, string label)
	: origin(origin),
	data(data),
	x_scale(x_scale),
	r1_min(r1_min),
	r1_max(r1_max),
	y_scale(y_scale),
	r2_min(r2_min),
	r2_max(r2_max),
	bar_width(bar_width),
	col(col),
	label(label)
{

}

void bar_graph::draw_lines() const
{
	int ds = data.size();
	cout << ds << endl;


	for (int i = 0; i < data.size(); i++) {

		int h = data[i].x;
		int c = data[i].y;

		// scale factor
		double sx = (xlength / 2.0) / (r1_max - r1_min);
		double sy = (ylength / 2.0) / (r2_max - r2_min);

		// draw point
		Point p(origin.x + (h - r1_min) * sx, origin.y - (c - r2_min) * sy);
		cout << p << endl;

		Graph_lib::Circle crcl(p, 3);
		crcl.set_color(col);
		crcl.set_fill_color(col);
		crcl.draw();

		// draw label
		string point_label = "(" + to_string(data[i].x) + "," + to_string(data[i].y) + ")";
		Text l(p, point_label);
		l.set_color(Color::red);

		l.draw();

	}

	// graph label
	Text gl(Point(origin.x - 90, origin.y + 15), label);
	gl.set_color(col);

	gl.draw();
}

int main()
try
{
	Point tl(100, 100);
	Simple_window win(tl, xmax, ymax, "Function graphs.");

	int r1_min = 170;
	int r1_max = 180;

	int r2_min = 7;
	int r2_max = 23;

	// notch label x
	string x_notch = "1 == " + to_string((r1_max - r1_min) / 10);

	// notch label y
	ostringstream strs;
	strs << setprecision(2) << (r2_max - r2_min) / 10.0;
	string y_notch = "1 == " + strs.str();

	// x axis
	Axis x(Axis::x, Point(orig.x - 200, orig.y), 400, 20, x_notch);
	x.set_color(Color::black);
	win.attach(x);

	// y axis
	Axis y(Axis::y, Point(orig.x, orig.y + 200), 400, 20, y_notch);
	y.set_color(Color::black);
	win.attach(y);

	// people height data
	vector<Point> d = {
		Point(170, 7),
		Point(175, 9),
		Point(180, 23),
		Point(173, 8),
		Point(178, 20),
		Point(177, 15),
		Point(171, 10),
		Point(174, 19)
	};

	// bar graph
	bar_graph bg(orig, d, x_scale, r1_min, r1_max, y_scale, r2_min, r2_max, Color::blue, "labeled points");
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