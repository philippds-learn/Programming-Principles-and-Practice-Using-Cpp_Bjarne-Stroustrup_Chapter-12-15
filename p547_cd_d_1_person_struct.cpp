//  Philipp Siedler
//  Bjarne Stroustrup's PP
//  Chapter 15 Class Definition Drill 1

#include "std_lib_facilities.h"

struct Person
{
	string name;
	int age;
};

int main()
try
{
	
}
catch (exception& e) {
	cout << e.what() << endl;
	return 1;
}
catch (...) {
	cout << "Exiting" << endl;
	return 2;
}