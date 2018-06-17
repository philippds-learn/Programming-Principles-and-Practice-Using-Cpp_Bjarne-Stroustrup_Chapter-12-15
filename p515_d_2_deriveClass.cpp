//  Philipp Siedler
//  Bjarne Stroustrup's PP
//  Chapter 14 Drill 2

#include "std_lib_facilities.h"
using namespace std;

class B1
{
public:
	virtual void vf() { cout << "B1::vf" << endl; }
	void f() { cout << "B1::f" << endl; }
};

class D1 : public B1
{
public:
	void vf() { cout << "D1::vf" << endl; }
};

int main()
try
{
	D1 d1;
	d1.f();
	d1.vf();

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
D1::vf
Please enter a character to exit
*/