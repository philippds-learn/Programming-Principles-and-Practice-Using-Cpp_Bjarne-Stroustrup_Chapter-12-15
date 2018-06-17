//  Philipp Siedler
//  Bjarne Stroustrup's PP
//  Chapter 14 Exercise 3

#define _USE_MATH_DEFINES
#include "Simple_window.h"
#include "Graph.h"
#include <cmath>
using namespace Graph_lib;

class abstract_class
{
protected:
	abstract_class() {};
};

int main()
try
{
	Point tl(100, 100);
	Simple_window win(tl, 720, 400, "Simple Window");
	Point center(win.x_max() / 2, win.y_max() / 2);

	//abstract_class a; //is inaccessible

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