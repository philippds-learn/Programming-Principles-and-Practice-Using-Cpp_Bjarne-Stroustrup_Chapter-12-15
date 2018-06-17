//  Philipp Siedler
//  Bjarne Stroustrup's PP
//  Chapter 15 Class Definition Drill 4

#include "std_lib_facilities.h"


struct Person
{
	Person(string name, int age)
		:name(name), age(age) {}
	Person() {}

	string name;
	int age;
};

istream& operator>>(istream& is, Person& p) {
	is >> p.name >> p.age;
	return is;
}

ostream& operator<<(ostream& os, Person& p) {
	os << "Name: " << p.name << " Age: " << p.age;
	return os;
}

int main()
try
{
	Person p1;
	cin >> p1;
	cout << p1 << endl;

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
Input:
Goofy 63
Output:
Name: Goofy Age: 63
Please enter a character to exit
*/