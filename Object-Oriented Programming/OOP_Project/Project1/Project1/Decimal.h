#pragma once
#include "Integer.h"

class Decimal : public NumberBase {
public:

	Integer denominator, numerator, power_denominator, power_numerator;
	int sign;

	Decimal();
	Decimal(string);
	Decimal(Decimal&);
	Decimal(Decimal&&);
	Decimal(Integer&);
	Decimal(Integer&&);

	Decimal operator+(Decimal plusDec);
	Decimal operator-(Decimal diffDec);
	Decimal operator*(Decimal multiDec);
	Decimal operator/(Decimal divDec);
	Decimal operator-();
	Decimal& operator+=(Decimal plusDec);
	Decimal& operator-=(Decimal diffDec);
	Decimal& operator*=(Decimal multiDec);
	Decimal& operator/=(Decimal divDec);
	Decimal& operator=(Decimal& assignDec);
	Decimal& operator=(Decimal&& assignDec);
	bool operator>(Decimal compareDec);
	bool operator<(Decimal compareDec);
	bool operator>=(Decimal compareDec);
	bool operator<=(Decimal compareDec);
	bool operator==(Decimal compareDec);
	bool operator!=(Decimal compareDec);
	friend istream& operator>>(istream& is, Decimal& to);
	friend ostream& operator<<(ostream& os, Decimal from);

	friend Decimal operator+(Integer i, Decimal d) { return d + i; }
	friend Decimal operator-(Integer i, Decimal d) { return Decimal(i) - d; }
	friend Decimal operator*(Integer i, Decimal d) { return d * i; }
	friend Decimal operator/(Integer i, Decimal d) { return Decimal(i) / d; }

	
	bool is_int();
	Decimal& simplefy(); 
	Integer to_integer();

	static Decimal factorial(Decimal);
	static Decimal power(Decimal, Decimal);
	static Integer gcd(Integer a, Integer b);

	static bool test();
};
