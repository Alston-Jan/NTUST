#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include "NumberObject.h"

struct dvide_zero_err : public std::exception {
	const char* what() const throw () { return "/ 0"; }
};

struct factorial_error :public std::exception {};

class Calculator
{
public:
	static int find_closing_parenthesis(string s, int open_index = 0) {
		int c = 0;
		for (int i = open_index + 1; i < s.size(); i++) {
			if (s[i] == '(')c++;
			else if (s[i] == ')') {
				if (c)c--;
				else return i;
			}
		}
		return -1;
	}

	static vector<string> divide(string raw) {
		for (int i = 0; i < raw.size(); i++)if (raw[i] == ' ')raw.erase(i,1);
		if (!raw.size())return vector<string>();
		bool is_operatee = true;
		vector<string> arg_list = {};
		for (int i = 0; i < raw.size();) {
			if (raw[i] == '(') {
				if (!is_operatee)arg_list.push_back("*");
				arg_list.push_back(
					raw.substr(
						i, 
						find_closing_parenthesis(
							raw, 
							i)
						- i + 1
					)
				);
				is_operatee = false;
				i = find_closing_parenthesis(raw, i) + 1;
			}
			else {
				if (is_operatee) {
					if (raw.size() - i - 1 > 7 &&
						(raw.substr(i, 5) == "Power" || raw.substr(i, 5) == "power")) {
						int c = 0,k;
						for (int j = i+6; j < raw.size(); j++) {
							if (raw[j] == '(')c++;
							else if (raw[j] == ',' && c == 0) {
								k = j;
							}
							else if (raw[j] == ')') {
								if (c)c--;
								else {
									arg_list.push_back(
										"((" + raw.substr(i + 6, k - (i + 6)) + ")^(" + raw.substr(k + 1, j - k -1) + "))"
									);
									i = j + 1;
									break;
								};
							}
						}
					}
					else if (raw.size() - i - 1 > 11 &&
						(raw.substr(i, 9) == "Factorial" || raw.substr(i, 9) == "Factorial")) {
						arg_list.push_back("(" + raw.substr(i + 9,
							find_closing_parenthesis(raw, i + 9) - (i + 9) + 1) + "!)");
						i = find_closing_parenthesis(raw, i + 9) + 1;
					}
					else {
						int sign = 1;
						while (raw[i] == '+' || raw[i] == '-') {
							if (raw[i] == '-')sign *= -1;
							i++;
						}
						if (raw[i] == '(') {
							arg_list.push_back("-1");
						}
						else
						{
							int c = 0;
							while ((raw[i + c] >= '0' && raw[i + c] <= '9') || raw[i + c] == '.')
							{
								c++;
							}
							arg_list.push_back((sign == -1 ? "-" : "") + raw.substr(i, c));
							i += c;
						}
					}
					is_operatee = false;
				}
				else {
					if (raw[i] == '+' || raw[i] == '-' || raw[i] == '*' ||
						raw[i] == '/' || raw[i] == '^') {
						arg_list.push_back(string{ raw[i] });
						is_operatee = true;
					}
					else if (raw[i] == '!') {
						arg_list.push_back(string{ raw[i] });
					}
					i++;
				}
			}
		}
		if (arg_list.size() == 1 &&
			arg_list[0][0] == '(' &&
			arg_list[0][arg_list[0].size() - 1] == ')')
			return divide(arg_list[0].substr(1, arg_list[0].size() - 2));
		return arg_list;
	}
	
	static Number evaluate(std::string form) {

		if (is_integer(form))return Number(Integer(form));
		if (is_decimal(form))return Number(Decimal(form));

		vector<string> arg_list = divide(form);

		if (arg_list.size() == 1) return evaluate(arg_list[0]);
		
		for (int i = arg_list.size() - 1; i >= 0; i--) {
			if (arg_list[i] == "+" || arg_list[i] == "-") {
				string ls, rs;
				for (int j = 0; j < i; j++)ls += arg_list[j];
				for (int j = i + 1; j < arg_list.size(); j++)rs += arg_list[j];
				
				Number left = evaluate(ls), right = evaluate(rs);

				if (left.type == Number::DECIMAL && right.type == Number::INTEGER)
					right = Decimal(right.integer);
				if (right.type == Number::DECIMAL && left.type == Number::INTEGER)
					left = Decimal(left.integer);

				if (arg_list[i] == "+")return left + right;
				else return left - right;
			}
		}

		for (int i = arg_list.size() - 1; i >= 0; i--) {
			if (arg_list[i] == "*" || arg_list[i] == "/") {
				string ls, rs;
				for (int j = 0; j < i; j++)ls += arg_list[j];
				for (int j = i + 1; j < arg_list.size(); j++)rs += arg_list[j];

				Number left = evaluate(ls), right = evaluate(rs);

				if (left.type == Number::DECIMAL && right.type == Number::INTEGER)
					right = Decimal(right.integer);
				if (right.type == Number::DECIMAL && left.type == Number::INTEGER)
					left = Decimal(left.integer);

				if (arg_list[i] == "*")return left * right;
				else {
					if (right == Number(Integer("0")))throw dvide_zero_err();
					return left / right;
				}
			}
		}
		
		if (arg_list[arg_list.size() - 1] == "!") {
			string ls;
			for (int j = 0; j < arg_list.size() - 1; j++)ls += arg_list[j];

			Number left = evaluate(ls);

			if (left.type == Number::DECIMAL) {
				if (!(left.decimal.is_int() && left.decimal >= Decimal("0")))
					throw factorial_error();
				return Decimal::factorial(left.decimal);
			}
			else
			{
				if (!(left.integer >= Integer("0")))
					throw factorial_error();
				return Integer::factorial(left.integer);
			}
		}
	}

	static bool is_integer(string s) {
		if (s.empty())return false;
		if (!(s[0] == '+' || s[0] == '-' || (s[0] >= '0' && s[0] <= '9')))return false;
		if (s.size() == 1 && !(s[0] >= '0' && s[0] <= '9'))return false;
		for (int i = 1; i < s.size(); i++) {
			if (!(s[i] >= '0' && s[i] <= '9'))return false;
		}
		return true;
	}

	static bool is_decimal(string s) {
		if (s.empty())return false;
		if (!(s[0] == '+' || s[0] == '-' || (s[0] >= '0' && s[0] <= '9')))return false;
		if (s.size() == 1 && !(s[0] >= '0' && s[0] <= '9'))return false;

		bool dot_flag = false;
		for (int i = 1; i < s.size(); i++) {
			if (!((s[i] >= '0' && s[i] <= '9')||s[i]=='.'))return false;
			else if (s[i] == '.') {
				if (!dot_flag)dot_flag = true;
				else return false;
			}
		}
		return dot_flag;
	}

	static bool is_num(string s) {
		return is_integer(s) || is_decimal(s);
	}
};

