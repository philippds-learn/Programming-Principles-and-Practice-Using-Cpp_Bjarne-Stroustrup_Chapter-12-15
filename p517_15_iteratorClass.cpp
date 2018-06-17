//  Philipp Siedler
//  Bjarne Stroustrup's PP
//  Chapter 14 Exercise 15

#include "std_lib_facilities.h"

class Base_iterator
{
public:
	virtual double* next() = 0;
protected:
	int count;
};

//------------------------VECTOR ITERATOR

class Vector_iterator : public Base_iterator
{
public:
	Vector_iterator(vector<double>& v);
	double* next();
private:
	vector<double> vec;
};

Vector_iterator::Vector_iterator(vector<double>& v)
{
	vec = v;
	count = 0;
}

double* Vector_iterator::next()
{
	if (vec.size() > 0 && count < vec.size()) {
		
		count++;
		return &vec[count - 1];
	}
	else {
		return 0;
	}
}

//------------------------LIST ITERATOR

class List_iterator : public Base_iterator
{
public:
	List_iterator(list<double>& l);
	double* next();
private:
	list<double> lis;
	list<double>::iterator pointer;
};

List_iterator::List_iterator(list<double>& l)
{
	lis = l;
	pointer = lis.begin();
}

double* List_iterator::next() {
	double* p;

	if (lis.size() && lis.size() > distance(lis.begin(), pointer)) {
		p = &*pointer;
		pointer++;
		return p;
	}
	else return 0;
}

void print(Base_iterator& iterator)
{
	double* pointer;
	pointer = iterator.next();

	while (pointer != 0) {
		cout << *pointer << endl;
		pointer = iterator.next();
	}
}

int main()
try
{
	vector<double> v;
	v.push_back(2.0);
	v.push_back(2.1);
	v.push_back(2.2);
	v.push_back(2.3);

	list<double> l;
	l.push_back(2.0);
	l.push_back(2.1);
	l.push_back(2.2);
	l.push_back(2.3);

	Vector_iterator vi(v);
	print(vi);

	List_iterator li(l);
	print(li);

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
2
2.1
2.2
2.3
2
2.1
2.2
2.3
Please enter a character to exit
*/