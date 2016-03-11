/* ----------------------------------------------------------------------------
* Copyright &copy; 2016 Alex Chuoy <HyrekanDragon@yahoo.com>
* Released under the [MIT License] (http://opensource.org/licenses/MIT)
* ------------------------------------------------------------------------- */

/**
* Functions for testing exceptions, templates and the vector, set and map STL.
*/

#include "Testing.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <exception>
#include <vector>
#include <set>
#include <map>

using std::cout;
using std::cin;
using std::endl;
using std::setw;
using std::right;
using std::string;
using std::vector;
using std::set;
using std::map;
using std::pair;



void test_exceptions()
{
	cout << "Starting test_exceptions!\n\n";

	try 
	{
		cout << "Testing divide function!\n";
		divide(1, 0);
	}

	catch (char x)
	{
		cout << "I caught a character??\n";
		cout << "That means an error has occured!\n";

		if (x == 'a')
		{
			cout << "Error Code '" << x << "' : Divided by 0.\n\n";
		}
	}
	try
	{
		int a = 100, b = 100;
		cout << "Testing swap function!\n";
		//This an arbitrary test. catch(...) shouldn't be used normally
		swap(a, b);
	}

	catch (...)
	{
		cout << "I caught something?! -_-\n";
		cout << "That means that you tried to swap variables with the same value.\n\n";
	}

	cout << "Ending test_exceptions!\n\n";
}

void test_templates()
{
	cout << "Testing templates!\n\n";

	cout << "Test divide template function!\n";
	cout << divide(4, 2) << endl;							//int
	cout << divide(1.3, 2.7) << endl;						//double
	cout << divide(1.5f, 1.6f) << endl;						//float
	cout << divide(1.237324L, 10.347334L) << endl << endl;	//long double

	int a = 18, b = 9;
	double pi = 6.28, tau = 3.14;
	char q = 't', r = 'p';
	string s1 = "dog", s2 = "hot";
	int arr_1[2] = { 9,2 }, arr_2[2] = { 3,7 };

	cout << "Testing swap template function!\n\n";
	cout << a << " " << b << endl;
	cout << "Pi is " << pi << " and tau is " << tau << "?\n";
	cout << q << " " << r << endl;
	cout << s1 << s2 << endl;
	cout << arr_1[0] << arr_2[0] << arr_1[1] << arr_2[1] << endl << endl;

	swap(a, b);
	swap(pi, tau);
	swap(q, r);
	swap(s1, s2);

	//Theres probably a better way to do this using loops

	swap(arr_1[1], arr_2[0]);
	swap(arr_2[1], arr_1[0]);
	
	cout << "Variables have now been swapped!\n\n";
	cout << a << " " << b << endl;
	cout << "Pi is " << pi << " and tau is " << tau << ".\n";
	cout << q << " " << r << endl;
	cout << s1 << s2 << endl;
	cout << arr_1[0] << arr_2[0] << arr_1[1] << arr_2[1] << endl << endl;

	cout << "Testing Dragon class template function\n\n";
	
	Dragon<int> Drake; Drake.setNumber(10);
	Dragon<double> Edjora; Edjora.setNumber(9.5);
	Dragon<float> Lyre;	Lyre.setNumber(1.38934F);
	Dragon<long double> Alex; Alex.setNumber(3.14159265358979323846L);

	Drake.speak();
	Edjora.speak();
	Lyre.speak();
	Alex.speak();
	cout << endl << "Done testing templates!\n\n";
}

void test_stl()
{
	cout << "Testing the Standard Template Library\n\n";
	cout << "Testing Vectors!\n\n";

	vector<int> k = { 1, 3 , 8 };
	k.clear();
	k.push_back(1); //push_back adds to the end of a vector
	k.push_back(2);
	k.push_back(4);
	k.pop_back();  //pop_back removes the last space reserved in memory for the vector
	k.push_back(3);
	cout << "The capacity is " << k.capacity() << ".\n";
	k.reserve(5); //Reserves nth amount of spaces in memory
	cout << "The capacity is now " << k.capacity() << ".\n";
	k.push_back(4);

	for (int e : k) //For every e in vector k
	{
		cout << e << endl;
	}

	cout << endl;
	cout << "Testing Set!\n\n";

	set<int> s = { 0,0,0,0,0,1,2,3,4,5 };
	cout << "The size of set s is " << s.size() << " elements.\n";
	s.clear();
	cout << "The size of set s is now " << s.size() << " elements.\n";
	cout << "The max size of set s is " << s.max_size() << " elements.\n";
	for (int i = 2; i <= 100; i++)
	{
		s.insert(i);
	}

	for (int j = 2; j <= 100; j++)
	{
		for (int k = 2; k < j; k++)
		{
			if (j%k == 0)
			{
				s.erase(j);
			}
		}
	}

	cout << "The set of prime numbers under 100 is " << s.size() << " elements.\n";
	cout << "The prime numbers up to 100 are\n";

	int counter = 0;

	for (int q : s)
	{
		cout << setw(2) << right << q << " ";
		counter++;

		if (counter == 5)
		{
			cout << endl;
			counter = 0;
		}
	}

	cout << endl << "Testing Maps!\n\n";

	//Most of the functions in Maps are similar to vectors or sets

	map<double, string > m = { {1,"ichi"},{2,"ni"},{3,"san"},{4,"yon"},{5,"go"},
							   {6,"roku"},{7,"shichi"},{8,"hachi"},{9,"kyuu"},
							   {10,"juu"},{100,"hyaku"},{1000,"sen"} };

	cout << "The Japanese equivalent of 1-1000 are the following:\n";

	for (pair < double,string> e : m)
		{
			cout << e.first << " is " << e.second << ".\n";
		}

	cout << endl << "Standard Template Library testing is done!\n\n";
}

template <typename t>

t divide(t a, t b)
{
	if (b == 0)
	{
		throw 'a';
	}

	return a / b;
}

template <typename t>

void swap(t & a, t & b)
{
	if (a == b)
	{
		throw a;
	}

	t temp = a;
	a = b;
	b = temp;
}
