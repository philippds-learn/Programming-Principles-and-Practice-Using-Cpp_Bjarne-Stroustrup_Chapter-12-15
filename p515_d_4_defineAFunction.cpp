//  Philipp Siedler
//  Bjarne Stroustrup's PP
//  Chapter 14 Drill 4

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
	void f() { cout << "D1::f" << endl; }
};

void call(B1& b1_ref) {	
	b1_ref.f();
	b1_ref.vf();
}

int main()
try
{
	cout << "drill 1" << endl;
	B1 b1;
	b1.f();
	b1.vf();

	cout << "drill 2" << endl;
	D1 d2;
	d2.f();
	d2.vf();

	cout << "drill 3" << endl;
	D1 d3;
	call(d3);

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
drill 1
B1::f
B1::vf
drill 2
D1::f
D1::vf
drill 3
B1::f
D1::vf
Please enter a character to exit
*/