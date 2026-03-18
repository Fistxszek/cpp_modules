#pragma once

#include <algorithm>
#include <iterator>
#include <stdexcept>
#include <vector>

class Span
{
	private:
		unsigned int _n;
		std::vector<int> _vec;
	public:
		Span(unsigned int N);
		Span(Span &other);
		Span &operator=(const Span &other);
		~Span(void);

		void addNumber(int number);
		template<typename T> void addNumber(T &numbers)
		{
			if (_vec.size() + std::distance(numbers.begin(), numbers.end()) > _n)
				throw std::runtime_error("Insertion exceed max capacity.");
			_vec.insert(_vec.end(), numbers.begin(), numbers.end());
		}
		int shortestSpan(void);
		int longestSpan(void);
};
