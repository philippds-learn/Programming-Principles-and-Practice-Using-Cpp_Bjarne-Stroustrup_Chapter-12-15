//  Philipp Siedler
//  Bjarne Stroustrup's PP
//  Chapter 14 Drill 1

#include "std_lib_facilities.h"
using namespace std;

class B1
{
public:
	virtual void vf() { cout << "B1::vf" << endl; }
	void f() { cout << "B1::f" << endl; }
};

int main()
try
{
	B1 b1;
	b1.f();
	b1.vf();

	keep_window_open();
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
B1::f
B1::vf
Please enter a character to exit
*/