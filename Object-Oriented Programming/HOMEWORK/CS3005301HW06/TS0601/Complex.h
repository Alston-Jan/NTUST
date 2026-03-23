#include <iostream>
#include <math.h>

using namespace std;

class Complex
{
public:
	double realValue, imaginaryValue;

	Complex()
	{
		realValue = 0;
		imaginaryValue = 0;
	}
	//~Complex();
	Complex(double r)
	{
		realValue = r;
		imaginaryValue = 0;
	}
	//~Complex(double r);
	Complex(double r, double i)
	{
		realValue = r;
		imaginaryValue = i;
	}
	//~Complex(double r, double i);

	double real()
	{
		return realValue;
	}
	double imag()
	{
		return imaginaryValue;
	}
	double norm()
	{
		return sqrt(pow(realValue, 2) + pow(imaginaryValue, 2));
	}
	friend double real(Complex c)
	{
		return c.realValue;
	}
	friend double imag(Complex c)
	{
		return c.imaginaryValue;
	}
	friend double norm(Complex c)
	{
		return sqrt(pow(c.realValue, 2) + pow(c.imaginaryValue, 2));
	}

	Complex operator+(Complex c)
	{
		Complex a;
		a.imaginaryValue=this->imaginaryValue + c.imaginaryValue;
		a.realValue=this->realValue + c.realValue;
		return a;
	}
	Complex operator-(Complex c)
	{
		Complex a;
		a.imaginaryValue = this->imaginaryValue - c.imaginaryValue;
		a.realValue = this->realValue - c.realValue;
		return a;
	}
	Complex operator*(Complex c)
	{
		Complex a;
		a.realValue = this->realValue * c.realValue - this->imaginaryValue * c.imaginaryValue;
		a.imaginaryValue = this->imaginaryValue * c.realValue + this->realValue * c.imaginaryValue;
		return a;
	}
	Complex operator/(Complex c)
	{
		Complex a;
		a.realValue = (this->realValue * c.realValue + this->imaginaryValue * c.imaginaryValue)/(pow(c.realValue,2)+ pow(c.imaginaryValue, 2));
		a.imaginaryValue = (this->imaginaryValue * c.realValue - this->realValue * c.imaginaryValue)/(pow(c.realValue, 2) + pow(c.imaginaryValue, 2));
		return a;
	}

	friend Complex operator+(double d, Complex c)
	{
		Complex a;
		a.realValue = d + c.realValue;
		a.imaginaryValue = c.imaginaryValue;
		return a;
	}
	friend Complex operator+(Complex c, double d)
	{
		Complex a;
		a.realValue = d + c.realValue;
		a.imaginaryValue = c.imaginaryValue;
		return a;
	}
	friend Complex operator-(double d, Complex c)
	{
		Complex a;
		a.realValue = d - c.realValue;
		a.imaginaryValue = c.imaginaryValue * -1;
		return a;
	}
	friend Complex operator-(Complex c, double d)
	{
		Complex a;
		a.realValue = c.realValue - d;
		a.imaginaryValue = c.imaginaryValue;
		return a;
	}
	friend Complex operator*(double d, Complex c)
	{
		Complex a(d);
		a = a * c;
		return a;
	}
	friend Complex operator*(Complex c, double d)
	{
		Complex a(d);
		a = a * c;
		return a;
	}
	friend Complex operator/(double d, Complex c)
	{
		Complex a,b(d);
		a = b / c;
		return a;
	}
	friend Complex operator/(Complex c, double d)
	{
		Complex a, b(d);
		a = c / b;
		return a;
	}

	friend bool operator==(Complex c1, Complex c2)
	{
		if (c1.imaginaryValue == c2.imaginaryValue && c1.realValue == c2.realValue)
		{
			return 1;
		}
		return 0;
	}
	friend ostream& operator<<(ostream& strm, const Complex& c)
	{
		strm << c.realValue << " + " << c.imaginaryValue << "*i";
		return strm;
	}
	friend istream& operator>>(istream &strm,Complex &c)
	{
		char a;
		strm >> a >> a >> c.realValue >> a >> c.imaginaryValue >> a >> a;
		return strm;
	}
};