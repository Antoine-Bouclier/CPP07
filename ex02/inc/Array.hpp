#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array
{
	private:
		T				*_array;
		unsigned int	_size;
	public:
		/* -- Constructors -- */
		Array();
		Array(unsigned int size);
		Array(Array const &copy);

		/* -- Operators -- */
		Array	&operator=(Array const &copy);
		T		&operator[](unsigned int i);
		T		&operator[](unsigned int i) const;

		/* -- Member function -- */
		unsigned int	size() const;

		/* -- Destructor -- */
		~Array();

		/* -- Exceptions -- */
		class OutOfBoundsException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

#include "Array.tpp"

#endif