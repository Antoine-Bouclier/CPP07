#include <iostream>
#include <cstdlib>
#include <Array.hpp>

#define MAX_VAL 750
int main(int, char**)
{
	Array<int>	num(12);
	std::cout << "TEST 1" << std::endl;
	for (int i = 0; i < 12; i++)
	{
		num[i] = i;
	}
	for (int i = 0; i < 12; i++)
	{
		std::cout << num[i] << ' ';
	}
	std::cout << std::endl;
	{
		/* -- TEST deep copy -- */
		std::cout << "TEST 2 deep copy" << std::endl;
		Array<int>	n;
		std::cout << "size of n before asignement: " << n.size() << std::endl;
		n = num;
		std::cout << "size of n after asignement: " << n.size() << std::endl;
		for (int i = 0; i < 12; i++)
		{
			std::cout << n[i] << ' ';
		}
		std::cout << std::endl;
		for (int i = 12, j = 0; i < 24; i++, j++)
		{
			n[j] = i;
		}
		for (int i = 0; i < 12; i++)
		{
			std::cout << n[i] << ' ';
		}
		std::cout << std::endl;
	}
	{
		/* -- TEST deep copy -- */
		std::cout << "TEST 3 deep copy" << std::endl;
		Array<int>	n(num);
		for (int i = 0; i < 12; i++)
		{
			std::cout << n[i] << ' ';
		}
		std::cout << std::endl;
		for (int i = 12, j = 0; i < 24; i++, j++)
		{
			n[j] = i;
		}
		for (int i = 0; i < 12; i++)
		{
			std::cout << n[i] << ' ';
		}
		std::cout << std::endl;
	}
	try
	{
		std::cout << "TEST 4 Out of bounds" << std::endl;
		std::cout << num[0] << std::endl;
		std::cout << num[11] << std::endl;
		std::cout << num[12] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	std::cout << "TEST 5 size()" << std::endl;
	std::cout << num.size() << std::endl;

	std::cout << "TEST 6 const operator[]" << std::endl;
	const Array<int>	n(5);
	for (int i = 0; i < 5; i++)
	{
		n[i] = i;
	}
	for (int i = 0; i < 5; i++)
	{
		std::cout << n[i] << ' ';
	}
	std::cout << std::endl;
}
