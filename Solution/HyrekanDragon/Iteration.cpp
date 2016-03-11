/* ----------------------------------------------------------------------------
* Copyright &copy; 2016 Alex Chuoy <HyrekanDragon@yahoo.com>
* Released under the [MIT License] (http://opensource.org/licenses/MIT)
* ------------------------------------------------------------------------- */

/**
* Functions for rewriting recursion functions into iteration functions.
*/


#include "Iteration.h"
#include <iostream>
#include <exception>
#include <string>

using std::cout;
using std::endl;

int gcd_iter(int a, int b)
{
	//Normalization of data
	if (a < 0) a *= -1;
	if (b < 0) b *= -1;

	//Exception
	if (a == 0 && b == 0) throw 'a';

	//Iteration
	while (a != 0 && b != 0) //if a or b is 0 move on
	{
		if (a > b) a -= b;
		else	   b -= a;
	}

	if (a == 0) return b;
	if (b == 0) return a;
}

int fib_iter(int n)
{
	//Exception
	if (n <= 0) throw 'b';

	//Iteration
	if (n == 1 || n == 2) return 1;

	int a = 1, b = 1, temp;

	for (int i = 3; i <= n; i++)
	{
		temp = b;
		b += a;
		a = temp;
	}

	return b;
}

int pow_iter(int a, int b)
{
	int pow = 1;

	//Exception
	if (b < 0) throw 'c';
	if (a == 0 && b == 0) throw 'c';
	
	//Iteration
	for (int i = 0; i < b ; i++)
	{
		pow *= a;
	}

	return pow;
}

int tri_iter(int n)
{
	int sum = 0;

	//Exception
	if (n < 1) throw 'd';

	//Iteration
	for (int i = 1; i <= n; i++)
	{
		sum += i;
	}

	return sum;
}
