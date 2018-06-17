//  Philipp Siedler
//  Bjarne Stroustrup's PP
//  Chapter 14 Drill 6

#include "std_lib_facilities.h"
using namespace std;

class B1
{
public:
	virtual void vf() { cout << "B1::vf" << endl; }
	void f() { cout << "B1::f" << endl; }
	virtual void pvf() = 0;
};

class D1 : public B1
{
public:
	void vf() { cout << "D1::vf" << endl; }
	void f() { cout << "D1::f" << endl; }
	void pvf() { cout << "D1::pvf" << endl; }
};

class D2 : public D1
{
public:
	void pvf() { cout << "D2::pvf" << endl; }
};

int main()
try
{
	D2 d2_0;
	d2_0.f();
	d2_0.vf();
	d2_0.pvf();

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
D1::f
D1::vf
D2::pvf
Please enter a character to exit
*/