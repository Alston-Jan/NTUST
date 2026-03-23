#include <iostream>
#include <iomanip>
#include "Decimal.h"
#include "Calculator.h"

using std::cout;
using std::endl;

Decimal::Decimal() {
	sign = 1;
	numerator = Integer("0");
	denominator = Integer("1");
	power_numerator = Integer("1");
	power_denominator = Integer("1");
}

Decimal::Decimal(string s) {
	if (!Calculator::is_num(s)) {
		Number r = Calculator::evaluate(s);
		if (r.type == Number::INTEGER)*this = r.integer;
		else *this = r.decimal;
	}
	else
	{
		sign = 1;
		if (s[0] == '-') {
			sign = -1;
			s = s.substr(1, s.size() - 1);
		}
		if (s[0] == '+') {
			sign = 1;
			s = s.substr(1, s.size() - 1);
		}

		denominator = Integer("1");
		numerator.Int.clear();
		bool is_point = false;

		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == '.')is_point = true;
			else {
				numerator.Int.insert(numerator.Int.begin(), s[i] - '0');
				if (is_point)denominator.Int.insert(denominator.Int.begin(), 0);
			}
		}

		power_numerator = Integer("1");
		power_denominator = Integer("1");
		simplefy();
	}
}

Decimal::Decimal(Decimal& from) {
	sign = from.sign;
	numerator = from.numerator;
	denominator = from.denominator;
	power_numerator = from.power_numerator;
	power_denominator = from.power_denominator;
	simplefy();
}

Decimal::Decimal(Decimal&& from) {
	sign = from.sign;
	numerator = from.numerator;
	denominator = from.denominator;
	power_numerator = from.power_numerator;
	power_denominator = from.power_denominator;
	simplefy();
}

Decimal::Decimal(Integer& from) {
	sign = from.flag;
	from.flag = 1;
	numerator = from;
	denominator = Integer("1");
	power_numerator = Integer("1");
	power_denominator = Integer("1");
}

Decimal::Decimal(Integer&& from) {
	sign = from.flag;
	from.flag = 1;
	numerator = from;
	denominator = Integer("1");
	power_numerator = Integer("1");
	power_denominator = Integer("1");
}

Decimal Decimal::operator+(Decimal plusDec) {
	if (sign == 1 && plusDec.sign == -1) {
		plusDec.sign = 1;
		return (*this) - plusDec;
	}
	else if (sign == -1 && plusDec.sign == 1) {
		Decimal a = (*this);
		a.sign = 1;
		return plusDec - a;
	}
	else if (sign == -1 && plusDec.sign == -1) {
		Decimal a = (*this);
		a.sign = 1;
		plusDec.sign = 1;
		a += plusDec;
		a.sign = -1;
		return a.simplefy();
	}
	else {
		Decimal a = (*this);
		if (a.power_denominator == plusDec.power_denominator &&
			a.power_numerator == plusDec.power_denominator) {

			if (a.denominator == plusDec.denominator) {
				a.numerator += plusDec.numerator;
			}
			else {
				a.numerator *= plusDec.denominator;
				a.numerator += (plusDec.numerator * a.denominator);
				a.denominator *= plusDec.denominator;
			}
			return a.simplefy();
		}
		else {
			// power != power
		}
	}
}

Decimal Decimal::operator-(Decimal diffDec) {
	if (sign == 1 && diffDec.sign == -1) {
		diffDec.sign = 1;
		return (*this) + diffDec;
	}
	else if (sign == -1 && diffDec.sign == -1) {
		Decimal a = (*this);
		a.sign = 1;
		diffDec.sign = 1;
		a -= diffDec;
		a.sign = -1;
		return a.simplefy();
	}
	else if (sign == -1 && diffDec.sign == 1) {
		Decimal a = (*this);
		a.sign = 1;
		a += diffDec;
		a.sign = -1;
		return a.simplefy();
	}
	else if ((*this) < diffDec) {
		diffDec -= (*this);
		diffDec.sign *= -1;
		return diffDec.simplefy();
	}
	else {
		Decimal a = (*this);
		if (a.denominator == diffDec.denominator) {
			a.numerator -= diffDec.numerator;
		}
		else {
			a.numerator *= diffDec.denominator;
			a.numerator -= (diffDec.numerator * (*this).denominator);
			a.denominator *= diffDec.denominator;
		}
		a.simplefy();
		return a;
	}
}

Decimal Decimal::operator*(Decimal multiDec) {
	multiDec.sign *= (*this).sign;
	multiDec.numerator *= (*this).numerator;
	multiDec.denominator *= (*this).denominator;
	return multiDec.simplefy();
}

Decimal Decimal::operator/(Decimal divDec) {
	Decimal result;
	result.sign = (*this).sign * divDec.sign;
	result.numerator = (*this).numerator * divDec.denominator;
	result.denominator = (*this).denominator * divDec.numerator;
	
	return result.simplefy();
}

Decimal& Decimal::operator+=(Decimal plusDec) {
	(*this) = (*this) + plusDec;
	return (*this);
}

Decimal& Decimal::operator-=(Decimal diffDec) {
	(*this) = (*this) - diffDec;
	return (*this);
}

Decimal& Decimal::operator*=(Decimal multiDec) {
	(*this) = (*this) * multiDec;
	return (*this);
}

Decimal& Decimal::operator/=(Decimal divDec) {
	(*this) = (*this) / divDec;
	return (*this);
}

Decimal Decimal::operator-() {
	Decimal a = (*this);
	a.sign *= -1;
	return a;
}

Decimal& Decimal::operator=(Decimal& assignDec) {
	assignDec.simplefy();
	sign = assignDec.sign;
	numerator = assignDec.numerator;
	denominator = assignDec.denominator;
	power_numerator = assignDec.power_denominator;
	power_denominator = assignDec.power_denominator;
	return *this;
}

Decimal& Decimal::operator=(Decimal&& assignDec) {
	assignDec.simplefy();
	sign = assignDec.sign;
	numerator = assignDec.numerator;
	denominator = assignDec.denominator;
	power_numerator = assignDec.power_denominator;
	power_denominator = assignDec.power_denominator;
	return *this;
}

bool Decimal::operator>(Decimal compareDec) {
	if ((*this).numerator * compareDec.denominator > compareDec.numerator * (*this).denominator) return true;
	return false;
}

bool Decimal::operator<(Decimal compareDec) {
	if ((*this).numerator * compareDec.denominator < compareDec.numerator * (*this).denominator) return true;
	return false;
}

bool Decimal::operator>=(Decimal compareDec) {
	if ((*this).numerator * compareDec.denominator < compareDec.numerator * (*this).denominator) return false;
	return true;
}

bool Decimal::operator<=(Decimal compareDec) {
	if ((*this).numerator * compareDec.denominator > compareDec.numerator * (*this).denominator) return false;
	return true;
}

bool Decimal::operator==(Decimal compareDec) {
	Decimal a = (*this);
	a.simplefy();
	compareDec.simplefy();
	if (numerator.Int.size() == 1 && numerator.Int[0] == 0 && compareDec.numerator.Int.size() == 1 && compareDec.numerator.Int[0]) return true;
	if (sign == compareDec.sign && a.numerator == compareDec.numerator && a.denominator == compareDec.denominator) return true;
	return false;
}

bool Decimal::operator!=(Decimal compareDec) {
	if ((*this) == compareDec) return false;
	return true;
}

istream& operator>>(istream& is, Decimal& to) {
	string A;
	is >> A;
	to = Decimal(A);
	return is;
}

ostream& operator<<(ostream& os, Decimal from) {
	if (from.sign == -1)
		os << '-';

	os << from.numerator / from.denominator << ".";

	from.numerator %= from.denominator;

	for (int i = 0; i < 100; i++) {
		if (i % 3 == 0 && i)os << ",";
		from.numerator *= Integer("10");
		os << from.numerator / from.denominator;
		from.numerator %= from.denominator;
	}


	return os; 
}

bool Decimal::is_int() {
	Integer zero("0");
	if (numerator % denominator == zero) return true;
	return false;
}

Decimal& Decimal::simplefy() { // 約分
	numerator.simplefy();
	denominator.simplefy();
	if (numerator == Integer("0")) {
		sign = 1;
		numerator = Integer("0");
		denominator = Integer("1");
		power_numerator = Integer("1");
		power_denominator = Integer("1");
	}
	else {
		Integer a = gcd(numerator, denominator);
		numerator /= a;
		denominator /= a;
		// simplefy power
	}
	return *this;
}

Integer Decimal::to_integer() {
	Integer r = numerator / denominator;
	r.flag = sign;
	return r.simplefy();
}

Integer Decimal::gcd(Integer a, Integer b) {
	a.flag = 1;
	b.flag = 1;
	while (a != Integer("0") && b != Integer("1"))
	{
		if (a >= b) a %= b;
		else
		{
			Integer t = a;
			a = b;
			b = t;
		}
	}
	return b;
}

Decimal Decimal::factorial(Decimal fac) {
	bool check = fac.is_int();
	if (check) {
		fac.simplefy();
		fac.numerator = Integer::factorial(fac.numerator);
	}
	else {
		cout << "factorial error" << endl;
	}
	return fac.simplefy();
}



Decimal Decimal::power(Decimal lower, Decimal upper) { // upper.denominator = 1 or 2
	Integer one("1");
	Integer multinum = lower.numerator;
	Integer multiden = lower.denominator;
	if (upper.is_int()) {
		for (Integer count = upper.numerator; count > one; count -= one) {
			lower.numerator *= multinum;
			lower.denominator *= multiden;
		}
		if (upper.sign == -1) {
			Integer temp = lower.numerator;
			lower.numerator = lower.denominator;
			lower.denominator = temp;
		}
		return lower;
	}
	else {
		// 開根號
	}
}

bool Decimal::test() { 
	bool test_pass = true;

	//test gcd
	if (!(gcd(Integer("1776"), Integer("37")) == Integer("37") &&
		gcd(Integer("300"), Integer("270")) == Integer("30"))) {
		cout << "gcd fail" << endl;
		test_pass = false;
	}
	// test constructors
	Decimal t;


	Decimal a("999.999999999999999999999999999999999999999999999999999999999999999999999999999999"), 
		b("333.333333333333333333333333333333333333333333333333333333333333333333333333333333");
	
	Decimal d = a;
	t = Decimal("3.333");

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
	if (!(d == a && Decimal("0.0") == Integer("-0.0"))) {
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
	
	t = Decimal("0.0");
	if (!(t == Decimal("0"))) {
		cout << "0 fail" << endl;
		test_pass = false;
	}
	t = Decimal("-0.0");
	if (!(t == Decimal("0"))) {
		cout << "-0 == 0 fail" << endl;
		test_pass = false;
	}

	//test - operator
	d = -a;
	if (d != Decimal("-999.999999999999999999999999999999999999999999999999999999999999999999999999999999")) {
		cout << "- fail" << endl;
		test_pass = false;
	}
	d = -d;
	if (d != Decimal("999.999999999999999999999999999999999999999999999999999999999999999999999999999999")) {
		cout << "- fail" << endl;
		test_pass = false;
	}


	// test assign operator
	d = Decimal("-100.0000001");
	t = d;
	if (!(t == Decimal("-100.0000001"))) {
		cout << "= fail" << endl;
		test_pass = false;
	}
	
	// test operators

	a = Decimal("999.999999999999999999999999999999999999999999999999999999999999999999999999999999");
	b = Decimal("333.333333333333333333333333333333333333333333333333333333333333333333333333333333");

	Decimal i("1333.333333333333333333333333333333333333333333333333333333333333333333333333333332");
	if ((a + b) != i) {
		cout << "a + b fail" << endl;
		test_pass = false;
	}

	i = Decimal("666.666666666666666666666666666666666666666666666666666666666666666666666666666666");
	Decimal j("9000.00000000000000000000000000000000000000000000000000000000000000000000000001");
	if (!((a - b) == i &&
		Decimal("9000.00000000000000000000000000000000000000000000000000000000000000000000000099")
		- Decimal ("0.00000000000000000000000000000000000000000000000000000000000000000000000098") == j)) {
		cout << "a - b fail" << endl;
		test_pass = false;
	}

	
	Decimal x("333333.333333333333333333333333333333333333333333333333333333333333333333333333332666666666666666666666666666666666666666666666666666666666666666666666666666666667");

	j = a * b;
	if (j != x) {
		cout << "a * b fail" << endl;
		test_pass = false;
	}
	
	Decimal y("3.0");
	Decimal k("24.24"), l("0.12");
	if (!(a / b == y &&
		k / l == Decimal("202") &&
		Decimal("-9999999999.9999999999") / Decimal("3333333333.3333333333") == Decimal("-3"))) {
		cout << "a / b fail" << endl;
		test_pass = false;
	}

	if (!(Decimal("1") / Decimal("3") * Decimal("3") == Decimal("1"))) {
		cout << "1 / 3 * 3 fail" << endl;
		test_pass = false;
	}

	//test is_int

	if (!Decimal("3.0").is_int()) {
		cout << "is_int() fail" << endl;
		test_pass = false;
	}
	
	// test factorial
	Decimal f("5");
	//Decimal f_err("5.2");
	Decimal ffac("120");
	//Decimal err_ffac("184.50432"); // 5.2*4.2*3.2*2.2*1.2
	Decimal fac = factorial(f);
	//Decimal err_fac = factorial(f_err);
	if (fac != ffac) {
		cout << "factorial 5! fail" << endl;
		test_pass = false;
	}
	//if (fac == err_fac) {
	//	cout << "factorial 5.2! fail" << endl;
	//	test_pass = false;
	//}

	/*
	// test power
	Decimal p("2.5");
	Decimal pp("4");
	if (power(p, pp) != Decimal("39.0625")) {
		cout << "power fail" << endl;
		test_pass = false;
	}
	p = Decimal("10");
	pp = Decimal("-5");
	if (power(p, pp) != Decimal("0.00001")) {
		cout << "power fail" << endl;
		test_pass = false;
	}

	//test 

	*/
	
	
	return test_pass;
}