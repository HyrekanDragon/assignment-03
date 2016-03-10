/* ----------------------------------------------------------------------------
* Copyright &copy; 2016 Alex Chuoy <HyrekanDragon@yahoo.com>
* Released under the [MIT License] (http://opensource.org/licenses/MIT)
* ------------------------------------------------------------------------- */

/**
* Functions for testing recursion.
*/

#include "Recursion.h"
#include <iostream>
#include <exception>
#include <string>

using std::cout;
using std::endl;

int gcd(int a, int b)
{
	//Normalization of data
	if (a < 0) a *= -1;
	if (b < 0) b *= -1;

	//Exception
	if (a == 0 && b == 0) throw 'a';

	//Base Case
	if (a == 0) return b;
	if (b == 0) return a;

	//Recursion
	if (a > b) return gcd(a - b, b);
	else	   return gcd(a, b - a);
}

int fib(int n)
{
	//Exception
	if (n <= 0) throw 'b';

	//Base Case
	if (n == 1 || n == 2) return 1;

	//Recursion
	return fib(n - 1) + fib(n - 2);
}

int pow(int a, int b)
{
	//Exception
	if (b < 0) throw 'c';
	if (a == 0 && b == 0) throw 'c';

	//Base Case
	if (b == 0) return 1;

	//Recursion
	return a * pow(a, b - 1);
}

int tri(int n)
{
	//Exception
	if (n < 1) throw 'd';

	//Base Case
	if (n == 1) return 1;

	//Recursion
	return n + tri(n - 1);
}

string int_to_roman(int n)
{
	int Arabic[13] = { 1,4,5,9,10,40,50,90,100,400,500,900,1000 };
	string Roman[13] = { "I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M" };
	//Exception

	if (n <= 0 || n > 3999) throw 'e';

	//BaseCase
	for (int i = 12; i >= 0; i--)
	{

		if (n == Arabic[i])
		return Roman[i];
	}
	//Recursive Case
	for (int j = 12; j >= 0; j--)
	{
		if (n >= Arabic[j])
		{
			return Roman[j] + int_to_roman(n - Arabic[j]);
		}
	}
}

string int_to_words(int n)
{
	int c = 0;
	int number[31] = { 0,1,2,3,4,5,6,7,8,9,10, 
		                11,12,13,14,15,16,17,18,19,
						20,30,40,50,60,70,80,90,
						100,1000,1000000 };
	string word[31] = { "zero ","one ","two ","three ","four ","five ",
					  "six ","seven ","eight ","nine ","ten ","eleven ",
					  "twelve ","thirteen ","fourteen ","fifteen ","sixteen ",
					  "seventeen ","eighteen ","nineteen ","twenty ","thirty ",
					  "forty ","fifty ","sixty ","seventy ","eighty ","ninety ",
					  "hundred ","thousand ","million " };
	//Exception
	if (n > 1000000000 || n < -1000000000) throw 'f';

	//Normalize
	if (n < 0) return "negative " + int_to_words(-n);

	//Base Case
	for (int i = 27; i >= 0; i--)
	{
		if (n == number[i]) return word[i];
	}

	//Recursion
	for (int i = 30; i >= 0; i--)
	{
		if (n == 0)
		{
			return " ";
		}

		if (n >= number[i])
		{
			if (number[i] < 100)
			{
				return word[i] + int_to_words(n - number[i]);
			}
			else if (number[i] >= 100)
			{
				while (n >= number[i])
				{
					n -= number[i];
					c++;
				}
				cout << counter(c) + word[i];
				if (n == 0)
				{
					return " ";
				}
				return int_to_words(n);
			}
		}
	}	
}

string counter(int n)
{
	int number[36] = { 1,2,3,4,5,6,7,8,9,10,
						11,12,13,14,15,16,17,18,19,
						20,30,40,50,60,70,80,90,
						100, 200, 300, 400 , 500, 600, 700,
						800, 900 };
	string word[36] = {"one ","two ","three ","four ","five ",
						"six ","seven ","eight ","nine ","ten ","eleven ",
						"twelve ","thirteen ","fourteen ","fifteen ","sixteen ",
						"seventeen ","eighteen ","nineteen ","twenty ","thirty ",
						"forty ","fifty ","sixty ","seventy ","eighty ","ninety ",
						"one hundred ", "two hundred ","three hundred ","four hundred ",
						"five hundred ", "six hundred ", "seven hundred ", "eight hundred ",
						"nine hundred "};

	//Base Case
	for (int i = 35; i >= 0; i--)
	{
		if (n == number[i]) return word[i];
	}
	//Recursive Case
	for (int i = 35; i >= 0; i--)
	{
		if (n >= number[i])
		{
			return word[i] + counter(n - number[i]);
		}
	}
}

string magic_number(int n)
{
	//Exception
	if (n < 0) throw 'g';

	//Base Case
	if (n == 4)
		return "4 is the magic number!";

	//Recursion 
	int a = int_to_words(n).length() - 1;
	cout << n << " is " << a << endl;
	return magic_number(a);
}
