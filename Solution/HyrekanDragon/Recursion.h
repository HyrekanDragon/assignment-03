/* ----------------------------------------------------------------------------
* Copyright &copy; 2016 Alex Chuoy <HyrekanDragon@yahoo.com>
* Released under the [MIT License] (http://opensource.org/licenses/MIT)
* ------------------------------------------------------------------------- */

/**
* Function prototypes for testing recursion.
*/

#ifndef RECURSION_H
#define RECURSION_H
#include <string>

using std::string;

int gcd(int a, int b);
//Finds the Greater Common Denominator fo two numbers

int fib(int n);
//Returns the nth Fibonacci number

int pow(int a, int b);
//Returns a to the bth power

int tri(int n);
//Returns the summation of all intergers up to n

string int_to_roman(int n);
//Converts Arabic Numerals to Roman Numerals

string int_to_words(int n);
//Prints out the name of a number

string counter(int n);
/*If a number passed into int_to_words is over 100
*counts how many times 100, 1000, or 1 000 000
*appear and returns the name of the number that counts
*how many times the aforementioned numbers appear
*/

string magic_number(int n);
/*Counts the number of characters in the name of a number
If the number of characters = the value of the number
it is a magic number otherwise return the number of characters
*/

string magic_to_words(int n);
//int_to_words modified to work with magic_number

string magic_counter(int n);
//counter modified to work with magic_number

#endif
