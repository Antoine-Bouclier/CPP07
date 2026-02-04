#include "iter.hpp"
#include <iostream>

template< typename T >
void print( T& x )
{
	std::cout << x << ' ';
	return;
}

void	increment(int &x)
{
	x++;
}

void	toUpper(char &c)
{
	c = (char)toupper(c);
}

int main()
{
	int intArray[] = {1, 2, 3, 4, 5};
	char charArray[] = {'a', 'b', 'c', 'd'};

	std::cout << "Array before incrementation : ";
	iter(intArray, 5, print<int>);
	std::cout << std::endl;

	iter(intArray, 5, increment);

	std::cout << "Array after incrementation : ";
	iter(intArray, 5, print<int>);
	std::cout << std::endl;

	std::cout << "Array of char before toUpper : ";
	iter(charArray, 4, print<char>);
	std::cout << std::endl;

	iter(charArray, 4, toUpper);

	std::cout << "Array of char after toUpper : ";
	iter(charArray, 4, print<char>);
	std::cout << std::endl;

	std::cout << "TEST const" << std::endl;
	iter(charArray, 4, print<const char>);
	iter(intArray, 4, print<const int>);

	// std::cout << "TEST third parameter is not a function" << std::endl;
	// iter(charArray, 4, 4);

	return 0;
}
