#include "Month.h"

Month::Month() 
{
	month = 1;
}

Month::Month(char first, char second, char third) 
{
	month = 1;
	switch (first)
	{
	case 'J':
		switch (second)
		{
		case 'a':
			month = 1;
			break;
		case 'u':
			switch (third)
			{
			case 'n':
				month = 6;
				break;
			case 'l':
				month = 7;
				break;
			default:
				break;
			}
		default:
			break;
		}
		break;
	case 'F':
		month = 2;
		break;
	case 'M':
		switch (third)
		{
		case 'r':
			month = 3;
			break;
		case 'y':
			month = 5;
			break;
		default:
			break;
		}
		break;
	case 'A':
		switch (second)
		{
		case 'p':
			month = 4;
			break;
		case 'u':
			month = 8;
			break;
		default:
			break;
		}
		break;
	case 'S':
		month = 9;
		break;
	case 'O':
		month = 10;
		break;
	case 'N':
		month = 11;
		break;
	case 'D':
		month = 12;
		break;
	default:
		month = 1;
		break;
	}
}

Month::Month(int monthInt) 
{
	if (monthInt < 1 || monthInt > 12)
	{
		month = 1;
	}
	else
	{
		month = monthInt;
	}
}

Month::~Month() 
{
	month = 1;
}

void Month::inputInt()
{
	int x = 0;
	cin >> x;
	if (x < 1 || x > 12)
	{
		month = 1;
	}
	else
	{
		month = x;
	}
}

void Month::inputStr()
{
	string input, s = "";
	for (int i = 0; i < 3; i++)
	{
		cin >> input;
		s += input;
	}

	if (s == "Jan")
	{
		month = 1;
	}else if (s == "Feb")
	{
		month = 2;
	}
	else if (s == "Mar")
	{
		month = 3;
	}
	else if (s == "Apr")
	{
		month = 4;
	}
	else if (s == "May")
	{
		month = 5;
	}
	else if (s == "Jun")
	{
		month = 6;
	}
	else if (s == "Jul")
	{
		month = 7;
	}
	else if (s == "Aug")
	{
		month = 8;
	}
	else if (s == "Sep")
	{
		month = 9;
	}
	else if (s == "Oct")
	{
		month = 10;
	}
	else if (s == "Nov")
	{
		month = 11;
	}
	else if (s == "Dec")
	{
		month = 12;
	}
	else
	{
		month = 1;
	}
}

void Month::outputInt() 
{
	cout << month;
}

void Month::outputStr() 
{
	switch (month)
	{
	case 1:
		cout << "Jan";
		break;
	case 2:
		cout << "Feb";
		break;
	case 3:
		cout << "Mar";
		break;
	case 4:
		cout << "Apr";
		break;
	case 5:
		cout << "May";
		break;
	case 6:
		cout << "Jun";
		break;
	case 7:
		cout << "Jul";
		break;
	case 8:
		cout << "Aug";
		break;
	case 9:
		cout << "Sep";
		break;
	case 10:
		cout << "Oct";
		break;
	case 11:
		cout << "Nov";
		break;
	case 12:
		cout << "Dec";
		break;
	}
}

Month Month::nextMonth() 
{
	if (month == 12)
	{
		return 1;
	}
	else
	{
		return month + 1;
	}
}
