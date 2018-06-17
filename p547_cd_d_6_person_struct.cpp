//  Philipp Siedler
//  Bjarne Stroustrup's PP
//  Chapter 15 Class Definition Drill 6

#include "std_lib_facilities.h"

struct Person
{
	Person(string name, int age)
		:n(name), a(age) {}
	Person() {}

	const string name() { return n; }
	const int age() { return a; }

	void set_name(string name) { n = name; }
	void set_age(int age) { a = age; }

private:
	string n;
	int a;
};

istream& operator>>(istream& is, Person& p) {
	string name;
	int age;

	is >> name >> age;

	p.set_name(name);
	p.set_age(age);

	return is;
}

ostream& operator<<(ostream& os, Person& p) {
	os << "Name: " << p.name() << " Age: " << p.age();
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