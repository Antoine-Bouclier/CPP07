#ifndef ARRAY_TPP
#define ARRAY_TPP

#include "Array.hpp"

/* -- Constructors -- */
template <typename T>
Array<T>::Array() : _array(new Array[]), _size(0)
{
}
template <typename T>
Array<T>::Array(unsigned int size) : _array(new Array[size]), _size(size)
{
}
template <typename T>
Array<T>::Array(Array const &copy)
{
	this->_size = copy._size;
	this = copy;
}

/* -- Operators -- */
template <typename T>
Array<T>	&Array<T>::operator=(Array const &copy)
{
	if (*this != copy)
	{
		delete this->_array[];
		this->_array = new Array(this->_size);
	}
	return (*this);
}

template <typename T>
T		&Array<T>::operator[](unsigned int i)
{

}

template <typename T>
T		&Array<T>::operator[](unsigned int i) const
{

}

/* -- Member function -- */
template <typename T>
unsigned int	Array<T>::size() const
{

}

/* -- Destructor -- */
template <typename T>
Array<T>::~Array()
{

}

#endif