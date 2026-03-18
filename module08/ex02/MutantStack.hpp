#pragma once

#include <stack>
#include <algorithm>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack(void);
		MutantStack(const MutantStack &other);
		MutantStack(const std::stack<T> &other);
		MutantStack &operator=(const MutantStack &other);
		MutantStack &operator=(const std::stack<T> &other);
		~MutantStack(void);

		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator begin();
		iterator end();
};

#include "MutantStack.tpp"
