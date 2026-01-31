#include "Array.hpp"

template<typename T>
Array<T>::Array(void) : _elements(new T[0]), _n(0)
{
	std::cout <<"tes\n";
}

template<typename T>
Array<T>::Array(unsigned int n) :_elements(new T[n]), _n(n)
{
}

template<typename T>
Array<T>::Array(const Array &other)
{

}

template<typename T>
Array<T> &Array<T>::operator=(const Array &other)
{
	if (this == &other)
		return *this;
	unsigned int siz = other.Size();

	this->_n = siz;
	this->_elements = new T[siz];
	T *tempList = other.GetElements();
	for (unsigned int i = 0; i <= siz; ++i)
	{
		_elements[i] = tempList[i];		
	}
	return *this;
}

template<typename T>
T &Array<T>::operator[](unsigned int index)
{
	if (index >= this->_n)
	{
		throw std::out_of_range("blah");
	}
	return this->_elements[index];
}

template<typename T>
Array<T>::~Array()
{
	delete[] _elements;
}

template<typename T>
T *Array<T>::GetElements(void) const
{
	return this->_elements;
}

template<typename T>
unsigned int Array<T>::Size(void) const
{
	return this->_n;	
}
