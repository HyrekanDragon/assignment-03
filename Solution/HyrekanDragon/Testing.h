/* ----------------------------------------------------------------------------
* Copyright &copy; 2016 Alex Chuoy <HyrekanDragon@yahoo.com>
* Released under the [MIT License] (http://opensource.org/licenses/MIT)
* ------------------------------------------------------------------------- */

/**
* Function prototypes for testing exceptions, templates and the vector, set and map STL.
*/

#ifndef TESTING_H
#define TESTING_H

template <typename D>
class Dragon
{
private:
	D number;
public:
	void setNumber(D newNumber)
	{
		number = newNumber;
	}
	//Didn't use this function for some reason
	//D getNumber() const
	//{
	//	return number;
	//}
	void speak() const
	{
		cout << "This dragon is holding the number "
			<< number
			<< endl;
	}
};

void test_exceptions();

void test_templates();

void test_stl();

template <typename t>
t divide(t a, t b);

template <typename t>
void swap(t & a, t & b);


#endif
