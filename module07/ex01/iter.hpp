#ifndef ITER_HPP
#define ITER_HPP

template <typename T, typename B> void iter(T *arrayAdress, const int arrayLen, B func)
{
	for (int i = 0; i < arrayLen; ++i)
	{
		func(arrayAdress[i]);
	}
}
#endif
