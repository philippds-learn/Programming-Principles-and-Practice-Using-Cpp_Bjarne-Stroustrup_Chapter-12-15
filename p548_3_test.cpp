//  Philipp Siedler
//  Bjarne Stroustrup's PP
//  Chapter 15 Exercise 3

// Make the type of that argument a template parameter for extra flexibility

#define _USE_MATH_DEFINES
#include "Simple_window.h"
#include "Graph.h"
#include <cmath>

template <class T> class myFct {
public:
	myFct(T precision = 1.0)
		:precision(precision) {}
	~myFct() {}

private:

	T precision;
};

int main()
try
{
	int min = 0;
	int max = 5;
	Point origin(0, 0);
	int count = 5;

	myFct<double> MF(2.0);

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
