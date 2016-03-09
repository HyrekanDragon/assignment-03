/* ----------------------------------------------------------------------------
* Copyright &copy; 2016 Alex Chuoy <HyrekanDragon@yahoo.com>
* Released under the [MIT License] (http://opensource.org/licenses/MIT)
* ------------------------------------------------------------------------- */

/**
* Function prototypes for rewriting recursion functions into iteration functions.
*/

#ifndef	ITERATION_H
#define ITERATION_H
#include <string>

using std::string;

int gcd_iter(int a, int b);

int fib_iter(int n);

int pow_iter(int a, int b);

int tri_iter(int n);

#endif 
