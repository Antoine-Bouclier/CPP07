#ifndef ARRAY_TPP
#define ARRAY_TPP

#include "Array.hpp"

/* -- Constructors -- */
template <typename T>
Array<T>::Array() : _array(NULL), _size(0)
{
}
template <typename T>
Array<T>::Array(unsigned int size) : _array(new T[size]), _size(size)
{
}
template <typename T>
Array<T>::Array(Array const &copy) : _array(new T[copy._size]), _size(copy._size)
{
	for (unsigned int i = 0; i < this->_size; i++)
	{
		this->_array[i] = copy._array[i];
	}
}

/* -- Operators -- */
template <typename T>
Array<T>	&Array<T>::operator=(Array const &copy)
{
	if (this != &copy)
	{
		this->_size = copy._size;
		delete[] this->_array;
		this->_array = new T[this->_size];
		for (unsigned int i = 0; i < this->_size; i++)
		{
			this->_array[i] = copy._array[i];
		}
	}
	return (*this);
}

template <typename T>
T		&Array<T>::operator[](unsigned int i)
{
	if (i >= this->_size)
		throw OutOfBoundsException();
	return (this->_array[i]);
}

template <typename T>
T		&Array<T>::operator[](unsigned int i) const
{
	if (i >= this->_size)
		throw OutOfBoundsException();
	return (this->_array[i]);
}

/* -- Member function -- */
template <typename T>
unsigned int	Array<T>::size() const
{
	return (this->_size);
}

/* -- Destructor -- */
template <typename T>
Array<T>::~Array()
{
}
template <typename T>
const char*	Array<T>::OutOfBoundsException::what() const throw()
{
	return ("Out of bounds");
}

#endif