
class PrimeNumber {
public:
	int value;
	int get()
	{
		return value;
	}
	PrimeNumber()
	{
		value = 1;
	}
	PrimeNumber(int _value)
	{
		value = _value;
	}

	PrimeNumber& operator++()
	{
		value++;
		while (1)
		{
			int counter = 0;
			for (int i = 1; i <= value; i++)
			{
				if (value % i == 0)
				{
					counter++;
				}
			}
			if (counter == 2)
			{
				return *this;
			}
			else
				value++;
		}
	}
	PrimeNumber operator++(int)
	{
		PrimeNumber a = *this;
		++*this;
		return a;
	}
	PrimeNumber& operator--() 
	{
		if (value > 2)
		{
			value--;
			while (1)
			{
				int counter = 0;
				for (int i = 1; i <= value; i++)
				{
					if (value % i == 0)
					{
						counter++;
					}
				}
				if (counter == 2)
				{
					return *this;
				}
				else
					value--;
			}
		}
		else
		{
			value = 1;
			return *this;
		}
	}
	PrimeNumber operator--(int)
	{
		PrimeNumber a = *this;
		--* this;
		return a;
	}
};