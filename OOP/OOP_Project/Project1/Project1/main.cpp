//#define TEST

#include <iostream>
#include <map>
#include <string>
#include "Integer.h"
#include "Decimal.h"
#include "CLI.h"

using namespace std;

bool test() {
	bool test_pass = true;

	if (!Integer::test()) {
		cout << "Test Integer fail." << endl;
		test_pass = false;
	}
	if (!Decimal::test()) {
		cout << "Test Decimal fail." << endl;
		test_pass = false;
	}

	//test common base

	vector<Number> ns;
	Integer i = Integer("3");
	Decimal d = Decimal("2.5");

	ns.push_back(i);
	ns.push_back(d);

	stringstream ss1, ss2;
	ss1 << ns[0] << endl << ns[1] << endl;
	ss2 << Integer("3") << endl << Decimal("2.5") << endl;
	if (!(ss1.str() == ss2.str())) {
		cout << "common vector fail" << endl;
		test_pass = false;
	}

	// test i to d

	Integer x("123456789");
	Decimal y("3.1415926");

	//cin >> x; // ¿é¤J 123456789
	//cin >> y; // ¿é¤J 3.1415926

	if (!(x + y == Decimal("123456792.1415926") &&
		x - y == Decimal("123456785.8584074") &&
		x * y == Decimal("387850934.7421614") &&
		x / y == Decimal(x)/y
		)) {
		cout << "i to d fail" << endl;
		test_pass = false;
	}

	return test_pass;
}

int main() {

#ifdef TEST
	if (test()) {
		cout << "Test pass." << endl;
	}
	else {
		cout << "Test fail." << endl;
	}
	cout << endl;
#endif // TEST

	CLI cli;
	cli.start();
	
}

