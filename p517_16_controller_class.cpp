//  Philipp Siedler
//  Bjarne Stroustrup's PP
//  Chapter 14 Exercise 16

#define _USE_MATH_DEFINES
#include "Simple_window.h"
#include "Graph.h"
#include <cmath>

using namespace Graph_lib;

class Controller
{
public:
	virtual void set_on() = 0;
	virtual void set_off() = 0;
	virtual void set_level(int l) = 0;
	virtual void show() = 0;
protected:
	bool on;
	bool off;
	int level;
};

class Controller_test : public Controller
{
public:
	void set_on();
	void set_off();
	void set_level(int l);
	void show();
};

void Controller_test::set_on()
{
	on = true;
	off = false;
}

void Controller_test::set_off()
{
	on = false;
	off = true;
}

void Controller_test::set_level(int l)
{
	level = l;
}

void Controller_test::show()
{
	cout << "on = " << on << ", off = " << off << ", level = " << level << endl;
}

class Controller_shape : public Controller
{
public:
	Controller_shape(Shape& shape) :s(shape) {};
	void set_on();
	void set_off();
	void set_level(int l);
	void show();

private:
	Shape& s;
};

void Controller_shape::set_on()
{
	s.set_color(Color::visible);
	on = true;
	off = false;
}

void Controller_shape::set_off()
{
	s.set_color(Color::invisible);
	on = false;
	off = true;
}

void Controller_shape::set_level(int l)
{
	s.set_style(Line_style(l));
}

void Controller_shape::show()
{
	s.set_fill_color(Color::cyan);
}

int main()
try
{
	Point tl(100, 100);
	Simple_window win(tl, 720, 400, "Simple Window");
	Point center(win.x_max() / 2, win.y_max() / 2);
	
	Controller_test ct;
	ct.set_on();
	ct.set_level(5);
	ct.show();

	Graph_lib::Rectangle r(Point(200, 200), Point(400, 300));

	Controller_shape cs(r);
	cs.set_on();
	cs.show();
	cs.set_level(1);
	
	win.attach(r);
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
*/