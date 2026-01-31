#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <stdexcept>

template <class T>
class Array
{
	private:
		T *_elements;
		unsigned int _n;
	public:
		Array(void);
		Array(unsigned int n);
		Array(const Array &other);
		Array &operator=(const Array &other);
		T &operator[](unsigned int index);
		~Array(void);
		T *GetElements(void) const;
		unsigned int Size(void) const;
};

#include "Array.tpp"
#endif
