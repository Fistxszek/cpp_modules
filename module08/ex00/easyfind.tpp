#include "easyfind.hpp"

template <typename T>
typename T::iterator easyfind(T &src, int val)
{
	typename T::iterator it;
	it = std::find(src.begin(), src.end(), val);
	if (it == src.end())
		throw std::runtime_error("Item not found.");
	return it;
}
