//  Philipp Siedler
//  Bjarne Stroustrup's PP
//  Chapter 15 Class Definition Drill 7

#include "std_lib_facilities.h"

struct Person
{
	Person(string first_name, string second_name, int age);
	Person() {}

	const string first_name() { return first_n; }
	const string second_name() { return second_n; }
	const int age() { return a; }

	void set_first_name(string first_name);
	void set_second_name(string second_name);
	void set_age(int age);

private:
	string first_n;
	string second_n;
	int a;
};

Person::Person(string first_name, string second_name, int age)
{
	for (char l : first_name) {
		if (!isalpha(l)) { error("first_name contains invalid character: ", first_name); }
	}
	for (char l : second_name) {
		if (!isalpha(l)) { error("second_name contains invalid character: ", second_name); }
	}
	if (age > 150 || age < 0) { error("age is not valid", age); }

	first_n = first_name;
	second_n = second_name;
	a = age;
}

void Person::set_first_name(string first_name)
{
	for (char l : first_name) {
		if (!isalpha(l)) { error("name contains invalid character: ", first_name); }
	}
	first_n = first_name;
}

void Person::set_second_name(string second_name)
{
	for (char l : second_name) {
		if (!isalpha(l)) { error("name contains invalid character: ", second_name); }
	}
	second_n = second_name;
}

void Person::set_age(int age)
{
	if (age > 150 || age < 0) { error("age is not valid", age); }
	a = age;
}

istream& operator>>(istream& is, Person& p) {
	string first_name;
	string second_name;
	int second_name_check;
	int age;

	is >> first_name;
	is >> second_name;
	for (char l : second_name) {
		if (!isalpha(l)) { error("there was no second name provided: ", second_name); }
	}
	is >> age;
	
	for (char l : first_name) {
		if (!isalpha(l)) { error("first_name contains invalid character: ", first_name); }
	}
	for (char l : second_name) {
		if (!isalpha(l)) { error("second_name contains invalid character: ", second_name); }
	}
	if (age > 150 || age < 0) { error("age is not valid", age); }

	p.set_first_name(first_name);
	p.set_second_name(second_name);
	p.set_age(age);

	return is;
}

ostream& operator<<(ostream& os, Person& p) {
	os << "Name: " << p.first_name() << ", " << p.second_name() << " Age: " << p.age();
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
Hans Peter 23
Phil Schneider 34
x
Output:
Name: Hans, Peter Age: 23
Name: Phil, Schneider Age: 34
Please enter a character to exit
*/