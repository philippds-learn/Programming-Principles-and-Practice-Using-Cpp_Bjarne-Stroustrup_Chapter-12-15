//  Philipp Siedler
//  Bjarne Stroustrup's PP
//  Chapter 15 Class Definition Drill 8

#include "std_lib_facilities.h"

struct Person
{
	Person(string name, int age);
	Person() {}

	const string name() { return n; }
	const int age() { return a; }

	void set_name(string name);
	void set_age(int age);

private:
	string n;
	int a;
};

Person::Person(string name, int age)
{
	for (char l : name) {
		if (!isalpha(l)) { error("name contains invalid character: ", name); }
	}
	if (age > 150 || age < 0) { error("age is not valid", age); }

	n = name;
	a = age;
}

void Person::set_name(string name)
{
	for (char l : name) {
		if (!isalpha(l)) { error("name contains invalid character: ", name); }
	}
	n = name;
}

void Person::set_age(int age)
{
	if (age > 150 || age < 0) { error("age is not valid", age); }
	a = age;
}

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
	vector<Person> ppl;

	char check;

	while (true) {
		cin >> check;
		if (check == 'x') {
			break;
		}
		else {
			cin.putback(check);
			cin >> p1;
			ppl.push_back(p1);
		}		
	}

	for (Person p : ppl) {
		cout << p << endl;
	}

	keep_window_open();
}
catch (exception& e) {
	cerr << "error: " << e.what() << '\n';
	keep_window_open();
	return 1;
}

catch (...) {
	cerr << "Unknown exception!\n";
	keep_window_open();
	return 2;
}

/*
Input:
Phil 28
Jasmin 30
Benjamin 22
x
Output:
Name: Phil Age: 28
Name: Jasmin Age: 30
Name: Benjamin Age: 22
Please enter a character to exit
*/