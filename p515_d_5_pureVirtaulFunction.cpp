//  Philipp Siedler
//  Bjarne Stroustrup's PP
//  Chapter 14 Drill 5

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

void call(B1& b1_ref) {
	b1_ref.f();
	b1_ref.vf();
	b1_ref.pvf();
}

int main()
try
{
	cout << "drill 1" << endl;
	//B1 b1;
	//b1.f();
	//b1.vf();
	cout << "not allowed, B1::pvf is a pure virtual function" << endl;

	cout << "drill 2" << endl;
	D1 d2;
	d2.f();
	d2.vf();
	d2.pvf();

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
not allowed, B1::pvf is a pure virtual function
drill 2
D1::f
D1::vf
D1::pvf
drill 3
B1::f
D1::vf
D1::pvf
Please enter a character to exit
*/