//  Philipp Siedler
//  Bjarne Stroustrup's PP
//  Chapter 15 Exercise 1

#include "std_lib_facilities.h"

int fac_recursive(int n) { return n > 1 ? n * fac_recursive(n - 1) : 1; } // factorial n!

int fac_iterative(int n)
{
	int r = 1;
	while (n > 1) {
		r *= n;
		--n;
	}
	return r;
}

int main()
try
{
	for (int i = 0; i < 21; i++) {
		cout << fac_recursive(i) << endl;
	}

	for (int i = 0; i < 21; i++) {
		cout << fac_iterative(i) << endl;
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
1
1
2
6
24
120
720
5040
40320
362880
3628800
39916800
479001600
1932053504
1278945280
2004310016
2004189184
-288522240
-898433024
109641728
-2102132736
1
1
2
6
24
120
720
5040
40320
362880
3628800
39916800
479001600
1932053504
1278945280
2004310016
2004189184
-288522240
-898433024
109641728
-2102132736
Please enter a character to exit
*/