//  Philipp Siedler
//  Bjarne Stroustrup's PP
//  Chapter 13 Exercise 4

#define _USE_MATH_DEFINES
#include "Simple_window.h"
#include "Graph.h"
#include <cmath>
using namespace Graph_lib;

ostream& operator<<(ostream& out, Point& a) {
	out << "(" << a.x << "," << a.y << ")";
	return out;
}

Point ne(Graph_lib::Rectangle& rect) {
	return rect.point(0);
}

Point n(Graph_lib::Rectangle& rect) {
	Point originPt = rect.point(0);
	return Point(originPt.x + rect.width() / 2, originPt.y);
}

Point nw(Graph_lib::Rectangle& rect) {
	Point originPt = rect.point(0);
	return Point(originPt.x + rect.width(), originPt.y);
}

Point w(Graph_lib::Rectangle& rect) {
	Point originPt = rect.point(0);
	return Point(originPt.x + rect.width(), originPt.y + rect.height() / 2);
}

Point sw(Graph_lib::Rectangle& rect) {
	Point originPt = rect.point(0);
	return Point(originPt.x + rect.width(), originPt.y + rect.height());
}

Point s(Graph_lib::Rectangle& rect) {
	Point originPt = rect.point(0);
	return Point(originPt.x + rect.width() / 2, originPt.y + rect.height());
}

Point se(Graph_lib::Rectangle& rect) {
	Point originPt = rect.point(0);
	return Point(originPt.x, originPt.y + rect.height());
}

Point e(Graph_lib::Rectangle& rect) {
	Point originPt = rect.point(0);
	return Point(originPt.x, originPt.y + rect.height() / 2);
}

int main()
try
{
	Point tl(100, 100);
	Simple_window win(tl, 600, 400, "Simple Window");

	Graph_lib::Rectangle testRect(Point(100,100), Point(300,200));
	testRect.set_color(Color::red);

	Point myPoint = n(testRect);
	Mark myMark(myPoint, 'x');
	myMark.set_color(Color::blue);
	cout << myPoint << endl;

	win.attach(testRect);
	win.attach(myMark);

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