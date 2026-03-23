#include "Fraction.h"

void Fraction::setNumerator(int nu)
{
	Fraction::numerator = nu;
}

void Fraction::setDenominator(int de)
{
	Fraction::denominator = de;
}

void Fraction::getDouble()
{
	double out = 0;
	out = double(numerator) / double(denominator);
	if (out==(int)out)
	{
		cout << (int)out << endl;
	}
	else 
	{
		cout << fixed << setprecision(6) << out << endl;
	}
}

void Fraction::outputReducedFraction()
{
	int a,b,tamp,out = 0;
	a = numerator;
	b = denominator;
	
	while (b != 0)
	{
		tamp = b;
		b = a % b;
		a = tamp;
	}
	if (numerator / a != denominator / a )
	{
		if (denominator == a)
		{
			cout << numerator / denominator << endl;
		}
		else
		{
			cout << numerator / a << "/" << denominator / a << endl;
		}
	}
	else
	{
		cout << numerator / denominator << endl;
	}
}



