/* ----------------------------------------------------------------------------
* Copyright &copy; 2016 Alex Chuoy <HyrekanDragon@yahoo.com>
* Released under the [MIT License] (http://opensource.org/licenses/MIT)
* ------------------------------------------------------------------------- */

/**
* Calls functions from other header files in order to test the following
* Excepctions, Templates, Standard Template Library
* Iteration Functions vs Recursion Functions
*/

#include "Testing.h"
#include "Recursion.h"
#include "Iteration.h"
#include <iostream>
#include <iomanip>


using std::cout;
using std::endl;
using std::setw;
using std::right;


int main()
{
	test_exceptions();
	test_templates();
	test_stl();
	
	cout << "Testing Recursion Functions\n\n";
	cout << "The GCD of 1 and 2 is " << gcd(1, 2) << endl;
	cout << "The GCD of 100 and 10 is " << gcd(100, 10) << endl;;
	cout << "The GCD of 40 and 16 is " << gcd(40, 16) << endl << endl;

	cout << "The first 15 Fibonacci numbers are " << endl;
	for (int i = 1; i <= 15; i++)
	{
		cout << setw(2) << right << fib(i) << " ";
	}
	cout << endl << endl;

	cout << "2 to the 5th power is " << pow(2, 5) << endl;
	cout << "3 to the 4rth power is " << pow(3, 4) << endl << endl;

	cout << "The first 10 triangle numbers are " << endl;
	for (int j = 1; j <= 10; j++)
	{
		cout << setw(2) << right << tri(j) << " ";
	}

	cout << endl << endl;
	
	int counter = 0;
	cout << "The first 100 Roman Numerals are " << endl;
	for (int k = 1; k <= 100; k++)
	{
		cout << int_to_roman(k) << " ";
		counter++;

		if (counter == 20)
		{
			cout << endl;
			counter = 0;
		}
	}
	cout << endl << endl;
	
	cout << "Converting numbers into words\n";
	for (int k = -5; k < 5; k++)
	{
		cout << int_to_words(k) << endl;
	}
	cout << endl;
	for (int l = 100000000; l < 1000000000; l += 100000000)
	{
		cout << int_to_words(l) << endl;
	}
	cout << endl;

	cout << magic_number(13) << endl << endl;
	cout << magic_number(20) << endl << endl;

	cout << "Done testing Recursion Functions\n\n";

	cout << "Starting Iteraton Function\n\n";

	cout << "The GCD of 1 and 2 is " << gcd_iter(1, 2) << endl;
	cout << "The GCD of 100 and 10 is " << gcd_iter(100, 10) << endl;;
	cout << "The GCD of 40 and 16 is " << gcd_iter(40, 16) << endl << endl;

	cout << "The first 15 Fibonacci numbers are " << endl;
	for (int i = 1; i <= 15; i++)
	{
		cout << setw(2) << right << fib_iter(i) << " ";
	}
	cout << endl << endl;

	cout << "2 to the 5th power is " << pow_iter(2, 5) << endl;
	cout << "3 to the 4rth power is " << pow_iter(3, 4) << endl << endl;

	cout << "The first 10 triangle numbers are " << endl;
	for (int j = 1; j <= 10; j++)
	{
		cout << setw(2) << right << tri_iter(j) << " ";
	}

	cout << endl << endl;

	cout << "Done testing Iteration Functions\n\n";

	system("pause");

	return 0;
}
