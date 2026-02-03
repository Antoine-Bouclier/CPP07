/* #include <iostream>
#include <cstdlib>
#include <Array.hpp>

#define MAX_VAL 750
int main(int, char**)
{
	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	//SCOPE
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}
	try
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}
	delete [] mirror;
	return 0;
} */

#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <ctime>
#include "Array.hpp"

#define MAX_VAL 750

int main()
{
	srand(time(NULL));

	// ===============================
	// 1. Construction & initialisation
	// ===============================
	Array<int> a(MAX_VAL);
	for (int i = 0; i < MAX_VAL; i++)
		a[i] = rand();

	// ===============================
	// 2. Copie profonde (copy constructor)
	// ===============================
	Array<int> b(a);

	for (int i = 0; i < MAX_VAL; i++)
	{
		if (a[i] != b[i])
		{
			std::cerr << "❌ Copy constructor failed" << std::endl;
			return 1;
		}
	}

	// ===============================
	// 3. Opérateur d'affectation
	// ===============================
	Array<int> c;
	c = a;

	for (int i = 0; i < MAX_VAL; i++)
	{
		if (a[i] != c[i])
		{
			std::cerr << "❌ Assignment operator failed" << std::endl;
			return 1;
		}
	}

	// ===============================
	// 4. Vérification deep copy
	// ===============================
	a[0] = 42;
	if (b[0] == 42 || c[0] == 42)
	{
		std::cerr << "❌ Shallow copy detected" << std::endl;
		return 1;
	}

	// ===============================
	// 5. Accès hors limites
	// ===============================
	try
	{
		a[-1] = 0;
		std::cerr << "❌ No exception for negative index" << std::endl;
		return 1;
	}
	catch (const std::exception& e)
	{
		std::cout << "✅ Exception caught: " << e.what() << std::endl;
	}

	try
	{
		a[MAX_VAL] = 0;
		std::cerr << "❌ No exception for overflow index" << std::endl;
		return 1;
	}
	catch (const std::exception& e)
	{
		std::cout << "✅ Exception caught: " << e.what() << std::endl;
	}

	// ===============================
	// 6. Test const Array
	// ===============================
	const Array<int> d(a);
	try
	{
		std::cout << "Const access OK: " << d[1] << std::endl;
	}
	catch (...)
	{
		std::cerr << "❌ Const operator[] failed" << std::endl;
		return 1;
	}

	// ===============================
	// 7. Taille
	// ===============================
	if (a.size() != MAX_VAL)
	{
		std::cerr << "❌ Wrong size()" << std::endl;
		return 1;
	}

	std::cout << "\n🎉 All tests passed successfully!" << std::endl;
	return 0;
}
