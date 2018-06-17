//  Philipp Siedler
//  Bjarne Stroustrup's PP
//  Chapter 13 Exercise 7

#define _USE_MATH_DEFINES
#include "Simple_window.h"
#include "Graph.h"
#include <cmath>

using namespace Graph_lib;

/*
template<class T> class Vector_ref {
public:
	void push_back(T&); //add a named object
	void push_back(T*); //add a unnamed object

	T& operator[](int i); //subscripting: read and write access
	const T& operator[](int i) const;

	int size() const;
};
*/

int main()
try
{
	int xcount = 13;
	int ycount = 9;
	int cellSize = 20;

	Point tl(100, 100);
	Simple_window win(tl, 720, 400, "Simple Window");
	
	Vector_ref<Graph_lib::Rectangle> vr;
	
	for (int i = 0; i < 6; ++i) {
		for (int j = 0; j < 6; ++j) {
			for (int k = 0; k < 6; ++k) {
				vr.push_back(new Graph_lib::Rectangle(Point(i * 6 * cellSize + j*cellSize, k*cellSize), cellSize, cellSize));
				vr[vr.size() - 1].set_fill_color(fl_rgb_color(51 * i, 51 * j, 51 * k));
				vr[vr.size() - 1].set_color(Color(Color::black, Color::invisible));
				win.attach(vr[vr.size() - 1]);
			}
		}
	}

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