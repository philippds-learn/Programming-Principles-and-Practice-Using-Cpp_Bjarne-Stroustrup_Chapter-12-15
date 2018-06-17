//  Philipp Siedler
//  Bjarne Stroustrup's PP
//  Chapter 15 Class Definition Drill 2

#include "std_lib_facilities.h"


struct Person
{
	string name;
	int age;	
};

int main()
try
{
	Person p1;
	p1.name = "Goofy";
	p1.age = 63;

	cout << "Name: " << p1.name << " Age: " << p1.age << endl;

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
Name: Goofy Age: 63
Please enter a character to exit
*/