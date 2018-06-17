//  Philipp Siedler
//  Bjarne Stroustrup's PP
//  Chapter 13 Exercise 5

#define _USE_MATH_DEFINES
#include "Simple_window.h"
#include "Graph.h"
#include <cmath>
using namespace Graph_lib;

ostream& operator<<(ostream& out, Point& a) {
	out << "(" << a.x << "," << a.y << ")";
	return out;
}

Point& operator+=(Point& a, Point& b) {
	a = Point(a.x + b.x, a.y + b.y);
	return a;
}

// CIRCLE -------------------------------

Point centerCircle(Graph_lib::Circle& cir) {
	return Point(cir.point(0).x + cir.radius(), cir.point(0).y + cir.radius());
}

Point nC(Graph_lib::Circle& cir) {
	Point temp = centerCircle(cir);
	return Point(temp.x, temp.y - cir.radius());
}

Point neC(Graph_lib::Circle& cir) {
	Point temp = centerCircle(cir);
	return Point(temp.x + cir.radius() * cos(M_PI / 4), temp.y - cir.radius() * sin(M_PI / 4));
}

Point eC(Graph_lib::Circle& cir) {
	Point temp = centerCircle(cir);
	return Point(temp.x + cir.radius(), temp.y);
}

Point seC(Graph_lib::Circle& cir) {
	Point temp = centerCircle(cir);
	return Point(temp.x + cir.radius() * cos(M_PI / 4), temp.y + cir.radius() * sin(M_PI / 4));
}

Point sC(Graph_lib::Circle& cir) {
	Point temp = centerCircle(cir);
	return Point(temp.x, temp.y + cir.radius());
}

Point swC(Graph_lib::Circle& cir) {
	Point temp = centerCircle(cir);
	return Point(temp.x - cir.radius() * cos(M_PI / 4), temp.y + cir.radius() * sin(M_PI / 4));
}

Point wC(Graph_lib::Circle& cir) {
	Point temp = centerCircle(cir);
	return Point(temp.x - cir.radius(), temp.y);
}

Point nwC(Graph_lib::Circle& cir) {
	Point temp = centerCircle(cir);
	return Point(temp.x - cir.radius() * cos(M_PI / 4), temp.y - cir.radius() * sin(M_PI / 4));
}

// ELLIPSE -------------------------------

Point nE(Graph_lib::Ellipse& eli) {
	int a = eli.major(); //width
	int b = eli.minor(); //height

	cout << a << endl;
	cout << b << endl;
	
	int x = eli.center().x;
	int y = eli.center().y - b;

	return Point(x,y);
}

Point neE(Graph_lib::Ellipse& eli) {
	int a = eli.major(); //width
	int b = eli.minor(); //height

	cout << a << endl;
	cout << b << endl;

	int x = eli.center().x + a * cos(M_PI / 4);
	int y = eli.center().y - b * sin(M_PI / 4);

	return Point(x, y);
}

Point eE(Graph_lib::Ellipse& eli) {
	int a = eli.major(); //width
	int b = eli.minor(); //height

	cout << a << endl;
	cout << b << endl;

	int x = eli.center().x + a;
	int y = eli.center().y;

	return Point(x, y);
}

Point seE(Graph_lib::Ellipse& eli) {
	int a = eli.major(); //width
	int b = eli.minor(); //height

	cout << a << endl;
	cout << b << endl;

	int x = eli.center().x + a * cos(M_PI / 4);
	int y = eli.center().y + b * sin(M_PI / 4);

	return Point(x, y);
}

Point sE(Graph_lib::Ellipse& eli) {
	int a = eli.major(); //width
	int b = eli.minor(); //height

	cout << a << endl;
	cout << b << endl;

	int x = eli.center().x;
	int y = eli.center().y + b;

	return Point(x, y);
}

Point swE(Graph_lib::Ellipse& eli) {
	int a = eli.major(); //width
	int b = eli.minor(); //height

	cout << a << endl;
	cout << b << endl;

	int x = eli.center().x - a * cos(M_PI / 4);
	int y = eli.center().y + b * sin(M_PI / 4);

	return Point(x, y);
}

Point wE(Graph_lib::Ellipse& eli) {
	int a = eli.major(); //width
	int b = eli.minor(); //height

	cout << a << endl;
	cout << b << endl;

	int x = eli.center().x - a;
	int y = eli.center().y;

	return Point(x, y);
}

Point nwE(Graph_lib::Ellipse& eli) {
	int a = eli.major(); //width
	int b = eli.minor(); //height

	cout << a << endl;
	cout << b << endl;

	int x = eli.center().x - a * cos(M_PI / 4);
	int y = eli.center().y - b * sin(M_PI / 4);

	return Point(x, y);
}

int main()
try
{
	Point tl(100, 100);
	Simple_window win(tl, 600, 400, "Simple Window");

	//CIRCLE
	Graph_lib::Circle testCircle(Point(200, 200), 50);
	testCircle.set_color(Color::red);

	Point ptCircle = neC(testCircle);

	Mark markCircle(ptCircle, '+');
	markCircle.set_color(Color::blue);
	cout << ptCircle << endl;

	win.attach(testCircle);
	win.attach(markCircle);

	//ELLIPSE
	Graph_lib::Ellipse testEllipse(Point(400, 200), 100, 50);
	testEllipse.set_color(Color::red);

	Point ptEllipse = neE(testEllipse);

	Mark markEllipse(ptEllipse, '+');
	markEllipse.set_color(Color::blue);

	cout << ptEllipse << endl;

	win.attach(testEllipse);
	win.attach(markEllipse);

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