//  Philipp Siedler
//  Bjarne Stroustrup's PP
//  Chapter 15 Exercise 2

#define _USE_MATH_DEFINES
#include "Simple_window.h"
#include "Graph.h"
#include <cmath>

typedef double Fct(double);

double one(double x) { return 1; }
double slope(double x) { return x / 2; }
double square(double x) { return x * x; }
double sloping_cos(double x) { return cos(x) + slope(x); }
double sum_sin_cos(double x) { return sin(x) + cos(x); }
double sum_sin_cos_sq(double x) { return sin(x) * sin(x) + cos(x) * cos(x); }

struct myFct : Shape {
	myFct(Fct* f, double r1, double r2, Point orig, int count = 100, double xscale = 25, double yscale = 25);
	~myFct() {}

	void set_f(Fct* p) { f = p; }
	void set_r1(double r) { r1 = r; }
	void set_r2(double r) { r2 = r; }
	void set_orig(Point o) { orig = o; }
	void set_count(int c) { count = c; }
	void set_xscale(double x) { xscale = x; }
	void set_yscale(double y) { yscale = y; }

	double get_r1() { return r1; }
	double get_r2() { return r2; }
	Point get_orig() { return orig; }
	int get_count() { return count; }
	double get_xscale() { return xscale; }
	double get_yscale() { return yscale; }

	void calc();
	void reset(Fct* f, double r1, double r2, Point orig, int count = 100, double xscale = 25, double yscale = 25);
	
private:
	Fct* f;
	double r1;
	double r2;
	Point orig;
	int count;
	double xscale;
	double yscale;
};

myFct::myFct(Fct* f, double r1, double r2, Point orig, int count, double xscale, double yscale)
	:f(f), r1(r1), r2(r2), orig(orig), count(count), xscale(xscale), yscale(yscale)
{
	calc();
}

void myFct::calc()
{
	if (r2 - r1 <= 0) error("bad graphing range");
	if (count <= 0) error("non-positive graphing count");
	double dist = (r2 - r1) / count;
	double r = r1;
	for (int i = 0; i < count; ++i) {
		cout << f(r) << endl;
		add(Point(orig.x + int(r * xscale), orig.y - int(f(r) * yscale)));
		r += dist;
	}
}

void myFct::reset(Fct* f, double r1, double r2, Point orig, int count, double xscale, double yscale)
{
	set_f(f);
	set_r1(r1);
	set_r2(r2);
	set_orig(orig);
	set_count(count);
	set_xscale(xscale);
	set_yscale(yscale);
	calc();
}

int main()
try
{	
	int min = 0;
	int max = 5;
	Point origin(0, 0);
	int count = 5;

	myFct MF(one, min, max, origin, count);
	cout << "---" << endl;
	MF.reset(slope, min, max, origin, count);

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

/*
1
1
1
1
1
---
0
0.5
1
1.5
2
Please enter a character to exit
*/