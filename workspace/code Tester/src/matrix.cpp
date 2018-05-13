//============================================================================
// Name        : matrix.cpp
// Author      : James Galante
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

void swap(string *a, string *b) {
	string tmp = *a;
	*a = *b;
	*b = tmp;
}
void func(string *x, string *y, string *z ) {

	cout << *x << endl;
	cout << *y << endl;
	cout << *z << endl;


	if (*x <*y) {
		cout << "true1" << endl;
		swap(x,y);
	}
	if (*x < *z) {
		cout << "true2" << endl;

		swap(x,z);
	}
	if (*y < *z) {
		cout << "true3" << endl;
		swap (y,z);
	}

}
int main() {
	string a = "lo";
	string b = "ck";
	string c = "war";
	func(&a,&b,&c);
	cout << a << b<<c<< endl;

	return 0;
}

