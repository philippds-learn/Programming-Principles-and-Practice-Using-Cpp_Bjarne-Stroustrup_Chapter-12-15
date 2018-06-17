//  Philipp Siedler
//  Bjarne Stroustrup's PP
//  Chapter 14 Drill 7

#include "std_lib_facilities.h"
using namespace std;

class B2
{
public:
	virtual void pvf() = 0;
};

class D21 : public B2
{
public:
	void pvf() { cout << data << endl; }
	string data;
};

class D22 : public B2
{
public:
	void pvf() { cout << val << endl; }
	int val;
};

void f(B2& b2_ref) {
	b2_ref.pvf();
}

int main()
try
{
	D21 d21;
	d21.data = "hello";
	D22 d22;
	d22.val = 5;

	f(d21);
	f(d22);

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
hello
5
Please enter a character to exit
*/