//  Philipp Siedler
//  Bjarne Stroustrup's PP
//  Chapter 15 Exercise 4

#define _USE_MATH_DEFINES
#include "Simple_window.h"
#include "Graph.h"
#include <cmath>


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

// graphing functions
typedef double Fct(double);

double one(double x) { return 1; }
double slope(double x) { return x / 2; }
double square(double x) { return x * x; }
double sloping_sin(double x) { return sin(x) + slope(x); }
double sloping_cos(double x) { return cos(x) + slope(x); }
double sum_sin_cos(double x) { return sin(x) + cos(x); }
double sum_sin_cos_sq(double x) { return sin(x) * sin(x) + cos(x) * cos(x); }

template <class T> class myFct : public Shape {
public:
	myFct(Fct* f, double r1, double r2, Point orig, int count = 100, double xscale = 25, double yscale = 25, T precision = 1.0);
	~myFct() {}

	void set_f(Fct* p) { f = p; }
	void set_r1(double r) { r1 = r; }
	void set_r2(double r) { r2 = r; }
	void set_orig(Point o) { orig = o; }
	void set_count(int c) { count = c; }
	void set_xscale(double x) { xscale = x; }
	void set_yscale(double y) { yscale = y; }
	void set_precision(T p) { precision = p; }

	double get_r1() { return r1; }
	double get_r2() { return r2; }
	Point get_orig() { return orig; }
	int get_count() { return count; }
	double get_xscale() { return xscale; }
	double get_yscale() { return yscale; }
	T get_precision() { return precision; }

	void calc();
	void reset(Fct* f, double r1, double r2, Point orig, int count = 100, double xscale = 25, double yscale = 25, T precision = 1.0);

private:
	Fct* f;
	double r1;
	double r2;
	Point orig;
	int count;
	double xscale;
	double yscale;
	T precision;
};

template <class T> myFct<T>::myFct(Fct* f, double r1, double r2, Point orig, int count, double xscale, double yscale, T precision)
	:f(f), r1(r1), r2(r2), orig(orig), count(count), xscale(xscale), yscale(yscale), precision(precision)
{
	calc();
}

template <class T> void myFct<T>::calc()
{
	if (r2 - r1 <= 0) error("bad graphing range");
	if (count <= 0) error("non-positive graphing count");
	double dist = (r2 - r1) / count;
	double r = r1;
	for (int i = 0; i < count; ++i) {		
		int x = orig.x + int(int(r * xscale) / precision) * precision;
		int y = orig.y - int(int(f(r) * yscale) / precision) * precision;
		add(Point(x, y));
		r += dist;
	}
}

template <class T> void myFct<T>::reset(Fct* f, double r1, double r2, Point orig, int count, double xscale, double yscale, T precision)
{
	set_f(f);
	set_r1(r1);
	set_r2(r2);
	set_orig(orig);
	set_count(count);
	set_xscale(xscale);
	set_yscale(yscale);
	set_precision(precision);
	calc();
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

	myFct<double> sin_graph(sin, r_min, r_max, orig, n_points, x_scale, y_scale);
	sin_graph.set_color(Color::blue);
	Text sg_label(Point(xoffset, orig.y + 60), "sin(x)");
	sg_label.set_color(Color::blue);
	win.attach(sin_graph);
	win.attach(sg_label);

	myFct<double> cos_graph(cos, r_min, r_max, orig, n_points, x_scale, y_scale);
	cos_graph.set_color(Color::green);
	Text cg_label(Point(xoffset, orig.y + 80), "cos(x)");
	cg_label.set_color(Color::green);
	win.attach(cos_graph);
	win.attach(cg_label);
	
	myFct<double> sin_cos_graph(sum_sin_cos, r_min, r_max, orig, n_points, x_scale, y_scale);
	sin_cos_graph.set_color(Color::cyan);
	Text scg_label(Point(xoffset, orig.y + 100), "sin(x) + cos(x)");
	scg_label.set_color(Color::cyan);
	win.attach(sin_cos_graph);
	win.attach(scg_label);

	myFct<double> sin_cos_sq_graph(sum_sin_cos_sq, r_min, r_max, orig, n_points, x_scale, y_scale);
	sin_cos_sq_graph.set_color(Color::magenta);
	Text scsq_label(Point(xoffset, orig.y - 40), "sin(x) * sin(x) + cos(x) * cos(x)");
	scsq_label.set_color(Color::magenta);
	win.attach(sin_cos_sq_graph);
	win.attach(scsq_label);
	
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