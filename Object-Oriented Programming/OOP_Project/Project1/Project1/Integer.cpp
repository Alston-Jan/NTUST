#include <iostream>
#include "Integer.h"
#include "Calculator.h"

using std::cout;
using std::endl;

Integer::Integer() {
	flag = 1;
	Int.push_back(0);
}

Integer::Integer(string s) {
	if (!Calculator::is_num(s)) {
		Number r = Calculator::evaluate(s);
		if (r.type == Number::DECIMAL)r = r.decimal.to_integer();
		else *this = r.integer;
	}
	else
	{
		flag = 1;
		if (s[0] == '-') {
			flag = -1;
			s = s.substr(1, s.size() - 1);
		}
		if (s[0] == '+') {
			flag = 1;
			s = s.substr(1, s.size() - 1);
		}
		for (auto i = s.rbegin(); i != s.rend(); i++) {
			if (*i == '.') break;
			Int.push_back(*i - '0');
		}
		simplefy();
		if (Int.size() == 1 && Int[0] == 0)
		{
			flag = 1;
		}
	}
}

Integer::Integer(Integer& from) {
	from.simplefy();
	flag = from.flag;
	Int = from.Int;
	if (Int.size() == 1 && Int[0] == 0)
	{
		flag = 1;
	}
}

Integer::Integer(Integer&& from) {
	from.simplefy();
	flag = from.flag;
	Int = from.Int;
	if (Int.size() == 1 && Int[0] == 0)
	{
		flag = 1;
	}
}

Integer Integer::operator+(Integer plusInt) {

	if (flag == -1 && plusInt.flag == -1) {
		Integer a = (*this);
		a.flag = 1;
		plusInt.flag = 1;
		a += plusInt;
		a.flag = -1;
		return a.simplefy();
	}
	else if (flag == 1 && plusInt.flag == -1)
	{
		plusInt.flag = 1;
		return ((*this) - plusInt).simplefy();
	}
	else if (flag == -1 && plusInt.flag == 1)
	{
		Integer a = (*this);
		a.flag = 1;
		return (plusInt - a).simplefy();
	}
	else
	{
		int plus = 0, index = 0;
		for (index; index < std::min(Int.size(), plusInt.Int.size()); index++) {

			int x = Int[index] + plusInt.Int[index] + plus; // x = each digit sum
			plusInt.Int[index] = x % 10;
			plus = x / 10;
		}
		if (Int.size() > plusInt.Int.size()) {
			for (index = plusInt.Int.size(); index < Int.size(); index++) {
				int x = Int[index] + plus;
				plusInt.Int.push_back(x % 10);
				plus = x / 10;
			}
		}
		else if (Int.size() < plusInt.Int.size()) {
			for (index = Int.size(); index < plusInt.Int.size(); index++) {
				int x = plusInt.Int[index] + plus;
				plusInt.Int[index] = x % 10;
				plus = x / 10;
			}
		}
		if (plus) {
			plusInt.Int.push_back(plus);
		}

		return plusInt.simplefy();
	}
}

Integer Integer::operator-(Integer diffInt) {
	if (flag == -1 && diffInt.flag == -1) {
		Integer a = (*this);
		a.flag = 1;
		diffInt.flag = 1;
		return (diffInt - a).simplefy();
	}
	else if (flag == 1 && diffInt.flag == -1)
	{
		diffInt.flag = 1;
		return ((*this) + diffInt).simplefy();
	}
	else if (flag == -1 && diffInt.flag == 1)
	{
		Integer a = (*this);
		a.flag = 1;
		a += diffInt;
		a.flag = -1;
		return a.simplefy();
	}
	else if( *this < diffInt)
	{
		diffInt -= (*this);
		diffInt.flag = -1;
		return diffInt.simplefy();
	}
	else
	{
		int minus = 0, index = 0;
		for (; index < diffInt.Int.size(); index++) {
			if (Int[index] - diffInt.Int[index] - minus < 0) {
				diffInt.Int[index] = 10 + Int[index] - diffInt.Int[index] - minus; // x = each digit difference
				minus = 1;
			}
			else {
				diffInt.Int[index] = Int[index] - diffInt.Int[index] - minus;
				minus = 0;
			}
		}

		for (index = diffInt.Int.size(); index < Int.size(); index++) {
			if (Int[index] - minus < 0) {
				diffInt.Int.push_back(10 + Int[index] - minus);
				minus = 1;
			}
			else {
				diffInt.Int.push_back(Int[index] - minus);
				minus = 0;
			}
		}

		for (int i = diffInt.Int.size() - 1; i > 0; i--) {
			if (diffInt.Int[i])break;
			diffInt.Int.pop_back();
		}
		return diffInt.simplefy();
	}
}

Integer Integer::operator*(Integer multiInt) {
	Integer product;

	if ((Int.size() == 1 && Int[0] == 0) || (multiInt.Int.size() == 1 && multiInt.Int[0] == 0)) {
		//product.flag = 1;
		//product.Int.push_back(0);
		return product;
	}

	if (flag == multiInt.flag) product.flag = 1;
	else product.flag = -1;

	for (int indextotal = 0; indextotal < Int.size() + multiInt.Int.size() - 2; indextotal++) {
		product.Int.push_back(0);
	}

	for (int indexsecond = 0; indexsecond < multiInt.Int.size(); indexsecond++) {
		for (int index = 0; index < Int.size(); index++) {
			product.Int[index + indexsecond] += (Int[index] * multiInt.Int[indexsecond]);
		}
	}

	int plus = 0;
	for (int indextotal = 0; indextotal < Int.size() + multiInt.Int.size() - 1; indextotal++) {
		int x = (product.Int[indextotal] + plus);
		product.Int[indextotal] = x % 10;
		plus = x / 10;
	}

	if (plus) {
		product.Int.push_back(plus % 10);
		plus /= 10;
	}

	return product.simplefy();
}

Integer Integer::operator/(Integer div) {
	Integer q("0"), a = (*this), p("1");
	int q_flag = flag * div.flag;
	a.flag = 1;
	div.flag = 1;

	while (!(div * p > a))p.Int.insert(p.Int.begin(), 0); // *= 10
	if (p.Int.size()>1)p.Int.erase(p.Int.begin()); // /=10

	while (p > Integer("0")) {
		while (a >= div * p) {
			a -= div * p;
			q += p;
		}
		p.Int.erase(p.Int.begin());
	}

	q.flag = q_flag;
	return q.simplefy();
}

Integer Integer::operator%(Integer remDec) {
	Integer a = (*this) / remDec;
	a = (*this) - (a * remDec);
	return a.simplefy();
}

Integer Integer::operator-() {
	Integer a = (*this);
	a.flag *= -1;
	return a.simplefy();
}

bool Integer::operator>(Integer compareInt) {
	(*this).simplefy();
	compareInt.simplefy();
	if (flag == 1 && compareInt.flag == -1) return true;
	if (flag == -1 && compareInt.flag == 1) return false;
	if (Int.size() > compareInt.Int.size()) return true;
	if (Int.size() < compareInt.Int.size()) return false;

	for (int i = Int.size() - 1; i >= 0; i--) {
		if (Int[i] > compareInt.Int[i]) return true;
		if (Int[i] < compareInt.Int[i]) return false;
	}
	return false; // ==
}

bool Integer::operator<(Integer compareInt) {
	(*this).simplefy();
	compareInt.simplefy();
	if (flag == 1 && compareInt.flag == -1) return false;
	if (flag == -1 && compareInt.flag == 1) return true;
	if (Int.size() > compareInt.Int.size()) return false;
	if (Int.size() < compareInt.Int.size()) return true;

	for (int i = Int.size() - 1; i >= 0; i--) {
		if (Int[i] > compareInt.Int[i]) return false;
		if (Int[i] < compareInt.Int[i]) return true;
	}
	return false; // ==
}

bool Integer::operator>=(Integer compareInt) {
	if ((*this) < compareInt) return false;
	return true;
}

bool Integer::operator<=(Integer compareInt) {
	if ((*this) > compareInt) return false;
	return true;
}

bool Integer::operator==(Integer compareInt) {
	(*this).simplefy();
	compareInt.simplefy();
	if (Int.size() == 1 && compareInt.Int.size() == 1 && Int[0] == 0 && compareInt.Int[0] == 0) return true;
	if (flag != compareInt.flag) return false;
	if (Int.size() != compareInt.Int.size()) return false;

	for (int i = Int.size() - 1; i >= 0; i--) {
		if (Int[i] != compareInt.Int[i]) return false;
	}

	return true; // ==
}

bool Integer::operator!=(Integer compareInt) {
	if (*this == compareInt) return false;
	return true;
}

Integer& Integer::operator=(Integer& assignInt) {
	assignInt.simplefy();
	flag = assignInt.flag;
	Int = assignInt.Int;
	return *this;
}

Integer& Integer::operator=(Integer&& assignInt) {
	assignInt.simplefy();
	flag = assignInt.flag;
	Int = assignInt.Int;
	return *this;
}

Integer& Integer::operator+=(Integer plusInt) {
	(*this) = (*this) + plusInt;
	return *this;
}

Integer& Integer::operator-=(Integer diffInt) {
	(*this) = (*this) - diffInt;
	return *this;
}

Integer& Integer::operator*=(Integer multiInt) {
	(*this) = (*this) * multiInt;
	return *this;
}

Integer& Integer::operator/=(Integer divInt) {
	(*this) = (*this) / divInt;
	return *this;
}

Integer& Integer::operator%=(Integer mod) {
	(*this) = (*this) % mod;
	return *this;
}

Integer Integer::factorial(Integer fac) {
	if (fac == Integer("0"))return Integer("1");
	Integer one("1");
	for (Integer i = fac - one; i > one; i -= one) {
		fac *= i;
	}
	return fac.simplefy();
}

Integer Integer::power(Integer lower, Integer upper) {
	if (upper.flag == -1) {
		lower.flag = 1;
		lower.Int.clear();
		lower.Int.push_back(0);
		return lower.simplefy();
	}
	Integer one("1");
	Integer multi = lower;
	for (Integer count = upper; count > one; count -= one) {
		lower *= multi;
	}
	return lower.simplefy();
}

Integer& Integer::simplefy() {
	for (int i = Int.size() - 1; i > 0; i--) {
		if (Int[i] == 0)Int.erase(Int.begin() + i);
		else break;
	}
	return *this;
}

//integer input
istream& operator>>(istream& in, Integer& to)
{
	string A;
	in >> A;
	to = Integer(A).simplefy();
	return in;
}


//integer output
ostream& operator<<(ostream& out, Integer to)
{
	to.simplefy();
	if (to.flag == -1)
		out << '-';
	int j = (to.Int.size() - 1) % 3 + 1;
	for (int i = to.Int.size() - 1; i >= 0; i--)
	{
		if (i != to.Int.size() - 1)
		{
			while (j == 0)
			{
				out << ',';
				j = 3;
			}		
		}
		
		out << to.Int[i];
		j--;
	}
	return out;
}

bool Integer::test() {
	bool test_pass = true;

	// test constructors
	Integer t;
	Integer a("999999999999999999999999999999999999999999999999999999999999999999999999999999999"),
		b("333333333333333333333333333333333333333333333333333333333333333333333333333333333");
	Integer d = a;
	t = Integer("3");

	d += d;
	if (d == a) {
		cout << "copy fail" << endl;
		test_pass = false;
	}
	d = a;

	// test compare
	if (!(a > b)) {
		cout << "> fail" << endl;
		test_pass = false;
	}
	if (!(b < a)) {
		cout << "< fail" << endl;
		test_pass = false;
	}
	if (!(d == a && Integer("0") == Integer("-0"))) {
		cout << "== fail" << endl;
		test_pass = false;
	}
	if (!(a >= b)) {
		cout << ">= fail" << endl;
		test_pass = false;
	}
	if (!(b <= a)) {
		cout << "<= fail" << endl;
		test_pass = false;
	}
	if (!(a != b)) {
		cout << "!= fail" << endl;
		test_pass = false;
	}


	// test assign operator
	d = Integer("10000");
	t = d;
	if (!(t == Integer("10000"))) {
		cout << "= fail" << endl;
		test_pass = false;
	}


	// test operators
	if ((a + b) != Integer("1333333333333333333333333333333333333333333333333333333333333333333333333333333332")) {
		cout << "a + b fail" << endl;
		test_pass = false;
	}
	if (!((a - b) == Integer("666666666666666666666666666666666666666666666666666666666666666666666666666666666") &&
		Integer("100000000000000000000000000000000000000000000000000000000000000000000000000000")
		- Integer("9") == Integer("99999999999999999999999999999999999999999999999999999999999999999999999999991"))) {
		cout << "a - b fail" << endl;
		test_pass = false;
	}
	if ((a * b) != Integer("333333333333333333333333333333333333333333333333333333333333333333333333333333332666666666666666666666666666666666666666666666666666666666666666666666666666666667")) {
		cout << "a * b fail" << endl;
		test_pass = false;
	}
	if (!(a / b == Integer("3") &&
		Integer("5") / Integer("2") == Integer("2") &&
		Integer("-300") / Integer("12") == Integer("-25"))) {
		cout << "a / b fail" << endl;
		test_pass = false;
	}

	// test factorial
	Integer f("5");
	Integer ffac("120");
	Integer fac = factorial(f);
	if (fac != ffac) {
		cout << "factorial 5! fail" << endl;
		test_pass = false;
	}

	//test - operator
	d = -a;
	if (d != Integer("-999999999999999999999999999999999999999999999999999999999999999999999999999999999")) {
		cout << "- fail" << endl;
		test_pass = false;
	}
	d = -d;
	if (d != Integer("999999999999999999999999999999999999999999999999999999999999999999999999999999999")) {
		cout << "- fail" << endl;
		test_pass = false;
	}

	// test power
	Integer p("2");
	Integer pp("10");
	if (power(p, pp)!= Integer("1024")) {
		cout << "power fail" << endl;
		test_pass = false;
	}

	//test %
	if (p % pp != Integer("2")) {
		cout << "% fail" << endl;
		test_pass = false;
	}

	return test_pass;
}
