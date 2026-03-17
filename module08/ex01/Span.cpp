#include "Span.hpp"

bool check_vector(std::vector<int> vec)
{
	if (vec.empty())
	{
		throw std::runtime_error("Empty! Can't do this action.\n");
		return false;
	}
	else if (vec.size() == 1)
	{
		throw std::runtime_error("Only one element! Can't do this action.\n");
		return false;
	}
	return true;
}

Span::Span(unsigned int N) : _n(N)
{
	_vec.reserve(_n);
}

void Span::addNumber(int number)
{
	if (_vec.size() == _n)
		throw std::runtime_error("Already max capacity.");
	_vec.push_back(number);
}

int Span::shortestSpan(void)
{
	if (!check_vector(_vec))
		return -1;

	std::vector<int> tmp = _vec;
	std::sort(tmp.begin(), tmp.end());

	int lowest_span = -1;

	for (std::vector<int>::iterator it = tmp.begin();
			it != tmp.end() - 1; 
			++it)
	{
		int span = *(it + 1) - *it;
		if (span < lowest_span || lowest_span == -1)	
			lowest_span = span;
	}
	return (lowest_span);
}

int Span::longestSpan(void)
{
	if (!check_vector(_vec))
		return -1;

	int min = *std::min_element(_vec.begin(), _vec.end()).base();
	int max = *std::max_element(_vec.begin(), _vec.end()).base();

	return (max - min);
}
