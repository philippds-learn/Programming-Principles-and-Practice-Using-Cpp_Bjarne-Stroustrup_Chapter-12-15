//  Philipp Siedler
//  Bjarne Stroustrup's PP
//  Chapter 15 Exercise 8

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

struct ppl_height
{
	ppl_height(double height, int count)
		:height(height), count(count) {	}
	double height;
	int count;
};

void read_data(string location, vector<ppl_height>& v)
{
	ifstream ist(location);
	if (!ist) { error("no such file exists", location); }

	char comma;
	double height;
	int count;

	while (ist >> height >> comma >> count)
	{
		if (ist.eof()) {
			break;
		}
		v.push_back(ppl_height(height, count));
	}

}

class bar_graph : public Shape
{
public:
	bar_graph(Point origin, vector<ppl_height>& data, int x_scale, int r1_min, int r1_max, int y_scale, int r2_min, int r2_max, int bar_width, Color col, string label);

	void draw_lines() const;

	vector<ppl_height>& get_data() { return data; }

private:
	Point origin;
	vector<ppl_height>& data;

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

bar_graph::bar_graph(Point origin, vector<ppl_height>& data, int x_scale, int r1_min, int r1_max, int y_scale, int r2_min, int r2_max, int bar_width, Color col, string label)
	:	origin(origin),
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


	for (int i = 0; i < data.size(); i++) {

		double w = double(bar_width / 2);
		int h = data[i].height;
		int c = data[i].count;

		// scale factor
		double sx = (xlength / 2.0) / (r1_max - r1_min);
		double sy = (ylength / 2.0) / (r2_max - r2_min);
		
		Point p0(origin.x + (h - r1_min) * sx - w, origin.y - c * sy);
		Point p1(origin.x + (h - r1_min) * sx + w, origin.y);

		Graph_lib::Rectangle r(p0, p1);

		r.set_color(col);
		r.set_fill_color(col);

		r.draw();

		// bar labels
		string hl = to_string((int)data[i].height);
		Text height_label(Point(p1.x - bar_width, p1.y + 15), hl);
		height_label.set_color(col);
		height_label.draw();
		
		string cl = to_string((int)data[i].count);
		Text count_label(Point(p0.x, p0.y - 10), cl);
		count_label.set_color(col);
		count_label.draw();

	}

	// graph label
	Text gl(Point(origin.x - 70, origin.y + 15), label);
	gl.set_color(col);

	gl.draw();
}

int main()
try
{
	Point tl(100, 100);
	Simple_window win(tl, xmax, ymax, "Function graphs.");

	int r1_min = 160;
	int r1_max = 200;

	int r2_min = 5;
	int r2_max = 30;

	int bar_width = 15;
	
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
	vector<ppl_height> d = {	ppl_height(170, 7),
								ppl_height(175, 9),
								ppl_height(180, 23),
								ppl_height(185, 17),
								ppl_height(190, 6),
								ppl_height(195, 1)
	};

	// stream data from file
	vector<ppl_height> dff;
	string location = "input/height_data.txt";
	read_data(location, dff);

	// bar graph
	bar_graph bg(orig, dff, x_scale, r1_min, r1_max, y_scale, r2_min, r2_max, bar_width, Color::blue, "bar graph");
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