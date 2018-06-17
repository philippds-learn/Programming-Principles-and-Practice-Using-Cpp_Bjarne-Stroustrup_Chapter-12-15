//  Philipp Siedler
//  Bjarne Stroustrup's PP
//  Chapter 14 Drill 3

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

void call(B1& b1_ref) {
	b1_ref.vf();
	b1_ref.f();	
}

int main()
try
{
	D1 d1;
	call(d1);
	
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
D1::vf
B1::f
Please enter a character to exit
*/